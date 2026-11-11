/*
 * File: Signal_Rationality_Check_Common.h
 *
 * Code generated for Simulink model 'Signal_Rationality_Check_Common'.
 *
 * Model version                  : 1.211
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:38 2026
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

#ifndef RTW_HEADER_Signal_Rationality_Check_Common_h_
   #define RTW_HEADER_Signal_Rationality_Check_Common_h_
   #include <math.h>
   #ifndef Signal_Rationality_Check_Common_COMMON_INCLUDES_
      #define Signal_Rationality_Check_Common_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* Signal_Rationality_Check_Common_COMMON_INCLUDES_ */

   #include "Signal_Rationality_Check_Common_types.h"

/* Block signals and states (default storage) for model 'Signal_Rationality_Check_Common' */
typedef struct
{
   real32_T matured_time;   /* '<S9>/MATLAB Function' */
   real32_T dematured_time; /* '<S9>/MATLAB Function' */
   struct
   {
      uint_T GreaterThan:1;           /* '<S8>/GreaterThan' */
      uint_T LogicalOperator:1;       /* '<S7>/Logical Operator' */
      uint_T prev_final_fault_flag:1; /* '<S9>/MATLAB Function' */
   } bitsForTID0;
} DW_Signal_Rationality_Check_Common_f_T;

typedef struct
{
   DW_Signal_Rationality_Check_Common_f_T rtdw;
} MdlrefDW_Signal_Rationality_Check_Common_T;

extern void Signal_Rationality_Check_Common(
   const real32_T *rtu_signal_priority_1, const real32_T *rtu_signal_priority_2, const real32_T *rtu_signal_priority_3,
   const enum_quality_factor_T *rtu_signal_priority_1_qf, const enum_quality_factor_T *rtu_signal_priority_2_qf,
   const enum_quality_factor_T *rtu_signal_priority_3_qf, const real32_T *rtu_k_acceptable_absolute_difference,
   const real32_T *rtu_fault_maturation_time, const real32_T *rtu_fault_dematuration_time,
   const boolean_T *rtu_f_use_tertiary_signal, const boolean_T *rtu_f_do_rationality_check,
   boolean_T *rty_f_rationality_check_passed, DW_Signal_Rationality_Check_Common_f_T *localDW);

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
 * '<Root>' : 'Signal_Rationality_Check_Common'
 * '<S1>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check'
 * '<S2>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Compare To Constant'
 * '<S3>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Compare To Constant1'
 * '<S4>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Compare To Constant3'
 * '<S5>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Compare To Constant4'
 * '<S6>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Compare To Constant5'
 * '<S7>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/CompareThreeSignals'
 * '<S8>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/CompareTwoSignals'
 * '<S9>'   : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Maturation_DeMaturation_Block'
 * '<S10>'  : 'Signal_Rationality_Check_Common/Signal_Rationality_Check/Maturation_DeMaturation_Block/MATLAB Function'
 */
#endif /* RTW_HEADER_Signal_Rationality_Check_Common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
