/*
 * File: VehicleMassEstimator_2018b.c
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

#include "VehicleMassEstimator_2018b.h"
#include "VehicleMassEstimator_2018b_private.h"

/* Named constants for Chart: '<S2>/Timer1' */
#define VehicleMassEstimator_2018b_IN_Init  ((uint8_T)1U)
#define VehicleMassEstimator_2018b_IN_Timer ((uint8_T)2U)
#define VehicleMassEstimator_2018b_IN_Valid ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Timer' */
#define VehicleMassEstimator_2018b_IN_Init1           ((uint8_T)1U)
#define VehicleMassEstimator_2018b_IN_Timer_Running   ((uint8_T)2U)
#define VehicleMassEstimator_2018b_IN_Timer_suspended ((uint8_T)3U)

/*
 * Output and update for atomic system:
 *    '<S8>/IIR_Filter'
 *    '<S9>/IIR_Filter'
 *    '<S11>/IIR_Filter'
 *    '<S12>/IIR_Filter'
 *    '<S13>/IIR_Filter'
 *    '<S14>/IIR_Filter'
 */
void VehicleMassEstimator_2018b_IIR_Filter(const real32_T *rtu_iir_input, real32_T *rty_iir_output,
                                           DW_IIR_Filter_VehicleMassEstimator_2018b_T *localDW)
{
   real32_T y;
   y               = ((*rtu_iir_input) * 0.00280792266F) + localDW->zi[0];
   localDW->zi[0]  = ((0.00842376798F * (*rtu_iir_input)) + localDW->zi[1]) - (-2.38124824F * y);
   localDW->zi[1]  = ((0.00842376798F * (*rtu_iir_input)) + localDW->zi[2]) - (1.93969858F * y);
   localDW->zi[2]  = ((0.00280792266F * (*rtu_iir_input)) + localDW->zi[3]) - (-0.535987F * y);
   localDW->zi[3]  = localDW->zi[4];
   localDW->zi[4]  = localDW->zi[5];
   localDW->zi[5]  = localDW->zi[6];
   localDW->zi[6]  = localDW->zi[7];
   localDW->zi[7]  = 0.0F;
   *rty_iir_output = y;
}

/*
 * Output and update for atomic system:
 *    '<S10>/IIR_Filter'
 *    '<S15>/IIR_Filter'
 */
void VehicleMassEstimator_2018b_IIR_Filter_a(real32_T rtu_iir_input, real32_T *rty_iir_output,
                                             DW_IIR_Filter_VehicleMassEstimator_2018b_b_T *localDW)
{
   real32_T y;
   y               = (rtu_iir_input * 0.00280792266F) + localDW->zi[0];
   localDW->zi[0]  = ((0.00842376798F * rtu_iir_input) + localDW->zi[1]) - (-2.38124824F * y);
   localDW->zi[1]  = ((0.00842376798F * rtu_iir_input) + localDW->zi[2]) - (1.93969858F * y);
   localDW->zi[2]  = ((0.00280792266F * rtu_iir_input) + localDW->zi[3]) - (-0.535987F * y);
   localDW->zi[3]  = localDW->zi[4];
   localDW->zi[4]  = localDW->zi[5];
   localDW->zi[5]  = localDW->zi[6];
   localDW->zi[6]  = localDW->zi[7];
   localDW->zi[7]  = 0.0F;
   *rty_iir_output = y;
}

