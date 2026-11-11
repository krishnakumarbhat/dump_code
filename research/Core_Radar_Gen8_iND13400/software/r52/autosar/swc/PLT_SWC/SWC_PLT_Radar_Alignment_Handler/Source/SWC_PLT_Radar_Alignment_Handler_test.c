/*===========================================================================*/
/**
 * @file SWC_PLT_Radar_Alignment_Handler.c
 *
 * Test stubs and utilities for Radar Alignment Handler SWC
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
 * Test stubs and utilities for Radar Control SWC
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
#include <cstring>
/*===========================================================================*
 * External Header Files
 *===========================================================================*/
#if ((ENABLE_SIT_TEST_STUBS == STD_ON) || (ENABLE_SQT_TEST_STUBS == STD_ON))
   #include "Rte_SWC_PLT_Radar_Alignment_Handler.h"
   #include "mcal_init.h"
volatile int Alignment_Test_Stub = 0U;
void Test_Alignment_Faults(Dt_Alignment_Faults_T *Alignment_Faults);

/******************************************************************************
 * Name:  Test_Alignment_Faults
 *   This function includes stub code to verify interfaces of Alignment Faults Errors to Diagnostic Component
 *
 * Shared Variables: none
 *
 * Parameters: Dt_Alignment_Faults_T *   - Pointer to the Alignment Faults structure
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Test_Alignment_Faults(Dt_Alignment_Faults_T *Alignment_Faults)
{
   if (Alignment_Test_Stub == 1U)
   {
      (void)memset(Alignment_Faults, CODED_FALSE, sizeof(Dt_Alignment_Faults_T));
   }
   if (Alignment_Test_Stub == 2U)
   {
      (void)memset(Alignment_Faults, CODED_TRUE, sizeof(Dt_Alignment_Faults_T));
   }
}

#endif
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
void Test_Alignment_NVM_Record_Write(Dt_Write_Alignment_NvM_Data_T *alignment_nvm_data);
void Test_Alignment_Main_RTE_Writes(Dt_AlignmentAuto *alignment_auto, Dt_AlignmentService *alignment_service,
                                    Dt_AlignmentShortTrack *alignment_shorttrack, Dt_AlignmentStatic *alignment_static,
                                    Dt_Alignment_Handler *alignment_handler, Dt_Alignment_M2D_Data *alignment_m2d);
void Test_Alignment_XCP_RTE_Writes(Dt_Auto_Alignment_Result_T *xcp_auto_alignment_data,
                                   Dt_Initial_Alignment_Result_T *xcp_initial_align_res,
                                   Dt_Initial_Alignment_Performance_Result_T *xcp_align_perf_res);

/* Single status variable to observe write-test success in debugger:
 * 0 = no new success, 3 = NVM(AUTO), 4 = NVM(OFF), 5 = MAIN, 6 = XCP, 7 = IPC
 */
volatile uint8_t Alignment_Write_Test_Result = 0U;

/******************************************************************************
 * Name:  Test_Alignment_NVM_Record_Write
 *   This function modifies alignment NVM record data for SIT/SQT before RTE write.
 *
 * Shared Variables: Alignment_Test_Stub
 *
 * Parameters: Dt_Write_Alignment_NvM_Data_T * - Pointer to NVM record to be written
 *
 * Return Value: none
 ******************************************************************************/
void Test_Alignment_NVM_Record_Write(Dt_Write_Alignment_NvM_Data_T *alignment_nvm_data)
{
   if (alignment_nvm_data == NULL)
   {
      return;
   }

   if ((Alignment_Test_Stub == 3U) || (Alignment_Test_Stub == 4U))
   {
      if (Alignment_Test_Stub == 3U)
      {
         alignment_nvm_data->AACurrentAzimuth   = 0.111F;
         alignment_nvm_data->AACurrentElevation = -0.222F;
         alignment_nvm_data->AACurrentRoll      = 0.0F;
         alignment_nvm_data->AlignmentModeOut   = (uint8_t)ALIGN_MODE_AUTO;
         Alignment_Write_Test_Result            = 3U;
      }
      else
      {
         alignment_nvm_data->AACurrentAzimuth   = 0.0F;
         alignment_nvm_data->AACurrentElevation = 0.0F;
         alignment_nvm_data->AACurrentRoll      = 0.0F;
         alignment_nvm_data->AlignmentModeOut   = (uint8_t)ALIGN_MODE_OFF;
         Alignment_Write_Test_Result            = 4U;
      }
   }
}

