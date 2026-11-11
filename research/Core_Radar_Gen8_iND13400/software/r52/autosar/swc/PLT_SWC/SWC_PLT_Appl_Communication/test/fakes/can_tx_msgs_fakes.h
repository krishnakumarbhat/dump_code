/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_Communication_fake.h
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
 * Fake/Mock header file for SWC_PLT_Appl_Communication unit testing
 *
 * @section ABBR ABBREVIATIONS:
 *   - FFF: Fake Function Framework
 *   - CAN: Controller Area Network
 *   - SOME/IP: Scalable service-Oriented MiddlewarE over IP
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWC_PLT_Appl_Communication Unit Test Design
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#ifndef SWC_PLT_APPL_COMMUNICATION_FAKE_H
#define SWC_PLT_APPL_COMMUNICATION_FAKE_H

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

/*===========================================================================*
 * Stub headers to prevent including real AUTOSAR headers
 *===========================================================================*/
#ifndef CANSM_COMM_H
   #define CANSM_COMM_H
#endif

#ifndef COMM_CFG_H
   #define COMM_CFG_H
#endif

#ifndef RTE_COMM_TYPE_H
   #define RTE_COMM_TYPE_H
#endif

#ifndef RTE_SWC_PLT_APPL_COMMUNICATION_H
   #define RTE_SWC_PLT_APPL_COMMUNICATION_H
#endif

#ifndef SCHM_COM_H
   #define SCHM_COM_H
#endif

#ifndef CAN_RX_MSGS_H
   #define CAN_RX_MSGS_H
#endif

#ifndef CAN_TX_MSGS_H
   #define CAN_TX_MSGS_H
#endif

#ifndef SOMEIP_SERVICES_H
   #define SOMEIP_SERVICES_H
#endif