/* Output and update for referenced model: 'VehicleMassEstimator_2018b' */
void VehicleMassEstimator_2018b(
   const real32_T *rtu_VsVCAN_Nm_Trailer_AxleTrq, const real32_T *rtu_filt_veh_speed_over_ground,
   const real32_T *rtu_wheel_running_radius, const real32_T *rtu_VsVCAN_Nm_BrkTrq, const real32_T *rtu_comp_long_accel,
   const real32_T *rtu_comp_yaw_rate_filtered, const real32_T *rtu_GearReductionRatio, const real32_T *rtu_wheel_rpm_front_right,
   const real32_T *rtu_wheel_rpm_front_left, const real32_T *rtu_VsVCAN_Trailer_ITBM_Power,
   const enum_Presence_Status *rtu_VeVSE_TrlrDetectSts, const uint8_T *rtu_CmdIgnSts, const boolean_T *rtu_CANNode95_ITBM,
   const boolean_T *rtu_f_stationary, const uint8_T *rtu_Brk_Stat, real32_T *rty_VsVSE_Kg_TrlrMass,
   boolean_T *rty_VsVSE_b_TrlrMassConvSts, real32_T *rty_VsVSE_s_TrlrMassCalcTimer, real32_T *rty_VsVSE_TrlrTotalCount,
   real32_T *rty_VsVSE_TrlrCountAccel, real32_T *rty_VsVSE_TrlrCountBrake, real32_T *rty_VsVSE_TrlrRunningAvgAccel,
   real32_T *rty_VsVSE_TrlrRunningAvgBrake, real32_T *rty_VsVSE_TrlrMassConvPercent, boolean_T *rty_VsVSE_b_ResetFlag,
   real32_T *rty_VsVSE_EstMassRunningAvg, DW_VehicleMassEstimator_2018b_f_T *localDW)
{
   boolean_T rtb_NotReset;
   real32_T rtb_iir_output_d;
   real32_T rtb_iir_output_fl;
   real32_T rtb_iir_output;
   real32_T rtb_iir_output_k;
   real32_T rtb_iir_output_l;
   real32_T rtb_iir_output_f;
   real32_T rtb_iir_output_dg;
   real32_T rtb_iir_output_c;
   real_T rtb_forgetting_factor;

   /* MATLAB Function: '<S10>/IIR_Filter' incorporates:
    *  Gain: '<Root>/Gain'
    *  Gain: '<Root>/Gain11'
    *  Gain: '<Root>/Gain7'
    *  Gain: '<Root>/Gain8'
    *  Sum: '<Root>/Add1'
    */
   VehicleMassEstimator_2018b_IIR_Filter_a(
      0.0166666675F * (0.5F * ((6.28318548F * (*rtu_wheel_rpm_front_right)) + (6.28318548F * (*rtu_wheel_rpm_front_left)))),
      &rtb_iir_output_d, &localDW->sf_IIR_Filter_a);

   /* Logic: '<S2>/AND' incorporates:
    *  Logic: '<S2>/NOT'
    */
   rtb_NotReset = !(*rtu_CANNode95_ITBM);

   /* Logic: '<S2>/OR' incorporates:
    *  Constant: '<S19>/Constant'
    *  Constant: '<S20>/Constant'
    *  Constant: '<S2>/RUN'
    *  Logic: '<S2>/AND'
    *  Logic: '<S6>/OR'
    *  RelationalOperator: '<S19>/Compare'
    *  RelationalOperator: '<S20>/Compare'
    *  RelationalOperator: '<S2>/Equal'
    */
   *rty_VsVSE_b_ResetFlag = ((rtb_NotReset || (rtb_NotReset || ((((uint32_T)(*rtu_VeVSE_TrlrDetectSts)) != Both_Connected) &&
                                                                (((uint32_T)(*rtu_VeVSE_TrlrDetectSts)) != HW_Connected_Only)))) ||
                             (((int32_T)(*rtu_CmdIgnSts)) != 4));

   /* MATLAB Function: '<S8>/IIR_Filter' */
   VehicleMassEstimator_2018b_IIR_Filter(rtu_VsVCAN_Nm_Trailer_AxleTrq, &rtb_iir_output_c, &localDW->sf_IIR_Filter);

   /* MATLAB Function: '<S9>/IIR_Filter' */
   VehicleMassEstimator_2018b_IIR_Filter(rtu_VsVCAN_Nm_BrkTrq, &rtb_iir_output_fl, &localDW->sf_IIR_Filter_l);

   /* MATLAB Function: '<S11>/IIR_Filter' */
   VehicleMassEstimator_2018b_IIR_Filter(rtu_comp_yaw_rate_filtered, &rtb_iir_output_f, &localDW->sf_IIR_Filter_aq);

   /* MATLAB Function: '<S12>/IIR_Filter' */
   VehicleMassEstimator_2018b_IIR_Filter(rtu_filt_veh_speed_over_ground, &rtb_iir_output_k, &localDW->sf_IIR_Filter_m);

   /* MATLAB Function: '<S13>/IIR_Filter' */
   VehicleMassEstimator_2018b_IIR_Filter(rtu_comp_long_accel, &rtb_iir_output_l, &localDW->sf_IIR_Filter_n);

   /* MATLAB Function: '<S14>/IIR_Filter' */
   VehicleMassEstimator_2018b_IIR_Filter(rtu_VsVCAN_Trailer_ITBM_Power, &rtb_iir_output_dg, &localDW->sf_IIR_Filter_h);

   /* MATLAB Function: '<S15>/IIR_Filter' incorporates:
    *  Gain: '<Root>/Gain10'
    */
   VehicleMassEstimator_2018b_IIR_Filter_a(0.159154937F * (*rtu_GearReductionRatio), &rtb_iir_output, &localDW->sf_IIR_Filter_no);

   /* MATLAB Function: '<Root>/MassEstimation_newCalc' */
   if ((!localDW->bitsForTID0.prev_angular_wheel_speed_not_empty) || (*rty_VsVSE_b_ResetFlag))
   {
      localDW->prev_angular_wheel_speed                       = rtb_iir_output_d;
      localDW->bitsForTID0.prev_angular_wheel_speed_not_empty = true;
      localDW->avg_mass_acc                                   = 5500.0F;
      localDW->avg_mass_brk                                   = 5500.0F;
      localDW->accel_count                                    = 0.0F;
      localDW->brake_count                                    = 0.0F;
      localDW->bitsForTID0.converge_flag                      = false;
      localDW->acc_filt_debounce                              = 0.0F;
      localDW->brake_filt_debounce                            = 0.0F;
      localDW->Percent_Convergence                            = 0.0F;
   }

   rtb_iir_output_fl += (3000.0F * rtb_iir_output_dg) / 100.0F;
   rtb_iir_output_c = (rtb_iir_output_c / 2.15F) - (rtb_iir_output_fl * 0.75F);
   if (rtb_iir_output == 0.0F)
   {
      rtb_iir_output = ((rtb_iir_output_d * rtb_iir_output_d) * 0.005F) + 0.6F;
   }
   else
   {
      rtb_iir_output = (((rtb_iir_output_d * rtb_iir_output_d) * 0.005F) + 0.6F) + (0.15F / (rtb_iir_output * rtb_iir_output));
   }

   rtb_iir_output_dg = fabsf(rtb_iir_output_l);
   if (((rtb_iir_output_dg > 0.25F) && (rtb_iir_output_k > 2.8F)) &&
       (((real_T)((real32_T)(rtb_iir_output_f / rtb_iir_output_k))) < 0.001))
   {
      if (((rtb_iir_output_l > 0.0F) && (rtb_iir_output_c > 100.0F)) && (((int32_T)(*rtu_Brk_Stat)) == 0))
      {
         localDW->acc_filt_debounce += 0.01F;
         localDW->brake_filt_debounce = 0.0F;
      }
      else if (((rtb_iir_output_l < 0.0F) && (rtb_iir_output_fl > 100.0F)) && (rtb_iir_output_c < -100.0F))
      {
         localDW->acc_filt_debounce = 0.0F;
         localDW->brake_filt_debounce += 0.01F;
      }
      else
      {
         localDW->acc_filt_debounce   = 0.0F;
         localDW->brake_filt_debounce = 0.0F;
      }
   }
   else
   {
      localDW->acc_filt_debounce   = 0.0F;
      localDW->brake_filt_debounce = 0.0F;
   }

   real32_T denom       = rtb_iir_output_l * (*rtu_wheel_running_radius);
   real32_T accel_count = localDW->accel_count + 1.0F;
   if ((rtb_iir_output_dg > 0.25F) && (((real_T)localDW->acc_filt_debounce) > 0.3) && (fabsf(denom) > 1.0e-6F) &&
       (accel_count > 0.0F))
   {
      localDW->accel_count = accel_count;
      localDW->avg_mass_acc =
         ((((rtb_iir_output_c - (((rtb_iir_output_d - localDW->prev_angular_wheel_speed) / 0.01F) * rtb_iir_output)) * 0.93F) /
           (denom)) +
          ((accel_count - 1.0F) * localDW->avg_mass_acc)) /
         accel_count;
   }

   rtb_iir_output_f = localDW->accel_count + localDW->brake_count;
   if (rtb_iir_output_f > 0.0F)
   {
      rtb_iir_output_k =
         ((localDW->accel_count * localDW->avg_mass_acc) + (localDW->brake_count * localDW->avg_mass_brk)) / rtb_iir_output_f;
   }
   else
   {
      rtb_iir_output_k = 5500.0F;
   }

   if (rtb_iir_output_k > 19000.0F)
   {
      rtb_iir_output_k = 19000.0F;
   }
   else
   {
      if (rtb_iir_output_k < 275.0F)
      {
         rtb_iir_output_k = 275.0F;
      }
   }

   if ((rtb_iir_output_f >= 4000.0F) && (!localDW->bitsForTID0.converge_flag))
   {
      localDW->bitsForTID0.converge_flag = true;
   }

   if ((!localDW->bitsForTID0.converge_flag) && (localDW->Percent_Convergence < 100.0F))
   {
      localDW->Percent_Convergence = (rtb_iir_output_f / 4000.0F) * 100.0F;
   }
   else
   {
      localDW->Percent_Convergence = 100.0F;
   }

   *rty_VsVSE_TrlrMassConvPercent    = localDW->Percent_Convergence;
   *rty_VsVSE_TrlrRunningAvgAccel    = localDW->avg_mass_acc;
   *rty_VsVSE_TrlrRunningAvgBrake    = localDW->avg_mass_brk;
   *rty_VsVSE_EstMassRunningAvg      = rtb_iir_output_k;
   *rty_VsVSE_TrlrCountBrake         = localDW->brake_count;
   *rty_VsVSE_TrlrCountAccel         = localDW->accel_count;
   localDW->prev_angular_wheel_speed = rtb_iir_output_d;
   *rty_VsVSE_TrlrTotalCount         = rtb_iir_output_f;

   /* MATLAB Function: '<Root>/forgettingfactorcalc' incorporates:
    *  MATLAB Function: '<Root>/MassEstimation_newCalc'
    */
   if (!localDW->bitsForTID0.converge_flag)
   {
      rtb_forgetting_factor = 0.9999;
   }
   else
   {
      rtb_forgetting_factor = 0.1;
   }

   /* End of MATLAB Function: '<Root>/forgettingfactorcalc' */

   /* MATLAB Function: '<S4>/exponential_moving_average' incorporates:
    *  MATLAB Function: '<Root>/MassEstimation_newCalc'
    */
   if (!localDW->bitsForTID0.initialized_not_empty)
   {
      localDW->yprev                             = rtb_iir_output_k;
      localDW->bitsForTID0.initialized_not_empty = true;
   }

   localDW->yprev =
      ((1.0F - ((real32_T)rtb_forgetting_factor)) * rtb_iir_output_k) + (((real32_T)rtb_forgetting_factor) * localDW->yprev);

   /* Switch: '<Root>/Switch' incorporates:
    *  Constant: '<Root>/DefaultMass'
    *  MATLAB Function: '<Root>/MassEstimation_newCalc'
    *  MATLAB Function: '<S4>/exponential_moving_average'
    */
   if (localDW->bitsForTID0.converge_flag)
   {
      rtb_iir_output_d = localDW->yprev;
   }
   else
   {
      rtb_iir_output_d = 5500.0F;
   }

   /* End of Switch: '<Root>/Switch' */

   /* MATLAB Function: '<S3>/Rate_Limiter' */
   if (!localDW->bitsForTID0.x_not_empty)
   {
      localDW->x                       = rtb_iir_output_d;
      localDW->bitsForTID0.x_not_empty = true;
   }

   rtb_iir_output_d -= localDW->x;
   if (rtb_iir_output_d > 1.0F)
   {
      rtb_iir_output_d = 1.0F;
   }
   else
   {
      if (rtb_iir_output_d < -1.0F)
      {
         rtb_iir_output_d = -1.0F;
      }
   }

   localDW->x += rtb_iir_output_d;

   /* End of MATLAB Function: '<S3>/Rate_Limiter' */

   /* Switch: '<Root>/Switch2' */
   *rty_VsVSE_Kg_TrlrMass = localDW->x;

   /* Switch: '<Root>/Switch1' incorporates:
    *  MATLAB Function: '<Root>/MassEstimation_newCalc'
    */
   *rty_VsVSE_b_TrlrMassConvSts = localDW->bitsForTID0.converge_flag;

   /* Chart: '<S2>/Timer1' incorporates:
    *  Constant: '<S2>/Constant2'
    */
   if (((uint32_T)localDW->bitsForTID0.is_active_c1_VehicleMassEstimator_2018b) == 0U)
   {
      localDW->bitsForTID0.is_active_c1_VehicleMassEstimator_2018b = 1;
      localDW->bitsForTID0.is_c1_VehicleMassEstimator_2018b        = VehicleMassEstimator_2018b_IN_Init;
      localDW->i                                                   = 0.0F;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c1_VehicleMassEstimator_2018b)
      {
         case VehicleMassEstimator_2018b_IN_Init:
            if (*rtu_f_stationary)
            {
               localDW->bitsForTID0.is_c1_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Timer;
               localDW->i += 0.01F;
            }
            else
            {
               localDW->i = 0.0F;
            }
            break;

         case VehicleMassEstimator_2018b_IN_Timer:
            if (!(*rtu_f_stationary))
            {
               localDW->bitsForTID0.is_c1_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Init;
               localDW->i                                            = 0.0F;
            }
            else if (localDW->i >= 120.0F)
            {
               localDW->bitsForTID0.is_c1_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Valid;
            }
            else
            {
               localDW->i += 0.01F;
            }
            break;

         default:
            if (!(*rtu_f_stationary))
            {
               localDW->bitsForTID0.is_c1_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Init;
               localDW->i                                            = 0.0F;
            }
            break;
      }
   }

   /* End of Chart: '<S2>/Timer1' */

   /* Logic: '<Root>/NOT1' */
   rtb_NotReset = !(*rty_VsVSE_b_ResetFlag);

   /* Chart: '<Root>/Timer' incorporates:
    *  MATLAB Function: '<Root>/MassEstimation_newCalc'
    */
   if (((uint32_T)localDW->bitsForTID0.is_active_c5_VehicleMassEstimator_2018b) == 0U)
   {
      localDW->bitsForTID0.is_active_c5_VehicleMassEstimator_2018b = 1;
      localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b        = VehicleMassEstimator_2018b_IN_Init1;
      *rty_VsVSE_s_TrlrMassCalcTimer                               = 0.0F;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b)
      {
         case VehicleMassEstimator_2018b_IN_Init1:
            if (localDW->bitsForTID0.converge_flag)
            {
               localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Timer_suspended;
            }
            else
            {
               if (((*rtu_filt_veh_speed_over_ground) > 2.8F) && rtb_NotReset)
               {
                  localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Timer_Running;
                  *rty_VsVSE_s_TrlrMassCalcTimer += 0.01F;
               }
            }
            break;

         case VehicleMassEstimator_2018b_IN_Timer_Running:
            if (!rtb_NotReset)
            {
               localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Init1;
               *rty_VsVSE_s_TrlrMassCalcTimer                        = 0.0F;
            }
            else if (((*rtu_filt_veh_speed_over_ground) < 2.8F) || (localDW->bitsForTID0.converge_flag))
            {
               localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Timer_suspended;
            }
            else
            {
               *rty_VsVSE_s_TrlrMassCalcTimer += 0.01F;
            }
            break;

         default:
            if (((*rtu_filt_veh_speed_over_ground) >= 2.8F) && (!localDW->bitsForTID0.converge_flag))
            {
               localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Timer_Running;
               *rty_VsVSE_s_TrlrMassCalcTimer += 0.01F;
            }
            else
            {
               if (!rtb_NotReset)
               {
                  localDW->bitsForTID0.is_c5_VehicleMassEstimator_2018b = VehicleMassEstimator_2018b_IN_Init1;
                  *rty_VsVSE_s_TrlrMassCalcTimer                        = 0.0F;
               }
            }
            break;
      }
   }

   /* End of Chart: '<Root>/Timer' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