void Test_Alignment_Main_RTE_Writes(Dt_AlignmentAuto *alignment_auto, Dt_AlignmentService *alignment_service,
                                    Dt_AlignmentShortTrack *alignment_shorttrack, Dt_AlignmentStatic *alignment_static,
                                    Dt_Alignment_Handler *alignment_handler, Dt_Alignment_M2D_Data *alignment_m2d)
{
   if ((alignment_auto == NULL) || (alignment_service == NULL) || (alignment_shorttrack == NULL) || (alignment_static == NULL) ||
       (alignment_handler == NULL) || (alignment_m2d == NULL))
   {
      return;
   }

   if (Alignment_Test_Stub == 5U)
   {
      alignment_auto->AlignAutoStatus                           = ALIGNMENT_PAUSED;
      alignment_service->AlignmentServiceSt                     = ALIGNMENT_FAILED;
      alignment_shorttrack->AlignShortTrackSt                   = ALIGNMENT_RUNNING;
      alignment_static->AlignmentStaticStatus                   = ALIGNMENT_SUCCESSFUL;
      alignment_handler->AlignmentError                         = AH_ALIGNERR_INVALID_INPUT;
      alignment_handler->AlignmentModeOut                       = ALIGN_MODE_MANUAL;
      alignment_m2d->dynamic_alignment_data.auto_align_status   = (uint8_t)ALIGNMENT_PAUSED;
      alignment_m2d->dynamic_alignment_data.aacurrent_azimuth   = 0.123F;
      alignment_m2d->dynamic_alignment_data.aacurrent_elevation = -0.456F;
      Alignment_Write_Test_Result                               = 5U;
   }
}

void Test_Alignment_XCP_RTE_Writes(Dt_Auto_Alignment_Result_T *xcp_auto_alignment_data,
                                   Dt_Initial_Alignment_Result_T *xcp_initial_align_res,
                                   Dt_Initial_Alignment_Performance_Result_T *xcp_align_perf_res)
{
   if ((xcp_auto_alignment_data == NULL) || (xcp_initial_align_res == NULL) || (xcp_align_perf_res == NULL))
   {
      return;
   }

   if (Alignment_Test_Stub == 6U)
   {
      xcp_auto_alignment_data->AlignmentAutoStatus        = FAILED;
      xcp_auto_alignment_data->AutoAlignmentFailRootCause = INVALID_INPUT;

      xcp_initial_align_res->AlignmentError  = AH_ALIGNERR_INVALID_INPUT;
      xcp_initial_align_res->ProgressPercent = 99U;

      xcp_align_perf_res->DistanceAbsolute = 999U;
      xcp_align_perf_res->DurationAbsolute = 777U;
      xcp_align_perf_res->AverageSpeed     = 12.34F;
      xcp_align_perf_res->VehicleCondition = ALIGN_VEH_VEL_HIGH;
      Alignment_Write_Test_Result          = 6U;
   }
}

void Test_Alignment_IPC_AutoAlignment_Write(Dt_Alignment_NVM_T *ipc_autoalignment_nvm)
{
   if (ipc_autoalignment_nvm == NULL)
   {
      return;
   }

   if (Alignment_Test_Stub == 7U)
   {
      ipc_autoalignment_nvm->Alignment_Initial_NVM_Data.InitialAlignmentResultAzimuth   = 1.111F;
      ipc_autoalignment_nvm->Alignment_Initial_NVM_Data.InitialAlignmentResultElevation = -2.222F;
      ipc_autoalignment_nvm->Alignment_AutoCyclic_NVM_Data.AACurrentAzimuth             = 0.333F;
      ipc_autoalignment_nvm->Alignment_AutoCyclic_NVM_Data.AACurrentElevation           = -0.444F;
      ipc_autoalignment_nvm->Alignment_Auto_NVM_data.AzimuthUpdates                     = 55U;
      ipc_autoalignment_nvm->Alignment_Auto_NVM_data.ElevationUpdates                   = 66U;
      ipc_autoalignment_nvm->AlignmentModeOut                                           = ALIGN_MODE_SERVICE;
      Alignment_Write_Test_Result                                                       = 7U;
   }
}
#endif
