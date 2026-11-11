/*
 * File: Wheel_Counts_To_Linear_Speed.c
 *
 * Code generated for Simulink model 'Wheel_Counts_To_Linear_Speed'.
 *
 * Model version                  : 1.1218
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:07:34 2026
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

#include "Wheel_Counts_To_Linear_Speed.h"
#include "Wheel_Counts_To_Linear_Speed_private.h"

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function'
 *    '<S2>/MATLAB Function'
 *    '<S3>/MATLAB Function'
 *    '<S4>/MATLAB Function'
 */
void Wheel_Counts_To_Linear_Speed_MATLABFunction(const uint8_T *rtu_pres_whl_count, uint8_T rtu_prev_whl_count,
                                                 uint8_T *rty_wheel_ticks)
{
   uint32_T qY;
   int32_T tmp;
   if ((*rtu_pres_whl_count) >= rtu_prev_whl_count)
   {
      qY = ((uint32_T)(*rtu_pres_whl_count)) - /*MW:OvSatOk*/ ((uint32_T)rtu_prev_whl_count);
      if (qY > ((uint32_T)(*rtu_pres_whl_count)))
      {
         qY = 0U;
      }

      *rty_wheel_ticks = (uint8_T)qY;
   }
   else
   {
      qY = 254U - /*MW:OvSatOk*/ ((uint32_T)rtu_prev_whl_count);
      if (qY > 254U)
      {
         qY = 0U;
      }

      tmp = (int32_T)((uint32_T)((((uint32_T)(*rtu_pres_whl_count)) + qY) + 1U));
      if (((uint32_T)tmp) > 255U)
      {
         tmp = 255;
      }

      *rty_wheel_ticks = (uint8_T)tmp;
   }
}

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function1'
 *    '<S2>/MATLAB Function1'
 *    '<S3>/MATLAB Function1'
 *    '<S4>/MATLAB Function1'
 */
void Wheel_Counts_To_Linear_Speed_MATLABFunction1(real32_T rtu_whl_tck_bsd_lin_spd, uint8_T rtu_HasScndTckEncountered_u8,
                                                  real32_T rtu_inst_whl_tck_bsd_lin_spd,
                                                  real32_T *rty_combined_whl_tck_bsd_lin_spd)
{
   if (((int32_T)rtu_HasScndTckEncountered_u8) == 0)
   {
      *rty_combined_whl_tck_bsd_lin_spd = rtu_inst_whl_tck_bsd_lin_spd;
   }
   else
   {
      *rty_combined_whl_tck_bsd_lin_spd = rtu_whl_tck_bsd_lin_spd;
   }
}

/*
 * Output and update for atomic system:
 *    '<S7>/MATLAB Function'
 *    '<S18>/MATLAB Function'
 *    '<S29>/MATLAB Function'
 *    '<S40>/MATLAB Function'
 */
