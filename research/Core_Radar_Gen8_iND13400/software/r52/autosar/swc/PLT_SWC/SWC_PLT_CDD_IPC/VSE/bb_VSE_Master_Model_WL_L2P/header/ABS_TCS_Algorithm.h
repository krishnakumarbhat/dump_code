/*
 * File: ABS_TCS_Algorithm.h
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
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

#ifndef RTW_HEADER_ABS_TCS_Algorithm_h_
   #define RTW_HEADER_ABS_TCS_Algorithm_h_
   #include <math.h>
   #ifndef ABS_TCS_Algorithm_COMMON_INCLUDES_
      #define ABS_TCS_Algorithm_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* ABS_TCS_Algorithm_COMMON_INCLUDES_ */

   #include "ABS_TCS_Algorithm_types.h"

   /* Shared type includes */
   #include "multiword_types.h"

/* Block signals and states (default storage) for system '<S82>/Debouncer' */
typedef struct
{
   uint32_T temporalCounter_i1; /* '<S82>/Debouncer' */
   uint32_T temporalCounter_i2; /* '<S82>/Debouncer' */
   struct
   {
      uint_T is_c1_SignalDebouncingLogic:2;        /* '<S82>/Debouncer' */
      uint_T is_Off:2;                             /* '<S82>/Debouncer' */
      uint_T is_Debounce:2;                        /* '<S82>/Debouncer' */
      uint_T is_active_c1_SignalDebouncingLogic:1; /* '<S82>/Debouncer' */
   } bitsForTID0;
} DW_Debouncer_ABS_TCS_Algorithm_T;

/* Block signals and states (default storage) for system '<S99>/calc_rate_from_the_sorted_spd' */
typedef struct
{
   real32_T UnitDelay_DSTATE; /* '<S109>/Unit Delay' */
} DW_CoreSubsys_ABS_TCS_Algorithm_T;

/* Block signals and states (default storage) for system '<S99>/calc_rate_from_the_sorted_spd' */
typedef struct
{
   DW_CoreSubsys_ABS_TCS_Algorithm_T CoreSubsys; /* '<S99>/calc_rate_from_the_sorted_spd' */
} DW_calc_rate_from_the_sorted_spd_ABS_TCS_Algorithm_T;

/* Block signals and states (default storage) for system '<S79>/calc_rate_from_the_unsorted_spd' */
typedef struct
{
   real32_T UnitDelay_DSTATE; /* '<S110>/Unit Delay' */
} DW_CoreSubsys_ABS_TCS_Algorithm_f_T;

