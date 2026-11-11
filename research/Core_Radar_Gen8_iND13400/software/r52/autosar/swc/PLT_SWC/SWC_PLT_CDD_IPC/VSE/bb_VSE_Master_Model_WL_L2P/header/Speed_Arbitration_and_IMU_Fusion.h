/*
 * File: Speed_Arbitration_and_IMU_Fusion.h
 *
 * Code generated for Simulink model 'Speed_Arbitration_and_IMU_Fusion'.
 *
 * Model version                  : 1.1412
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:59 2026
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

#ifndef RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_h_
   #define RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_h_
   #include <math.h>
   #ifndef Speed_Arbitration_and_IMU_Fusion_COMMON_INCLUDES_
      #define Speed_Arbitration_and_IMU_Fusion_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* Speed_Arbitration_and_IMU_Fusion_COMMON_INCLUDES_ */

   #include "Speed_Arbitration_and_IMU_Fusion_types.h"

   /* Shared type includes */
   #include "multiword_types.h"

/* Block signals and states (default storage) for model 'Speed_Arbitration_and_IMU_Fusion' */
typedef struct
{
   dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T gobj_0;                /* '<S16>/Lowpass Filter' */
   dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T gobj_1;                /* '<S16>/Lowpass Filter' */
   dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T obj;                /* '<S15>/Moving Average' */
   dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T obj_n;                       /* '<S16>/Lowpass Filter' */
   dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T gobj_0_d; /* '<S15>/Moving Average' */
   dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T gobj_1_h; /* '<S15>/Moving Average' */
   uint64_T ResettableDelay_DSTATE;                                                  /* '<S7>/Resettable Delay' */
   real32_T diff_num[4];                                                             /* '<S54>/FindDifferentiatorCoeff' */
   real32_T diff_denom[4];                                                           /* '<S54>/FindDifferentiatorCoeff' */
   real32_T DataTypeConversion[4];                                                   /* '<S50>/Data Type Conversion' */
   real32_T DataTypeConversion1[4];                                                  /* '<S50>/Data Type Conversion1' */
   real32_T diff_num_o[4];                                                           /* '<S41>/find_Differentiator_Coeff' */
   real32_T diff_denom_d[4];                                                         /* '<S41>/find_Differentiator_Coeff' */
   real32_T diff_num_e[4];                                                           /* '<S33>/find_Differentiator_Coeff' */
   real32_T diff_denom_b[4];                                                         /* '<S33>/find_Differentiator_Coeff' */
   real32_T P_delay_DSTATE[4];                                                       /* '<S19>/P_delay' */
   real32_T Differentiator_states[3];                                                /* '<S53>/Differentiator' */
   real32_T FixPtUnitDelay1_DSTATE_d[2];                                             /* '<S22>/FixPt Unit Delay1' */
   real32_T Differentiator_states_j[3];                                              /* '<S31>/Differentiator' */
   real32_T DiscreteFilter_states[3];                                                /* '<S9>/Discrete Filter' */
   real32_T Differentiator_states_n[3];                                              /* '<S30>/Differentiator' */
   real32_T Divide_DWORK4[4];                                                        /* '<S20>/Divide' */
   real32_T Differentiator;                                                          /* '<S53>/Differentiator' */
   real32_T FixPtUnitDelay1_DSTATE;                                                  /* '<S66>/FixPt Unit Delay1' */
   real32_T UnitDelay1_DSTATE;                                                       /* '<S12>/Unit Delay1' */
   real32_T Differentiator_tmp;                                                      /* '<S53>/Differentiator' */
   real32_T Differentiator_tmp_c;                                                    /* '<S31>/Differentiator' */
   real32_T DiscreteFilter_tmp;                                                      /* '<S9>/Discrete Filter' */
   real32_T Differentiator_tmp_o;                                                    /* '<S30>/Differentiator' */
   real32_T last_inp;                                                                /* '<S15>/MATLAB Function1' */
   uint32_T UnitDelay_DSTATE;                                                        /* '<S13>/Unit Delay' */
   uint32_T UnitDelay_DSTATE_f;                                                      /* '<S12>/Unit Delay' */
   uint32_T temporalCounter_i1;                                                      /* '<S57>/Debouncer' */
   uint32_T temporalCounter_i2;                                                      /* '<S57>/Debouncer' */
   struct
   {
      uint_T is_c1_SignalDebouncingLogic:2;        /* '<S57>/Debouncer' */
      uint_T is_Off:2;                             /* '<S57>/Debouncer' */
      uint_T is_Debounce:2;                        /* '<S57>/Debouncer' */
      uint_T is_active_c1_SignalDebouncingLogic:1; /* '<S57>/Debouncer' */
      uint_T Output:1;                             /* '<S57>/Debouncer' */
      uint_T Fault:1;                              /* '<S57>/Debouncer' */
      uint_T UnitDelay2_DSTATE_l:1;                /* '<S13>/Unit Delay2' */
      uint_T UnitDelay3_DSTATE:1;                  /* '<S12>/Unit Delay3' */
      uint_T UnitDelay4_DSTATE:1;                  /* '<S12>/Unit Delay4' */
      uint_T ABS_State_Transition:1;               /* '<S14>/MATLAB Function1' */
      uint_T objisempty:1;                         /* '<S16>/Lowpass Filter' */
      uint_T isInitialized:1;                      /* '<S16>/Lowpass Filter' */
      uint_T last_inp_not_empty:1;                 /* '<S15>/MATLAB Function1' */
      uint_T objisempty_j:1;                       /* '<S15>/Moving Average' */
   } bitsForTID0;

   uint8_T UnitDelay_DSTATE_n;       /* '<S53>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_b;       /* '<S10>/Unit Delay' */
   uint8_T UnitDelay2_DSTATE;        /* '<S14>/Unit Delay2' */
   uint8_T FixPtUnitDelay2_DSTATE;   /* '<S66>/FixPt Unit Delay2' */
   uint8_T UnitDelay_DSTATE_j;       /* '<S31>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_fa;      /* '<S30>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_m;       /* '<S9>/Unit Delay' */
   uint8_T FixPtUnitDelay2_DSTATE_j; /* '<S22>/FixPt Unit Delay2' */
   uint8_T icLoad;                   /* '<S7>/Resettable Delay' */
} DW_Speed_Arbitration_and_IMU_Fusion_f_T;

