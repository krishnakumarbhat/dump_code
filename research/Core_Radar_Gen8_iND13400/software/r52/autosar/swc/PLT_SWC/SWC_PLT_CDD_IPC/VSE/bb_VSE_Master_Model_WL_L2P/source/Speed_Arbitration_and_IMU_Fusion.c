/*
 * File: Speed_Arbitration_and_IMU_Fusion.c
 *
 * Code generated for Simulink model 'Speed_Arbitration_and_IMU_Fusion'.
 *
 * Model version                  : 1.1412
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:59 2026
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

#include "Speed_Arbitration_and_IMU_Fusion.h"
#include "MultiWordSub_Aptiv.h"
#include "MultiWordUnsignedWrap_Aptiv.h"
#include "Speed_Arbitration_and_IMU_Fusion_private.h"
#include "rt_mrdividef2x2_Aptiv.h"
#include "sMultiWord2uMultiWordSat_Aptiv.h"
#include "uLong2MultiWord_Aptiv.h"
#include "uMultiWord2MultiWord_Aptiv.h"
#include "uMultiWord2uMultiWordSat_Aptiv.h"
#include "uMultiWordShl_Aptiv.h"
#include "uMultiWordShr_Aptiv.h"
#include "uMultiWordSingle_Aptiv.h"

/* Named constants for Chart: '<S57>/Debouncer' */
#define Speed_Arbitration_and_IMU_Fusion_IN_Debounce        ((uint8_T)1U)
#define Speed_Arbitration_and_IMU_Fusion_IN_Fault           ((uint8_T)1U)
#define Speed_Arbitration_and_IMU_Fusion_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Speed_Arbitration_and_IMU_Fusion_IN_Normal          ((uint8_T)2U)
#define Speed_Arbitration_and_IMU_Fusion_IN_Off             ((uint8_T)2U)
#define Speed_Arbitration_and_IMU_Fusion_IN_Off_c           ((uint8_T)1U)
#define Speed_Arbitration_and_IMU_Fusion_IN_On              ((uint8_T)3U)
#define Speed_Arbitration_and_IMU_Fusion_IN_On_e            ((uint8_T)2U)

