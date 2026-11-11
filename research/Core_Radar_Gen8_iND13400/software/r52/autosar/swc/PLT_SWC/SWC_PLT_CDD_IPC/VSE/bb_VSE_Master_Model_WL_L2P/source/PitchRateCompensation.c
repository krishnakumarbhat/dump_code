/*
 * File: PitchRateCompensation.c
 *
 * Code generated for Simulink model 'PitchRateCompensation'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:19 2026
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

#include "PitchRateCompensation.h"
#include "PitchRateCompensation_private.h"

/* Output and update for referenced model: 'PitchRateCompensation' */
void PitchRateCompensation(const real32_T *rtu_raw_pitch_rate_rps, const enum_quality_factor_T *rtu_raw_pitch_rate_qf,
                           const boolean_T *rtu_f_stationary, real32_T *rty_pitch_rate_bias,
                           real32_T *rty_comp_pitch_rate_unfiltered, real32_T *rty_comp_pitch_rate_filtered,
                           enum_quality_factor_T *rty_comp_pitch_rate_qf, boolean_T *rty_f_stop_pitchrate_bias_converged,
                           DW_PitchRateCompensation_f_T *localDW)
{
   boolean_T rtb_f_imu_signal_bias_saturated;
   real32_T rtb_Add_f;

   /* Sum: '<S3>/Subtract' incorporates:
    *  Delay: '<S3>/Delay4'
    */
   *rty_comp_pitch_rate_unfiltered = (*rtu_raw_pitch_rate_rps) - localDW->Delay4_DSTATE;

   /* Sum: '<S4>/Add' incorporates:
    *  Delay: '<S1>/Delay'
    *  Product: '<S4>/Multiply'
    *  Product: '<S4>/Multiply1'
    */
   *rty_comp_pitch_rate_filtered = ((*rty_comp_pitch_rate_unfiltered) * 0.166666657F) + (localDW->Delay_DSTATE * 0.833333373F);

   /* If: '<S3>/If' incorporates:
    *  Constant: '<S7>/Constant'
    *  Delay: '<S3>/Delay1'
    *  Delay: '<S3>/Delay3'
    *  Delay: '<S3>/Delay7'
    *  Inport: '<S5>/f_roll_rate_bias_saturated_prev'
    *  Inport: '<S5>/f_stop_rollrate_bias_converged_prev'
    *  Inport: '<S5>/roll_rate_bias_prev'
    *  RelationalOperator: '<S7>/Compare'
    */
   if (((uint32_T)(*rtu_raw_pitch_rate_qf)) == ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S3>/CalculateBias' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* If: '<S6>/If' incorporates:
       *  Delay: '<S3>/Delay2'
       */
      if (localDW->bitsForTID0.Delay2_DSTATE)
      {
         /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
          *  ActionPort: '<S8>/Action Port'
          */
         /* Sum: '<S14>/Add' incorporates:
          *  Constant: '<S14>/Constant'
          *  Delay: '<S6>/Delay'
          *  Delay: '<S6>/Delay1'
          *  Product: '<S14>/Multiply'
          *  Product: '<S14>/Multiply1'
          *  Sum: '<S14>/Subtract'
          */
         localDW->Delay1_DSTATE = ((*rty_comp_pitch_rate_unfiltered) * 0.0123456791F) + (localDW->Delay_DSTATE_g * 0.987654328F);

         /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
      }
      else
      {
         /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
          *  ActionPort: '<S9>/Action Port'
          */
         /* Sum: '<S15>/Add' incorporates:
          *  Constant: '<S15>/Constant'
          *  Delay: '<S6>/Delay1'
          *  Product: '<S15>/Multiply'
          *  Product: '<S15>/Multiply1'
          *  Sum: '<S15>/Subtract'
          */
         localDW->Delay1_DSTATE = ((*rty_comp_pitch_rate_unfiltered) * 0.0909090862F) + (localDW->Delay1_DSTATE * 0.909090936F);

         /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
      }

      /* End of If: '<S6>/If' */

      /* If: '<S6>/If1' incorporates:
       *  Constant: '<S6>/Constant'
       *  Delay: '<S3>/Delay2'
       *  Delay: '<S6>/Delay1'
       *  Inport: '<S13>/f_stop_imu_signal_bias_converged_prev'
       */
      if (!(*rtu_f_stationary))
      {
         /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem5' incorporates:
          *  ActionPort: '<S13>/Action Port'
          */
         /* Logic: '<S13>/Logical Operator' incorporates:
          *  Constant: '<S23>/Constant'
          *  Constant: '<S24>/Constant'
          *  Delay: '<S3>/Delay5'
          *  RelationalOperator: '<S23>/Compare'
          *  RelationalOperator: '<S24>/Compare'
          */
         rtb_f_imu_signal_bias_saturated = ((localDW->Delay5_DSTATE > 0.0610865243F) || (localDW->Delay5_DSTATE < -0.0610865243F));

         /* Saturate: '<S13>/Saturation' incorporates:
          *  Delay: '<S3>/Delay5'
          */
         if (localDW->Delay5_DSTATE > 0.0610865243F)
         {
            *rty_pitch_rate_bias = 0.0610865243F;
         }
         else if (localDW->Delay5_DSTATE < -0.0610865243F)
         {
            *rty_pitch_rate_bias = -0.0610865243F;
         }
         else
         {
            *rty_pitch_rate_bias = localDW->Delay5_DSTATE;
         }

         /* End of Saturate: '<S13>/Saturation' */
         *rty_f_stop_pitchrate_bias_converged = localDW->bitsForTID0.Delay2_DSTATE;

         /* End of Outputs for SubSystem: '<S6>/If Action Subsystem5' */
      }
      else if (localDW->Delay1_DSTATE > 0.00174532924F)
      {
         /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
          *  ActionPort: '<S10>/Action Port'
          */
         /* Logic: '<S10>/Logical Operator' incorporates:
          *  Constant: '<S16>/Constant'
          *  Constant: '<S17>/Constant'
          *  Constant: '<S6>/Constant1'
          *  Delay: '<S3>/Delay5'
          *  RelationalOperator: '<S16>/Compare'
          *  RelationalOperator: '<S17>/Compare'
          *  Sum: '<S10>/Add'
          */
         rtb_f_imu_signal_bias_saturated = (((localDW->Delay5_DSTATE + 0.000872664619F) > 0.0610865243F) ||
                                            ((localDW->Delay5_DSTATE + 0.000872664619F) < -0.0610865243F));

         /* Saturate: '<S10>/Saturation' incorporates:
          *  Constant: '<S6>/Constant1'
          *  Delay: '<S3>/Delay5'
          *  Sum: '<S10>/Add'
          */
         if ((localDW->Delay5_DSTATE + 0.000872664619F) > 0.0610865243F)
         {
            *rty_pitch_rate_bias = 0.0610865243F;
         }
         else if ((localDW->Delay5_DSTATE + 0.000872664619F) < -0.0610865243F)
         {
            *rty_pitch_rate_bias = -0.0610865243F;
         }
         else
         {
            *rty_pitch_rate_bias = localDW->Delay5_DSTATE + 0.000872664619F;
         }

         /* End of Saturate: '<S10>/Saturation' */

         /* SignalConversion: '<S10>/OutportBuffer_InsertedFor_f_stop_imu_signal_bias_converged_at_inport_0' incorporates:
          *  Constant: '<S10>/Constant'
          */
         *rty_f_stop_pitchrate_bias_converged = false;

         /* End of Outputs for SubSystem: '<S6>/If Action Subsystem2' */
      }
      else if (localDW->Delay1_DSTATE < -0.00174532924F)
      {
         /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
          *  ActionPort: '<S11>/Action Port'
          */
         /* Logic: '<S11>/Logical Operator' incorporates:
          *  Constant: '<S18>/Constant'
          *  Constant: '<S19>/Constant'
          *  Constant: '<S6>/Constant2'
          *  Delay: '<S3>/Delay5'
          *  RelationalOperator: '<S18>/Compare'
          *  RelationalOperator: '<S19>/Compare'
          *  Sum: '<S11>/Add'
          */
         rtb_f_imu_signal_bias_saturated = (((localDW->Delay5_DSTATE - 0.000872664619F) > 0.0610865243F) ||
                                            ((localDW->Delay5_DSTATE - 0.000872664619F) < -0.0610865243F));

         /* Saturate: '<S11>/Saturation' incorporates:
          *  Constant: '<S6>/Constant2'
          *  Delay: '<S3>/Delay5'
          *  Sum: '<S11>/Add'
          */
         if ((localDW->Delay5_DSTATE - 0.000872664619F) > 0.0610865243F)
         {
            *rty_pitch_rate_bias = 0.0610865243F;
         }
         else if ((localDW->Delay5_DSTATE - 0.000872664619F) < -0.0610865243F)
         {
            *rty_pitch_rate_bias = -0.0610865243F;
         }
         else
         {
            *rty_pitch_rate_bias = localDW->Delay5_DSTATE - 0.000872664619F;
         }

         /* End of Saturate: '<S11>/Saturation' */

         /* SignalConversion: '<S11>/OutportBuffer_InsertedFor_f_stop_imu_signal_bias_converged_at_inport_0' incorporates:
          *  Constant: '<S11>/Constant'
          */
         *rty_f_stop_pitchrate_bias_converged = false;

         /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
      }
      else
      {
         /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
          *  ActionPort: '<S12>/Action Port'
          */
         /* Sum: '<S22>/Add' incorporates:
          *  Constant: '<S22>/Constant'
          *  Delay: '<S3>/Delay5'
          *  Product: '<S22>/Multiply'
          *  Product: '<S22>/Multiply1'
          *  Sum: '<S22>/Subtract'
          */
         rtb_Add_f = ((*rtu_raw_pitch_rate_rps) * 0.00199600775F) + (localDW->Delay5_DSTATE * 0.998004F);

         /* Logic: '<S12>/Logical Operator' incorporates:
          *  Constant: '<S20>/Constant'
          *  Constant: '<S21>/Constant'
          *  RelationalOperator: '<S20>/Compare'
          *  RelationalOperator: '<S21>/Compare'
          */
         rtb_f_imu_signal_bias_saturated = ((rtb_Add_f > 0.0610865243F) || (rtb_Add_f < -0.0610865243F));

         /* Saturate: '<S12>/Saturation' */
         if (rtb_Add_f > 0.0610865243F)
         {
            *rty_pitch_rate_bias = 0.0610865243F;
         }
         else if (rtb_Add_f < -0.0610865243F)
         {
            *rty_pitch_rate_bias = -0.0610865243F;
         }
         else
         {
            *rty_pitch_rate_bias = rtb_Add_f;
         }

         /* End of Saturate: '<S12>/Saturation' */

         /* SignalConversion: '<S12>/OutportBuffer_InsertedFor_f_stop_imu_signal_bias_converged_at_inport_0' incorporates:
          *  Constant: '<S12>/Constant2'
          */
         *rty_f_stop_pitchrate_bias_converged = true;

         /* End of Outputs for SubSystem: '<S6>/If Action Subsystem4' */
      }

      /* End of If: '<S6>/If1' */

      /* Update for Delay: '<S6>/Delay' incorporates:
       *  Delay: '<S6>/Delay1'
       */
      localDW->Delay_DSTATE_g = localDW->Delay1_DSTATE;

      /* End of Outputs for SubSystem: '<S3>/CalculateBias' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S3>/By-pass previous values' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      *rty_pitch_rate_bias                 = localDW->Delay3_DSTATE;
      rtb_f_imu_signal_bias_saturated      = localDW->bitsForTID0.Delay7_DSTATE;
      *rty_f_stop_pitchrate_bias_converged = localDW->bitsForTID0.Delay1_DSTATE_o;

      /* End of Outputs for SubSystem: '<S3>/By-pass previous values' */
   }

   /* End of If: '<S3>/If' */

   /* Switch: '<S1>/Switch1' incorporates:
    *  Constant: '<S1>/Constant2'
    *  Constant: '<S2>/Constant'
    *  Logic: '<S1>/Logical Operator'
    *  RelationalOperator: '<S2>/Compare'
    */
   if (rtb_f_imu_signal_bias_saturated && (((uint32_T)(*rtu_raw_pitch_rate_qf)) == ACCURATED))
   {
      *rty_comp_pitch_rate_qf = NOT_ACCURATED;
   }
   else
   {
      *rty_comp_pitch_rate_qf = *rtu_raw_pitch_rate_qf;
   }

   /* End of Switch: '<S1>/Switch1' */

   /* Update for Delay: '<S3>/Delay4' */
   localDW->Delay4_DSTATE = *rty_pitch_rate_bias;

   /* Update for Delay: '<S1>/Delay' */
   localDW->Delay_DSTATE = *rty_comp_pitch_rate_filtered;

   /* Update for Delay: '<S3>/Delay5' */
   localDW->Delay5_DSTATE = *rty_pitch_rate_bias;

   /* Update for Delay: '<S3>/Delay2' */
   localDW->bitsForTID0.Delay2_DSTATE = *rty_f_stop_pitchrate_bias_converged;

   /* Update for Delay: '<S3>/Delay3' */
   localDW->Delay3_DSTATE = *rty_pitch_rate_bias;

   /* Update for Delay: '<S3>/Delay7' */
   localDW->bitsForTID0.Delay7_DSTATE = rtb_f_imu_signal_bias_saturated;

   /* Update for Delay: '<S3>/Delay1' */
   localDW->bitsForTID0.Delay1_DSTATE_o = *rty_f_stop_pitchrate_bias_converged;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
