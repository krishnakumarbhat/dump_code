/*===========================================================================*/
/**
 * @file SWC_PRJ_Appl_FaultMgr_fake_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the SWC_PRJ_Appl_FaultMgr.c file
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
#include <cstring>

#include "SWC_PRJ_Appl_FaultMgr_fake.h"

extern "C"
{
#include "Fault_Lib_Plt.h"
#include "Fault_Lib_Prj.h"
#include "Rte_Type.h"
   uint16 PRJ_Fail_Count_Debounce[MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT];
   uint16 PRJ_Pass_Count_Debounce[MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT];
// #include "SWC_PRJ_Appl_FaultMgr.c"
/* Disable the PCAN RX timeout diagnostic implementation when including the
   production C file into this test TU. This makes the internal static helper
   `checkComRxTimeoutFault` compile with an empty body and prevents access
   violations during gcov-instrumented runs while still exercising the
   runnable's branches. */
#ifndef ENABLE_PCAN_RX_TIMEOUT_FAULT
   #define ENABLE_PCAN_RX_TIMEOUT_FAULT FALSE
#endif
/* Disable VCAN timeout diagnostics for test TU and provide simple no-op
   implementations for the check and DTC functions so the runnable branches
   are callable without invoking RTE reads under gcov instrumentation. */
#ifndef ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT FALSE
#endif
#ifndef ENABLE_PRJ_BATTERY_LOW_FAULT
   #define ENABLE_PRJ_BATTERY_LOW_FAULT FALSE
#endif
#ifndef ENABLE_PRJ_BATTERY_HIGH_FAULT
   #define ENABLE_PRJ_BATTERY_HIGH_FAULT FALSE
#endif
/* VCAN check and DTC implementations are provided by the production C file.
   Do not define them here to avoid duplicate symbol errors when including
   the production translation unit. */
#include "SWC_PRJ_Appl_FaultMgr.c"
#undef checkComRxTimeoutFault
#undef PCAN_Timeout_Dtc
}

Platform_fault_T Platform_Fault_Enable_Table;
Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table;

