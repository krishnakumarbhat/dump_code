/*
 * File: Acceleration_VCS.h
 *
 * Code generated for Simulink model 'Acceleration_VCS'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:47 2026
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

#ifndef RTW_HEADER_Acceleration_VCS_h_
   #define RTW_HEADER_Acceleration_VCS_h_
   #ifndef Acceleration_VCS_COMMON_INCLUDES_
      #define Acceleration_VCS_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* Acceleration_VCS_COMMON_INCLUDES_ */

   #include "Acceleration_VCS_types.h"

/* Block signals and states (default storage) for model 'Acceleration_VCS' */
typedef struct
{
   real32_T num_discrete[4];           /* '<S3>/Find_Speed_To_Accel_TF' */
   real32_T den_discrete[4];           /* '<S3>/Find_Speed_To_Accel_TF' */
   real32_T DiscreteFilter1_states[3]; /* '<S1>/Discrete Filter1' */
   real32_T DiscreteFilter_states[3];  /* '<S1>/Discrete Filter' */
   real32_T DiscreteFilter1_tmp;       /* '<S1>/Discrete Filter1' */
   real32_T DiscreteFilter_tmp;        /* '<S1>/Discrete Filter' */
   struct
   {
      uint_T is_c2_Acceleration_VCS:2;          /* '<S1>/Chart1' */
      uint_T is_active_c2_Acceleration_VCS:1;   /* '<S1>/Chart1' */
      uint_T f_initialize_speed_to_accel_vcs:1; /* '<S1>/Chart1' */
   } bitsForTID0;
} DW_Acceleration_VCS_f_T;

typedef struct
{
   DW_Acceleration_VCS_f_T rtdw;
} MdlrefDW_Acceleration_VCS_T;

extern void Acceleration_VCS(const real32_T *rtu_vcs_lat_velocity, const real32_T *rtu_vcs_long_velocity,
                             const real32_T *rtu_comp_yaw_rate_filtered,
                             const enum_quality_factor_T *rtu_filt_veh_speed_over_ground_qf,
                             const enum_quality_factor_T *rtu_comp_yaw_rate_qf, real32_T *rty_vcs_lat_accel,
                             real32_T *rty_vcs_long_accel, enum_quality_factor_T *rty_vcs_lat_accel_qf,
                             enum_quality_factor_T *rty_vcs_long_accel_qf, DW_Acceleration_VCS_f_T *localDW);

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
 * '<Root>' : 'Acceleration_VCS'
 * '<S1>'   : 'Acceleration_VCS/Acceleration_VCS'
 * '<S2>'   : 'Acceleration_VCS/Acceleration_VCS/Chart1'
 * '<S3>'   : 'Acceleration_VCS/Acceleration_VCS/Speed_To_Accel_TF_Coeff'
 * '<S4>'   : 'Acceleration_VCS/Acceleration_VCS/Speed_To_Accel_TF_Coeff/Find_Speed_To_Accel_TF'
 */
#endif /* RTW_HEADER_Acceleration_VCS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