/* Block signals and states (default storage) for model 'ABS_TCS_Algorithm' */
typedef struct
{
   DW_calc_rate_from_the_sorted_spd_ABS_TCS_Algorithm_T
      calc_rate_from_the_sorted_spd_l[4];             /* '<S127>/calc_rate_from_the_sorted_spd' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_i;   /* '<S149>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_a;   /* '<S148>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_l;   /* '<S147>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_dl;  /* '<S146>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_jd;  /* '<S122>/Debouncer' */
   DW_CoreSubsys_ABS_TCS_Algorithm_f_T CoreSubsys[4]; /* '<S79>/calc_rate_from_the_unsorted_spd' */
   DW_calc_rate_from_the_sorted_spd_ABS_TCS_Algorithm_T
      calc_rate_from_the_sorted_spd[4];                             /* '<S99>/calc_rate_from_the_sorted_spd' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_j;                 /* '<S103>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_c;                 /* '<S102>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_p;                 /* '<S101>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_d;                 /* '<S100>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer_h;                 /* '<S95>/Debouncer' */
   DW_Debouncer_ABS_TCS_Algorithm_T sf_Debouncer;                   /* '<S82>/Debouncer' */
   dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T obj;              /* '<S10>/Moving Average' */
   dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T gobj_0; /* '<S10>/Moving Average' */
   dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T gobj_1; /* '<S10>/Moving Average' */
   uint64_T ResettableDelay_DSTATE;                                 /* '<S4>/Resettable Delay' */
   real32_T TmpSignalConversionAtcalc_speed_under_ABSInport2[4];
   real32_T TmpSignalConversionAtcalc_speed_under_ABSInport2_h[4];
   real32_T diff_num[4];                 /* '<S67>/find_Differentiator_Coeff' */
   real32_T diff_denom[4];               /* '<S67>/find_Differentiator_Coeff' */
   real32_T diff_num_b[4];               /* '<S59>/find_Differentiator_Coeff' */
   real32_T diff_denom_k[4];             /* '<S59>/find_Differentiator_Coeff' */
   real32_T Assignment[2];               /* '<S26>/Assignment' */
   real32_T filter_num[3];               /* '<S14>/MATLAB Function' */
   real32_T filter_den[3];               /* '<S14>/MATLAB Function' */
   real32_T DiscreteFilter_states[2];    /* '<S13>/Discrete Filter' */
   real32_T FixPtUnitDelay1_DSTATE_j[2]; /* '<S22>/FixPt Unit Delay1' */
   real32_T UnitDelay3_DSTATE[4];        /* '<S16>/Unit Delay3' */
   real32_T Differentiator_states[3];    /* '<S56>/Differentiator' */
   real32_T Differentiator_states_c[3];  /* '<S57>/Differentiator' */
   real32_T ScndOrderButterFiltOut;      /* '<S13>/Discrete Filter' */
   real32_T UnitDelay_DSTATE;            /* '<S133>/Unit Delay' */
   real32_T UnitDelay_DSTATE_f;          /* '<S131>/Unit Delay' */
   real32_T UnitDelay_DSTATE_m;          /* '<S134>/Unit Delay' */
   real32_T UnitDelay_DSTATE_n;          /* '<S132>/Unit Delay' */
   real32_T UnitDelay_DSTATE_j;          /* '<S143>/Unit Delay' */
   real32_T UnitDelay_DSTATE_i;          /* '<S140>/Unit Delay' */
   real32_T UnitDelay_DSTATE_e;          /* '<S141>/Unit Delay' */
   real32_T UnitDelay_DSTATE_c;          /* '<S142>/Unit Delay' */
   real32_T Accel_Counter_DSTATE;        /* '<S136>/Accel_Counter' */
   real32_T EWMA_Left_DSTATE;            /* '<S137>/EWMA_Left' */
   real32_T EWVAR_DSTATE;                /* '<S137>/EWVAR' */
   real32_T EWMA_Left_DSTATE_j;          /* '<S138>/EWMA_Left' */
   real32_T EWVAR_DSTATE_c;              /* '<S138>/EWVAR' */
   real32_T SD_Counter_DSTATE;           /* '<S135>/SD_Counter' */
   real32_T UnitDelay_DSTATE_h;          /* '<S8>/Unit Delay' */
   real32_T UnitDelay1_DSTATE;           /* '<S169>/Unit Delay1' */
   real32_T UnitDelay1_DSTATE_g;         /* '<S8>/Unit Delay1' */
   real32_T UnitDelay_DSTATE_fz;         /* '<S169>/Unit Delay' */
   real32_T FixPtUnitDelay1_DSTATE;      /* '<S174>/FixPt Unit Delay1' */
   real32_T lastOut_DSTATE;              /* '<S33>/lastOut' */
   real32_T UnitDelay_DSTATE_nz;         /* '<S37>/Unit Delay' */
   real32_T lastOut_DSTATE_d;            /* '<S34>/lastOut' */
   real32_T UnitDelay_DSTATE_ms;         /* '<S40>/Unit Delay' */
   real32_T DiscreteFilter_tmp;          /* '<S13>/Discrete Filter' */
   real32_T Differentiator_tmp;          /* '<S56>/Differentiator' */
   real32_T Differentiator_tmp_f;        /* '<S57>/Differentiator' */
   real32_T LDLFactorization_VMX;        /* '<S28>/LDL Factorization' */
   real32_T last_inp;                    /* '<S10>/MATLAB Function1' */
   int32_T Index;                        /* '<S23>/Data Store Memory' */
   uint32_T UnitDelay_DSTATE_a;          /* '<S7>/Unit Delay' */
   struct
   {
      uint_T UnitDelay3_DSTATE_i:1;    /* '<S169>/Unit Delay3' */
      uint_T UnitDelay2_DSTATE_i:1;    /* '<S7>/Unit Delay2' */
      uint_T LDLFactorization_STATE:1; /* '<S28>/LDL Factorization' */
      uint_T last_inp_not_empty:1;     /* '<S10>/MATLAB Function1' */
      uint_T objisempty:1;             /* '<S10>/Moving Average' */
   } bitsForTID0;

   int16_T UnitDelay2_DSTATE;                                         /* '<S169>/Unit Delay2' */
   uint8_T FixPtUnitDelay2_DSTATE;                                    /* '<S174>/FixPt Unit Delay2' */
   uint8_T FixPtUnitDelay2_DSTATE_e;                                  /* '<S22>/FixPt Unit Delay2' */
   uint8_T init_value_DSTATE;                                         /* '<S35>/init_value' */
   uint8_T prvious_flag_value_DSTATE;                                 /* '<S35>/prvious_flag_value' */
   uint8_T step_counter_DSTATE;                                       /* '<S35>/step_counter' */
   uint8_T init_value_DSTATE_a;                                       /* '<S38>/init_value' */
   uint8_T prvious_flag_value_DSTATE_n;                               /* '<S38>/prvious_flag_value' */
   uint8_T step_counter_DSTATE_j;                                     /* '<S38>/step_counter' */
   uint8_T icLoad;                                                    /* '<S4>/Resettable Delay' */
   uint8_T DiscreteFilter_icLoad;                                     /* '<S13>/Discrete Filter' */
   boolean_T VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[4];   /* '<S98>/Vector Concatenate' */
   boolean_T VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[4]; /* '<S123>/Vector Concatenate' */
   boolean_T VaVSE_b_IsWhlUnderASR[4];                                /* '<S121>/Vector Concatenate' */
   boolean_T ImpAsg_InsertedFor_VaVSE_b_IsWhlUnderABS_at_inport_0[4]; /* '<S90>/ABS detection logic' */
   boolean_T Fault;                                                   /* '<S149>/Debouncer' */
   boolean_T Fault_f;                                                 /* '<S148>/Debouncer' */
   boolean_T Fault_d;                                                 /* '<S147>/Debouncer' */
   boolean_T Fault_m;                                                 /* '<S146>/Debouncer' */
   boolean_T Fault_h;                                                 /* '<S122>/Debouncer' */
   boolean_T Fault_g;                                                 /* '<S103>/Debouncer' */
   boolean_T Fault_n;                                                 /* '<S102>/Debouncer' */
   boolean_T Fault_fo;                                                /* '<S101>/Debouncer' */
   boolean_T Fault_nj;                                                /* '<S100>/Debouncer' */
   boolean_T Output;                                                  /* '<S95>/Debouncer' */
   boolean_T Fault_fe;                                                /* '<S95>/Debouncer' */
   boolean_T Output_f;                                                /* '<S82>/Debouncer' */
   boolean_T Fault_k;                                                 /* '<S82>/Debouncer' */
} DW_ABS_TCS_Algorithm_f_T;

