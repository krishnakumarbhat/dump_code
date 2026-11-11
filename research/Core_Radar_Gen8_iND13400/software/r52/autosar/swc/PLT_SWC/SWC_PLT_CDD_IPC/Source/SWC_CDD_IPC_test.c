/*===========================================================================*/
/**
 * @file SWC_CDD_IPC_test.c
 *
 * Test stubs and utilities for IPC SWC
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Test stubs and utilities for IPC SWC
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
#include <cstring>
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
/*===========================================================================*
 * External Header Files
 *===========================================================================*/
#ifndef TRUE
   #define TRUE 1U
#endif
#if (TRUE == ENABLE_SQT_TEST_STUBS)
   #include "Rte_SWC_CDD_IPC.h"
   #include "reuse.h"

/*===========================================================================*
 * Local Variables
 *===========================================================================*/
static volatile uint8_t core_selt_test_failure_flag             = 0U;
static volatile uint8_t ipc_r52_bbe_fault                       = 0U;
static volatile uint8_t first_pass_saturation_test_failure_flag = 0U;
static volatile uint8_t Data_integrity_Test_Stub                = 0U;
static volatile uint8_t Dsp_internal_Test_Stub                  = 0U;
static Dt_RadarCapability_Faults test_diag_ipc_faults           = {0};
Dt_IPC_Faults test_ipc_faults                                   = {0};

/*===========================================================================*
 * Function Declarations
 *===========================================================================*/
void Test_IPC_SQT_RadarCapability_Faults_Set(void);
#endif

#if (TRUE == ENABLE_SIT_TEST_STUBS)
   #include "Rte_SWC_CDD_IPC.h"
   #include "reuse.h"
/*===========================================================================*
 * Local Variables
 *===========================================================================*/
volatile uint8_t Test_IPC_Alignment_Data_Control = 0U;
volatile uint8_t test_ipc_var                    = 0U;

/*===========================================================================*
 * Function Declarations
 *===========================================================================*/
void Test_IPC_Alignment_Data_Set(Dt_Alignment_IPC_Data *alignment_ipc_data);
void Test_IPC_SIT_Fault_Injection(Dt_RadarCapability_Faults *diag_ipc_faults);
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  Test_IPC_Alignment_Data_Set
 *   This function includes stub code to verify IPC alignment data paths.
 *
 * Shared Variables: none
 *
 * Parameters: Dt_Alignment_IPC_Data * - Pointer to the alignment IPC data structure
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Test_IPC_Alignment_Data_Set(Dt_Alignment_IPC_Data *alignment_ipc_data)
{
   if (Test_IPC_Alignment_Data_Control == 1U)
   {
      alignment_ipc_data->data_qualifier = CODED_TRUE;
   }
   else if (Test_IPC_Alignment_Data_Control == 2U)
   {
      alignment_ipc_data->data_qualifier = CODED_FALSE;
   }
}

/******************************************************************************
 * Name:  Test_IPC_SIT_Fault_Injection
 *   This function includes stub code to inject radar capability fault states
 *   for SIT testing purposes. It modifies the provided fault structure directly
 *   before the RTE write, allowing controlled fault injection and clearing.
 *
 * Shared Variables: test_ipc_var - controls injection behaviour:
 *                     1       = set all faults (CODED_TRUE)
 *                     non-zero  = clear all faults (CODED_FALSE)
 *                     0       = no change
 *
 * Parameters: Dt_RadarCapability_Faults * - Pointer to the radar capability
 *                                           faults structure to be modified
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Test_IPC_SIT_Fault_Injection(Dt_RadarCapability_Faults *diag_ipc_faults)
{
   if (1 == test_ipc_var)
   {
      (void)memset(diag_ipc_faults, CODED_TRUE, sizeof(*diag_ipc_faults));
   }
   else
   {
      (void)memset(diag_ipc_faults, CODED_FALSE, sizeof(*diag_ipc_faults));
   }
}
#endif

#if (TRUE == ENABLE_SQT_TEST_STUBS)
void Test_IPC_SQT_RadarCapability_Faults_Set(void)
{
   if (core_selt_test_failure_flag == 1U)
   {
      test_diag_ipc_faults.Safety_Integrity_Fault = CODED_TRUE;
      test_diag_ipc_faults.Core_Self_Test_Fault   = CODED_TRUE;
   }
   else if (core_selt_test_failure_flag == 2U)
   {
      test_diag_ipc_faults.Safety_Integrity_Fault = CODED_FALSE;
      test_diag_ipc_faults.Core_Self_Test_Fault   = CODED_FALSE;
   }
   if (ipc_r52_bbe_fault == 1u)
   {
      test_ipc_faults.IPC_M2D_Crc_Err_Cnt++;
      test_ipc_faults.IPC_D2M_Crc_Err_Cnt++;
   }
   else if (ipc_r52_bbe_fault == 2u)
   {
      test_ipc_faults.IPC_M2D_Crc_Err_Cnt = 1;
      test_ipc_faults.IPC_D2M_Crc_Err_Cnt = 1;
   }
   if (first_pass_saturation_test_failure_flag == 1U)
   {
      test_diag_ipc_faults.Firstpass_Saturation_Fault = CODED_TRUE;
   }
   else if (first_pass_saturation_test_failure_flag == 2U)
   {
      test_diag_ipc_faults.Firstpass_Saturation_Fault = CODED_FALSE;
   }
   if (1 == Data_integrity_Test_Stub)
   {
      test_diag_ipc_faults.Detection_Data_Integrity_Fault          = CODED_TRUE;
      test_diag_ipc_faults.Detection_Procession_Loop_Overrun_Fault = CODED_TRUE;
   }
   else
   {
      test_diag_ipc_faults.Detection_Data_Integrity_Fault          = CODED_FALSE;
      test_diag_ipc_faults.Detection_Procession_Loop_Overrun_Fault = CODED_FALSE;
   }
   if (1 == Dsp_internal_Test_Stub)
   {
      test_diag_ipc_faults.Dsp_Internal_Fault = CODED_TRUE;
   }
   else
   {
      test_diag_ipc_faults.Dsp_Internal_Fault = CODED_FALSE;
   }

   (void)Rte_Write_Pp_RadarCapability_Faults_De_RadarCapability_Faults(&test_diag_ipc_faults);
   Rte_Write_Pp_IPC_Faults_De_IPC_Faults(&test_ipc_faults);
}
#endif
