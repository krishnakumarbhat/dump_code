/*
 * File: SelectHostLongAccel.c
 *
 * Code generated for Simulink model 'SelectHostLongAccel'.
 *
 * Model version                  : 1.178
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:28 2026
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

#include "SelectHostLongAccel.h"
#include "SelectHostLongAccel_private.h"
#include "look1_iflf_linlc_Aptiv.h"

/* Named constants for Chart: '<S10>/Chart' */
#define SelectHostLongAccel_IN_Initialize ((uint8_T)1U)
#define SelectHostLongAccel_IN_Running    ((uint8_T)2U)

/* Output and update for referenced model: 'SelectHostLongAccel' */
void SelectHostLongAccel(const boolean_T *rtu_VehicleSpeedVSOSig_SNA, const real32_T *rtu_ego_longitudinal_accel,
                         const boolean_T *rtu_LongAcceleration_BSM_SNA, const real32_T *rtu_ego_vehicle_speed_signed,
                         const uint8_T *rtu_filt_veh_speed_over_ground_qf, const uint8_T *rtu_raw_long_accel_qf_primary_in,
                         real32_T *rty_Host_Long_Accel_mpss, real32_T *rty_Road_Grade_Accel, real32_T *rty_IMULongAccelFilt_mpss,
                         real32_T *rty_HostLongAccelFilt_mpss, uint8_T *rty_Road_Grade_Accel_QF,
                         DW_SelectHostLongAccel_f_T *localDW)
{
   boolean_T rtb_speed_not_reliable;
   real32_T rtb_IMULonAccAvail_0;
   boolean_T rtb_IMULonAccAvail_tmp;

   /* Outputs for Atomic SubSystem: '<Root>/Select_Host_Long_Accel'
    *
    * Block description for '<Root>/Select_Host_Long_Accel':
    *  _FCA1PX.DHVS.000_174_
    */
   /* Chart: '<S10>/Chart' */
   /* _FCA8P3.DHVS.111_1_ */
   if (((uint32_T)localDW->bitsForTID0.is_active_c2_SelectHostLongAccel) == 0U)
   {
      localDW->bitsForTID0.is_active_c2_SelectHostLongAccel = 1;
      localDW->bitsForTID0.is_c2_SelectHostLongAccel        = SelectHostLongAccel_IN_Initialize;
      localDW->bitsForTID0.f_initialize_DtrmnVehStationary  = true;
   }
   else if (((uint32_T)localDW->bitsForTID0.is_c2_SelectHostLongAccel) == SelectHostLongAccel_IN_Initialize)
   {
      if (localDW->bitsForTID0.f_initialize_DtrmnVehStationary)
      {
         localDW->bitsForTID0.is_c2_SelectHostLongAccel       = SelectHostLongAccel_IN_Running;
         localDW->bitsForTID0.f_initialize_DtrmnVehStationary = false;
      }
   }
   else
   {
      localDW->bitsForTID0.f_initialize_DtrmnVehStationary = false;
   }

   /* End of Chart: '<S10>/Chart' */

   /* Outputs for Enabled SubSystem: '<S10>/Differentiator Generator' incorporates:
    *  EnablePort: '<S13>/Enable'
    */
   if (localDW->bitsForTID0.f_initialize_DtrmnVehStationary)
   {
      /* MATLAB Function: '<S13>/FindDifferentiatorCoeff' */
      localDW->diff_num[0]   = 0.724336267F;
      localDW->diff_denom[0] = 1.0F;
      localDW->diff_num[1]   = 0.724336267F;
      localDW->diff_denom[1] = -0.822694957F;
      localDW->diff_num[2]   = -0.724336267F;
      localDW->diff_denom[2] = -0.98551327F;
      localDW->diff_num[3]   = -0.724336267F;
      localDW->diff_denom[3] = 0.837181628F;
   }

   /* End of Outputs for SubSystem: '<S10>/Differentiator Generator' */

   /* DiscreteTransferFcn: '<S10>/Differentiator' */
   localDW->Differentiator_tmp =
      (((*rtu_ego_vehicle_speed_signed) - (localDW->diff_denom[1] * localDW->Differentiator_states[0])) -
       (localDW->diff_denom[2] * localDW->Differentiator_states[1])) -
      (localDW->diff_denom[3] * localDW->Differentiator_states[2]);

   /* RelationalOperator: '<S1>/Relational Operator' incorporates:
    *  Constant: '<Root>/k_host_long_accel_min_spd_thrsh'
    *
    * Block description for '<S1>/Relational Operator':
    *  _V5P4R104PX.DHVS.000_27_
    */
   rtb_speed_not_reliable = (0.0F > (*rtu_ego_vehicle_speed_signed));

   /* Switch: '<S1>/Switch' incorporates:
    *  Constant: '<S1>/VS_LOOP_TIME_SEC'
    *  Product: '<S1>/Divide'
    *  Sum: '<S1>/Add8'
    *  UnitDelay: '<S1>/Unit Delay4'
    *
    * Block description for '<S1>/Switch':
    *  _V5P4R104PX.DHVS.000_29_
    *
    * Block description for '<S1>/VS_LOOP_TIME_SEC':
    *  _2p0.DHVS.000_106_
    *
    * Block description for '<S1>/Divide':
    *  _2p0.DHVS.000_89_
    *
    * Block description for '<S1>/Add8':
    *  _2p0.DHVS.000_87_
    *
    * Block description for '<S1>/Unit Delay4':
    *  _2p0.DHVS.000_112_
    */
   if (!rtb_speed_not_reliable)
   {
      localDW->UnitDelay5_DSTATE = ((*rtu_ego_vehicle_speed_signed) - localDW->UnitDelay4_DSTATE) / 0.01F;
   }

   /* End of Switch: '<S1>/Switch' */

   /* Sum: '<S1>/Add' incorporates:
    *  Product: '<S1>/Product'
    *  Sum: '<S1>/Add1'
    *  UnitDelay: '<S1>/Unit Delay'
    *
    * Block description for '<S1>/Add':
    *  _2p0.DHVS.000_79_
    *
    * Block description for '<S1>/Product':
    *  _2p0.DHVS.000_102_
    *
    * Block description for '<S1>/Add1':
    *  _2p0.DHVS.000_80_
    *
    * Block description for '<S1>/Unit Delay':
    *  _2p0.DHVS.000_108_
    */
   localDW->UnitDelay_DSTATE += (localDW->UnitDelay5_DSTATE - localDW->UnitDelay_DSTATE) * 0.000133333335F;

   /* Sum: '<S1>/Add2' incorporates:
    *  Product: '<S1>/Product1'
    *  Sum: '<S1>/Add3'
    *  UnitDelay: '<S1>/Unit Delay1'
    *
    * Block description for '<S1>/Add2':
    *  _2p0.DHVS.000_81_
    *
    * Block description for '<S1>/Product1':
    *  _2p0.DHVS.000_103_
    *
    * Block description for '<S1>/Add3':
    *  _2p0.DHVS.000_82_
    *
    * Block description for '<S1>/Unit Delay1':
    *  _2p0.DHVS.000_109_
    */
   localDW->UnitDelay1_DSTATE += (localDW->UnitDelay_DSTATE - localDW->UnitDelay1_DSTATE) * 0.000133333335F;

   /* Sum: '<S1>/Add4' incorporates:
    *  Product: '<S1>/Product2'
    *  Sum: '<S1>/Add5'
    *  UnitDelay: '<S1>/Unit Delay2'
    *
    * Block description for '<S1>/Add4':
    *  _2p0.DHVS.000_83_
    *
    * Block description for '<S1>/Product2':
    *  _2p0.DHVS.000_104_
    *
    * Block description for '<S1>/Add5':
    *  _2p0.DHVS.000_84_
    *
    * Block description for '<S1>/Unit Delay2':
    *  _2p0.DHVS.000_110_
    */
   localDW->UnitDelay2_DSTATE += (localDW->UnitDelay1_DSTATE - localDW->UnitDelay2_DSTATE) * 0.000133333335F;

   /* Sum: '<S1>/Add6' incorporates:
    *  Product: '<S1>/Product3'
    *  Sum: '<S1>/Add7'
    *  UnitDelay: '<S1>/Unit Delay3'
    *
    * Block description for '<S1>/Add6':
    *  _2p0.DHVS.000_85_
    *
    * Block description for '<S1>/Product3':
    *  _2p0.DHVS.000_105_
    *
    * Block description for '<S1>/Add7':
    *  _2p0.DHVS.000_86_
    *
    * Block description for '<S1>/Unit Delay3':
    *  _2p0.DHVS.000_111_
    */
   localDW->UnitDelay3_DSTATE += (localDW->UnitDelay2_DSTATE - localDW->UnitDelay3_DSTATE) * 0.000133333335F;

   /* Logic: '<S1>/Logical Operator1' incorporates:
    *  MATLAB Function: '<S1>/calc_Road_Grade_Accel_QF'
    *
    * Block description for '<S1>/Logical Operator1':
    *  _4P1R102PX.DHVS.000_11_
    */
   rtb_IMULonAccAvail_tmp = !(*rtu_LongAcceleration_BSM_SNA);

   /* Switch: '<S1>/Switch3' incorporates:
    *  DiscreteTransferFcn: '<S10>/Differentiator'
    *  Logic: '<S1>/Logical Operator1'
    *  Logic: '<S1>/Logical Operator3'
    *  Switch: '<S1>/Switch2'
    *
    * Block description for '<S1>/Switch3':
    *  _V5P4R104PX.DHVS.000_30_
    *
    * Block description for '<S1>/Logical Operator1':
    *  _4P1R102PX.DHVS.000_11_
    *
    * Block description for '<S1>/Logical Operator3':
    *  _V5P4R104PX.DHVS.000_26_
    *
    * Block description for '<S1>/Switch2':
    *  _2p0.DHVS.000_107_
    */
   if ((!rtb_speed_not_reliable) || rtb_IMULonAccAvail_tmp)
   {
      localDW->UnitDelay5_DSTATE = localDW->UnitDelay3_DSTATE;
   }
   else if (*rtu_VehicleSpeedVSOSig_SNA)
   {
      /* Switch: '<S1>/Switch2' incorporates:
       *  Constant: '<S1>/Constant1'
       *
       * Block description for '<S1>/Switch2':
       *  _2p0.DHVS.000_107_
       *
       * Block description for '<S1>/Constant1':
       *  _2p0.DHVS.000_88_
       */
      localDW->UnitDelay5_DSTATE = 0.0F;
   }
   else
   {
      localDW->UnitDelay5_DSTATE =
         (((localDW->diff_num[0] * localDW->Differentiator_tmp) + (localDW->diff_num[1] * localDW->Differentiator_states[0])) +
          (localDW->diff_num[2] * localDW->Differentiator_states[1])) +
         (localDW->diff_num[3] * localDW->Differentiator_states[2]);
   }

   /* End of Switch: '<S1>/Switch3' */

   /* Saturate: '<S1>/Host_Long_Accel_Limit'
    *
    * Block description for '<S1>/Host_Long_Accel_Limit':
    *  _2p0.DHVS.000_100_
    */
   if (localDW->UnitDelay5_DSTATE > 15.0F)
   {
      *rty_Host_Long_Accel_mpss = 15.0F;
   }
   else if (localDW->UnitDelay5_DSTATE < -15.0F)
   {
      *rty_Host_Long_Accel_mpss = -15.0F;
   }
   else
   {
      *rty_Host_Long_Accel_mpss = localDW->UnitDelay5_DSTATE;
   }

   /* End of Saturate: '<S1>/Host_Long_Accel_Limit' */

   /* Outputs for Atomic SubSystem: '<S1>/HostAccelGrade_Filter'
    *
    * Block description for '<S1>/HostAccelGrade_Filter':
    *  _FCA1PX.DHVS.000_183_
    */
   /* Sum: '<S5>/Sum1' incorporates:
    *  Constant: '<S1>/VS_LOOP_TIME1'
    *  DataTypeConversion: '<S1>/Data Type Conversion1'
    *  DataTypeConversion: '<S4>/Cast1'
    *  Lookup_n-D: '<S1>/k_HostAccelGrade_Filt_Time_ms'
    *  Product: '<S4>/Product4'
    *  Product: '<S5>/Product'
    *  Sum: '<S4>/Sum'
    *  Sum: '<S5>/Sum'
    *  UnitDelay: '<S5>/Unit Delay'
    *
    * Block description for '<S5>/Sum1':
    *  _SGM3PX.DHVS.000_5_
    *
    * Block description for '<S1>/VS_LOOP_TIME1':
    *  _SGM3PX.DHVS.000_8_
    *
    * Block description for '<S4>/Product4':
    *  _2p0.Clib.000_11_
    *
    * Block description for '<S5>/Product':
    *  _SGM3PX.DHVS.000_3_
    *
    * Block description for '<S4>/Sum':
    *  _2p0.Clib.000_12_
    *
    * Block description for '<S5>/Sum':
    *  _SGM3PX.DHVS.000_4_
    *
    * Block description for '<S5>/Unit Delay':
    *  _SGM3PX.DHVS.000_6_
    */
   *rty_HostLongAccelFilt_mpss =
      (((real32_T)((
          real_T)(0.01 / ((real_T)((uint16_T)((
                            real32_T)(0.01F + ((real32_T)((uint16_T)look1_iflf_linlc_Aptiv(
                                                 *rtu_ego_vehicle_speed_signed, SelectHostLongAccel_ConstP.pooled3,
                                                 SelectHostLongAccel_ConstP.k_HostAccelGrade_Filt_Time_ms_tableData, 6U)))))))))) *
       ((*rty_Host_Long_Accel_mpss) - localDW->UnitDelay_DSTATE_j)) +
      localDW->UnitDelay_DSTATE_j;

   /* Update for UnitDelay: '<S5>/Unit Delay'
    *
    * Block description for '<S5>/Unit Delay':
    *  _SGM3PX.DHVS.000_6_
    */
   localDW->UnitDelay_DSTATE_j = *rty_HostLongAccelFilt_mpss;

   /* End of Outputs for SubSystem: '<S1>/HostAccelGrade_Filter' */

   /* Outputs for Atomic SubSystem: '<S1>/IMULonAcc_Filter'
    *
    * Block description for '<S1>/IMULonAcc_Filter':
    *  _FCA1PX.DHVS.000_184_
    */
   /* Sum: '<S7>/Sum1' incorporates:
    *  Constant: '<S1>/VS_LOOP_TIME'
    *  DataTypeConversion: '<S1>/Data Type Conversion2'
    *  DataTypeConversion: '<S3>/Cast1'
    *  Lookup_n-D: '<S1>/k_IMULonAccPri_Filt_Time_ms'
    *  Product: '<S3>/Product4'
    *  Product: '<S7>/Product'
    *  Sum: '<S3>/Sum'
    *  Sum: '<S7>/Sum'
    *  UnitDelay: '<S7>/Unit Delay'
    *
    * Block description for '<S7>/Sum1':
    *  _V4P10R103PX.DHVS.000_41_
    *
    * Block description for '<S1>/VS_LOOP_TIME':
    *  _V4P10R103PX.DHVS.000_46_
    *
    * Block description for '<S3>/Product4':
    *  _2p0.Clib.000_11_
    *
    * Block description for '<S7>/Product':
    *  _V4P10R103PX.DHVS.000_39_
    *
    * Block description for '<S3>/Sum':
    *  _2p0.Clib.000_12_
    *
    * Block description for '<S7>/Sum':
    *  _V4P10R103PX.DHVS.000_40_
    *
    * Block description for '<S7>/Unit Delay':
    *  _V4P10R103PX.DHVS.000_42_
    */
   *rty_IMULongAccelFilt_mpss =
      (((real32_T)((
          real_T)(0.01 / ((real_T)((uint16_T)((
                            real32_T)(0.01F + ((real32_T)((uint16_T)look1_iflf_linlc_Aptiv(
                                                 *rtu_ego_vehicle_speed_signed, SelectHostLongAccel_ConstP.pooled3,
                                                 SelectHostLongAccel_ConstP.k_IMULonAccPri_Filt_Time_ms_tableData, 6U)))))))))) *
       ((*rtu_ego_longitudinal_accel) - localDW->UnitDelay_DSTATE_m)) +
      localDW->UnitDelay_DSTATE_m;

   /* Update for UnitDelay: '<S7>/Unit Delay'
    *
    * Block description for '<S7>/Unit Delay':
    *  _V4P10R103PX.DHVS.000_42_
    */
   localDW->UnitDelay_DSTATE_m = *rty_IMULongAccelFilt_mpss;

   /* End of Outputs for SubSystem: '<S1>/IMULonAcc_Filter' */

   /* Switch: '<S1>/Switch1' incorporates:
    *  Constant: '<S1>/Constant2'
    *  Logic: '<S1>/Logical Operator1'
    *  Sum: '<S1>/Subtract'
    *
    * Block description for '<S1>/Switch1':
    *  _4P1R102PX.DHVS.000_21_
    *
    * Block description for '<S1>/Constant2':
    *  _2p0.DHVS.000_88_
    *
    * Block description for '<S1>/Logical Operator1':
    *  _4P1R102PX.DHVS.000_11_
    *
    * Block description for '<S1>/Subtract':
    *  _4P1R102PX.DHVS.000_20_
    */
   if (rtb_IMULonAccAvail_tmp)
   {
      rtb_IMULonAccAvail_0 = (*rty_IMULongAccelFilt_mpss) - (*rty_HostLongAccelFilt_mpss);
   }
   else
   {
      rtb_IMULonAccAvail_0 = 0.0F;
   }

   /* End of Switch: '<S1>/Switch1' */

   /* Outputs for Atomic SubSystem: '<S1>/Road_Grade_Accel_Filter'
    *
    * Block description for '<S1>/Road_Grade_Accel_Filter':
    *  _FCA1PX.DHVS.000_187_
    */
   /* Sum: '<S9>/Sum1' incorporates:
    *  Constant: '<S1>/VS_LOOP_TIME2'
    *  DataTypeConversion: '<S1>/Data Type Conversion'
    *  DataTypeConversion: '<S2>/Cast2'
    *  Lookup_n-D: '<S1>/k_Road_Grade_Accel_Filt_Time'
    *  Product: '<S2>/Product4'
    *  Product: '<S9>/Product'
    *  Sum: '<S2>/Sum'
    *  Sum: '<S9>/Sum'
    *  UnitDelay: '<S9>/Unit Delay'
    *
    * Block description for '<S9>/Sum1':
    *  _4P1R102PX.DHVS.000_15_
    *
    * Block description for '<S1>/VS_LOOP_TIME2':
    *  _4P1R102PX.DHVS.000_7_
    *
    * Block description for '<S2>/Product4':
    *  _2p0.Clib.000_11_
    *
    * Block description for '<S9>/Product':
    *  _4P1R102PX.DHVS.000_13_
    *
    * Block description for '<S2>/Sum':
    *  _2p0.Clib.000_12_
    *
    * Block description for '<S9>/Sum':
    *  _4P1R102PX.DHVS.000_14_
    *
    * Block description for '<S9>/Unit Delay':
    *  _4P1R102PX.DHVS.000_16_
    */
   localDW->UnitDelay_DSTATE_d +=
      ((real32_T)((
         real_T)(0.01 / ((real_T)((uint16_T)((
                           real32_T)(0.01F + ((real32_T)((uint16_T)look1_iflf_linlc_Aptiv(
                                                *rtu_ego_vehicle_speed_signed, SelectHostLongAccel_ConstP.pooled3,
                                                SelectHostLongAccel_ConstP.k_Road_Grade_Accel_Filt_Time_tableData, 6U)))))))))) *
      (rtb_IMULonAccAvail_0 - localDW->UnitDelay_DSTATE_d);

   /* End of Outputs for SubSystem: '<S1>/Road_Grade_Accel_Filter' */

   /* Sum: '<S1>/Subtract1' incorporates:
    *  UnitDelay: '<S1>/Unit Delay5'
    *  UnitDelay: '<S9>/Unit Delay'
    *
    * Block description for '<S1>/Subtract1':
    *  _V5P4R104PX.DHVS.000_28_
    *
    * Block description for '<S1>/Unit Delay5':
    *  _V5P4R104PX.DHVS.000_31_
    *
    * Block description for '<S9>/Unit Delay':
    *  _4P1R102PX.DHVS.000_16_
    */
   localDW->UnitDelay5_DSTATE = (*rtu_ego_longitudinal_accel) - localDW->UnitDelay_DSTATE_d;

   /* Saturate: '<S1>/Road_Grade_Accel_Limit' incorporates:
    *  UnitDelay: '<S9>/Unit Delay'
    *
    * Block description for '<S1>/Road_Grade_Accel_Limit':
    *  _4P1R102PX.DHVS.000_9_
    *
    * Block description for '<S9>/Unit Delay':
    *  _4P1R102PX.DHVS.000_16_
    */
   if (localDW->UnitDelay_DSTATE_d > 5.0F)
   {
      *rty_Road_Grade_Accel = 5.0F;
   }
   else if (localDW->UnitDelay_DSTATE_d < -5.0F)
   {
      *rty_Road_Grade_Accel = -5.0F;
   }
   else
   {
      *rty_Road_Grade_Accel = localDW->UnitDelay_DSTATE_d;
   }

   /* End of Saturate: '<S1>/Road_Grade_Accel_Limit' */

   /* MATLAB Function: '<S1>/calc_Road_Grade_Accel_QF' */
   if ((!(*rtu_VehicleSpeedVSOSig_SNA)) && rtb_IMULonAccAvail_tmp)
   {
      if ((*rtu_filt_veh_speed_over_ground_qf) <= (*rtu_raw_long_accel_qf_primary_in))
      {
         *rty_Road_Grade_Accel_QF = *rtu_filt_veh_speed_over_ground_qf;
      }
      else
      {
         *rty_Road_Grade_Accel_QF = *rtu_raw_long_accel_qf_primary_in;
      }
   }
   else
   {
      *rty_Road_Grade_Accel_QF = 0U;
   }

   /* Update for DiscreteTransferFcn: '<S10>/Differentiator' */
   localDW->Differentiator_states[2] = localDW->Differentiator_states[1];
   localDW->Differentiator_states[1] = localDW->Differentiator_states[0];
   localDW->Differentiator_states[0] = localDW->Differentiator_tmp;

   /* Update for UnitDelay: '<S1>/Unit Delay4'
    *
    * Block description for '<S1>/Unit Delay4':
    *  _2p0.DHVS.000_112_
    */
   localDW->UnitDelay4_DSTATE = *rtu_ego_vehicle_speed_signed;

   /* End of Outputs for SubSystem: '<Root>/Select_Host_Long_Accel' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
