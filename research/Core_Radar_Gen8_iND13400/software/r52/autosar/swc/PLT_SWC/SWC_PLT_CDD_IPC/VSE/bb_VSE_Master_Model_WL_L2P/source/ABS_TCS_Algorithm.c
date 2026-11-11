/*
 * File: ABS_TCS_Algorithm.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
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

#include "ABS_TCS_Algorithm.h"
#include "ABS_TCS_Algorithm_private.h"
#include "LDLf_int32_Treal32_T_Aptiv.h"
#include "MultiWordSub_Aptiv.h"
#include "MultiWordUnsignedWrap_Aptiv.h"
#include "sMultiWord2uMultiWordSat_Aptiv.h"
#include "sort_SnqwCpb7_Aptiv.h"
#include "uLong2MultiWord_Aptiv.h"
#include "uMultiWord2MultiWord_Aptiv.h"
#include "uMultiWord2uMultiWordSat_Aptiv.h"
#include "uMultiWordShl_Aptiv.h"
#include "uMultiWordShr_Aptiv.h"
#include "uMultiWordSingle_Aptiv.h"

/* Named constants for Chart: '<S82>/Debouncer' */
#define ABS_TCS_Algorithm_IN_Debounce        ((uint8_T)1U)
#define ABS_TCS_Algorithm_IN_Fault           ((uint8_T)1U)
#define ABS_TCS_Algorithm_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ABS_TCS_Algorithm_IN_Normal          ((uint8_T)2U)
#define ABS_TCS_Algorithm_IN_Off             ((uint8_T)2U)
#define ABS_TCS_Algorithm_IN_Off_i           ((uint8_T)1U)
#define ABS_TCS_Algorithm_IN_On              ((uint8_T)3U)
#define ABS_TCS_Algorithm_IN_On_g            ((uint8_T)2U)

/* Forward declaration for local functions */
static void ABS_TCS_Algorithm_SystemCore_release(dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T *obj);
static void ABS_TCS_Algorithm_SystemCore_delete(dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T *obj);
static void ABS_TCS_Algorithm_matlabCodegenHandle_matlabCodegenDestructor(dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T *obj);

/*
 * Output and update for action system:
 *    '<S43>/calc_accuracy_level_under_medium_confidence'
 *    '<S43>/calc_accuracy_level_under_low_confidence'
 */
void ABS_TCS_Algorithm_calc_accuracy_level_under_medium_confidence(
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongSpdAccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongAccelAccLvl,
   const ConstB_calc_accuracy_level_under_medium_confidence_ABS_TCS_Algorithm_T *localC)
{
   /* SignalConversion: '<S49>/OutportBufferForVeVSE_WhlOdoVehLongAccelAccLvl' */
   *rty_VeVSE_WhlOdoVehLongAccelAccLvl = localC->In1;

   /* SignalConversion: '<S49>/OutportBufferForVeVSE_WhlOdoVehLongSpdAccLvl' */
   *rty_VeVSE_WhlOdoVehLongSpdAccLvl = localC->In1;
}

/*
 * Output and update for enable system:
 *    '<S56>/Initialization1'
 *    '<S57>/Initialization'
 */
void ABS_TCS_Algorithm_Initialization1(boolean_T rtu_Enable, real32_T rty_diff_num[4], real32_T rty_diff_denom[4])
{
   /* Outputs for Enabled SubSystem: '<S56>/Initialization1' incorporates:
    *  EnablePort: '<S59>/Enable'
    */
   if (rtu_Enable)
   {
      /* MATLAB Function: '<S59>/find_Differentiator_Coeff' */
      rty_diff_num[0]   = 0.724336267F;
      rty_diff_denom[0] = 1.0F;
      rty_diff_num[1]   = 0.724336267F;
      rty_diff_denom[1] = -0.822694957F;
      rty_diff_num[2]   = -0.724336267F;
      rty_diff_denom[2] = -0.98551327F;
      rty_diff_num[3]   = -0.724336267F;
      rty_diff_denom[3] = 0.837181628F;
   }

   /* End of Outputs for SubSystem: '<S56>/Initialization1' */
}

/*
 * System initialize for atomic system:
 *    '<S82>/Debouncer'
 *    '<S95>/Debouncer'
 *    '<S100>/Debouncer'
 *    '<S101>/Debouncer'
 *    '<S102>/Debouncer'
 *    '<S103>/Debouncer'
 *    '<S122>/Debouncer'
 *    '<S146>/Debouncer'
 *    '<S147>/Debouncer'
 *    '<S148>/Debouncer'
 *    '<S149>/Debouncer'
 */
void ABS_TCS_Algorithm_Debouncer_Init(boolean_T *rty_Fault)
{
   *rty_Fault = false;
}

/*
 * Output and update for atomic system:
 *    '<S82>/Debouncer'
 *    '<S95>/Debouncer'
 *    '<S100>/Debouncer'
 *    '<S101>/Debouncer'
 *    '<S102>/Debouncer'
 *    '<S103>/Debouncer'
 *    '<S122>/Debouncer'
 *    '<S146>/Debouncer'
 *    '<S147>/Debouncer'
 *    '<S148>/Debouncer'
 *    '<S149>/Debouncer'
 */
void ABS_TCS_Algorithm_Debouncer(boolean_T rtu_sw, boolean_T *rty_Output, boolean_T *rty_Fault,
                                 DW_Debouncer_ABS_TCS_Algorithm_T *localDW, real32_T rtp_Debounce_Time,
                                 boolean_T rtp_Demat_Duration_Check, real32_T rtp_Dematuration_Time, boolean_T rtp_Fault_Check,
                                 boolean_T rtp_Mat_Duration_Check, real32_T rtp_Maturation_Time, real32_T rtp_Recovery_Time)
{
   boolean_T tmp;

   /* Chart: '<S82>/Debouncer' */
   if (localDW->temporalCounter_i1 < MAX_uint32_T)
   {
      localDW->temporalCounter_i1++;
   }

   if (localDW->temporalCounter_i2 < MAX_uint32_T)
   {
      localDW->temporalCounter_i2++;
   }

   if (((uint32_T)localDW->bitsForTID0.is_active_c1_SignalDebouncingLogic) == 0U)
   {
      localDW->bitsForTID0.is_active_c1_SignalDebouncingLogic = 1;
      localDW->bitsForTID0.is_c1_SignalDebouncingLogic        = ABS_TCS_Algorithm_IN_Off;
      *rty_Output                                             = false;
      localDW->bitsForTID0.is_Off                             = ABS_TCS_Algorithm_IN_Normal;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c1_SignalDebouncingLogic)
      {
         case ABS_TCS_Algorithm_IN_Debounce:
            if ((((real32_T)localDW->temporalCounter_i1) >= (rtp_Debounce_Time * 100.0F)) && rtp_Fault_Check)
            {
               localDW->bitsForTID0.is_Debounce                 = ABS_TCS_Algorithm_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_Off;
               *rty_Output                                      = false;
               localDW->bitsForTID0.is_Off                      = ABS_TCS_Algorithm_IN_Fault;
               localDW->temporalCounter_i1                      = 0U;
               *rty_Fault                                       = true;
            }
            else if (((uint32_T)localDW->bitsForTID0.is_Debounce) == ABS_TCS_Algorithm_IN_Off_i)
            {
               if (((real32_T)localDW->temporalCounter_i2) >= (rtp_Dematuration_Time * 100.0F))
               {
                  localDW->bitsForTID0.is_Debounce                 = ABS_TCS_Algorithm_IN_NO_ACTIVE_CHILD;
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_Off;
                  *rty_Output                                      = false;
                  localDW->bitsForTID0.is_Off                      = ABS_TCS_Algorithm_IN_Normal;
               }
               else
               {
                  if (rtu_sw)
                  {
                     localDW->bitsForTID0.is_Debounce = ABS_TCS_Algorithm_IN_On_g;
                     localDW->temporalCounter_i2      = 0U;
                  }
               }
            }
            else if (((real32_T)localDW->temporalCounter_i2) >= (rtp_Maturation_Time * 100.0F))
            {
               localDW->bitsForTID0.is_Debounce                 = ABS_TCS_Algorithm_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_On;
               *rty_Output                                      = true;
            }
            else
            {
               if (!rtu_sw)
               {
                  localDW->bitsForTID0.is_Debounce = ABS_TCS_Algorithm_IN_Off_i;
                  localDW->temporalCounter_i2      = 0U;
               }
            }
            break;

         case ABS_TCS_Algorithm_IN_Off:
            *rty_Output = false;
            if (rtu_sw && (!rtp_Mat_Duration_Check))
            {
               *rty_Fault                                       = false;
               localDW->bitsForTID0.is_Off                      = ABS_TCS_Algorithm_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_On;
               *rty_Output                                      = true;
            }
            else if (((uint32_T)localDW->bitsForTID0.is_Off) == ABS_TCS_Algorithm_IN_Fault)
            {
               if (((real32_T)localDW->temporalCounter_i1) >= (rtp_Recovery_Time * 100.0F))
               {
                  *rty_Fault                  = false;
                  localDW->bitsForTID0.is_Off = ABS_TCS_Algorithm_IN_Normal;
               }
            }
            else
            {
               if (rtp_Mat_Duration_Check && rtu_sw)
               {
                  localDW->bitsForTID0.is_Off                      = ABS_TCS_Algorithm_IN_NO_ACTIVE_CHILD;
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_Debounce;
                  localDW->temporalCounter_i1                      = 0U;
                  localDW->bitsForTID0.is_Debounce                 = ABS_TCS_Algorithm_IN_On_g;
                  localDW->temporalCounter_i2                      = 0U;
               }
            }
            break;

         default:
            *rty_Output = true;
            tmp         = !rtu_sw;
            if (tmp && rtp_Demat_Duration_Check)
            {
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_Debounce;
               localDW->temporalCounter_i1                      = 0U;
               localDW->bitsForTID0.is_Debounce                 = ABS_TCS_Algorithm_IN_Off_i;
               localDW->temporalCounter_i2                      = 0U;
            }
            else
            {
               if ((!rtp_Demat_Duration_Check) && tmp)
               {
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = ABS_TCS_Algorithm_IN_Off;
                  *rty_Output                                      = false;
                  localDW->bitsForTID0.is_Off                      = ABS_TCS_Algorithm_IN_Normal;
               }
            }
            break;
      }
   }

   /* End of Chart: '<S82>/Debouncer' */
}

/*
 * Output and update for atomic system:
 *    '<S79>/MATLAB Function'
 *    '<S128>/MATLAB Function'
 */
void ABS_TCS_Algorithm_MATLABFunction(real32_T rtu_Input_Vector, real32_T rtu_Input_Vector_n, real32_T rtu_Input_Vector_l,
                                      real32_T rtu_Input_Vector_p, real32_T rty_Output_Vector[4])
{
   /* SignalConversion: '<S83>/TmpSignal ConversionAt SFunction Inport1' */
   rty_Output_Vector[0] = rtu_Input_Vector;
   rty_Output_Vector[1] = rtu_Input_Vector_n;
   rty_Output_Vector[2] = rtu_Input_Vector_l;
   rty_Output_Vector[3] = rtu_Input_Vector_p;
   sort_SnqwCpb7_Aptiv(rty_Output_Vector);
}

/*
 * Output and update for action system:
 *    '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1'
 *    '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1'
 */
void ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1(real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec,
                                                                      real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec_i,
                                                                      real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec_f,
                                                                      real32_T rtu_VsVSE_mps_TransFiltWhlSpd_vec_n,
                                                                      uint8_T *rty_VsVSE_u8_SwitchToMeasAx,
                                                                      real32_T *rty_VsVSE_mps_SpeedUnderABS)
{
   /* SignalConversion: '<S92>/OutportBuffer_InsertedFor_VsVSE_u8_SwitchToMeasAx_at_inport_0' incorporates:
    *  Constant: '<S92>/Constant'
    */
   *rty_VsVSE_u8_SwitchToMeasAx = 1U;

   /* Product: '<S92>/Divide' incorporates:
    *  Constant: '<S92>/Constant1'
    *  Sum: '<S92>/Add'
    */
   *rty_VsVSE_mps_SpeedUnderABS =
      (((rtu_VsVSE_mps_TransFiltWhlSpd_vec + rtu_VsVSE_mps_TransFiltWhlSpd_vec_i) + rtu_VsVSE_mps_TransFiltWhlSpd_vec_f) +
       rtu_VsVSE_mps_TransFiltWhlSpd_vec_n) /
      4.0F;
}

/*
 * Output and update for action system:
 *    '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2'
 *    '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2'
 */
void ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2(real32_T rtu_VsVSE_mps_MeanWhlSpdCloser,
                                                                      uint8_T *rty_VsVSE_u8_SwitchToMeasAx,
                                                                      real32_T *rty_VsVSE_mps_SpeedUnderABS)
{
   /* SignalConversion: '<S93>/OutportBuffer_InsertedFor_VsVSE_u8_SwitchToMeasAx_at_inport_0' incorporates:
    *  Constant: '<S93>/Constant'
    */
   *rty_VsVSE_u8_SwitchToMeasAx = 0U;

   /* Inport: '<S93>/VsVSE_mps_MeanWhlSpdCloser' */
   *rty_VsVSE_mps_SpeedUnderABS = rtu_VsVSE_mps_MeanWhlSpdCloser;
}

/*
 * Output and update for iterator system:
 *    '<S99>/calc_rate_from_the_sorted_spd'
 *    '<S127>/calc_rate_from_the_sorted_spd'
 */
void ABS_TCS_Algorithm_calc_rate_from_the_sorted_spd(int32_T NumIters, const real32_T rtu_VaVSE_mps_TransFiltWhlLinSpd[4],
                                                     real32_T rtu_Vs_s_DeltaSystemTime,
                                                     real32_T rtu_KsVSE_mps2_SortedWhlBsdAcclMaxThrsh,
                                                     boolean_T rty_VaVSE_b_IsSortedWhlSpdBsdAcclHigh[4],
                                                     DW_calc_rate_from_the_sorted_spd_ABS_TCS_Algorithm_T localDW[4])
{
   /* local scratch DWork variables */
   int32_T ForEach_itr;
   boolean_T rtb_VaVSE_b_IsSortedWhlSpdBsdAcclHigh;

   /* Outputs for Iterator SubSystem: '<S99>/calc_rate_from_the_sorted_spd' incorporates:
    *  ForEach: '<S108>/For Each'
    */
   for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++)
   {
      /* Product: '<S109>/Divide' incorporates:
       *  ForEachSliceSelector: '<S108>/ImpSel_InsertedFor_VaVSE_mps_TransFiltWhlLinSpd_at_outport_0'
       *  Sum: '<S109>/Add1'
       *  UnitDelay: '<S109>/Unit Delay'
       */
      localDW[ForEach_itr].CoreSubsys.UnitDelay_DSTATE =
         (rtu_VaVSE_mps_TransFiltWhlLinSpd[ForEach_itr] - localDW[ForEach_itr].CoreSubsys.UnitDelay_DSTATE) /
         rtu_Vs_s_DeltaSystemTime;

      /* Abs: '<S108>/Abs' incorporates:
       *  UnitDelay: '<S109>/Unit Delay'
       */
      localDW[ForEach_itr].CoreSubsys.UnitDelay_DSTATE = fabsf(localDW[ForEach_itr].CoreSubsys.UnitDelay_DSTATE);

      /* RelationalOperator: '<S108>/GreaterThan' incorporates:
       *  UnitDelay: '<S109>/Unit Delay'
       */
      rtb_VaVSE_b_IsSortedWhlSpdBsdAcclHigh =
         (localDW[ForEach_itr].CoreSubsys.UnitDelay_DSTATE > rtu_KsVSE_mps2_SortedWhlBsdAcclMaxThrsh);

      /* Update for UnitDelay: '<S109>/Unit Delay' incorporates:
       *  ForEachSliceSelector: '<S108>/ImpSel_InsertedFor_VaVSE_mps_TransFiltWhlLinSpd_at_outport_0'
       */
      localDW[ForEach_itr].CoreSubsys.UnitDelay_DSTATE = rtu_VaVSE_mps_TransFiltWhlLinSpd[ForEach_itr];

      /* ForEachSliceAssignment: '<S108>/ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0' */
      rty_VaVSE_b_IsSortedWhlSpdBsdAcclHigh[ForEach_itr] = rtb_VaVSE_b_IsSortedWhlSpdBsdAcclHigh;
   }

   /* End of Outputs for SubSystem: '<S99>/calc_rate_from_the_sorted_spd' */
}

/*
 * Output and update for iterator system:
 *    '<S89>/Final_Check_For_Closer_Whl_Spd'
 *    '<S126>/Final_Check_For_Closer_Whl_Spd'
 */