/* Invariant block signals for system '<S43>/calc_accuracy_level_under_medium_confidence' */
typedef struct
{
   const enum_accuracy_level_wheelodo_T In1; /* '<S49>/In1' */
} ConstB_calc_accuracy_level_under_medium_confidence_ABS_TCS_Algorithm_T;

/* Invariant block signals for model 'ABS_TCS_Algorithm' */
typedef struct
{
   const enum_accuracy_level_wheelodo_T In1; /* '<S47>/In1' */
   ConstB_calc_accuracy_level_under_medium_confidence_ABS_TCS_Algorithm_T
      calc_accuracy_level_under_low_confidence; /* '<S43>/calc_accuracy_level_under_low_confidence' */
   ConstB_calc_accuracy_level_under_medium_confidence_ABS_TCS_Algorithm_T
      calc_accuracy_level_under_medium_confidence; /* '<S43>/calc_accuracy_level_under_medium_confidence' */
} ConstB_ABS_TCS_Algorithm_h_T;

typedef struct
{
   DW_ABS_TCS_Algorithm_f_T rtdw;
} MdlrefDW_ABS_TCS_Algorithm_T;

extern void ABS_TCS_Algorithm_calc_accuracy_level_under_medium_confidence(
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongSpdAccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongAccelAccLvl,
   const ConstB_calc_accuracy_level_under_medium_confidence_ABS_TCS_Algorithm_T *localC);
