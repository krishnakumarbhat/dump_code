/*===========================================================================*/
/**
 * @file C_Template.c
 *
 * @todo Add a one line description of the implementation.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
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
 * Standard Header Files
 *===========================================================================*/
#if ((ENABLE_SIT_TEST_STUBS == STD_ON) || (ENABLE_SQT_TEST_STUBS == STD_ON))
   #include "Rte_SWC_PLT_Appl_Diag.h"
   #include "SWC_PLT_Appl_Diag.h"
   #include "calibration.h"
   #include "string.h"
#endif
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

extern Dt_Rdr_Hw_Tst_T rdr_hw_tst;
extern volatile Dt_MMIC_ErrorFlags MMIC_Errors;
extern volatile Dt_Alignment_Faults_T Alignment_Errors;
extern Dt_PltToFltMgr_Blockage_Detection_T PltToFltMgr_algo_Status_diag;
extern volatile uint8 rfe_repetitive_reset_fault_status;
extern volatile Dt_Battery_Tst_T platform_battery_tst;
extern volatile Dt_PltToFltMgr_Alignment_Faults_T PltToFltMgr_Alignment_Faults;
extern volatile uint8 TR_Signal_Integrity;
extern Dt_PltToFltMgr_Memory_Diagnostics_T PltToFltMgr_Memory_Diagnostics;
extern Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T PltToFltMgr_MMIC_A_MMIC_Diag;
extern volatile uint8 TR_Platform_Time_Periodic;
extern volatile Dt_IPC_Faults IPC_Faults_sts;

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
volatile uint8 test_radar_faults                     = 0;
volatile uint8 hardware_tests_stub                   = 0;
volatile uint8 PltToFltMgr_MMIC_A_MMIC_Diag_Stub     = 0;
volatile uint8 IPC_CRC_Stub                          = 0;
volatile uint8 plt_time_test_stub                    = 0;
volatile uint8 PltToFltMgr_Alignment_Faults_Stub     = 0;
volatile uint8_t test_stub_rfe_fault_status          = 0;
volatile uint8_t Diag_Host_Microcontroller_Test_Stub = 0;
volatile uint8_t Diag_Memory_Diagnostics_Test_Stub   = 0;
uint8 Battery_Test                                   = 0;
#endif

