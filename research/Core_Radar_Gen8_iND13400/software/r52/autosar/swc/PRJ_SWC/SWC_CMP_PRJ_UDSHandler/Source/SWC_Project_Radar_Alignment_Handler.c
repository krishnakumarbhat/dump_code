/*===========================================================================*/
/*****************************************************************************
 * @file SWC_Project_Radar_Alignment_Handler.c
 *
 *  This file contains functions required for RIDs/DIDs present in Requirements
 * for Turnkey - Gen8 iND13400 adaptation
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file contains function implementations of RIDs/DIDs required for TurnKey.
 * Ported from Gen7V2 with the following Gen8-specific adaptations:
 *  - No PIM-based NvM storage (no Rte_Pim_* calls, no CRC)
 *  - No Alignment_RID_Data_nvm struct; use AlignmentHandler fields directly
 *  - Roll data accessed via AlignmentHandler.AlignmentRoll / RollStd directly
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
\*===========================================================================*/
#include "Rte_SWC_PLT_Radar_Alignment_Handler.h"

#include "SWC_Project_Radar_Alignment_Handler.h"

/*===========================================================================*\
 * Module State Variables
\*===========================================================================*/

/** Set to CODED_TRUE by RID Start handlers so the main runnable picks up the
 *  new Alignment_modeIn value on the next cycle. */
volatile uint8_t RID_Align_Cmd_Rcvd = CODED_FALSE;

/** Set to CODED_TRUE specifically when a Manual Alignment RID is received. */
volatile uint8_t RID_Manual_Align_Cmd_Rcvd = CODED_FALSE;

/** Set to CODED_TRUE after the Static Alignment Start RID has been accepted. */
uint8_t StaticAlignmentStarted = CODED_FALSE;

/** Set to CODED_TRUE after the Static Alignment Stop RID has been called. */
uint8_t StaticAlignmentStoppedByTester = CODED_FALSE;

/** Set to CODED_TRUE after the Service Alignment Start RID has been accepted. */
uint8_t ServiceAlignmentStarted = CODED_FALSE;

/** Set to CODED_TRUE after the Service Alignment Stop RID has been called. */
uint8_t ServiceAlignmentStoppedByTester = CODED_FALSE;

/*===========================================================================*\
 * Static Function Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/******************************************************************************
 * Routine_Start_StaticAlignment
 *
 * Description: Trigger Static Alignment when called (RID 0x7000 Start)
 ******************************************************************************/
void Routine_Start_StaticAlignment(void)
{
   /* RID ID = 31 01 70 00 */
   /* Start execution of static alignment */

   AlignmentHandler.Alignment_modeIn = ALIGN_MODE_STATIC;
   RID_Align_Cmd_Rcvd                = CODED_TRUE;
   StaticAlignmentStarted            = CODED_TRUE;
   StaticAlignmentStoppedByTester    = CODED_FALSE;

   /* RID ID = 31 01 70 00 */
   /* End of function */
}

/******************************************************************************
 * Routine_Stop_StaticAlignment
 *
 * Description: Stop Static Alignment when called (RID 0x7000 Stop)
 ******************************************************************************/
void Routine_Stop_StaticAlignment(void)
{
   /* RID ID = 31 02 70 00 */
   /* Stop execution of static alignment */

   AlignmentHandler.Alignment_modeIn = ALIGN_MODE_OFF;
   StaticAlignmentStoppedByTester    = CODED_TRUE;

   /* RID ID = 31 02 70 00 */
   /* End of function */
}

/******************************************************************************
 * Routine_Result_StaticAlignment
 *
 * Description: Return Result of Static Alignment when called (RID 0x7000 RequestResults)
 ******************************************************************************/
