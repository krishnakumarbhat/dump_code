#ifndef SWC_PLT_RADAR_ALIGNMENT_HANDLER_H /* { */
#define SWC_PLT_RADAR_ALIGNMENT_HANDLER_H
/*===========================================================================*\
 * FILE: SWC_PLT_Radar_Alignment_Handler.h
 *===========================================================================
 * Copyright 2022 Aptiv, Inc., All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * %full_filespec:  SWC_PLT_Radar_Alignment_Handler.h~1:incl:kok_css2#1 %
 * %version:  1 %
 * %derived_by:  vj1jjy %
 * %date_modified:  Thur June 23 16:11:01 2023 %
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *  This file contains functions & object definitions for storing misalignment angle in NvM.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *       TODO: Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

#ifndef UT_APPL_COMM /*Added for UT to not include of rte_type.h in SWC_PLT_Appl_Communication_unit_test.cc*/
   #include "Rte_Type.h"
#endif
#include "dra_types.h"
#include "dsp_setup.h"
#include "radar_data_quality.h"
#include "sensor_position.h"
#include "smc_cal.h"

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
#define MAX_RADAR_SENSOR_POS (14U)
/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

#define ALIGNMENT_COMPLETION_AZ    (100U)
#define ALIGNMENT_COMPLETION_EL    (100U)
#define SEC_TO_50mSEC              (20)
#define MAX_RADAR_SENSOR_POS       (14U)
#define VEH_SPEED_QF_VALUE         (2U)
#define VEH_YAW_QF_VALUE           (2U)
#define LROS_DRIVE_REVERSE_VALUE   (1U)
#define AZIMUTH_THRESHOLD_VALUE    (3.14F)
#define ELEVATION_THRESHOLD_VALUE  (3.14F)
#define ROLL_THRESHOLD_VALUE       (3.14159F)
#define AZ_EL_UPDATE_MAX_VALUE     (65535U)
#define AZ_EL_UPDATE_MIN_VALUE     (0U)
#define ALIGNMNET_MODE_MAX_VALUE   (5U)
#define ALIGNMNET_MODE_MIN_VALUE   (0U)
#define HOST_SPEED_COMP_FACTOR_MAX (1.2F)
#define HOST_SPEED_COMP_FACTOR_MIN (0.80F)
#define SEC_TO_5MIN                (300)
#ifndef Deg2Radians
   #define Deg2Radians (0.0174532925199433f)
#endif
#ifndef Rad2Degree
   #define Rad2Degree (57.2957795130823069f)
#endif
#ifndef PERCENTAGE
   #define PERCENTAGE (100U)
#endif
#ifndef METER_TO_MILLIMETER
   #define METER_TO_MILLIMETER (1000.0F) /* Conversion factor from Milli Second to Second */
#endif
#define POSITIVE_POLARITY                     (1.0F)
#define NEGATIVE_POLARITY                     (-1.0F)
#define ROLL_THRESHOLD_VALUE                  (3.14159F) /* Threshold for roll misalignment in radians */
#define SENSOR_DOWNMOUNT_ROLL_SMC             (3.141F)
#define INITIAL_VACS_BORESIGHT_AZ_ESTIMATED   (50.0F * DRA_DEG2RAD) /* Initial estimated azimuth boresight in radians */
#define MAX_ABS_MISALIGNMENT_AZ               (7.5F * DRA_DEG2RAD)
#define MAX_ABS_MISALIGNMENT_EL               (7.5F * DRA_DEG2RAD)
#define MAX_AA_ANGLE_CHG_LIMIT                (8 * Deg2Radians)
#define MAX_AA_ROLL_ANGLE_CHG_LIMIT           (2 * Deg2Radians)
#define NVM_UPDATE_DEGREE_THRESHOLD           (0.2F) /* Misalignment angle Threshold for updating NvM in degrees */
#define DETECTION_INPUT_ERR_TRANSITION_BUFFER (3U)   /* Buffer cycles for BBE32/R52 sync (150ms at 50ms cycle) */
#ifndef SECONDS_TO_MILLISECONDS
   #define SECONDS_TO_MILLISECONDS (1000.0F) /* Conversion factor from  Second to Milli Second */
