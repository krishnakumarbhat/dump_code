/*
 * File: VSE_Master_Model_WL_L2P_types.h
 *
 * Code generated for Simulink model 'VSE_Master_Model_WL_L2P'.
 *
 * Model version                  : 1.1208
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:08:25 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Safety precaution
 *    4. Execution efficiency
 *    5. MISRA C:2012 guidelines
 *    6. Traceability
 *    7. Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VSE_Master_Model_WL_L2P_types_h_
   #define RTW_HEADER_VSE_Master_Model_WL_L2P_types_h_
   #include "rtwtypes.h"
   #ifndef DEFINED_TYPEDEF_FOR_enum_quality_factor_T_
      #define DEFINED_TYPEDEF_FOR_enum_quality_factor_T_

typedef uint8_T enum_quality_factor_T;

      /* enum enum_quality_factor_T */
      #define UNDEFINED      ((enum_quality_factor_T)0U) /* Default value */
      #define TEMP_UNDEFINED ((enum_quality_factor_T)1U)
      #define NOT_ACCURATED  ((enum_quality_factor_T)2U)
      #define ACCURATED      ((enum_quality_factor_T)3U)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_VnetInVehicleStateEstimator_
      #define DEFINED_TYPEDEF_FOR_VnetInVehicleStateEstimator_

typedef struct
{
   enum_quality_factor_T rr_wheel_pulse_counter_qf;
   enum_quality_factor_T rl_wheel_pulse_counter_qf;
   enum_quality_factor_T fr_wheel_pulse_counter_qf;
   enum_quality_factor_T fl_wheel_pulse_counter_qf;
   boolean_T LongAcceleration_BSM_SNA;
   boolean_T VehicleSpeedVSOSig_SNA;
   real32_T VsVCAN_Trailer_ITBM_Power;
   real32_T VsVCAN_Nm_Trailer_AxleTrq;
   enum_quality_factor_T rear_rwa_speed_measured_rad_per_s_validity;
   enum_quality_factor_T rear_rwa_measured_rad_validity;
   enum_quality_factor_T rwa_speed_measured_rad_per_s_validity;
   enum_quality_factor_T rwa_measured_rad_validity;
   real32_T rear_rwa_speed_measured_rad_per_s;
   real32_T rear_rwa_measured_rad;
   real32_T rwa_speed_measured_rad_per_s;
   real32_T rwa_measured_rad;
   uint8_T gear_box_pos;
   real32_T pitch_rate;
   enum_quality_factor_T pitch_rate_qf;
   real32_T ego_vehicle_speed;
   enum_quality_factor_T ego_vehicle_speed_qf;
   real32_T ground_speed_gvpm;
   enum_quality_factor_T ground_speed_qf_gvpm;
   real32_T ego_yaw_rate;
   enum_quality_factor_T ego_yaw_rate_qf;
   real32_T yaw_rate_gvpm;
   enum_quality_factor_T yaw_rate_qf_gvpm;
   uint8_T vehicle_standstill;
   real32_T steering_whl_angle;
   enum_quality_factor_T steering_whl_angle_qf;
   real32_T steering_whl_speed_deg_per_s;
   real32_T ego_lateral_accel;
   enum_quality_factor_T ego_lateral_accel_qf;
   real32_T lateral_acceleration_gvpm;
   enum_quality_factor_T lateral_acceleration_qf_gvpm;
   real32_T ego_longitudinal_accel;
   enum_quality_factor_T ego_longitudinal_accel_qf;
   real32_T longitudinal_acceleration_gvpm;
   enum_quality_factor_T logitudinal_acceleration_qf_gvpm;
   real32_T vertical_acceleration;
   enum_quality_factor_T vertical_acceleration_qf;
   real32_T roll_rate;
   enum_quality_factor_T roll_rate_qf;
   real32_T fl_wheel_rot_speed_rpm;
   real32_T fr_wheel_rot_speed_rpm;
   real32_T fl_wheel_speed;
   enum_quality_factor_T fl_wheel_speed_qf;
   real32_T fr_wheel_speed;
   enum_quality_factor_T fr_wheel_speed_qf;
   real32_T tire_pressure_front_left_psi;
   real32_T tire_pressure_front_right_psi;
   uint8_T fl_wheel_spin;
   uint8_T fr_wheel_spin;
   uint8_T rl_wheel_spin;
   uint8_T rr_wheel_spin;
   uint8_T fl_wheel_pulse_counter;
   uint8_T fr_wheel_pulse_counter;
   uint8_T rl_wheel_pulse_counter;
   uint8_T rr_wheel_pulse_counter;
   boolean_T asr_active;
   boolean_T abs_active;
   uint8_T brake_padel_press;
   real32_T total_axle_torque_static;
   real32_T engine_rpm;
   real32_T brk_trq;
   real32_T trq_amp_trans;
   uint8_T trailer_connection_sts;
   uint8_T trailer_sts;
   uint8_T veh_ignition_sts;
   uint8_T bsd_drv_setting;
} VnetInVehicleStateEstimator;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_Tracker_VSE_
      #define DEFINED_TYPEDEF_FOR_Tracker_VSE_

