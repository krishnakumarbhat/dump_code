/*
 * File: VehicleMassEstimator_2018b.h
 *
 * Code generated for Simulink model 'VehicleMassEstimator_2018b'.
 *
 * Model version                  : 1.861
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:07:28 2026
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

#ifndef RTW_HEADER_VehicleMassEstimator_2018b_h_
   #define RTW_HEADER_VehicleMassEstimator_2018b_h_
   #include <math.h>
   #ifndef VehicleMassEstimator_2018b_COMMON_INCLUDES_
      #define VehicleMassEstimator_2018b_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* VehicleMassEstimator_2018b_COMMON_INCLUDES_ */

   #include "VehicleMassEstimator_2018b_types.h"

/* Block signals and states (default storage) for system '<S8>/IIR_Filter' */
typedef struct
{
   real32_T zi[8]; /* '<S8>/IIR_Filter' */
} DW_IIR_Filter_VehicleMassEstimator_2018b_T;

/* Block signals and states (default storage) for system '<S10>/IIR_Filter' */
typedef struct
{
   real32_T zi[8]; /* '<S10>/IIR_Filter' */
} DW_IIR_Filter_VehicleMassEstimator_2018b_b_T;

/* Block signals and states (default storage) for model 'VehicleMassEstimator_2018b' */
typedef struct
{
   DW_IIR_Filter_VehicleMassEstimator_2018b_b_T sf_IIR_Filter_no; /* '<S15>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_T sf_IIR_Filter_h;    /* '<S14>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_T sf_IIR_Filter_n;    /* '<S13>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_T sf_IIR_Filter_m;    /* '<S12>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_T sf_IIR_Filter_aq;   /* '<S11>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_b_T sf_IIR_Filter_a;  /* '<S10>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_T sf_IIR_Filter_l;    /* '<S9>/IIR_Filter' */
   DW_IIR_Filter_VehicleMassEstimator_2018b_T sf_IIR_Filter;      /* '<S8>/IIR_Filter' */
   real32_T yprev;                                                /* '<S4>/exponential_moving_average' */
   real32_T x;                                                    /* '<S3>/Rate_Limiter' */
   real32_T i;                                                    /* '<S2>/Timer1' */
   real32_T avg_mass_acc;                                         /* '<Root>/MassEstimation_newCalc' */
   real32_T avg_mass_brk;                                         /* '<Root>/MassEstimation_newCalc' */
   real32_T prev_angular_wheel_speed;                             /* '<Root>/MassEstimation_newCalc' */
   real32_T accel_count;                                          /* '<Root>/MassEstimation_newCalc' */
   real32_T brake_count;                                          /* '<Root>/MassEstimation_newCalc' */
   real32_T acc_filt_debounce;                                    /* '<Root>/MassEstimation_newCalc' */
   real32_T brake_filt_debounce;                                  /* '<Root>/MassEstimation_newCalc' */
   real32_T Percent_Convergence;                                  /* '<Root>/MassEstimation_newCalc' */
   struct
   {
      uint_T is_c5_VehicleMassEstimator_2018b:2;        /* '<Root>/Timer' */
      uint_T is_c1_VehicleMassEstimator_2018b:2;        /* '<S2>/Timer1' */
      uint_T is_active_c5_VehicleMassEstimator_2018b:1; /* '<Root>/Timer' */
      uint_T is_active_c1_VehicleMassEstimator_2018b:1; /* '<S2>/Timer1' */
      uint_T initialized_not_empty:1;                   /* '<S4>/exponential_moving_average' */
      uint_T x_not_empty:1;                             /* '<S3>/Rate_Limiter' */
      uint_T prev_angular_wheel_speed_not_empty:1;      /* '<Root>/MassEstimation_newCalc' */
      uint_T converge_flag:1;                           /* '<Root>/MassEstimation_newCalc' */
   } bitsForTID0;
} DW_VehicleMassEstimator_2018b_f_T;

typedef struct
{
   DW_VehicleMassEstimator_2018b_f_T rtdw;
} MdlrefDW_VehicleMassEstimator_2018b_T;

extern void VehicleMassEstimator_2018b_IIR_Filter(const real32_T *rtu_iir_input, real32_T *rty_iir_output,
                                                  DW_IIR_Filter_VehicleMassEstimator_2018b_T *localDW);
extern void VehicleMassEstimator_2018b_IIR_Filter_a(real32_T rtu_iir_input, real32_T *rty_iir_output,
                                                    DW_IIR_Filter_VehicleMassEstimator_2018b_b_T *localDW);