/* Invariant block signals for system '<S23>/calc_accuracy_level_under_medium_confidence' */
typedef struct
{
   const enum_accuracy_level_wheelodo_T In1; /* '<S27>/In1' */
} ConstB_calc_accuracy_level_under_medium_confidence_Speed_Arbitration_and_IMU_Fusion_T;

/* Invariant block signals for model 'Speed_Arbitration_and_IMU_Fusion' */
typedef struct
{
   const enum_accuracy_level_wheelodo_T In1; /* '<S25>/In1' */
   ConstB_calc_accuracy_level_under_medium_confidence_Speed_Arbitration_and_IMU_Fusion_T
      calc_accuracy_level_under_low_confidence; /* '<S23>/calc_accuracy_level_under_low_confidence' */
   ConstB_calc_accuracy_level_under_medium_confidence_Speed_Arbitration_and_IMU_Fusion_T
      calc_accuracy_level_under_medium_confidence; /* '<S23>/calc_accuracy_level_under_medium_confidence' */
} ConstB_Speed_Arbitration_and_IMU_Fusion_h_T;

typedef struct
{
   DW_Speed_Arbitration_and_IMU_Fusion_f_T rtdw;
} MdlrefDW_Speed_Arbitration_and_IMU_Fusion_T;

extern void Speed_Arbitration_and_IMU_Fusion_calc_accuracy_level_under_medium_confidence(
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongSpdAccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongAccelAccLvl,
   const ConstB_calc_accuracy_level_under_medium_confidence_Speed_Arbitration_and_IMU_Fusion_T *localC);
extern void Speed_Arbitration_and_IMU_Fusion_Initialization1(uint8_T rtu_Enable, real32_T rty_diff_num[4],
                                                             real32_T rty_diff_denom[4]);