typedef struct
{
   real32_T VehSpeedCompFac_KA_2;
   enum_quality_factor_T VehSpeedCompFac_KA_QF_2;
   real32_T VehSpeedCompFac_KA_3;
   enum_quality_factor_T VehSpeedCompFac_KA_QF_3;
   real32_T VehSpeedCompFac_KA_4;
   enum_quality_factor_T VehSpeedCompFac_KA_QF_4;
   real32_T VehSpeedCompFac_KA_5;
   enum_quality_factor_T VehSpeedCompFac_KA_QF_5;
   real32_T VehSpeedCompFac_KA_1;
   enum_quality_factor_T VehSpeedCompFac_KA_QF_1;
} Tracker_VSE;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_Vehicle_Parameters_
      #define DEFINED_TYPEDEF_FOR_Vehicle_Parameters_

typedef struct
{
   real32_T front_bumper_sensor_lat_distance_from_rear_axle;
   real32_T rear_right_sensor_lat_distance_from_rear_axle;
   real32_T rear_left_sensor_lat_distance_from_rear_axle;
   real32_T front_right_sensor_lat_distance_from_rear_axle;
   real32_T front_left_sensor_lat_distance_from_rear_axle;
   real32_T front_right_sensor_long_distance_from_rear_axle;
   real32_T rear_left_sensor_long_distance_from_rear_axle;
   real32_T rear_right_sensor_long_distance_from_rear_axle;
   real32_T front_bumper_sensor_long_distance_from_rear_axle;
   real32_T front_left_sensor_long_distance_from_rear_axle;
   real32_T k_wheel_base;
   real32_T k_dist_rear_axle_to_vcs;
   real32_T k_long_dist_radar_to_rear_axle;
   real32_T k_lat_dist_radar_to_rear_axle;
   real32_T k_steering_gear_ratio;
   real32_T k_understeer_coefficient;
   real32_T k_rear_cornering_compliance;
   real32_T k_vehicle_width;
   real32_T k_cog_x;
   real32_T k_cog_y;
   real32_T k_front_wheel_radius_static_loaded;
   real32_T k_front_track_width;
} Vehicle_Parameters;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_LAST_KEY_CYCLE_
      #define DEFINED_TYPEDEF_FOR_LAST_KEY_CYCLE_

typedef struct
{
   real32_T nvm_last_rem_swa_bias_deg;
   boolean_T nvm_f_last_rem_swa_bias;

   /* NVM saved initialization of Speed Comp Factor */
   real32_T nvm_last_rem_speed_comp;
   real32_T nvm_last_rem_stop_yaw_bias_primary_radps;
   real32_T nvm_last_rem_stop_yaw_bias_secondary_radps;
} LAST_KEY_CYCLE;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_Tracker_VSE_Trailer_Signals_
      #define DEFINED_TYPEDEF_FOR_Tracker_VSE_Trailer_Signals_

