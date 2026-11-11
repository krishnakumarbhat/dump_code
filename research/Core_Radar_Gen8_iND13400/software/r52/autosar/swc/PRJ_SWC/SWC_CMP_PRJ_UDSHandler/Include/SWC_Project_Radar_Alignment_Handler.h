#ifndef SWC_PROJECT_Radar_Alignment_Handler_H
#define SWC_PROJECT_Radar_Alignment_Handler_H

/*===========================================================================*/
/*****************************************************************************
 * @file SWC_Project_Radar_Alignment_Handler.h
 *
 *  This file contains Structure definitions and functions required for
 * RIDs/DIDs present in Requirements for Turnkey
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
 * This file contains function declaration of RIDs/DIDs required for TurnKey
 *
 * @section ABBR ABBREVIATIONS:
 *   - List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file, or "None".
 *
 */
/*==========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Rte_Type.h"
#include "SWC_PLT_Radar_Alignment_Handler.h"

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define FLOATCONVERSION_FOR_HUNDRED         100.0F
#define FLOATCONVERSION_FOR_THOUSAND        1000.0F
#define FLOATCONVERSION_FOR_FIVE_THOUSAND   5000.0F
#define FLOATCONVERSION_FOR_TEN_THOUSAND    10000.0F
#define FLOATCONVERSION_FOR_TWENTY_THOUSAND 20000.0F
#define OFFSET_ZERO                         0U

/* Progress percent reported once an alignment routine completes successfully */
#define ALIGNMENT_PROGRESS_PERCENT_COMPLETE 100U
/* Static alignment scan count - hard-coded as per algorithm specification */
#define ALIGNMENT_STATIC_NUM_SCANS 20U
/* Static alignment range-rate upper threshold (0.02 * 100) - hard-coded as per algorithm specification */
#define ALIGNMENT_STATIC_RANGE_RATE_UPPER_THRESHOLD 2U
/* Service alignment min velocity (3 m/s * 100) - SMC value is incorrect, hard-coded */
#define ALIGNMENT_SERVICE_VELOCITY_MIN 300U

#ifndef CODED_TRUE
   #define CODED_TRUE (1U)
#endif
#ifndef CODED_FALSE
   #define CODED_FALSE (0U)
#endif

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/* Structure to store manual alignment NvM write data */
typedef struct RID_Write_ManualAlignment_NvM_Data_Tag
{
   float32_t InitialAlignmentResultAzimuth;
   float32_t InitialAlignmentResultElevation;
} RID_Write_ManualAlignment_NvM_Data_T;

/* Structure to store static alignment result data */
typedef struct RID_StaticAlignment_Result_Data_Tag
{
   uint8_t AlignmentStaticStatus;
   uint8_t AlignmentError;
   uint8_t ProgressPercent;
} RID_StaticAlignment_Result_Data_T;

/* Structure to store configurable parameters for static alignment (DID F012 read / F013 write) */
typedef struct DID_StaticAlignment_Config_Param_Tag
{
   uint16_t AlignmentStatic_AzimuthUpper_Threshold;
   int16_t AlignmentStatic_AzimuthLower_Threshold;
   uint16_t AlignmentStatic_ElevationUpper_Threshold;
   int16_t AlignmentStatic_ElevationLower_Threshold;
   int16_t AlignmentStatic_TargetAzimuth;
   int16_t AlignmentStatic_TargetElevation;
   uint16_t AlignmentStatic_TargetDistance;
} DID_StaticAlignment_Config_Param_T;

/* Structure to store static alignment result (DID F01C) */
typedef struct DID_StaticAlignment_Result_Tag
{
   uint8_t AlignmentModeOut;
   uint8_t AlignmentStaticStatus;
   uint8_t AlignmentError;
   float32_t AlignmentAzimuth;
   float32_t AlignmentElevation;
   float32_t AzimuthStd;
   float32_t ElevationStd;
   float32_t CalTime;
   uint8_t ProgressPercent;
   float32_t MeasuredRange;
   uint16_t MeasuredRangeStd;
   int32_t MeasuredRangeRate;
   float32_t MeasuredRangeRateStd;
   float32_t MeasuredRCS;
   float32_t MeasuredRCSStd;
   uint8_t InitialLastSuccessfulAlignmentMode;
   float32_t InitialAlignmentResultAzimuth;
   float32_t InitialAlignmentResultElevation;
} DID_StaticAlignment_Result_T;