#if (ENABLE_SQT_TEST_STUBS == STD_ON)
uint8 test_stub_pll_unlock_fault        = 0;
uint8 mmic_tx_id_stub                   = 0;
uint8 mmic_temp_high_stub               = 0;
uint8 mmic_safe_startup_stub            = 0;
uint8 mmic_temp_low_stub                = 0;
uint8 Alignment_stub                    = 0;
uint8 mmic_usc_unprogrammed_stub        = 0;
uint8 mmic_error_failure_stub           = 0;
volatile uint8 platform_time_fault_stub = 0;
volatile uint8 test_radar_faults        = 0;
volatile uint8 IPC_CRC_Stub             = 0;
volatile uint8 HWA_stub                 = 0;
volatile uint8 mmic_sensor_dead_stub    = 0;
volatile uint8 mmic_transmitter_id_stub = 0;
#endif
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/******************************************************************************
 * Name:  Appl_Diag_SIT_Functionality_Test
 *   This function includes stub code to verify interfaces of Mode Manager Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Appl_Diag.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
void Appl_Diag_SIT_Functionality_Test(void)
{
   // Diag_Init SIT_STUB_CODE for Integration_Test
   if (test_stub_rfe_fault_status == 1)
   {
      rfe_repetitive_reset_fault_status = DIAG_TEST_FAIL;
   }
   // Diag_Battery_Fault_Tests_50ms SIT_STUB_CODE for Integration_Test
   if (Battery_Test == 1)
   {
      platform_battery_tst.battery_low_flt_sts = DIAG_TEST_FAIL;
   }
   else if (Battery_Test == 2)
   {
      platform_battery_tst.battery_high_flt_sts = DIAG_TEST_FAIL;
   }
   else
   {
      // do nothing
   }
   // Diag_Alignment_Diagnostics_50ms SIT_STUB_CODE for Integration_Test
   if (PltToFltMgr_Alignment_Faults_Stub == 1)
   {
      PltToFltMgr_Alignment_Faults.Autoalign_outof_range_flt_sts = DIAG_TEST_FAIL;
   }
   // Diag_Host_Microcontroller_Tests_50ms SIT_STUB_CODE for Integration_Test
   if (Diag_Host_Microcontroller_Test_Stub == 1)
   {
      TR_Signal_Integrity = DIAG_TEST_PASS;
   }
   else
   {
      TR_Signal_Integrity = DIAG_TEST_FAIL;
   }
   // Diag_Memory_Diagnostics_50ms SIT_STUB_CODE for Integration_Test
   if (Diag_Memory_Diagnostics_Test_Stub == 1)
   {
      (void)memset(&PltToFltMgr_Memory_Diagnostics, DIAG_TEST_FAIL, sizeof(PltToFltMgr_Memory_Diagnostics));
   }
   else if (Diag_Memory_Diagnostics_Test_Stub == 2)
   {
      (void)memset(&PltToFltMgr_Memory_Diagnostics, DIAG_TEST_PASS, sizeof(PltToFltMgr_Memory_Diagnostics));
   }
   // Diag_Radar_Hardware_Tests_50ms SIT_STUB_CODE for Integration_Test
   if (hardware_tests_stub == 1)
   {
      (void)memset(&rdr_hw_tst, DIAG_TEST_FAIL, sizeof(rdr_hw_tst));
   }
   if (hardware_tests_stub == 2)
   {
      (void)memset(&rdr_hw_tst, DIAG_TEST_PASS, sizeof(rdr_hw_tst));
   }
   // Diag_Radar_Transceiver_Diagnostics_50ms SIT_STUB_CODE for Integration_Test
   if (PltToFltMgr_MMIC_A_MMIC_Diag_Stub == 1)
   {
      (void)memset(&PltToFltMgr_MMIC_A_MMIC_Diag, DIAG_TEST_FAIL, sizeof(PltToFltMgr_MMIC_A_MMIC_Diag));
   }
   if (PltToFltMgr_MMIC_A_MMIC_Diag_Stub == 2)
   {
      (void)memset(&PltToFltMgr_MMIC_A_MMIC_Diag, DIAG_TEST_PASS, sizeof(PltToFltMgr_MMIC_A_MMIC_Diag));
   }
   // Diag_PlatformTime_Test_50ms SIT_STUB_CODE for Integration_Test
   if (plt_time_test_stub == 1)
   {
      TR_Platform_Time_Periodic = DIAG_TEST_FAIL;
   }
   if (plt_time_test_stub == 2)
   {
      TR_Platform_Time_Periodic = DIAG_TEST_PASS;
   }
}
#endif
/******************************************************************************
 * Name:  Appl_Diag_SQT_Functionality_Test
 *   This function includes stub code to verify functionality of Mode Manager Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Appl_Diag.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == ENABLE_SQT_TEST_STUBS)
void Appl_Diag_SQT_Functionality_Test(void)
{
   // Diag_Alignment_Diagnostics_50ms SQT_STUB_CODE for Functionality_Test
   if (Alignment_stub == 1)
   {
      Alignment_Errors.No_Initial_Calibration_error = CODED_TRUE;
   }
   if (Alignment_stub == 2)
   {
      Alignment_Errors.Static_Calibration_error = CODED_TRUE;
   }
   if (Alignment_stub == 3)
   {
      Alignment_Errors.Service_Calibration_error = CODED_TRUE;
   }
   if (Alignment_stub == 4)
   {
      Alignment_Errors.ShortTrack_Calibration_error = CODED_TRUE;
   }
   if (Alignment_stub == 5)
   {
      Alignment_Errors.Autoalign_outof_range_error = CODED_TRUE;
   }
   if (Alignment_stub == 6)
   {
      Alignment_Errors.Autoalignment_algo_error = CODED_TRUE;
   }
   if (Alignment_stub == 7)
   {
      Alignment_Errors.Autoalignment_sudden_jump_detection_error = CODED_TRUE;
   }
   if (Alignment_stub == 8)
   {
      Alignment_Errors.Autoalignment_sudden_jump_detection_error = CODED_FALSE;
   }
   if (Alignment_stub == 9)
   {
      Alignment_Errors.Autoalignment_critical_misalignment_error = CODED_TRUE;
   }
   if (Alignment_stub == 10)
   {
      Alignment_Errors.Autoalignment_critical_misalignment_error = CODED_FALSE;
   }
   else
   {
      /* Do Nothing */
   }
   // Diag_Radar_Hardware_Tests_50ms SQT_STUB_CODE for Functionality_Test
   if (HWA_stub == 1)
   {
      (void)memset(&rdr_hw_tst, DIAG_TEST_FAIL, sizeof(rdr_hw_tst));
   }
   if (HWA_stub == 2)
   {
      (void)memset(&rdr_hw_tst, DIAG_TEST_PASS, sizeof(rdr_hw_tst));
   }
   // Diag_Radar_Transceiver_Diagnostics_50ms SQT_STUB_CODE for Functionality_Test
   if (test_stub_pll_unlock_fault == 1)
   {
      MMIC_Errors.chirp_pll_err = (uint8)CODED_TRUE;
   }
   // MMIC transmitter id fault SQT_STUB_CODE for Functionality_Test
   if (mmic_transmitter_id_stub == 1)
   {
      MMIC_Errors.MMIC_Transmitter_ID_Fault = (uint8)CODED_TRUE;
   }
   if (mmic_transmitter_id_stub == 2)
   {
      MMIC_Errors.MMIC_Transmitter_ID_Fault = (uint8)CODED_FALSE;
   }
   // MMIC sensor dead fault SQT_STUB_CODE for Functionality_Test
   if (mmic_sensor_dead_stub == 1)
   {
      MMIC_Errors.sensor_dead_err = (uint8)CODED_TRUE;
   }
   if (mmic_sensor_dead_stub == 2)
   {
      MMIC_Errors.sensor_dead_err = (uint8)CODED_FALSE;
   }
   /*Platform time fault*/
   if (platform_time_fault_stub == 1)
   {
      TR_Platform_Time_Periodic = Validate_Platform_Time_Range(4400, CODED_FALSE);
   }
   if (platform_time_fault_stub == 2)
   {
      TR_Platform_Time_Periodic = Validate_Platform_Time_Range(52000, CODED_FALSE);
   }
   if (platform_time_fault_stub == 3)
   {
      TR_Platform_Time_Periodic = Validate_Platform_Time_Range(50000, CODED_TRUE);
   }
   if (platform_time_fault_stub == 4 || platform_time_fault_stub == 5 || platform_time_fault_stub == 6)
   {
      TR_Platform_Time_Periodic = Validate_Platform_Time_Range(50000, CODED_FALSE);
   }
}
#endif
/******************************************************************************
 * Name:  Appl_Diag_SIT_SQT_Functionality_Test
 *   This function includes stub code to verify functionality of Mode Manager Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Appl_Diag.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SIT_TEST_STUBS == STD_ON) || (ENABLE_SQT_TEST_STUBS == STD_ON)
void Appl_Diag_SIT_SQT_Functionality_Test(void)
{
   // Diag_Inter_Processor_Communication_Diagnostics_50ms STUB_CODE for Integration_Functionality_Test
   if (IPC_CRC_Stub == 1)
   {
      IPC_Faults_sts.IPC_M2D_Crc_Err_Cnt = 85;
      IPC_Faults_sts.IPC_D2M_Crc_Err_Cnt = 85;
      IPC_Faults_sts.IPC_D2A_Crc_Err_Cnt = 85;
      IPC_Faults_sts.IPC_A2M_Crc_Err_Cnt = 85;
   }
   if (IPC_CRC_Stub == 2)
   {
      IPC_Faults_sts.IPC_M2D_Crc_Err_Cnt = 170;
      IPC_Faults_sts.IPC_D2M_Crc_Err_Cnt = 170;
      IPC_Faults_sts.IPC_D2A_Crc_Err_Cnt = 170;
      IPC_Faults_sts.IPC_A2M_Crc_Err_Cnt = 170;
   }
   // Diag_Radar_Blockage_Detection_Test_50ms STUB_CODE for Integration_Functionality_Test
   if (test_radar_faults == 1)
   {
      (void)memset(&PltToFltMgr_algo_Status_diag, DIAG_TEST_FAIL, sizeof(PltToFltMgr_algo_Status_diag));
   }
   if (test_radar_faults == 2)
   {
      (void)memset(&PltToFltMgr_algo_Status_diag, DIAG_TEST_PASS, sizeof(PltToFltMgr_algo_Status_diag));
   }
}
#endif