typedef struct
{
   /* Radar Trailer connection status */
   uint8_T VsTracker_TrailerPresence;

   /* Confidence level for radar trailer connection status */
   uint8_T VsTracker_TrailerPresenceConfLvl;

   /* Trailer length */
   real32_T VsTracker_m_TrailerLength;

   /* Confidence level for Trailer length */
   uint8_T VsTracker_TrailerLengthConfLvl;

   /* Trailer width */
   real32_T VsTracker_m_TrailerWidth;

   /* Confidence level for Trailer width */
   uint8_T VsTracker_TrailerWidthConfLvl;

   /* Hitch angle */
   real32_T VsTracker_rad_TrailerAngle;

   /* Hitch angle rate */
   real32_T VsTracker_rps_TrailerAngleRate;

   /* Confidence level for Hitch angle */
   uint8_T VsTracker_TrailerAngleConfLvl;

   /* Confidence level for Hitch angle rate */
   uint8_T VsTracker_TrailerAngleRateConfLvl;

   /* Gap between host vehicle and trailer */
   real32_T VsTracker_m_TrailerHVGap;

   /* trailer detection status */
   uint8_T VsTracker_RadarDetectSts;

   /* radar detection timer */
   int32_T VsTracker_ms_RadarDetectTimer;

   /* stationary timer */
   int32_T VsTracker_ms_StationaryTimer;
} Tracker_VSE_Trailer_Signals;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_AptivCfg_
      #define DEFINED_TYPEDEF_FOR_AptivCfg_

typedef struct
{
   /* Steering Sytem Type */
   uint8_T CsPROXI_SteeringSystemInputType;

   /* TTM trailer is present or not */
   boolean_T CsPROXI_CANNode63_TTM;

   /* ITBM/ITCM trailer is present or not */
   boolean_T CsPROXI_CANNode95_ITBM;

   /* Steering Ratio rack type */
   uint8_T CsPROXI_SteeringRatioRackPinionType;
} AptivCfg;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_VSE_OUT_
      #define DEFINED_TYPEDEF_FOR_VSE_OUT_

