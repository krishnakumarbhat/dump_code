/*
 * File: Signal_Rationality_Check_Common.c
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

#include "Signal_Rationality_Check_Common.h"
#include "Signal_Rationality_Check_Common_private.h"

/* Output and update for referenced model: 'Signal_Rationality_Check_Common' */
void Signal_Rationality_Check_Common(const real32_T *rtu_signal_priority_1, const real32_T *rtu_signal_priority_2,
                                     const real32_T *rtu_signal_priority_3, const enum_quality_factor_T *rtu_signal_priority_1_qf,
                                     const enum_quality_factor_T *rtu_signal_priority_2_qf,
                                     const enum_quality_factor_T *rtu_signal_priority_3_qf,
                                     const real32_T *rtu_k_acceptable_absolute_difference,
                                     const real32_T *rtu_fault_maturation_time, const real32_T *rtu_fault_dematuration_time,
                                     const boolean_T *rtu_f_use_tertiary_signal, const boolean_T *rtu_f_do_rationality_check,
                                     boolean_T *rty_f_rationality_check_passed, DW_Signal_Rationality_Check_Common_f_T *localDW)
{
   boolean_T rtb_LogicalOperator;
   boolean_T rtb_LogicalOperator1;
   boolean_T tmp;

   /* Logic: '<S1>/Logical Operator' incorporates:
    *  Constant: '<S2>/Constant'
    *  Constant: '<S3>/Constant'
    *  Logic: '<S1>/Logical Operator2'
    *  RelationalOperator: '<S2>/Compare'
    *  RelationalOperator: '<S3>/Compare'
    */
   rtb_LogicalOperator =
      (((((uint32_T)(*rtu_signal_priority_1_qf)) == ACCURATED) && (((uint32_T)(*rtu_signal_priority_2_qf)) == ACCURATED)) &&
       (!(*rtu_f_use_tertiary_signal)));

   /* Outputs for Enabled SubSystem: '<S1>/CompareTwoSignals' incorporates:
    *  EnablePort: '<S8>/Enable'
    */
   if (rtb_LogicalOperator)
   {
      /* RelationalOperator: '<S8>/GreaterThan' incorporates:
       *  Abs: '<S8>/Abs'
       *  Sum: '<S8>/Subtract'
       */
      localDW->bitsForTID0.GreaterThan =
         (fabsf((*rtu_signal_priority_1) - (*rtu_signal_priority_2)) <= (*rtu_k_acceptable_absolute_difference));
   }

   /* End of Outputs for SubSystem: '<S1>/CompareTwoSignals' */

   /* Logic: '<S1>/Logical Operator1' incorporates:
    *  Constant: '<S4>/Constant'
    *  Constant: '<S5>/Constant'
    *  Constant: '<S6>/Constant'
    *  RelationalOperator: '<S4>/Compare'
    *  RelationalOperator: '<S5>/Compare'
    *  RelationalOperator: '<S6>/Compare'
    */
   rtb_LogicalOperator1 =
      ((((((uint32_T)(*rtu_signal_priority_1_qf)) == ACCURATED) && (((uint32_T)(*rtu_signal_priority_2_qf)) == ACCURATED)) &&
        (((uint32_T)(*rtu_signal_priority_3_qf)) == ACCURATED)) &&
       (*rtu_f_use_tertiary_signal));

   /* Outputs for Enabled SubSystem: '<S1>/CompareThreeSignals' incorporates:
    *  EnablePort: '<S7>/Enable'
    */
   if (rtb_LogicalOperator1)
   {
      /* Logic: '<S7>/Logical Operator' incorporates:
       *  Abs: '<S7>/Abs'
       *  Abs: '<S7>/Abs1'
       *  Abs: '<S7>/Abs2'
       *  RelationalOperator: '<S7>/GreaterThan'
       *  RelationalOperator: '<S7>/GreaterThan1'
       *  RelationalOperator: '<S7>/GreaterThan2'
       *  Sum: '<S7>/Subtract'
       *  Sum: '<S7>/Subtract1'
       *  Sum: '<S7>/Subtract2'
       */
      localDW->bitsForTID0.LogicalOperator =
         (((fabsf((*rtu_signal_priority_1) - (*rtu_signal_priority_2)) <= (*rtu_k_acceptable_absolute_difference)) &&
           (fabsf((*rtu_signal_priority_2) - (*rtu_signal_priority_3)) <= (*rtu_k_acceptable_absolute_difference))) &&
          (fabsf((*rtu_signal_priority_1) - (*rtu_signal_priority_3)) <= (*rtu_k_acceptable_absolute_difference)));
   }

   /* End of Outputs for SubSystem: '<S1>/CompareThreeSignals' */

   /* Switch: '<S1>/Switch' */
   if (*rtu_f_do_rationality_check)
   {
      /* Logic: '<S1>/Logical Operator6' incorporates:
       *  Logic: '<S1>/Logical Operator3'
       *  Logic: '<S1>/Logical Operator4'
       *  Logic: '<S1>/Logical Operator5'
       */
      rtb_LogicalOperator = (((!rtb_LogicalOperator) || (!localDW->bitsForTID0.GreaterThan)) &&
                             ((!rtb_LogicalOperator1) || (!localDW->bitsForTID0.LogicalOperator)));
   }
   else
   {
      /* Logic: '<S1>/Logical Operator6' */
      rtb_LogicalOperator = false;
   }

   /* End of Switch: '<S1>/Switch' */

   /* MATLAB Function: '<S9>/MATLAB Function' */
   rtb_LogicalOperator1 = !localDW->bitsForTID0.prev_final_fault_flag;
   if (rtb_LogicalOperator && rtb_LogicalOperator1)
   {
      localDW->matured_time += 0.01F;
   }
   else
   {
      if (!rtb_LogicalOperator)
      {
         localDW->matured_time = 0.0F;
      }
   }

   tmp = !rtb_LogicalOperator;
   if (tmp && (localDW->bitsForTID0.prev_final_fault_flag))
   {
      localDW->dematured_time += 0.01F;
   }
   else
   {
      if (!localDW->bitsForTID0.prev_final_fault_flag)
      {
         localDW->dematured_time = 0.0F;
      }
   }

   rtb_LogicalOperator =
      (((rtb_LogicalOperator && rtb_LogicalOperator1) && (localDW->matured_time >= (*rtu_fault_maturation_time))) ||
       ((tmp || (localDW->bitsForTID0.prev_final_fault_flag)) &&
        (((rtb_LogicalOperator || rtb_LogicalOperator1) || (localDW->dematured_time < (*rtu_fault_dematuration_time))) &&
         ((tmp && (localDW->bitsForTID0.prev_final_fault_flag)) || rtb_LogicalOperator))));
   localDW->bitsForTID0.prev_final_fault_flag = rtb_LogicalOperator;

   /* End of MATLAB Function: '<S9>/MATLAB Function' */

   /* Logic: '<S1>/Logical Operator7' */
   *rty_f_rationality_check_passed = !rtb_LogicalOperator;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
