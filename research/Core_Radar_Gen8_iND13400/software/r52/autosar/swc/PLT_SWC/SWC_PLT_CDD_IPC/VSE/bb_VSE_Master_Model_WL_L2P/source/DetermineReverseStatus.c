/*
 * File: DetermineReverseStatus.c
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

#include "DetermineReverseStatus.h"
#include "DetermineReverseStatus_private.h"

/* Output and update for referenced model: 'DetermineReverseStatus' */
void DetermineReverseStatus(const uint8_T *rtu_WhlRotDrctnlStLftDrvn, const uint8_T *rtu_WhlRotDrctnlStLfNDrvn,
                            const uint8_T *rtu_WhlRotDrctnlStRtDrvn, const uint8_T *rtu_WhlRotDrctnlSRtNDrvn,
                            const uint8_T *rtu_fl_wheel_pulse_counter, const uint8_T *rtu_fr_wheel_pulse_counter,
                            const uint8_T *rtu_rl_wheel_pulse_counter, const uint8_T *rtu_rr_wheel_pulse_counter,
                            const uint8_T *rtu_gear_box_pos, const enum_quality_factor_T *rtu_fl_wheel_pulse_counter_qf,
                            const enum_quality_factor_T *rtu_fr_wheel_pulse_counter_qf,
                            const enum_quality_factor_T *rtu_rl_wheel_pulse_counter_qf,
                            const enum_quality_factor_T *rtu_rr_wheel_pulse_counter_qf, boolean_T *rty_f_reverse,
                            DW_DetermineReverseStatus_f_T *localDW)
{
   boolean_T rtb_RelationalOperator3;
   boolean_T rtb_RelationalOperator1;
   boolean_T rtb_RelationalOperator2;
   boolean_T rtb_RelationalOperator4;

   /* RelationalOperator: '<S6>/Relational Operator3' incorporates:
    *  Constant: '<S6>/WHLDIR_REVERSE'
    *
    * Block description for '<S6>/Relational Operator3':
    *  _FCA1PX.DHVS.000_130_
    *
    * Block description for '<S6>/WHLDIR_REVERSE':
    *  _FCA1PX.DHVS.000_133_
    */
   rtb_RelationalOperator3 = (((int32_T)(*rtu_WhlRotDrctnlStLftDrvn)) == 2);

   /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
    *  Constant: '<S6>/WHLDIR_REVERSE1'
    *
    * Block description for '<S6>/Relational Operator1':
    *  _FCA1PX.DHVS.000_128_
    *
    * Block description for '<S6>/WHLDIR_REVERSE1':
    *  _FCA1PX.DHVS.000_134_
    */
   rtb_RelationalOperator1 = (((int32_T)(*rtu_WhlRotDrctnlStLfNDrvn)) == 2);

   /* RelationalOperator: '<S6>/Relational Operator2' incorporates:
    *  Constant: '<S6>/WHLDIR_REVERSE2'
    *
    * Block description for '<S6>/Relational Operator2':
    *  _FCA1PX.DHVS.000_129_
    *
    * Block description for '<S6>/WHLDIR_REVERSE2':
    *  _FCA1PX.DHVS.000_135_
    */
   rtb_RelationalOperator2 = (((int32_T)(*rtu_WhlRotDrctnlStRtDrvn)) == 2);

   /* RelationalOperator: '<S6>/Relational Operator4' incorporates:
    *  Constant: '<S6>/WHLDIR_REVERSE3'
    *
    * Block description for '<S6>/Relational Operator4':
    *  _FCA1PX.DHVS.000_131_
    *
    * Block description for '<S6>/WHLDIR_REVERSE3':
    *  _FCA1PX.DHVS.000_136_
    */
   rtb_RelationalOperator4 = (((int32_T)(*rtu_WhlRotDrctnlSRtNDrvn)) == 2);

   /* Switch: '<S6>/Switch'
    *
    * Block description for '<S6>/Switch':
    *  _FCA7P1.DHVS.000_26_
    */
   if (rtb_RelationalOperator2)
   {
      /* Sum: '<S6>/Add1' incorporates:
       *  RelationalOperator: '<S6>/Relational Operator7'
       *  UnitDelay: '<S6>/Unit Delay'
       *  UnitDelay: '<S6>/Unit Delay1'
       *
       * Block description for '<S6>/Add1':
       *  _FCA7P1.DHVS.000_7_
       *
       * Block description for '<S6>/Relational Operator7':
       *  _FCA7P1.DHVS.000_23_
       *
       * Block description for '<S6>/Unit Delay':
       *  _FCA7P1.DHVS.000_30_
       */
      localDW->UnitDelay1_DSTATE = (uint8_T)(((uint32_T)(((*rtu_fl_wheel_pulse_counter) != localDW->UnitDelay_DSTATE) ? 1 : 0)) +
                                             ((uint32_T)localDW->UnitDelay1_DSTATE));

      /* MinMax: '<S6>/Min' */
      if (((int32_T)localDW->UnitDelay1_DSTATE) >= 7)
      {
         /* Sum: '<S6>/Add1'
          *
          * Block description for '<S6>/Add1':
          *  _FCA7P1.DHVS.000_7_
          */
         localDW->UnitDelay1_DSTATE = 7U;
      }

      /* End of MinMax: '<S6>/Min' */
   }
   else
   {
      /* Sum: '<S6>/Add1' incorporates:
       *  Constant: '<S6>/C_ZERO'
       *  UnitDelay: '<S6>/Unit Delay1'
       *
       * Block description for '<S6>/Add1':
       *  _FCA7P1.DHVS.000_7_
       *
       * Block description for '<S6>/C_ZERO':
       *  _FCA7P1.DHVS.000_12_
       */
      localDW->UnitDelay1_DSTATE = 0U;
   }

   /* End of Switch: '<S6>/Switch' */

   /* Switch: '<S6>/Switch1'
    *
    * Block description for '<S6>/Switch1':
    *  _FCA7P1.DHVS.000_27_
    */
   if (rtb_RelationalOperator3)
   {
      /* Sum: '<S6>/Add2' incorporates:
       *  RelationalOperator: '<S6>/Relational Operator8'
       *  UnitDelay: '<S6>/Unit Delay2'
       *  UnitDelay: '<S6>/Unit Delay3'
       *
       * Block description for '<S6>/Add2':
       *  _FCA7P1.DHVS.000_8_
       *
       * Block description for '<S6>/Relational Operator8':
       *  _FCA7P1.DHVS.000_24_
       *
       * Block description for '<S6>/Unit Delay2':
       *  _FCA7P1.DHVS.000_32_
       */
      localDW->UnitDelay3_DSTATE = (uint8_T)(((uint32_T)(((*rtu_fr_wheel_pulse_counter) != localDW->UnitDelay2_DSTATE) ? 1 : 0)) +
                                             ((uint32_T)localDW->UnitDelay3_DSTATE));

      /* MinMax: '<S6>/Min1' */
      if (((int32_T)localDW->UnitDelay3_DSTATE) >= 7)
      {
         /* Sum: '<S6>/Add2'
          *
          * Block description for '<S6>/Add2':
          *  _FCA7P1.DHVS.000_8_
          */
         localDW->UnitDelay3_DSTATE = 7U;
      }

      /* End of MinMax: '<S6>/Min1' */
   }
   else
   {
      /* Sum: '<S6>/Add2' incorporates:
       *  Constant: '<S6>/C_ZERO5'
       *  UnitDelay: '<S6>/Unit Delay3'
       *
       * Block description for '<S6>/Add2':
       *  _FCA7P1.DHVS.000_8_
       *
       * Block description for '<S6>/C_ZERO5':
       *  _FCA7P1.DHVS.000_12_
       */
      localDW->UnitDelay3_DSTATE = 0U;
   }

   /* End of Switch: '<S6>/Switch1' */

   /* Switch: '<S6>/Switch2'
    *
    * Block description for '<S6>/Switch2':
    *  _FCA7P1.DHVS.000_28_
    */
   if (rtb_RelationalOperator4)
   {
      /* Sum: '<S6>/Add3' incorporates:
       *  RelationalOperator: '<S6>/Relational Operator9'
       *  UnitDelay: '<S6>/Unit Delay4'
       *  UnitDelay: '<S6>/Unit Delay5'
       *
       * Block description for '<S6>/Add3':
       *  _FCA7P1.DHVS.000_9_
       *
       * Block description for '<S6>/Relational Operator9':
       *  _FCA7P1.DHVS.000_25_
       *
       * Block description for '<S6>/Unit Delay4':
       *  _FCA7P1.DHVS.000_34_
       */
      localDW->UnitDelay5_DSTATE = (uint8_T)(((uint32_T)(((*rtu_rl_wheel_pulse_counter) != localDW->UnitDelay4_DSTATE) ? 1 : 0)) +
                                             ((uint32_T)localDW->UnitDelay5_DSTATE));

      /* MinMax: '<S6>/Min2' */
      if (((int32_T)localDW->UnitDelay5_DSTATE) >= 7)
      {
         /* Sum: '<S6>/Add3'
          *
          * Block description for '<S6>/Add3':
          *  _FCA7P1.DHVS.000_9_
          */
         localDW->UnitDelay5_DSTATE = 7U;
      }

      /* End of MinMax: '<S6>/Min2' */
   }
   else
   {
      /* Sum: '<S6>/Add3' incorporates:
       *  Constant: '<S6>/C_ZERO1'
       *  UnitDelay: '<S6>/Unit Delay5'
       *
       * Block description for '<S6>/Add3':
       *  _FCA7P1.DHVS.000_9_
       *
       * Block description for '<S6>/C_ZERO1':
       *  _FCA7P1.DHVS.000_12_
       */
      localDW->UnitDelay5_DSTATE = 0U;
   }

   /* End of Switch: '<S6>/Switch2' */

   /* Switch: '<S6>/Switch3'
    *
    * Block description for '<S6>/Switch3':
    *  _FCA7P1.DHVS.000_29_
    */
   if (rtb_RelationalOperator1)
   {
      /* Sum: '<S6>/Add4' incorporates:
       *  RelationalOperator: '<S6>/Relational Operator10'
       *  UnitDelay: '<S6>/Unit Delay6'
       *  UnitDelay: '<S6>/Unit Delay7'
       *
       * Block description for '<S6>/Add4':
       *  _FCA7P1.DHVS.000_10_
       *
       * Block description for '<S6>/Relational Operator10':
       *  _FCA7P1.DHVS.000_18_
       *
       * Block description for '<S6>/Unit Delay6':
       *  _FCA7P1.DHVS.000_36_
       */
      localDW->UnitDelay7_DSTATE = (uint8_T)(((uint32_T)(((*rtu_rr_wheel_pulse_counter) != localDW->UnitDelay6_DSTATE) ? 1 : 0)) +
                                             ((uint32_T)localDW->UnitDelay7_DSTATE));

      /* MinMax: '<S6>/Min3' */
      if (((int32_T)localDW->UnitDelay7_DSTATE) >= 7)
      {
         /* Sum: '<S6>/Add4'
          *
          * Block description for '<S6>/Add4':
          *  _FCA7P1.DHVS.000_10_
          */
         localDW->UnitDelay7_DSTATE = 7U;
      }

      /* End of MinMax: '<S6>/Min3' */
   }
   else
   {
      /* Sum: '<S6>/Add4' incorporates:
       *  Constant: '<S6>/C_ZERO2'
       *  UnitDelay: '<S6>/Unit Delay7'
       *
       * Block description for '<S6>/Add4':
       *  _FCA7P1.DHVS.000_10_
       *
       * Block description for '<S6>/C_ZERO2':
       *  _FCA7P1.DHVS.000_12_
       */
      localDW->UnitDelay7_DSTATE = 0U;
   }

   /* End of Switch: '<S6>/Switch3' */

   /* Switch: '<S1>/Switch' incorporates:
    *  Constant: '<S1>/k_BackwardWheelPulses'
    *  Constant: '<S1>/k_wheel_direction_count'
    *  Constant: '<S2>/Constant'
    *  Constant: '<S3>/Constant'
    *  Constant: '<S4>/Constant'
    *  Constant: '<S5>/Constant'
    *  Constant: '<S7>/WHLDIR_REVERSE'
    *  DataTypeConversion: '<S6>/Data Type Conversion'
    *  DataTypeConversion: '<S6>/Data Type Conversion1'
    *  DataTypeConversion: '<S6>/Data Type Conversion2'
    *  DataTypeConversion: '<S6>/Data Type Conversion3'
    *  Logic: '<S1>/AND'
    *  Logic: '<S6>/Logical Operator'
    *  Logic: '<S6>/Logical Operator2'
    *  RelationalOperator: '<S2>/Compare'
    *  RelationalOperator: '<S3>/Compare'
    *  RelationalOperator: '<S4>/Compare'
    *  RelationalOperator: '<S5>/Compare'
    *  RelationalOperator: '<S6>/Relational Operator11'
    *  RelationalOperator: '<S6>/Relational Operator12'
    *  RelationalOperator: '<S6>/Relational Operator13'
    *  RelationalOperator: '<S6>/Relational Operator14'
    *  RelationalOperator: '<S6>/Relational Operator6'
    *  RelationalOperator: '<S7>/Equal'
    *  Sum: '<S6>/Add'
    *  UnitDelay: '<S6>/Unit Delay1'
    *  UnitDelay: '<S6>/Unit Delay3'
    *  UnitDelay: '<S6>/Unit Delay5'
    *  UnitDelay: '<S6>/Unit Delay7'
    *
    * Block description for '<S7>/WHLDIR_REVERSE':
    *  _FCA1PX.DHVS.000_133_
    *
    * Block description for '<S6>/Logical Operator':
    *  _FCA1PX.DHVS.000_125_
    *
    * Block description for '<S6>/Logical Operator2':
    *  _FCA7P1.DHVS.000_16_
    *
    * Block description for '<S6>/Relational Operator11':
    *  _FCA7P1.DHVS.000_19_
    *
    * Block description for '<S6>/Relational Operator12':
    *  _FCA7P1.DHVS.000_20_
    *
    * Block description for '<S6>/Relational Operator13':
    *  _FCA7P1.DHVS.000_21_
    *
    * Block description for '<S6>/Relational Operator14':
    *  _FCA7P1.DHVS.000_22_
    *
    * Block description for '<S6>/Relational Operator6':
    *  _FCA5P0.DHVS.000_2_
    *
    * Block description for '<S6>/Add':
    *  _FCA5P0.DHVS.000_1_
    */
   if ((((((uint32_T)(*rtu_fl_wheel_pulse_counter_qf)) == ACCURATED) &&
         (((uint32_T)(*rtu_fr_wheel_pulse_counter_qf)) == ACCURATED)) &&
        (((uint32_T)(*rtu_rl_wheel_pulse_counter_qf)) == ACCURATED)) &&
       (((uint32_T)(*rtu_rr_wheel_pulse_counter_qf)) == ACCURATED))
   {
      *rty_f_reverse =
         ((((int32_T)((uint32_T)(((((uint32_T)(rtb_RelationalOperator3 ? 1U : 0U)) + (rtb_RelationalOperator1 ? 1U : 0U)) +
                                  (rtb_RelationalOperator2 ? 1U : 0U)) +
                                 (rtb_RelationalOperator4 ? 1U : 0U)))) > 1) &&
          ((((((int32_T)localDW->UnitDelay1_DSTATE) > 6) || (((int32_T)localDW->UnitDelay3_DSTATE) > 6)) ||
            (((int32_T)localDW->UnitDelay5_DSTATE) > 6)) ||
           (((int32_T)localDW->UnitDelay7_DSTATE) > 6)));
   }
   else
   {
      *rty_f_reverse = (((int32_T)(*rtu_gear_box_pos)) == 1);
   }

   /* End of Switch: '<S1>/Switch' */

   /* Update for UnitDelay: '<S6>/Unit Delay'
    *
    * Block description for '<S6>/Unit Delay':
    *  _FCA7P1.DHVS.000_30_
    */
   localDW->UnitDelay_DSTATE = *rtu_fl_wheel_pulse_counter;

   /* Update for UnitDelay: '<S6>/Unit Delay2'
    *
    * Block description for '<S6>/Unit Delay2':
    *  _FCA7P1.DHVS.000_32_
    */
   localDW->UnitDelay2_DSTATE = *rtu_fr_wheel_pulse_counter;

   /* Update for UnitDelay: '<S6>/Unit Delay4'
    *
    * Block description for '<S6>/Unit Delay4':
    *  _FCA7P1.DHVS.000_34_
    */
   localDW->UnitDelay4_DSTATE = *rtu_rl_wheel_pulse_counter;

   /* Update for UnitDelay: '<S6>/Unit Delay6'
    *
    * Block description for '<S6>/Unit Delay6':
    *  _FCA7P1.DHVS.000_36_
    */
   localDW->UnitDelay6_DSTATE = *rtu_rr_wheel_pulse_counter;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