typedef struct
{
   uint64_T timestamp_us;
   uint32_T veh_index;
   real32_T raw_speed_mps;
   enum_quality_factor_T raw_speed_qf;
   real32_T speed_compensation_factor;
   enum_quality_factor_T speed_compensation_factor_qf;
   real32_T filt_veh_speed_over_ground;
   enum_quality_factor_T filt_veh_speed_over_ground_qf;
   real32_T signed_filt_veh_speed_over_ground;
   real32_T wheel_odo_speed_over_ground;
   enum_quality_factor_T wheel_odo_speed_over_ground_qf;
   real32_T raw_lat_accel;
   enum_quality_factor_T raw_lat_accel_qf;
   real32_T raw_long_accel;
   enum_quality_factor_T raw_long_accel_qf;
   real32_T raw_vert_accel;
   enum_quality_factor_T raw_vert_accel_qf;
   real32_T VCS_Lat_Accel;
   real32_T VCS_Long_Accel;
   enum_quality_factor_T VCS_Lat_Accel_QF;
   enum_quality_factor_T VCS_Long_Accel_QF;
   real32_T comp_lat_accel;
   enum_quality_factor_T comp_lat_accel_qf;
   real32_T comp_long_accel;
   enum_quality_factor_T comp_long_accel_qf;
   real32_T wheel_odo_long_accel;
   enum_quality_factor_T wheel_odo_long_accel_qf;
   real32_T comp_vert_accel;
   enum_quality_factor_T comp_vert_accel_qf;
   real32_T vert_jerk;
   enum_quality_factor_T vert_jerk_qf;
   real32_T lateral_jerk;
   enum_quality_factor_T lateral_jerk_qf;
   real32_T longitudinal_jerk;
   enum_quality_factor_T longitudinal_jerk_qf;
   real32_T bank_angle_deg;
   enum_quality_factor_T bank_angle_qf;
   real32_T grade_angle_deg;
   enum_quality_factor_T grade_angle_qf;
   real32_T raw_yaw_rate_rps;
   enum_quality_factor_T raw_yaw_rate_qf;
   boolean_T f_yaw_stop_bias_converged;
   real32_T raw_roll_rate_rps;
   enum_quality_factor_T raw_roll_rate_qf;
   real32_T raw_pitch_rate_rps;
   enum_quality_factor_T raw_pitch_rate_qf;
   real32_T raw_steering_angle_deg;
   enum_quality_factor_T raw_steering_angle_qf;
   real32_T comp_steering_angle_deg;
   enum_quality_factor_T comp_steering_angle_qf;
   real32_T swa_bias_deg_converged_to_nvm;
   boolean_T f_swa_bias_converged_to_nvm;
   boolean_T f_swa_bias_converged_internal;
   real32_T road_wheel_angle_deg;
   enum_quality_factor_T road_wheel_angle_qf;
   real32_T steering_angle_rate_filt_degpsec;
   real32_T yaw_rate_sa;
   enum_quality_factor_T yaw_rate_sa_qf;
   real32_T yaw_rate_bias;
   enum_quality_factor_T yaw_rate_bias_qf;
   real32_T stop_yaw_bias_nvm_write_primary;
   real32_T stop_yaw_bias_nvm_write_secondary;
   real32_T comp_yaw_rate_unfiltered;
   real32_T comp_yaw_rate_filtered;
   enum_quality_factor_T comp_yaw_rate_qf;
   real32_T roll_rate_bias;
   real32_T comp_roll_rate_unfiltered;
   real32_T comp_roll_rate_filtered;
   enum_quality_factor_T comp_roll_rate_qf;
   real32_T pitch_rate_bias;
   real32_T comp_pitch_rate_unfiltered;
   real32_T comp_pitch_rate_filtered;
   enum_quality_factor_T comp_pitch_rate_qf;
   real32_T curvature_rear_axle;
   real32_T sideslip_rear_axle;
   real32_T vcs_sideslip;
   real32_T vcs_long_velocity;
   real32_T vcs_lat_velocity;
   real32_T sensor_sideslip;
   real32_T sensor_long_velocity;
   real32_T sensor_lat_velocity;
   real32_T cog_long_vel;
   real32_T cog_lat_vel;
   real32_T cog_long_accel;
   real32_T cog_lat_accel;
   uint8_T stationary;
   boolean_T f_stationary_vse;
   uint8_T reverse_status;
   uint8_T motion_direction;
   boolean_T f_speed_rationality_check_passed;
   boolean_T f_yawrate_rationality_check_passed;
   boolean_T f_steering_rationality_check_passed;
   boolean_T f_lataccel_rationality_check_passed;
   boolean_T f_longaccel_rationality_check_passed;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_primary_rawspeed_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_secondary_rawspeed_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_primary_rawyawrate_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_secondary_rawyawrate_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_primary_rawlataccel_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_secondary_rawlataccel_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_primary_rawlongaccel_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_secondary_rawlongaccel_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_rawsteeringangle_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_compspeed_plausibility_fault;

   /* 1- Fault, 0 - No Fault */
   boolean_T f_compyawrate_plausibility_fault;
   real32_T rwa_measured_rad;
   enum_quality_factor_T rwa_measured_rad_validity;
   real32_T rwa_speed_measured_rad_per_s;
   enum_quality_factor_T rwa_speed_measured_rad_per_s_validity;
   real32_T rear_rwa_measured_rad;
   enum_quality_factor_T rear_rwa_measured_rad_validity;
   real32_T rear_rwa_speed_measured_rad_per_s;
   enum_quality_factor_T rear_rwa_speed_measured_rad_per_s_validity;
   real32_T Lat_Delta_ULVC;
   real32_T Long_Delta_ULVC;
   real32_T Heading_Delta_ULVC;
   enum_quality_factor_T Heading_Delta_ULVC_QF;
   real32_T front_left_sensor_long_velocity_ULVC;
   real32_T front_left_sensor_lat_velocity_ULVC;
   real32_T front_right_sensor_long_velocity_ULVC;
   real32_T front_right_sensor_lat_velocity_ULVC;
   real32_T rear_left_sensor_long_velocity_ULVC;
   real32_T rear_left_sensor_lat_velocity_ULVC;
   real32_T rear_right_sensor_long_velocity_ULVC;
   real32_T rear_right_sensor_lat_velocity_ULVC;
   real32_T front_bumper_sensor_long_velocity_ULVC;
   real32_T front_bumper_sensor_lat_velocity_ULVC;
   real32_T Road_Grade_Accel;
   enum_quality_factor_T Road_Grade_Accel_QF;

   /* Updates with addition of new modules/removal of modules/change in output interface */
   uint8_T vse_major_version;

   /* Updates for internal functional changes to algorithms */
   uint8_T vse_minor_version;

   /* Updates after non-functional changes to algorithm, e.g. fixing MISRA compliance warnings */
   uint8_T vse_field_version;

   /* Updates when calibrations are changed without any other code change */
   uint8_T vse_calibration_version;
} VSE_OUT;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_enum_road_type_T_
      #define DEFINED_TYPEDEF_FOR_enum_road_type_T_