void Wheel_Counts_To_Linear_Speed_MATLABFunction_i(uint8_T rtu_wheel_ticks, const real32_T *rtu_whl_radius_m,
                                                   const real32_T *rtu_CPR, const real32_T *rtu_last_estimated_spd,
                                                   const real32_T *rtu_last_differen_estimated_spd, const uint64_T *rtu_curr_time,
                                                   real32_T rtu_delta_time, uint8_T rtu_IsFirstPulseEncountered_in,
                                                   real32_T rtu_pred_lin_spd_in, uint64_T rtu_time_in,
                                                   uint32_T rtu_counter_20cyc_in, uint8_T rtu_wheel_tck_count_in,
                                                   uint8_T rtu_SecondPlsEncountered_in, uint8_T *rty_IsFirstPulseEncountered,
                                                   real32_T *rty_pred_lin_spd, uint64_T *rty_time_out, uint32_T *rty_counter_20cyc,
                                                   uint8_T *rty_wheel_tck_count, uint8_T *rty_SecondPlsEncountered_out)
{
   uint32_T qY;
   int32_T rtu_last_estimated_spd_0;
   *rty_IsFirstPulseEncountered  = rtu_IsFirstPulseEncountered_in;
   *rty_pred_lin_spd             = rtu_pred_lin_spd_in;
   *rty_time_out                 = rtu_time_in;
   *rty_counter_20cyc            = rtu_counter_20cyc_in;
   *rty_wheel_tck_count          = rtu_wheel_tck_count_in;
   *rty_SecondPlsEncountered_out = rtu_SecondPlsEncountered_in;
   if ((((int32_T)rtu_wheel_ticks) > 0) && (((int32_T)rtu_IsFirstPulseEncountered_in) == 0))
   {
      *rty_IsFirstPulseEncountered  = 1U;
      *rty_time_out                 = *rtu_curr_time;
      *rty_pred_lin_spd             = 0.0F;
      *rty_counter_20cyc            = 0U;
      *rty_SecondPlsEncountered_out = 0U;
   }
   else if ((((int32_T)rtu_wheel_ticks) > 0) && (rtu_delta_time > 0.0F))
   {
      if (((real_T)rtu_delta_time) >= 0.005)
      {
         rtu_last_estimated_spd_0 = (int32_T)((uint32_T)(((uint32_T)rtu_wheel_ticks) + ((uint32_T)rtu_wheel_tck_count_in)));
         if (((uint32_T)rtu_last_estimated_spd_0) > 255U)
         {
            rtu_last_estimated_spd_0 = 255;
         }

         *rty_pred_lin_spd =
            (((((real32_T)rtu_last_estimated_spd_0) * 2.0F) * 3.14159274F) * (*rtu_whl_radius_m)) / (rtu_delta_time * (*rtu_CPR));
         *rty_wheel_tck_count = 0U;
         *rty_time_out        = *rtu_curr_time;
      }
      else
      {
         rtu_last_estimated_spd_0 = (int32_T)((uint32_T)(((uint32_T)rtu_wheel_tck_count_in) + ((uint32_T)rtu_wheel_ticks)));
         if (((uint32_T)rtu_last_estimated_spd_0) > 255U)
         {
            rtu_last_estimated_spd_0 = 255;
         }

         *rty_wheel_tck_count = (uint8_T)rtu_last_estimated_spd_0;
      }

      *rty_counter_20cyc            = 0U;
      *rty_SecondPlsEncountered_out = 1U;
   }
   else
   {
      if (((int32_T)rtu_IsFirstPulseEncountered_in) == 0)
      {
         *rty_pred_lin_spd = 0.0F;
      }
   }

   if (((int32_T)rtu_wheel_ticks) == 0)
   {
      qY = rtu_counter_20cyc_in + /*MW:OvSatOk*/ 1U;
      if (qY < rtu_counter_20cyc_in)
      {
         qY = MAX_uint32_T;
      }

      *rty_counter_20cyc = qY;
      if ((*rtu_last_estimated_spd) <= 0.08F)
      {
         if (fabsf(*rtu_last_differen_estimated_spd) < 0.1F)
         {
            rtu_last_estimated_spd_0 = 30;
         }
         else
         {
            rtu_last_estimated_spd_0 = 20;
         }
      }
      else
      {
         rtu_last_estimated_spd_0 = 20;
      }

      if (qY > ((uint32_T)rtu_last_estimated_spd_0))
      {
         *rty_pred_lin_spd             = 0.0F;
         *rty_IsFirstPulseEncountered  = 0U;
         *rty_wheel_tck_count          = 0U;
         *rty_SecondPlsEncountered_out = 0U;
      }
   }
}

/*
 * Output and update for atomic system:
 *    '<S8>/MATLAB Function'
 *    '<S19>/MATLAB Function'
 *    '<S30>/MATLAB Function'
 *    '<S41>/MATLAB Function'
 */
void Wheel_Counts_To_Linear_Speed_MATLABFunction_l(uint8_T rtu_wheel_ticks, real32_T rtu_delta_time,
                                                   const real32_T *rtu_whl_radius_m, const real32_T *rtu_CPR,
                                                   real32_T rtu_pred_lin_spd_in, real32_T *rty_pred_lin_spd)
{
   *rty_pred_lin_spd = rtu_pred_lin_spd_in;
   if (rtu_delta_time > 0.0F)
   {
      *rty_pred_lin_spd =
         (((((real32_T)rtu_wheel_ticks) * 2.0F) * 3.14159274F) * (*rtu_whl_radius_m)) / (rtu_delta_time * (*rtu_CPR));
   }
}

/*
 * Output and update for enable system:
 *    '<S13>/Initialization'
 *    '<S24>/Initialization'
 *    '<S35>/Initialization'
 *    '<S46>/Initialization'
 */
void Wheel_Counts_To_Linear_Speed_Initialization(uint8_T rtu_Enable, real32_T rty_filt_num[3], real32_T rty_filt_den[3])
{
   /* Outputs for Enabled SubSystem: '<S13>/Initialization' incorporates:
    *  EnablePort: '<S14>/Enable'
    */
   if (((int32_T)rtu_Enable) > 0)
   {
      /* MATLAB Function: '<S14>/MATLAB Function' */
      rty_filt_num[0] = 0.00134871202F;
      rty_filt_den[0] = 1.0F;
      rty_filt_num[1] = 0.00269742403F;
      rty_filt_den[1] = -1.89346409F;
      rty_filt_num[2] = 0.00134871202F;
      rty_filt_den[2] = 0.898858964F;
   }

   /* End of Outputs for SubSystem: '<S13>/Initialization' */
}