extern void ABS_TCS_Algorithm_Initialization1(boolean_T rtu_Enable, real32_T rty_diff_num[4], real32_T rty_diff_denom[4]);
extern void ABS_TCS_Algorithm_Debouncer_Init(boolean_T *rty_Fault);
extern void ABS_TCS_Algorithm_Debouncer(boolean_T rtu_sw, boolean_T *rty_Output, boolean_T *rty_Fault,
                                        DW_Debouncer_ABS_TCS_Algorithm_T *localDW, real32_T rtp_Debounce_Time,
                                        boolean_T rtp_Demat_Duration_Check, real32_T rtp_Dematuration_Time,
                                        boolean_T rtp_Fault_Check, boolean_T rtp_Mat_Duration_Check, real32_T rtp_Maturation_Time,
                                        real32_T rtp_Recovery_Time);
extern void ABS_TCS_Algorithm_MATLABFunction(real32_T rtu_Input_Vector, real32_T rtu_Input_Vector_n, real32_T rtu_Input_Vector_l,
                                             real32_T rtu_Input_Vector_p, real32_T rty_Output_Vector[4]);
extern void ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1(real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec,
                                                                             real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec_i,
                                                                             real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec_f,
                                                                             real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec_n,
                                                                             uint8_T *rty_VsVSE_u8_SwitchToMeasAx,
                                                                             real32_T *rty_VsVSE_mps_SpeedUnderABS);
extern void ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2(real32_T rtu_VsVSE_mps_MeanWhlSpdCloser,
                                                                             uint8_T *rty_VsVSE_u8_SwitchToMeasAx,
                                                                             real32_T *rty_VsVSE_mps_SpeedUnderABS);
extern void ABS_TCS_Algorithm_calc_rate_from_the_sorted_spd(int32_T NumIters, const real32_T rtu_VaVSE_mps_TransFiltWhlLinSpd[4],
                                                            real32_T rtu_Vs_s_DeltaSystemTime,
                                                            real32_T rtu_KsVSE_mps2_SortedWhlBsdAcclMaxThrsh,
                                                            boolean_T rty_VaVSE_b_IsSortedWhlSpdBsdAcclHigh[4],
                                                            DW_calc_rate_from_the_sorted_spd_ABS_TCS_Algorithm_T localDW[4]);
extern void ABS_TCS_Algorithm_Final_Check_For_Closer_Whl_Spd(int32_T NumIters, const boolean_T rtu_VsVSE_b_AreWhlsCloser_vec[5],
                                                             const boolean_T rtu_VsVSE_b_IsCloserWhlRateLow_vec[5],
                                                             boolean_T rty_VaVSE_b_CloserWhlSpdSet[5]);
extern void ABS_TCS_Algorithm_Init(real32_T *rty_VsVSE_mps_WhlOdoVehSpeedFromABSTCS, real32_T *rty_VsVSE_mps_WhlOdoVehAxFromABSTCS,
                                   DW_ABS_TCS_Algorithm_f_T *localDW);
