/*
 * File: RollRateCompensation.h
 *
 * Code generated for Simulink model 'RollRateCompensation'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:24 2026
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

#ifndef RTW_HEADER_RollRateCompensation_h_
   #define RTW_HEADER_RollRateCompensation_h_
   #ifndef RollRateCompensation_COMMON_INCLUDES_
      #define RollRateCompensation_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* RollRateCompensation_COMMON_INCLUDES_ */

   #include "RollRateCompensation_types.h"

/* Block signals and states (default storage) for model 'RollRateCompensation' */
typedef struct
{
   real32_T Delay4_DSTATE; /* '<S3>/Delay4' */
   real32_T Delay6_DSTATE; /* '<S1>/Delay6' */
   real32_T Delay5_DSTATE; /* '<S3>/Delay5' */
   real32_T Delay3_DSTATE; /* '<S3>/Delay3' */
   real32_T Delay_DSTATE;  /* '<S6>/Delay' */
   real32_T Delay1_DSTATE; /* '<S6>/Delay1' */
   struct
   {
      uint_T Delay2_DSTATE:1;   /* '<S3>/Delay2' */
      uint_T Delay7_DSTATE:1;   /* '<S3>/Delay7' */
      uint_T Delay1_DSTATE_i:1; /* '<S3>/Delay1' */
   } bitsForTID0;
} DW_RollRateCompensation_f_T;

typedef struct
{
   DW_RollRateCompensation_f_T rtdw;
} MdlrefDW_RollRateCompensation_T;

extern void RollRateCompensation(const real32_T *rtu_raw_roll_rate_rps, const enum_quality_factor_T *rtu_raw_roll_rate_qf,
                                 const boolean_T *rtu_f_stationary, real32_T *rty_roll_rate_bias,
                                 real32_T *rty_comp_roll_rate_unfiltered, real32_T *rty_comp_roll_rate_filtered,
                                 enum_quality_factor_T *rty_comp_roll_rate_qf, boolean_T *rty_f_stop_rollrate_bias_converged,
                                 DW_RollRateCompensation_f_T *localDW);

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
 * '<Root>' : 'RollRateCompensation'
 * '<S1>'   : 'RollRateCompensation/RollRateCompensation'
 * '<S2>'   : 'RollRateCompensation/RollRateCompensation/Compare To Constant1'
 * '<S3>'   : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary'
 * '<S4>'   : 'RollRateCompensation/RollRateCompensation/First_Order_Lag_Filter'
 * '<S5>'   : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/By-pass previous values'
 * '<S6>'   : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias'
 * '<S7>'   : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/Compare To Constant'
 * '<S8>'   : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action Subsystem'
 * '<S9>'   : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action Subsystem1'
 * '<S10>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action Subsystem2'
 * '<S11>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action Subsystem3'
 * '<S12>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action Subsystem4'
 * '<S13>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action Subsystem5'
 * '<S14>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem/FirstOrderLagFilter'
 * '<S15>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem1/FirstOrderLagFilter'
 * '<S16>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem2/Compare To Constant'
 * '<S17>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem2/Compare To Constant1'
 * '<S18>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem3/Compare To Constant'
 * '<S19>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem3/Compare To Constant1'
 * '<S20>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem4/Compare To Constant'
 * '<S21>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem4/Compare To Constant1'
 * '<S22>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem4/First_Order_Lag_Filter'
 * '<S23>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem5/Compare To Constant'
 * '<S24>'  : 'RollRateCompensation/RollRateCompensation/Find_IMU_Signal_Bias_When_Stationary/CalculateBias/If Action
 * Subsystem5/Compare To Constant1'
 */
#endif /* RTW_HEADER_RollRateCompensation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