typedef int32_T enum_road_type_T;

      /* enum enum_road_type_T */
      #define UNKNOWN_ROAD      (0) /* Default value */
      #define STRAIGHT_ROAD     (1)
      #define CURVED_ROAD       (2)
      #define INTERMEDIATE_ROAD (3)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_VSE_RESIM_T_
      #define DEFINED_TYPEDEF_FOR_VSE_RESIM_T_

typedef struct
{
   real32_T yaw_rate_bias1;
   real32_T yaw_rate_bias2;
   real32_T yaw_rate_bias_fast_bias1;
   real32_T yaw_rate_bias_fast_bias2;
   real32_T comp_yaw_rate_diff_filt;
   real32_T yaw_rate_bias_diff;
   enum_road_type_T road_type;
   boolean_T f_yaw_rate_bias_shift;
   boolean_T f_Yaw_Rate_Bias_Converged;
   boolean_T f_stop_bias_converged;
   boolean_T f_yaw_rate_steady;
   boolean_T f_input_invalid_persistent;
   boolean_T f_execution_period_error_persistent;
   boolean_T f_bias_was_accurate;
   real32_T ignition_time;
   boolean_T f_yaw_stop_bias_converged;
   real32_T CurvKalmanFilterC0;
   real32_T CurvKalmanFilterC1;
   boolean_T f_stop_rollrate_bias_converged;
   boolean_T f_stop_pitchrate_bias_converged;
   real32_T VsVSE_TrlrTotalCount;
   real32_T VsVSE_TrlrCountAccel;
   real32_T VsVSE_TrlrCountBrake;
   real32_T VsVSE_TrlrRunningAvgAccel;
   real32_T VsVSE_TrlrRunningAvgBrake;
   real32_T VsVSE_EstMassRunningAvg;
   boolean_T VsVSE_b_ResetFlag;
} VSE_RESIM_T;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_enum_Presence_Status_
      #define DEFINED_TYPEDEF_FOR_enum_Presence_Status_

typedef uint8_T enum_Presence_Status;

      /* enum enum_Presence_Status */
      #define Neither_Connected    ((enum_Presence_Status)0U) /* Default value */
      #define HW_Connected_Only    ((enum_Presence_Status)1U)
      #define RADAR_Connected_Only ((enum_Presence_Status)2U)
      #define Both_Connected       ((enum_Presence_Status)3U)
      #define Undefined            ((enum_Presence_Status)4U)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_VSE_OUT_Trailer_
      #define DEFINED_TYPEDEF_FOR_VSE_OUT_Trailer_