/* Structure to store auto alignment status (DID F016) */
typedef struct DID_AutoAlignment_Status_Tag
{
   uint8_t AlignmentModeOut;
   uint8_t AlignmentAutoStatus;
   uint8_t AutoAlignmentFailRootCause;
   float32_t StartAzimuth;
   float32_t StartElevation;
   float32_t StartRoll;
   float32_t AACurrentAzimuth;
   float32_t AACurrentElevation;
   float32_t AACurrentRoll;
   float32_t AAAzimuthStd;
   float32_t AAElevationStd;
   float32_t AARollStd;
   uint8_t InitialLastSuccessfulAlignmentMode;
   float32_t InitialAlignmentResultAzimuth;
   float32_t InitialAlignmentResultElevation;
   float32_t InitialAlignmentResultRoll;
   float32_t AzimuthError_positive;
   float32_t ElevationError_positive;
   float32_t RollError_positive;
   float32_t AzimuthError_negative;
   float32_t ElevationError_negative;
   float32_t RollError_negative;
   float32_t HostSpeedCompensationFactor;
   uint8_t HostSpeedCompensationFactor_QF;
   uint32_t AzimuthUpdates;
   uint32_t ElevationUpdates;
   uint32_t RollUpdates;
} DID_AutoAlignment_Status_T;

/* Structure to store service alignment result data (RID 0x7003 RequestResults) */
typedef struct RID_ServiceAlignment_Result_Data_Tag
{
   uint8_t AlignmentServiceStatus;
   uint8_t AlignmentError;
   uint8_t ProgressPercent;
   uint8_t VehicleCondition;
   uint32_t DistanceAbsolute;
   uint32_t DistanceEffective;
   uint32_t DurationAbsolute;
   uint32_t DurationEffective;
   uint32_t AverageSpeed;
   uint32_t AverageNumberOfDetections;
} RID_ServiceAlignment_Result_Data_T;

/* Structure to store service alignment result (DID F015) */
typedef struct DID_ServiceAlignment_Result_Tag
{
   uint8_t AlignmentModeOut;
   uint8_t AlignmentServiceStatus;
   uint8_t AlignmentError;
   float32_t AlignmentAzimuth;
   float32_t AlignmentElevation;
   float32_t AlignmentRoll;
   float32_t AzimuthStd;
   float32_t ElevationStd;
   float32_t RollStd;
   float32_t CalTime;
   uint8_t ProgressPercent;
   uint8_t CalDisplay;
   uint32_t InitialAlignmentResultAzimuthUpdates;
   uint32_t InitialAlignmentResultElevationUpdates;
   uint32_t InitialAlignmentResultRollUpdates;
   float32_t InitialAlignmentResultHostSpeedCompensationFactor;
   uint8_t VehicleCondition;
   uint32_t AverageNumberOfDetections;
   uint32_t AverageSpeed;
   uint32_t DistanceAbsolute;
   uint32_t DistanceEffective;
   uint32_t DurationAbsolute;
   uint32_t DurationEffective;
   uint8_t InitialLastSuccessfulAlignmentMode;
   float32_t InitialAlignmentResultAzimuth;
   float32_t InitialAlignmentResultElevation;
   float32_t InitialAlignmentResultRoll;
} DID_ServiceAlignment_Result_T;

/* Structure to store non-configurable parameters for service alignment (DID F014) */
typedef struct DID_ServiceAlignment_NonConfig_Param_Tag
{
   uint16_t AlignService_Abs_Dist_Th;
   uint16_t AlignService_Eff_Dist_Th;
   uint16_t AlignService_Abs_Duration_Th;
   uint16_t AlignService_Eff_Duration_Th;
   uint16_t AlignService_Vel_Min;
   uint16_t AlignService_Vel_Max;
   uint16_t AlignService_Yawrate_Max;
} DID_ServiceAlignment_NonConfig_Param_T;

/* Structure for static alignment configurable parameters (F012 read / F013 write) */
typedef struct FD_02_Alignment_Param_Tag
{
   uint16_t AlignmentStatic_AzimuthUpper_Threshold;
   int16_t AlignmentStatic_AzimuthLower_Threshold;
   uint16_t AlignmentStatic_ElevationUpper_Threshold;
   int16_t AlignmentStatic_ElevationLower_Threshold;
   int16_t AlignmentStatic_TargetAzimuth;
   int16_t AlignmentStatic_TargetElevation;
   uint16_t AlignmentStatic_TargetDistance;
} FD_02_Alignment_Param_T;