extern void VehicleMassEstimator_2018b(
   const real32_T *rtu_VsVCAN_Nm_Trailer_AxleTrq, const real32_T *rtu_filt_veh_speed_over_ground,
   const real32_T *rtu_wheel_running_radius, const real32_T *rtu_VsVCAN_Nm_BrkTrq, const real32_T *rtu_comp_long_accel,
   const real32_T *rtu_comp_yaw_rate_filtered, const real32_T *rtu_GearReductionRatio, const real32_T *rtu_wheel_rpm_front_right,
   const real32_T *rtu_wheel_rpm_front_left, const real32_T *rtu_VsVCAN_Trailer_ITBM_Power,
   const enum_Presence_Status *rtu_VeVSE_TrlrDetectSts, const uint8_T *rtu_CmdIgnSts, const boolean_T *rtu_CANNode95_ITBM,
   const boolean_T *rtu_f_stationary, const uint8_T *rtu_Brk_Stat, real32_T *rty_VsVSE_Kg_TrlrMass,
   boolean_T *rty_VsVSE_b_TrlrMassConvSts, real32_T *rty_VsVSE_s_TrlrMassCalcTimer, real32_T *rty_VsVSE_TrlrTotalCount,
   real32_T *rty_VsVSE_TrlrCountAccel, real32_T *rty_VsVSE_TrlrCountBrake, real32_T *rty_VsVSE_TrlrRunningAvgAccel,
   real32_T *rty_VsVSE_TrlrRunningAvgBrake, real32_T *rty_VsVSE_TrlrMassConvPercent, boolean_T *rty_VsVSE_b_ResetFlag,
   real32_T *rty_VsVSE_EstMassRunningAvg, DW_VehicleMassEstimator_2018b_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Switch' : Eliminated due to constant selection input
 * Block '<S2>/Switch1' : Eliminated due to constant selection input
 * Block '<S2>/Switch2' : Eliminated due to constant selection input
 * Block '<S2>/Switch3' : Eliminated due to constant selection input
 * Block '<S2>/Switch4' : Eliminated due to constant selection input
 * Block '<S4>/Cast To Single' : Eliminate redundant data type conversion
 * Block '<S4>/Reshape' : Reshape block reduction
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant5' : Unused code path elimination
 * Block '<Root>/Constant8' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Constant10' : Unused code path elimination
 * Block '<S2>/Constant12' : Unused code path elimination
 * Block '<S2>/Constant3' : Unused code path elimination
 * Block '<S2>/Constant4' : Unused code path elimination
 * Block '<S2>/Constant5' : Unused code path elimination
 * Block '<S2>/Constant6' : Unused code path elimination
 * Block '<S2>/Constant7' : Unused code path elimination
 * Block '<S2>/Constant8' : Unused code path elimination
 * Block '<S2>/Less Than' : Unused code path elimination
 * Block '<S2>/Less Than1' : Unused code path elimination
 * Block '<S2>/OR1' : Unused code path elimination
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
 * '<Root>' : 'VehicleMassEstimator_2018b'
 * '<S1>'   : 'VehicleMassEstimator_2018b/MassEstimation_newCalc'
 * '<S2>'   : 'VehicleMassEstimator_2018b/Mass_Resting_Conditions'
 * '<S3>'   : 'VehicleMassEstimator_2018b/Rate_Limiter'
 * '<S4>'   : 'VehicleMassEstimator_2018b/Subsystem3'
 * '<S5>'   : 'VehicleMassEstimator_2018b/Timer'
 * '<S6>'   : 'VehicleMassEstimator_2018b/TrailerChecks'
 * '<S7>'   : 'VehicleMassEstimator_2018b/forgettingfactorcalc'
 * '<S8>'   : 'VehicleMassEstimator_2018b/low_pass_filter'
 * '<S9>'   : 'VehicleMassEstimator_2018b/low_pass_filter1'
 * '<S10>'  : 'VehicleMassEstimator_2018b/low_pass_filter2'
 * '<S11>'  : 'VehicleMassEstimator_2018b/low_pass_filter3'
 * '<S12>'  : 'VehicleMassEstimator_2018b/low_pass_filter4'
 * '<S13>'  : 'VehicleMassEstimator_2018b/low_pass_filter5'
 * '<S14>'  : 'VehicleMassEstimator_2018b/low_pass_filter6'
 * '<S15>'  : 'VehicleMassEstimator_2018b/low_pass_filter7'
 * '<S16>'  : 'VehicleMassEstimator_2018b/Mass_Resting_Conditions/Timer1'
 * '<S17>'  : 'VehicleMassEstimator_2018b/Rate_Limiter/Rate_Limiter'
 * '<S18>'  : 'VehicleMassEstimator_2018b/Subsystem3/exponential_moving_average'
 * '<S19>'  : 'VehicleMassEstimator_2018b/TrailerChecks/Compare To Constant'
 * '<S20>'  : 'VehicleMassEstimator_2018b/TrailerChecks/Compare To Constant2'
 * '<S21>'  : 'VehicleMassEstimator_2018b/low_pass_filter/IIR_Filter'
 * '<S22>'  : 'VehicleMassEstimator_2018b/low_pass_filter1/IIR_Filter'
 * '<S23>'  : 'VehicleMassEstimator_2018b/low_pass_filter2/IIR_Filter'
 * '<S24>'  : 'VehicleMassEstimator_2018b/low_pass_filter3/IIR_Filter'
 * '<S25>'  : 'VehicleMassEstimator_2018b/low_pass_filter4/IIR_Filter'
 * '<S26>'  : 'VehicleMassEstimator_2018b/low_pass_filter5/IIR_Filter'
 * '<S27>'  : 'VehicleMassEstimator_2018b/low_pass_filter6/IIR_Filter'
 * '<S28>'  : 'VehicleMassEstimator_2018b/low_pass_filter7/IIR_Filter'
 */
#endif /* RTW_HEADER_VehicleMassEstimator_2018b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