void Routine_Result_StaticAlignment(RID_StaticAlignment_Result_Data_T *Alignment_Static_Result)
{
   /* RID ID = 31 03 70 00 */
   /* return result of static alignment */

   Alignment_Static_Result->AlignmentStaticStatus = (uint8_t)AlignmentStatic.AlignmentStaticStatus;
   Alignment_Static_Result->AlignmentError        = (uint8_t)AlignmentHandler.AlignmentError;

   /* Make static alignment progress status 100% when it is successful */
   if (ALIGNMENT_SUCCESSFUL == (Dt_Align_Status)Alignment_Static_Result->AlignmentStaticStatus)
   {
      Alignment_Static_Result->ProgressPercent = ALIGNMENT_PROGRESS_PERCENT_COMPLETE;
   }
   else
   {
      Alignment_Static_Result->ProgressPercent = AlignmentHandler.ProgressPercent;
   }

   /* RID ID = 31 03 70 00 */
   /* End of function */
}

/******************************************************************************
 * Routine_Start_ServiceAlignment
 *
 * Description: Trigger Service Alignment when called (RID 0x7003 Start)
 ******************************************************************************/
void Routine_Start_ServiceAlignment(void)
{
   /* RID ID = 31 01 70 03 */
   /* Start execution of service alignment */

   AlignmentHandler.Alignment_modeIn = ALIGN_MODE_SERVICE;
   RID_Align_Cmd_Rcvd                = CODED_TRUE;
   ServiceAlignmentStarted           = CODED_TRUE;
   ServiceAlignmentStoppedByTester   = CODED_FALSE;

   /* RID ID = 31 01 70 03 */
   /* End of function */
}

/******************************************************************************
 * Routine_Stop_ServiceAlignment
 *
 * Description: Stop Service Alignment when called (RID 0x7003 Stop)
 ******************************************************************************/
void Routine_Stop_ServiceAlignment(void)
{
   /* RID ID = 31 02 70 03 */
   /* Stop execution of Service alignment */

   AlignmentHandler.Alignment_modeIn = ALIGN_MODE_OFF;
   ServiceAlignmentStoppedByTester   = CODED_TRUE;

   /* RID ID = 31 02 70 03 */
   /* End of function */
}

/******************************************************************************
 * Routine_Result_ServiceAlignment
 *
 * Description: Return Result of Service Alignment when called (RID 0x7003 RequestResults)
 ******************************************************************************/
void Routine_Result_ServiceAlignment(RID_ServiceAlignment_Result_Data_T *Alignment_Service_Result)
{
   /* RID ID = 31 03 70 03 */
   /* return result of Service alignment */

   Alignment_Service_Result->AlignmentServiceStatus = (uint8_t)AlignmentService.AlignmentServiceSt;
   Alignment_Service_Result->AlignmentError         = (uint8_t)AlignmentHandler.AlignmentError;

   /* Make Service alignment progress status 100% when it is successful */
   if (ALIGNMENT_SUCCESSFUL == (Dt_Align_Status)Alignment_Service_Result->AlignmentServiceStatus)
   {
      Alignment_Service_Result->ProgressPercent = ALIGNMENT_PROGRESS_PERCENT_COMPLETE;
   }
   else
   {
      Alignment_Service_Result->ProgressPercent = AlignmentHandler.ProgressPercent;
   }

   Alignment_Service_Result->VehicleCondition          = (uint8_t)AlignmentService.VehicleCondition;
   Alignment_Service_Result->DistanceAbsolute          = AlignmentService.DistanceAbsolute;
   Alignment_Service_Result->DistanceEffective         = AlignmentService.DistanceEffective;
   Alignment_Service_Result->DurationAbsolute          = AlignmentService.DurationAbsolute;
   Alignment_Service_Result->DurationEffective         = AlignmentService.DurationEffective;
   Alignment_Service_Result->AverageSpeed              = (uint32_t)(AlignmentService.AverageSpeed * FLOATCONVERSION_FOR_HUNDRED);
   Alignment_Service_Result->AverageNumberOfDetections = AlignmentService.AvgNumOfDet;

   /* RID ID = 31 03 70 03 */
   /* End of function */
}