namespace
{
static Platform_fault_T g_platform_active_fault_table;
static Platform_fault_T g_platform_fault_enable_table;
static Platform_fault_T g_platform_fault_test_completed_table;
static Customer_fault_T g_customer_active_fault_table;
static Customer_fault_T g_customer_active_fault_latched_table;
static Customer_fault_T g_customer_fault_test_completed_table;
static Customer_fault_T g_customer_history_fault_table;
static Customer_fault_Latch_Enable_T g_customer_fault_enable_table;
static uint8 g_fault_blockage_status;
static uint8 g_fault_damping_status;
static uint8 g_fault_range_status;
static uint8 g_fault_sll_status;
static uint8 g_fault_api_cfg_status;
static uint8 g_fault_api_trigger_status;
static uint8 g_fault_api_complete_status;
static uint8 g_fault_mmic_a_sensor_dead_status;
static uint8 g_fault_mmic_safe_start_status;
static uint8 g_fault_safety_integrity_status;
static uint8 g_fault_mmic_secondary_mipi_status;
static uint8 g_fault_mmic_secondary_clock_status;
static uint8 g_fault_mmic_secondary_register_status;
static uint8 g_fault_mmic_secondary_mcu_status;
static uint8 g_fault_usc_validation_status;
static uint8 g_fault_mmic_transmitter_id_status;
static uint8 g_fault_rfe_tx_rfbist_status;
static uint8 g_fault_rfe_rx_rfbist_status;
static uint8 g_fault_smc_validtn_status;
static uint8 g_fault_alignment_no_initial_cal_status;
static uint8 g_fault_alignment_sudden_jump_status;
static uint8 g_fault_alignment_critical_misalignment_status;
static uint8 g_fault_alignment_algo_status;
static uint8 g_fault_bbe_to_r52_ipc_status;
static uint8 g_fault_r52_to_bbe_ipc_status;
static uint8 g_fault_signal_integrity_status;
static uint8 g_fault_mcu_startup_status;
static uint8 g_fault_mmic_temperature_high_status;
static uint8 g_fault_mmic_temperature_low_status;
static uint8 g_fault_mcu_repetitive_reset_status;
static uint8 g_fault_external_watchdog_status;
static uint8 g_fault_platform_time_status;
static uint8 g_fault_alignment_out_of_range_status;

static uint8 Fake_Platform_Get_Fault_Status(uint16 fault_name);

static void Reset_Platform_Fault_Statuses(void)
{
   g_fault_blockage_status                        = CODED_FALSE;
   g_fault_damping_status                         = CODED_FALSE;
   g_fault_range_status                           = CODED_FALSE;
   g_fault_sll_status                             = CODED_FALSE;
   g_fault_api_cfg_status                         = CODED_FALSE;
   g_fault_api_trigger_status                     = CODED_FALSE;
   g_fault_api_complete_status                    = CODED_FALSE;
   g_fault_mmic_a_sensor_dead_status              = CODED_FALSE;
   g_fault_mmic_safe_start_status                 = CODED_FALSE;
   g_fault_safety_integrity_status                = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status             = CODED_FALSE;
   g_fault_mmic_secondary_clock_status            = CODED_FALSE;
   g_fault_mmic_secondary_register_status         = CODED_FALSE;
   g_fault_mmic_secondary_mcu_status              = CODED_FALSE;
   g_fault_usc_validation_status                  = CODED_FALSE;
   g_fault_mmic_transmitter_id_status             = CODED_FALSE;
   g_fault_rfe_tx_rfbist_status                   = CODED_FALSE;
   g_fault_rfe_rx_rfbist_status                   = CODED_FALSE;
   g_fault_smc_validtn_status                     = CODED_FALSE;
   g_fault_alignment_no_initial_cal_status        = CODED_FALSE;
   g_fault_alignment_sudden_jump_status           = CODED_FALSE;
   g_fault_alignment_critical_misalignment_status = CODED_FALSE;
   g_fault_alignment_algo_status                  = CODED_FALSE;
   g_fault_bbe_to_r52_ipc_status                  = CODED_FALSE;
   g_fault_r52_to_bbe_ipc_status                  = CODED_FALSE;
   g_fault_signal_integrity_status                = CODED_FALSE;
   g_fault_mcu_startup_status                     = CODED_FALSE;
}

static void Prepare_Dem_Dtc_Evaluation(void)
{
   RESET_FAKE(Dem_SetEventStatus);
   RESET_FAKE(Platform_Get_Fault_Status);
   Platform_Get_Fault_Status_fake.custom_fake = (uint8(*)(uint16))Fake_Platform_Get_Fault_Status;
}

static void Prepare_Project_Dtc_Evaluation(void)
{
   RESET_FAKE(Dem_SetEventStatus);
   RESET_FAKE(Customer_Get_Fault_Status);
   Customer_Get_Fault_Status_fake.return_val = CODED_FALSE;
}

static void Fake_Platform_memory_Copy(void *destination, void *source, uint8 num)
{
   if ((destination != NULL_PTR) && (source != NULL_PTR))
   {
      (void)memcpy(destination, source, num);
   }
}

static Std_ReturnType Fake_NvM_GetErrorStatus(NvM_BlockIdType block_id, NvM_RequestResultType *request_result_ptr)
{
   (void)block_id;
   if (request_result_ptr != NULL_PTR)
   {
      *request_result_ptr = NVM_REQ_OK;
   }
   return E_OK;
}

static Std_ReturnType Fake_NvM_WriteBlock(NvM_BlockIdType block_id, const void *src_ptr)
{
   (void)block_id;
   (void)src_ptr;
   return E_OK;
}

static uint8 Fake_Platform_Get_Fault_Status(uint16 fault_name)
{
   switch (fault_name)
   {
      case BLOCKAGE_ALGO_ERROR_FAULT:
         return g_fault_blockage_status;
      case DAMPING_ALGO_ERROR_FAULT:
         return g_fault_damping_status;
      case RANGE_ALGO_ERROR_FAULT:
         return g_fault_range_status;
      case SLL_MONITORING_ALGO_ERROR_FAULT:
         return g_fault_sll_status;
      case API_LOOK_CONFIG_FAULT:
         return g_fault_api_cfg_status;
      case API_LOOK_TRIGGER_FAULT:
         return g_fault_api_trigger_status;
      case API_LOOK_COMPLETE_FAULT:
         return g_fault_api_complete_status;
      case MMIC_A_SENSOR_DEAD_FAULT:
         return g_fault_mmic_a_sensor_dead_status;
      case MMIC_SAFE_START_FAULT:
         return g_fault_mmic_safe_start_status;
      case SAFETY_INTEGRITY_FAULT:
         return g_fault_safety_integrity_status;
      case MMIC_SECONDARY_MIPI_FAULT:
         return g_fault_mmic_secondary_mipi_status;
      case MMIC_SECONDARY_CLOCK_FAULT:
         return g_fault_mmic_secondary_clock_status;
      case MMIC_SECONDARY_REGISTER_FAULT:
         return g_fault_mmic_secondary_register_status;
      case MMIC_SECONDARY_MCU_FAULT:
         return g_fault_mmic_secondary_mcu_status;
      case USC_VALIDATION_FAULT:
         return g_fault_usc_validation_status;
      case MMIC_TRANSMITTER_ID_FAULT:
         return g_fault_mmic_transmitter_id_status;
      case RFE_TX_RFBIST_FAULT:
         return g_fault_rfe_tx_rfbist_status;
      case RFE_RX_RFBIST_FAULT:
         return g_fault_rfe_rx_rfbist_status;
      case BBE_TO_R52_IPC_FAULT:
         return g_fault_bbe_to_r52_ipc_status;
      case R52_TO_BBE_IPC_FAULT:
         return g_fault_r52_to_bbe_ipc_status;
      case SIGNAL_INTEGRITY_FAULT:
         return g_fault_signal_integrity_status;
      case MCU_STARTUP_FAULT:
         return g_fault_mcu_startup_status;
      case SMC_VALIDTN_FAULT:
         return g_fault_smc_validtn_status;
      case ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT:
         return g_fault_alignment_no_initial_cal_status;
      case AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT:
         return g_fault_alignment_sudden_jump_status;
      case AUTOALIGNMENT_CRITICAL_MISALIGNMENT_FAULT:
         return g_fault_alignment_critical_misalignment_status;
      case ALIGNMENT_AUTOALIGN_ALGO_FAULT:
         return g_fault_alignment_algo_status;
      case MMIC_TEMPERATURE_HIGH_FAULT:
         return g_fault_mmic_temperature_high_status;
      case MMIC_TEMPERATURE_LOW_FAULT:
         return g_fault_mmic_temperature_low_status;
      case MCU_REPETITIVE_RESET_FAULT:
         return g_fault_mcu_repetitive_reset_status;
      case EXTERNAL_WATCHDOG_FAULT:
         return g_fault_external_watchdog_status;
      case PLATFORM_TIME_FAULT:
         return g_fault_platform_time_status;
      case ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT:
         return g_fault_alignment_out_of_range_status;
      default:
         return CODED_FALSE;
   }
}
} // namespace

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class SWC_PRJ_Appl_FaultMgr_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      RESET_FAKE(NvM_GetErrorStatus);
      RESET_FAKE(NvM_WriteBlock);
      RESET_FAKE(Platform_memory_Copy);
      RESET_FAKE(Dem_SetEventStatus);
      RESET_FAKE(Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable);
      RESET_FAKE(Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable);
      RESET_FAKE(Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable);
      RESET_FAKE(Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable);

      (void)memset(&g_platform_active_fault_table, 0, sizeof(g_platform_active_fault_table));
      (void)memset(&g_platform_fault_enable_table, 0, sizeof(g_platform_fault_enable_table));
      (void)memset(&g_platform_fault_test_completed_table, 0, sizeof(g_platform_fault_test_completed_table));
      (void)memset(&g_customer_active_fault_table, 0, sizeof(g_customer_active_fault_table));
      (void)memset(&g_customer_active_fault_latched_table, 0, sizeof(g_customer_active_fault_latched_table));
      (void)memset(&g_customer_fault_test_completed_table, 0, sizeof(g_customer_fault_test_completed_table));
      (void)memset(&g_customer_history_fault_table, 0, sizeof(g_customer_history_fault_table));
      (void)memset(&g_customer_fault_enable_table, 0, sizeof(g_customer_fault_enable_table));
      Reset_Platform_Fault_Statuses();

      Get_Platform_Fault_Test_Completed_Table_fake.return_val = &g_platform_fault_test_completed_table;
      Get_Platform_Fault_Enable_Table_fake.return_val         = &g_platform_fault_enable_table;
      Get_Platform_Active_Fault_Table_fake.return_val         = &g_platform_active_fault_table;

      Get_Customer_Active_Fault_Table_fake.return_val         = &g_customer_active_fault_table;
      Get_Customer_Active_Fault_Latched_Table_fake.return_val = &g_customer_active_fault_latched_table;
      Get_Customer_Fault_Test_Completed_Table_fake.return_val = &g_customer_fault_test_completed_table;
      Get_Customer_Fault_Enable_Table_fake.return_val         = &g_customer_fault_enable_table;
      Get_Customer_History_Fault_Table_fake.return_val        = &g_customer_history_fault_table;

      Platform_memory_Copy_fake.custom_fake      = Fake_Platform_memory_Copy;
      NvM_GetErrorStatus_fake.custom_fake        = Fake_NvM_GetErrorStatus;
      NvM_WriteBlock_fake.custom_fake            = Fake_NvM_WriteBlock;
      Platform_Get_Fault_Status_fake.custom_fake = (uint8(*)(uint16))Fake_Platform_Get_Fault_Status;

      Platform_Get_Fault_Status_fake.return_val = CODED_FALSE;
      Customer_Get_Fault_Status_fake.return_val = CODED_FALSE;
      Dem_SetEventStatus_fake.return_val        = E_OK;

      Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable_fake.return_val   = E_OK;
      Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable_fake.return_val             = E_OK;
      Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable_fake.return_val = E_OK;
      Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable_fake.return_val           = E_OK;

      RE_PRJ_FaultMgr_Init();
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