typedef struct
{
   /* Estimated trailer mass */
   real32_T VsVSE_Kg_TrlrMass;

   /* Estimated host vehicle mass */
   real32_T VsVSE_Kg_HostVehMass;

   /* Trailer length */
   real32_T VsVSE_m_TrlrLen;

   /* Trailer width */
   real32_T VsVSE_m_TrlrWidth;

   /* Estimated host Vehicle Moment of Inertia */
   real32_T VsVSE_Kgm2_HostVehIzz;

   /* Trailer Moment of Inertia Converged */
   real32_T VsVSE_Kgm2_TrlrIzz;

   /* Hitch force Fx  */
   real32_T VsVSE_N_HitchFx;

   /* Hitch force Fy */
   real32_T VsVSE_N_HitchFy;

   /* Hitch yaw moment */
   real32_T VsVSE_Nm_HitchMz;

   /* Hitch angle */
   real32_T VsVSE_rad_HitchAng;

   /* Hitch angle rate */
   real32_T VsVSE_rps_HitchAngSpd;

   /* Gap between host vehicle and trailer */
   real32_T VsVSE_m_TrlrHostVehGap;

   /* Trailer connection status */
   enum_Presence_Status VeVSE_TrlrDetectSts;

   /* Trailer connection status Confidence level */
   uint8_T VeVSE_TrlrDetectStsConfLvl;

   /* Trailer mass converged */
   boolean_T VsVSE_b_TrlrMassConv;

   /* Host vehicle mass converged */
   boolean_T VsVSE_b_HostVehMassConv;

   /* Trailer length confidence level */
   uint8_T VeVSE_TrlrLenConfLvl;

   /* Trailer width confidence level */
   uint8_T VeVSE_TrlrWidthConfLvl;

   /* Host vehicle Moment of Inertia converged */
   boolean_T VsVSE_b_HostVehIzzConv;

   /* Trailer Moment of Inertia converged */
   boolean_T VsVSE_b_TrlrIzzConv;

   /* Hitch force Fx confidence level */
   uint8_T VeVSE_HitchFxConfLvl;

   /* Hitch force Fy confidence level */
   uint8_T VeVSE_HitchFyConfLvl;

   /* Hitch moment confidence level */
   uint8_T VeVSE_HitchMzConfLvl;

   /* Hitch angle confidence level */
   uint8_T VeVSE_HitchAngConfLvl;

   /* Hitch angle rate confidence level */
   uint8_T VeVSE_HitchAngSpdConfLvl;

   /* Indication of whether the state of radar trailer detection process should be entered or not */
   boolean_T VeVSE_b_RadarDetectionSts;

   /* The number of radar cycles for radar detection algo to generate the detection result increasing 1 by 1 and 50 ms in each
    * increasing */
   real32_T VsVSE_s_RadarDetectionTimer;

   /* The number of radar cycles for host in stationary status as defined in requirement increasing 1 by 1 and 50 ms in each
    * increasing */
   real32_T VsVSE_s_StationaryTimer;
   real32_T VsVSE_s_TrlrMassCalcTimer;
   real32_T VsVSE_TrlrMassConvPercent;
} VSE_OUT_Trailer;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_selected_signal_number_T_
      #define DEFINED_TYPEDEF_FOR_selected_signal_number_T_

typedef uint8_T selected_signal_number_T;

      /* enum selected_signal_number_T */
      #define PRIMARY   ((selected_signal_number_T)1U) /* Default value */
      #define SECONDARY ((selected_signal_number_T)2U)
      #define TERTIARY  ((selected_signal_number_T)3U)
      #define UNKNOWN   ((selected_signal_number_T)4U)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_enum_accuracy_level_T_
      #define DEFINED_TYPEDEF_FOR_enum_accuracy_level_T_