extern void ABS_TCS_Algorithm_Start(DW_ABS_TCS_Algorithm_f_T *localDW);
extern void ABS_TCS_Algorithm(
   const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FL, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FR,
   const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RL, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RR,
   const uint8_T *rtu_VsVCAN_u8_WhlSpin_FL, const uint8_T *rtu_VsVCAN_u8_WhlSpin_FR, const uint8_T *rtu_VsVCAN_u8_WhlSpin_RL,
   const uint8_T *rtu_VsVCAN_u8_WhlSpin_RR, const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_FL_QF,
   const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_FR_QF, const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_RL_QF,
   const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_RR_QF, const real32_T *rtu_VsVSE_rad_RoadWhlAngle_Fornt,
   const real32_T *rtu_VsVSE_rad_RoadWhlAngle_Rear, const real32_T *rtu_KsVSE_m_TrackWidth_Front,
   const real32_T *rtu_KsVSE_m_TrackWidth_Rear, const boolean_T *rtu_VsVCAN_b_ABSActive, const boolean_T *rtu_VsVCAN_b_ASRActive,
   const real32_T *rtu_VsVCAN_mps2_RawLongAccel, const enum_quality_factor_T *rtu_VeVCAN_IMU_Ax_QF,
   const uint8_T *rtu_VsVCAN_u8_GearBsdReverseStat, const real32_T *rtu_VsVSE_rps_CompYawRateFilt,
   const real32_T *rtu_VsVCAN_s_ModelExecutionTime, const uint64_T *rtu_VsVCAN_u64_SystemTime,
   real32_T *rty_VsVSE_mps_WhlOdoVehSpeedFromABSTCS, real32_T *rty_VsVSE_mps_WhlOdoVehAxFromABSTCS,
   uint8_T *rty_VsVSE_u8_ABS_Status, boolean_T *rty_VsVSE_b_ASR_Status, enum_quality_factor_T *rty_VeVSE_EstimatedVxFromABSTCS_QF,
   enum_quality_factor_T *rty_VeVSE_EstimatedAxFromABSTCS_QF,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_EstimatedVxFromABSTCS_AccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_EstimatedAxFromABSTCS_AccLvl, DW_ABS_TCS_Algorithm_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Extract Diagonal' : Unused code path elimination
 * Block '<S20>/Check Signal Attributes' : Unused code path elimination
 * Block '<S30>/Check Signal Attributes' : Unused code path elimination
 * Block '<S31>/Check Signal Attributes' : Unused code path elimination
 * Block '<S32>/Check Signal Attributes' : Unused code path elimination
 * Block '<S24>/Scope' : Unused code path elimination
 * Block '<S24>/Scope1' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S89>/Scope' : Unused code path elimination
 * Block '<S135>/Scope' : Unused code path elimination
 * Block '<S128>/Scope' : Unused code path elimination
 * Block '<S174>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/A_Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/P_Reshape' : Reshape block reduction
 * Block '<S24>/P_prd_Reshape' : Reshape block reduction
 * Block '<S24>/Reshape' : Reshape block reduction
 * Block '<S16>/H_Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Q_Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/R_Conversion' : Eliminate redundant data type conversion
 * Block '<S79>/Reshape' : Reshape block reduction
 * Block '<S79>/Reshape1' : Reshape block reduction
 * Block '<S128>/Reshape' : Reshape block reduction
 * Block '<S128>/Reshape2' : Reshape block reduction
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
 * '<Root>' : 'ABS_TCS_Algorithm'
 * '<S1>'   : 'ABS_TCS_Algorithm/IMU_Ax_Processing'
 * '<S2>'   : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax'
 * '<S3>'   : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS'
 * '<S4>'   : 'ABS_TCS_Algorithm/delta_time_correction'
 * '<S5>'   : 'ABS_TCS_Algorithm/mean_of_raw_wheel_speeds'
 * '<S6>'   : 'ABS_TCS_Algorithm/veh_reverse_status_calc'
 * '<S7>'   : 'ABS_TCS_Algorithm/veh_stationary_detection_for_Ax_bias'
 * '<S8>'   : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic'
 * '<S9>'   : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG '
 * '<S10>'  : 'ABS_TCS_Algorithm/IMU_Ax_Processing/IMU_Ax_Standstill_Offset'
 * '<S11>'  : 'ABS_TCS_Algorithm/IMU_Ax_Processing/meas_Ax_passed_through_a_butterwothr_IIR_filter1'
 * '<S12>'  : 'ABS_TCS_Algorithm/IMU_Ax_Processing/IMU_Ax_Standstill_Offset/MATLAB Function1'
 * '<S13>'  :
 * 'ABS_TCS_Algorithm/IMU_Ax_Processing/meas_Ax_passed_through_a_butterwothr_IIR_filter1/raw_long_accel_passed_through_a_second_order_butterworth_filter'
 * '<S14>'  :
 * 'ABS_TCS_Algorithm/IMU_Ax_Processing/meas_Ax_passed_through_a_butterwothr_IIR_filter1/raw_long_accel_passed_through_a_second_order_butterworth_filter/Initialization'
 * '<S15>'  :
 * 'ABS_TCS_Algorithm/IMU_Ax_Processing/meas_Ax_passed_through_a_butterwothr_IIR_filter1/raw_long_accel_passed_through_a_second_order_butterworth_filter/Initialization/MATLAB
 * Function'
 * '<S16>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter'
 * '<S17>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Subsystem'
 * '<S18>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Subsystem4'
 * '<S19>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Z_H_and_R_design'
 * '<S20>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Check Signal Attributes'
 * '<S21>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control'
 * '<S22>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Unit Delay External IC'
 * '<S23>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options'
 * '<S24>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core'
 * '<S25>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/P_prd_Assign'
 * '<S26>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/X_est_Assign'
 * '<S27>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/X_prd_Assign'
 * '<S28>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/LDL Solver'
 * '<S29>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce counter'
 * '<S30>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/LDL Solver/Check Signal Attributes'
 * '<S31>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/LDL Solver/Check Signal Attributes1'
 * '<S32>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/LDL Solver/Check Signal Attributes2'
 * '<S33>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce counter/step_increment_logic'
 * '<S34>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic1'
 * '<S35>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic/counter_logic'
 * '<S36>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic/step_increment_logic'
 * '<S37>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic/step_increment_logic/output_when_no_transition'
 * '<S38>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic1/counter_logic'
 * '<S39>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic1/step_increment_logic'
 * '<S40>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Kalman_Filter/Control/Options/Core/debounce
 * counter/step_increment_logic1/step_increment_logic/output_when_no_transition'
 * '<S41>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Subsystem/DesignAdaptationMatrix'
 * '<S42>'  : 'ABS_TCS_Algorithm/KF_To_Estimate_Vx_and_Ax/Subsystem4/DesignProcessNoiseMatrix'
 * '<S43>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels'
 * '<S44>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor'
 * '<S45>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/Compare To Constant'
 * '<S46>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/Compare To Constant1'
 * '<S47>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/calc_accuracy_level_under_high_confidence'
 * '<S48>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/calc_accuracy_level_under_low_confidence'
 * '<S49>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Accuracy_levels/calc_accuracy_level_under_medium_confidence'
 * '<S50>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To Constant'
 * '<S51>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To Constant1'
 * '<S52>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To Constant2'
 * '<S53>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To Constant3'
 * '<S54>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To Constant4'
 * '<S55>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Compare To Constant5'
 * '<S56>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check'
 * '<S57>'  : 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check'
 * '<S58>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/DecideQualityFactor'
 * '<S59>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/Initialization1'
 * '<S60>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/SignalRangeCheck'
 * '<S61>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/SignalRateCheck'
 * '<S62>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/DecideQualityFactor/Compare
 * To Constant'
 * '<S63>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S64>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S65>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Accel_QF_Check/Initialization1/find_Differentiator_Coeff'
 * '<S66>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/DecideQualityFactor'
 * '<S67>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/Initialization'
 * '<S68>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/SignalRangeCheck'
 * '<S69>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/SignalRateCheck'
 * '<S70>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S71>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S72>'  :
 * 'ABS_TCS_Algorithm/Quality_Factor_And_Accuracy_Level_Under_ABS_TCS/Quality_factor/Veh_Long_Speed_QF_Check/Initialization/find_Differentiator_Coeff'
 * '<S73>'  : 'ABS_TCS_Algorithm/delta_time_correction/MATLAB Function'
 * '<S74>'  : 'ABS_TCS_Algorithm/delta_time_correction/calc_corrected_delta_sys_time_under_extreme_cases'
 * '<S75>'  : 'ABS_TCS_Algorithm/delta_time_correction/calc_corrected_delta_sys_time_under_normal_cases'
 * '<S76>'  : 'ABS_TCS_Algorithm/veh_reverse_status_calc/MATLAB Function'
 * '<S77>'  : 'ABS_TCS_Algorithm/veh_stationary_detection_for_Ax_bias/MATLAB Function'
 * '<S78>'  : 'ABS_TCS_Algorithm/veh_stationary_detection_for_Ax_bias/MATLAB Function2'
 * '<S79>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic'
 * '<S80>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection'
 * '<S81>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/Subsystem'
 * '<S82>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Debouncing Logic'
 * '<S83>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/MATLAB Function'
 * '<S84>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem1'
 * '<S85>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem2'
 * '<S86>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem3'
 * '<S87>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calc_rate_from_the_unsorted_spd'
 * '<S88>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/calc_speed_under_ABS'
 * '<S89>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1'
 * '<S90>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/logic_to_detect_if_indvidual_whls_are_under_ABS'
 * '<S91>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Debouncing Logic/Debouncer'
 * '<S92>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem1/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1'
 * '<S93>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem1/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2'
 * '<S94>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem1/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario3'
 * '<S95>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem1/Debouncing Logic'
 * '<S96>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem1/MATLAB Function2'
 * '<S97>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem1/Debouncing
 * Logic/Debouncer'
 * '<S98>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection logic/Subsystem3/Subsystem'
 * '<S99>'  : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/check_if_rate_of_sorted_whl_spd_is_higher_than_15_mps2'
 * '<S100>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic'
 * '<S101>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic1'
 * '<S102>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic2'
 * '<S103>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic3'
 * '<S104>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic/Debouncer'
 * '<S105>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic1/Debouncer'
 * '<S106>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic2/Debouncer'
 * '<S107>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/Subsystem/Debouncing Logic3/Debouncer'
 * '<S108>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/check_if_rate_of_sorted_whl_spd_is_higher_than_15_mps2/calc_rate_from_the_sorted_spd'
 * '<S109>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/Subsystem3/check_if_rate_of_sorted_whl_spd_is_higher_than_15_mps2/calc_rate_from_the_sorted_spd/calc_wheel_speed_rate'
 * '<S110>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calc_rate_from_the_unsorted_spd/calc_wheel_speed_rate'
 * '<S111>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Check_For_Closer_Whl_Spd_and_their_Rate'
 * '<S112>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Final_Check_For_Closer_Whl_Spd'
 * '<S113>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario1'
 * '<S114>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario2'
 * '<S115>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario3'
 * '<S116>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario4'
 * '<S117>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario5'
 * '<S118>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario6'
 * '<S119>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ABS detection
 * logic/logic_to_detect_if_indvidual_whls_are_under_ABS/ABS detection logic'
 * '<S120>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic'
 * '<S121>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection'
 * '<S122>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Debouncing_Logic_ASR'
 * '<S123>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem'
 * '<S124>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem1'
 * '<S125>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calc_speed_under_ABS'
 * '<S126>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1'
 * '<S127>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/check_if_rate_of_sorted_whl_spd_is_higher_than_15_mps2'
 * '<S128>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection'
 * '<S129>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/Else_condition'
 * '<S130>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/If_ASR_detected'
 * '<S131>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/Subsystem1'
 * '<S132>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/Subsystem2'
 * '<S133>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/Subsystem3'
 * '<S134>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/Subsystem4'
 * '<S135>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/cal_flag_vel_std_dev'
 * '<S136>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/calc_flag_accel'
 * '<S137>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/cal_flag_vel_std_dev/Left'
 * '<S138>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/cal_flag_vel_std_dev/Left1'
 * '<S139>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/cal_flag_vel_std_dev/whl_vel_std_dev_function'
 * '<S140>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/calc_flag_accel/derivative1'
 * '<S141>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/calc_flag_accel/derivative2'
 * '<S142>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/calc_flag_accel/derivative3'
 * '<S143>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/calc_flag_accel/derivative4'
 * '<S144>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/ASR_Detection/calc_flag_accel/whl_accel_function'
 * '<S145>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Debouncing_Logic_ASR/Debouncer'
 * '<S146>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic'
 * '<S147>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic1'
 * '<S148>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic2'
 * '<S149>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic3'
 * '<S150>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic/Debouncer'
 * '<S151>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic1/Debouncer'
 * '<S152>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic2/Debouncer'
 * '<S153>' : 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem/Debouncing
 * Logic3/Debouncer'
 * '<S154>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem1/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1'
 * '<S155>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem1/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2'
 * '<S156>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/Subsystem1/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario3'
 * '<S157>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Check_For_Closer_Whl_Spd_and_their_Rate'
 * '<S158>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Final_Check_For_Closer_Whl_Spd'
 * '<S159>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario1'
 * '<S160>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario2'
 * '<S161>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario3'
 * '<S162>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario4'
 * '<S163>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario5'
 * '<S164>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/calculating_the_mean_of_all_the_possible_set_of_sorted_wheel_speed_which_are_close1/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario6'
 * '<S165>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/check_if_rate_of_sorted_whl_spd_is_higher_than_15_mps2/calc_rate_from_the_sorted_spd'
 * '<S166>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/check_if_rate_of_sorted_whl_spd_is_higher_than_15_mps2/calc_rate_from_the_sorted_spd/calc_wheel_speed_rate'
 * '<S167>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/MATLAB
 * Function'
 * '<S168>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3'
 * '<S169>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3/debounce_estimated_vx'
 * '<S170>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3/limiting_the_minimum_wheel_speed'
 * '<S171>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3/debounce_estimated_vx/calibrated_acceleration_while_decelerating'
 * '<S172>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3/debounce_estimated_vx/exponential_moving_avg'
 * '<S173>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3/limiting_the_minimum_wheel_speed/Subsystem10'
 * '<S174>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/ASR_Detection/ASR_Logic/minimum_whl_spd_selection/Subsystem3/limiting_the_minimum_wheel_speed/limWheelSpeedLast'
 * '<S175>' :
 * 'ABS_TCS_Algorithm/wheel_speed_selection_and_ABS_TCS_detection_logic/Subsystem/calc_final_whl_speed_which_will_be_considered_as_Z_vec'
 * '<S176>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /wheel_speed_transformation_when_vehicle_is_in_reverse'
 * '<S177>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /wheel_speed_transformation_when_vehicle_is_not_in_reverse'
 * '<S178>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero'
 * '<S179>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero1'
 * '<S180>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero2'
 * '<S181>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero3'
 * '<S182>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG
 * /wheel_speed_transformation_when_vehicle_is_in_reverse/wheel_speed_transformation_for_front_speeds'
 * '<S183>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG
 * /wheel_speed_transformation_when_vehicle_is_in_reverse/wheel_speed_transformation_for_rear_speeds'
 * '<S184>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG
 * /wheel_speed_transformation_when_vehicle_is_not_in_reverse/wheel_speed_transformation_for_front_speeds'
 * '<S185>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG
 * /wheel_speed_transformation_when_vehicle_is_not_in_reverse/wheel_speed_transformation_for_rear_speeds'
 * '<S186>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero/Compare To Constant'
 * '<S187>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero1/Compare To Constant'
 * '<S188>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero2/Compare To Constant'
 * '<S189>' : 'ABS_TCS_Algorithm/wheel_speed_transformation_to_CoG /when_stationary_make_the_whl_spd_to_zero3/Compare To Constant'
 */
#endif /* RTW_HEADER_ABS_TCS_Algorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