/******************************************************************************
 * Data_Auto_Alignment_Status
 *
 * Description: Return status of Auto Alignment (DID 0xF016)
 ******************************************************************************/
void Data_Auto_Alignment_Status(Dt_Auto_Alignment_Status_Information *DID_AA_Status)
{
   /* DID ID = F0 16 */

   DID_AA_Status->AlignmentModeOut           = (uint8_t)AlignmentHandler.AlignmentModeOut;
   DID_AA_Status->AlignmentAutoStatus        = (uint8_t)AlignmentAuto.AlignAutoStatus;
   DID_AA_Status->AutoAlignmentFailRootCause = (uint8_t)AlignmentAuto.AutoAlignmentFailRootCause;
   DID_AA_Status->StartAzimuth               = (int32_t)(AlignmentAuto.StartAzimuth * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->StartElevation             = (int32_t)(AlignmentAuto.StartElevation * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->StartRoll                  = (int32_t)(AlignmentAuto.StartRoll * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AACurrentAzimuth           = (int32_t)(AlignmentAuto.AACurrentAzimuth * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AACurrentElevation         = (int32_t)(AlignmentAuto.AACurrentElevation * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AACurrentRoll              = (int32_t)(AlignmentAuto.AACurrentRoll * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AAAzimuthStd               = (int32_t)(AlignmentAuto.AAAzimuthStd * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AAElevationStd             = (int32_t)(AlignmentAuto.AAElevationStd * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AARollStd                  = (int32_t)(AlignmentAuto.AARollStd * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->InitialLastSuccessfulAlignmentMode = (uint8_t)AlignmentHandler.InitialLastSuccessAlignmentMode;
   DID_AA_Status->InitialAlignmentResultAzimuth =
      (int32_t)(AlignmentHandler.InitialAlignmentResultAz * FLOATCONVERSION_FOR_THOUSAND);
   DID_AA_Status->InitialAlignmentResultElevation =
      (int32_t)(AlignmentHandler.InitialAlignmentResultEl * FLOATCONVERSION_FOR_THOUSAND);
   DID_AA_Status->InitialAlignmentResultRoll =
      (int32_t)(AlignmentHandler.InitialAlignmentResultRoll * FLOATCONVERSION_FOR_THOUSAND);
   DID_AA_Status->AzimuthError_positive          = (int32_t)(AlignmentAuto.Az_Err_positive * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->ElevationError_positive        = (int32_t)(AlignmentAuto.El_Err_positive * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->RollError_positive             = (int32_t)(AlignmentAuto.RollError_positive * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->AzimuthError_negative          = (int32_t)(AlignmentAuto.Az_Err_negative * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->ElevationError_negative        = (int32_t)(AlignmentAuto.El_Err_negative * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->RollError_negative             = (int32_t)(AlignmentAuto.RollError_negative * FLOATCONVERSION_FOR_FIVE_THOUSAND);
   DID_AA_Status->HostSpeedCompensationFactor    = (int32_t)(AlignmentAuto.HostScf * FLOATCONVERSION_FOR_HUNDRED);
   DID_AA_Status->HostSpeedCompensationFactor_QF = AlignmentAuto.HostScf_QF;
   DID_AA_Status->AzimuthUpdates                 = AlignmentAuto.AzimuthNumUpdates;
   DID_AA_Status->ElevationUpdates               = AlignmentAuto.ElevationNumUpdates;
   DID_AA_Status->RollUpdates                    = AlignmentAuto.RollUpdates;
   /* DID ID = F0 16 */
   /* End of function */
}

/******************************************************************************
 * Data_Result_StaticAlignment
 *
 * Description: Return result of Static Alignment (DID 0xF01C)
 ******************************************************************************/
void Data_Result_StaticAlignment(DID_StaticAlignment_Result_T *Alignment_Static_Result)
{
   /* DID ID = F0 1C */

   Alignment_Static_Result->AlignmentModeOut      = (uint8_t)AlignmentHandler.AlignmentModeOut;
   Alignment_Static_Result->AlignmentStaticStatus = (uint8_t)AlignmentStatic.AlignmentStaticStatus;
   Alignment_Static_Result->AlignmentError        = (uint8_t)AlignmentHandler.AlignmentError;
   Alignment_Static_Result->AlignmentAzimuth      = AlignmentHandler.AlignmentAzimuth * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Static_Result->AlignmentElevation    = AlignmentHandler.AlignmentElevation * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Static_Result->AzimuthStd            = AlignmentHandler.AzimuthStd * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Static_Result->ElevationStd          = AlignmentHandler.ElevationStd * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Static_Result->CalTime               = AlignmentHandler.calTime * FLOATCONVERSION_FOR_HUNDRED;
   Alignment_Static_Result->ProgressPercent       = AlignmentHandler.ProgressPercent;
   Alignment_Static_Result->MeasuredRange         = AlignmentStatic.MeasuredRange;
   Alignment_Static_Result->MeasuredRangeStd      = (uint16_t)AlignmentStatic.MeasuredRangeStd;
   Alignment_Static_Result->MeasuredRangeRate     = (int32_t)AlignmentStatic.MeasuredRangeRate;
   Alignment_Static_Result->MeasuredRangeRateStd  = AlignmentStatic.MeasuredRangeRateStd;
   Alignment_Static_Result->MeasuredRCS           = AlignmentStatic.MeasuredAmplitude * FLOATCONVERSION_FOR_HUNDRED;
   Alignment_Static_Result->MeasuredRCSStd        = AlignmentStatic.MeasuredAmpStd * FLOATCONVERSION_FOR_HUNDRED;
   Alignment_Static_Result->InitialLastSuccessfulAlignmentMode = (uint8_t)AlignmentHandler.InitialLastSuccessAlignmentMode;
   Alignment_Static_Result->InitialAlignmentResultAzimuth =
      AlignmentHandler.InitialAlignmentResultAz * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Static_Result->InitialAlignmentResultElevation =
      AlignmentHandler.InitialAlignmentResultEl * FLOATCONVERSION_FOR_THOUSAND;

   /* DID ID = F0 1C */
   /* End of function */
}

/******************************************************************************
 * Data_NonConfig_Param_StaticAlignment
 *
 * Description: Return non-configurable parameters of Static Alignment (DID 0xF011)
 ******************************************************************************/
void Data_NonConfig_Param_StaticAlignment(DID_StaticAlignment_NonConfig_Param_T *AlignmentNonConfigParam)
{
   /* DID ID = F0 11 */
   /* Return non-configurable parameters of static alignment */
   /* Note: Parameters without Gen8 SMC equivalents use hard-coded values based on algorithm specification */

   AlignmentNonConfigParam->AlignmentStatic_NumberOfScans         = ALIGNMENT_STATIC_NUM_SCANS; /* Hard-coded as per algo */
   AlignmentNonConfigParam->AlignmentStatic_RangeOffset_Threshold = OFFSET_ZERO; /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->RangeRateUpper_Threshold    = ALIGNMENT_STATIC_RANGE_RATE_UPPER_THRESHOLD; /* Hard-coded as per algo */
   AlignmentNonConfigParam->RCS_Min                     = 0;     /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->RCS_Max                     = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->Velocity_Max                = 0U;    /* Hard-coded as per algo */
   AlignmentNonConfigParam->Yaw_Max                     = 0;     /* Hard-coded as per algo */
   AlignmentNonConfigParam->FlatPlateWidth_Lower_Limit  = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateWidth_Upper_Limit  = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateHeight_Lower_Limit = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateHeight_Upper_Limit = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateRCS_Lower_Limit    = 0;     /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateRCS_Upper_Limit    = 0;     /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateRange_Lower_Limit  = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateRange_Upper_Limit  = 0U;    /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateAzimuth_Lower_Limit   = 0;  /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateAzimuth_Upper_Limit   = 0U; /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateElevation_Lower_Limit = 0;  /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateElevation_Upper_Limit = 0U; /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateRangeRate_Lower_Limit = 0;  /* Placeholder - no Gen8 SMC equivalent */
   AlignmentNonConfigParam->FlatPlateRangeRate_Upper_Limit = 0U; /* Placeholder - no Gen8 SMC equivalent */

   /* DID ID = F0 11 */
   /* End of function */
}

/******************************************************************************
 * Data_Config_Param_ReadStaticAlignment
 *
 * Description: Return configurable parameters of Static Alignment (DID 0xF012)
 ******************************************************************************/
void Data_Config_Param_ReadStaticAlignment(Dt_Static_Alignment_Engineering_Parameters *AlignmentConfigParam)
{
   /* DID ID = F0 12 */
   /* Return configurable parameters of static alignment */

   AlignmentConfigParam->AlignmentStatic_AzimuthUpper_Threshold =
      (uint16_t)(alignment_m2d_data.static_alignment_data.horz_angle_max * FLOATCONVERSION_FOR_HUNDRED);
   AlignmentConfigParam->AlignmentStatic_AzimuthLower_Threshold =
      (int16_t)(alignment_m2d_data.static_alignment_data.horz_angle_min * FLOATCONVERSION_FOR_HUNDRED);
   AlignmentConfigParam->AlignmentStatic_ElevationUpper_Threshold =
      (uint16_t)(alignment_m2d_data.static_alignment_data.vert_angle_max * FLOATCONVERSION_FOR_HUNDRED);
   AlignmentConfigParam->AlignmentStatic_ElevationLower_Threshold =
      (int16_t)(alignment_m2d_data.static_alignment_data.vert_angle_min * FLOATCONVERSION_FOR_HUNDRED);
   AlignmentConfigParam->AlignmentStatic_TargetAzimuth =
      (int16_t)(alignment_m2d_data.static_alignment_data.plate_angle_deg_scs * FLOATCONVERSION_FOR_HUNDRED);
   AlignmentConfigParam->AlignmentStatic_TargetElevation =
      (int16_t)(alignment_m2d_data.static_alignment_data.pitch * FLOATCONVERSION_FOR_HUNDRED);
   AlignmentConfigParam->AlignmentStatic_TargetDistance =
      (uint16_t)(alignment_m2d_data.static_alignment_data.plate_distance * FLOATCONVERSION_FOR_HUNDRED);

   /* DID ID = F0 12 */
   /* End of function */
}

/******************************************************************************
 * Data_Config_Param_WriteStaticAlignment
 *
 * Description: Write configurable parameters of Static Alignment (DID 0xF013)
 ******************************************************************************/
void Data_Config_Param_WriteStaticAlignment(
   Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *AlignmentConfigParam)
{
   /* DID ID = F0 13 */
   /* Write configurable parameters of static alignment */

   /* DID ID = F0 13 */
   /* Write configurable parameters of static alignment */
   /* Note: RTE port only carries the 3 target signals - thresholds are not writable via this DID */

   alignment_m2d_data.static_alignment_data.plate_angle_deg_scs =
      ((float32_t)AlignmentConfigParam->Static_alignment_write_Params.AlignmentStatic_TargetAzimuth / FLOATCONVERSION_FOR_HUNDRED);
   alignment_m2d_data.static_alignment_data.pitch =
      ((float32_t)AlignmentConfigParam->Static_alignment_write_Params.AlignmentStatic_TargetElevation /
       FLOATCONVERSION_FOR_HUNDRED);
   alignment_m2d_data.static_alignment_data.plate_distance =
      ((float32_t)AlignmentConfigParam->Static_alignment_write_Params.AlignmentStatic_TargetDistance /
       FLOATCONVERSION_FOR_HUNDRED);

   /* DID ID = F0 13 */
   /* End of function */
}

/******************************************************************************
 * Data_Result_ServiceAlignment
 *
 * Description: Return result of Service Alignment (DID 0xF015)
 ******************************************************************************/
void Data_Result_ServiceAlignment(Dt_Service_Alignment_Result_Parameters *Alignment_Service_Result)
{
   /* DID ID = F0 15 */
   /* Return result of Service alignment */

   Alignment_Service_Result->AlignmentModeOut       = (uint8_t)AlignmentHandler.AlignmentModeOut;
   Alignment_Service_Result->AlignmentServiceStatus = (uint8_t)AlignmentService.AlignmentServiceSt;
   Alignment_Service_Result->AlignmentError         = (uint8_t)AlignmentHandler.AlignmentError;
   Alignment_Service_Result->AlignmentAzimuth       = AlignmentHandler.AlignmentAzimuth * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->AlignmentElevation     = AlignmentHandler.AlignmentElevation * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->AlignmentRoll          = AlignmentHandler.AlignmentRoll * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->AzimuthStd             = AlignmentHandler.AzimuthStd * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->ElevationStd           = AlignmentHandler.ElevationStd * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->RollStd                = AlignmentHandler.RollStd * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->CalTime                = AlignmentHandler.calTime * FLOATCONVERSION_FOR_HUNDRED;
   Alignment_Service_Result->ProgressPercent        = AlignmentHandler.ProgressPercent;
   Alignment_Service_Result->CalDisplay             = AlignmentHandler.CalDisplay;
   Alignment_Service_Result->InitialAlignmentResultAzimuthUpdates   = AlignmentHandler.InitialAlignmentResultAzUpdates;
   Alignment_Service_Result->InitialAlignmentResultElevationUpdates = AlignmentHandler.InitialAlignmentResultElUpdates;
   Alignment_Service_Result->InitialAlignmentResultRollUpdates      = AlignmentHandler.InitialAlignmentResultRollUpdates;
   Alignment_Service_Result->InitialAlignmentResultHostSpeedCompensationFactor =
      AlignmentHandler.InitialAlignmentResultHostSCF * FLOATCONVERSION_FOR_HUNDRED;
   Alignment_Service_Result->VehicleCondition          = (uint8_t)AlignmentService.VehicleCondition;
   Alignment_Service_Result->AverageNumberOfDetections = AlignmentService.AvgNumOfDet;
   Alignment_Service_Result->AverageSpeed              = (uint32_t)(AlignmentService.AverageSpeed * FLOATCONVERSION_FOR_HUNDRED);
   Alignment_Service_Result->DistanceAbsolute          = AlignmentService.DistanceAbsolute;
   Alignment_Service_Result->DistanceEffective         = AlignmentService.DistanceEffective;
   Alignment_Service_Result->DurationAbsolute          = AlignmentService.DurationAbsolute;
   Alignment_Service_Result->DurationEffective         = AlignmentService.DurationEffective;
   Alignment_Service_Result->InitialLastSuccessfulAlignmentMode = (uint8_t)AlignmentHandler.InitialLastSuccessAlignmentMode;
   Alignment_Service_Result->InitialAlignmentResultAzimuth =
      AlignmentHandler.InitialAlignmentResultAz * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->InitialAlignmentResultElevation =
      AlignmentHandler.InitialAlignmentResultEl * FLOATCONVERSION_FOR_THOUSAND;
   Alignment_Service_Result->InitialAlignmentResultRoll =
      AlignmentHandler.InitialAlignmentResultRoll * FLOATCONVERSION_FOR_THOUSAND;

   /* DID ID = F0 15 */
   /* End of function */
}

/******************************************************************************
 * Data_NonConfig_Param_ServiceAlignment
 *
 * Description: Return non-configurable parameters of Service Alignment (DID 0xF014)
 ******************************************************************************/
void Data_NonConfig_Param_ServiceAlignment(
   Dt_Service_Alignment_Engineering_Non_Configuration_Parameters *AlignServiceNonConfigParam)
{
   /* DID ID = F0 14 */
   /* Return non-configurable parameters of service alignment */

   AlignServiceNonConfigParam->AlignService_Abs_Dist_Th     = alignment_initial_cals.absolute_distance_threshold;
   AlignServiceNonConfigParam->AlignService_Eff_Dist_Th     = alignment_initial_cals.effective_distance_threshold;
   AlignServiceNonConfigParam->AlignService_Abs_Duration_Th = alignment_initial_cals.absolute_duration_threshold;
   AlignServiceNonConfigParam->AlignService_Eff_Duration_Th = alignment_initial_cals.effective_duration_threshold;
   AlignServiceNonConfigParam->AlignService_Vel_Min =
      ALIGNMENT_SERVICE_VELOCITY_MIN; /* Min velocity 3m/s * 100 - SMC value is incorrect, hard-coded */
   AlignServiceNonConfigParam->AlignService_Vel_Max =
      (uint16_t)(alignment_initial_cals.velocity_max * FLOATCONVERSION_FOR_HUNDRED);
   AlignServiceNonConfigParam->AlignService_Yawrate_Max =
      (uint16_t)(alignment_initial_cals.yawrate_max * FLOATCONVERSION_FOR_TEN_THOUSAND);

   /* DID ID = F0 14 */
   /* End of function */
}

/******************************************************************************
 * Data_Params_WriteManualAlignment
 *
 * Description: Write Manual Alignment parameters (DID 0xF01B Write)
 ******************************************************************************/
void Data_Params_WriteManualAlignment(Dt_Manual_Alignment_Execution_Data_CRC *ManualAlignment)
{
   /* DID ID = F0 1B */
   /* Write parameters of Manual alignment */
   /* Note: Gen8 does not use Alignment_RID_Data_nvm struct; values are written
    * directly to AlignmentHandler for use by the alignment algorithm */

   AlignmentHandler.Alignment_modeIn = ManualAlignment->Manual_Alignment_Execution_Data.AlignmentModeIn;
   AlignmentHandler.InitialLastSuccessAlignmentMode =
      ManualAlignment->Manual_Alignment_Execution_Data.InitialLastSuccessfulAlignmentMode;
   AlignmentHandler.InitialAlignmentResultAz =
      ((float32_t)ManualAlignment->Manual_Alignment_Execution_Data.IntialMisalignmentAngleAzimuth) / FLOATCONVERSION_FOR_THOUSAND;
   AlignmentHandler.InitialAlignmentResultEl =
      ((float32_t)ManualAlignment->Manual_Alignment_Execution_Data.IntialMisalignmentAngleElevation) /
      FLOATCONVERSION_FOR_THOUSAND;
   RID_Manual_Align_Cmd_Rcvd = CODED_TRUE;

   /* DID ID = F0 1B */
   /* End of function */
}

/******************************************************************************
 * Data_Params_ReadManualAlignment
 *
 * Description: Read Manual Alignment parameters (DID 0xF01B Read)
 ******************************************************************************/
void Data_Params_ReadManualAlignment(Dt_Manual_Alignment_Execution_Data_CRC *ManualAlignment)
{
   /* DID ID = F0 1B */
   /* Read parameters of Manual alignment */

   ManualAlignment->Manual_Alignment_Execution_Data.AlignmentModeIn = AlignmentHandler.Alignment_modeIn;
   ManualAlignment->Manual_Alignment_Execution_Data.InitialLastSuccessfulAlignmentMode =
      AlignmentHandler.InitialLastSuccessAlignmentMode;
   ManualAlignment->Manual_Alignment_Execution_Data.IntialMisalignmentAngleAzimuth =
      (int32_t)(AlignmentHandler.InitialAlignmentResultAz * FLOATCONVERSION_FOR_THOUSAND);
   ManualAlignment->Manual_Alignment_Execution_Data.IntialMisalignmentAngleElevation =
      (int32_t)(AlignmentHandler.InitialAlignmentResultEl * FLOATCONVERSION_FOR_THOUSAND);

   /* DID ID = F0 1B */
   /* End of function */
}