void ABS_TCS_Algorithm_Final_Check_For_Closer_Whl_Spd(int32_T NumIters, const boolean_T rtu_VsVSE_b_AreWhlsCloser_vec[5],
                                                      const boolean_T rtu_VsVSE_b_IsCloserWhlRateLow_vec[5],
                                                      boolean_T rty_VaVSE_b_CloserWhlSpdSet[5])
{
   /* local scratch DWork variables */
   int32_T ForEach_itr;

   /* Outputs for Iterator SubSystem: '<S89>/Final_Check_For_Closer_Whl_Spd' incorporates:
    *  ForEach: '<S112>/For Each'
    */
   for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++)
   {
      /* ForEachSliceAssignment: '<S112>/ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0' incorporates:
       *  ForEachSliceSelector: '<S112>/ImpSel_InsertedFor_VsVSE_b_AreWhlsCloser_vec_at_outport_0'
       *  ForEachSliceSelector: '<S112>/ImpSel_InsertedFor_VsVSE_b_IsCloserWhlRateLow_vec_at_outport_0'
       *  Logic: '<S112>/Logical Operator'
       */
      rty_VaVSE_b_CloserWhlSpdSet[ForEach_itr] =
         ((rtu_VsVSE_b_AreWhlsCloser_vec[ForEach_itr]) && (rtu_VsVSE_b_IsCloserWhlRateLow_vec[ForEach_itr]));
   }

   /* End of Outputs for SubSystem: '<S89>/Final_Check_For_Closer_Whl_Spd' */
}

static void ABS_TCS_Algorithm_SystemCore_release(dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T *obj)
{
   dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T *obj_0;
   if ((obj->isInitialized == 1) && (obj->isSetupComplete))
   {
      obj_0 = obj->pStatistic;
      if (obj_0->isInitialized == 1)
      {
         obj_0->isInitialized = 2;
      }

      obj->NumChannels = -1;
   }
}

static void ABS_TCS_Algorithm_SystemCore_delete(dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T *obj)
{
   ABS_TCS_Algorithm_SystemCore_release(obj);
}

static void ABS_TCS_Algorithm_matlabCodegenHandle_matlabCodegenDestructor(dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T *obj)
{
   if (!obj->matlabCodegenIsDeleted)
   {
      obj->matlabCodegenIsDeleted = true;
      ABS_TCS_Algorithm_SystemCore_delete(obj);
   }
}

/* System initialize for referenced model: 'ABS_TCS_Algorithm' */
void ABS_TCS_Algorithm_Init(real32_T *rty_VsVSE_mps_WhlOdoVehSpeedFromABSTCS, real32_T *rty_VsVSE_mps_WhlOdoVehAxFromABSTCS,
                            DW_ABS_TCS_Algorithm_f_T *localDW)
{
   /* InitializeConditions for Delay: '<S4>/Resettable Delay' */
   localDW->icLoad = 1U;

   /* InitializeConditions for UnitDelay: '<S174>/FixPt Unit Delay2' */
   localDW->FixPtUnitDelay2_DSTATE = 1U;

   /* InitializeConditions for DiscreteFilter: '<S13>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad = 1U;

   /* InitializeConditions for UnitDelay: '<S22>/FixPt Unit Delay2' */
   localDW->FixPtUnitDelay2_DSTATE_e = 1U;

   /* InitializeConditions for UnitDelay: '<S16>/Unit Delay3' */
   localDW->UnitDelay3_DSTATE[0] = 10.051F;
   localDW->UnitDelay3_DSTATE[1] = 0.1F;
   localDW->UnitDelay3_DSTATE[2] = 0.1F;
   localDW->UnitDelay3_DSTATE[3] = 10.05F;

   /* SystemInitialize for Chart: '<S82>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_k);

   /* SystemInitialize for Chart: '<S122>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_h);

   /* SystemInitialize for Chart: '<S100>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_nj);

   /* SystemInitialize for Chart: '<S101>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_fo);

   /* SystemInitialize for Chart: '<S102>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_n);

   /* SystemInitialize for Chart: '<S103>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_g);

   /* SystemInitialize for Chart: '<S95>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_fe);

   /* SystemInitialize for Chart: '<S146>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_m);

   /* SystemInitialize for Chart: '<S147>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_d);

   /* SystemInitialize for Chart: '<S148>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault_f);

   /* SystemInitialize for Chart: '<S149>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer_Init(&localDW->Fault);

   /* InitializeConditions for MATLABSystem: '<S10>/Moving Average' */
   if (localDW->obj.pStatistic->isInitialized == 1)
   {
      localDW->obj.pStatistic->pwN = 1.0F;
      localDW->obj.pStatistic->pmN = 0.0F;
   }

   /* End of InitializeConditions for MATLABSystem: '<S10>/Moving Average' */

   /* SystemInitialize for Iterator SubSystem: '<S16>/Control' */
   /* InitializeConditions for UnitDelay: '<S35>/init_value' */
   localDW->init_value_DSTATE = 1U;

   /* InitializeConditions for UnitDelay: '<S38>/init_value' */
   localDW->init_value_DSTATE_a = 1U;

   /* End of SystemInitialize for SubSystem: '<S16>/Control' */

   /* SystemInitialize for SignalConversion: '<Root>/TmpSignal ConversionAtVsVSE_mps_WhlOdoVehAxFromABSTCSInport1' */
   *rty_VsVSE_mps_WhlOdoVehAxFromABSTCS = localDW->Assignment[1];

   /* SystemInitialize for SignalConversion: '<Root>/TmpSignal ConversionAtVsVSE_mps_WhlOdoVehSpeedFromABSTCSInport1' */
   *rty_VsVSE_mps_WhlOdoVehSpeedFromABSTCS = localDW->Assignment[0];
}

/* Start for referenced model: 'ABS_TCS_Algorithm' */
void ABS_TCS_Algorithm_Start(DW_ABS_TCS_Algorithm_f_T *localDW)
{
   boolean_T flag;

   /* Start for MATLABSystem: '<S10>/Moving Average' */
   localDW->obj.matlabCodegenIsDeleted = true;
   localDW->obj.isInitialized          = 0;
   localDW->obj.NumChannels            = -1;
   localDW->obj.matlabCodegenIsDeleted = false;
   localDW->bitsForTID0.objisempty     = true;
   if (localDW->obj.isInitialized == 1)
   {
      localDW->obj.TunablePropsChanged = true;
   }

   localDW->obj.ForgettingFactor = 0.99F;
   localDW->obj.isSetupComplete  = false;
   localDW->obj.isInitialized    = 1;
   localDW->obj.NumChannels      = 1;
   localDW->gobj_0.isInitialized = 0;
   flag                          = (localDW->gobj_0.isInitialized == 1);
   if (flag)
   {
      localDW->gobj_0.TunablePropsChanged = true;
   }

   localDW->gobj_0.ForgettingFactor = localDW->obj.ForgettingFactor;
   localDW->obj.pStatistic          = &localDW->gobj_0;
   localDW->obj.isSetupComplete     = true;
   localDW->obj.TunablePropsChanged = false;

   /* End of Start for MATLABSystem: '<S10>/Moving Average' */
}