/* System initialize for referenced model: 'Wheel_Counts_To_Linear_Speed' */
void Wheel_Counts_To_Linear_Speed_Init(DW_Wheel_Counts_To_Linear_Speed_f_T *localDW)
{
   /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
   localDW->UnitDelay_DSTATE_p = 1U;

   /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
   localDW->UnitDelay_DSTATE_fz = 1U;

   /* InitializeConditions for UnitDelay: '<S35>/Unit Delay' */
   localDW->UnitDelay_DSTATE_b = 1U;

   /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
   localDW->UnitDelay_DSTATE_ku = 1U;

   /* InitializeConditions for Delay: '<S4>/Resettable Delay' */
   localDW->icLoad = 1U;

   /* InitializeConditions for Delay: '<S45>/Resettable Delay' */
   localDW->icLoad_a = 1U;

   /* InitializeConditions for DiscreteFilter: '<S46>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad = 1U;

   /* InitializeConditions for Delay: '<S1>/Resettable Delay' */
   localDW->icLoad_j = 1U;

   /* InitializeConditions for Delay: '<S2>/Resettable Delay' */
   localDW->icLoad_k = 1U;

   /* InitializeConditions for Delay: '<S3>/Resettable Delay' */
   localDW->icLoad_g = 1U;

   /* InitializeConditions for Delay: '<S34>/Resettable Delay' */
   localDW->icLoad_e = 1U;

   /* InitializeConditions for DiscreteFilter: '<S35>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad_o = 1U;

   /* InitializeConditions for Delay: '<S23>/Resettable Delay' */
   localDW->icLoad_n = 1U;

   /* InitializeConditions for DiscreteFilter: '<S24>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad_d = 1U;

   /* InitializeConditions for Delay: '<S12>/Resettable Delay' */
   localDW->icLoad_eq = 1U;

   /* InitializeConditions for DiscreteFilter: '<S13>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad_a = 1U;
}

/* Output and update for referenced model: 'Wheel_Counts_To_Linear_Speed' */
void Wheel_Counts_To_Linear_Speed(const uint8_T *rtu_VsVCAN_nu_WheelCount_FL, const uint8_T *rtu_VsVCAN_nu_WheelCount_FR,
                                  const uint8_T *rtu_VsVCAN_nu_WheelCount_RL, const uint8_T *rtu_VsVCAN_nu_WheelCount_RR,
                                  const real32_T *rtu_KsVSE_m_WheelRadius, const uint64_T *rtu_VsVCAN_us_SysTimer,
                                  const real32_T *rtu_VsVCAN_nu_CountsPerRevol, const real32_T *rtu_VsVSE_mps_LastEstimWhlSpd,
                                  const real32_T *rtu_VsVSE_mps2_LastDifferentiatedWhlSpd, real32_T *rty_whl_tck_bsd_lin_spd_fl,
                                  real32_T *rty_whl_tck_bsd_lin_spd_fr, real32_T *rty_whl_tck_bsd_lin_spd_rl,
                                  real32_T *rty_whl_tck_bsd_lin_spd_rr, boolean_T *rty_WhlTckIsZeroForLongerDuration,
                                  DW_Wheel_Counts_To_Linear_Speed_f_T *localDW)
{
   uint8_T rtb_wheel_ticks_c;
   uint8_T rtb_wheel_ticks;

   /* Outputs for Enabled SubSystem: '<S13>/Initialization' */
   /* Switch: '<S13>/Switch' incorporates:
    *  UnitDelay: '<S13>/Unit Delay'
    */
   Wheel_Counts_To_Linear_Speed_Initialization((uint8_T)((((int32_T)localDW->UnitDelay_DSTATE_p) != 0) ? 1 : 0),
                                               localDW->filter_num_h, localDW->filter_den_p);

   /* End of Outputs for SubSystem: '<S13>/Initialization' */

   /* Outputs for Enabled SubSystem: '<S24>/Initialization' */
   /* Switch: '<S24>/Switch' incorporates:
    *  UnitDelay: '<S24>/Unit Delay'
    */
   Wheel_Counts_To_Linear_Speed_Initialization((uint8_T)((((int32_T)localDW->UnitDelay_DSTATE_fz) != 0) ? 1 : 0),
                                               localDW->filter_num_n, localDW->filter_den_b);

   /* End of Outputs for SubSystem: '<S24>/Initialization' */

   /* Outputs for Enabled SubSystem: '<S35>/Initialization' */
   /* Switch: '<S35>/Switch' incorporates:
    *  UnitDelay: '<S35>/Unit Delay'
    */
   Wheel_Counts_To_Linear_Speed_Initialization((uint8_T)((((int32_T)localDW->UnitDelay_DSTATE_b) != 0) ? 1 : 0),
                                               localDW->filter_num_f, localDW->filter_den_e);

   /* End of Outputs for SubSystem: '<S35>/Initialization' */

   /* Outputs for Enabled SubSystem: '<S46>/Initialization' */
   /* Switch: '<S46>/Switch' incorporates:
    *  UnitDelay: '<S46>/Unit Delay'
    */
   Wheel_Counts_To_Linear_Speed_Initialization((uint8_T)((((int32_T)localDW->UnitDelay_DSTATE_ku) != 0) ? 1 : 0),
                                               localDW->filter_num, localDW->filter_den);

   /* End of Outputs for SubSystem: '<S46>/Initialization' */

   /* Delay: '<S4>/Resettable Delay' */
   if (((int32_T)localDW->icLoad) != 0)
   {
      localDW->ResettableDelay_DSTATE_n = *rtu_VsVCAN_nu_WheelCount_RR;
   }

   /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
    *  Delay: '<S4>/Resettable Delay'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction(rtu_VsVCAN_nu_WheelCount_RR, localDW->ResettableDelay_DSTATE_n,
                                               &localDW->UnitDelay_DSTATE_ku);

   /* Delay: '<S45>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_a) != 0)
   {
      localDW->ResettableDelay_DSTATE = *rtu_VsVCAN_us_SysTimer;
   }

   /* MATLAB Function: '<S41>/MATLAB Function' incorporates:
    *  Constant: '<S45>/Constant'
    *  DataTypeConversion: '<S45>/Data Type Conversion'
    *  Delay: '<S45>/Resettable Delay'
    *  Product: '<S45>/Multiply'
    *  Sum: '<S45>/Add1'
    *  UnitDelay: '<S41>/Unit Delay2'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_l(
      localDW->UnitDelay_DSTATE_ku,
      ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->ResettableDelay_DSTATE))) * 1.0E-6F, rtu_KsVSE_m_WheelRadius,
      rtu_VsVCAN_nu_CountsPerRevol, localDW->UnitDelay2_DSTATE, &localDW->UnitDelay2_DSTATE);

   /* DiscreteFilter: '<S46>/Discrete Filter' incorporates:
    *  UnitDelay: '<S41>/Unit Delay2'
    */
   if (((int32_T)localDW->DiscreteFilter_icLoad) != 0)
   {
      localDW->DiscreteFilter_states[0] = localDW->UnitDelay2_DSTATE;
      localDW->DiscreteFilter_states[1] = localDW->UnitDelay2_DSTATE;
      localDW->DiscreteFilter_icLoad    = 0U;
   }

   localDW->DiscreteFilter_tmp = (localDW->UnitDelay2_DSTATE - (localDW->filter_den[1] * localDW->DiscreteFilter_states[0])) -
                                 (localDW->filter_den[2] * localDW->DiscreteFilter_states[1]);

   /* MATLAB Function: '<S40>/MATLAB Function' incorporates:
    *  Constant: '<S43>/Constant'
    *  DataTypeConversion: '<S43>/Data Type Conversion'
    *  Product: '<S43>/Multiply'
    *  Sum: '<S43>/Add'
    *  UnitDelay: '<S40>/Unit Delay'
    *  UnitDelay: '<S40>/Unit Delay1'
    *  UnitDelay: '<S40>/Unit Delay2'
    *  UnitDelay: '<S40>/Unit Delay3'
    *  UnitDelay: '<S40>/Unit Delay4'
    *  UnitDelay: '<S40>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_i(
      localDW->UnitDelay_DSTATE_ku, rtu_KsVSE_m_WheelRadius, rtu_VsVCAN_nu_CountsPerRevol, rtu_VsVSE_mps_LastEstimWhlSpd,
      rtu_VsVSE_mps2_LastDifferentiatedWhlSpd, rtu_VsVCAN_us_SysTimer,
      ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->UnitDelay1_DSTATE))) * 1.0E-6F, localDW->UnitDelay3_DSTATE,
      localDW->UnitDelay2_DSTATE_c, localDW->UnitDelay1_DSTATE, localDW->UnitDelay_DSTATE, localDW->UnitDelay4_DSTATE,
      localDW->UnitDelay5_DSTATE, &localDW->UnitDelay3_DSTATE, &localDW->UnitDelay2_DSTATE_c, &localDW->UnitDelay1_DSTATE,
      &localDW->UnitDelay_DSTATE, &localDW->UnitDelay4_DSTATE, &localDW->UnitDelay5_DSTATE);

   /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
    *  DiscreteFilter: '<S46>/Discrete Filter'
    *  UnitDelay: '<S40>/Unit Delay2'
    *  UnitDelay: '<S40>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction1(
      localDW->UnitDelay2_DSTATE_c, localDW->UnitDelay5_DSTATE,
      ((localDW->filter_num[0] * localDW->DiscreteFilter_tmp) + (localDW->filter_num[1] * localDW->DiscreteFilter_states[0])) +
         (localDW->filter_num[2] * localDW->DiscreteFilter_states[1]),
      rty_whl_tck_bsd_lin_spd_rr);

   /* Delay: '<S1>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_j) != 0)
   {
      localDW->ResettableDelay_DSTATE_i = *rtu_VsVCAN_nu_WheelCount_FL;
   }

   /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
    *  Delay: '<S1>/Resettable Delay'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction(rtu_VsVCAN_nu_WheelCount_FL, localDW->ResettableDelay_DSTATE_i, &rtb_wheel_ticks_c);

   /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
    *  Constant: '<S10>/Constant'
    *  DataTypeConversion: '<S10>/Data Type Conversion'
    *  Product: '<S10>/Multiply'
    *  Sum: '<S10>/Add'
    *  UnitDelay: '<S7>/Unit Delay'
    *  UnitDelay: '<S7>/Unit Delay1'
    *  UnitDelay: '<S7>/Unit Delay2'
    *  UnitDelay: '<S7>/Unit Delay3'
    *  UnitDelay: '<S7>/Unit Delay4'
    *  UnitDelay: '<S7>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_i(
      rtb_wheel_ticks_c, rtu_KsVSE_m_WheelRadius, rtu_VsVCAN_nu_CountsPerRevol, rtu_VsVSE_mps_LastEstimWhlSpd,
      rtu_VsVSE_mps2_LastDifferentiatedWhlSpd, rtu_VsVCAN_us_SysTimer,
      ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->UnitDelay1_DSTATE_o))) * 1.0E-6F, localDW->UnitDelay3_DSTATE_m,
      localDW->UnitDelay2_DSTATE_f, localDW->UnitDelay1_DSTATE_o, localDW->UnitDelay_DSTATE_a, localDW->UnitDelay4_DSTATE_p,
      localDW->UnitDelay5_DSTATE_d, &localDW->UnitDelay3_DSTATE_m, &localDW->UnitDelay2_DSTATE_f, &localDW->UnitDelay1_DSTATE_o,
      &localDW->UnitDelay_DSTATE_a, &localDW->UnitDelay4_DSTATE_p, &localDW->UnitDelay5_DSTATE_d);

   /* Delay: '<S2>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_k) != 0)
   {
      localDW->ResettableDelay_DSTATE_mw = *rtu_VsVCAN_nu_WheelCount_FR;
   }

   /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
    *  Delay: '<S2>/Resettable Delay'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction(rtu_VsVCAN_nu_WheelCount_FR, localDW->ResettableDelay_DSTATE_mw, &rtb_wheel_ticks);

   /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
    *  Constant: '<S21>/Constant'
    *  DataTypeConversion: '<S21>/Data Type Conversion'
    *  Product: '<S21>/Multiply'
    *  Sum: '<S21>/Add'
    *  UnitDelay: '<S18>/Unit Delay'
    *  UnitDelay: '<S18>/Unit Delay1'
    *  UnitDelay: '<S18>/Unit Delay2'
    *  UnitDelay: '<S18>/Unit Delay3'
    *  UnitDelay: '<S18>/Unit Delay4'
    *  UnitDelay: '<S18>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_i(
      rtb_wheel_ticks, rtu_KsVSE_m_WheelRadius, rtu_VsVCAN_nu_CountsPerRevol, rtu_VsVSE_mps_LastEstimWhlSpd,
      rtu_VsVSE_mps2_LastDifferentiatedWhlSpd, rtu_VsVCAN_us_SysTimer,
      ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->UnitDelay1_DSTATE_l))) * 1.0E-6F, localDW->UnitDelay3_DSTATE_mx,
      localDW->UnitDelay2_DSTATE_k, localDW->UnitDelay1_DSTATE_l, localDW->UnitDelay_DSTATE_f, localDW->UnitDelay4_DSTATE_k,
      localDW->UnitDelay5_DSTATE_c, &localDW->UnitDelay3_DSTATE_mx, &localDW->UnitDelay2_DSTATE_k, &localDW->UnitDelay1_DSTATE_l,
      &localDW->UnitDelay_DSTATE_f, &localDW->UnitDelay4_DSTATE_k, &localDW->UnitDelay5_DSTATE_c);

   /* Delay: '<S3>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_g) != 0)
   {
      localDW->ResettableDelay_DSTATE_g = *rtu_VsVCAN_nu_WheelCount_RL;
   }

   /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
    *  Delay: '<S3>/Resettable Delay'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction(rtu_VsVCAN_nu_WheelCount_RL, localDW->ResettableDelay_DSTATE_g,
                                               &localDW->UnitDelay_DSTATE_ku);

   /* MATLAB Function: '<S29>/MATLAB Function' incorporates:
    *  Constant: '<S32>/Constant'
    *  DataTypeConversion: '<S32>/Data Type Conversion'
    *  Product: '<S32>/Multiply'
    *  Sum: '<S32>/Add'
    *  UnitDelay: '<S29>/Unit Delay'
    *  UnitDelay: '<S29>/Unit Delay1'
    *  UnitDelay: '<S29>/Unit Delay2'
    *  UnitDelay: '<S29>/Unit Delay3'
    *  UnitDelay: '<S29>/Unit Delay4'
    *  UnitDelay: '<S29>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_i(
      localDW->UnitDelay_DSTATE_ku, rtu_KsVSE_m_WheelRadius, rtu_VsVCAN_nu_CountsPerRevol, rtu_VsVSE_mps_LastEstimWhlSpd,
      rtu_VsVSE_mps2_LastDifferentiatedWhlSpd, rtu_VsVCAN_us_SysTimer,
      ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->UnitDelay1_DSTATE_e))) * 1.0E-6F, localDW->UnitDelay3_DSTATE_e,
      localDW->UnitDelay2_DSTATE_b, localDW->UnitDelay1_DSTATE_e, localDW->UnitDelay_DSTATE_k, localDW->UnitDelay4_DSTATE_d,
      localDW->UnitDelay5_DSTATE_f, &localDW->UnitDelay3_DSTATE_e, &localDW->UnitDelay2_DSTATE_b, &localDW->UnitDelay1_DSTATE_e,
      &localDW->UnitDelay_DSTATE_k, &localDW->UnitDelay4_DSTATE_d, &localDW->UnitDelay5_DSTATE_f);

   /* Logic: '<Root>/Logical Operator' incorporates:
    *  RelationalOperator: '<Root>/GreaterThan2'
    *  RelationalOperator: '<Root>/GreaterThan3'
    *  RelationalOperator: '<Root>/GreaterThan4'
    *  RelationalOperator: '<Root>/GreaterThan5'
    *  UnitDelay: '<S18>/Unit Delay'
    *  UnitDelay: '<S29>/Unit Delay'
    *  UnitDelay: '<S40>/Unit Delay'
    *  UnitDelay: '<S7>/Unit Delay'
    */
   *rty_WhlTckIsZeroForLongerDuration =
      ((((localDW->UnitDelay_DSTATE_a > 10U) && (localDW->UnitDelay_DSTATE_f > 10U)) && (localDW->UnitDelay_DSTATE_k > 10U)) &&
       (localDW->UnitDelay_DSTATE > 10U));

   /* Delay: '<S34>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_e) != 0)
   {
      localDW->ResettableDelay_DSTATE_p = *rtu_VsVCAN_us_SysTimer;
   }

   /* MATLAB Function: '<S30>/MATLAB Function' incorporates:
    *  Constant: '<S34>/Constant'
    *  DataTypeConversion: '<S34>/Data Type Conversion'
    *  Delay: '<S34>/Resettable Delay'
    *  Product: '<S34>/Multiply'
    *  Sum: '<S34>/Add1'
    *  UnitDelay: '<S30>/Unit Delay2'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_l(
      localDW->UnitDelay_DSTATE_ku,
      ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->ResettableDelay_DSTATE_p))) * 1.0E-6F, rtu_KsVSE_m_WheelRadius,
      rtu_VsVCAN_nu_CountsPerRevol, localDW->UnitDelay2_DSTATE_m, &localDW->UnitDelay2_DSTATE_m);

   /* DiscreteFilter: '<S35>/Discrete Filter' incorporates:
    *  UnitDelay: '<S30>/Unit Delay2'
    */
   if (((int32_T)localDW->DiscreteFilter_icLoad_o) != 0)
   {
      localDW->DiscreteFilter_states_o[0] = localDW->UnitDelay2_DSTATE_m;
      localDW->DiscreteFilter_states_o[1] = localDW->UnitDelay2_DSTATE_m;
      localDW->DiscreteFilter_icLoad_o    = 0U;
   }

   localDW->DiscreteFilter_tmp_c =
      (localDW->UnitDelay2_DSTATE_m - (localDW->filter_den_e[1] * localDW->DiscreteFilter_states_o[0])) -
      (localDW->filter_den_e[2] * localDW->DiscreteFilter_states_o[1]);

   /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
    *  DiscreteFilter: '<S35>/Discrete Filter'
    *  UnitDelay: '<S29>/Unit Delay2'
    *  UnitDelay: '<S29>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction1(localDW->UnitDelay2_DSTATE_b, localDW->UnitDelay5_DSTATE_f,
                                                ((localDW->filter_num_f[0] * localDW->DiscreteFilter_tmp_c) +
                                                 (localDW->filter_num_f[1] * localDW->DiscreteFilter_states_o[0])) +
                                                   (localDW->filter_num_f[2] * localDW->DiscreteFilter_states_o[1]),
                                                rty_whl_tck_bsd_lin_spd_rl);

   /* Delay: '<S23>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_n) != 0)
   {
      localDW->ResettableDelay_DSTATE_j = *rtu_VsVCAN_us_SysTimer;
   }

   /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
    *  Constant: '<S23>/Constant'
    *  DataTypeConversion: '<S23>/Data Type Conversion'
    *  Delay: '<S23>/Resettable Delay'
    *  Product: '<S23>/Multiply'
    *  Sum: '<S23>/Add1'
    *  UnitDelay: '<S19>/Unit Delay2'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_l(
      rtb_wheel_ticks, ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->ResettableDelay_DSTATE_j))) * 1.0E-6F,
      rtu_KsVSE_m_WheelRadius, rtu_VsVCAN_nu_CountsPerRevol, localDW->UnitDelay2_DSTATE_m3, &localDW->UnitDelay2_DSTATE_m3);

   /* DiscreteFilter: '<S24>/Discrete Filter' incorporates:
    *  UnitDelay: '<S19>/Unit Delay2'
    */
   if (((int32_T)localDW->DiscreteFilter_icLoad_d) != 0)
   {
      localDW->DiscreteFilter_states_i[0] = localDW->UnitDelay2_DSTATE_m3;
      localDW->DiscreteFilter_states_i[1] = localDW->UnitDelay2_DSTATE_m3;
      localDW->DiscreteFilter_icLoad_d    = 0U;
   }

   localDW->DiscreteFilter_tmp_a =
      (localDW->UnitDelay2_DSTATE_m3 - (localDW->filter_den_b[1] * localDW->DiscreteFilter_states_i[0])) -
      (localDW->filter_den_b[2] * localDW->DiscreteFilter_states_i[1]);

   /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
    *  DiscreteFilter: '<S24>/Discrete Filter'
    *  UnitDelay: '<S18>/Unit Delay2'
    *  UnitDelay: '<S18>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction1(localDW->UnitDelay2_DSTATE_k, localDW->UnitDelay5_DSTATE_c,
                                                ((localDW->filter_num_n[0] * localDW->DiscreteFilter_tmp_a) +
                                                 (localDW->filter_num_n[1] * localDW->DiscreteFilter_states_i[0])) +
                                                   (localDW->filter_num_n[2] * localDW->DiscreteFilter_states_i[1]),
                                                rty_whl_tck_bsd_lin_spd_fr);

   /* Delay: '<S12>/Resettable Delay' */
   if (((int32_T)localDW->icLoad_eq) != 0)
   {
      localDW->ResettableDelay_DSTATE_m = *rtu_VsVCAN_us_SysTimer;
   }

   /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
    *  Constant: '<S12>/Constant'
    *  DataTypeConversion: '<S12>/Data Type Conversion'
    *  Delay: '<S12>/Resettable Delay'
    *  Product: '<S12>/Multiply'
    *  Sum: '<S12>/Add1'
    *  UnitDelay: '<S8>/Unit Delay2'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction_l(
      rtb_wheel_ticks_c, ((real32_T)((uint64_T)((*rtu_VsVCAN_us_SysTimer) - localDW->ResettableDelay_DSTATE_m))) * 1.0E-6F,
      rtu_KsVSE_m_WheelRadius, rtu_VsVCAN_nu_CountsPerRevol, localDW->UnitDelay2_DSTATE_i, &localDW->UnitDelay2_DSTATE_i);

   /* DiscreteFilter: '<S13>/Discrete Filter' incorporates:
    *  UnitDelay: '<S8>/Unit Delay2'
    */
   if (((int32_T)localDW->DiscreteFilter_icLoad_a) != 0)
   {
      localDW->DiscreteFilter_states_j[0] = localDW->UnitDelay2_DSTATE_i;
      localDW->DiscreteFilter_states_j[1] = localDW->UnitDelay2_DSTATE_i;
      localDW->DiscreteFilter_icLoad_a    = 0U;
   }

   localDW->DiscreteFilter_tmp_n =
      (localDW->UnitDelay2_DSTATE_i - (localDW->filter_den_p[1] * localDW->DiscreteFilter_states_j[0])) -
      (localDW->filter_den_p[2] * localDW->DiscreteFilter_states_j[1]);

   /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
    *  DiscreteFilter: '<S13>/Discrete Filter'
    *  UnitDelay: '<S7>/Unit Delay2'
    *  UnitDelay: '<S7>/Unit Delay5'
    */
   Wheel_Counts_To_Linear_Speed_MATLABFunction1(localDW->UnitDelay2_DSTATE_f, localDW->UnitDelay5_DSTATE_d,
                                                ((localDW->filter_num_h[0] * localDW->DiscreteFilter_tmp_n) +
                                                 (localDW->filter_num_h[1] * localDW->DiscreteFilter_states_j[0])) +
                                                   (localDW->filter_num_h[2] * localDW->DiscreteFilter_states_j[1]),
                                                rty_whl_tck_bsd_lin_spd_fl);

   /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
    *  Constant: '<S13>/Constant'
    */
   localDW->UnitDelay_DSTATE_p = 0U;

   /* Update for UnitDelay: '<S24>/Unit Delay' incorporates:
    *  Constant: '<S24>/Constant'
    */
   localDW->UnitDelay_DSTATE_fz = 0U;

   /* Update for UnitDelay: '<S35>/Unit Delay' incorporates:
    *  Constant: '<S35>/Constant'
    */
   localDW->UnitDelay_DSTATE_b = 0U;

   /* Update for UnitDelay: '<S46>/Unit Delay' incorporates:
    *  Constant: '<S46>/Constant'
    */
   localDW->UnitDelay_DSTATE_ku = 0U;

   /* Update for Delay: '<S4>/Resettable Delay' */
   localDW->icLoad                   = 0U;
   localDW->ResettableDelay_DSTATE_n = *rtu_VsVCAN_nu_WheelCount_RR;

   /* Update for Delay: '<S45>/Resettable Delay' */
   localDW->icLoad_a               = 0U;
   localDW->ResettableDelay_DSTATE = *rtu_VsVCAN_us_SysTimer;

   /* Update for DiscreteFilter: '<S46>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad    = 0U;
   localDW->DiscreteFilter_states[1] = localDW->DiscreteFilter_states[0];
   localDW->DiscreteFilter_states[0] = localDW->DiscreteFilter_tmp;

   /* Update for Delay: '<S1>/Resettable Delay' */
   localDW->icLoad_j                 = 0U;
   localDW->ResettableDelay_DSTATE_i = *rtu_VsVCAN_nu_WheelCount_FL;

   /* Update for Delay: '<S2>/Resettable Delay' */
   localDW->icLoad_k                  = 0U;
   localDW->ResettableDelay_DSTATE_mw = *rtu_VsVCAN_nu_WheelCount_FR;

   /* Update for Delay: '<S3>/Resettable Delay' */
   localDW->icLoad_g                 = 0U;
   localDW->ResettableDelay_DSTATE_g = *rtu_VsVCAN_nu_WheelCount_RL;

   /* Update for Delay: '<S34>/Resettable Delay' */
   localDW->icLoad_e                 = 0U;
   localDW->ResettableDelay_DSTATE_p = *rtu_VsVCAN_us_SysTimer;

   /* Update for DiscreteFilter: '<S35>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad_o    = 0U;
   localDW->DiscreteFilter_states_o[1] = localDW->DiscreteFilter_states_o[0];
   localDW->DiscreteFilter_states_o[0] = localDW->DiscreteFilter_tmp_c;

   /* Update for Delay: '<S23>/Resettable Delay' */
   localDW->icLoad_n                 = 0U;
   localDW->ResettableDelay_DSTATE_j = *rtu_VsVCAN_us_SysTimer;

   /* Update for DiscreteFilter: '<S24>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad_d    = 0U;
   localDW->DiscreteFilter_states_i[1] = localDW->DiscreteFilter_states_i[0];
   localDW->DiscreteFilter_states_i[0] = localDW->DiscreteFilter_tmp_a;

   /* Update for Delay: '<S12>/Resettable Delay' */
   localDW->icLoad_eq                = 0U;
   localDW->ResettableDelay_DSTATE_m = *rtu_VsVCAN_us_SysTimer;

   /* Update for DiscreteFilter: '<S13>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad_a    = 0U;
   localDW->DiscreteFilter_states_j[1] = localDW->DiscreteFilter_states_j[0];
   localDW->DiscreteFilter_states_j[0] = localDW->DiscreteFilter_tmp_n;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