/* Forward declaration for local functions */
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_release(
   dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_delete(dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_matlabCodegenHandle_matlabCodegenDestructor(
   dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_release_m(dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_releaseWrapper(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_release_mt(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_delete_as(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_matlabCodegenHandle_matlabCodegenDestructor_go(
   dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_SystemCore_delete_a(dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);
static void Speed_Arbitration_and_IMU_Fusion_matlabCodegenHandle_matlabCodegenDestructor_g(
   dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *obj);

/*
 * Output and update for action system:
 *    '<S23>/calc_accuracy_level_under_medium_confidence'
 *    '<S23>/calc_accuracy_level_under_low_confidence'
 */
void Speed_Arbitration_and_IMU_Fusion_calc_accuracy_level_under_medium_confidence(
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongSpdAccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoVehLongAccelAccLvl,
   const ConstB_calc_accuracy_level_under_medium_confidence_Speed_Arbitration_and_IMU_Fusion_T *localC)
{
   /* SignalConversion: '<S27>/OutportBufferForVeVSE_WhlOdoVehLongAccelAccLvl' */
   *rty_VeVSE_WhlOdoVehLongAccelAccLvl = localC->In1;

   /* SignalConversion: '<S27>/OutportBufferForVeVSE_WhlOdoVehLongSpdAccLvl' */
   *rty_VeVSE_WhlOdoVehLongSpdAccLvl = localC->In1;
}

/*
 * Output and update for enable system:
 *    '<S30>/Initialization1'
 *    '<S31>/Initialization'
 */
void Speed_Arbitration_and_IMU_Fusion_Initialization1(uint8_T rtu_Enable, real32_T rty_diff_num[4], real32_T rty_diff_denom[4])
{
   /* Outputs for Enabled SubSystem: '<S30>/Initialization1' incorporates:
    *  EnablePort: '<S33>/Enable'
    */
   if (((int32_T)rtu_Enable) > 0)
   {
      /* MATLAB Function: '<S33>/find_Differentiator_Coeff' */
      rty_diff_num[0]   = 0.724336267F;
      rty_diff_denom[0] = 1.0F;
      rty_diff_num[1]   = 0.724336267F;
      rty_diff_denom[1] = -0.822694957F;
      rty_diff_num[2]   = -0.724336267F;
      rty_diff_denom[2] = -0.98551327F;
      rty_diff_num[3]   = -0.724336267F;
      rty_diff_denom[3] = 0.837181628F;
   }

   /* End of Outputs for SubSystem: '<S30>/Initialization1' */
}

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_release(dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj_0;
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

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_delete(dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   Speed_Arbitration_and_IMU_Fusion_SystemCore_release(obj);
}

static void Speed_Arbitration_and_IMU_Fusion_matlabCodegenHandle_matlabCodegenDestructor(
   dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   if (!obj->matlabCodegenIsDeleted)
   {
      obj->matlabCodegenIsDeleted = true;
      Speed_Arbitration_and_IMU_Fusion_SystemCore_delete(obj);
   }
}

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_release_m(dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   if (obj->isInitialized == 1)
   {
      obj->isInitialized = 2;
   }
}

static void Speed_Arbitration_and_IMU_Fusion_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   Speed_Arbitration_and_IMU_Fusion_SystemCore_release_m(obj->FilterObj);
   obj->NumChannels = -1;
}

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_releaseWrapper(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   if (obj->isSetupComplete)
   {
      Speed_Arbitration_and_IMU_Fusion_LPHPFilterBase_releaseImpl(obj);
   }
}

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_release_mt(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   if (obj->isInitialized == 1)
   {
      Speed_Arbitration_and_IMU_Fusion_SystemCore_releaseWrapper(obj);
   }
}

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_delete_as(dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   Speed_Arbitration_and_IMU_Fusion_SystemCore_release_mt(obj);
}

static void Speed_Arbitration_and_IMU_Fusion_matlabCodegenHandle_matlabCodegenDestructor_go(
   dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   if (!obj->matlabCodegenIsDeleted)
   {
      obj->matlabCodegenIsDeleted = true;
      Speed_Arbitration_and_IMU_Fusion_SystemCore_delete_as(obj);
   }
}

static void Speed_Arbitration_and_IMU_Fusion_SystemCore_delete_a(dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   Speed_Arbitration_and_IMU_Fusion_SystemCore_release_m(obj);
}

static void Speed_Arbitration_and_IMU_Fusion_matlabCodegenHandle_matlabCodegenDestructor_g(
   dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *obj)
{
   if (!obj->matlabCodegenIsDeleted)
   {
      obj->matlabCodegenIsDeleted = true;
      Speed_Arbitration_and_IMU_Fusion_SystemCore_delete_a(obj);
   }
}

/* System initialize for referenced model: 'Speed_Arbitration_and_IMU_Fusion' */
void Speed_Arbitration_and_IMU_Fusion_Init(DW_Speed_Arbitration_and_IMU_Fusion_f_T *localDW)
{
   /* InitializeConditions for UnitDelay: '<S19>/P_delay' */
   localDW->P_delay_DSTATE[0] = 2.0F;
   localDW->P_delay_DSTATE[1] = 0.0F;
   localDW->P_delay_DSTATE[2] = 0.0F;
   localDW->P_delay_DSTATE[3] = 100.0F;

   /* InitializeConditions for Delay: '<S7>/Resettable Delay' */
   localDW->icLoad = 1U;

   /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
   localDW->UnitDelay_DSTATE_n = 1U;

   /* InitializeConditions for UnitDelay: '<S66>/FixPt Unit Delay2' */
   localDW->FixPtUnitDelay2_DSTATE = 1U;

   /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
   localDW->UnitDelay_DSTATE_j = 1U;

   /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
   localDW->UnitDelay_DSTATE_fa = 1U;

   /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
   localDW->UnitDelay_DSTATE_m = 1U;

   /* InitializeConditions for UnitDelay: '<S22>/FixPt Unit Delay2' */
   localDW->FixPtUnitDelay2_DSTATE_j = 1U;

   /* InitializeConditions for MATLABSystem: '<S15>/Moving Average' */
   if (localDW->obj.pStatistic->isInitialized == 1)
   {
      localDW->obj.pStatistic->pwN = 1.0F;
      localDW->obj.pStatistic->pmN = 0.0F;
   }

   /* End of InitializeConditions for MATLABSystem: '<S15>/Moving Average' */

   /* InitializeConditions for MATLABSystem: '<S16>/Lowpass Filter' */
   if (localDW->obj_n.FilterObj->isInitialized == 1)
   {
      /* System object Initialization function: dsp.BiquadFilter */
      localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[0] = localDW->obj_n.FilterObj->cSFunObject.P0_ICRTP;
      localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[0] = localDW->obj_n.FilterObj->cSFunObject.P5_IC2RTP;
      localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[1] = localDW->obj_n.FilterObj->cSFunObject.P0_ICRTP;
      localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[1] = localDW->obj_n.FilterObj->cSFunObject.P5_IC2RTP;
   }

   /* End of InitializeConditions for MATLABSystem: '<S16>/Lowpass Filter' */
}

/* Start for referenced model: 'Speed_Arbitration_and_IMU_Fusion' */
void Speed_Arbitration_and_IMU_Fusion_Start(DW_Speed_Arbitration_and_IMU_Fusion_f_T *localDW)
{
   boolean_T flag;
   dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *iobj_0;

   /* Start for MATLABSystem: '<S15>/Moving Average' */
   localDW->obj.matlabCodegenIsDeleted = true;
   localDW->obj.isInitialized          = 0;
   localDW->obj.NumChannels            = -1;
   localDW->obj.matlabCodegenIsDeleted = false;
   localDW->bitsForTID0.objisempty_j   = true;
   if (localDW->obj.isInitialized == 1)
   {
      localDW->obj.TunablePropsChanged = true;
   }

   localDW->obj.ForgettingFactor   = 0.99F;
   localDW->obj.isSetupComplete    = false;
   localDW->obj.isInitialized      = 1;
   localDW->obj.NumChannels        = 1;
   localDW->gobj_0_d.isInitialized = 0;
   flag                            = (localDW->gobj_0_d.isInitialized == 1);
   if (flag)
   {
      localDW->gobj_0_d.TunablePropsChanged = true;
   }

   localDW->gobj_0_d.ForgettingFactor = localDW->obj.ForgettingFactor;
   localDW->obj.pStatistic            = &localDW->gobj_0_d;
   localDW->obj.isSetupComplete       = true;
   localDW->obj.TunablePropsChanged   = false;

   /* End of Start for MATLABSystem: '<S15>/Moving Average' */

   /* Start for MATLABSystem: '<S16>/Lowpass Filter' */
   localDW->gobj_1.matlabCodegenIsDeleted = true;
   localDW->gobj_0.matlabCodegenIsDeleted = true;
   localDW->obj_n.matlabCodegenIsDeleted  = true;
   localDW->obj_n.isInitialized           = 0;
   localDW->obj_n.NumChannels             = -1;
   localDW->obj_n.matlabCodegenIsDeleted  = false;
   localDW->bitsForTID0.objisempty        = true;
   iobj_0                                 = &localDW->gobj_0;
   localDW->obj_n.isSetupComplete         = false;
   localDW->obj_n.isInitialized           = 1;
   localDW->gobj_0.isInitialized          = 0;

   /* System object Constructor function: dsp.BiquadFilter */
   iobj_0->cSFunObject.P0_ICRTP              = 0.0F;
   iobj_0->cSFunObject.P1_RTP1COEFF[0]       = 0.226032734F;
   iobj_0->cSFunObject.P1_RTP1COEFF[1]       = 0.226032734F;
   iobj_0->cSFunObject.P1_RTP1COEFF[2]       = 0.0F;
   iobj_0->cSFunObject.P2_RTP2COEFF[0]       = -0.547934532F;
   iobj_0->cSFunObject.P2_RTP2COEFF[1]       = 0.0F;
   iobj_0->cSFunObject.P3_RTP3COEFF[0]       = 0.0F;
   iobj_0->cSFunObject.P3_RTP3COEFF[1]       = 0.0F;
   iobj_0->cSFunObject.P4_RTP_COEFF3_BOOL[0] = false;
   iobj_0->cSFunObject.P4_RTP_COEFF3_BOOL[1] = false;
   iobj_0->cSFunObject.P5_IC2RTP             = 0.0F;
   localDW->gobj_0.matlabCodegenIsDeleted    = false;
   localDW->obj_n.FilterObj                  = &localDW->gobj_0;
   localDW->obj_n.NumChannels                = 1;
   localDW->obj_n.isSetupComplete            = true;
}

/* Output and update for referenced model: 'Speed_Arbitration_and_IMU_Fusion' */
void Speed_Arbitration_and_IMU_Fusion(
   const real32_T *rtu_Raw_IMU_Ax, const real32_T *rtu_EstimatedVx_FromABSTCS,
   const enum_quality_factor_T *rtu_EstimatedVxForABSTCS_QF, const enum_quality_factor_T *rtu_EstimatedAxForABSTCS_QF,
   const uint8_T *rtu_VsVCAN_u8_WhlSpin_FL, const uint8_T *rtu_VsVCAN_u8_WhlSpin_FR, const uint8_T *rtu_VsVCAN_u8_WhlSpin_RL,
   const uint8_T *rtu_VsVCAN_u8_WhlSpin_RR, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FL,
   const real32_T *rtu_VsVCAN_mps_WheelLinSpd_FR, const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RL,
   const real32_T *rtu_VsVCAN_mps_WheelLinSpd_RR, const uint64_T *rtu_VsVCAN_u64_SystemTime,
   const uint8_T *rtu_VsVCAN_u8_BrakeState, const real32_T *rtu_whl_tck_spd_fl, const real32_T *rtu_whl_tck_spd_fr,
   const real32_T *rtu_whl_tck_spd_rl, const real32_T *rtu_whl_tck_spd_rr, const boolean_T *rtu_WhlTckIsZeroForLongerTime,
   const uint8_T *rtu_ABS_Status, const uint8_T *rtu_VsVCAN_u8_GearBsdRvrsStat, real32_T *rty_VsVSE_mps_WhlOdoArbitratedVehSpeed,
   real32_T *rty_VsVSE_mps2_WhlOdoArbitratedVehLongAccel, enum_quality_factor_T *rty_VeVSE_WhlOdoArbitratedVehSpeed_QF,
   enum_quality_factor_T *rty_VeVSE_WhlOdoArbitratedAx_QF, enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoArbitratedVx_AccLvl,
   enum_accuracy_level_wheelodo_T *rty_VeVSE_WhlOdoArbitratedAx_AccLvl, real32_T *rty_VsVSE_mps2_WhlOdoLongAcclFromEstimWhlSpd,
   DW_Speed_Arbitration_and_IMU_Fusion_f_T *localDW)
{
   int32_T nonZeroCount;
   real32_T pmLocal;
   real32_T rtb_Divide[4];
   real32_T rtb_Add_m4[4];
   boolean_T rtb_IsVehInSlowMotion;
   boolean_T rtb_veh_decelerating;
   real32_T rtb_measAx_BeforeLPF;
   enum_quality_factor_T rtb_VeVSE_CorrecrDeltaSysTimeQF;
   real32_T rtb_Differentiator;
   real32_T rtb_VsVCAN_mps_MeanWheelLinSpd;
   boolean_T rtb_veh_reverse_status;
   boolean_T rtb_VehStationaryForAxOffs_out;
   real32_T rtb_avgResult;
   real32_T rtb_delta_t;
   real32_T P_delay_DSTATE_tmp[4];
   real32_T rtb_Divide_0[4];
   real32_T rtb_Z_idx_1;
   int32_T rtb_H_idx_3;
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
   real32_T rtb_VehStationaryForAxOffs_out_0;
   int32_T rtb_Divide_tmp;
   int32_T rtb_H_tmp;

   /* Delay: '<S7>/Resettable Delay' */
   if (((int32_T)localDW->icLoad) != 0)
   {
      localDW->ResettableDelay_DSTATE = *rtu_VsVCAN_u64_SystemTime;
   }

   /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
    *  Delay: '<S7>/Resettable Delay'
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

   /* If: '<S7>/If' incorporates:
    *  Constant: '<S7>/Constant'
    *  Inport: '<S48>/VsVCAN_s_DefaultDeltaSystemTime'
    */
   if ((rtb_delta_t <= 0.005F) || (rtb_delta_t >= 0.08F))
   {
      /* Outputs for IfAction SubSystem: '<S7>/calc_corrected_delta_sys_time_under_extreme_cases' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* SignalConversion: '<S48>/OutportBuffer_InsertedFor_VeVSE_CorrecrDeltaSysTimeQF_at_inport_0' incorporates:
       *  Constant: '<S48>/Constant'
       */
      rtb_VeVSE_CorrecrDeltaSysTimeQF = NOT_ACCURATED;
      rtb_delta_t                     = 0.01F;

      /* End of Outputs for SubSystem: '<S7>/calc_corrected_delta_sys_time_under_extreme_cases' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S7>/calc_corrected_delta_sys_time_under_normal_cases' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      /* SignalConversion: '<S49>/OutportBuffer_InsertedFor_VeVSE_CorrecrDeltaSysTimeQF_at_inport_0' incorporates:
       *  Constant: '<S49>/Constant'
       */
      rtb_VeVSE_CorrecrDeltaSysTimeQF = ACCURATED;

      /* End of Outputs for SubSystem: '<S7>/calc_corrected_delta_sys_time_under_normal_cases' */
   }

   /* End of If: '<S7>/If' */

   /* Product: '<S19>/A*P_prevEstim' incorporates:
    *  MATLAB Function: '<Root>/A_matrix_4x4'
    *  UnitDelay: '<S19>/P_delay'
    */
   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      rtb_H_idx_3             = (nonZeroCount << 1);
      rtb_Divide[rtb_H_idx_3] = 0.0F;
      rtb_Divide[rtb_H_idx_3] += localDW->P_delay_DSTATE[rtb_H_idx_3];
      rtb_Divide_tmp = rtb_H_idx_3 + 1;
      rtb_Divide[rtb_H_idx_3] += localDW->P_delay_DSTATE[rtb_Divide_tmp] * rtb_delta_t;
      rtb_H_idx_3++;
      rtb_Divide[rtb_H_idx_3] = 0.0F;
      rtb_Divide[rtb_H_idx_3] = rtb_Divide[rtb_Divide_tmp] + localDW->P_delay_DSTATE[(nonZeroCount << 1) + 1];
   }

   /* End of Product: '<S19>/A*P_prevEstim' */

   /* Math: '<S19>/Transpose' incorporates:
    *  MATLAB Function: '<Root>/A_matrix_4x4'
    *  UnitDelay: '<S19>/P_delay'
    */
   localDW->P_delay_DSTATE[0] = 1.0F;
   localDW->P_delay_DSTATE[1] = rtb_delta_t;
   localDW->P_delay_DSTATE[2] = 0.0F;
   localDW->P_delay_DSTATE[3] = 1.0F;

   /* MATLAB Function: '<S14>/MATLAB Function2' */
   nonZeroCount = ((((int32_T)(((*rtu_whl_tck_spd_fl) > 0.0F) ? 1 : 0)) + ((int32_T)(((*rtu_whl_tck_spd_fr) > 0.0F) ? 1 : 0))) +
                   ((int32_T)(((*rtu_whl_tck_spd_rl) > 0.0F) ? 1 : 0))) +
                  ((int32_T)(((*rtu_whl_tck_spd_rr) > 0.0F) ? 1 : 0));
   if (nonZeroCount == 0)
   {
      rtb_avgResult = 0.0F;
   }
   else
   {
      rtb_avgResult = ((((*rtu_whl_tck_spd_fl) + (*rtu_whl_tck_spd_fr)) + (*rtu_whl_tck_spd_rl)) + (*rtu_whl_tck_spd_rr)) /
                      ((real32_T)nonZeroCount);
   }

   /* End of MATLAB Function: '<S14>/MATLAB Function2' */

   /* Product: '<S8>/Divide' incorporates:
    *  Constant: '<S8>/Constant'
    *  Sum: '<S8>/Add'
    */
   rtb_VsVCAN_mps_MeanWheelLinSpd =
      ((((*rtu_VsVCAN_mps_WheelLinSpd_FL) + (*rtu_VsVCAN_mps_WheelLinSpd_FR)) + (*rtu_VsVCAN_mps_WheelLinSpd_RL)) +
       (*rtu_VsVCAN_mps_WheelLinSpd_RR)) /
      4.0F;

   /* Outputs for Enabled SubSystem: '<S53>/Differentiator Generator' incorporates:
    *  EnablePort: '<S54>/Enable'
    */
   /* Switch: '<S53>/Switch' incorporates:
    *  UnitDelay: '<S53>/Unit Delay'
    */
   if (((int32_T)localDW->UnitDelay_DSTATE_n) != 0)
   {
      /* MATLAB Function: '<S54>/FindDifferentiatorCoeff' */
      localDW->diff_num[0]   = 0.724336267F;
      localDW->diff_denom[0] = 1.0F;
      localDW->diff_num[1]   = 0.724336267F;
      localDW->diff_denom[1] = -0.822694957F;
      localDW->diff_num[2]   = -0.724336267F;
      localDW->diff_denom[2] = -0.98551327F;
      localDW->diff_num[3]   = -0.724336267F;
      localDW->diff_denom[3] = 0.837181628F;
   }

   /* End of Switch: '<S53>/Switch' */
   /* End of Outputs for SubSystem: '<S53>/Differentiator Generator' */

   /* DiscreteTransferFcn: '<S53>/Differentiator' */
   localDW->Differentiator_tmp = ((rtb_VsVCAN_mps_MeanWheelLinSpd - (localDW->diff_denom[1] * localDW->Differentiator_states[0])) -
                                  (localDW->diff_denom[2] * localDW->Differentiator_states[1])) -
                                 (localDW->diff_denom[3] * localDW->Differentiator_states[2]);
   localDW->Differentiator =
      (((localDW->diff_num[0] * localDW->Differentiator_tmp) + (localDW->diff_num[1] * localDW->Differentiator_states[0])) +
       (localDW->diff_num[2] * localDW->Differentiator_states[1])) +
      (localDW->diff_num[3] * localDW->Differentiator_states[2]);

   /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
    *  UnitDelay: '<S10>/Unit Delay'
    */
   rtb_veh_decelerating = false;
   if (localDW->Differentiator < -0.5F)
   {
      nonZeroCount = (int32_T)((uint32_T)(((uint32_T)localDW->UnitDelay_DSTATE_b) + 1U));
      if (((uint32_T)nonZeroCount) > 255U)
      {
         nonZeroCount = 255;
      }

      localDW->UnitDelay_DSTATE_b = (uint8_T)nonZeroCount;
      if (((int32_T)((uint8_T)nonZeroCount)) >= 5)
      {
         localDW->UnitDelay_DSTATE_b = 5U;
      }
   }

   if (((((uint32_T)localDW->UnitDelay_DSTATE_b) >= 5U) || (((int32_T)(*rtu_VsVCAN_u8_BrakeState)) == 1)) &&
       (rtb_VsVCAN_mps_MeanWheelLinSpd < 1.5F))
   {
      rtb_veh_decelerating        = true;
      localDW->UnitDelay_DSTATE_b = 5U;
   }

   if (localDW->Differentiator > -0.5F)
   {
      localDW->UnitDelay_DSTATE_b = 0U;
   }

   /* End of MATLAB Function: '<S10>/MATLAB Function' */

   /* MATLAB Function: '<S14>/MATLAB Function1' incorporates:
    *  UnitDelay: '<S14>/Unit Delay2'
    */
   if (((real_T)(*rtu_EstimatedVx_FromABSTCS)) < 0.6)
   {
      rtb_Differentiator = 1.0F;
   }
   else if ((*rtu_EstimatedVx_FromABSTCS) <= 1.0F)
   {
      rtb_Differentiator = 1.0F - (((*rtu_EstimatedVx_FromABSTCS) - 0.6F) / 0.4F);
   }
   else
   {
      rtb_Differentiator = 0.0F;
   }

   if ((((((((int32_T)(*rtu_ABS_Status)) == 0) && (((int32_T)localDW->UnitDelay2_DSTATE) != 0)) && rtb_veh_decelerating) ||
         (localDW->bitsForTID0.ABS_State_Transition)) ||
        (((int32_T)(*rtu_ABS_Status)) != 0)) ||
       ((rtb_veh_decelerating && (*rtu_WhlTckIsZeroForLongerTime)) && ((*rtu_EstimatedVx_FromABSTCS) > 0.2F)))
   {
      rtb_Differentiator                        = 0.0F;
      localDW->bitsForTID0.ABS_State_Transition = true;
   }

   if (!rtb_veh_decelerating)
   {
      localDW->bitsForTID0.ABS_State_Transition = false;
   }

   rtb_avgResult = ((1.0F - rtb_Differentiator) * (*rtu_EstimatedVx_FromABSTCS)) + (rtb_avgResult * rtb_Differentiator);

   /* End of MATLAB Function: '<S14>/MATLAB Function1' */

   /* Switch: '<S66>/Init' incorporates:
    *  UnitDelay: '<S66>/FixPt Unit Delay1'
    *  UnitDelay: '<S66>/FixPt Unit Delay2'
    */
   if (((int32_T)localDW->FixPtUnitDelay2_DSTATE) != 0)
   {
      localDW->FixPtUnitDelay1_DSTATE = rtb_avgResult;
   }

   /* End of Switch: '<S66>/Init' */

   /* MATLAB Function: '<S14>/MATLAB Function' */
   if ((rtb_avgResult < 1.0F) && rtb_veh_decelerating)
   {
      nonZeroCount = 2;
   }
   else if (rtb_avgResult < 1.0F)
   {
      nonZeroCount = 4;
   }
   else
   {
      nonZeroCount = 7;
   }

   /* End of MATLAB Function: '<S14>/MATLAB Function' */

   /* Product: '<S65>/one_by_twoPiFc' incorporates:
    *  Constant: '<S65>/Constant1'
    *  Constant: '<S65>/Constant2'
    *  Constant: '<S65>/Pi'
    *  Product: '<S65>/Divide4'
    */
   rtb_Differentiator = 1.0F / (6.28318548F * ((real32_T)nonZeroCount));

   /* Product: '<S61>/Divide1' incorporates:
    *  Constant: '<S14>/Constant4'
    *  Product: '<S61>/Divide2'
    *  Product: '<S61>/Divide3'
    *  Sum: '<S61>/Add1'
    *  Sum: '<S61>/Add2'
    *  UnitDelay: '<S66>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE =
      ((rtb_avgResult * 0.01F) + (localDW->FixPtUnitDelay1_DSTATE * rtb_Differentiator)) / (rtb_Differentiator + 0.01F);

   /* Switch: '<S14>/Switch1' incorporates:
    *  Constant: '<S14>/Constant5'
    *  Constant: '<S14>/Constant6'
    *  RelationalOperator: '<S14>/GreaterThan1'
    *  UnitDelay: '<S66>/FixPt Unit Delay1'
    */
   if (((real_T)localDW->FixPtUnitDelay1_DSTATE) < 0.001)
   {
      rtb_avgResult = 0.0F;
   }
   else
   {
      rtb_avgResult = localDW->FixPtUnitDelay1_DSTATE;
   }

   /* End of Switch: '<S14>/Switch1' */

   /* MATLAB Function: '<Root>/Q_mat' */
   rtb_Differentiator = rtb_delta_t * rtb_delta_t;

   /* Product: '<S19>/A*P*At' incorporates:
    *  UnitDelay: '<S19>/P_delay'
    */
   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      rtb_H_idx_3               = (nonZeroCount << 1);
      rtb_Divide_0[rtb_H_idx_3] = 0.0F;
      rtb_Divide_0[rtb_H_idx_3] += localDW->P_delay_DSTATE[rtb_H_idx_3] * rtb_Divide[0];
      rtb_Divide_tmp = rtb_H_idx_3 + 1;
      rtb_Divide_0[rtb_H_idx_3] += localDW->P_delay_DSTATE[rtb_Divide_tmp] * rtb_Divide[2];
      rtb_H_idx_3++;
      rtb_Divide_0[rtb_H_idx_3] = 0.0F;
      rtb_Divide_0[rtb_H_idx_3] += localDW->P_delay_DSTATE[nonZeroCount << 1] * rtb_Divide[1];
      rtb_Divide_0[rtb_H_idx_3] += localDW->P_delay_DSTATE[(nonZeroCount << 1) + 1] * rtb_Divide[3];
   }

   /* End of Product: '<S19>/A*P*At' */

   /* Sum: '<S19>/Add' incorporates:
    *  Constant: '<Root>/Constant'
    *  Constant: '<Root>/Constant1'
    *  MATLAB Function: '<Root>/Q_mat'
    */
   rtb_Add_m4[0] = ((((rtb_Differentiator * rtb_delta_t) / 3.0F) * 100.0F) + (16.0F * rtb_delta_t)) + rtb_Divide_0[0];

   /* MATLAB Function: '<Root>/Q_mat' incorporates:
    *  Constant: '<Root>/Constant1'
    */
   rtb_Differentiator = (rtb_Differentiator / 2.0F) * 100.0F;

   /* Sum: '<S19>/Add' incorporates:
    *  Constant: '<Root>/Constant1'
    *  MATLAB Function: '<Root>/Q_mat'
    */
   rtb_Add_m4[1] = rtb_Differentiator + rtb_Divide_0[1];
   rtb_Add_m4[2] = rtb_Differentiator + rtb_Divide_0[2];
   rtb_Add_m4[3] = (100.0F * rtb_delta_t) + rtb_Divide_0[3];

   /* MATLAB Function: '<S13>/MATLAB Function' incorporates:
    *  MATLAB Function: '<Root>/Z_H_R_Design'
    *  MATLAB Function: '<S12>/MATLAB Function'
    *  UnitDelay: '<S13>/Unit Delay'
    *  UnitDelay: '<S13>/Unit Delay2'
    */
   rtb_VehStationaryForAxOffs_out = localDW->bitsForTID0.UnitDelay2_DSTATE_l;
   rtb_Differentiator             = fabsf(rtb_avgResult);
   if (rtb_Differentiator < 2.22044605E-16F)
   {
      qY = localDW->UnitDelay_DSTATE + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->UnitDelay_DSTATE)
      {
         qY = MAX_uint32_T;
      }
   }
   else
   {
      qY                             = 0U;
      rtb_VehStationaryForAxOffs_out = false;
   }

   if (qY >= 10U)
   {
      rtb_VehStationaryForAxOffs_out = true;
   }

   localDW->UnitDelay_DSTATE = qY;

   /* End of MATLAB Function: '<S13>/MATLAB Function' */

   /* MATLABSystem: '<S15>/Moving Average' */
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
      rtb_veh_reverse_status           = (localDW->obj.pStatistic->isInitialized == 1);
      if (rtb_veh_reverse_status)
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

   rtb_Z_idx_1          = localDW->obj.pStatistic->pwN;
   pmLocal              = localDW->obj.pStatistic->pmN;
   rtb_measAx_BeforeLPF = localDW->obj.pStatistic->plambda;

   /* Switch: '<S15>/Switch' incorporates:
    *  Constant: '<S15>/Constant'
    */
   if (rtb_VehStationaryForAxOffs_out)
   {
      rtb_VehStationaryForAxOffs_out_0 = *rtu_Raw_IMU_Ax;
   }
   else
   {
      rtb_VehStationaryForAxOffs_out_0 = 0.0F;
   }

   /* End of Switch: '<S15>/Switch' */

   /* MATLABSystem: '<S15>/Moving Average' */
   pmLocal = ((1.0F - (1.0F / rtb_Z_idx_1)) * pmLocal) + ((1.0F / rtb_Z_idx_1) * rtb_VehStationaryForAxOffs_out_0);
   localDW->obj.pStatistic->pwN = (rtb_measAx_BeforeLPF * rtb_Z_idx_1) + 1.0F;
   localDW->obj.pStatistic->pmN = pmLocal;

   /* MATLAB Function: '<S15>/MATLAB Function1' incorporates:
    *  MATLABSystem: '<S15>/Moving Average'
    */
   if (!localDW->bitsForTID0.last_inp_not_empty)
   {
      localDW->last_inp                       = pmLocal;
      localDW->bitsForTID0.last_inp_not_empty = true;
   }

   if (rtb_VehStationaryForAxOffs_out)
   {
      localDW->last_inp = pmLocal;
   }

   /* End of MATLAB Function: '<S15>/MATLAB Function1' */

   /* MATLAB Function: '<S11>/MATLAB Function' */
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
      if ((fabsf(rtb_VsVCAN_mps_MeanWheelLinSpd) < 1.0E-6F) && (((int32_T)(*rtu_VsVCAN_u8_GearBsdRvrsStat)) == 1))
      {
         rtb_veh_reverse_status = true;
      }
   }

   /* End of MATLAB Function: '<S11>/MATLAB Function' */

   /* Switch: '<S16>/Switch' incorporates:
    *  Product: '<S16>/Multiply'
    *  Sum: '<S2>/Add'
    */
   if (rtb_veh_reverse_status)
   {
      rtb_measAx_BeforeLPF = -((*rtu_Raw_IMU_Ax) - localDW->last_inp);
   }
   else
   {
      rtb_measAx_BeforeLPF = (*rtu_Raw_IMU_Ax) - localDW->last_inp;
   }

   /* End of Switch: '<S16>/Switch' */

   /* MATLABSystem: '<S16>/Lowpass Filter' */
   if (localDW->obj_n.FilterObj->isInitialized != 1)
   {
      localDW->obj_n.FilterObj->isSetupComplete = false;
      localDW->obj_n.FilterObj->isInitialized   = 1;
      localDW->obj_n.FilterObj->isSetupComplete = true;

      /* System object Initialization function: dsp.BiquadFilter */
      localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[0] = localDW->obj_n.FilterObj->cSFunObject.P0_ICRTP;
      localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[0] = localDW->obj_n.FilterObj->cSFunObject.P5_IC2RTP;
      localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[1] = localDW->obj_n.FilterObj->cSFunObject.P0_ICRTP;
      localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[1] = localDW->obj_n.FilterObj->cSFunObject.P5_IC2RTP;
   }

   /* System object Outputs function: dsp.BiquadFilter */
   rtb_Z_idx_1 = localDW->obj_n.FilterObj->cSFunObject.P1_RTP1COEFF[0] * rtb_measAx_BeforeLPF;
   rtb_Z_idx_1 += localDW->obj_n.FilterObj->cSFunObject.P1_RTP1COEFF[1] * localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[0];
   rtb_Z_idx_1 += localDW->obj_n.FilterObj->cSFunObject.P1_RTP1COEFF[2] * localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[1];
   rtb_Z_idx_1 -= localDW->obj_n.FilterObj->cSFunObject.P2_RTP2COEFF[0] * localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[0];
   rtb_Z_idx_1 -= localDW->obj_n.FilterObj->cSFunObject.P2_RTP2COEFF[1] * localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[1];
   localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[1] = localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[0];
   localDW->obj_n.FilterObj->cSFunObject.W0_ZERO_STATES[0] = rtb_measAx_BeforeLPF;
   localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[1] = localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[0];
   localDW->obj_n.FilterObj->cSFunObject.W1_POLE_STATES[0] = rtb_Z_idx_1;

   /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
    *  UnitDelay: '<S12>/Unit Delay'
    *  UnitDelay: '<S12>/Unit Delay1'
    *  UnitDelay: '<S12>/Unit Delay3'
    *  UnitDelay: '<S12>/Unit Delay4'
    */
   rtb_veh_reverse_status = localDW->bitsForTID0.UnitDelay4_DSTATE;
   if (rtb_Differentiator < 2.22044605E-16F)
   {
      qY = localDW->UnitDelay_DSTATE_f + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->UnitDelay_DSTATE_f)
      {
         qY = MAX_uint32_T;
      }
   }
   else
   {
      qY = 0U;
   }

   if ((rtb_Differentiator > 2.22044605E-16F) && (fabsf(localDW->UnitDelay1_DSTATE) <= 2.22044605E-16F))
   {
      rtb_IsVehInSlowMotion = true;
   }
   else
   {
      rtb_IsVehInSlowMotion = ((localDW->bitsForTID0.UnitDelay3_DSTATE) && (rtb_Differentiator < 1.0F));
   }

   if (qY > 500U)
   {
      rtb_veh_reverse_status = true;
   }

   if (rtb_Differentiator >= 1.0F)
   {
      rtb_veh_reverse_status = false;
   }

   localDW->UnitDelay_DSTATE_f = qY;

   /* Chart: '<S57>/Debouncer' */
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
      localDW->bitsForTID0.is_c1_SignalDebouncingLogic        = Speed_Arbitration_and_IMU_Fusion_IN_Off;
      localDW->bitsForTID0.Output                             = false;
      localDW->bitsForTID0.is_Off                             = Speed_Arbitration_and_IMU_Fusion_IN_Normal;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c1_SignalDebouncingLogic)
      {
         case Speed_Arbitration_and_IMU_Fusion_IN_Debounce:
            if (((uint32_T)localDW->bitsForTID0.is_Debounce) == Speed_Arbitration_and_IMU_Fusion_IN_Off_c)
            {
               if (((real32_T)localDW->temporalCounter_i2) >= 5.0F)
               {
                  localDW->bitsForTID0.is_Debounce                 = Speed_Arbitration_and_IMU_Fusion_IN_NO_ACTIVE_CHILD;
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = Speed_Arbitration_and_IMU_Fusion_IN_Off;
                  localDW->bitsForTID0.Output                      = false;
                  localDW->bitsForTID0.is_Off                      = Speed_Arbitration_and_IMU_Fusion_IN_Normal;
               }
               else
               {
                  if (rtb_IsVehInSlowMotion)
                  {
                     localDW->bitsForTID0.is_Debounce = Speed_Arbitration_and_IMU_Fusion_IN_On_e;
                     localDW->temporalCounter_i2      = 0U;
                  }
               }
            }
            else if (((real32_T)localDW->temporalCounter_i2) >= 5.0F)
            {
               localDW->bitsForTID0.is_Debounce                 = Speed_Arbitration_and_IMU_Fusion_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = Speed_Arbitration_and_IMU_Fusion_IN_On;
               localDW->bitsForTID0.Output                      = true;
            }
            else
            {
               if (!rtb_IsVehInSlowMotion)
               {
                  localDW->bitsForTID0.is_Debounce = Speed_Arbitration_and_IMU_Fusion_IN_Off_c;
                  localDW->temporalCounter_i2      = 0U;
               }
            }
            break;

         case Speed_Arbitration_and_IMU_Fusion_IN_Off:
            localDW->bitsForTID0.Output = false;
            if (rtb_IsVehInSlowMotion)
            {
               localDW->bitsForTID0.Fault                       = false;
               localDW->bitsForTID0.is_Off                      = Speed_Arbitration_and_IMU_Fusion_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = Speed_Arbitration_and_IMU_Fusion_IN_On;
               localDW->bitsForTID0.Output                      = true;
            }
            else
            {
               if ((((uint32_T)localDW->bitsForTID0.is_Off) == Speed_Arbitration_and_IMU_Fusion_IN_Fault) &&
                   (((real32_T)localDW->temporalCounter_i1) >= 100.0F))
               {
                  localDW->bitsForTID0.Fault  = false;
                  localDW->bitsForTID0.is_Off = Speed_Arbitration_and_IMU_Fusion_IN_Normal;
               }
            }
            break;

         default:
            localDW->bitsForTID0.Output = true;
            if (!rtb_IsVehInSlowMotion)
            {
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = Speed_Arbitration_and_IMU_Fusion_IN_Debounce;
               localDW->temporalCounter_i1                      = 0U;
               localDW->bitsForTID0.is_Debounce                 = Speed_Arbitration_and_IMU_Fusion_IN_Off_c;
               localDW->temporalCounter_i2                      = 0U;
            }
            break;
      }
   }

   /* End of Chart: '<S57>/Debouncer' */

   /* MATLAB Function: '<Root>/Z_H_R_Design' incorporates:
    *  MATLABSystem: '<S16>/Lowpass Filter'
    */
   rtb_Divide[0]        = 0.0001F;
   rtb_Divide[1]        = 0.0F;
   rtb_Divide[2]        = 0.0F;
   rtb_Divide[3]        = 1.0E+6F;
   rtb_H_idx_3          = 0;
   rtb_measAx_BeforeLPF = rtb_avgResult;
   if ((rtb_Differentiator > 0.001F) && (rtb_Differentiator < 1.0F))
   {
      if ((localDW->bitsForTID0.Output) && rtb_veh_reverse_status)
      {
         rtb_Divide[0] = 25.0F;
         rtb_Divide[1] = 0.0F;
         rtb_Divide[2] = 0.0F;
         rtb_Divide[3] = 0.0001F;
         rtb_H_idx_3   = 1;
      }

      if ((localDW->bitsForTID0.Output) && (!rtb_veh_reverse_status))
      {
         rtb_Divide[0] = 4.0F;
         rtb_Divide[1] = 0.0F;
         rtb_Divide[2] = 0.0F;
         rtb_Divide[3] = 0.0001F;
         rtb_H_idx_3   = 1;
      }
   }

   if (((rtb_Differentiator > 0.3F) && (rtb_Differentiator <= 1.0F)) && (rtb_veh_decelerating && (rtb_Z_idx_1 <= 0.1F)))
   {
      rtb_Divide[0] = 25.0F;
      rtb_Divide[1] = 0.0F;
      rtb_Divide[2] = 0.0F;
      rtb_Divide[3] = 0.0001F;
      rtb_H_idx_3   = 1;
   }

   if (rtb_avgResult <= 2.22044605E-16F)
   {
      rtb_Divide[0]        = 2.22044605E-16F;
      rtb_Divide[1]        = 0.0F;
      rtb_Divide[2]        = 0.0F;
      rtb_Divide[3]        = 2.22044605E-16F;
      rtb_H_idx_3          = 1;
      rtb_measAx_BeforeLPF = 0.0F;
      rtb_Z_idx_1          = 0.0F;
   }

   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      /* Product: '<S20>/P_pred *Ht' incorporates:
       *  Math: '<S20>/Transpose1'
       *  Product: '<S20>/H*P*Ht'
       */
      P_delay_DSTATE_tmp[nonZeroCount] = 0.0F;
      P_delay_DSTATE_tmp[nonZeroCount] += rtb_Add_m4[nonZeroCount];
      P_delay_DSTATE_tmp[nonZeroCount + 2] = 0.0F;
      P_delay_DSTATE_tmp[nonZeroCount + 2] += rtb_Add_m4[nonZeroCount + 2] * ((real32_T)rtb_H_idx_3);
   }

   /* Product: '<S20>/P_pred *Ht' incorporates:
    *  UnitDelay: '<S19>/P_delay'
    */
   localDW->P_delay_DSTATE[0] = P_delay_DSTATE_tmp[0];
   localDW->P_delay_DSTATE[1] = P_delay_DSTATE_tmp[1];
   localDW->P_delay_DSTATE[2] = P_delay_DSTATE_tmp[2];
   localDW->P_delay_DSTATE[3] = P_delay_DSTATE_tmp[3];

   /* Sum: '<S20>/HPHt + R' incorporates:
    *  Product: '<S20>/H*P*Ht'
    */
   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      /* Product: '<S20>/H*P*Ht' */
      rtb_Divide_tmp               = (nonZeroCount << 1);
      rtb_Divide_0[rtb_Divide_tmp] = P_delay_DSTATE_tmp[rtb_Divide_tmp] + rtb_Divide[rtb_Divide_tmp];

      /* Product: '<S20>/H*P*Ht' */
      rtb_H_tmp                        = rtb_Divide_tmp + 1;
      rtb_Divide_0[1 + rtb_Divide_tmp] = (P_delay_DSTATE_tmp[rtb_H_tmp] * ((real32_T)rtb_H_idx_3)) + rtb_Divide[rtb_H_tmp];
   }

   P_delay_DSTATE_tmp[0] = rtb_Divide_0[0];
   P_delay_DSTATE_tmp[1] = rtb_Divide_0[1];
   P_delay_DSTATE_tmp[2] = rtb_Divide_0[2];
   P_delay_DSTATE_tmp[3] = rtb_Divide_0[3];

   /* End of Sum: '<S20>/HPHt + R' */

   /* Product: '<S20>/Divide' incorporates:
    *  UnitDelay: '<S19>/P_delay'
    */
   rt_mrdividef2x2_Aptiv(localDW->P_delay_DSTATE, P_delay_DSTATE_tmp, rtb_Divide);
   for (nonZeroCount = 0; nonZeroCount < 2; nonZeroCount++)
   {
      /* Sum: '<S18>/Add3' incorporates:
       *  Constant: '<S18>/Constant'
       *  Product: '<S18>/K*H'
       */
      P_delay_DSTATE_tmp[nonZeroCount] =
         Speed_Arbitration_and_IMU_Fusion_ConstP.Constant_Value_j[nonZeroCount] - rtb_Divide[nonZeroCount];
      P_delay_DSTATE_tmp[nonZeroCount + 2] = Speed_Arbitration_and_IMU_Fusion_ConstP.Constant_Value_j[nonZeroCount + 2] -
                                             (rtb_Divide[nonZeroCount + 2] * ((real32_T)rtb_H_idx_3));

      /* Product: '<S18>/P_estim' incorporates:
       *  UnitDelay: '<S19>/P_delay'
       */
      localDW->P_delay_DSTATE[nonZeroCount] = 0.0F;
      localDW->P_delay_DSTATE[nonZeroCount] += P_delay_DSTATE_tmp[nonZeroCount] * rtb_Add_m4[0];
      rtb_Differentiator = P_delay_DSTATE_tmp[nonZeroCount + 2];
      localDW->P_delay_DSTATE[nonZeroCount] += rtb_Differentiator * rtb_Add_m4[1];
      localDW->P_delay_DSTATE[nonZeroCount + 2] = 0.0F;
      localDW->P_delay_DSTATE[nonZeroCount + 2] += P_delay_DSTATE_tmp[nonZeroCount] * rtb_Add_m4[2];
      localDW->P_delay_DSTATE[nonZeroCount + 2] += rtb_Differentiator * rtb_Add_m4[3];
   }

   /* Outputs for Enabled SubSystem: '<S31>/Initialization' */
   /* Switch: '<S31>/Switch' incorporates:
    *  UnitDelay: '<S31>/Unit Delay'
    */
   Speed_Arbitration_and_IMU_Fusion_Initialization1((uint8_T)((((int32_T)localDW->UnitDelay_DSTATE_j) != 0) ? 1 : 0),
                                                    localDW->diff_num_o, localDW->diff_denom_d);

   /* End of Outputs for SubSystem: '<S31>/Initialization' */

   /* Outputs for Enabled SubSystem: '<S30>/Initialization1' */
   /* Switch: '<S30>/Switch' incorporates:
    *  UnitDelay: '<S30>/Unit Delay'
    */
   Speed_Arbitration_and_IMU_Fusion_Initialization1((uint8_T)((((int32_T)localDW->UnitDelay_DSTATE_fa) != 0) ? 1 : 0),
                                                    localDW->diff_num_e, localDW->diff_denom_b);

   /* End of Outputs for SubSystem: '<S30>/Initialization1' */

   /* Outputs for Enabled SubSystem: '<S9>/Speed_To_Accel_TF_Coeff' incorporates:
    *  EnablePort: '<S50>/Enable'
    */
   /* Switch: '<S9>/Switch' incorporates:
    *  UnitDelay: '<S9>/Unit Delay'
    */
   if (((int32_T)localDW->UnitDelay_DSTATE_m) != 0)
   {
      /* DataTypeConversion: '<S50>/Data Type Conversion' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion[0] = 0.416113406F;

      /* DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion1[0] = 1.0F;

      /* DataTypeConversion: '<S50>/Data Type Conversion' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion[1] = 0.416113406F;

      /* DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion1[1] = -0.866892278F;

      /* DataTypeConversion: '<S50>/Data Type Conversion' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion[2] = -0.416113406F;

      /* DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion1[2] = -0.991677761F;

      /* DataTypeConversion: '<S50>/Data Type Conversion' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion[3] = -0.416113406F;

      /* DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
       *  MATLAB Function: '<S50>/Find_Speed_To_Accel_TF'
       */
      localDW->DataTypeConversion1[3] = 0.875214577F;
   }

   /* End of Switch: '<S9>/Switch' */
   /* End of Outputs for SubSystem: '<S9>/Speed_To_Accel_TF_Coeff' */

   /* Switch: '<S22>/Init' incorporates:
    *  Constant: '<S19>/x_init_accel'
    *  DataTypeConversion: '<S19>/Data Type Conversion'
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    *  UnitDelay: '<S22>/FixPt Unit Delay2'
    */
   if (((int32_T)localDW->FixPtUnitDelay2_DSTATE_j) != 0)
   {
      localDW->FixPtUnitDelay1_DSTATE_d[0] = rtb_avgResult;
      localDW->FixPtUnitDelay1_DSTATE_d[1] = 0.0F;
   }

   /* End of Switch: '<S22>/Init' */

   /* Product: '<S19>/A*x_k-1' incorporates:
    *  MATLAB Function: '<Root>/A_matrix_4x4'
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   rtb_delta_t = (rtb_delta_t * localDW->FixPtUnitDelay1_DSTATE_d[1]) + localDW->FixPtUnitDelay1_DSTATE_d[0];
   pmLocal     = localDW->FixPtUnitDelay1_DSTATE_d[1];

   /* Product: '<S18>/H*x_pred' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE_d[0] = 0.0F;
   localDW->FixPtUnitDelay1_DSTATE_d[0] += rtb_delta_t;

   /* Sum: '<S18>/Add' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE_d[0] = rtb_measAx_BeforeLPF - localDW->FixPtUnitDelay1_DSTATE_d[0];

   /* Product: '<S18>/H*x_pred' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE_d[1] = 0.0F;
   localDW->FixPtUnitDelay1_DSTATE_d[1] += ((real32_T)rtb_H_idx_3) * pmLocal;

   /* Sum: '<S18>/Add' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE_d[1] = rtb_Z_idx_1 - localDW->FixPtUnitDelay1_DSTATE_d[1];

   /* Sum: '<S18>/Add1' incorporates:
    *  Product: '<S18>/K*Error'
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   rtb_Differentiator =
      (rtb_Divide[1] * localDW->FixPtUnitDelay1_DSTATE_d[0]) + (rtb_Divide[3] * localDW->FixPtUnitDelay1_DSTATE_d[1]);

   /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
    *  Product: '<S18>/K*Error'
    *  Sum: '<S18>/Add1'
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   localDW->FixPtUnitDelay1_DSTATE_d[0] =
      ((rtb_Divide[0] * localDW->FixPtUnitDelay1_DSTATE_d[0]) + (rtb_Divide[2] * localDW->FixPtUnitDelay1_DSTATE_d[1])) +
      rtb_delta_t;
   localDW->FixPtUnitDelay1_DSTATE_d[1] = pmLocal + rtb_Differentiator;

   /* Switch: '<Root>/Switch' incorporates:
    *  Constant: '<Root>/Constant2'
    *  RelationalOperator: '<Root>/compare2'
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   if (localDW->FixPtUnitDelay1_DSTATE_d[0] <= 0.0F)
   {
      *rty_VsVSE_mps_WhlOdoArbitratedVehSpeed = 0.0F;
   }
   else
   {
      *rty_VsVSE_mps_WhlOdoArbitratedVehSpeed = localDW->FixPtUnitDelay1_DSTATE_d[0];
   }

   /* End of Switch: '<Root>/Switch' */

   /* If: '<S23>/If' incorporates:
    *  Abs: '<S23>/Abs'
    *  Constant: '<S23>/Constant'
    *  Constant: '<S23>/Constant4'
    *  Constant: '<S23>/Constant5'
    *  Logic: '<S23>/Logical Operator'
    *  RelationalOperator: '<S23>/GreaterThan'
    *  RelationalOperator: '<S23>/GreaterThan1'
    *  RelationalOperator: '<S23>/NotEqual'
    *  Sum: '<S23>/Add'
    */
   if (((uint32_T)rtb_VeVSE_CorrecrDeltaSysTimeQF) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S23>/calc_accuracy_level_under_medium_confidence' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      Speed_Arbitration_and_IMU_Fusion_calc_accuracy_level_under_medium_confidence(
         rty_VeVSE_WhlOdoArbitratedVx_AccLvl, rty_VeVSE_WhlOdoArbitratedAx_AccLvl,
         &Speed_Arbitration_and_IMU_Fusion_ConstB.calc_accuracy_level_under_medium_confidence);

      /* End of Outputs for SubSystem: '<S23>/calc_accuracy_level_under_medium_confidence' */
   }
   else if ((fabsf((*rty_VsVSE_mps_WhlOdoArbitratedVehSpeed) - rtb_VsVCAN_mps_MeanWheelLinSpd) > 0.2F) &&
            (rtb_VsVCAN_mps_MeanWheelLinSpd > 2.0F))
   {
      /* Outputs for IfAction SubSystem: '<S23>/calc_accuracy_level_under_low_confidence' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      Speed_Arbitration_and_IMU_Fusion_calc_accuracy_level_under_medium_confidence(
         rty_VeVSE_WhlOdoArbitratedVx_AccLvl, rty_VeVSE_WhlOdoArbitratedAx_AccLvl,
         &Speed_Arbitration_and_IMU_Fusion_ConstB.calc_accuracy_level_under_low_confidence);

      /* End of Outputs for SubSystem: '<S23>/calc_accuracy_level_under_low_confidence' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S23>/calc_accuracy_level_under_high_confidence' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* SignalConversion: '<S25>/OutportBufferForVeVSE_WhlOdoVehLongAccelAccLvl' */
      *rty_VeVSE_WhlOdoArbitratedAx_AccLvl = Speed_Arbitration_and_IMU_Fusion_ConstB.In1;

      /* SignalConversion: '<S25>/OutportBufferForVeVSE_WhlOdoVehLongSpdAccLvl' */
      *rty_VeVSE_WhlOdoArbitratedVx_AccLvl = Speed_Arbitration_and_IMU_Fusion_ConstB.In1;

      /* End of Outputs for SubSystem: '<S23>/calc_accuracy_level_under_high_confidence' */
   }

   /* End of If: '<S23>/If' */

   /* DiscreteTransferFcn: '<S31>/Differentiator' */
   localDW->Differentiator_tmp_c =
      (((*rty_VsVSE_mps_WhlOdoArbitratedVehSpeed) - (localDW->diff_denom_d[1] * localDW->Differentiator_states_j[0])) -
       (localDW->diff_denom_d[2] * localDW->Differentiator_states_j[1])) -
      (localDW->diff_denom_d[3] * localDW->Differentiator_states_j[2]);
   rtb_Z_idx_1 = (((localDW->diff_num_o[0] * localDW->Differentiator_tmp_c) +
                   (localDW->diff_num_o[1] * localDW->Differentiator_states_j[0])) +
                  (localDW->diff_num_o[2] * localDW->Differentiator_states_j[1])) +
                 (localDW->diff_num_o[3] * localDW->Differentiator_states_j[2]);

   /* If: '<S40>/If1' incorporates:
    *  Constant: '<S28>/Constant'
    *  Constant: '<S29>/Constant'
    *  Constant: '<S40>/Constant'
    *  Constant: '<S40>/Constant5'
    *  Constant: '<S42>/Constant'
    *  Constant: '<S42>/Constant1'
    *  Constant: '<S43>/Constant1'
    *  Constant: '<S43>/Constant2'
    *  DiscreteTransferFcn: '<S31>/Differentiator'
    *  Inport: '<S44>/In1'
    *  Inport: '<S45>/In1'
    *  Logic: '<S42>/Logical Operator'
    *  Logic: '<S43>/Logical Operator'
    *  RelationalOperator: '<S23>/NotEqual'
    *  RelationalOperator: '<S28>/Compare'
    *  RelationalOperator: '<S29>/Compare'
    *  RelationalOperator: '<S42>/Equal'
    *  RelationalOperator: '<S42>/Equal1'
    *  RelationalOperator: '<S43>/Equal'
    *  RelationalOperator: '<S43>/Equal1'
    */
   if ((((((*rty_VsVSE_mps_WhlOdoArbitratedVehSpeed) >= 0.0F) && ((*rty_VsVSE_mps_WhlOdoArbitratedVehSpeed) <= 150.0F)) &&
         ((rtb_Z_idx_1 >= -20.0F) && (rtb_Z_idx_1 <= 20.0F))) &&
        (((uint32_T)(*rtu_EstimatedVxForABSTCS_QF)) == ACCURATED)) &&
       (((uint32_T)rtb_VeVSE_CorrecrDeltaSysTimeQF) == ACCURATED))
   {
      /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      *rty_VeVSE_WhlOdoArbitratedVehSpeed_QF = ACCURATED;

      /* End of Outputs for SubSystem: '<S40>/If Action Subsystem1' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      *rty_VeVSE_WhlOdoArbitratedVehSpeed_QF = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S40>/If Action Subsystem5' */
   }

   /* End of If: '<S40>/If1' */

   /* DiscreteFilter: '<S9>/Discrete Filter' */
   localDW->DiscreteFilter_tmp =
      (((*rty_VsVSE_mps_WhlOdoArbitratedVehSpeed) - (localDW->DataTypeConversion1[1] * localDW->DiscreteFilter_states[0])) -
       (localDW->DataTypeConversion1[2] * localDW->DiscreteFilter_states[1])) -
      (localDW->DataTypeConversion1[3] * localDW->DiscreteFilter_states[2]);
   *rty_VsVSE_mps2_WhlOdoLongAcclFromEstimWhlSpd = (((localDW->DataTypeConversion[0] * localDW->DiscreteFilter_tmp) +
                                                     (localDW->DataTypeConversion[1] * localDW->DiscreteFilter_states[0])) +
                                                    (localDW->DataTypeConversion[2] * localDW->DiscreteFilter_states[1])) +
                                                   (localDW->DataTypeConversion[3] * localDW->DiscreteFilter_states[2]);

   /* DiscreteTransferFcn: '<S30>/Differentiator' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   localDW->Differentiator_tmp_o =
      ((localDW->FixPtUnitDelay1_DSTATE_d[1] - (localDW->diff_denom_b[1] * localDW->Differentiator_states_n[0])) -
       (localDW->diff_denom_b[2] * localDW->Differentiator_states_n[1])) -
      (localDW->diff_denom_b[3] * localDW->Differentiator_states_n[2]);
   rtb_Z_idx_1 = (((localDW->diff_num_e[0] * localDW->Differentiator_tmp_o) +
                   (localDW->diff_num_e[1] * localDW->Differentiator_states_n[0])) +
                  (localDW->diff_num_e[2] * localDW->Differentiator_states_n[1])) +
                 (localDW->diff_num_e[3] * localDW->Differentiator_states_n[2]);

   /* If: '<S32>/If' incorporates:
    *  Constant: '<S32>/Constant'
    *  Constant: '<S32>/Constant2'
    *  Constant: '<S34>/Constant2'
    *  Constant: '<S34>/Constant3'
    *  Constant: '<S35>/Constant_Val_neg_ten'
    *  Constant: '<S35>/Constant_Val_pos_ten'
    *  Constant: '<S36>/Constant'
    *  DiscreteTransferFcn: '<S30>/Differentiator'
    *  Inport: '<S37>/In1'
    *  Inport: '<S38>/In1'
    *  Logic: '<S34>/Logical Operator'
    *  Logic: '<S35>/Logical Operator'
    *  RelationalOperator: '<S34>/Equal'
    *  RelationalOperator: '<S34>/Equal1'
    *  RelationalOperator: '<S35>/Equal'
    *  RelationalOperator: '<S35>/Equal1'
    *  RelationalOperator: '<S36>/Compare'
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   if ((((localDW->FixPtUnitDelay1_DSTATE_d[1] >= -15.0F) && (localDW->FixPtUnitDelay1_DSTATE_d[1] <= 15.0F)) &&
        ((rtb_Z_idx_1 >= -10.0F) && (rtb_Z_idx_1 <= 10.0F))) &&
       (((uint32_T)(*rtu_EstimatedAxForABSTCS_QF)) == ACCURATED))
   {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      *rty_VeVSE_WhlOdoArbitratedAx_QF = ACCURATED;

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem1' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      *rty_VeVSE_WhlOdoArbitratedAx_QF = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem3' */
   }

   /* End of If: '<S32>/If' */

   /* SignalConversion: '<Root>/TmpSignal ConversionAtVsVSE_mps2_WhlOdoArbitratedVehLongAccelInport1' incorporates:
    *  UnitDelay: '<S22>/FixPt Unit Delay1'
    */
   *rty_VsVSE_mps2_WhlOdoArbitratedVehLongAccel = localDW->FixPtUnitDelay1_DSTATE_d[1];

   /* Update for Delay: '<S7>/Resettable Delay' */
   localDW->icLoad                 = 0U;
   localDW->ResettableDelay_DSTATE = *rtu_VsVCAN_u64_SystemTime;

   /* Update for UnitDelay: '<S53>/Unit Delay' incorporates:
    *  Constant: '<S53>/Constant'
    */
   localDW->UnitDelay_DSTATE_n = 0U;

   /* Update for DiscreteTransferFcn: '<S53>/Differentiator' */
   localDW->Differentiator_states[2] = localDW->Differentiator_states[1];
   localDW->Differentiator_states[1] = localDW->Differentiator_states[0];
   localDW->Differentiator_states[0] = localDW->Differentiator_tmp;

   /* Update for UnitDelay: '<S14>/Unit Delay2' */
   localDW->UnitDelay2_DSTATE = *rtu_ABS_Status;

   /* Update for UnitDelay: '<S66>/FixPt Unit Delay2' incorporates:
    *  Constant: '<S66>/FixPt Constant'
    */
   localDW->FixPtUnitDelay2_DSTATE = 0U;

   /* Update for UnitDelay: '<S13>/Unit Delay2' */
   localDW->bitsForTID0.UnitDelay2_DSTATE_l = rtb_VehStationaryForAxOffs_out;

   /* Update for UnitDelay: '<S12>/Unit Delay1' */
   localDW->UnitDelay1_DSTATE = rtb_avgResult;

   /* Update for UnitDelay: '<S12>/Unit Delay3' */
   localDW->bitsForTID0.UnitDelay3_DSTATE = localDW->bitsForTID0.Output;

   /* Update for UnitDelay: '<S12>/Unit Delay4' */
   localDW->bitsForTID0.UnitDelay4_DSTATE = rtb_veh_reverse_status;

   /* Update for UnitDelay: '<S31>/Unit Delay' incorporates:
    *  Constant: '<S31>/Constant1'
    */
   localDW->UnitDelay_DSTATE_j = 0U;

   /* Update for UnitDelay: '<S30>/Unit Delay' incorporates:
    *  Constant: '<S30>/Constant1'
    */
   localDW->UnitDelay_DSTATE_fa = 0U;

   /* Update for UnitDelay: '<S9>/Unit Delay' incorporates:
    *  Constant: '<S9>/Constant'
    */
   localDW->UnitDelay_DSTATE_m = 0U;

   /* Update for UnitDelay: '<S22>/FixPt Unit Delay2' incorporates:
    *  Constant: '<S22>/FixPt Constant'
    */
   localDW->FixPtUnitDelay2_DSTATE_j = 0U;

   /* Update for DiscreteTransferFcn: '<S31>/Differentiator' */
   localDW->Differentiator_states_j[2] = localDW->Differentiator_states_j[1];
   localDW->Differentiator_states_j[1] = localDW->Differentiator_states_j[0];
   localDW->Differentiator_states_j[0] = localDW->Differentiator_tmp_c;

   /* Update for DiscreteFilter: '<S9>/Discrete Filter' */
   localDW->DiscreteFilter_states[2] = localDW->DiscreteFilter_states[1];
   localDW->DiscreteFilter_states[1] = localDW->DiscreteFilter_states[0];
   localDW->DiscreteFilter_states[0] = localDW->DiscreteFilter_tmp;

   /* Update for DiscreteTransferFcn: '<S30>/Differentiator' */
   localDW->Differentiator_states_n[2] = localDW->Differentiator_states_n[1];
   localDW->Differentiator_states_n[1] = localDW->Differentiator_states_n[0];
   localDW->Differentiator_states_n[0] = localDW->Differentiator_tmp_o;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
