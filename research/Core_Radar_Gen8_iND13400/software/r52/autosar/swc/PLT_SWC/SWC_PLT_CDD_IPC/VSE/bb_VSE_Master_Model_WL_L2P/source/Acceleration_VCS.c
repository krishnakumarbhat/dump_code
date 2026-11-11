/*
 * File: Acceleration_VCS.c
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

#include "Acceleration_VCS.h"
#include "Acceleration_VCS_private.h"

/* Named constants for Chart: '<S1>/Chart1' */
#define Acceleration_VCS_IN_Initialize ((uint8_T)1U)
#define Acceleration_VCS_IN_Running    ((uint8_T)2U)

/* Output and update for referenced model: 'Acceleration_VCS' */
void Acceleration_VCS(const real32_T *rtu_vcs_lat_velocity, const real32_T *rtu_vcs_long_velocity,
                      const real32_T *rtu_comp_yaw_rate_filtered, const enum_quality_factor_T *rtu_filt_veh_speed_over_ground_qf,
                      const enum_quality_factor_T *rtu_comp_yaw_rate_qf, real32_T *rty_vcs_lat_accel, real32_T *rty_vcs_long_accel,
                      enum_quality_factor_T *rty_vcs_lat_accel_qf, enum_quality_factor_T *rty_vcs_long_accel_qf,
                      DW_Acceleration_VCS_f_T *localDW)
{
   real32_T rtb_Add1;
   uint8_T rtb_Min;

   /* Chart: '<S1>/Chart1' */
   if (((uint32_T)localDW->bitsForTID0.is_active_c2_Acceleration_VCS) == 0U)
   {
      localDW->bitsForTID0.is_active_c2_Acceleration_VCS   = 1;
      localDW->bitsForTID0.is_c2_Acceleration_VCS          = Acceleration_VCS_IN_Initialize;
      localDW->bitsForTID0.f_initialize_speed_to_accel_vcs = true;
   }
   else if (((uint32_T)localDW->bitsForTID0.is_c2_Acceleration_VCS) == Acceleration_VCS_IN_Initialize)
   {
      if (localDW->bitsForTID0.f_initialize_speed_to_accel_vcs)
      {
         localDW->bitsForTID0.is_c2_Acceleration_VCS          = Acceleration_VCS_IN_Running;
         localDW->bitsForTID0.f_initialize_speed_to_accel_vcs = false;
      }
   }
   else
   {
      localDW->bitsForTID0.f_initialize_speed_to_accel_vcs = false;
   }

   /* End of Chart: '<S1>/Chart1' */

   /* Outputs for Enabled SubSystem: '<S1>/Speed_To_Accel_TF_Coeff' incorporates:
    *  EnablePort: '<S3>/Enable'
    */
   if (localDW->bitsForTID0.f_initialize_speed_to_accel_vcs)
   {
      /* MATLAB Function: '<S3>/Find_Speed_To_Accel_TF' */
      localDW->num_discrete[0] = 1.10854352F;
      localDW->den_discrete[0] = 1.0F;
      localDW->num_discrete[1] = 1.10854352F;
      localDW->den_discrete[1] = -0.778631747F;
      localDW->num_discrete[2] = -1.10854352F;
      localDW->den_discrete[2] = -0.977829158F;
      localDW->num_discrete[3] = -1.10854352F;
      localDW->den_discrete[3] = 0.800802648F;
   }

   /* End of Outputs for SubSystem: '<S1>/Speed_To_Accel_TF_Coeff' */

   /* DiscreteFilter: '<S1>/Discrete Filter1' */
   localDW->DiscreteFilter1_tmp = (((*rtu_vcs_lat_velocity) - (localDW->den_discrete[1] * localDW->DiscreteFilter1_states[0])) -
                                   (localDW->den_discrete[2] * localDW->DiscreteFilter1_states[1])) -
                                  (localDW->den_discrete[3] * localDW->DiscreteFilter1_states[2]);

   /* Sum: '<S1>/Add' incorporates:
    *  DiscreteFilter: '<S1>/Discrete Filter1'
    *  Product: '<S1>/Product'
    */
   rtb_Add1 = ((((localDW->num_discrete[0] * localDW->DiscreteFilter1_tmp) +
                 (localDW->num_discrete[1] * localDW->DiscreteFilter1_states[0])) +
                (localDW->num_discrete[2] * localDW->DiscreteFilter1_states[1])) +
               (localDW->num_discrete[3] * localDW->DiscreteFilter1_states[2])) +
              ((*rtu_comp_yaw_rate_filtered) * (*rtu_vcs_long_velocity));

   /* Saturate: '<S1>/Saturation1' */
   if (rtb_Add1 > 10.0F)
   {
      *rty_vcs_lat_accel = 10.0F;
   }
   else if (rtb_Add1 < -10.0F)
   {
      *rty_vcs_lat_accel = -10.0F;
   }
   else
   {
      *rty_vcs_lat_accel = rtb_Add1;
   }

   /* End of Saturate: '<S1>/Saturation1' */

   /* DiscreteFilter: '<S1>/Discrete Filter' */
   localDW->DiscreteFilter_tmp = (((*rtu_vcs_long_velocity) - (localDW->den_discrete[1] * localDW->DiscreteFilter_states[0])) -
                                  (localDW->den_discrete[2] * localDW->DiscreteFilter_states[1])) -
                                 (localDW->den_discrete[3] * localDW->DiscreteFilter_states[2]);

   /* Sum: '<S1>/Add1' incorporates:
    *  DiscreteFilter: '<S1>/Discrete Filter'
    *  Product: '<S1>/Product1'
    */
   rtb_Add1 = ((((localDW->num_discrete[0] * localDW->DiscreteFilter_tmp) +
                 (localDW->num_discrete[1] * localDW->DiscreteFilter_states[0])) +
                (localDW->num_discrete[2] * localDW->DiscreteFilter_states[1])) +
               (localDW->num_discrete[3] * localDW->DiscreteFilter_states[2])) -
              ((*rtu_vcs_lat_velocity) * (*rtu_comp_yaw_rate_filtered));

   /* Saturate: '<S1>/Saturation2' */
   if (rtb_Add1 > 10.0F)
   {
      *rty_vcs_long_accel = 10.0F;
   }
   else if (rtb_Add1 < -10.0F)
   {
      *rty_vcs_long_accel = -10.0F;
   }
   else
   {
      *rty_vcs_long_accel = rtb_Add1;
   }

   /* End of Saturate: '<S1>/Saturation2' */

   /* DataTypeConversion: '<S1>/Cast1' */
   rtb_Min = (uint8_T)(*rtu_comp_yaw_rate_qf);

   /* MinMax: '<S1>/Min' */
   if ((*rtu_filt_veh_speed_over_ground_qf) < (*rtu_comp_yaw_rate_qf))
   {
      rtb_Min = (uint8_T)(*rtu_filt_veh_speed_over_ground_qf);
   }

   /* End of MinMax: '<S1>/Min' */

   /* DataTypeConversion: '<S1>/Data Type Conversion1' */
   *rty_vcs_lat_accel_qf = (enum_quality_factor_T)rtb_Min;

   /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
    *  DataTypeConversion: '<S1>/Data Type Conversion1'
    */
   *rty_vcs_long_accel_qf = (enum_quality_factor_T)rtb_Min;

   /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
   localDW->DiscreteFilter1_states[2] = localDW->DiscreteFilter1_states[1];
   localDW->DiscreteFilter1_states[1] = localDW->DiscreteFilter1_states[0];
   localDW->DiscreteFilter1_states[0] = localDW->DiscreteFilter1_tmp;

   /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
   localDW->DiscreteFilter_states[2] = localDW->DiscreteFilter_states[1];
   localDW->DiscreteFilter_states[1] = localDW->DiscreteFilter_states[0];
   localDW->DiscreteFilter_states[0] = localDW->DiscreteFilter_tmp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
