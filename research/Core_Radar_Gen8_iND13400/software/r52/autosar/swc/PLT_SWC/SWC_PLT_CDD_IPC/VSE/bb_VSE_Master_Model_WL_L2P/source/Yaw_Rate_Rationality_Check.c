/*
 * File: Yaw_Rate_Rationality_Check.c
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

#include "Yaw_Rate_Rationality_Check.h"
#include "Yaw_Rate_Rationality_Check_private.h"

/* Output and update for referenced model: 'Yaw_Rate_Rationality_Check' */
void Yaw_Rate_Rationality_Check(
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
   DW_Yaw_Rate_Rationality_Check_f_T *localDW)
{
   /* Switch: '<S4>/Switch' incorporates:
    *  Constant: '<S10>/Constant'
    *  Constant: '<S4>/Constant1'
    *  Constant: '<S4>/Constant2'
    *  Constant: '<S5>/Constant'
    *  Constant: '<S6>/Constant'
    *  Constant: '<S7>/Constant'
    *  Constant: '<S8>/Constant'
    *  Constant: '<S9>/Constant'
    *  Logic: '<S4>/Logical Operator'
    *  Logic: '<S4>/Logical Operator1'
    *  Logic: '<S4>/Logical Operator2'
    *  Logic: '<S4>/Logical Operator3'
    *  RelationalOperator: '<S10>/Compare'
    *  RelationalOperator: '<S5>/Compare'
    *  RelationalOperator: '<S6>/Compare'
    *  RelationalOperator: '<S7>/Compare'
    *  RelationalOperator: '<S8>/Compare'
    *  RelationalOperator: '<S9>/Compare'
    *  Sum: '<S4>/Add'
    *  UnitDelay: '<S4>/Unit Delay'
    */
   if ((((((uint32_T)(*rtu_uncomp_primary_yaw_rate_qf)) == ACCURATED) &&
         (((uint32_T)(*rtu_comp_filt_primary_yaw_rate_qf)) != ACCURATED)) ||
        ((((uint32_T)(*rtu_uncomp_secondary_yaw_rate_qf)) == ACCURATED) &&
         (((uint32_T)(*rtu_comp_filt_secondary_yaw_rate_qf)) != ACCURATED))) ||
       ((((uint32_T)(*rtu_uncomp_tertiary_yaw_rate_qf)) == ACCURATED) &&
        (((uint32_T)(*rtu_comp_filt_tertiary_yaw_rate_qf)) != ACCURATED)))
   {
      localDW->UnitDelay_DSTATE += 0.01F;
   }
   else
   {
      localDW->UnitDelay_DSTATE = 0.0F;
   }

   /* End of Switch: '<S4>/Switch' */

   /* If: '<S1>/If' incorporates:
    *  Constant: '<S4>/Constant'
    *  Constant: '<S4>/Constant3'
    *  Logic: '<S4>/Logical Operator4'
    *  RelationalOperator: '<S4>/GreaterThan'
    *  RelationalOperator: '<S4>/GreaterThan1'
    *  UnitDelay: '<S4>/Unit Delay'
    */
   if (((localDW->UnitDelay_DSTATE > 0.0F) && (localDW->UnitDelay_DSTATE <= 120.0F)) &&
       ((!(*rtu_f_yaw_rate_stop_bias_converged_primary)) || (!(*rtu_f_yaw_rate_stop_bias_converged_secondary))))
   {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* ModelReference: '<S2>/YawRateRationalityCheckInStandstillBiasNotLearned' */
      Signal_Rationality_Check_Common(rtu_uncomp_primary_yaw_rate, rtu_uncomp_secondary_yaw_rate, rtu_uncomp_tertiary_yaw_rate,
                                      rtu_uncomp_primary_yaw_rate_qf, rtu_uncomp_secondary_yaw_rate_qf,
                                      rtu_uncomp_tertiary_yaw_rate_qf, rtu_acceptable_yaw_rate_diff_IfStandstillBiasIsNotLearned,
                                      rtu_fault_maturation_time, rtu_default_maturation_time, rtu_use_tertiary_signal,
                                      rtu_do_rationality_check, rty_yaw_rate_rationality_check_status,
                                      &(localDW->YawRateRationalityCheckInStandstillBiasNotLearned_InstanceData.rtdw));

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* ModelReference: '<S3>/YawRateRationalityCheckInNormalScenraio' */
      Signal_Rationality_Check_Common(
         rtu_comp_filt_primary_yaw_rate, rtu_comp_filt_secondary_yaw_rate, rtu_comp_filt_tertiary_yaw_rate,
         rtu_comp_filt_primary_yaw_rate_qf, rtu_comp_filt_secondary_yaw_rate_qf, rtu_comp_filt_tertiary_yaw_rate_qf,
         rtu_acceptable_yaw_rate_diff_IfStandstillBiasIsLearned, rtu_fault_maturation_time, rtu_default_maturation_time,
         rtu_use_tertiary_signal, rtu_do_rationality_check, rty_yaw_rate_rationality_check_status,
         &(localDW->YawRateRationalityCheckInNormalScenraio_InstanceData.rtdw));

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
   }

   /* End of If: '<S1>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