/* Structure for manual alignment parameters (DID F01B read/write) */
typedef struct FD_0B_Alignment_Param_Tag
{
   Dt_Align_Mode_T AlignmentModeIn;
   Dt_Align_Mode_T InitialLastSuccessfulAlignmentMode;
   int32_t IntialMisalignmentAngleAzimuth;
   int32_t IntialMisalignmentAngleElevation;
} FD_0B_Alignment_Param_T;

/* Union to represent a 32-bit unsigned integer as bytes */
typedef union Uint32_Byte_Tag
{
   uint32_t value;
   struct
   {
      uint8_t byte1;
      uint8_t byte2;
      uint8_t byte3;
      uint8_t byte4;
   } bytes;
} Uint32_Byte_t;

/* Union to represent a 16-bit unsigned integer as bytes */
typedef union Uint16_Byte_Tag
{
   uint16_t value;
   struct
   {
      uint8_t byte1;
      uint8_t byte2;
   } bytes;
} Uint16_Byte_t;

/* Union to represent a 32-bit signed integer as bytes */
typedef union int32_Byte_Tag
{
   int32_t value;
   struct
   {
      int8_t byte1;
      int8_t byte2;
      int8_t byte3;
      int8_t byte4;
   } bytes;
} int32_Byte_t;

/* Union to represent a 16-bit signed integer as bytes */
typedef union int16_Byte_Tag
{
   int16_t value;
   struct
   {
      int8_t byte1;
      int8_t byte2;
   } bytes;
} int16_Byte_t;

/*============================================================================*\
   OBJECT DEFINITIONS
 \*============================================================================*/

/* EXPORTED OBJECTS ----------------------------------------------------------*/
extern Dt_Alignment_Handler AlignmentHandler;
extern Dt_AlignmentAuto AlignmentAuto;
extern Dt_AlignmentService AlignmentService;
extern Dt_AlignmentStatic AlignmentStatic;
extern Dt_Alignment_M2D_Data alignment_m2d_data;
extern AlignmentInitialCals_T alignment_initial_cals;
extern volatile uint8_t RID_Align_Cmd_Rcvd;
extern volatile uint8_t RID_Manual_Align_Cmd_Rcvd;
extern uint8_t StaticAlignmentStarted;
extern uint8_t StaticAlignmentStoppedByTester;
extern uint8_t ServiceAlignmentStarted;
extern uint8_t ServiceAlignmentStoppedByTester;

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void Routine_Start_StaticAlignment(void);
void Routine_Stop_StaticAlignment(void);
void Routine_Result_StaticAlignment(RID_StaticAlignment_Result_Data_T *Alignment_Static_Result);

void Routine_Start_ServiceAlignment(void);
void Routine_Stop_ServiceAlignment(void);
void Routine_Result_ServiceAlignment(RID_ServiceAlignment_Result_Data_T *Alignment_Service_Result);

void Data_Auto_Alignment_Status(Dt_Auto_Alignment_Status_Information *DID_AA_Status);

void Data_Result_StaticAlignment(DID_StaticAlignment_Result_T *Alignment_Static_Result);
void Data_NonConfig_Param_StaticAlignment(DID_StaticAlignment_NonConfig_Param_T *AlignmentNonConfigParam);
void Data_Config_Param_ReadStaticAlignment(Dt_Static_Alignment_Engineering_Parameters *AlignmentConfigParam);
void Data_Config_Param_WriteStaticAlignment(
   Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *AlignmentConfigParam);

void Data_Result_ServiceAlignment(Dt_Service_Alignment_Result_Parameters *Alignment_Service_Result);
void Data_NonConfig_Param_ServiceAlignment(
   Dt_Service_Alignment_Engineering_Non_Configuration_Parameters *AlignServiceNonConfigParam);

void Data_Params_WriteManualAlignment(Dt_Manual_Alignment_Execution_Data_CRC *ManualAlignment);
void Data_Params_ReadManualAlignment(Dt_Manual_Alignment_Execution_Data_CRC *ManualAlignment);

#endif /* SWC_PROJECT_RADAR_ALIGNMENT_HANDLER_H  */