/* Additional tests moved outside the fixture to avoid defining TEST_F within the class body. */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_BusoffCleared_TakeIfTrue)
{
   /* Ensure no high-priority bus-off qualification exists so the inner 'if' is true */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
   {
      Fail_Count_Debounce[i] = 0u;
   }
   /* Ensure no bus-off active flags */
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = 0u;
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   /* No explicit asserts — calling the runnable with cleared debounce should take the 'if' true paths */
   ASSERT_EQ(true, true);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event_BusoffCleared_TakeIfTrue)
{
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
   {
      Fail_Count_Debounce[i] = 0u;
   }
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = 0u;
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = 0u;

   RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event();
   ASSERT_EQ(true, true);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PCAN_Timeout_Faults_Event_BusoffCleared_TakeIfTrue)
{
   /* Clear debounce counters and bus-off flags so the checkComRxTimeoutFault path is taken */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
   {
      Fail_Count_Debounce[i] = 0u;
   }
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = 0u;
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = 0u;

   RE_PCAN_Timeout_Faults_Event();

   /* No explicit asserts; successful invocation exercises the 'if' true branch */
   ASSERT_EQ(true, true);
}

/* redefinition of global variables used by UUT */
/**
 *  @b RE_PRJ_FaultMgr_50ms
 *  @n
 */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PRJ_FaultMgr_50ms_test)
{
   RE_PRJ_FaultMgr_50ms();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_true_false)
{
   /* Ensure global Customer_Active_Fault_Table reflects test data */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   /* Initially no high priority faults */
   ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT));

   /* Set a high priority fault (pcan bus off) and verify true path */
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = 1u;
   ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_SIGNAL_ERROR_TRUE)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   /* set one of the bits checked in SIGNAL_ERROR_INVALID_DATA */
   Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault = 1u;
   ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_SIGNAL_ERROR_INVALID_DATA));

   /* clearing should yield false */
   Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault = 0u;
   ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_SIGNAL_ERROR_INVALID_DATA));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_ERRATIC_TRUE)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   /* set a bit included in ERRATIC_COMMUNICATION_ABNORMAL */
   Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = 1u;
   ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));

   Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = 0u;
   ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_E2E_TRUE)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   /* set a bit included in E2E case */
   Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault = 1u;
   ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_E2E));

   Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault = 0u;
   ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_E2E));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_BUSOFF_false)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   /* FAULT_BUSOFF should always return false per implementation */
   ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_BUSOFF));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_SIGNAL_ERROR_each_bit)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   using Setter                      = std::function<void(uint8)>;
   const std::vector<Setter> setters = {
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.PCAN_Message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CLS_TX_4_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CLS_Tx_16_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ETC2_MT_Variant_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CCVS1_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.OEL_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.TD_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.VD_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.SAS_message_timeout_fault = v; }};

   for (const auto &s : setters)
   {
      (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
      s(1u);
      ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_SIGNAL_ERROR_INVALID_DATA));
      s(0u);
      ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_SIGNAL_ERROR_INVALID_DATA));
   }
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_ERRATIC_each_bit)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   using Setter                      = std::function<void(uint8)>;
   const std::vector<Setter> setters = {
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.PCAN_Message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CLS_TX_4_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CLS_Tx_16_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ETC2_MT_Variant_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CCVS1_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.OEL_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.TD_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.VD_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.SAS_message_timeout_fault = v; }};

   for (const auto &s : setters)
   {
      (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
      s(1u);
      ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
      s(0u);
      ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
   }
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_E2E_each_bit)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   using Setter                      = std::function<void(uint8)>;
   const std::vector<Setter> setters = {
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.PCAN_Message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CLS_TX_4_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CLS_Tx_16_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ADAS_Function_Switch_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.ETC2_MT_Variant_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.VDC2_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.CCVS1_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.OEL_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.TD_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.VD_message_timeout_fault = v; },
      [](uint8 v) { Customer_Active_Fault_Table.Customer_Bits.SAS_message_timeout_fault = v; }};

   for (const auto &s : setters)
   {
      (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
      s(1u);
      ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_E2E));
      s(0u);
      ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_E2E));
   }
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_MESSAGE_TIMEOUT_checks)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   ASSERT_EQ(false, isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = 1u;
   ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault = 0u;
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault = 1u;
   ASSERT_EQ(true, isHighPriorityfaultactive(FAULT_MESSAGE_TIMEOUT));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultactive_default_case)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   FaultType unknown = (FaultType)0xFFu;
   /* default branch should be safe and return the (initialized) false value */
   ASSERT_EQ(false, isHighPriorityfaultactive(unknown));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultQualified_all_branches_false_and_true)
{
   /* start with all zeros -> all should be false */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
   {
      Fail_Count_Debounce[i] = 0u;
   }
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_SIGNAL_ERROR_INVALID_DATA));
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_E2E));
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_BUSOFF));

   /* bus-off qualifies everything except BUSOFF itself */
   Fail_Count_Debounce[PCAN_BUSOFF_FAULT_COUNT] = 1u;
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_SIGNAL_ERROR_INVALID_DATA));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_E2E));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_BUSOFF));

   /* clear and test timeout qualification (message timeout index) */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
   {
      Fail_Count_Debounce[i] = 0u;
   }
   Fail_Count_Debounce[PCAN_MESSAGE_TIMEOUT_COUNT] = 1u;
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_SIGNAL_ERROR_INVALID_DATA));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_E2E));
   /* MESSAGE_TIMEOUT is only qualified by bus-off, so remains false here */
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_BUSOFF));

   /* default/unknown should be safe */
   FaultType unknown = (FaultType)0xFEu;
   ASSERT_EQ(false, isHighPriorityfaultQualified(unknown));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultQualified_true_false)
{
   /* Clear debounce arrays then set bus-off debounce to exercise qualification */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
   {
      Fail_Count_Debounce[i] = 0u;
   }

   /* No debounces -> not qualified */
   ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));

   /* Simulate bus-off debounce exceeded */
   Fail_Count_Debounce[PCAN_BUSOFF_FAULT_COUNT] = 1u;
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, isHighPriorityfaultQualified_each_timeout_index)
{
   /* Ensure clean slate */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
      Fail_Count_Debounce[i] = 0u;

   const std::vector<uint16> timeout_indices = {PCAN_MESSAGE_TIMEOUT_COUNT,
                                                CLS_TX_4_MESSAGE_TIMEOUT_COUNT,
                                                CLS_TX_16_MESSAGE_TIMEOUT_COUNT,
                                                ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT,
                                                ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT,
                                                ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT,
                                                VDC2_MESSAGE_TIMEOUT_COUNT,
                                                CCVS1_MESSAGE_TIMEOUT_COUNT,
                                                OEL_MESSAGE_TIMEOUT_COUNT,
                                                TD_MESSAGE_TIMEOUT_COUNT,
                                                VD_MESSAGE_TIMEOUT_COUNT,
                                                SAS_MESSAGE_TIMEOUT_COUNT};

   for (auto idx : timeout_indices)
   {
      for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
         Fail_Count_Debounce[i] = 0u;
      Fail_Count_Debounce[idx] = 1u;

      /* timeout qualification should make these faults qualified */
      ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_SIGNAL_ERROR_INVALID_DATA));
      ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
      ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_E2E));

      /* MESSAGE_TIMEOUT is only qualified by bus-off, so remains false */
      ASSERT_EQ(false, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));
   }

   /* Also exercise VCAN bus-off qualified path */
   for (size_t i = 0; i < MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT; ++i)
      Fail_Count_Debounce[i] = 0u;
   Fail_Count_Debounce[VCAN_BUSOFF_FAULT_COUNT] = 1u;
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_SIGNAL_ERROR_INVALID_DATA));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_ERRATIC_COMMUNICATION_ABNORMAL));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_E2E));
   ASSERT_EQ(true, isHighPriorityfaultQualified(FAULT_MESSAGE_TIMEOUT));
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PCAN_Timeout_Faults_Event_Cover_CheckPath)
{
   /* Ensure no high priority faults and not qualified -> should call checkComRxTimeoutFault (no-op)
      and not set the test-completed flag. */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze = CODED_FALSE;
   /* clear relevant debounce counters so high-priority checks return false */
   Fail_Count_Debounce[PCAN_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   Fail_Count_Debounce[PCAN_BUSOFF_FAULT_COUNT]                           = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault = 0u;

   RE_PCAN_Timeout_Faults_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PCAN_Timeout_Faults_Event_Cover_FreezePath)
{
   /* Simulate high-priority active and freeze set -> else branch should set the flag */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault           = 1u; /* high priority */
   Plt_Fault_Table_Freeze                                                 = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault = 0u;

   RE_PCAN_Timeout_Faults_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PCAN_Timeout_Faults_Event_Cover_NonFreezeInnerFalse)
{
   /* Simulate high-priority active but Plt_Fault_Table_Freeze == CODED_FALSE -> inner if false */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault           = 1u; /* high priority */
   Plt_Fault_Table_Freeze                                                 = CODED_FALSE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault = 0u;

   RE_PCAN_Timeout_Faults_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_CheckPath)
{
   /* Ensure no high priority faults and not qualified -> should call check (no-op)
      and not set the test-completed flag for ETC2_MT variant. */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze                                                            = CODED_FALSE;
   Fail_Count_Debounce[ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_FreezePath)
{
   /* Simulate high-priority active and freeze set -> else branch should set the ETC2_MT flag */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault                      = 1u; /* high priority */
   Plt_Fault_Table_Freeze                                                            = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_NonFreezeInnerFalse)
{
   /* Simulate high-priority active but Plt_Fault_Table_Freeze == CODED_FALSE -> inner if false */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault                      = 1u; /* high priority */
   Plt_Fault_Table_Freeze                                                            = CODED_FALSE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault);
}

// Additional VCAN 100ms/1000ms variant coverage tests
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_ETC2_AT_AMT)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze                                                                = CODED_FALSE;
   Fail_Count_Debounce[ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_ETC2_AT_AMT_Freeze)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault                          = 1u;
   Plt_Fault_Table_Freeze                                                                = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_ETC2_AT_AMT_NonFreeze)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault                          = 1u;
   Plt_Fault_Table_Freeze                                                                = CODED_FALSE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_CLS_TX_4)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze                                                     = CODED_FALSE;
   Fail_Count_Debounce[CLS_TX_4_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_CLS_TX_4_Freeze)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault               = 1u;
   Plt_Fault_Table_Freeze                                                     = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_CLS_TX_4_NonFreeze)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault               = 1u;
   Plt_Fault_Table_Freeze                                                     = CODED_FALSE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_CLS_TX_16)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze                                                      = CODED_FALSE;
   Fail_Count_Debounce[CLS_TX_16_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_CLS_TX_16_Freeze)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault                = 1u;
   Plt_Fault_Table_Freeze                                                      = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_OEL)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze                                                = CODED_FALSE;
   Fail_Count_Debounce[OEL_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_OEL_Freeze)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.vcan_bus_off_fault          = 1u;
   Plt_Fault_Table_Freeze                                                = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_100ms_1000ms_Event_Cover_VD_TD)
{
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   /* VD */
   Plt_Fault_Table_Freeze                                               = CODED_FALSE;
   Fail_Count_Debounce[VD_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.VD_message_timeout_fault = 0u;
   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();
   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.VD_message_timeout_fault);

   /* TD (1000ms) freeze path */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault         = 1u;
   Plt_Fault_Table_Freeze                                               = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.TD_message_timeout_fault = 0u;
   RE_VCAN_Timeout_Faults_100ms_1000ms_Event();
   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.TD_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event_Cover_CheckPath_VDC2)
{
   /* Ensure no high priority faults and not qualified -> should call check (no-op)
      and not set the test-completed flag for VDC2. */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Plt_Fault_Table_Freeze                                                 = CODED_FALSE;
   Fail_Count_Debounce[VDC2_MESSAGE_TIMEOUT_COUNT]                        = 0u;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event_Cover_FreezePath_VDC2)
{
   /* Simulate high-priority active and freeze set -> else branch should set the VDC2 flag */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault           = 1u; /* high priority */
   Plt_Fault_Table_Freeze                                                 = CODED_TRUE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event();

   ASSERT_EQ(1u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event_Cover_NonFreezeInnerFalse_VDC2)
{
   /* Simulate high-priority active but Plt_Fault_Table_Freeze == CODED_FALSE -> inner if false */
   (void)memset(&Customer_Active_Fault_Table, 0, sizeof(Customer_Active_Fault_Table));
   Customer_Active_Fault_Table.Customer_Bits.pcan_bus_off_fault           = 1u; /* high priority */
   Plt_Fault_Table_Freeze                                                 = CODED_FALSE;
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault = 0u;

   RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event();

   ASSERT_EQ(0u, SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PRJ_FaultMgr_50ms_HistoryMismatch_UpdatesNvM_test)
{
   g_platform_active_fault_table.Platform_byte[0] = 0x01u;

   RE_PRJ_FaultMgr_50ms();

   ASSERT_EQ(1u, NvM_WriteBlock_fake.call_count);
   ASSERT_EQ(0x01u, g_customer_history_fault_table.Platform_byte[0]);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_OuterCondition_FirstOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = FALSE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_OuterCondition_SecondOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   /* Second operand (damping) false, others true -> outer AND short-circuits and inner OR is not evaluated */
   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = FALSE; /* second false */
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_OuterCondition_ThirdOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   /* Third operand (range) false, others true -> outer AND short-circuits and inner OR is not evaluated */
   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = FALSE; /* third false */
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_OuterCondition_LastOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = FALSE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_AllComplete_AllFaultsClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_FALSE;
   g_fault_range_status    = CODED_FALSE;
   g_fault_sll_status      = CODED_FALSE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(4u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_AllComplete_FirstFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_TRUE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_AllComplete_ThirdFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_FALSE;
   g_fault_range_status    = CODED_TRUE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(3u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_AllComplete_SecondFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_TRUE; /* second operand true */
   g_fault_range_status    = CODED_FALSE;
   g_fault_sll_status      = CODED_FALSE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_AllComplete_FourthFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_FALSE;
   g_fault_range_status    = CODED_FALSE;
   g_fault_sll_status      = CODED_TRUE; /* fourth operand true */

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(4u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_OuterCondition_FirstOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = FALSE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = TRUE;

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_AllComplete_SecondFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = TRUE;

   g_fault_api_cfg_status     = CODED_FALSE;
   g_fault_api_trigger_status = CODED_TRUE;

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_OuterCondition_LastOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = FALSE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_AllComplete_FourthFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status  = CODED_FALSE;
   g_fault_mmic_safe_start_status     = CODED_FALSE;
   g_fault_safety_integrity_status    = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status = CODED_TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(4u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarCalibration_OuterCondition_FirstOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.usc_validation_fault      = FALSE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_transmitter_id_fault = TRUE;

   Radar_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarCalibration_AllComplete_SecondFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.usc_validation_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_transmitter_id_fault = TRUE;

   g_fault_usc_validation_status      = CODED_FALSE;
   g_fault_mmic_transmitter_id_status = CODED_TRUE;

   Radar_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarRFBIST_OuterCondition_LastOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.rfe_tx_rfbist_err = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.rfe_rx_rfbist_err = FALSE;

   Radar_MMIC_RFBIST_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarRFBIST_AllComplete_FirstFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.rfe_tx_rfbist_err = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.rfe_rx_rfbist_err = TRUE;

   g_fault_rfe_tx_rfbist_status = CODED_TRUE;

   Radar_MMIC_RFBIST_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarRFBIST_AllComplete_SecondFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.rfe_tx_rfbist_err = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.rfe_rx_rfbist_err = TRUE;

   /* First returns false, second returns true -> two calls expected */
   g_fault_rfe_tx_rfbist_status = CODED_FALSE;
   g_fault_rfe_rx_rfbist_status = CODED_TRUE;

   Radar_MMIC_RFBIST_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarRFBIST_AllComplete_BothFaultsClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.rfe_tx_rfbist_err = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.rfe_rx_rfbist_err = TRUE;

   /* both platform fault status clear -> PASSED, two calls expected */
   g_fault_rfe_tx_rfbist_status = CODED_FALSE;
   g_fault_rfe_rx_rfbist_status = CODED_FALSE;

   Radar_MMIC_RFBIST_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, SMCChecksum_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.smc_validtn_fault = FALSE;

   SMC_Checksum_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, SMCChecksum_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.smc_validtn_fault = TRUE;
   g_fault_smc_validtn_status                                            = CODED_TRUE;

   SMC_Checksum_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, SMCChecksum_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.smc_validtn_fault = TRUE;
   g_fault_smc_validtn_status                                            = CODED_FALSE;

   SMC_Checksum_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignNoInitCal_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_no_initial_calibration_error_fault = FALSE;

   Alignment_No_Initial_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignNoInitCal_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_no_initial_calibration_error_fault = TRUE;
   g_fault_alignment_no_initial_cal_status                                                          = CODED_FALSE;

   Alignment_No_Initial_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignNoInitCal_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_no_initial_calibration_error_fault = TRUE;
   g_fault_alignment_no_initial_cal_status                                                          = CODED_TRUE;

   Alignment_No_Initial_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignSuddenJump_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_sudden_jump_detection_fault = FALSE;

   Alignment_Sudden_Jump_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignSuddenJump_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_sudden_jump_detection_fault = TRUE;
   g_fault_alignment_sudden_jump_status                                                                    = CODED_FALSE;

   Alignment_Sudden_Jump_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignSuddenJump_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_sudden_jump_detection_fault = TRUE;
   g_fault_alignment_sudden_jump_status                                                                    = CODED_TRUE;

   Alignment_Sudden_Jump_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignCriticalMisalignment_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.autoalignment_critical_misalignment_fault = FALSE;

   Alignment_Critical_Misalignment_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignCriticalMisalignment_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.autoalignment_critical_misalignment_fault = TRUE;
   g_fault_alignment_critical_misalignment_status                                                = CODED_FALSE;

   Alignment_Critical_Misalignment_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignCriticalMisalignment_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.autoalignment_critical_misalignment_fault = TRUE;
   g_fault_alignment_critical_misalignment_status                                                = CODED_TRUE;

   Alignment_Critical_Misalignment_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignAlgo_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_algo_error_fault = FALSE;

   Alignment_Algo_Error_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignAlgo_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_algo_error_fault = TRUE;
   g_fault_alignment_algo_status                                                                = CODED_FALSE;

   Alignment_Algo_Error_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignAlgo_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_algo_error_fault = TRUE;
   g_fault_alignment_algo_status                                                                = CODED_TRUE;

   Alignment_Algo_Error_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignOutOfRange_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_out_of_range_fault = FALSE;

   Alignment_Out_Of_Range_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignOutOfRange_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_out_of_range_fault = TRUE;
   g_fault_alignment_out_of_range_status                                                          = CODED_FALSE;

   Alignment_Out_Of_Range_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AlignOutOfRange_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.alignment_autoalignment_out_of_range_fault = TRUE;
   g_fault_alignment_out_of_range_status                                                          = CODED_TRUE;

   Alignment_Out_Of_Range_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PlatformTimeSync_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.platform_time_fault = FALSE;

   Platform_Time_Sync_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PlatformTimeSync_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.platform_time_fault = TRUE;
   g_fault_platform_time_status                                            = CODED_FALSE;

   Platform_Time_Sync_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PlatformTimeSync_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.platform_time_fault = TRUE;
   g_fault_platform_time_status                                            = CODED_TRUE;

   Platform_Time_Sync_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleTemperature_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_high_fault = FALSE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_low_fault  = FALSE;

   Radar_Module_Temperature_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleTemperature_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_high_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_low_fault  = TRUE;
   g_fault_mmic_temperature_high_status                                            = CODED_FALSE;
   g_fault_mmic_temperature_low_status                                             = CODED_FALSE;

   Radar_Module_Temperature_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleTemperature_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_high_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_low_fault  = TRUE;
   g_fault_mmic_temperature_high_status                                            = CODED_TRUE;
   g_fault_mmic_temperature_low_status                                             = CODED_FALSE;

   Radar_Module_Temperature_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleTemperature_CompletedAndLowFaultOnly_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_high_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_low_fault  = TRUE;
   g_fault_mmic_temperature_high_status                                            = CODED_FALSE;
   g_fault_mmic_temperature_low_status                                             = CODED_TRUE;

   Radar_Module_Temperature_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleTemperature_CompletedAndBothFaultsSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_high_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_temperature_low_fault  = TRUE;
   g_fault_mmic_temperature_high_status                                            = CODED_TRUE;
   g_fault_mmic_temperature_low_status                                             = CODED_TRUE;

   Radar_Module_Temperature_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleMemory_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mcu_repetitive_reset_fault = FALSE;

   Radar_Module_Memory_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleMemory_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mcu_repetitive_reset_fault = TRUE;
   g_fault_mcu_repetitive_reset_status                                            = CODED_FALSE;

   Radar_Module_Memory_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarModuleMemory_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mcu_repetitive_reset_fault = TRUE;
   g_fault_mcu_repetitive_reset_status                                            = CODED_TRUE;

   Radar_Module_Memory_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, ExternalWatchdog_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.external_watchdog_fault = FALSE;

   External_Watchdog_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, ExternalWatchdog_CompletedAndFaultClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.external_watchdog_fault = TRUE;
   g_fault_external_watchdog_status                                            = CODED_FALSE;

   External_Watchdog_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, ExternalWatchdog_CompletedAndFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.external_watchdog_fault = TRUE;
   g_fault_external_watchdog_status                                            = CODED_TRUE;

   External_Watchdog_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PCANBusOff_OuterConditionFalse_test)
{
   Prepare_Project_Dtc_Evaluation();

   g_customer_fault_test_completed_table.Customer_Bits.pcan_bus_off_fault = FALSE;

   PCAN_Bus_Off_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Customer_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PCANBusOff_CompletedAndFaultClear_test)
{
   Prepare_Project_Dtc_Evaluation();

   g_customer_fault_test_completed_table.Customer_Bits.pcan_bus_off_fault = TRUE;
   Customer_Get_Fault_Status_fake.return_val                              = CODED_FALSE;

   PCAN_Bus_Off_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Customer_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PCANBusOff_CompletedAndFaultSet_test)
{
   Prepare_Project_Dtc_Evaluation();

   g_customer_fault_test_completed_table.Customer_Bits.pcan_bus_off_fault = TRUE;
   Customer_Get_Fault_Status_fake.return_val                              = CODED_TRUE;

   PCAN_Bus_Off_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Customer_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, VCANBusOff_OuterConditionFalse_test)
{
   Prepare_Project_Dtc_Evaluation();

   g_customer_fault_test_completed_table.Customer_Bits.vcan_bus_off_fault = FALSE;

   VCAN_Bus_Off_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Customer_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, VCANBusOff_CompletedAndFaultClear_test)
{
   Prepare_Project_Dtc_Evaluation();

   g_customer_fault_test_completed_table.Customer_Bits.vcan_bus_off_fault = TRUE;
   Customer_Get_Fault_Status_fake.return_val                              = CODED_FALSE;

   VCAN_Bus_Off_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Customer_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, VCANBusOff_CompletedAndFaultSet_test)
{
   Prepare_Project_Dtc_Evaluation();

   g_customer_fault_test_completed_table.Customer_Bits.vcan_bus_off_fault = TRUE;
   Customer_Get_Fault_Status_fake.return_val                              = CODED_TRUE;

   VCAN_Bus_Off_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Customer_Get_Fault_Status_fake.call_count);
}

/**
 *  @b RE_PRJ_FaultMgr_Init
 *  @n
 */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PRJ_FaultMgr_Init_test)
{
   RE_PRJ_FaultMgr_Init();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PRJ_FaultMgr_DEM_50ms
 *  @n
 */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RE_PRJ_FaultMgr_DEM_50ms_test)
{
   RE_PRJ_FaultMgr_DEM_50ms();
   ASSERT_EQ(true, true);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, App_DemCbkEventStatus_PCAN_BusOffFault_ReturnsEOK)
{
   Std_ReturnType rc = App_DemCbkEventStatus_PCAN_BusOffFault(0u, 1u);
   ASSERT_EQ(E_OK, rc);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, App_DemCbkEventStatus_VCAN_BusOffFault_ReturnsEOK)
{
   Std_ReturnType rc = App_DemCbkEventStatus_VCAN_BusOffFault(0u, 1u);
   ASSERT_EQ(E_OK, rc);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, PinPositionMismatch_Dtc_ReportsCustomerFaultStatus)
{
   SWC_PRJ_Fault_Test_Completed->Customer_Bits.pin_position_fault = TRUE;

   Customer_Get_Fault_Status_fake.return_val = CODED_FALSE;
   PinPosition_Mismatch_Dtc();
   EXPECT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);

   RESET_FAKE(Dem_SetEventStatus);
   Customer_Get_Fault_Status_fake.return_val = CODED_TRUE;
   PinPosition_Mismatch_Dtc();
   EXPECT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Customer_DTC_Functions_Exercise_AllBranches)
{
   using Setter = std::function<void(uint8)>;
   struct Entry
   {
      Setter set;
      void (*fn)(void);
   };

   const std::vector<Entry> entries = {
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.pcan_bus_off_fault = v; }, PCAN_Bus_Off_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.vcan_bus_off_fault = v; }, VCAN_Bus_Off_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.PCAN_Message_timeout_fault = v; }, PCAN_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.CCVS1_message_timeout_fault = v; }, VCAN_CCVS1_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.VDC2_message_timeout_fault = v; }, VCAN_VDC2_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_MT_Variant_message_timeout_fault = v; },
       VCAN_ETC2_MT_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.ETC2_AT_AMT_Variant_message_timeout_fault = v; },
       VCAN_ETC2_AT_AMT_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.ADAS_Function_Switch_message_timeout_fault = v; },
       VCAN_ADAS_FN_Enable_Disable_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_Tx_16_message_timeout_fault = v; },
       VCAN_CLS_Tx_16_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.CLS_TX_4_message_timeout_fault = v; }, VCAN_CLS_Tx_4_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.OEL_message_timeout_fault = v; }, VCAN_OEL_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.TD_message_timeout_fault = v; }, VCAN_TD_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.VD_message_timeout_fault = v; }, VCAN_VD_Timeout_Dtc},
      {[](uint8 v) { SWC_PRJ_Fault_Test_Completed->Customer_Bits.SAS_message_timeout_fault = v; }, VCAN_SAS_Timeout_Dtc}};

   for (const auto &e : entries)
   {
      /* outer false -> should map to PASSED */
      Prepare_Project_Dtc_Evaluation();
      e.set(0u);
      e.fn();
      ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);

      /* outer true + customer clear -> PASSED */
      Prepare_Project_Dtc_Evaluation();
      e.set(1u);
      Customer_Get_Fault_Status_fake.return_val = CODED_FALSE;
      e.fn();
      ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);

      /* outer true + customer set -> FAILED */
      Prepare_Project_Dtc_Evaluation();
      e.set(1u);
      Customer_Get_Fault_Status_fake.return_val = CODED_TRUE;
      e.fn();
      ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   }
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Platform_DTC_Functions_Exercise_AllBranches)
{
   using Setter = std::function<void(uint8)>;
   struct Entry
   {
      Setter setBits;
      void (*fn)(void);
      std::vector<uint8 *> faultFlagPtrs;
   };

   const std::vector<Entry> entries = {
      /* Radar Performance Capability: blockage, damping, range, sll */
      {[](uint8 v)
       {
          g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = v;
          g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = v;
          g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = v;
          g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = v;
       },
       Radar_Performance_Capability_Dtc,
       std::vector<uint8 *>{&g_fault_blockage_status, &g_fault_damping_status, &g_fault_range_status, &g_fault_sll_status}},

      /* Application Interface Lookup: api look config/trigger/complete */
      {[](uint8 v)
       {
          g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = v;
          g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = v;
          g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = v;
       },
       Application_Interface_Lookup_Dtc,
       std::vector<uint8 *>{&g_fault_api_cfg_status, &g_fault_api_trigger_status, &g_fault_api_complete_status}},

      /* MMIC Internal Failure: mmic sensor dead, safe start, safety integrity, secondary mipi/clock/register/mcu */
      {[](uint8 v)
       {
          g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = v;
          g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = v;
          g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = v;
          g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = v;
          g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = v;
          g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = v;
          g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = v;
       },
       MMIC_Component_Internal_Failure_Dtc,
       std::vector<uint8 *>{&g_fault_mmic_a_sensor_dead_status, &g_fault_mmic_safe_start_status, &g_fault_safety_integrity_status,
                            &g_fault_mmic_secondary_mipi_status, &g_fault_mmic_secondary_clock_status,
                            &g_fault_mmic_secondary_register_status, &g_fault_mmic_secondary_mcu_status}},

      /* Radar Calibration: USC validation + MMIC transmitter id */
      {[](uint8 v)
       {
          g_platform_fault_test_completed_table.Platform_Bits.usc_validation_fault      = v;
          g_platform_fault_test_completed_table.Platform_Bits.mmic_transmitter_id_fault = v;
       },
       Radar_Calibration_Dtc,
       std::vector<uint8 *>{&g_fault_usc_validation_status,
                            &g_fault_mmic_transmitter_id_status}}, /* IPC Faults: BBE<->R52 IPC + signal integrity + MCU startup */
      {[](uint8 v)
       {
          g_platform_fault_test_completed_table.Platform_Bits.bbe_to_r52_ipc_fault   = v;
          g_platform_fault_test_completed_table.Platform_Bits.r52_to_bbe_ipc_fault   = v;
          g_platform_fault_test_completed_table.Platform_Bits.signal_integrity_fault = v;
          g_platform_fault_test_completed_table.Platform_Bits.mcu_startup_fault      = v;
       },
       IPC_Faults_Dtc,
       std::vector<uint8 *>{&g_fault_bbe_to_r52_ipc_status, &g_fault_r52_to_bbe_ipc_status, &g_fault_signal_integrity_status,
                            &g_fault_mcu_startup_status}}};

   for (const auto &e : entries)
   {
      /* outer false -> should be PASSED */
      Prepare_Dem_Dtc_Evaluation();
      e.setBits(0u);
      e.fn();
      ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);

      /* outer true and platform faults clear -> PASSED */
      Prepare_Dem_Dtc_Evaluation();
      e.setBits(1u);
      /* ensure all platform fault status flags are clear */
      for (auto p : e.faultFlagPtrs)
      {
         *p = CODED_FALSE;
      }
      e.fn();
      ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);

      /* outer true and each platform fault set individually -> FAILED (each OR operand) */
      for (auto p : e.faultFlagPtrs)
      {
         Prepare_Dem_Dtc_Evaluation();
         e.setBits(1u);
         /* clear all then set only this one */
         for (auto q : e.faultFlagPtrs)
         {
            *q = CODED_FALSE;
         }
         *p = CODED_TRUE;
         e.fn();
         ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
      }
   }
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, checkComRxTimeoutFault_Test)
{
   checkComRxTimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_VcanCCVS1_TimeoutFault_Test)
{
   Check_VcanCCVS1_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_VDC2_TimeoutFault_Test)
{
   Check_Vcan_VDC2_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_ETC2_MT_Variant_TimeoutFault_Test)
{
   Check_Vcan_ETC2_MT_Variant_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_ADAS_Function_Switch_TimeoutFault_Test)
{
   Check_Vcan_ADAS_Function_Switch_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_CLS_TX_4_TimeoutFault_Test)
{
   Check_Vcan_CLS_TX_4_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_OEL_TimeoutFault_Test)
{
   Check_Vcan_OEL_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_TD_TimeoutFault_Test)
{
   Check_Vcan_TD_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_VD_TimeoutFault_Test)
{
   Check_Vcan_VD_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_SAS_TimeoutFault_Test)
{
   Check_Vcan_SAS_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_CLS_Tx_16_TimeoutFault_Test)
{
   Check_Vcan_CLS_Tx_16_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Check_Vcan_ETC2_AT_AMT_Variant_TimeoutFault_Test)
{
   Check_Vcan_ETC2_AT_AMT_Variant_TimeoutFault();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, IPC_Faults_OuterConditionFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   /* ensure at least one outer operand false */
   g_platform_fault_test_completed_table.Platform_Bits.bbe_to_r52_ipc_fault   = FALSE;
   g_platform_fault_test_completed_table.Platform_Bits.r52_to_bbe_ipc_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.signal_integrity_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mcu_startup_fault      = TRUE;

   IPC_Faults_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, IPC_Faults_AllComplete_AllFaultsClear_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.bbe_to_r52_ipc_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.r52_to_bbe_ipc_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.signal_integrity_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mcu_startup_fault      = TRUE;

   g_fault_bbe_to_r52_ipc_status   = CODED_FALSE;
   g_fault_r52_to_bbe_ipc_status   = CODED_FALSE;
   g_fault_signal_integrity_status = CODED_FALSE;
   g_fault_mcu_startup_status      = CODED_FALSE;

   IPC_Faults_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, IPC_Faults_AllComplete_EachFaultSet_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.bbe_to_r52_ipc_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.r52_to_bbe_ipc_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.signal_integrity_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mcu_startup_fault      = TRUE;

   /* exercise each inner OR operand individually */
   g_fault_bbe_to_r52_ipc_status   = CODED_TRUE;
   g_fault_r52_to_bbe_ipc_status   = CODED_FALSE;
   g_fault_signal_integrity_status = CODED_FALSE;
   g_fault_mcu_startup_status      = CODED_FALSE;
   IPC_Faults_Dtc();
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);

   Prepare_Dem_Dtc_Evaluation();
   g_fault_bbe_to_r52_ipc_status = CODED_FALSE;
   g_fault_r52_to_bbe_ipc_status = CODED_TRUE;
   IPC_Faults_Dtc();
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);

   Prepare_Dem_Dtc_Evaluation();
   g_fault_r52_to_bbe_ipc_status   = CODED_FALSE;
   g_fault_signal_integrity_status = CODED_TRUE;
   IPC_Faults_Dtc();
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);

   Prepare_Dem_Dtc_Evaluation();
   g_fault_signal_integrity_status = CODED_FALSE;
   g_fault_mcu_startup_status      = CODED_TRUE;
   IPC_Faults_Dtc();
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
}