typedef uint8_T enum_accuracy_level_T;

      /* enum enum_accuracy_level_T */
      #define NO_ACCURATED     ((enum_accuracy_level_T)0U) /* Default value */
      #define MEDIUM_ACCURATED ((enum_accuracy_level_T)1U)
      #define HIGH_ACCURATED   ((enum_accuracy_level_T)2U)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_YC_INTERNAL_RESIM_T_
      #define DEFINED_TYPEDEF_FOR_YC_INTERNAL_RESIM_T_

typedef struct
{
   real32_T yaw_rate_bias1;
   real32_T yaw_rate_bias2;
   real32_T yaw_rate_bias_fast_bias1;
   real32_T yaw_rate_bias_fast_bias2;
   real32_T comp_yaw_rate_diff_filt;
   real32_T yaw_rate_bias_diff;
   enum_road_type_T road_type;
   boolean_T f_yaw_rate_bias_shift;
   boolean_T f_Yaw_Rate_Bias_Converged;
   boolean_T f_stop_bias_converged;
   boolean_T f_yaw_rate_steady;
   boolean_T f_input_invalid_persistent;
   boolean_T f_execution_period_error_persistent;
   boolean_T f_bias_was_accurate;
   real32_T ignition_time;
   boolean_T f_yaw_stop_bias_converged;
} YC_INTERNAL_RESIM_T;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_enum_yaw_rate_bias_accuracy_T_
      #define DEFINED_TYPEDEF_FOR_enum_yaw_rate_bias_accuracy_T_

typedef int32_T enum_yaw_rate_bias_accuracy_T;

      /* enum enum_yaw_rate_bias_accuracy_T */
      #define BIAS_UNDEFINED    (0) /* Default value */
      #define BIAS_NOT_ACCURATE (1)
      #define BIAS_ACCURATE     (2)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_RoadWheel_vs_SteeringWheel_Table_
      #define DEFINED_TYPEDEF_FOR_RoadWheel_vs_SteeringWheel_Table_

typedef struct
{
   real32_T SteeringWheelAngle_Deg[31];
   real32_T RoadWheelAngle_Deg[31];
} RoadWheel_vs_SteeringWheel_Table;

   #endif

   #ifndef DEFINED_TYPEDEF_FOR_enum_accuracy_level_wheelodo_T_
      #define DEFINED_TYPEDEF_FOR_enum_accuracy_level_wheelodo_T_

typedef uint8_T enum_accuracy_level_wheelodo_T;

      /* enum enum_accuracy_level_wheelodo_T */
      #define LOW    ((enum_accuracy_level_wheelodo_T)0U) /* Default value */
      #define MEDIUM ((enum_accuracy_level_wheelodo_T)1U)
      #define HIGH   ((enum_accuracy_level_wheelodo_T)2U)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_Wheel_Odo_QF_and_AccuracyLvl_
      #define DEFINED_TYPEDEF_FOR_Wheel_Odo_QF_and_AccuracyLvl_

typedef struct
{
   enum_quality_factor_T EstimatedVxForABSTCS_QF;
   enum_quality_factor_T EstimatedAxForABSTCS_QF;
   enum_quality_factor_T FinalEstimatedVx_QF;
   enum_quality_factor_T FinalEstimatedAx_QF;
   enum_accuracy_level_wheelodo_T EstimatedVxForABSTCS_AccLvl;
   enum_accuracy_level_wheelodo_T EstimatedAxForABSTCS_AccLvl;
   enum_accuracy_level_wheelodo_T FinalEstimatedVx_AccLvl;
   enum_accuracy_level_wheelodo_T FinalEstimatedAx_AccLvl;
} Wheel_Odo_QF_and_AccuracyLvl;

   #endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_VSE_Master_Model_WL_L2P_T RT_MODEL_VSE_Master_Model_WL_L2P_T;

#endif /* RTW_HEADER_VSE_Master_Model_WL_L2P_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
