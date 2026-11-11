/*
 * File: HeadingAngleandLatLongDisplacement.h
 *
 * Code generated for Simulink model 'HeadingAngleandLatLongDisplacement'.
 *
 * Model version                  : 1.475
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:16 2026
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

#ifndef RTW_HEADER_HeadingAngleandLatLongDisplacement_h_
   #define RTW_HEADER_HeadingAngleandLatLongDisplacement_h_
   #ifndef HeadingAngleandLatLongDisplacement_COMMON_INCLUDES_
      #define HeadingAngleandLatLongDisplacement_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* HeadingAngleandLatLongDisplacement_COMMON_INCLUDES_ */

   #include "HeadingAngleandLatLongDisplacement_types.h"

/* Block signals and states (default storage) for model 'HeadingAngleandLatLongDisplacement' */
typedef struct
{
   real32_T Minus3;        /* '<S3>/Minus3' */
   real32_T Delay_DSTATE;  /* '<Root>/Delay' */
   real32_T Delay1_DSTATE; /* '<Root>/Delay1' */
   real32_T Delay2_DSTATE; /* '<Root>/Delay2' */
   real32_T Delay3_DSTATE; /* '<Root>/Delay3' */
} DW_HeadingAngleandLatLongDisplacement_f_T;

typedef struct
{
   DW_HeadingAngleandLatLongDisplacement_f_T rtdw;
} MdlrefDW_HeadingAngleandLatLongDisplacement_T;

extern void HeadingAngleandLatLongDisplacement(const real32_T *rtu_VCS_Lat_Velocity, const real32_T *rtu_VCS_Long_Velocity,
                                               const real32_T *rtu_comp_yaw_rate_filtered,
                                               const enum_quality_factor_T *rtu_comp_yaw_rate_filtered_qf,
                                               const real32_T *rtu_VCS_Sideslip, const boolean_T *rtu_f_yaw_stop_bias_converged,
                                               real32_T *rty_Lat_Delta_ULVC, real32_T *rty_Long_Delta_ULVC,
                                               real32_T *rty_Heading_Delta_ULVC, enum_quality_factor_T *rty_Heading_Delta_ULVC_QF,
                                               DW_HeadingAngleandLatLongDisplacement_f_T *localDW);

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
 * '<Root>' : 'HeadingAngleandLatLongDisplacement'
 * '<S1>'   : 'HeadingAngleandLatLongDisplacement/HeadingAngleandLatLongDisplacement'
 * '<S2>'   : 'HeadingAngleandLatLongDisplacement/HeadingAngleandLatLongDisplacement/Elapsed_Time'
 * '<S3>'   : 'HeadingAngleandLatLongDisplacement/HeadingAngleandLatLongDisplacement/Subsystem'
 */
#endif /* RTW_HEADER_HeadingAngleandLatLongDisplacement_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