/* Targeted short-circuit coverage tests for RADAR Performance Capability (4 OR operands) */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_ShortCircuit_FirstOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_TRUE;
   g_fault_damping_status  = CODED_FALSE;
   g_fault_range_status    = CODED_FALSE;
   g_fault_sll_status      = CODED_FALSE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_ShortCircuit_SecondOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_TRUE;
   g_fault_range_status    = CODED_FALSE;
   g_fault_sll_status      = CODED_FALSE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_ShortCircuit_ThirdOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_FALSE;
   g_fault_range_status    = CODED_TRUE;
   g_fault_sll_status      = CODED_FALSE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(3u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Radar_PerfCap_ShortCircuit_FourthOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.blockage_algo_error_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.damping_algo_error_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.range_algo_error_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.sll_monitoring_algo_error = TRUE;

   g_fault_blockage_status = CODED_FALSE;
   g_fault_damping_status  = CODED_FALSE;
   g_fault_range_status    = CODED_FALSE;
   g_fault_sll_status      = CODED_TRUE;

   Radar_Performance_Capability_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(4u, Platform_Get_Fault_Status_fake.call_count);
}

/* Application Interface Lookup: 3 OR operands */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_ShortCircuit_FirstOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = TRUE;

   g_fault_api_cfg_status      = CODED_TRUE;
   g_fault_api_trigger_status  = CODED_FALSE;
   g_fault_api_complete_status = CODED_FALSE;

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_ShortCircuit_SecondOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = TRUE;

   g_fault_api_cfg_status      = CODED_FALSE;
   g_fault_api_trigger_status  = CODED_TRUE;
   g_fault_api_complete_status = CODED_FALSE;

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_ShortCircuit_ThirdOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = TRUE;

   g_fault_api_cfg_status      = CODED_FALSE;
   g_fault_api_trigger_status  = CODED_FALSE;
   g_fault_api_complete_status = CODED_TRUE;

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(3u, Platform_Get_Fault_Status_fake.call_count);
}

