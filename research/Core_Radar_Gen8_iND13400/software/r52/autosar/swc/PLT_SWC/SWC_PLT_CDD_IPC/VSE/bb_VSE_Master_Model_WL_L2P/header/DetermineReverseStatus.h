/*
 * File: DetermineReverseStatus.h
 *
 * Code generated for Simulink model 'DetermineReverseStatus'.
 *
 * Model version                  : 1.870
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:52 2026
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

#ifndef RTW_HEADER_DetermineReverseStatus_h_
   #define RTW_HEADER_DetermineReverseStatus_h_
   #ifndef DetermineReverseStatus_COMMON_INCLUDES_
      #define DetermineReverseStatus_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* DetermineReverseStatus_COMMON_INCLUDES_ */

   #include "DetermineReverseStatus_types.h"

/* Block signals and states (default storage) for model 'DetermineReverseStatus' */
typedef struct
{
   uint8_T UnitDelay1_DSTATE; /* '<S6>/Unit Delay1' */
   uint8_T UnitDelay_DSTATE;  /* '<S6>/Unit Delay' */
   uint8_T UnitDelay3_DSTATE; /* '<S6>/Unit Delay3' */
   uint8_T UnitDelay2_DSTATE; /* '<S6>/Unit Delay2' */
   uint8_T UnitDelay5_DSTATE; /* '<S6>/Unit Delay5' */
   uint8_T UnitDelay4_DSTATE; /* '<S6>/Unit Delay4' */
   uint8_T UnitDelay7_DSTATE; /* '<S6>/Unit Delay7' */
   uint8_T UnitDelay6_DSTATE; /* '<S6>/Unit Delay6' */
} DW_DetermineReverseStatus_f_T;

typedef struct
{
   DW_DetermineReverseStatus_f_T rtdw;
} MdlrefDW_DetermineReverseStatus_T;

extern void DetermineReverseStatus(const uint8_T *rtu_WhlRotDrctnlStLftDrvn, const uint8_T *rtu_WhlRotDrctnlStLfNDrvn,
                                   const uint8_T *rtu_WhlRotDrctnlStRtDrvn, const uint8_T *rtu_WhlRotDrctnlSRtNDrvn,
                                   const uint8_T *rtu_fl_wheel_pulse_counter, const uint8_T *rtu_fr_wheel_pulse_counter,
                                   const uint8_T *rtu_rl_wheel_pulse_counter, const uint8_T *rtu_rr_wheel_pulse_counter,
                                   const uint8_T *rtu_gear_box_pos, const enum_quality_factor_T *rtu_fl_wheel_pulse_counter_qf,
                                   const enum_quality_factor_T *rtu_fr_wheel_pulse_counter_qf,
                                   const enum_quality_factor_T *rtu_rl_wheel_pulse_counter_qf,
                                   const enum_quality_factor_T *rtu_rr_wheel_pulse_counter_qf, boolean_T *rty_f_reverse,
                                   DW_DetermineReverseStatus_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Cast' : Eliminate redundant data type conversion
 * Block '<S7>/Cast1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'DetermineReverseStatus'
 * '<S1>'   : 'DetermineReverseStatus/Reverse Status Calculation'
 * '<S2>'   : 'DetermineReverseStatus/Reverse Status Calculation/Compare To Constant'
 * '<S3>'   : 'DetermineReverseStatus/Reverse Status Calculation/Compare To Constant1'
 * '<S4>'   : 'DetermineReverseStatus/Reverse Status Calculation/Compare To Constant2'
 * '<S5>'   : 'DetermineReverseStatus/Reverse Status Calculation/Compare To Constant3'
 * '<S6>'   : 'DetermineReverseStatus/Reverse Status Calculation/Determine_Host_Wheel_Rotational_Direction1'
 * '<S7>'   : 'DetermineReverseStatus/Reverse Status Calculation/Gear_Box_Position_Reverse_Sts'
 */
#endif /* RTW_HEADER_DetermineReverseStatus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
