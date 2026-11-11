/*
 * File: Yaw_Rate_Rationality_Check.h
 *
 * Code generated for Simulink model 'Yaw_Rate_Rationality_Check'.
 *
 * Model version                  : 1.253
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:07:53 2026
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

#ifndef RTW_HEADER_Yaw_Rate_Rationality_Check_h_
   #define RTW_HEADER_Yaw_Rate_Rationality_Check_h_
   #ifndef Yaw_Rate_Rationality_Check_COMMON_INCLUDES_
      #define Yaw_Rate_Rationality_Check_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* Yaw_Rate_Rationality_Check_COMMON_INCLUDES_ */

   #include "Yaw_Rate_Rationality_Check_types.h"

   /* Child system includes */
   #include "Signal_Rationality_Check_Common.h"

/* Block signals and states (default storage) for model 'Yaw_Rate_Rationality_Check' */
typedef struct
{
   MdlrefDW_Signal_Rationality_Check_Common_T
      YawRateRationalityCheckInNormalScenraio_InstanceData; /* '<S3>/YawRateRationalityCheckInNormalScenraio' */
   MdlrefDW_Signal_Rationality_Check_Common_T
      YawRateRationalityCheckInStandstillBiasNotLearned_InstanceData; /* '<S2>/YawRateRationalityCheckInStandstillBiasNotLearned'
                                                                       */
   real32_T UnitDelay_DSTATE;                                         /* '<S4>/Unit Delay' */
} DW_Yaw_Rate_Rationality_Check_f_T;

typedef struct
{
   DW_Yaw_Rate_Rationality_Check_f_T rtdw;
} MdlrefDW_Yaw_Rate_Rationality_Check_T;

extern void Yaw_Rate_Rationality_Check(
   const boolean_T *rtu_f_yaw_rate_stop_bias_converged_primary, const boolean_T *rtu_f_yaw_rate_stop_bias_converged_secondary,
   const real32_T *rtu_uncomp_primary_yaw_rate, const real32_T *rtu_uncomp_secondary_yaw_rate,
   const real32_T *rtu_uncomp_tertiary_yaw_rate, const enum_quality_factor_T *rtu_uncomp_primary_yaw_rate_qf,
   const enum_quality_factor_T *rtu_uncomp_secondary_yaw_rate_qf, const enum_quality_factor_T *rtu_uncomp_tertiary_yaw_rate_qf,
   const real32_T *rtu_acceptable_yaw_rate_diff_IfStandstillBiasIsNotLearned, const real32_T *rtu_fault_maturation_time,
   const real32_T *rtu_default_maturation_time, const boolean_T *rtu_use_tertiary_signal,
   const boolean_T *rtu_do_rationality_check, const real32_T *rtu_comp_filt_primary_yaw_rate,
   const real32_T *rtu_comp_filt_secondary_yaw_rate, const real32_T *rtu_comp_filt_tertiary_yaw_rate,
   const enum_quality_factor_T *rtu_comp_filt_primary_yaw_rate_qf,
   const enum_quality_factor_T *rtu_comp_filt_secondary_yaw_rate_qf,
   const enum_quality_factor_T *rtu_comp_filt_tertiary_yaw_rate_qf,
   const real32_T *rtu_acceptable_yaw_rate_diff_IfStandstillBiasIsLearned, boolean_T *rty_yaw_rate_rationality_check_status,
   DW_Yaw_Rate_Rationality_Check_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Yaw_Rate_Rationality_Check'
 * '<S1>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck'
 * '<S2>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/If Action Subsystem'
 * '<S3>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/If Action Subsystem1'
 * '<S4>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic'
 * '<S5>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic/Compare To Constant1'
 * '<S6>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic/Compare To Constant2'
 * '<S7>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic/Compare To Constant3'
 * '<S8>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic/Compare To Constant4'
 * '<S9>'   : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic/Compare To Constant5'
 * '<S10>'  : 'Yaw_Rate_Rationality_Check/YawRateRationalityCheck/Timer_Logic/Compare To Constant6'
 */
#endif /* RTW_HEADER_Yaw_Rate_Rationality_Check_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