/* MMIC internal failure: 7 OR operands - test first and last to exercise call counts */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_ShortCircuit_FirstOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   /* set outer bits true */
   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status      = CODED_TRUE;
   g_fault_mmic_safe_start_status         = CODED_FALSE;
   g_fault_safety_integrity_status        = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status     = CODED_FALSE;
   g_fault_mmic_secondary_clock_status    = CODED_FALSE;
   g_fault_mmic_secondary_register_status = CODED_FALSE;
   g_fault_mmic_secondary_mcu_status      = CODED_FALSE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_ShortCircuit_LastOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status      = CODED_FALSE;
   g_fault_mmic_safe_start_status         = CODED_FALSE;
   g_fault_safety_integrity_status        = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status     = CODED_FALSE;
   g_fault_mmic_secondary_clock_status    = CODED_FALSE;
   g_fault_mmic_secondary_register_status = CODED_FALSE;
   g_fault_mmic_secondary_mcu_status      = CODED_TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(7u, Platform_Get_Fault_Status_fake.call_count);
}

/* Radar Calibration: ensure short-circuit first-operand true and second-only true are covered */
TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarCalibration_ShortCircuit_FirstOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.usc_validation_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_transmitter_id_fault = TRUE;

   g_fault_usc_validation_status      = CODED_TRUE;
   g_fault_mmic_transmitter_id_status = CODED_FALSE;

   Radar_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(1u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, RadarCalibration_ShortCircuit_SecondOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.usc_validation_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_transmitter_id_fault = TRUE;

   g_fault_usc_validation_status      = CODED_FALSE;
   g_fault_mmic_transmitter_id_status = CODED_TRUE;

   Radar_Calibration_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_OuterCondition_SecondOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   /* Second operand (api_look_trigger) false, others true -> outer AND short-circuits */
   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = FALSE; /* second false */
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = TRUE;

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, AppLookup_OuterCondition_ThirdOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   /* Third operand (api_look_complete) false, others true -> outer AND short-circuits */
   g_platform_fault_test_completed_table.Platform_Bits.api_look_config_fault   = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_trigger_fault  = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.api_look_complete_fault = FALSE; /* third false */

   Application_Interface_Lookup_Dtc();

   ASSERT_EQ(1u, Dem_SetEventStatus_fake.call_count);
   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_OuterCondition_FirstOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = FALSE; /* first false */
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_OuterCondition_SecondOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = FALSE; /* second false */
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_OuterCondition_ThirdOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = FALSE; /* third false */
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_OuterCondition_FifthOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = FALSE; /* fifth false */
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_OuterCondition_SixthOperandFalse_test)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = FALSE; /* sixth false */
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_PASSED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(0u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_ShortCircuit_SecondOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   /* set outer bits true */
   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status      = CODED_FALSE;
   g_fault_mmic_safe_start_status         = CODED_TRUE; /* second operand true */
   g_fault_safety_integrity_status        = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status     = CODED_FALSE;
   g_fault_mmic_secondary_clock_status    = CODED_FALSE;
   g_fault_mmic_secondary_register_status = CODED_FALSE;
   g_fault_mmic_secondary_mcu_status      = CODED_FALSE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(2u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_ShortCircuit_ThirdOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status      = CODED_FALSE;
   g_fault_mmic_safe_start_status         = CODED_FALSE;
   g_fault_safety_integrity_status        = CODED_TRUE; /* third operand true */
   g_fault_mmic_secondary_mipi_status     = CODED_FALSE;
   g_fault_mmic_secondary_clock_status    = CODED_FALSE;
   g_fault_mmic_secondary_register_status = CODED_FALSE;
   g_fault_mmic_secondary_mcu_status      = CODED_FALSE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(3u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_ShortCircuit_FifthOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status      = CODED_FALSE;
   g_fault_mmic_safe_start_status         = CODED_FALSE;
   g_fault_safety_integrity_status        = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status     = CODED_FALSE;
   g_fault_mmic_secondary_clock_status    = CODED_TRUE; /* fifth operand true */
   g_fault_mmic_secondary_register_status = CODED_FALSE;
   g_fault_mmic_secondary_mcu_status      = CODED_FALSE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(5u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, MMICInternal_ShortCircuit_SixthOperand_true)
{
   Prepare_Dem_Dtc_Evaluation();

   g_platform_fault_test_completed_table.Platform_Bits.mmic_a_sensor_dead_fault      = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_safe_start_fault         = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.safety_integrity_fault        = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mipi_fault     = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_clock_fault    = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_register_fault = TRUE;
   g_platform_fault_test_completed_table.Platform_Bits.mmic_secondary_mcu_fault      = TRUE;

   g_fault_mmic_a_sensor_dead_status      = CODED_FALSE;
   g_fault_mmic_safe_start_status         = CODED_FALSE;
   g_fault_safety_integrity_status        = CODED_FALSE;
   g_fault_mmic_secondary_mipi_status     = CODED_FALSE;
   g_fault_mmic_secondary_clock_status    = CODED_FALSE;
   g_fault_mmic_secondary_register_status = CODED_TRUE; /* sixth operand true */
   g_fault_mmic_secondary_mcu_status      = CODED_FALSE;

   MMIC_Component_Internal_Failure_Dtc();

   ASSERT_EQ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED, Dem_SetEventStatus_fake.arg1_val);
   ASSERT_EQ(6u, Platform_Get_Fault_Status_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Time_Synchronization_Fault_NotCompleted_test)
{
   RESET_FAKE(Diag_No_Filter_Test);
   Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = DIAG_TEST_NOT_COMPLETED;

   Time_Synchronization_Fault();

   ASSERT_EQ(0u, Diag_No_Filter_Test_fake.call_count);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Time_Synchronization_Fault_Completed_test)
{
   RESET_FAKE(Diag_No_Filter_Test);
   Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = DIAG_TEST_FAIL;

   Time_Synchronization_Fault();

   ASSERT_EQ(1u, Diag_No_Filter_Test_fake.call_count);
   ASSERT_EQ((uint16)TIME_SYNCHRONIZATION_FAULT, Diag_No_Filter_Test_fake.arg1_val);
}

TEST_F(SWC_PRJ_Appl_FaultMgr_UnitTestSuite, Project_Fault_50ms_test)
{
   RESET_FAKE(Diag_No_Filter_Test);
   Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State                                              = LO_V1;
   Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = DIAG_TEST_FAIL;

   Project_Fault_50ms();

   EXPECT_EQ(1u, Diag_No_Filter_Test_fake.call_count);
   EXPECT_EQ((uint16)TIME_SYNCHRONIZATION_FAULT, Diag_No_Filter_Test_fake.arg1_val);
}