/* Output and update for referenced model: 'ABS_TCS_Algorithm' */
void ABS_TCS_Algorithm(const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FL, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FR,
                       const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RL, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RR,
                       const uint8_T *rtu_VsVCAN_u8_WhlSpin_FL, const uint8_T *rtu_VsVCAN_u8_WhlSpin_FR,
                       const uint8_T *rtu_VsVCAN_u8_WhlSpin_RL, const uint8_T *rtu_VsVCAN_u8_WhlSpin_RR,
                       const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_FL_QF, const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_FR_QF,
                       const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_RL_QF, const enum_quality_factor_T *rtu_VeVCAN_WhlSpd_RR_QF,
                       const real32_T *rtu_VsVSE_rad_RoadWhlAngle_Fornt, const real32_T *rtu_VsVSE_rad_RoadWhlAngle_Rear,
                       const real32_T *rtu_KsVSE_m_TrackWidth_Front, const real32_T *rtu_KsVSE_m_TrackWidth_Rear,
                       const boolean_T *rtu_VsVCAN_b_ABSActive, const boolean_T *rtu_VsVCAN_b_ASRActive,
                       const real32_T *rtu_VsVCAN_mps2_RawLongAccel, const enum_quality_factor_T *rtu_VeVCAN_IMU_Ax_QF,
                       const uint8_T *rtu_VsVCAN_u8_GearBsdReverseStat, const real32_T *rtu_VsVSE_rps_CompYawRateFilt,
                       const real32_T *rtu_VsVCAN_s_ModelExecutionTime, const uint64_T *rtu_VsVCAN_u64_SystemTime,
                       real32_T *rty_VsVSE_mps_WhlOdoVehSpeedFromABSTCS, real32_T *rty_VsVSE_mps_WhlOdoVehAxFromABSTCS,
                       uint8_T *rty_VsVSE_u8_ABS_Status, boolean_T *rty_VsVSE_b_ASR_Status,
                       enum_quality_factor_T *rty_VeVSE_EstimatedVxFromABSTCS_QF,
                       enum_quality_factor_T *rty_VeVSE_EstimatedAxFromABSTCS_QF,
                       enum_accuracy_level_wheelodo_T *rty_VeVSE_EstimatedVxFromABSTCS_AccLvl,
                       enum_accuracy_level_wheelodo_T *rty_VeVSE_EstimatedAxFromABSTCS_AccLvl, DW_ABS_TCS_Algorithm_f_T *localDW)
{
   /* local block i/o variables */
   boolean_T rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0[4];
   boolean_T rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0[5];
   boolean_T rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n[5];
   boolean_T rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0_n[4];

   /* local scratch DWork variables */
   int32_T ForEach_itr;
   int32_T ForEach_itr_e;
   int32_T ForEach_itr_c;
   int32_T ForEach_itr_l;
   int32_T nonZeroCount;
   real32_T rtb_AX[2];
   real32_T rtb_Transpose[4];
   real32_T rtb_Abs_p;
   real32_T rtb_Divide_g;
   real32_T rtb_VsVSE_mps_SpeedUnderABS;
   uint8_T rtb_Switch2;
   real32_T rtb_VsVSE_mps_MeanCloserWhls;
   real32_T rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[4];
   boolean_T rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[5];
   boolean_T rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[5];
   real32_T rtb_Output_Vector[4];
   real32_T rtb_Init[2];
   enum_quality_factor_T rtb_VeVSE_CorrecrDeltaSysTimeQF;
   real32_T rtb_VsVSE_mps_TransWhlLinSpd_RR;
   real32_T rtb_VsVSE_mps_TransWhlLinSpd_RL;
   real32_T rtb_VsVSE_mps_TransWhlLinSpd_FR;
   real32_T rtb_VsVSE_mps_TransWhlLinSpd_FL;
   real32_T rtb_Init_f;
   uint8_T rtb_DataTypeConversion_i;
   uint8_T rtb_SwitchToMeasAxUnderASR_u8;
   uint8_T rtb_SwitchToMeasAxUnderABSAndBraking_u8;
   real32_T rtb_avgResult_n;
   real32_T rtb_delta_t;
   real32_T rtb_VsVCAN_mps_MeanWheelLinSpd;
   boolean_T rtb_veh_reverse_status;
   real32_T rtb_VsVSE_KFState_Vx;
   real32_T rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[4];
   int8_T rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0[4];
   real32_T tmpForInput[2];
   real32_T rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[4];
   int8_T rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0[4];
   boolean_T rtb_ASRStatus_bool_bs;
   boolean_T rtb_ASRStatus_bool_j;
   boolean_T rtb_ASRStatus_bool_l3;
   boolean_T rtb_ASRStatus_bool_l;
   boolean_T rtb_RelationalOperator2;
   boolean_T rtb_RelationalOperator1;
   boolean_T rtb_RelationalOperator;
   uint32_T qY;
   uint128m_T tmp;
   uint128m_T tmp_0;
   uint192m_T tmp_1;
   uint192m_T tmp_2;
   uint128m_T tmp_3;
   int128m_T tmp_4;
   int128m_T tmp_5;
   uint128m_T tmp_6;
   uint128m_T tmp_7;
   int128m_T tmp_8;
   boolean_T rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp;
   boolean_T rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0;
   boolean_T rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp;

   /* Sum: '<S5>/Add' incorporates:
    *  MATLAB Function: '<S7>/MATLAB Function2'
    */
   rtb_avgResult_n = (((*rtu_VsVCAN_mps_WheelLinSpd_FL) + (*rtu_VsVCAN_mps_WheelLinSpd_FR)) + (*rtu_VsVCAN_mps_WheelLinSpd_RL)) +
                     (*rtu_VsVCAN_mps_WheelLinSpd_RR);

   /* Product: '<S5>/Divide' incorporates:
    *  Constant: '<S5>/Constant'
    *  Sum: '<S5>/Add'
    */
   rtb_VsVCAN_mps_MeanWheelLinSpd = rtb_avgResult_n / 4.0F;

   /* MATLAB Function: '<S6>/MATLAB Function' */
   rtb_veh_reverse_status = false;
   if (((((((int32_T)((((int32_T)(*rtu_VsVCAN_u8_WhlSpin_FL)) == 2) ? 1 : 0)) +
           ((int32_T)((((int32_T)(*rtu_VsVCAN_u8_WhlSpin_FR)) == 2) ? 1 : 0))) +
          ((int32_T)((((int32_T)(*rtu_VsVCAN_u8_WhlSpin_RL)) == 2) ? 1 : 0))) +
         ((int32_T)((((int32_T)(*rtu_VsVCAN_u8_WhlSpin_RR)) == 2) ? 1 : 0))) >= 2) &&
       (fabsf(rtb_VsVCAN_mps_MeanWheelLinSpd) > 1.0E-6F))
   {
      rtb_veh_reverse_status = true;
   }
   else
   {
      if ((fabsf(rtb_VsVCAN_mps_MeanWheelLinSpd) < 1.0E-6F) && (((int32_T)(*rtu_VsVCAN_u8_GearBsdReverseStat)) == 1))
      {
         rtb_veh_reverse_status = true;
      }
   }

   /* End of MATLAB Function: '<S6>/MATLAB Function' */

   /* If: '<S9>/If' */
   if (rtb_veh_reverse_status)
   {
      /* Outputs for IfAction SubSystem: '<S9>/wheel_speed_transformation_when_vehicle_is_in_reverse' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* Product: '<S182>/Divide' incorporates:
       *  Constant: '<S182>/Constant'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_RR = (*rtu_KsVSE_m_TrackWidth_Front) / 2.0F;

      /* Trigonometry: '<S182>/Cos' */
      rtb_VsVSE_KFState_Vx = cosf(*rtu_VsVSE_rad_RoadWhlAngle_Fornt);

      /* Sum: '<S182>/Add' incorporates:
       *  Product: '<S182>/Multiply'
       *  Product: '<S182>/Multiply1'
       *  Trigonometry: '<S182>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_FL = ((*rtu_VsVCAN_mps_WheelLinSpd_FL) * rtb_VsVSE_KFState_Vx) +
                                        (rtb_VsVSE_mps_TransWhlLinSpd_RR * (*rtu_VsVSE_rps_CompYawRateFilt));

      /* Sum: '<S182>/Add1' incorporates:
       *  Product: '<S182>/Multiply2'
       *  Product: '<S182>/Multiply3'
       *  Trigonometry: '<S182>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_FR = ((*rtu_VsVCAN_mps_WheelLinSpd_FR) * rtb_VsVSE_KFState_Vx) -
                                        (rtb_VsVSE_mps_TransWhlLinSpd_RR * (*rtu_VsVSE_rps_CompYawRateFilt));

      /* Product: '<S183>/Divide' incorporates:
       *  Constant: '<S183>/Constant'
       */
      rtb_VsVSE_KFState_Vx = (*rtu_KsVSE_m_TrackWidth_Rear) / 2.0F;

      /* Trigonometry: '<S183>/Cos' */
      rtb_VsVSE_mps_TransWhlLinSpd_RR = cosf(*rtu_VsVSE_rad_RoadWhlAngle_Rear);

      /* Sum: '<S183>/Add' incorporates:
       *  Product: '<S183>/Multiply'
       *  Product: '<S183>/Multiply1'
       *  Trigonometry: '<S183>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_RL = ((*rtu_VsVCAN_mps_WheelLinSpd_RL) * rtb_VsVSE_mps_TransWhlLinSpd_RR) +
                                        (rtb_VsVSE_KFState_Vx * (*rtu_VsVSE_rps_CompYawRateFilt));

      /* Sum: '<S183>/Add1' incorporates:
       *  Product: '<S183>/Multiply2'
       *  Product: '<S183>/Multiply3'
       *  Trigonometry: '<S183>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_RR = ((*rtu_VsVCAN_mps_WheelLinSpd_RR) * rtb_VsVSE_mps_TransWhlLinSpd_RR) -
                                        (rtb_VsVSE_KFState_Vx * (*rtu_VsVSE_rps_CompYawRateFilt));

      /* End of Outputs for SubSystem: '<S9>/wheel_speed_transformation_when_vehicle_is_in_reverse' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S9>/wheel_speed_transformation_when_vehicle_is_not_in_reverse' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* Trigonometry: '<S184>/Cos' */
      rtb_VsVSE_mps_TransWhlLinSpd_FR = cosf(*rtu_VsVSE_rad_RoadWhlAngle_Fornt);

      /* Product: '<S184>/Multiply1' incorporates:
       *  Constant: '<S184>/Constant'
       *  Product: '<S184>/Divide'
       *  Product: '<S184>/Multiply3'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_RL = -(((*rtu_KsVSE_m_TrackWidth_Front) / 2.0F) * (*rtu_VsVSE_rps_CompYawRateFilt));

      /* Sum: '<S184>/Add' incorporates:
       *  Product: '<S184>/Multiply'
       *  Product: '<S184>/Multiply1'
       *  Trigonometry: '<S184>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_FL =
         ((*rtu_VsVCAN_mps_WheelLinSpd_FL) * rtb_VsVSE_mps_TransWhlLinSpd_FR) + rtb_VsVSE_mps_TransWhlLinSpd_RL;

      /* Sum: '<S184>/Add1' incorporates:
       *  Product: '<S184>/Multiply2'
       *  Trigonometry: '<S184>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_FR =
         ((*rtu_VsVCAN_mps_WheelLinSpd_FR) * rtb_VsVSE_mps_TransWhlLinSpd_FR) - rtb_VsVSE_mps_TransWhlLinSpd_RL;

      /* Trigonometry: '<S185>/Cos' */
      rtb_VsVSE_mps_TransWhlLinSpd_RR = cosf(*rtu_VsVSE_rad_RoadWhlAngle_Rear);

      /* Product: '<S185>/Multiply1' incorporates:
       *  Constant: '<S185>/Constant'
       *  Product: '<S185>/Divide'
       *  Product: '<S185>/Multiply3'
       */
      rtb_VsVSE_KFState_Vx = -(((*rtu_KsVSE_m_TrackWidth_Rear) / 2.0F) * (*rtu_VsVSE_rps_CompYawRateFilt));

      /* Sum: '<S185>/Add' incorporates:
       *  Product: '<S185>/Multiply'
       *  Product: '<S185>/Multiply1'
       *  Trigonometry: '<S185>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_RL =
         ((*rtu_VsVCAN_mps_WheelLinSpd_RL) * rtb_VsVSE_mps_TransWhlLinSpd_RR) + rtb_VsVSE_KFState_Vx;

      /* Sum: '<S185>/Add1' incorporates:
       *  Product: '<S185>/Multiply2'
       *  Trigonometry: '<S185>/Cos'
       */
      rtb_VsVSE_mps_TransWhlLinSpd_RR =
         ((*rtu_VsVCAN_mps_WheelLinSpd_RR) * rtb_VsVSE_mps_TransWhlLinSpd_RR) - rtb_VsVSE_KFState_Vx;

      /* End of Outputs for SubSystem: '<S9>/wheel_speed_transformation_when_vehicle_is_not_in_reverse' */
   }

   /* End of If: '<S9>/If' */

   /* Switch: '<S178>/when_stationary_make_the_whl_spd_is_zero' incorporates:
    *  Constant: '<S178>/Constant'
    *  Constant: '<S186>/Constant'
    *  RelationalOperator: '<S186>/Compare'
    */
   if ((*rtu_VsVCAN_mps_WheelLinSpd_FL) <= 2.22044605E-16F)
   {
      rtb_VsVSE_mps_TransWhlLinSpd_FL = 0.0F;
   }

   /* End of Switch: '<S178>/when_stationary_make_the_whl_spd_is_zero' */

   /* Switch: '<S179>/when_stationary_make_the_whl_spd_is_zero' incorporates:
    *  Constant: '<S179>/Constant'
    *  Constant: '<S187>/Constant'
    *  RelationalOperator: '<S187>/Compare'
    */
   if ((*rtu_VsVCAN_mps_WheelLinSpd_FR) <= 2.22044605E-16F)
   {
      rtb_VsVSE_mps_TransWhlLinSpd_FR = 0.0F;
   }

   /* End of Switch: '<S179>/when_stationary_make_the_whl_spd_is_zero' */

   /* Switch: '<S180>/when_stationary_make_the_whl_spd_is_zero' incorporates:
    *  Constant: '<S180>/Constant'
    *  Constant: '<S188>/Constant'
    *  RelationalOperator: '<S188>/Compare'
    */
   if ((*rtu_VsVCAN_mps_WheelLinSpd_RL) <= 2.22044605E-16F)
   {
      rtb_VsVSE_mps_TransWhlLinSpd_RL = 0.0F;
   }

   /* End of Switch: '<S180>/when_stationary_make_the_whl_spd_is_zero' */

   /* Switch: '<S181>/when_stationary_make_the_whl_spd_is_zero' incorporates:
    *  Constant: '<S181>/Constant'
    *  Constant: '<S189>/Constant'
    *  RelationalOperator: '<S189>/Compare'
    */
   if ((*rtu_VsVCAN_mps_WheelLinSpd_RR) <= 2.22044605E-16F)
   {
      rtb_VsVSE_mps_TransWhlLinSpd_RR = 0.0F;
   }

   /* End of Switch: '<S181>/when_stationary_make_the_whl_spd_is_zero' */

   /* MATLAB Function: '<S79>/MATLAB Function' */
   ABS_TCS_Algorithm_MATLABFunction(rtb_VsVSE_mps_TransWhlLinSpd_FL, rtb_VsVSE_mps_TransWhlLinSpd_FR,
                                    rtb_VsVSE_mps_TransWhlLinSpd_RL, rtb_VsVSE_mps_TransWhlLinSpd_RR, rtb_Output_Vector);

   /* SignalConversion: '<S89>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport1' incorporates:
    *  Constant: '<S79>/Maximal_Set_Special_Threshold'
    *  RelationalOperator: '<S111>/LessThanOrEqual'
    *  RelationalOperator: '<S111>/LessThanOrEqual1'
    *  RelationalOperator: '<S111>/LessThanOrEqual3'
    *  Sum: '<S111>/Add'
    *  Sum: '<S111>/Add1'
    *  Sum: '<S111>/Add3'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[0] = ((rtb_Output_Vector[0] - rtb_Output_Vector[3]) <= 0.1F);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[1] = ((rtb_Output_Vector[0] - rtb_Output_Vector[2]) <= 0.1F);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[2] = ((rtb_Output_Vector[1] - rtb_Output_Vector[3]) <= 0.1F);

   /* Sum: '<S111>/Add2' incorporates:
    *  Sum: '<S84>/Add2'
    */
   rtb_VsVSE_mps_SpeedUnderABS = rtb_Output_Vector[0] - rtb_Output_Vector[1];

   /* SignalConversion: '<S89>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport1' incorporates:
    *  Constant: '<S79>/Maximal_Set_Special_Threshold'
    *  RelationalOperator: '<S111>/LessThanOrEqual2'
    *  RelationalOperator: '<S111>/LessThanOrEqual4'
    *  Sum: '<S111>/Add2'
    *  Sum: '<S111>/Add4'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[3] = (rtb_VsVSE_mps_SpeedUnderABS <= 0.1F);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[4] = ((rtb_Output_Vector[1] - rtb_Output_Vector[2]) <= 0.1F);

   /* Delay: '<S4>/Resettable Delay' */
   if (((int32_T)localDW->icLoad) != 0)
   {
      localDW->ResettableDelay_DSTATE = *rtu_VsVCAN_u64_SystemTime;
   }

   /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
    *  Delay: '<S4>/Resettable Delay'
    */
   uLong2MultiWord_Aptiv(*rtu_VsVCAN_u64_SystemTime, &tmp_7.chunks[0U], 2);
   MultiWordUnsignedWrap_Aptiv(&tmp_7.chunks[0U], 2, 63U, &tmp_6.chunks[0U]);
   uMultiWord2MultiWord_Aptiv(&tmp_6.chunks[0U], 2, &tmp_5.chunks[0U], 2);
   uLong2MultiWord_Aptiv(localDW->ResettableDelay_DSTATE, &tmp_7.chunks[0U], 2);
   MultiWordUnsignedWrap_Aptiv(&tmp_7.chunks[0U], 2, 63U, &tmp_6.chunks[0U]);
   uMultiWord2MultiWord_Aptiv(&tmp_6.chunks[0U], 2, &tmp_8.chunks[0U], 2);
   MultiWordSub_Aptiv(&tmp_5.chunks[0U], &tmp_8.chunks[0U], &tmp_4.chunks[0U], 2);
   sMultiWord2uMultiWordSat_Aptiv(&tmp_4.chunks[0U], 2, &tmp_3.chunks[0U], 2);
   uMultiWord2MultiWord_Aptiv(&tmp_3.chunks[0U], 2, &tmp_2.chunks[0U], 3);
   uMultiWordShl_Aptiv(&tmp_2.chunks[0U], 3, 63U, &tmp_1.chunks[0U], 3);
   uMultiWord2uMultiWordSat_Aptiv(&tmp_1.chunks[0U], 3, &tmp_0.chunks[0U], 2);
   uMultiWordShr_Aptiv(&tmp_0.chunks[0U], 2, 63U, &tmp.chunks[0U], 2);
   rtb_delta_t = uMultiWordSingle_Aptiv(&tmp.chunks[0U], 2, 0) / 1.0E-6F;

   /* If: '<S4>/If' incorporates:
    *  Constant: '<S4>/Constant'
    *  Inport: '<S74>/VsVCAN_s_DefaultDeltaSystemTime'
    */
   if ((rtb_delta_t <= 0.005F) || (rtb_delta_t >= 0.08F))
   {
      /* Outputs for IfAction SubSystem: '<S4>/calc_corrected_delta_sys_time_under_extreme_cases' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      /* SignalConversion: '<S74>/OutportBuffer_InsertedFor_VeVSE_CorrecrDeltaSysTimeQF_at_inport_0' incorporates:
       *  Constant: '<S74>/Constant'
       */
      rtb_VeVSE_CorrecrDeltaSysTimeQF = NOT_ACCURATED;
      rtb_delta_t                     = 0.01F;

      /* End of Outputs for SubSystem: '<S4>/calc_corrected_delta_sys_time_under_extreme_cases' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S4>/calc_corrected_delta_sys_time_under_normal_cases' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      /* SignalConversion: '<S75>/OutportBuffer_InsertedFor_VeVSE_CorrecrDeltaSysTimeQF_at_inport_0' incorporates:
       *  Constant: '<S75>/Constant'
       */
      rtb_VeVSE_CorrecrDeltaSysTimeQF = ACCURATED;

      /* End of Outputs for SubSystem: '<S4>/calc_corrected_delta_sys_time_under_normal_cases' */
   }

   /* End of If: '<S4>/If' */

   /* Outputs for Iterator SubSystem: '<S99>/calc_rate_from_the_sorted_spd' */
   /* Constant: '<S79>/Constant4' */
   ABS_TCS_Algorithm_calc_rate_from_the_sorted_spd(4, rtb_Output_Vector, rtb_delta_t, 15.0F,
                                                   rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0_n,
                                                   localDW->calc_rate_from_the_sorted_spd);

   /* End of Outputs for SubSystem: '<S99>/calc_rate_from_the_sorted_spd' */

   /* SignalConversion: '<S120>/TmpSignal ConversionAtcalc_speed_under_ABSInport2' */
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[0] = rtb_VsVSE_mps_TransWhlLinSpd_FL;
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[1] = rtb_VsVSE_mps_TransWhlLinSpd_FR;
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[2] = rtb_VsVSE_mps_TransWhlLinSpd_RL;
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[3] = rtb_VsVSE_mps_TransWhlLinSpd_RR;

   /* SignalConversion: '<S79>/TmpSignal ConversionAtcalc_speed_under_ABSInport2' incorporates:
    *  SignalConversion: '<S79>/TmpSignal ConversionAtlogic_to_detect_if_indvidual_whls_are_under_ABSInport1'
    */
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[0] = localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[0];
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[1] = localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[1];
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[2] = localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[2];
   localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[3] = localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[3];

   /* Outputs for Iterator SubSystem: '<S79>/calc_rate_from_the_unsorted_spd' incorporates:
    *  ForEach: '<S87>/For Each'
    */
   for (ForEach_itr_l = 0; ForEach_itr_l < 4; ForEach_itr_l++)
   {
      /* Sum: '<S110>/Add1' incorporates:
       *  ForEachSliceSelector: '<S87>/ImpSel_InsertedFor_VaVSE_mps_TransFiltWhlLinSpd_at_outport_0'
       *  SignalConversion: '<S79>/TmpSignal ConversionAtcalc_rate_from_the_unsorted_spdInport1'
       *  UnitDelay: '<S110>/Unit Delay'
       */
      rtb_VsVSE_KFState_Vx = localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[ForEach_itr_l] -
                             localDW->CoreSubsys[ForEach_itr_l].UnitDelay_DSTATE;

      /* Update for UnitDelay: '<S110>/Unit Delay' incorporates:
       *  ForEachSliceSelector: '<S87>/ImpSel_InsertedFor_VaVSE_mps_TransFiltWhlLinSpd_at_outport_0'
       *  SignalConversion: '<S79>/TmpSignal ConversionAtcalc_rate_from_the_unsorted_spdInport1'
       */
      localDW->CoreSubsys[ForEach_itr_l].UnitDelay_DSTATE =
         localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[ForEach_itr_l];

      /* ForEachSliceAssignment: '<S87>/ImpAsg_InsertedFor_VaVSE_mps2_WhlSpdBsdAccel_at_inport_0' incorporates:
       *  Product: '<S110>/Divide'
       */
      rtb_Transpose[ForEach_itr_l] = rtb_VsVSE_KFState_Vx / rtb_delta_t;
   }

   /* End of Outputs for SubSystem: '<S79>/calc_rate_from_the_unsorted_spd' */

   /* Outputs for Iterator SubSystem: '<S79>/logic_to_detect_if_indvidual_whls_are_under_ABS' incorporates:
    *  ForEach: '<S90>/For Each'
    */
   for (ForEach_itr_e = 0; ForEach_itr_e < 4; ForEach_itr_e++)
   {
      /* ForEachSliceAssignment: '<S90>/ImpAsg_InsertedFor_VaVSE_b_IsWhlUnderABS_at_inport_0' incorporates:
       *  Abs: '<S119>/Abs'
       *  Constant: '<S79>/Constant2'
       *  Constant: '<S79>/Constant3'
       *  ForEachSliceSelector: '<S90>/ImpSel_InsertedFor_VaVSE_mps2_WhlSpdBsdAccel_at_outport_0'
       *  ForEachSliceSelector: '<S90>/ImpSel_InsertedFor_VaVSE_mps_TransFiltWhlLinSpd_at_outport_0'
       *  Logic: '<S119>/Logical Operator'
       *  RelationalOperator: '<S119>/GreaterThan'
       *  RelationalOperator: '<S119>/GreaterThan1'
       *  SignalConversion: '<S79>/TmpSignal ConversionAtlogic_to_detect_if_indvidual_whls_are_under_ABSInport1'
       *  Sum: '<S119>/Add'
       */
      localDW->ImpAsg_InsertedFor_VaVSE_b_IsWhlUnderABS_at_inport_0[ForEach_itr_e] =
         (((localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[ForEach_itr_e] - rtb_Output_Vector[0]) <= -0.2F) ||
          (fabsf(rtb_Transpose[ForEach_itr_e]) > 15.0F));
   }

   /* End of Outputs for SubSystem: '<S79>/logic_to_detect_if_indvidual_whls_are_under_ABS' */

   /* Outputs for Iterator SubSystem: '<S79>/calc_speed_under_ABS' incorporates:
    *  ForEach: '<S88>/For Each'
    */
   for (ForEach_itr_c = 0; ForEach_itr_c < 4; ForEach_itr_c++)
   {
      /* ForEachSliceAssignment: '<S88>/ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0' incorporates:
       *  ForEachSliceSelector: '<S88>/ImpSel_InsertedFor_VaVSE_b_IsWhlUnderABS_at_outport_0'
       *  RelationalOperator: '<S88>/GreaterThan'
       */
      rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0[ForEach_itr_c] =
         (int8_T)((!localDW->ImpAsg_InsertedFor_VaVSE_b_IsWhlUnderABS_at_inport_0[ForEach_itr_c]) ? 1 : 0);

      /* Switch: '<S88>/Switch' incorporates:
       *  ForEachSliceSelector: '<S88>/ImpSel_InsertedFor_VaVSE_b_IsWhlUnderABS_at_outport_0'
       *  RelationalOperator: '<S88>/GreaterThan'
       */
      if (localDW->ImpAsg_InsertedFor_VaVSE_b_IsWhlUnderABS_at_inport_0[ForEach_itr_c])
      {
         /* ForEachSliceAssignment: '<S88>/ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0' incorporates:
          *  Constant: '<S88>/Constant1'
          */
         rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[ForEach_itr_c] = 0.0F;
      }
      else
      {
         /* ForEachSliceAssignment: '<S88>/ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0' incorporates:
          *  ForEachSliceSelector: '<S88>/ImpSel_InsertedFor_VsVSE_mps_TransFiltWhlLinSpd_at_outport_0'
          */
         rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[ForEach_itr_c] =
            localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2_h[ForEach_itr_c];
      }

      /* End of Switch: '<S88>/Switch' */
   }

   /* End of Outputs for SubSystem: '<S79>/calc_speed_under_ABS' */

   /* Sum: '<S84>/Add' */
   nonZeroCount = (int32_T)((uint32_T)(((((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0[0]) +
                                         ((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0[1])) +
                                        ((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0[2])) +
                                       ((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoABS_at_inport_0[3])));

   /* Chart: '<S82>/Debouncer' incorporates:
    *  Constant: '<S84>/Constant1'
    *  Logic: '<S79>/Logical Operator2'
    *  Logic: '<S84>/Logical Operator2'
    *  RelationalOperator: '<S84>/Equal1'
    *  Sum: '<S84>/Add'
    */
   ABS_TCS_Algorithm_Debouncer((((int32_T)((uint8_T)nonZeroCount)) != 4) || (*rtu_VsVCAN_b_ABSActive), &localDW->Output_f,
                               &localDW->Fault_k, &localDW->sf_Debouncer, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Logic: '<S133>/Logical Operator1' incorporates:
    *  Abs: '<S133>/Abs'
    *  Abs: '<S133>/Abs1'
    *  Abs: '<S133>/Abs2'
    *  Constant: '<S121>/Constant2'
    *  Constant: '<S133>/slip_thresh'
    *  Logic: '<S133>/Logical Operator'
    *  Product: '<S133>/Divide'
    *  RelationalOperator: '<S133>/GreaterThan'
    *  RelationalOperator: '<S133>/GreaterThan1'
    *  RelationalOperator: '<S133>/GreaterThan2'
    *  Sum: '<S133>/Add1'
    *  Sum: '<S133>/Add2'
    *  Sum: '<S133>/Add3'
    *  UnitDelay: '<S133>/Unit Delay'
    */
   rtb_ASRStatus_bool_l = (((fabsf(rtb_VsVSE_mps_TransWhlLinSpd_FL - rtb_VsVSE_mps_TransWhlLinSpd_RL) > 0.4F) &&
                            (fabsf(rtb_VsVSE_mps_TransWhlLinSpd_FL - rtb_VsVSE_mps_TransWhlLinSpd_RR) > 0.4F)) ||
                           (fabsf((rtb_VsVSE_mps_TransWhlLinSpd_FL - localDW->UnitDelay_DSTATE) / rtb_delta_t) > 14.0F));

   /* Logic: '<S131>/Logical Operator1' incorporates:
    *  Abs: '<S131>/Abs'
    *  Abs: '<S131>/Abs1'
    *  Abs: '<S131>/Abs2'
    *  Constant: '<S121>/Constant2'
    *  Constant: '<S131>/slip_thresh'
    *  Logic: '<S131>/Logical Operator'
    *  Product: '<S131>/Divide'
    *  RelationalOperator: '<S131>/GreaterThan'
    *  RelationalOperator: '<S131>/GreaterThan1'
    *  RelationalOperator: '<S131>/GreaterThan2'
    *  Sum: '<S131>/Add1'
    *  Sum: '<S131>/Add2'
    *  Sum: '<S131>/Add3'
    *  UnitDelay: '<S131>/Unit Delay'
    */
   rtb_ASRStatus_bool_l3 = (((fabsf(rtb_VsVSE_mps_TransWhlLinSpd_FR - rtb_VsVSE_mps_TransWhlLinSpd_RL) > 0.4F) &&
                             (fabsf(rtb_VsVSE_mps_TransWhlLinSpd_FR - rtb_VsVSE_mps_TransWhlLinSpd_RR) > 0.4F)) ||
                            (fabsf((rtb_VsVSE_mps_TransWhlLinSpd_FR - localDW->UnitDelay_DSTATE_f) / rtb_delta_t) > 14.0F));

   /* Logic: '<S134>/Logical Operator1' incorporates:
    *  Abs: '<S134>/Abs'
    *  Abs: '<S134>/Abs1'
    *  Abs: '<S134>/Abs2'
    *  Constant: '<S121>/Constant2'
    *  Constant: '<S134>/slip_thresh'
    *  Logic: '<S134>/Logical Operator'
    *  Product: '<S134>/Divide'
    *  RelationalOperator: '<S134>/GreaterThan'
    *  RelationalOperator: '<S134>/GreaterThan1'
    *  RelationalOperator: '<S134>/GreaterThan2'
    *  Sum: '<S134>/Add1'
    *  Sum: '<S134>/Add2'
    *  Sum: '<S134>/Add3'
    *  UnitDelay: '<S134>/Unit Delay'
    */
   rtb_ASRStatus_bool_j = (((fabsf(rtb_VsVSE_mps_TransWhlLinSpd_RL - rtb_VsVSE_mps_TransWhlLinSpd_FL) > 0.4F) &&
                            (fabsf(rtb_VsVSE_mps_TransWhlLinSpd_RL - rtb_VsVSE_mps_TransWhlLinSpd_FR) > 0.4F)) ||
                           (fabsf((rtb_VsVSE_mps_TransWhlLinSpd_RL - localDW->UnitDelay_DSTATE_m) / rtb_delta_t) > 14.0F));

   /* Logic: '<S132>/Logical Operator1' incorporates:
    *  Abs: '<S132>/Abs'
    *  Abs: '<S132>/Abs1'
    *  Abs: '<S132>/Abs2'
    *  Constant: '<S121>/Constant2'
    *  Constant: '<S132>/slip_thresh'
    *  Logic: '<S132>/Logical Operator'
    *  Product: '<S132>/Divide'
    *  RelationalOperator: '<S132>/GreaterThan'
    *  RelationalOperator: '<S132>/GreaterThan1'
    *  RelationalOperator: '<S132>/GreaterThan2'
    *  Sum: '<S132>/Add1'
    *  Sum: '<S132>/Add2'
    *  Sum: '<S132>/Add3'
    *  UnitDelay: '<S132>/Unit Delay'
    */
   rtb_ASRStatus_bool_bs = (((fabsf(rtb_VsVSE_mps_TransWhlLinSpd_RR - rtb_VsVSE_mps_TransWhlLinSpd_FL) > 0.4F) &&
                             (fabsf(rtb_VsVSE_mps_TransWhlLinSpd_RR - rtb_VsVSE_mps_TransWhlLinSpd_FR) > 0.4F)) ||
                            (fabsf((rtb_VsVSE_mps_TransWhlLinSpd_RR - localDW->UnitDelay_DSTATE_n) / rtb_delta_t) > 14.0F));

   /* Product: '<S143>/Divide' incorporates:
    *  Constant: '<S143>/Constant'
    *  Sum: '<S143>/Add1'
    *  UnitDelay: '<S143>/Unit Delay'
    */
   rtb_Init_f = (rtb_VsVSE_mps_TransWhlLinSpd_FL - localDW->UnitDelay_DSTATE_j) / 0.01F;

   /* DeadZone: '<S136>/Dead Zone_FL' */
   if (rtb_Init_f > 0.5F)
   {
      rtb_Init_f -= 0.5F;
   }
   else if (rtb_Init_f >= -0.5F)
   {
      rtb_Init_f = 0.0F;
   }
   else
   {
      rtb_Init_f -= -0.5F;
   }

   /* End of DeadZone: '<S136>/Dead Zone_FL' */

   /* RelationalOperator: '<S136>/Relational Operator' incorporates:
    *  Constant: '<S136>/Constant'
    */
   rtb_RelationalOperator = (rtb_Init_f > 0.01F);

   /* Product: '<S140>/Divide' incorporates:
    *  Constant: '<S140>/Constant'
    *  Sum: '<S140>/Add1'
    *  UnitDelay: '<S140>/Unit Delay'
    */
   rtb_Init_f = (rtb_VsVSE_mps_TransWhlLinSpd_FR - localDW->UnitDelay_DSTATE_i) / 0.01F;

   /* DeadZone: '<S136>/Dead Zone_FR' */
   if (rtb_Init_f > 0.5F)
   {
      rtb_Init_f -= 0.5F;
   }
   else if (rtb_Init_f >= -0.5F)
   {
      rtb_Init_f = 0.0F;
   }
   else
   {
      rtb_Init_f -= -0.5F;
   }

   /* End of DeadZone: '<S136>/Dead Zone_FR' */

   /* RelationalOperator: '<S136>/Relational Operator1' incorporates:
    *  Constant: '<S136>/Constant'
    */
   rtb_RelationalOperator1 = (rtb_Init_f > 0.01F);

   /* Product: '<S141>/Divide' incorporates:
    *  Constant: '<S141>/Constant'
    *  Sum: '<S141>/Add1'
    *  UnitDelay: '<S141>/Unit Delay'
    */
   rtb_Init_f = (rtb_VsVSE_mps_TransWhlLinSpd_RL - localDW->UnitDelay_DSTATE_e) / 0.01F;

   /* DeadZone: '<S136>/Dead Zone_RL' */
   if (rtb_Init_f > 0.5F)
   {
      rtb_Init_f -= 0.5F;
   }
   else if (rtb_Init_f >= -0.5F)
   {
      rtb_Init_f = 0.0F;
   }
   else
   {
      rtb_Init_f -= -0.5F;
   }

   /* End of DeadZone: '<S136>/Dead Zone_RL' */

   /* RelationalOperator: '<S136>/Relational Operator2' incorporates:
    *  Constant: '<S136>/Constant'
    */
   rtb_RelationalOperator2 = (rtb_Init_f > 0.01F);

   /* Product: '<S142>/Divide' incorporates:
    *  Constant: '<S142>/Constant'
    *  Sum: '<S142>/Add1'
    *  UnitDelay: '<S142>/Unit Delay'
    */
   rtb_Init_f = (rtb_VsVSE_mps_TransWhlLinSpd_RR - localDW->UnitDelay_DSTATE_c) / 0.01F;

   /* DeadZone: '<S136>/Dead Zone_RR' */
   if (rtb_Init_f > 0.5F)
   {
      rtb_Init_f -= 0.5F;
   }
   else if (rtb_Init_f >= -0.5F)
   {
      rtb_Init_f = 0.0F;
   }
   else
   {
      rtb_Init_f -= -0.5F;
   }

   /* End of DeadZone: '<S136>/Dead Zone_RR' */

   /* MATLAB Function: '<S136>/whl_accel_function' incorporates:
    *  Constant: '<S136>/Constant'
    *  Logic: '<S136>/OR Logical Operator'
    *  RelationalOperator: '<S136>/Relational Operator3'
    *  UnitDelay: '<S136>/Accel_Counter'
    */
   if (((rtb_RelationalOperator || rtb_RelationalOperator1) || rtb_RelationalOperator2) || (rtb_Init_f > 0.01F))
   {
      localDW->Accel_Counter_DSTATE++;
   }
   else
   {
      localDW->Accel_Counter_DSTATE -= 0.5F;
   }

   if (localDW->Accel_Counter_DSTATE < 0.0F)
   {
      localDW->Accel_Counter_DSTATE = 0.0F;
   }

   if (localDW->Accel_Counter_DSTATE >= 100.0F)
   {
      localDW->Accel_Counter_DSTATE = 100.0F;
   }

   /* End of MATLAB Function: '<S136>/whl_accel_function' */

   /* Sum: '<S135>/Sum' */
   rtb_Init_f = rtb_VsVSE_mps_TransWhlLinSpd_FL - rtb_VsVSE_mps_TransWhlLinSpd_FR;

   /* Sum: '<S137>/EWMA_Sum' incorporates:
    *  Constant: '<S137>/Constant'
    *  Constant: '<S137>/Constant1'
    *  Product: '<S137>/Product'
    *  Product: '<S137>/Product1'
    *  UnitDelay: '<S137>/EWMA_Left'
    */
   localDW->EWMA_Left_DSTATE = (rtb_Init_f * 0.2F) + (0.8F * localDW->EWMA_Left_DSTATE);

   /* Sum: '<S137>/Sum1' incorporates:
    *  UnitDelay: '<S137>/EWMA_Left'
    */
   rtb_Init_f -= localDW->EWMA_Left_DSTATE;

   /* Sum: '<S137>/stnd_dev_left_wheels' incorporates:
    *  Constant: '<S137>/Constant2'
    *  Constant: '<S137>/Constant3'
    *  Product: '<S137>/Product2'
    *  Product: '<S137>/Product3'
    *  UnitDelay: '<S137>/EWVAR'
    */
   localDW->EWVAR_DSTATE = ((rtb_Init_f * rtb_Init_f) * 0.2F) + (0.8F * localDW->EWVAR_DSTATE);

   /* Sum: '<S135>/Sum1' */
   rtb_Divide_g = rtb_VsVSE_mps_TransWhlLinSpd_RL - rtb_VsVSE_mps_TransWhlLinSpd_RR;

   /* Sum: '<S138>/EWMA_Sum' incorporates:
    *  Constant: '<S138>/Constant'
    *  Constant: '<S138>/Constant1'
    *  Product: '<S138>/Product'
    *  Product: '<S138>/Product1'
    *  UnitDelay: '<S138>/EWMA_Left'
    */
   localDW->EWMA_Left_DSTATE_j = (rtb_Divide_g * 0.2F) + (0.8F * localDW->EWMA_Left_DSTATE_j);

   /* Sum: '<S138>/Sum1' incorporates:
    *  UnitDelay: '<S138>/EWMA_Left'
    */
   rtb_Divide_g -= localDW->EWMA_Left_DSTATE_j;

   /* Sum: '<S138>/stnd_dev_left_wheels' incorporates:
    *  Constant: '<S138>/Constant2'
    *  Constant: '<S138>/Constant3'
    *  Product: '<S138>/Product2'
    *  Product: '<S138>/Product3'
    *  UnitDelay: '<S138>/EWVAR'
    */
   localDW->EWVAR_DSTATE_c = ((rtb_Divide_g * rtb_Divide_g) * 0.2F) + (0.8F * localDW->EWVAR_DSTATE_c);

   /* MATLAB Function: '<S135>/whl_vel_std_dev_function' incorporates:
    *  Constant: '<S135>/Constant'
    *  Logic: '<S135>/OR Logical Operator'
    *  RelationalOperator: '<S135>/Relational Operator'
    *  RelationalOperator: '<S135>/Relational Operator1'
    *  UnitDelay: '<S135>/SD_Counter'
    *  UnitDelay: '<S137>/EWVAR'
    *  UnitDelay: '<S138>/EWVAR'
    */
   if ((localDW->EWVAR_DSTATE > 0.1F) || (localDW->EWVAR_DSTATE_c > 0.1F))
   {
      localDW->SD_Counter_DSTATE++;
   }
   else
   {
      localDW->SD_Counter_DSTATE -= 0.5F;
   }

   if (localDW->SD_Counter_DSTATE < 0.0F)
   {
      localDW->SD_Counter_DSTATE = 0.0F;
   }

   if (localDW->SD_Counter_DSTATE >= 100.0F)
   {
      localDW->SD_Counter_DSTATE = 100.0F;
   }

   /* End of MATLAB Function: '<S135>/whl_vel_std_dev_function' */

   /* If: '<S121>/If' incorporates:
    *  Chart: '<S122>/Debouncer'
    *  Constant: '<S121>/Constant'
    *  DataTypeConversion: '<S135>/Data Type Conversion1'
    *  DataTypeConversion: '<S136>/Data Type Conversion'
    *  Logic: '<S121>/Logical Operator'
    *  Logic: '<S121>/OR'
    *  RelationalOperator: '<S121>/GreaterThan1'
    *  RelationalOperator: '<S121>/GreaterThan2'
    *  UnitDelay: '<S135>/SD_Counter'
    *  UnitDelay: '<S136>/Accel_Counter'
    */
   ABS_TCS_Algorithm_Debouncer(
      (((((rtb_ASRStatus_bool_l || rtb_ASRStatus_bool_l3) || rtb_ASRStatus_bool_j) || rtb_ASRStatus_bool_bs) &&
        (((int32_T)((uint8_T)localDW->Accel_Counter_DSTATE)) >= 5)) &&
       (((int32_T)((uint8_T)localDW->SD_Counter_DSTATE)) >= 5)) ||
         (*rtu_VsVCAN_b_ASRActive),
      rty_VsVSE_b_ASR_Status, &localDW->Fault_h, &localDW->sf_Debouncer_jd, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S100>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0_n[0],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[0], &localDW->Fault_nj,
                               &localDW->sf_Debouncer_d, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S101>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0_n[1],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[1], &localDW->Fault_fo,
                               &localDW->sf_Debouncer_p, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S102>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0_n[2],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[2], &localDW->Fault_n,
                               &localDW->sf_Debouncer_c, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S103>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0_n[3],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[3], &localDW->Fault_g,
                               &localDW->sf_Debouncer_j, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Logic: '<S111>/Logical Operator6' incorporates:
    *  Logic: '<S111>/Logical Operator1'
    *  Logic: '<S111>/Logical Operator2'
    *  Logic: '<S111>/Logical Operator3'
    */
   rtb_RelationalOperator1 = !localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[1];
   rtb_RelationalOperator2 = !localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[2];
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp =
      ((!localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[0]) && rtb_RelationalOperator1);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp =
      (rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp && rtb_RelationalOperator2);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0 =
      !localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr[3];

   /* SignalConversion: '<S89>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport2' incorporates:
    *  Logic: '<S111>/Logical Operator6'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[0] =
      (rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp &&
       rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[1] =
      rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp;

   /* Logic: '<S111>/Logical Operator3' incorporates:
    *  Logic: '<S111>/Logical Operator4'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp = (rtb_RelationalOperator1 && rtb_RelationalOperator2);

   /* SignalConversion: '<S89>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport2' incorporates:
    *  Logic: '<S111>/Logical Operator3'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[2] =
      (rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp &&
       rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[3] =
      rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp;
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[4] =
      rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp;

   /* Outputs for Iterator SubSystem: '<S89>/Final_Check_For_Closer_Whl_Spd' */
   ABS_TCS_Algorithm_Final_Check_For_Closer_Whl_Spd(5, rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1,
                                                    rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2,
                                                    rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n);

   /* End of Outputs for SubSystem: '<S89>/Final_Check_For_Closer_Whl_Spd' */

   /* If: '<S89>/If' */
   if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n[0])
   {
      /* Outputs for IfAction SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario1'
       * incorporates: ActionPort: '<S113>/Action Port'
       */
      /* Product: '<S113>/Divide' incorporates:
       *  Constant: '<S113>/Constant'
       *  Sum: '<S113>/Add'
       */
      rtb_VsVSE_mps_MeanCloserWhls =
         (((rtb_Output_Vector[0] + rtb_Output_Vector[1]) + rtb_Output_Vector[2]) + rtb_Output_Vector[3]) / 4.0F;

      /* SignalConversion: '<S113>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S113>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario1' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n[1])
   {
      /* Outputs for IfAction SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario2'
       * incorporates: ActionPort: '<S114>/Action Port'
       */
      /* Product: '<S114>/Divide' incorporates:
       *  Constant: '<S114>/Constant'
       *  Sum: '<S114>/Add'
       */
      rtb_VsVSE_mps_MeanCloserWhls = ((rtb_Output_Vector[0] + rtb_Output_Vector[1]) + rtb_Output_Vector[2]) / 3.0F;

      /* SignalConversion: '<S114>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S114>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario2' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n[2])
   {
      /* Outputs for IfAction SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario4'
       * incorporates: ActionPort: '<S116>/Action Port'
       */
      /* Product: '<S116>/Divide' incorporates:
       *  Constant: '<S116>/Constant'
       *  Sum: '<S116>/Add'
       */
      rtb_VsVSE_mps_MeanCloserWhls = ((rtb_Output_Vector[1] + rtb_Output_Vector[2]) + rtb_Output_Vector[3]) / 3.0F;

      /* SignalConversion: '<S116>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S116>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario4' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n[3])
   {
      /* Outputs for IfAction SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario3'
       * incorporates: ActionPort: '<S115>/Action Port'
       */
      /* Product: '<S115>/Divide' incorporates:
       *  Constant: '<S115>/Constant'
       *  Sum: '<S115>/Add'
       */
      rtb_VsVSE_mps_MeanCloserWhls = (rtb_Output_Vector[0] + rtb_Output_Vector[1]) / 2.0F;

      /* SignalConversion: '<S115>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S115>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario3' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0_n[4])
   {
      /* Outputs for IfAction SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario5'
       * incorporates: ActionPort: '<S117>/Action Port'
       */
      /* Product: '<S117>/Divide' incorporates:
       *  Constant: '<S117>/Constant'
       *  Sum: '<S117>/Add'
       */
      rtb_VsVSE_mps_MeanCloserWhls = (rtb_Output_Vector[1] + rtb_Output_Vector[2]) / 2.0F;

      /* SignalConversion: '<S117>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S117>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario5' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario6'
       * incorporates: ActionPort: '<S118>/Action Port'
       */
      /* Product: '<S118>/Divide' incorporates:
       *  Constant: '<S118>/Constant'
       *  Sum: '<S118>/Add'
       */
      rtb_VsVSE_mps_MeanCloserWhls =
         (((rtb_Output_Vector[0] + rtb_Output_Vector[1]) + rtb_Output_Vector[2]) + rtb_Output_Vector[3]) / 4.0F;

      /* SignalConversion: '<S118>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S118>/Constant1'
       */
      rtb_Switch2 = 0U;

      /* End of Outputs for SubSystem: '<S89>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario6' */
   }

   /* End of If: '<S89>/If' */

   /* MATLAB Function: '<S128>/MATLAB Function' */
   ABS_TCS_Algorithm_MATLABFunction(rtb_VsVSE_mps_TransWhlLinSpd_FL, rtb_VsVSE_mps_TransWhlLinSpd_FR,
                                    rtb_VsVSE_mps_TransWhlLinSpd_RL, rtb_VsVSE_mps_TransWhlLinSpd_RR, rtb_Transpose);

   /* UnitDelay: '<S8>/Unit Delay1' */
   rtb_VsVSE_KFState_Vx = localDW->UnitDelay1_DSTATE_g;

   /* Sum: '<S172>/Add2' incorporates:
    *  Constant: '<S169>/Constant'
    *  Constant: '<S172>/Constant2'
    *  Constant: '<S172>/Constant4'
    *  Product: '<S169>/accelFromVel'
    *  Product: '<S172>/Divide1'
    *  Product: '<S172>/Divide2'
    *  Sum: '<S169>/Add'
    *  Sum: '<S172>/Add1'
    *  UnitDelay: '<S169>/Unit Delay'
    *  UnitDelay: '<S169>/Unit Delay1'
    */
   localDW->UnitDelay1_DSTATE +=
      ((((rtb_VsVSE_KFState_Vx - localDW->UnitDelay_DSTATE_fz) * 100.0F) - localDW->UnitDelay1_DSTATE) * 2.0F) / 21.0F;

   /* MATLAB Function: '<S169>/calibrated_acceleration_while_decelerating' incorporates:
    *  UnitDelay: '<S169>/Unit Delay1'
    *  UnitDelay: '<S169>/Unit Delay2'
    *  UnitDelay: '<S169>/Unit Delay3'
    */
   rtb_RelationalOperator = localDW->bitsForTID0.UnitDelay3_DSTATE_i;
   if (localDW->UnitDelay1_DSTATE < -0.02F)
   {
      if (localDW->UnitDelay2_DSTATE < 10)
      {
         localDW->UnitDelay2_DSTATE++;
      }
      else
      {
         rtb_RelationalOperator = true;
      }
   }
   else if (localDW->UnitDelay2_DSTATE > 0)
   {
      localDW->UnitDelay2_DSTATE--;
   }
   else
   {
      rtb_RelationalOperator = false;
   }

   /* End of MATLAB Function: '<S169>/calibrated_acceleration_while_decelerating' */

   /* Switch: '<S169>/Switch' incorporates:
    *  Abs: '<S169>/Abs'
    *  Constant: '<S169>/Constant1'
    *  Constant: '<S169>/Constant2'
    *  MinMax: '<S169>/Max'
    *  Product: '<S169>/Divide'
    */
   if (rtb_RelationalOperator)
   {
      rtb_Divide_g = fmaxf(fabsf(localDW->UnitDelay_DSTATE_h * 1.2F), 10.0F);
   }
   else
   {
      rtb_Divide_g = 10.0F;
   }

   /* End of Switch: '<S169>/Switch' */

   /* Product: '<S173>/Divide1' */
   rtb_Divide_g *= *rtu_VsVCAN_s_ModelExecutionTime;

   /* Switch: '<S174>/Init' incorporates:
    *  UnitDelay: '<S174>/FixPt Unit Delay1'
    *  UnitDelay: '<S174>/FixPt Unit Delay2'
    */
   if (((int32_T)localDW->FixPtUnitDelay2_DSTATE) != 0)
   {
      rtb_Init_f = rtb_Transpose[0];
   }
   else
   {
      rtb_Init_f = localDW->FixPtUnitDelay1_DSTATE;
   }

   /* End of Switch: '<S174>/Init' */

   /* MinMax: '<S173>/Min' incorporates:
    *  Sum: '<S173>/whlSpdCngLimMax'
    */
   rtb_Abs_p = fminf(rtb_Transpose[0], rtb_Divide_g + rtb_Init_f);

   /* Sum: '<S173>/whlSpdCngLimMin' */
   rtb_Divide_g = rtb_Init_f - rtb_Divide_g;

   /* MinMax: '<S173>/Min1' incorporates:
    *  UnitDelay: '<S174>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE = fmaxf(rtb_Abs_p, rtb_Divide_g);

   /* SignalConversion: '<S126>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport1' incorporates:
    *  Abs: '<S157>/Abs'
    *  Abs: '<S157>/Abs1'
    *  Abs: '<S157>/Abs3'
    *  Constant: '<S120>/Maximal_Set_Special_Threshold'
    *  RelationalOperator: '<S157>/LessThanOrEqual'
    *  RelationalOperator: '<S157>/LessThanOrEqual1'
    *  RelationalOperator: '<S157>/LessThanOrEqual3'
    *  Sum: '<S157>/Add'
    *  Sum: '<S157>/Add1'
    *  Sum: '<S157>/Add3'
    *  UnitDelay: '<S174>/FixPt Unit Delay1'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[0] =
      (fabsf(localDW->FixPtUnitDelay1_DSTATE - rtb_Transpose[3]) <= 0.1F);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[1] =
      (fabsf(localDW->FixPtUnitDelay1_DSTATE - rtb_Transpose[2]) <= 0.1F);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[2] = (fabsf(rtb_Transpose[1] - rtb_Transpose[3]) <= 0.1F);

   /* Abs: '<S157>/Abs2' incorporates:
    *  Abs: '<S124>/Abs'
    *  Sum: '<S157>/Add2'
    *  UnitDelay: '<S174>/FixPt Unit Delay1'
    */
   rtb_Divide_g = fabsf(localDW->FixPtUnitDelay1_DSTATE - rtb_Transpose[1]);

   /* SignalConversion: '<S126>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport1' incorporates:
    *  Abs: '<S157>/Abs2'
    *  Abs: '<S157>/Abs4'
    *  Constant: '<S120>/Maximal_Set_Special_Threshold'
    *  RelationalOperator: '<S157>/LessThanOrEqual2'
    *  RelationalOperator: '<S157>/LessThanOrEqual4'
    *  Sum: '<S157>/Add4'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[3] = (rtb_Divide_g <= 0.1F);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1[4] = (fabsf(rtb_Transpose[1] - rtb_Transpose[2]) <= 0.1F);

   /* SignalConversion: '<S127>/TmpSignal ConversionAtcalc_rate_from_the_sorted_spdInport1' incorporates:
    *  UnitDelay: '<S174>/FixPt Unit Delay1'
    */
   rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[0] = localDW->FixPtUnitDelay1_DSTATE;
   rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[1] = rtb_Transpose[1];
   rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[2] = rtb_Transpose[2];
   rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[3] = rtb_Transpose[3];

   /* Outputs for Iterator SubSystem: '<S127>/calc_rate_from_the_sorted_spd' */
   /* Constant: '<S120>/Constant2' */
   ABS_TCS_Algorithm_calc_rate_from_the_sorted_spd(4, rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1, rtb_delta_t,
                                                   15.0F, rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0,
                                                   localDW->calc_rate_from_the_sorted_spd_l);

   /* End of Outputs for SubSystem: '<S127>/calc_rate_from_the_sorted_spd' */

   /* If: '<S84>/If' incorporates:
    *  Constant: '<S84>/Constant4'
    *  Constant: '<S84>/Constant5'
    *  Constant: '<S84>/Constant6'
    *  DataTypeConversion: '<S84>/Data Type Conversion1'
    *  Logic: '<S84>/Logical Operator'
    *  Logic: '<S84>/Logical Operator1'
    *  Logic: '<S84>/Logical Operator3'
    *  RelationalOperator: '<S84>/Equal'
    *  RelationalOperator: '<S84>/GreaterThan'
    *  RelationalOperator: '<S84>/LessThanOrEqual'
    *  Sum: '<S84>/Add'
    */
   if ((((int32_T)((uint8_T)nonZeroCount)) == 0) ||
       (((((int32_T)((uint8_T)nonZeroCount)) <= 1) && (((int32_T)rtb_Switch2) == 0)) && (rtb_VsVSE_mps_SpeedUnderABS >= 0.199F)))
   {
      /* Outputs for IfAction SubSystem: '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1' incorporates:
       *  ActionPort: '<S92>/Action Port'
       */
      ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1(
         rtb_VsVSE_mps_TransWhlLinSpd_FL, rtb_VsVSE_mps_TransWhlLinSpd_FR, rtb_VsVSE_mps_TransWhlLinSpd_RL,
         rtb_VsVSE_mps_TransWhlLinSpd_RR, &rtb_Switch2, &rtb_VsVSE_mps_SpeedUnderABS);

      /* End of Outputs for SubSystem: '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1' */
   }
   else if (((int32_T)rtb_Switch2) != 0)
   {
      /* Outputs for IfAction SubSystem: '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2' incorporates:
       *  ActionPort: '<S93>/Action Port'
       */
      ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2(rtb_VsVSE_mps_MeanCloserWhls, &rtb_Switch2,
                                                                       &rtb_VsVSE_mps_SpeedUnderABS);

      /* End of Outputs for SubSystem: '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario3' incorporates:
       *  ActionPort: '<S94>/Action Port'
       */
      /* Product: '<S94>/Divide' incorporates:
       *  DataTypeConversion: '<S94>/Data Type Conversion'
       *  Sum: '<S94>/Add'
       */
      rtb_VsVSE_mps_SpeedUnderABS = (((rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[0] +
                                       rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[1]) +
                                      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[2]) +
                                     rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[3]) /
                                    ((real32_T)((uint8_T)nonZeroCount));

      /* End of Outputs for SubSystem: '<S84>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario3' */
   }

   /* End of If: '<S84>/If' */

   /* Chart: '<S95>/Debouncer' incorporates:
    *  DataTypeConversion: '<S84>/Data Type Conversion3'
    */
   ABS_TCS_Algorithm_Debouncer(((int32_T)rtb_Switch2) != 0, &localDW->Output, &localDW->Fault_fe, &localDW->sf_Debouncer_h, 0.3F,
                               true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S146>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0[0],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[0], &localDW->Fault_m,
                               &localDW->sf_Debouncer_dl, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S147>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0[1],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[1], &localDW->Fault_d,
                               &localDW->sf_Debouncer_l, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S148>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0[2],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[2], &localDW->Fault_f,
                               &localDW->sf_Debouncer_a, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Chart: '<S149>/Debouncer' */
   ABS_TCS_Algorithm_Debouncer(rtb_ImpAsg_InsertedFor_VaVSE_b_IsSortedWhlSpdBsdAcclHigh_at_inport_0[3],
                               &localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[3], &localDW->Fault,
                               &localDW->sf_Debouncer_i, 0.3F, true, 0.05F, false, false, 0.05F, 1.0F);

   /* Logic: '<S157>/Logical Operator6' incorporates:
    *  Logic: '<S157>/Logical Operator1'
    *  Logic: '<S157>/Logical Operator2'
    *  Logic: '<S157>/Logical Operator3'
    */
   rtb_RelationalOperator1 = !localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[1];
   rtb_RelationalOperator2 = !localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[2];
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp =
      ((!localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[0]) && rtb_RelationalOperator1);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp =
      (rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp && rtb_RelationalOperator2);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0 =
      !localDW->VaVSE_b_IsSortedWhlBsdAcclMoreThan15AfterDebncCntr_a[3];

   /* SignalConversion: '<S126>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport2' incorporates:
    *  Logic: '<S157>/Logical Operator6'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[0] =
      (rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp &&
       rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[1] =
      rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp;

   /* Logic: '<S157>/Logical Operator3' incorporates:
    *  Logic: '<S157>/Logical Operator4'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp = (rtb_RelationalOperator1 && rtb_RelationalOperator2);

   /* SignalConversion: '<S126>/TmpSignal ConversionAtFinal_Check_For_Closer_Whl_SpdInport2' incorporates:
    *  Logic: '<S157>/Logical Operator3'
    */
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[2] =
      (rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp &&
       rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_0);
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[3] =
      rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp_tmp;
   rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2[4] =
      rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2_tmp;

   /* Outputs for Iterator SubSystem: '<S126>/Final_Check_For_Closer_Whl_Spd' */
   ABS_TCS_Algorithm_Final_Check_For_Closer_Whl_Spd(5, rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport1,
                                                    rtb_TmpSignalConversionAtFinal_Check_For_Closer_Whl_SpdInport2,
                                                    rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0);

   /* End of Outputs for SubSystem: '<S126>/Final_Check_For_Closer_Whl_Spd' */

   /* If: '<S126>/If' */
   if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0[0])
   {
      /* Outputs for IfAction SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario1'
       * incorporates: ActionPort: '<S159>/Action Port'
       */
      /* Product: '<S159>/Divide' incorporates:
       *  Constant: '<S159>/Constant'
       *  Sum: '<S159>/Add'
       *  UnitDelay: '<S174>/FixPt Unit Delay1'
       */
      rtb_Init_f = (((localDW->FixPtUnitDelay1_DSTATE + rtb_Transpose[1]) + rtb_Transpose[2]) + rtb_Transpose[3]) / 4.0F;

      /* SignalConversion: '<S159>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S159>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario1' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0[1])
   {
      /* Outputs for IfAction SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario2'
       * incorporates: ActionPort: '<S160>/Action Port'
       */
      /* Product: '<S160>/Divide' incorporates:
       *  Constant: '<S160>/Constant'
       *  Sum: '<S160>/Add'
       *  UnitDelay: '<S174>/FixPt Unit Delay1'
       */
      rtb_Init_f = ((localDW->FixPtUnitDelay1_DSTATE + rtb_Transpose[1]) + rtb_Transpose[2]) / 3.0F;

      /* SignalConversion: '<S160>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S160>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario2' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0[2])
   {
      /* Outputs for IfAction SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario4'
       * incorporates: ActionPort: '<S162>/Action Port'
       */
      /* Product: '<S162>/Divide' incorporates:
       *  Constant: '<S162>/Constant'
       *  Sum: '<S162>/Add'
       */
      rtb_Init_f = ((rtb_Transpose[1] + rtb_Transpose[2]) + rtb_Transpose[3]) / 3.0F;

      /* SignalConversion: '<S162>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S162>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario4' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0[3])
   {
      /* Outputs for IfAction SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario3'
       * incorporates: ActionPort: '<S161>/Action Port'
       */
      /* Product: '<S161>/Divide' incorporates:
       *  Constant: '<S161>/Constant'
       *  Sum: '<S161>/Add'
       *  UnitDelay: '<S174>/FixPt Unit Delay1'
       */
      rtb_Init_f = (localDW->FixPtUnitDelay1_DSTATE + rtb_Transpose[1]) / 2.0F;

      /* SignalConversion: '<S161>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S161>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario3' */
   }
   else if (rtb_ImpAsg_InsertedFor_VaVSE_b_CloserWhlSpdSet_at_inport_0[4])
   {
      /* Outputs for IfAction SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario5'
       * incorporates: ActionPort: '<S163>/Action Port'
       */
      /* Product: '<S163>/Divide' incorporates:
       *  Constant: '<S163>/Constant'
       *  Sum: '<S163>/Add'
       */
      rtb_Init_f = (rtb_Transpose[1] + rtb_Transpose[2]) / 2.0F;

      /* SignalConversion: '<S163>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S163>/Constant1'
       */
      rtb_Switch2 = 1U;

      /* End of Outputs for SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario5' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario6'
       * incorporates: ActionPort: '<S164>/Action Port'
       */
      /* Product: '<S164>/Divide' incorporates:
       *  Constant: '<S164>/Constant'
       *  Sum: '<S164>/Add'
       *  UnitDelay: '<S174>/FixPt Unit Delay1'
       */
      rtb_Init_f = (((localDW->FixPtUnitDelay1_DSTATE + rtb_Transpose[1]) + rtb_Transpose[2]) + rtb_Transpose[3]) / 4.0F;

      /* SignalConversion: '<S164>/OutportBuffer_InsertedFor_VsVSE_u8_AtLeastTwoWhlClose_at_inport_0' incorporates:
       *  Constant: '<S164>/Constant1'
       */
      rtb_Switch2 = 0U;

      /* End of Outputs for SubSystem: '<S126>/Get_The_Mean_of_Closer_Whl_Spd_And_Check_for_Atleast_Two_Whls_Close_Scenario6' */
   }

   /* End of If: '<S126>/If' */

   /* SignalConversion: '<S121>/ConcatBufferAtVector ConcatenateIn1' */
   localDW->VaVSE_b_IsWhlUnderASR[0] = rtb_ASRStatus_bool_l;

   /* SignalConversion: '<S121>/ConcatBufferAtVector ConcatenateIn2' */
   localDW->VaVSE_b_IsWhlUnderASR[1] = rtb_ASRStatus_bool_l3;

   /* SignalConversion: '<S121>/ConcatBufferAtVector ConcatenateIn3' */
   localDW->VaVSE_b_IsWhlUnderASR[2] = rtb_ASRStatus_bool_j;

   /* SignalConversion: '<S121>/ConcatBufferAtVector ConcatenateIn4' */
   localDW->VaVSE_b_IsWhlUnderASR[3] = rtb_ASRStatus_bool_bs;

   /* Outputs for Iterator SubSystem: '<S120>/calc_speed_under_ABS' incorporates:
    *  ForEach: '<S125>/For Each'
    */
   for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++)
   {
      /* ForEachSliceAssignment: '<S125>/ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0' incorporates:
       *  ForEachSliceSelector: '<S125>/ImpSel_InsertedFor_VaVSE_b_IsWhlUnderASR_at_outport_0'
       */
      rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0[ForEach_itr] =
         (int8_T)((!localDW->VaVSE_b_IsWhlUnderASR[ForEach_itr]) ? 1 : 0);

      /* Switch: '<S125>/Switch' incorporates:
       *  ForEachSliceSelector: '<S125>/ImpSel_InsertedFor_VaVSE_b_IsWhlUnderASR_at_outport_0'
       */
      if (localDW->VaVSE_b_IsWhlUnderASR[ForEach_itr])
      {
         /* ForEachSliceAssignment: '<S125>/ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0' incorporates:
          *  Constant: '<S125>/Constant1'
          */
         rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[ForEach_itr] = 0.0F;
      }
      else
      {
         /* ForEachSliceAssignment: '<S125>/ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0' incorporates:
          *  ForEachSliceSelector: '<S125>/ImpSel_InsertedFor_VsVSE_mps_TransFiltWhlLinSpd_at_outport_0'
          */
         rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[ForEach_itr] =
            localDW->TmpSignalConversionAtcalc_speed_under_ABSInport2[ForEach_itr];
      }

      /* End of Switch: '<S125>/Switch' */
   }

   /* End of Outputs for SubSystem: '<S120>/calc_speed_under_ABS' */

   /* Sum: '<S124>/Add' */
   nonZeroCount = (int32_T)((uint32_T)(((((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0[0]) +
                                         ((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0[1])) +
                                        ((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0[2])) +
                                       ((uint32_T)rtb_ImpAsg_InsertedFor_VaVSE_u8_NumOfWhlUnderNoASR_at_inport_0[3])));

   /* If: '<S124>/If' incorporates:
    *  Constant: '<S124>/Constant4'
    *  Constant: '<S124>/Constant5'
    *  Constant: '<S124>/Constant6'
    *  DataTypeConversion: '<S124>/Data Type Conversion1'
    *  Logic: '<S124>/Logical Operator'
    *  Logic: '<S124>/Logical Operator1'
    *  Logic: '<S124>/Logical Operator3'
    *  RelationalOperator: '<S124>/Equal'
    *  RelationalOperator: '<S124>/GreaterThan'
    *  RelationalOperator: '<S124>/LessThanOrEqual'
    *  Sum: '<S124>/Add'
    */
   if ((((int32_T)((uint8_T)nonZeroCount)) == 0) ||
       (((((int32_T)((uint8_T)nonZeroCount)) <= 1) && (((int32_T)rtb_Switch2) == 0)) && (rtb_Divide_g >= 0.199F)))
   {
      /* Outputs for IfAction SubSystem: '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1' incorporates:
       *  ActionPort: '<S154>/Action Port'
       */
      ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1(
         rtb_VsVSE_mps_TransWhlLinSpd_FL, rtb_VsVSE_mps_TransWhlLinSpd_FR, rtb_VsVSE_mps_TransWhlLinSpd_RL,
         rtb_VsVSE_mps_TransWhlLinSpd_RR, &rtb_Switch2, &rtb_Divide_g);

      /* End of Outputs for SubSystem: '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario1' */
   }
   else if (((int32_T)rtb_Switch2) != 0)
   {
      /* Outputs for IfAction SubSystem: '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2' incorporates:
       *  ActionPort: '<S155>/Action Port'
       */
      ABS_TCS_Algorithm_Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2(rtb_Init_f, &rtb_Switch2, &rtb_Divide_g);

      /* End of Outputs for SubSystem: '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario2' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario3' incorporates:
       *  ActionPort: '<S156>/Action Port'
       */
      /* SignalConversion: '<S156>/OutportBuffer_InsertedFor_VsVSE_u8_SwitchToMeasAx_at_inport_0' incorporates:
       *  Constant: '<S156>/Constant'
       */
      rtb_Switch2 = 0U;

      /* Product: '<S156>/Divide' incorporates:
       *  DataTypeConversion: '<S156>/Data Type Conversion'
       *  Sum: '<S156>/Add'
       */
      rtb_Divide_g = (((rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[0] +
                        rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[1]) +
                       rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[2]) +
                      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[3]) /
                     ((real32_T)((uint8_T)nonZeroCount));

      /* End of Outputs for SubSystem: '<S124>/Check_For_ABS_and_SwitchToMeasAxFlag_Scenario3' */
   }

   /* End of If: '<S124>/If' */

   /* Outputs for Enabled SubSystem: '<S13>/Initialization' incorporates:
    *  EnablePort: '<S14>/Enable'
    */
   /* MATLAB Function: '<S14>/MATLAB Function' */
   localDW->filter_num[0] = 0.0564484671F;
   localDW->filter_den[0] = 1.0F;
   localDW->filter_num[1] = 0.112896934F;
   localDW->filter_den[1] = -1.22465158F;
   localDW->filter_num[2] = 0.0564484671F;
   localDW->filter_den[2] = 0.450445414F;

   /* End of Outputs for SubSystem: '<S13>/Initialization' */

   /* MATLAB Function: '<S7>/MATLAB Function2' */
   nonZeroCount = ((((int32_T)(((*rtu_VsVCAN_mps_WheelLinSpd_FL) > 0.0F) ? 1 : 0)) +
                    ((int32_T)(((*rtu_VsVCAN_mps_WheelLinSpd_FR) > 0.0F) ? 1 : 0))) +
                   ((int32_T)(((*rtu_VsVCAN_mps_WheelLinSpd_RL) > 0.0F) ? 1 : 0))) +
                  ((int32_T)(((*rtu_VsVCAN_mps_WheelLinSpd_RR) > 0.0F) ? 1 : 0));
   if (nonZeroCount == 0)
   {
      rtb_avgResult_n = 0.0F;
   }
   else
   {
      rtb_avgResult_n /= (real32_T)nonZeroCount;
   }

   /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
    *  UnitDelay: '<S7>/Unit Delay'
    *  UnitDelay: '<S7>/Unit Delay2'
    */
   rtb_ASRStatus_bool_l = localDW->bitsForTID0.UnitDelay2_DSTATE_i;
   if (fabsf(rtb_avgResult_n) < 2.22044605E-16F)
   {
      qY = localDW->UnitDelay_DSTATE_a + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->UnitDelay_DSTATE_a)
      {
         qY = MAX_uint32_T;
      }
   }
   else
   {
      qY                   = 0U;
      rtb_ASRStatus_bool_l = false;
   }

   if (qY >= 10U)
   {
      rtb_ASRStatus_bool_l = true;
   }

   localDW->UnitDelay_DSTATE_a = qY;

   /* End of MATLAB Function: '<S7>/MATLAB Function' */

   /* MATLABSystem: '<S10>/Moving Average' */
   if (localDW->obj.ForgettingFactor != 0.99F)
   {
      if (localDW->obj.isInitialized == 1)
      {
         localDW->obj.TunablePropsChanged = true;
      }

      localDW->obj.ForgettingFactor = 0.99F;
   }

   if (localDW->obj.TunablePropsChanged)
   {
      localDW->obj.TunablePropsChanged = false;
      rtb_ASRStatus_bool_l3            = (localDW->obj.pStatistic->isInitialized == 1);
      if (rtb_ASRStatus_bool_l3)
      {
         localDW->obj.pStatistic->TunablePropsChanged = true;
      }

      localDW->obj.pStatistic->ForgettingFactor = localDW->obj.ForgettingFactor;
   }

   if (localDW->obj.pStatistic->isInitialized != 1)
   {
      localDW->obj.pStatistic->isSetupComplete     = false;
      localDW->obj.pStatistic->isInitialized       = 1;
      localDW->obj.pStatistic->pwN                 = 1.0F;
      localDW->obj.pStatistic->pmN                 = 0.0F;
      localDW->obj.pStatistic->plambda             = localDW->obj.pStatistic->ForgettingFactor;
      localDW->obj.pStatistic->isSetupComplete     = true;
      localDW->obj.pStatistic->TunablePropsChanged = false;
      localDW->obj.pStatistic->pwN                 = 1.0F;
      localDW->obj.pStatistic->pmN                 = 0.0F;
   }

   if (localDW->obj.pStatistic->TunablePropsChanged)
   {
      localDW->obj.pStatistic->TunablePropsChanged = false;
      localDW->obj.pStatistic->plambda             = localDW->obj.pStatistic->ForgettingFactor;
   }

   rtb_avgResult_n              = localDW->obj.pStatistic->pwN;
   rtb_VsVSE_mps_MeanCloserWhls = localDW->obj.pStatistic->pmN;
   rtb_Init_f                   = localDW->obj.pStatistic->plambda;

   /* Switch: '<S10>/Switch' incorporates:
    *  Constant: '<S10>/Constant'
    */
   if (rtb_ASRStatus_bool_l)
   {
      rtb_Abs_p = *rtu_VsVCAN_mps2_RawLongAccel;
   }
   else
   {
      rtb_Abs_p = 0.0F;
   }

   /* End of Switch: '<S10>/Switch' */

   /* MATLABSystem: '<S10>/Moving Average' */
   rtb_VsVSE_mps_MeanCloserWhls =
      ((1.0F - (1.0F / rtb_avgResult_n)) * rtb_VsVSE_mps_MeanCloserWhls) + ((1.0F / rtb_avgResult_n) * rtb_Abs_p);
   localDW->obj.pStatistic->pwN = (rtb_Init_f * rtb_avgResult_n) + 1.0F;
   localDW->obj.pStatistic->pmN = rtb_VsVSE_mps_MeanCloserWhls;

   /* MATLAB Function: '<S10>/MATLAB Function1' incorporates:
    *  MATLABSystem: '<S10>/Moving Average'
    */
   if (!localDW->bitsForTID0.last_inp_not_empty)
   {
      localDW->last_inp                       = rtb_VsVSE_mps_MeanCloserWhls;
      localDW->bitsForTID0.last_inp_not_empty = true;
   }

   if (rtb_ASRStatus_bool_l)
   {
      localDW->last_inp = rtb_VsVSE_mps_MeanCloserWhls;
   }

   /* End of MATLAB Function: '<S10>/MATLAB Function1' */

   /* Switch: '<S11>/Switch' incorporates:
    *  Product: '<S11>/Multiply'
    *  Sum: '<S1>/Add'
    */
   if (rtb_veh_reverse_status)
   {
      rtb_avgResult_n = -((*rtu_VsVCAN_mps2_RawLongAccel) - localDW->last_inp);
   }
   else
   {
      rtb_avgResult_n = (*rtu_VsVCAN_mps2_RawLongAccel) - localDW->last_inp;
   }

   /* End of Switch: '<S11>/Switch' */

   /* DiscreteFilter: '<S13>/Discrete Filter' */
   if (((int32_T)localDW->DiscreteFilter_icLoad) != 0)
   {
      localDW->DiscreteFilter_states[0] = rtb_avgResult_n;
      localDW->DiscreteFilter_states[1] = rtb_avgResult_n;
      localDW->DiscreteFilter_icLoad    = 0U;
   }

   localDW->DiscreteFilter_tmp = (rtb_avgResult_n - (localDW->filter_den[1] * localDW->DiscreteFilter_states[0])) -
                                 (localDW->filter_den[2] * localDW->DiscreteFilter_states[1]);
   localDW->ScndOrderButterFiltOut =
      ((localDW->filter_num[0] * localDW->DiscreteFilter_tmp) + (localDW->filter_num[1] * localDW->DiscreteFilter_states[0])) +
      (localDW->filter_num[2] * localDW->DiscreteFilter_states[1]);

   /* End of DiscreteFilter: '<S13>/Discrete Filter' */

   /* MATLAB Function: '<S84>/MATLAB Function2' */
   nonZeroCount = ((((int32_T)((rtb_VsVSE_mps_TransWhlLinSpd_FL > 0.0F) ? 1 : 0)) +
                    ((int32_T)((rtb_VsVSE_mps_TransWhlLinSpd_FR > 0.0F) ? 1 : 0))) +
                   ((int32_T)((rtb_VsVSE_mps_TransWhlLinSpd_RL > 0.0F) ? 1 : 0))) +
                  ((int32_T)((rtb_VsVSE_mps_TransWhlLinSpd_RR > 0.0F) ? 1 : 0));
   if (nonZeroCount == 0)
   {
      rtb_Init_f = 0.0F;
   }
   else
   {
      rtb_Init_f = (((rtb_VsVSE_mps_TransWhlLinSpd_FL + rtb_VsVSE_mps_TransWhlLinSpd_FR) + rtb_VsVSE_mps_TransWhlLinSpd_RL) +
                    rtb_VsVSE_mps_TransWhlLinSpd_RR) /
                   ((real32_T)nonZeroCount);
   }

   /* End of MATLAB Function: '<S84>/MATLAB Function2' */

   /* MATLAB Function: '<S81>/calc_final_whl_speed_which_will_be_considered_as_Z_vec' incorporates:
    *  Constant: '<S85>/Constant2'
    *  DataTypeConversion: '<S84>/Data Type Conversion2'
    *  Logic: '<S85>/Logical Operator3'
    *  Logic: '<S85>/Logical Operator4'
    *  RelationalOperator: '<S85>/GreaterThan'
    *  RelationalOperator: '<S85>/GreaterThan1'
    */
   *rty_VsVSE_u8_ABS_Status                = 0U;
   rtb_SwitchToMeasAxUnderABSAndBraking_u8 = 0U;
   rtb_SwitchToMeasAxUnderASR_u8           = 0U;
   if (fabsf(rtb_Init_f) > 1.0F)
   {
      if ((*rtu_VsVCAN_b_ABSActive) || ((localDW->UnitDelay_DSTATE_h < 0.0F) || (localDW->ScndOrderButterFiltOut < 0.0F)))
      {
         if (localDW->Output_f)
         {
            rtb_Init_f               = rtb_VsVSE_mps_SpeedUnderABS;
            *rty_VsVSE_u8_ABS_Status = 1U;
         }

         if (localDW->Output)
         {
            rtb_SwitchToMeasAxUnderABSAndBraking_u8 = 1U;
         }
      }
      else
      {
         if (*rty_VsVSE_b_ASR_Status)
         {
            rtb_Init_f = rtb_Divide_g;
            if (((int32_T)rtb_Switch2) != 0)
            {
               rtb_SwitchToMeasAxUnderASR_u8 = 1U;
            }
         }
      }
   }

   /* End of MATLAB Function: '<S81>/calc_final_whl_speed_which_will_be_considered_as_Z_vec' */

   /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
    *  DataTypeConversion: '<S2>/Data Type Conversion1'
    *  DataTypeConversion: '<S2>/Data Type Conversion2'
    *  Logic: '<S2>/Logical Operator1'
    */
   rtb_DataTypeConversion_i =
      (uint8_T)(((((int32_T)rtb_SwitchToMeasAxUnderABSAndBraking_u8) != 0) || (((int32_T)rtb_SwitchToMeasAxUnderASR_u8) != 0)) ?
                   1 :
                   0);

   /* MATLAB Function: '<S2>/Z_H_and_R_design' */
   if ((((int32_T)(*rty_VsVSE_u8_ABS_Status)) == 0) || (!(*rty_VsVSE_b_ASR_Status)))
   {
      rtb_VsVSE_mps_SpeedUnderABS = 2.22044605E-16F;
   }
   else if (fabsf(rtb_Init_f) <= 0.5F)
   {
      rtb_VsVSE_mps_SpeedUnderABS = 2.22044605E-16F;
   }
   else
   {
      rtb_VsVSE_mps_SpeedUnderABS = 0.0100000007F;
   }

   tmpForInput[0]  = 1.0F;
   tmpForInput[1]  = 0.0F;
   rtb_avgResult_n = rtb_Init_f;
   if ((((int32_T)rtb_SwitchToMeasAxUnderABSAndBraking_u8) == 1) || (((int32_T)rtb_SwitchToMeasAxUnderASR_u8) == 1))
   {
      rtb_VsVSE_mps_SpeedUnderABS = 0.0100000007F;
      tmpForInput[0]              = 0.0F;
      tmpForInput[1]              = 1.0F;
      rtb_avgResult_n             = localDW->ScndOrderButterFiltOut;
   }

   /* End of MATLAB Function: '<S2>/Z_H_and_R_design' */

   /* Switch: '<S22>/Init' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    *  UnitDelay: '<S22>/FixPt Unit Delay2'
    */
   if (((int32_T)localDW->FixPtUnitDelay2_DSTATE_e) != 0)
   {
      rtb_Init[0] = rtb_Init_f;
      rtb_Init[1] = localDW->ScndOrderButterFiltOut;
   }
   else
   {
      rtb_Init[0] = localDW->FixPtUnitDelay1_DSTATE_j[0];
      rtb_Init[1] = localDW->FixPtUnitDelay1_DSTATE_j[1];
   }

   /* End of Switch: '<S22>/Init' */

   /* MATLAB Function: '<S17>/DesignAdaptationMatrix' */
   rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[0] = 1.0F;
   rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[2] = rtb_delta_t;
   rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[1] = 0.0F;
   rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[3] = 1.0F;

   /* MATLAB Function: '<S18>/DesignProcessNoiseMatrix' incorporates:
    *  Constant: '<S2>/Constant1'
    *  Constant: '<S2>/Constant2'
    */
   rtb_Divide_g         = rtb_delta_t * rtb_delta_t;
   rtb_Output_Vector[0] = (((rtb_Divide_g * rtb_delta_t) / 3.0F) * 100.0F) + (1.1F * rtb_delta_t);
   rtb_Divide_g         = (rtb_Divide_g / 2.0F) * 100.0F;
   rtb_Output_Vector[2] = rtb_Divide_g;
   rtb_Output_Vector[1] = rtb_Divide_g;
   rtb_Output_Vector[3] = 100.0F * rtb_delta_t;

   /* Outputs for Iterator SubSystem: '<S16>/Control' incorporates:
    *  ForIterator: '<S21>/Iterator'
    */
   /* UnitDelay: '<S16>/Unit Delay3' */
   rtb_Transpose[0] = localDW->UnitDelay3_DSTATE[0];
   rtb_Transpose[1] = localDW->UnitDelay3_DSTATE[1];
   rtb_Transpose[2] = localDW->UnitDelay3_DSTATE[2];
   rtb_Transpose[3] = localDW->UnitDelay3_DSTATE[3];

   /* DataStoreWrite: '<S23>/Data Store Write' */
   localDW->Index = 1;

   /* Update for UnitDelay: '<S22>/FixPt Unit Delay1' */
   localDW->FixPtUnitDelay1_DSTATE_j[0] = rtb_Init[0];

   /* Product: '<S24>/H*P_prdt' incorporates:
    *  Math: '<S24>/P_prd Trans'
    *  Product: '<S24>/K*H*P_prd'
    *  UnitDelay: '<S16>/Unit Delay3'
    */
   localDW->Assignment[0]       = 0.0F;
   rtb_VsVSE_mps_MeanCloserWhls = tmpForInput[0] * localDW->UnitDelay3_DSTATE[0];
   localDW->Assignment[0] += rtb_VsVSE_mps_MeanCloserWhls;
   localDW->Assignment[0] += tmpForInput[1] * localDW->UnitDelay3_DSTATE[2];

   /* Update for UnitDelay: '<S22>/FixPt Unit Delay1' */
   localDW->FixPtUnitDelay1_DSTATE_j[1] = rtb_Init[1];

   /* Product: '<S24>/H*P_prdt' incorporates:
    *  Math: '<S24>/P_prd Trans'
    *  Product: '<S24>/K*H*P_prd'
    *  UnitDelay: '<S16>/Unit Delay3'
    */
   localDW->Assignment[1] = 0.0F;
   localDW->Assignment[1] += tmpForInput[0] * localDW->UnitDelay3_DSTATE[1];
   rtb_Init_f = tmpForInput[1] * localDW->UnitDelay3_DSTATE[3];
   localDW->Assignment[1] += rtb_Init_f;

   /* Sum: '<S24>/H*P_prdt*Ht+R' incorporates:
    *  Math: '<S16>/H_Transpose'
    *  Product: '<S24>/H*P_prdt*Ht'
    */
   rtb_Abs_p =
      ((localDW->Assignment[0] * tmpForInput[0]) + (localDW->Assignment[1] * tmpForInput[1])) + rtb_VsVSE_mps_SpeedUnderABS;

   /* S-Function (sdspldl2): '<S28>/LDL Factorization' */
   LDLf_int32_Treal32_T_Aptiv(&rtb_Abs_p, &localDW->LDLFactorization_VMX, 1, &rtb_Abs_p);

   /* Math: '<S28>/Math Function' incorporates:
    *  S-Function (sdspdiag2): '<S28>/Extract Diagonal'
    *
    * About '<S28>/Math Function':
    *  Operator: reciprocal
    */
   rtb_Divide_g = 1.0F / rtb_Abs_p;

   /* S-Function (sdspdmult2): '<S28>/Matrix Scaling' */
   rtb_AX[0] = localDW->Assignment[0] * rtb_Divide_g;

   /* Product: '<S24>/K*H*P_prd' incorporates:
    *  UnitDelay: '<S16>/Unit Delay3'
    */
   rtb_VsVSE_mps_SpeedUnderABS = rtb_VsVSE_mps_MeanCloserWhls + (tmpForInput[1] * localDW->UnitDelay3_DSTATE[1]);

   /* S-Function (sdspdmult2): '<S28>/Matrix Scaling' */
   rtb_AX[1] = localDW->Assignment[1] * rtb_Divide_g;

   /* Product: '<S24>/K*H*P_prd' incorporates:
    *  UnitDelay: '<S16>/Unit Delay3'
    */
   rtb_Divide_g = (tmpForInput[0] * localDW->UnitDelay3_DSTATE[2]) + rtb_Init_f;
   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      /* Sum: '<S24>/P_prd-K*H*P_prd' incorporates:
       *  Product: '<S24>/K*H*P_prd'
       *  UnitDelay: '<S16>/Unit Delay3'
       */
      rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[nonZeroCount] =
         localDW->UnitDelay3_DSTATE[nonZeroCount] - (rtb_AX[nonZeroCount] * rtb_VsVSE_mps_SpeedUnderABS);
      rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[nonZeroCount + 2] =
         localDW->UnitDelay3_DSTATE[nonZeroCount + 2] - (rtb_AX[nonZeroCount] * rtb_Divide_g);

      /* Product: '<S24>/A*P*At' incorporates:
       *  MATLAB Function: '<S17>/DesignAdaptationMatrix'
       *  Math: '<S24>/Transpose'
       */
      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[nonZeroCount] = 0.0F;
      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[nonZeroCount] +=
         rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[nonZeroCount];
      rtb_Init_f = rtb_TmpSignalConversionAtcalc_rate_from_the_sorted_spdInport1[nonZeroCount + 2];
      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[nonZeroCount] += rtb_Init_f * rtb_delta_t;
      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[nonZeroCount + 2] = 0.0F;
      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[nonZeroCount + 2] += rtb_Init_f;
   }

   /* Product: '<S24>/H*X_prd' */
   rtb_VsVSE_mps_SpeedUnderABS = 0.0F;
   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      /* Sum: '<S24>/A*P*At+Q' incorporates:
       *  Product: '<S24>/A*P*At'
       */
      rtb_Divide_g = rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[nonZeroCount + 2];

      /* Assignment: '<S25>/Assignment' incorporates:
       *  Product: '<S24>/A*P*At'
       *  Sum: '<S24>/A*P*At+Q'
       */
      rtb_Transpose[nonZeroCount] = ((rtb_Divide_g * rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[1]) +
                                     (rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[nonZeroCount] *
                                      rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[0])) +
                                    rtb_Output_Vector[nonZeroCount];
      rtb_Transpose[nonZeroCount + 2] =
         ((rtb_Divide_g * rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[3]) +
          (rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderASR_at_inport_0[nonZeroCount] *
           rtb_ImpAsg_InsertedFor_VaVSE_mps_TransFiltWhlLinSpdUnderABS_at_inport_0[2])) +
         rtb_Output_Vector[nonZeroCount + 2];

      /* Product: '<S24>/H*X_prd' incorporates:
       *  Selector: '<S23>/Selector1'
       */
      rtb_VsVSE_mps_SpeedUnderABS += tmpForInput[nonZeroCount] * rtb_Init[nonZeroCount];
   }

   /* Sum: '<S24>/Z-H*X_prd' incorporates:
    *  Product: '<S24>/H*X_prd'
    *  Selector: '<S23>/Selector'
    */
   rtb_Abs_p = rtb_avgResult_n - rtb_VsVSE_mps_SpeedUnderABS;

   /* Sum: '<S24>/X_prd+K*(Z-H*X_prd)' incorporates:
    *  Product: '<S24>/K*(Z-H*X_prd)'
    *  Selector: '<S23>/Selector1'
    */
   rtb_AX[0]       = (rtb_AX[0] * rtb_Abs_p) + rtb_Init[0];
   rtb_avgResult_n = (rtb_AX[1] * rtb_Abs_p) + rtb_Init[1];

   /* Switch: '<S35>/Switch' incorporates:
    *  UnitDelay: '<S35>/init_value'
    */
   if (((int32_T)localDW->init_value_DSTATE) != 0)
   {
      localDW->prvious_flag_value_DSTATE = rtb_DataTypeConversion_i;
   }

   /* End of Switch: '<S35>/Switch' */

   /* Switch: '<S36>/Switch' incorporates:
    *  Constant: '<S35>/Constant1'
    *  Constant: '<S35>/Constant2'
    *  RelationalOperator: '<S35>/IsTransition'
    *  Sum: '<S35>/Sum'
    *  Switch: '<S35>/Switch2'
    *  Switch: '<S37>/Switch'
    *  UnitDelay: '<S33>/lastOut'
    *  UnitDelay: '<S35>/init_value'
    *  UnitDelay: '<S35>/step_counter'
    *  UnitDelay: '<S37>/Unit Delay'
    */
   if (rtb_DataTypeConversion_i != localDW->prvious_flag_value_DSTATE)
   {
      localDW->UnitDelay_DSTATE_nz = localDW->lastOut_DSTATE;
      rtb_Switch2                  = 1U;
   }
   else
   {
      if (((int32_T)localDW->init_value_DSTATE) != 0)
      {
         /* Switch: '<S37>/Switch' incorporates:
          *  UnitDelay: '<S37>/Unit Delay'
          */
         localDW->UnitDelay_DSTATE_nz = rtb_AX[0];
      }

      rtb_Switch2 = (uint8_T)(1U + ((uint32_T)localDW->step_counter_DSTATE));
   }

   /* End of Switch: '<S36>/Switch' */

   /* Switch: '<S35>/Switch1' incorporates:
    *  Constant: '<S24>/MAX_COUNTER'
    *  RelationalOperator: '<S35>/Relational Operator1'
    *  UnitDelay: '<S35>/step_counter'
    */
   if (((int32_T)rtb_Switch2) > 7)
   {
      localDW->step_counter_DSTATE = 7U;
   }
   else
   {
      localDW->step_counter_DSTATE = rtb_Switch2;
   }

   /* End of Switch: '<S35>/Switch1' */

   /* Sum: '<S36>/sum' incorporates:
    *  Product: '<S36>/Divide'
    *  Product: '<S36>/Divide1'
    *  Sum: '<S36>/Sum'
    *  UnitDelay: '<S33>/lastOut'
    *  UnitDelay: '<S35>/step_counter'
    *  UnitDelay: '<S37>/Unit Delay'
    */
   localDW->lastOut_DSTATE = (((rtb_AX[0] - localDW->UnitDelay_DSTATE_nz) / 7.0F) * ((real32_T)localDW->step_counter_DSTATE)) +
                             localDW->UnitDelay_DSTATE_nz;

   /* Switch: '<S38>/Switch' incorporates:
    *  UnitDelay: '<S38>/init_value'
    */
   if (((int32_T)localDW->init_value_DSTATE_a) != 0)
   {
      localDW->prvious_flag_value_DSTATE_n = rtb_DataTypeConversion_i;
   }

   /* End of Switch: '<S38>/Switch' */

   /* Switch: '<S39>/Switch' incorporates:
    *  Constant: '<S38>/Constant1'
    *  Constant: '<S38>/Constant2'
    *  RelationalOperator: '<S38>/IsTransition'
    *  Sum: '<S38>/Sum'
    *  Switch: '<S38>/Switch2'
    *  Switch: '<S40>/Switch'
    *  UnitDelay: '<S34>/lastOut'
    *  UnitDelay: '<S38>/init_value'
    *  UnitDelay: '<S38>/step_counter'
    *  UnitDelay: '<S40>/Unit Delay'
    */
   if (rtb_DataTypeConversion_i != localDW->prvious_flag_value_DSTATE_n)
   {
      localDW->UnitDelay_DSTATE_ms = localDW->lastOut_DSTATE_d;
      rtb_Switch2                  = 1U;
   }
   else
   {
      if (((int32_T)localDW->init_value_DSTATE_a) != 0)
      {
         /* Switch: '<S40>/Switch' incorporates:
          *  UnitDelay: '<S40>/Unit Delay'
          */
         localDW->UnitDelay_DSTATE_ms = rtb_avgResult_n;
      }

      rtb_Switch2 = (uint8_T)(1U + ((uint32_T)localDW->step_counter_DSTATE_j));
   }

   /* End of Switch: '<S39>/Switch' */

   /* Switch: '<S38>/Switch1' incorporates:
    *  Constant: '<S24>/MAX_COUNTER'
    *  RelationalOperator: '<S38>/Relational Operator1'
    */
   if (((int32_T)rtb_Switch2) > 7)
   {
      rtb_Switch2 = 7U;
   }

   /* End of Switch: '<S38>/Switch1' */

   /* Sum: '<S39>/sum' incorporates:
    *  Product: '<S39>/Divide'
    *  Product: '<S39>/Divide1'
    *  Sum: '<S39>/Sum'
    *  UnitDelay: '<S34>/lastOut'
    *  UnitDelay: '<S40>/Unit Delay'
    */
   localDW->lastOut_DSTATE_d =
      (((rtb_avgResult_n - localDW->UnitDelay_DSTATE_ms) / 7.0F) * ((real32_T)rtb_Switch2)) + localDW->UnitDelay_DSTATE_ms;

   /* SignalConversion: '<S24>/TmpSignal ConversionAtA*XInport2' incorporates:
    *  UnitDelay: '<S33>/lastOut'
    *  UnitDelay: '<S34>/lastOut'
    */
   localDW->Assignment[0] = localDW->lastOut_DSTATE;
   localDW->Assignment[1] = localDW->lastOut_DSTATE_d;

   /* Update for UnitDelay: '<S22>/FixPt Unit Delay1' incorporates:
    *  Assignment: '<S27>/Assignment'
    *  MATLAB Function: '<S17>/DesignAdaptationMatrix'
    *  Product: '<S24>/A*X'
    */
   localDW->FixPtUnitDelay1_DSTATE_j[0] = (rtb_delta_t * localDW->Assignment[1]) + localDW->Assignment[0];
   localDW->FixPtUnitDelay1_DSTATE_j[1] = localDW->Assignment[1];

   /* Update for UnitDelay: '<S35>/init_value' incorporates:
    *  Constant: '<S35>/Constant'
    */
   localDW->init_value_DSTATE = 0U;

   /* Update for Switch: '<S35>/Switch' incorporates:
    *  UnitDelay: '<S35>/prvious_flag_value'
    */
   localDW->prvious_flag_value_DSTATE = rtb_DataTypeConversion_i;

   /* Update for UnitDelay: '<S38>/init_value' incorporates:
    *  Constant: '<S38>/Constant'
    */
   localDW->init_value_DSTATE_a = 0U;

   /* Update for Switch: '<S38>/Switch' incorporates:
    *  UnitDelay: '<S38>/prvious_flag_value'
    */
   localDW->prvious_flag_value_DSTATE_n = rtb_DataTypeConversion_i;

   /* Update for UnitDelay: '<S38>/step_counter' */
   localDW->step_counter_DSTATE_j = rtb_Switch2;

   /* End of Outputs for SubSystem: '<S16>/Control' */

   /* Outputs for Enabled SubSystem: '<S57>/Initialization' */
   /* Constant: '<S57>/Constant' */
   ABS_TCS_Algorithm_Initialization1(true, localDW->diff_num, localDW->diff_denom);

   /* End of Outputs for SubSystem: '<S57>/Initialization' */

   /* Outputs for Enabled SubSystem: '<S56>/Initialization1' */
   /* Constant: '<S56>/Constant' */
   ABS_TCS_Algorithm_Initialization1(true, localDW->diff_num_b, localDW->diff_denom_k);

   /* End of Outputs for SubSystem: '<S56>/Initialization1' */

   /* DiscreteTransferFcn: '<S56>/Differentiator' */
   localDW->Differentiator_tmp = ((localDW->Assignment[1] - (localDW->diff_denom_k[1] * localDW->Differentiator_states[0])) -
                                  (localDW->diff_denom_k[2] * localDW->Differentiator_states[1])) -
                                 (localDW->diff_denom_k[3] * localDW->Differentiator_states[2]);
   rtb_delta_t =
      (((localDW->diff_num_b[0] * localDW->Differentiator_tmp) + (localDW->diff_num_b[1] * localDW->Differentiator_states[0])) +
       (localDW->diff_num_b[2] * localDW->Differentiator_states[1])) +
      (localDW->diff_num_b[3] * localDW->Differentiator_states[2]);

   /* DiscreteTransferFcn: '<S57>/Differentiator' */
   localDW->Differentiator_tmp_f = ((localDW->Assignment[0] - (localDW->diff_denom[1] * localDW->Differentiator_states_c[0])) -
                                    (localDW->diff_denom[2] * localDW->Differentiator_states_c[1])) -
                                   (localDW->diff_denom[3] * localDW->Differentiator_states_c[2]);
   rtb_avgResult_n =
      (((localDW->diff_num[0] * localDW->Differentiator_tmp_f) + (localDW->diff_num[1] * localDW->Differentiator_states_c[0])) +
       (localDW->diff_num[2] * localDW->Differentiator_states_c[1])) +
      (localDW->diff_num[3] * localDW->Differentiator_states_c[2]);

   /* If: '<S66>/If1' incorporates:
    *  Constant: '<S50>/Constant'
    *  Constant: '<S51>/Constant'
    *  Constant: '<S52>/Constant'
    *  Constant: '<S53>/Constant'
    *  Constant: '<S54>/Constant'
    *  Constant: '<S55>/Constant'
    *  Constant: '<S66>/Constant'
    *  Constant: '<S66>/Constant2'
    *  Constant: '<S68>/Constant'
    *  Constant: '<S68>/Constant1'
    *  Constant: '<S69>/Constant1'
    *  Constant: '<S69>/Constant2'
    *  DiscreteTransferFcn: '<S57>/Differentiator'
    *  Inport: '<S70>/In1'
    *  Inport: '<S71>/In1'
    *  Logic: '<S44>/Logical Operator'
    *  Logic: '<S68>/Logical Operator'
    *  Logic: '<S69>/Logical Operator'
    *  RelationalOperator: '<S50>/Compare'
    *  RelationalOperator: '<S51>/Compare'
    *  RelationalOperator: '<S52>/Compare'
    *  RelationalOperator: '<S53>/Compare'
    *  RelationalOperator: '<S54>/Compare'
    *  RelationalOperator: '<S55>/Compare'
    *  RelationalOperator: '<S68>/Equal'
    *  RelationalOperator: '<S68>/Equal1'
    *  RelationalOperator: '<S69>/Equal'
    *  RelationalOperator: '<S69>/Equal1'
    */
   if (((((localDW->Assignment[0] < 0.0F) || (localDW->Assignment[0] > 150.0F)) ||
         ((rtb_avgResult_n < -20.0F) || (rtb_avgResult_n > 20.0F))) ||
        (((((((uint32_T)(*rtu_VeVCAN_WhlSpd_FL_QF)) != ACCURATED) || (((uint32_T)(*rtu_VeVCAN_WhlSpd_FR_QF)) != ACCURATED)) ||
           (((uint32_T)(*rtu_VeVCAN_WhlSpd_RL_QF)) != ACCURATED)) ||
          (((uint32_T)(*rtu_VeVCAN_WhlSpd_RR_QF)) != ACCURATED)) ||
         (((uint32_T)(*rtu_VeVCAN_IMU_Ax_QF)) != ACCURATED))) ||
       (((uint32_T)rtb_VeVSE_CorrecrDeltaSysTimeQF) != ACCURATED))
   {
      /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      *rty_VeVSE_EstimatedVxFromABSTCS_QF = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S66>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      *rty_VeVSE_EstimatedVxFromABSTCS_QF = ACCURATED;

      /* End of Outputs for SubSystem: '<S66>/If Action Subsystem1' */
   }

   /* End of If: '<S66>/If1' */

   /* If: '<S58>/If' incorporates:
    *  Constant: '<S58>/Constant'
    *  Constant: '<S58>/Constant2'
    *  Constant: '<S60>/Constant2'
    *  Constant: '<S60>/Constant3'
    *  Constant: '<S61>/Constant_Val_neg_ten'
    *  Constant: '<S61>/Constant_Val_pos_ten'
    *  Constant: '<S62>/Constant'
    *  DiscreteTransferFcn: '<S56>/Differentiator'
    *  Inport: '<S63>/In1'
    *  Inport: '<S64>/In1'
    *  Logic: '<S60>/Logical Operator'
    *  Logic: '<S61>/Logical Operator'
    *  RelationalOperator: '<S60>/Equal'
    *  RelationalOperator: '<S60>/Equal1'
    *  RelationalOperator: '<S61>/Equal'
    *  RelationalOperator: '<S61>/Equal1'
    *  RelationalOperator: '<S62>/Compare'
    */
   if ((((localDW->Assignment[1] < -15.0F) || (localDW->Assignment[1] > 15.0F)) ||
        ((rtb_delta_t < -10.0F) || (rtb_delta_t > 10.0F))) ||
       (((uint32_T)(*rty_VeVSE_EstimatedVxFromABSTCS_QF)) != ACCURATED))
   {
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      *rty_VeVSE_EstimatedAxFromABSTCS_QF = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      *rty_VeVSE_EstimatedAxFromABSTCS_QF = ACCURATED;

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem1' */
   }

   /* End of If: '<S58>/If' */

   /* If: '<S43>/If' incorporates:
    *  Abs: '<S43>/Abs'
    *  Constant: '<S43>/Constant'
    *  Constant: '<S43>/Constant4'
    *  Constant: '<S45>/Constant'
    *  RelationalOperator: '<S43>/GreaterThan'
    *  RelationalOperator: '<S43>/NotEqual'
    *  RelationalOperator: '<S45>/Compare'
    *  RelationalOperator: '<S55>/Compare'
    *  Sum: '<S43>/Add'
    */
   if (((((int32_T)(*rty_VsVSE_u8_ABS_Status)) == 1) || (*rty_VsVSE_b_ASR_Status)) ||
       (((uint32_T)rtb_VeVSE_CorrecrDeltaSysTimeQF) != ACCURATED))
   {
      /* Outputs for IfAction SubSystem: '<S43>/calc_accuracy_level_under_medium_confidence' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      ABS_TCS_Algorithm_calc_accuracy_level_under_medium_confidence(
         rty_VeVSE_EstimatedVxFromABSTCS_AccLvl, rty_VeVSE_EstimatedAxFromABSTCS_AccLvl,
         &ABS_TCS_Algorithm_ConstB.calc_accuracy_level_under_medium_confidence);

      /* End of Outputs for SubSystem: '<S43>/calc_accuracy_level_under_medium_confidence' */
   }
   else if (fabsf(localDW->Assignment[0] - rtb_VsVCAN_mps_MeanWheelLinSpd) > 0.2F)
   {
      /* Outputs for IfAction SubSystem: '<S43>/calc_accuracy_level_under_low_confidence' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      ABS_TCS_Algorithm_calc_accuracy_level_under_medium_confidence(
         rty_VeVSE_EstimatedVxFromABSTCS_AccLvl, rty_VeVSE_EstimatedAxFromABSTCS_AccLvl,
         &ABS_TCS_Algorithm_ConstB.calc_accuracy_level_under_low_confidence);

      /* End of Outputs for SubSystem: '<S43>/calc_accuracy_level_under_low_confidence' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S43>/calc_accuracy_level_under_high_confidence' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      /* SignalConversion: '<S47>/OutportBufferForVeVSE_WhlOdoVehLongAccelAccLvl' */
      *rty_VeVSE_EstimatedAxFromABSTCS_AccLvl = ABS_TCS_Algorithm_ConstB.In1;

      /* SignalConversion: '<S47>/OutportBufferForVeVSE_WhlOdoVehLongSpdAccLvl' */
      *rty_VeVSE_EstimatedVxFromABSTCS_AccLvl = ABS_TCS_Algorithm_ConstB.In1;

      /* End of Outputs for SubSystem: '<S43>/calc_accuracy_level_under_high_confidence' */
   }

   /* End of If: '<S43>/If' */

   /* SignalConversion: '<Root>/TmpSignal ConversionAtVsVSE_mps_WhlOdoVehAxFromABSTCSInport1' */
   *rty_VsVSE_mps_WhlOdoVehAxFromABSTCS = localDW->Assignment[1];

   /* SignalConversion: '<Root>/TmpSignal ConversionAtVsVSE_mps_WhlOdoVehSpeedFromABSTCSInport1' */
   *rty_VsVSE_mps_WhlOdoVehSpeedFromABSTCS = localDW->Assignment[0];

   /* Update for Delay: '<S4>/Resettable Delay' */
   localDW->icLoad                 = 0U;
   localDW->ResettableDelay_DSTATE = *rtu_VsVCAN_u64_SystemTime;

   /* Update for UnitDelay: '<S133>/Unit Delay' */
   localDW->UnitDelay_DSTATE = rtb_VsVSE_mps_TransWhlLinSpd_FL;

   /* Update for UnitDelay: '<S131>/Unit Delay' */
   localDW->UnitDelay_DSTATE_f = rtb_VsVSE_mps_TransWhlLinSpd_FR;

   /* Update for UnitDelay: '<S134>/Unit Delay' */
   localDW->UnitDelay_DSTATE_m = rtb_VsVSE_mps_TransWhlLinSpd_RL;

   /* Update for UnitDelay: '<S132>/Unit Delay' */
   localDW->UnitDelay_DSTATE_n = rtb_VsVSE_mps_TransWhlLinSpd_RR;

   /* Update for UnitDelay: '<S143>/Unit Delay' */
   localDW->UnitDelay_DSTATE_j = rtb_VsVSE_mps_TransWhlLinSpd_FL;

   /* Update for UnitDelay: '<S140>/Unit Delay' */
   localDW->UnitDelay_DSTATE_i = rtb_VsVSE_mps_TransWhlLinSpd_FR;

   /* Update for UnitDelay: '<S141>/Unit Delay' */
   localDW->UnitDelay_DSTATE_e = rtb_VsVSE_mps_TransWhlLinSpd_RL;

   /* Update for UnitDelay: '<S142>/Unit Delay' */
   localDW->UnitDelay_DSTATE_c = rtb_VsVSE_mps_TransWhlLinSpd_RR;

   /* Update for UnitDelay: '<S8>/Unit Delay' */
   localDW->UnitDelay_DSTATE_h = localDW->Assignment[1];

   /* Update for UnitDelay: '<S8>/Unit Delay1' */
   localDW->UnitDelay1_DSTATE_g = localDW->Assignment[0];

   /* Update for UnitDelay: '<S169>/Unit Delay' */
   localDW->UnitDelay_DSTATE_fz = rtb_VsVSE_KFState_Vx;

   /* Update for UnitDelay: '<S169>/Unit Delay3' */
   localDW->bitsForTID0.UnitDelay3_DSTATE_i = rtb_RelationalOperator;

   /* Update for UnitDelay: '<S174>/FixPt Unit Delay2' incorporates:
    *  Constant: '<S174>/FixPt Constant'
    */
   localDW->FixPtUnitDelay2_DSTATE = 0U;

   /* Update for UnitDelay: '<S7>/Unit Delay2' */
   localDW->bitsForTID0.UnitDelay2_DSTATE_i = rtb_ASRStatus_bool_l;

   /* Update for DiscreteFilter: '<S13>/Discrete Filter' */
   localDW->DiscreteFilter_icLoad    = 0U;
   localDW->DiscreteFilter_states[1] = localDW->DiscreteFilter_states[0];
   localDW->DiscreteFilter_states[0] = localDW->DiscreteFilter_tmp;

   /* Update for UnitDelay: '<S22>/FixPt Unit Delay2' incorporates:
    *  Constant: '<S22>/FixPt Constant'
    */
   localDW->FixPtUnitDelay2_DSTATE_e = 0U;

   /* Update for UnitDelay: '<S16>/Unit Delay3' */
   localDW->UnitDelay3_DSTATE[0] = rtb_Transpose[0];
   localDW->UnitDelay3_DSTATE[1] = rtb_Transpose[1];
   localDW->UnitDelay3_DSTATE[2] = rtb_Transpose[2];
   localDW->UnitDelay3_DSTATE[3] = rtb_Transpose[3];

   /* Update for DiscreteTransferFcn: '<S56>/Differentiator' */
   localDW->Differentiator_states[2] = localDW->Differentiator_states[1];
   localDW->Differentiator_states[1] = localDW->Differentiator_states[0];
   localDW->Differentiator_states[0] = localDW->Differentiator_tmp;

   /* Update for DiscreteTransferFcn: '<S57>/Differentiator' */
   localDW->Differentiator_states_c[2] = localDW->Differentiator_states_c[1];
   localDW->Differentiator_states_c[1] = localDW->Differentiator_states_c[0];
   localDW->Differentiator_states_c[0] = localDW->Differentiator_tmp_f;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