#ifdef __cplusplus
extern "C"
{
#endif
   /* AUTOSAR Standard Types */
   typedef uint8_t Std_ReturnType;
   typedef uint16_t Com_IpduGroupIdType;
   typedef uint8_t boolean;
   typedef uint8_t uint8;
   typedef uint16_t uint16;
   typedef uint32_t uint32;
   typedef int8_t sint8;
   typedef int16_t sint16;
   typedef signed long sint32; /* Match AUTOSAR Platform_Types.h definition */
   typedef float float32;
   typedef double float64;

#ifndef TRUE
   #define TRUE (1U)
#endif
#ifndef FALSE
   #define FALSE (0U)
#endif
#ifndef RTE_E_OK
   #define RTE_E_OK 0x00U
#endif
   /* ComM Types */
   typedef uint8_t ComM_ModeType;
#define COMM_NO_COMMUNICATION   0U
#define COMM_FULL_COMMUNICATION 2U

   typedef uint8_t ComM_UserHandleType;
#define ComMConf_ComMUser_CN_PCAN_RADAR_d6cf874b 0U
#define ComMConf_ComMUser_CN_VCAN_RADAR_4b138c58 1U

#ifndef ALIGNMENT_RUNNING
   #define ALIGNMENT_RUNNING (1U)
#endif

#ifndef ALIGNMENT_PAUSED
   #define ALIGNMENT_PAUSED (2U)
#endif

#define Rte_TypeDef_Dt_Align_Mode_T
   typedef unsigned char Dt_Align_Mode_T;

#define Rte_TypeDef_Dt_DRA_Detection_Coordinate_System
   typedef uint8 Dt_DRA_Detection_Coordinate_System;

#define Rte_TypeDef_Dt_AlignAuto_Error
   typedef uint8 Dt_AlignAuto_Error;

#define Rte_TypeDef_Dt_AlignHandler_Error
   typedef uint8 Dt_AlignHandler_Error;

#define Rte_TypeDef_Dt_Align_Status
   typedef uint8 Dt_Align_Status;

#define Rte_TypeDef_Dt_Align_Veh_Cond
   typedef uint8 Dt_Align_Veh_Cond;

#define Rte_TypeDef_Dt_AlignmentModeIn_T
   typedef uint8 Dt_AlignmentModeIn_T;

#define Rte_TypeDef_Rte_DT_Dt_Dynamic_Alignment_Data_6
   typedef float32 Rte_DT_Dt_Dynamic_Alignment_Data_6[4];

#define Rte_TypeDef_Rte_DT_Dt_Dynamic_Alignment_Data_30
   typedef float32 Rte_DT_Dt_Dynamic_Alignment_Data_30[4];

#define Rte_TypeDef_Dt_Dynamic_Alignment_Data
   typedef struct
   {
      float32 initial_vacs_boresight_az_estimated;
      float32 initial_vacs_boresight_el_estimated;
      float32 initial_speed_compensation_factor;
      float32 max_abs_misalignment_az;
      float32 short_track_target_height;
      float32 short_track_target_range_rate;
      Rte_DT_Dt_Dynamic_Alignment_Data_6 az_scf_kf_covariance;
      float32 el_kf_covariance;
      float32 iso_sensor_x_posn;
      float32 iso_sensor_y_posn;
      float32 iso_sensor_z_posn;
      float32 iso_sensor_yaw;
      float32 iso_sensor_pitch;
      float32 iso_sensor_roll;
      float32 distance_rear_axle_to_front_bumper;
      float32 max_abs_misalignment_el_sky;
      float32 max_abs_misalignment_el_ground;
      float32 aacurrent_azimuth;
      float32 aacurrent_elevation;
      uint32 initial_num_updates_az;
      float32 initial_num_updates_el;
      uint8 mount_loc;
      uint8 short_track_exit_condition;
      uint8 f_data_valid;
      uint8 initial_align_quality_factor_el;
      uint8 initial_align_quality_factor_az;
      uint8 align_cmd;
      uint8 auto_align_status;
      float32 initial_vacs_boresight_rl_estimated;
      uint8 initial_num_updates_rl;
      Rte_DT_Dt_Dynamic_Alignment_Data_30 el_roll_kf_covariance;
      uint8 Align_RadarOperation_Mode;
      uint8 coordinate_system_input;
   } Dt_Dynamic_Alignment_Data;

#define Rte_TypeDef_Dt_Static_Alignment_Data
   typedef struct
   {
      float32 yaw;
      float32 pitch;
      float32 plate_angle_deg_scs;
      float32 plate_distance;
      float32 polarity;
      float32 horz_angle_min;
      float32 horz_angle_max;
      float32 vert_angle_min;
      float32 vert_angle_max;
      float32 plate_lat_position;
      uint8 mount_loc;
      uint8 align_cmd;
      float32 max_abs_misalignment_az;
      float32 max_abs_misalignment_el_sky;
      float32 max_abs_misalignment_el_ground;
      float32 target_height_over_ground;
      uint16 k_num_valid_scan_needed;
      uint16 k_max_number_of_scans_allowed;
      float32 target_range_rate;
      uint8 target_type_select;
      uint8 f_data_valid;
   } Dt_Static_Alignment_Data;

#define Rte_TypeDef_Dt_AlignmentAuto
   typedef struct
   {
      float32 StartAzimuth;
      float32 StartElevation;
      float32 AACurrentAzimuth;
      float32 AACurrentElevation;
      float32 AAAzimuthStd;
      float32 AAElevationStd;
      float32 AARollStd;
      float32 Az_Err_positive;
      float32 Az_Err_negative;
      float32 El_Err_positive;
      float32 El_Err_negative;
      float32 RollError_positive;
      float32 RollError_negative;
      float32 HostScf;
      uint32 AzimuthNumUpdates;
      uint32 ElevationNumUpdates;
      Dt_AlignAuto_Error AutoAlignmentFailRootCause;
      Dt_Align_Status AlignAutoStatus;
      uint8 HostScf_QF;
      float32 StartRoll;
      float32 AACurrentRoll;
      uint32 RollUpdates;
   } Dt_AlignmentAuto;

#define Rte_TypeDef_Dt_AlignmentService
   typedef struct
   {
      uint32 DistanceAbsolute;
      uint32 DistanceEffective;
      uint32 AvgNumOfDet;
      uint32 DurationAbsolute;
      uint32 DurationEffective;
      float32 AverageSpeed;
      Dt_Align_Status AlignmentServiceSt;
      Dt_Align_Veh_Cond VehicleCondition;
   } Dt_AlignmentService;

#define Rte_TypeDef_Dt_AlignmentShortTrack
   typedef struct
   {
      Dt_Align_Status AlignShortTrackSt;
   } Dt_AlignmentShortTrack;

#define Rte_TypeDef_Dt_AlignmentStatic
   typedef struct
   {
      float32 MeasuredAzimuth;
      float32 MeasuredElevation;
      float32 Measured_Az_Std;
      float32 Measured_El_Std;
      float32 MeasuredRange;
      float32 MeasuredRangeStd;
      float32 MeasuredRangeRate;
      float32 MeasuredRangeRateStd;
      float32 MeasuredAmplitude;
      float32 MeasuredAmpStd;
      Dt_Align_Status AlignmentStaticStatus;
      uint8 StatusOfPlate;
      uint8 StatusOfAzimuth;
      uint8 StatusOfElevation;
      boolean ImpactByInterference;
   } Dt_AlignmentStatic;

#define Rte_TypeDef_Dt_Alignment_Handler
   typedef struct
   {
      float32 InitialAlignmentResultAz;
      float32 InitialAlignmentResultEl;
      float32 InitialAlignmentResultHostSCF;
      uint32 InitialAlignmentResultAzUpdates;
      uint32 InitialAlignmentResultElUpdates;
      float32 AlignmentAzimuth;
      float32 AlignmentElevation;
      float32 AzimuthStd;
      float32 ElevationStd;
      float32 calTime;
      uint8 CalDisplay;
      uint8 ProgressPercent;
      Dt_AlignHandler_Error AlignmentError;
      uint8 ElevationQuality;
      uint8 AzimuthQuality;
      Dt_Align_Mode_T Alignment_modeIn;
      Dt_Align_Mode_T AlignmentModeOut;
      Dt_Align_Mode_T InitialLastSuccessAlignmentMode;
      uint8 Radar_Type_Input;
      Dt_DRA_Detection_Coordinate_System CoordinateSystem_Input;
      float32 InitialAlignmentResultRoll;
      uint32 InitialAlignmentResultRollUpdates;
      float32 AlignmentRoll;
      float32 RollStd;
   } Dt_Alignment_Handler;

/* Function pointer for AUTOSAR FUNC macro */
#define FUNC(rettype, memclass) rettype
#define SWC_PLT_Appl_Communication_CODE

   /* Mock CAN Functions */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, CanSM_RequestComMode, ComM_UserHandleType, ComM_ModeType);
   DECLARE_FAKE_VOID_FUNC(Com_MainFunctionTx_ComMainFunctionTx_Event);

   /* Mock SOME/IP Functions */
   DECLARE_FAKE_VOID_FUNC(Init_Provided_Services);
   DECLARE_FAKE_VOID_FUNC(Init_Consumed_Services);
   DECLARE_FAKE_VOID_FUNC(Process_Provided_Services);
   DECLARE_FAKE_VOID_FUNC(Process_Consumed_Services);

   /* Mock CAN Processing Functions */
   DECLARE_FAKE_VOID_FUNC(Process_Received_CAN_Msgs);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Status_001_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Status_001_Messages_2nd_VCAN);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Status_002_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Alignment_Status_001_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Capability_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Tracker_Status_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Header_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Header_Messages_2nd_VCAN);
   DECLARE_FAKE_VOID_FUNC(Send_Alignment_Status_002_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Radar_Detection_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Tracker_Header_Messages);
   DECLARE_FAKE_VOID_FUNC(Send_Tracker_Objects_On_CAN);
   DECLARE_FAKE_VOID_FUNC(Com_IpduGroupStop, Com_IpduGroupIdType);
   DECLARE_FAKE_VOID_FUNC(Com_IpduGroupStart, Com_IpduGroupIdType, boolean);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentStatic *, Get_AlignmentStatic);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentService *, Get_AlignmentService);
   DECLARE_FAKE_VALUE_FUNC(Dt_AlignmentShortTrack *, Get_AlignmentShortTrack);

#ifdef __cplusplus
}
#endif

#endif /* SWC_PLT_APPL_COMMUNICATION_FAKE_H */
