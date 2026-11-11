/*
 * File: Signal_Arbitration_Common.c
 *
 * Code generated for Simulink model 'Signal_Arbitration_Common'.
 *
 * Model version                  : 1.197
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:33 2026
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

#include "Signal_Arbitration_Common.h"
#include "Signal_Arbitration_Common_private.h"

/* Named constants for Chart: '<S1>/Initial_Arbitration_Chart' */
#define Signal_Arbitration_Common_IN_PRIORITY_1                ((uint8_T)1U)
#define Signal_Arbitration_Common_IN_PRIORITY_2                ((uint8_T)2U)
#define Signal_Arbitration_Common_IN_PRIORITY_3                ((uint8_T)3U)
#define Signal_Arbitration_Common_sig_arbit_sampling_time_msec ((uint8_T)10U)

/*
 * Output and update for action system:
 *    '<S2>/If Action Subsystem1'
 *    '<S2>/If Action Subsystem2'
 *    '<S2>/If Action Subsystem3'
 */
void Signal_Arbitration_Common_IfActionSubsystem1(const real32_T *rtu_In1, const enum_quality_factor_T *rtu_In1_d,
                                                  selected_signal_number_T rtu_In1_f, real32_T *rty_Out1,
                                                  enum_quality_factor_T *rty_Out1_d, selected_signal_number_T *rty_Out1_f)
{
   /* SignalConversion: '<S4>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1 = *rtu_In1;

   /* SignalConversion: '<S4>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_d = *rtu_In1_d;

   /* SignalConversion: '<S4>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_f = rtu_In1_f;
}

/* System initialize for referenced model: 'Signal_Arbitration_Common' */
void Signal_Arbitration_Common_Init(selected_signal_number_T *rty_selected_signal_number)
{
   /* SystemInitialize for Merge: '<S2>/Merge' */
   *rty_selected_signal_number = PRIMARY;
}

/* Output and update for referenced model: 'Signal_Arbitration_Common' */
void Signal_Arbitration_Common(const real32_T *rtu_signal_priority_1, const real32_T *rtu_signal_priority_2,
                               const real32_T *rtu_signal_priority_3, const enum_quality_factor_T *rtu_signal_priority_1_qf,
                               const enum_quality_factor_T *rtu_signal_priority_2_qf,
                               const enum_quality_factor_T *rtu_signal_priority_3_qf, real32_T *rty_selected_signal,
                               enum_quality_factor_T *rty_selected_signal_qf, selected_signal_number_T *rty_selected_signal_number,
                               DW_Signal_Arbitration_Common_f_T *localDW)
{
   real32_T rtb_selected_signal;
   enum_quality_factor_T rtb_selected_signal_qf;
   selected_signal_number_T rtb_selected_signal_number;
   int32_T tmp;
   boolean_T guard1 = false;

   /* Chart: '<S1>/Initial_Arbitration_Chart' */
   if (((uint32_T)localDW->bitsForTID0.is_active_c1_Signal_Arbitration_Common) == 0U)
   {
      localDW->bitsForTID0.is_active_c1_Signal_Arbitration_Common = 1;
      localDW->bitsForTID0.is_c1_Signal_Arbitration_Common        = Signal_Arbitration_Common_IN_PRIORITY_1;
      rtb_selected_signal                                         = *rtu_signal_priority_1;
      rtb_selected_signal_qf                                      = *rtu_signal_priority_1_qf;
      rtb_selected_signal_number                                  = PRIMARY;
      localDW->priority_1_counter_msec                            = 0U;
   }
   else
   {
      guard1 = false;
      switch (localDW->bitsForTID0.is_c1_Signal_Arbitration_Common)
      {
         case Signal_Arbitration_Common_IN_PRIORITY_1:
            if ((((*rtu_signal_priority_2_qf) > (*rtu_signal_priority_1_qf)) &&
                 ((*rtu_signal_priority_2_qf) >= (*rtu_signal_priority_3_qf))) &&
                (((int32_T)localDW->priority_1_counter_msec) > 50))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_2;
               rtb_selected_signal                                  = *rtu_signal_priority_2;
               rtb_selected_signal_qf                               = *rtu_signal_priority_2_qf;
               rtb_selected_signal_number                           = SECONDARY;
               localDW->priority_2_counter_msec                     = 0U;
            }
            else if ((((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_3_qf)) &&
                      ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_2_qf))) &&
                     (((int32_T)localDW->priority_1_counter_msec) > 50))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_1;
               rtb_selected_signal                                  = *rtu_signal_priority_1;
               rtb_selected_signal_qf                               = *rtu_signal_priority_1_qf;
               rtb_selected_signal_number                           = PRIMARY;
               localDW->priority_1_counter_msec                     = 0U;
            }
            else if ((((*rtu_signal_priority_3_qf) > (*rtu_signal_priority_1_qf)) &&
                      ((*rtu_signal_priority_3_qf) > (*rtu_signal_priority_2_qf))) &&
                     (((int32_T)localDW->priority_1_counter_msec) > 50))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_3;
               rtb_selected_signal                                  = *rtu_signal_priority_3;
               rtb_selected_signal_qf                               = *rtu_signal_priority_3_qf;
               rtb_selected_signal_number                           = TERTIARY;
               localDW->priority_3_counter_msec                     = 0U;
            }
            else
            {
               rtb_selected_signal        = *rtu_signal_priority_1;
               rtb_selected_signal_qf     = *rtu_signal_priority_1_qf;
               rtb_selected_signal_number = PRIMARY;
               if (((uint32_T)(*rtu_signal_priority_1_qf)) != ACCURATED)
               {
                  tmp = (int32_T)((uint32_T)(((uint32_T)localDW->priority_1_counter_msec) +
                                             Signal_Arbitration_Common_sig_arbit_sampling_time_msec));
                  if (((uint32_T)tmp) > 255U)
                  {
                     tmp = 255;
                  }

                  localDW->priority_1_counter_msec = (uint8_T)tmp;
               }
            }
            break;

         case Signal_Arbitration_Common_IN_PRIORITY_2:
            if (((((uint32_T)(*rtu_signal_priority_2_qf)) == ACCURATED) &&
                 (((uint32_T)(*rtu_signal_priority_1_qf)) == ACCURATED)) ||
                (((((int32_T)localDW->priority_2_counter_msec) > 50) &&
                  ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_2_qf))) &&
                 ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_3_qf))))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_1;
               rtb_selected_signal                                  = *rtu_signal_priority_1;
               rtb_selected_signal_qf                               = *rtu_signal_priority_1_qf;
               rtb_selected_signal_number                           = PRIMARY;
               localDW->priority_1_counter_msec                     = 0U;
            }
            else if ((((*rtu_signal_priority_2_qf) >= (*rtu_signal_priority_3_qf)) &&
                      ((*rtu_signal_priority_2_qf) > (*rtu_signal_priority_1_qf))) &&
                     (((int32_T)localDW->priority_2_counter_msec) > 50))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_2;
               rtb_selected_signal                                  = *rtu_signal_priority_2;
               rtb_selected_signal_qf                               = *rtu_signal_priority_2_qf;
               rtb_selected_signal_number                           = SECONDARY;
               localDW->priority_2_counter_msec                     = 0U;
            }
            else if ((((*rtu_signal_priority_3_qf) > (*rtu_signal_priority_2_qf)) &&
                      ((*rtu_signal_priority_3_qf) > (*rtu_signal_priority_1_qf))) &&
                     (((int32_T)localDW->priority_2_counter_msec) > 50))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_3;
               rtb_selected_signal                                  = *rtu_signal_priority_3;
               rtb_selected_signal_qf                               = *rtu_signal_priority_3_qf;
               rtb_selected_signal_number                           = TERTIARY;
               localDW->priority_3_counter_msec                     = 0U;
            }
            else
            {
               rtb_selected_signal        = *rtu_signal_priority_2;
               rtb_selected_signal_qf     = *rtu_signal_priority_2_qf;
               rtb_selected_signal_number = SECONDARY;
               if (((uint32_T)(*rtu_signal_priority_2_qf)) != ACCURATED)
               {
                  tmp = (int32_T)((uint32_T)(((uint32_T)localDW->priority_2_counter_msec) +
                                             Signal_Arbitration_Common_sig_arbit_sampling_time_msec));
                  if (((uint32_T)tmp) > 255U)
                  {
                     tmp = 255;
                  }

                  localDW->priority_2_counter_msec = (uint8_T)tmp;
               }
            }
            break;

         default:
            if ((((((int32_T)localDW->priority_3_counter_msec) > 50) &&
                  ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_3_qf))) &&
                 ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_2_qf))) ||
                ((((uint32_T)(*rtu_signal_priority_3_qf)) == ACCURATED) && (((uint32_T)(*rtu_signal_priority_1_qf)) == ACCURATED)))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_1;
               rtb_selected_signal                                  = *rtu_signal_priority_1;
               rtb_selected_signal_qf                               = *rtu_signal_priority_1_qf;
               rtb_selected_signal_number                           = PRIMARY;
               localDW->priority_1_counter_msec                     = 0U;
            }
            else if ((((*rtu_signal_priority_2_qf) > (*rtu_signal_priority_1_qf)) &&
                      (((int32_T)localDW->priority_3_counter_msec) > 50)) &&
                     ((*rtu_signal_priority_2_qf) >= (*rtu_signal_priority_3_qf)))
            {
               guard1 = true;
            }
            else if ((((*rtu_signal_priority_3_qf) > (*rtu_signal_priority_2_qf)) &&
                      ((*rtu_signal_priority_3_qf) > (*rtu_signal_priority_1_qf))) &&
                     (((int32_T)localDW->priority_3_counter_msec) > 50))
            {
               localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_3;
               rtb_selected_signal                                  = *rtu_signal_priority_3;
               rtb_selected_signal_qf                               = *rtu_signal_priority_3_qf;
               rtb_selected_signal_number                           = TERTIARY;
               localDW->priority_3_counter_msec                     = 0U;
            }
            else if (((((uint32_T)(*rtu_signal_priority_1_qf)) != ACCURATED) &&
                      (((uint32_T)(*rtu_signal_priority_3_qf)) == ACCURATED)) &&
                     (((uint32_T)(*rtu_signal_priority_2_qf)) == ACCURATED))
            {
               guard1 = true;
            }
            else
            {
               rtb_selected_signal        = *rtu_signal_priority_3;
               rtb_selected_signal_qf     = *rtu_signal_priority_3_qf;
               rtb_selected_signal_number = TERTIARY;
               if (((uint32_T)(*rtu_signal_priority_3_qf)) != ACCURATED)
               {
                  tmp = (int32_T)((uint32_T)(((uint32_T)localDW->priority_3_counter_msec) +
                                             Signal_Arbitration_Common_sig_arbit_sampling_time_msec));
                  if (((uint32_T)tmp) > 255U)
                  {
                     tmp = 255;
                  }

                  localDW->priority_3_counter_msec = (uint8_T)tmp;
               }
            }
            break;
      }

      if (guard1)
      {
         localDW->bitsForTID0.is_c1_Signal_Arbitration_Common = Signal_Arbitration_Common_IN_PRIORITY_2;
         rtb_selected_signal                                  = *rtu_signal_priority_2;
         rtb_selected_signal_qf                               = *rtu_signal_priority_2_qf;
         rtb_selected_signal_number                           = SECONDARY;
         localDW->priority_2_counter_msec                     = 0U;
      }
   }

   /* End of Chart: '<S1>/Initial_Arbitration_Chart' */

   /* If: '<S2>/If' incorporates:
    *  Constant: '<S2>/Constant'
    *  Constant: '<S2>/Constant1'
    *  Constant: '<S2>/Constant2'
    *  DataTypeConversion: '<S2>/Cast To Single3'
    */
   if ((((int32_T)rtb_selected_signal_qf) != 0) ||
       (((((int32_T)(*rtu_signal_priority_1_qf)) == 0) && (((int32_T)(*rtu_signal_priority_2_qf)) == 0)) &&
        (((int32_T)(*rtu_signal_priority_3_qf)) == 0)))
   {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* SignalConversion: '<S7>/BusConversion_InsertedFor_Out1_at_inport_0' */
      *rty_selected_signal = rtb_selected_signal;

      /* SignalConversion: '<S7>/BusConversion_InsertedFor_Out1_at_inport_0' */
      *rty_selected_signal_qf = rtb_selected_signal_qf;

      /* SignalConversion: '<S7>/BusConversion_InsertedFor_Out1_at_inport_0' */
      *rty_selected_signal_number = rtb_selected_signal_number;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
   }
   else if (((0 == ((int32_T)(*rtu_signal_priority_2_qf))) && ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_3_qf))) ||
            ((0 == ((int32_T)(*rtu_signal_priority_3_qf))) && ((*rtu_signal_priority_1_qf) >= (*rtu_signal_priority_2_qf))))
   {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      Signal_Arbitration_Common_IfActionSubsystem1(rtu_signal_priority_1, rtu_signal_priority_1_qf, PRIMARY, rty_selected_signal,
                                                   rty_selected_signal_qf, rty_selected_signal_number);

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
   }
   else if (((0 == ((int32_T)(*rtu_signal_priority_1_qf))) && ((*rtu_signal_priority_2_qf) >= (*rtu_signal_priority_3_qf))) ||
            ((0 == ((int32_T)(*rtu_signal_priority_3_qf))) && ((*rtu_signal_priority_1_qf) < (*rtu_signal_priority_2_qf))))
   {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      Signal_Arbitration_Common_IfActionSubsystem1(rtu_signal_priority_2, rtu_signal_priority_2_qf, SECONDARY, rty_selected_signal,
                                                   rty_selected_signal_qf, rty_selected_signal_number);

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
   }
   else
   {
      if (((0 == ((int32_T)(*rtu_signal_priority_1_qf))) && ((*rtu_signal_priority_2_qf) < (*rtu_signal_priority_3_qf))) ||
          ((0 == ((int32_T)(*rtu_signal_priority_2_qf))) && ((*rtu_signal_priority_1_qf) < (*rtu_signal_priority_3_qf))))
      {
         /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
          *  ActionPort: '<S6>/Action Port'
          */
         Signal_Arbitration_Common_IfActionSubsystem1(rtu_signal_priority_3, rtu_signal_priority_3_qf, TERTIARY,
                                                      rty_selected_signal, rty_selected_signal_qf, rty_selected_signal_number);

         /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
      }
   }

   /* End of If: '<S2>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