extern void Speed_Arbitration_and_IMU_Fusion_Init(DW_Speed_Arbitration_and_IMU_Fusion_f_T *localDW);
extern void Speed_Arbitration_and_IMU_Fusion_Start(DW_Speed_Arbitration_and_IMU_Fusion_f_T *localDW);
extern void Speed_Arbitration_and_IMU_Fusion(
   const real32_T *rtu_Raw_IMU_Ax, const real32_T *rtu_EstimatedVx_FromABSTCS,
   const enum_quality_factor_T *rtu_EstimatedVxForABSTCS_QF, const enum_quality_factor_T *rtu_EstimatedAxForABSTCS_QF,
   const uint8_T *rtu_VsVCAN_u8_WhlSpin_FL, const uint8_T *rtu_VsVCAN_u8_WhlSpin_FR, const uint8_T *rtu_VsVCAN_u8_WhlSpin_RL,
   const uint8_T *rtu_VsVCAN_u8_WhlSpin_RR, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FL,
   const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FR, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RL,
   const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RR, const uint64_T *rtu_VsVCAN_u64_SystemTime,
   const uint8_T *rtu_VsVCAN_u8_BrakeState, const real32_T *rtu_whl_tck_spd_fl, const real32_T *rtu_whl_tck_spd_fr,
   const real32_T *rtu_whl_tck_spd_rl, const real32_T *rtu_whl_tck_spd_rr, const boolean_T *rtu_WhlTckIsZeroForLongerTime,
   const uint8_T *rtu_ABS_Status, const uint8_T *rtu_VsVCAN_u8_GearBsdRvrsStat, real32_T *rty_VsVSE_mps_WhlOdoArbitratedVehSpeed,
   real32_T *rty_VsVSE_mps2_WhlOdoArbitratedVehLongAccel, enum_quality_factor_T *rty_VeVSE_WhlOdoArbitratedVehSpeed_QF,
   enum_quality_factor_T *rty_VeVSE_WhlOdoArbitratedAx_QF, enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoArbitratedVx_AccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoArbitratedAx_AccLvl, real32_T *rty_VsVSE_mps2_WhlOdoLongAcclFromEstimWhlSpd,
   DW_Speed_Arbitration_and_IMU_Fusion_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S66>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/Reshape' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Speed_Arbitration_and_IMU_Fusion'
 * '<S1>'   : 'Speed_Arbitration_and_IMU_Fusion/A_matrix_4x4'
 * '<S2>'   : 'Speed_Arbitration_and_IMU_Fusion/IMU_Ax_Processing'
 * '<S3>'   : 'Speed_Arbitration_and_IMU_Fusion/Linear_Kalman_FIlter'
 * '<S4>'   : 'Speed_Arbitration_and_IMU_Fusion/Q_mat'
 * '<S5>'   : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS'
 * '<S6>'   : 'Speed_Arbitration_and_IMU_Fusion/Z_H_R_Design'
 * '<S7>'   : 'Speed_Arbitration_and_IMU_Fusion/delta_time_correction'
 * '<S8>'   : 'Speed_Arbitration_and_IMU_Fusion/mean_of_raw_wheel_speeds'
 * '<S9>'   : 'Speed_Arbitration_and_IMU_Fusion/smooth_differentiator'
 * '<S10>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_decelerating'
 * '<S11>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_reverse_status_calc'
 * '<S12>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_stationary_and_slow_motion__detection'
 * '<S13>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_stationary_detection_for_Ax_bias'
 * '<S14>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration'
 * '<S15>'  : 'Speed_Arbitration_and_IMU_Fusion/IMU_Ax_Processing/IMU_Ax_Standstill_Offset'
 * '<S16>'  : 'Speed_Arbitration_and_IMU_Fusion/IMU_Ax_Processing/meas_Ax_passed_through_a_butterwothr_IIR_filter'
 * '<S17>'  : 'Speed_Arbitration_and_IMU_Fusion/IMU_Ax_Processing/IMU_Ax_Standstill_Offset/MATLAB Function1'
 * '<S18>'  : 'Speed_Arbitration_and_IMU_Fusion/Linear_Kalman_FIlter/KF_Estimation'
 * '<S19>'  : 'Speed_Arbitration_and_IMU_Fusion/Linear_Kalman_FIlter/KF_Prediction'
 * '<S20>'  : 'Speed_Arbitration_and_IMU_Fusion/Linear_Kalman_FIlter/KF_Estimation/Kalman Gain'
 * '<S21>'  : 'Speed_Arbitration_and_IMU_Fusion/Linear_Kalman_FIlter/KF_Estimation/MATLAB Function'
 * '<S22>'  : 'Speed_Arbitration_and_IMU_Fusion/Linear_Kalman_FIlter/KF_Prediction/x_delay'
 * '<S23>'  : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels'
 * '<S24>'  : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor'
 * '<S25>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/calc_accuracy_level_under_high_confidence'
 * '<S26>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/calc_accuracy_level_under_low_confidence'
 * '<S27>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/calc_accuracy_level_under_medium_confidence'
 * '<S28>'  : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To
 * Constant1'
 * '<S29>'  : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To
 * Constant5'
 * '<S30>'  : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check'
 * '<S31>'  : 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1'
 * '<S32>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/DecideQualityFactor'
 * '<S33>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/Initialization1'
 * '<S34>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/SignalRangeCheck'
 * '<S35>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/SignalRateCheck'
 * '<S36>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/DecideQualityFactor/Compare
 * To Constant'
 * '<S37>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S38>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S39>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check/Initialization1/find_Differentiator_Coeff'
 * '<S40>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/DecideQualityFactor'
 * '<S41>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/Initialization'
 * '<S42>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/SignalRangeCheck'
 * '<S43>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/SignalRateCheck'
 * '<S44>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S45>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/DecideQualityFactor/If
 * Action Subsystem5'
 * '<S46>'  :
 * 'Speed_Arbitration_and_IMU_Fusion/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Plausibility_Check1/Initialization/find_Differentiator_Coeff'
 * '<S47>'  : 'Speed_Arbitration_and_IMU_Fusion/delta_time_correction/MATLAB Function'
 * '<S48>'  : 'Speed_Arbitration_and_IMU_Fusion/delta_time_correction/calc_corrected_delta_sys_time_under_extreme_cases'
 * '<S49>'  : 'Speed_Arbitration_and_IMU_Fusion/delta_time_correction/calc_corrected_delta_sys_time_under_normal_cases'
 * '<S50>'  : 'Speed_Arbitration_and_IMU_Fusion/smooth_differentiator/Speed_To_Accel_TF_Coeff'
 * '<S51>'  : 'Speed_Arbitration_and_IMU_Fusion/smooth_differentiator/Speed_To_Accel_TF_Coeff/Find_Speed_To_Accel_TF'
 * '<S52>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_decelerating/MATLAB Function'
 * '<S53>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_decelerating/Subsystem8'
 * '<S54>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_decelerating/Subsystem8/Differentiator Generator'
 * '<S55>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_decelerating/Subsystem8/Differentiator Generator/FindDifferentiatorCoeff'
 * '<S56>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_reverse_status_calc/MATLAB Function'
 * '<S57>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_stationary_and_slow_motion__detection/Debouncing Logic'
 * '<S58>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_stationary_and_slow_motion__detection/MATLAB Function'
 * '<S59>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_stationary_and_slow_motion__detection/Debouncing Logic/Debouncer'
 * '<S60>'  : 'Speed_Arbitration_and_IMU_Fusion/veh_stationary_detection_for_Ax_bias/MATLAB Function'
 * '<S61>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration/First order discrete constant time LPF1'
 * '<S62>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration/MATLAB Function'
 * '<S63>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration/MATLAB Function1'
 * '<S64>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration/MATLAB Function2'
 * '<S65>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration/First order discrete constant time
 * LPF1/Subsystem'
 * '<S66>'  : 'Speed_Arbitration_and_IMU_Fusion/wheel_tick_and_vcan_speed_arbitration/First order discrete constant time
 * LPF1/delay'
 */
#endif /* RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
