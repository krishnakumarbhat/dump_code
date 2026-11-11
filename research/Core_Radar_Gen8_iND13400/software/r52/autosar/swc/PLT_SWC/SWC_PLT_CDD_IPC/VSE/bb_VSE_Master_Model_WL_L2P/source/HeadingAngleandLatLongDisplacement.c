/*
 * File: HeadingAngleandLatLongDisplacement.c
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

#include "HeadingAngleandLatLongDisplacement.h"
#include "HeadingAngleandLatLongDisplacement_private.h"

/* Output and update for referenced model: 'HeadingAngleandLatLongDisplacement' */
void HeadingAngleandLatLongDisplacement(const real32_T *rtu_VCS_Lat_Velocity, const real32_T *rtu_VCS_Long_Velocity,
                                        const real32_T *rtu_comp_yaw_rate_filtered,
                                        const enum_quality_factor_T *rtu_comp_yaw_rate_filtered_qf,
                                        const real32_T *rtu_VCS_Sideslip, const boolean_T *rtu_f_yaw_stop_bias_converged,
                                        real32_T *rty_Lat_Delta_ULVC, real32_T *rty_Long_Delta_ULVC,
                                        real32_T *rty_Heading_Delta_ULVC, enum_quality_factor_T *rty_Heading_Delta_ULVC_QF,
                                        DW_HeadingAngleandLatLongDisplacement_f_T *localDW)
{
   /* Gain: '<S1>/Gain2' incorporates:
    *  Delay: '<Root>/Delay'
    *  Gain: '<S1>/Gain'
    *  Sum: '<S1>/Minus'
    */
   *rty_Lat_Delta_ULVC = -(((*rtu_VCS_Lat_Velocity) - localDW->Delay_DSTATE) * 0.01F);

   /* Gain: '<S1>/Gain3' incorporates:
    *  Delay: '<Root>/Delay1'
    *  Gain: '<S1>/Gain1'
    *  Sum: '<S1>/Minus1'
    */
   *rty_Long_Delta_ULVC = ((*rtu_VCS_Long_Velocity) - localDW->Delay1_DSTATE) * 0.01F;

   /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
    *  EnablePort: '<S3>/Enable'
    */
   if (*rtu_f_yaw_stop_bias_converged)
   {
      /* Sum: '<S3>/Minus3' incorporates:
       *  Delay: '<Root>/Delay2'
       *  Delay: '<Root>/Delay3'
       *  Gain: '<S3>/Gain2'
       *  Sum: '<S3>/Minus1'
       *  Sum: '<S3>/Minus2'
       */
      localDW->Minus3 =
         (((*rtu_comp_yaw_rate_filtered) - localDW->Delay2_DSTATE) * 0.01F) + ((*rtu_VCS_Sideslip) - localDW->Delay3_DSTATE);
   }

   /* End of Outputs for SubSystem: '<S1>/Subsystem' */

   /* Gain: '<S1>/Gain4' */
   *rty_Heading_Delta_ULVC = -localDW->Minus3;

   /* Inport: '<Root>/comp_yaw_rate_filtered_qf' */
   *rty_Heading_Delta_ULVC_QF = *rtu_comp_yaw_rate_filtered_qf;

   /* Update for Delay: '<Root>/Delay' */
   localDW->Delay_DSTATE = *rtu_VCS_Lat_Velocity;

   /* Update for Delay: '<Root>/Delay1' */
   localDW->Delay1_DSTATE = *rtu_VCS_Long_Velocity;

   /* Update for Delay: '<Root>/Delay2' */
   localDW->Delay2_DSTATE = *rtu_comp_yaw_rate_filtered;

   /* Update for Delay: '<Root>/Delay3' */
   localDW->Delay3_DSTATE = *rtu_VCS_Sideslip;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