#endif

typedef struct AlignmentDynamic_Tag
{
   float32_t AzimuthMisalignmentAngle;
   float32_t ElevationMisalignmentAngle;
   float32_t AzimuthStdMisalignmentAngle;
   float32_t ElevationStdMisalignmentAngle;
   float32_t ProgressPercent_az;
   float32_t ProgressPercent_el;
   float32_t AbsoluteTime;
   float32_t EffectiveTimeAzimuth;
   float32_t EffectiveTimeElevation;
   float32_t AbsoluteDistance;
   float32_t EffectiveDistanceAzimuth;
   float32_t EffectiveDistanceElevation;
   float32_t AbsoluteAverageSpeed;
   float32_t EffectiveAverageSpeedAzimuth;
   float32_t EffectiveAverageSpeedElevation;
   uint32_t NumberOfUpdatesAzimuth;
   uint32_t NumberOfUpdatesElevation;
   DRA_Algo_Mode_T DynamicAlignmentModeOut;
   uint8_t AzimuthQuality;
   uint8_t ElevationQuality;
   uint8_t ErrSt_out_of_bounds_az;
   uint8_t ErrSt_out_of_bounds_el;
   uint8_t Failstatus_Initialization;
   uint8_t Failstatus_Blockage;
   uint8_t FailStatus_Vehicle_In;
} AlignmentDynamic_T;

typedef struct
{
   uint16_t nvm_cycle_time;       /* sec*/
   float32_t azimuth_threshold;   /*rad*/
   float32_t elevation_threshold; /*rad*/
   float32_t critical_misalignment_threshold;
} AlignmentAutoCals_T;
typedef struct
{
   uint16_t absolute_distance_threshold; /* m*/
   uint16_t effective_distance_threshold;
   uint16_t absolute_duration_threshold;  /* sec*/
   uint16_t effective_duration_threshold; /* sec*/
   uint16_t velocity_min;                 /*m/sec*/
   uint16_t velocity_max;                 /*190m/sec*/
   float32_t yawrate_max;                 /*rad/s*/
   uint8_t short_track_submode;           /* Short Track submode selection: 0=Standard Short Track,
                                             1=Short Track Guardrail or fast service */
} AlignmentInitialCals_T;

typedef struct
{
   float32_t AACurrentAzimuth;
   float32_t AACurrentElevation;
   float32_t AACurrentRoll;
   float32_t InitialAlignmentResultAzimuth;
   float32_t InitialAlignmentResultElevation;
   float32_t InitialAlignmentResultRoll;
   float32_t InitialLastSuccessfulAlignmentMode;
   float32_t ElevationUpdates;
   float32_t AzimuthUpdates;
   float32_t RollUpdates;
   float32_t InitialAlignmentResultElevationUpdates;
   float32_t InitialAlignmentResultHostSpeedCompensationFactor;
   float32_t HostSpeedCompensationFactor;
   float32_t InitialAlignmentResultAzimuthUpdates;
   float32_t InitialAlignmentResultRollUpdates;
   uint8_t AlignmentModeOut;
} Write_Alignment_NvM_Data_T;

typedef struct
{
   float32_t iso_sensor_yaw;
   float32_t iso_sensor_pitch;
   float32_t iso_sensor_roll;
} Sensor_Align_Mounting_Parameters_T;

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/

Dt_Dynamic_Alignment_Data *Get_Dynamic_Alignment_M2D(void);
Dt_Static_Alignment_Data *Get_Static_Alignment_M2D(void);
Dt_Alignment_Handler *Get_AlignmentHandler(void);
Dt_AlignmentService *Get_AlignmentService(void);
Dt_AlignmentShortTrack *Get_AlignmentShortTrack(void);
Dt_AlignmentAuto *Get_AlignmentAuto(void);
Dt_AlignmentStatic *Get_AlignmentStatic(void);
void Auto_Align_OOR_Fault_Check(void);

#endif /*SWC_PLT_Radar_Alignment_Handler_H*/
