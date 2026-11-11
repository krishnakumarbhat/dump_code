/*
 * File: GradeEstimation.c
 *
 * Code generated for Simulink model 'GradeEstimation'.
 *
 * Model version                  : 1.10380
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:08 2026
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

#include "GradeEstimation.h"
#include "GradeEstimation_private.h"

/* Named constants for Chart: '<S9>/Debouncer' */
#define GradeEstimation_IN_Debounce        ((uint8_T)1U)
#define GradeEstimation_IN_Fault           ((uint8_T)1U)
#define GradeEstimation_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define GradeEstimation_IN_Normal          ((uint8_T)2U)
#define GradeEstimation_IN_Off             ((uint8_T)2U)
#define GradeEstimation_IN_Off_g           ((uint8_T)1U)
#define GradeEstimation_IN_On              ((uint8_T)3U)
#define GradeEstimation_IN_On_h            ((uint8_T)2U)

/* Named constants for Chart: '<S13>/Chart' */
#define GradeEstimation_IN_Initialize ((uint8_T)1U)
#define GradeEstimation_IN_Running    ((uint8_T)2U)

/* Named constants for Chart: '<S25>/AccuracyLevelDebouncer' */
#define GradeEstimation_IN_Check_Off         ((uint8_T)1U)
#define GradeEstimation_IN_Check_On          ((uint8_T)2U)
#define GradeEstimation_IN_Check_On1         ((uint8_T)3U)
#define GradeEstimation_IN_NO_ACTIVE_CHILD_c ((uint8_T)0U)

/* Named constants for Chart: '<S26>/Initialization_Trigger' */
#define GradeEstimation_IN_Initialize_n ((uint8_T)1U)
#define GradeEstimation_IN_Running_g    ((uint8_T)2U)

/* Named constants for Chart: '<S6>/GNMMDebouncer' */
#define GradeEstimation_GNMM_Recovery_Time  (5.0)
#define GradeEstimation_IN_Check_On_Initial ((uint8_T)3U)
#define GradeEstimation_IN_Debounce_Fault   ((uint8_T)4U)
#define GradeEstimation_IN_Fault_a          ((uint8_T)1U)
#define GradeEstimation_IN_Normal_l         ((uint8_T)2U)
#define GradeEstimation_IN_Off_j            ((uint8_T)1U)
#define GradeEstimation_IN_On_a             ((uint8_T)2U)

/* Named constants for Chart: '<S6>/IMUDebouncer' */
#define GradeEstimation_IMU_Recovery_Time (5.0)

/* Forward declaration for local functions */
static void GradeEstimation_SystemCore_release(dsp_simulink_MovingAverage_GradeEstimation_T *obj);
static void GradeEstimation_SystemCore_delete(dsp_simulink_MovingAverage_GradeEstimation_T *obj);
static void GradeEstimation_matlabCodegenHandle_matlabCodegenDestructor(dsp_simulink_MovingAverage_GradeEstimation_T *obj);
static void GradeEstimation_SystemCore_release(dsp_simulink_MovingAverage_GradeEstimation_T *obj)
{
   dsp_private_SlidingWindowAverageCG_GradeEstimation_T *obj_0;
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

static void GradeEstimation_SystemCore_delete(dsp_simulink_MovingAverage_GradeEstimation_T *obj)
{
   GradeEstimation_SystemCore_release(obj);
}

static void GradeEstimation_matlabCodegenHandle_matlabCodegenDestructor(dsp_simulink_MovingAverage_GradeEstimation_T *obj)
{
   if (!obj->matlabCodegenIsDeleted)
   {
      obj->matlabCodegenIsDeleted = true;
      GradeEstimation_SystemCore_delete(obj);
   }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void GradeEstimation_MovingAverage_Init(DW_MovingAverage_GradeEstimation_T *localDW)
{
   int32_T i;

   /* InitializeConditions for MATLABSystem: '<S2>/MovingAverage' */
   if (localDW->obj.pStatistic->isInitialized == 1)
   {
      localDW->obj.pStatistic->pCumSum = 0.0F;
      for (i = 0; i < 9; i++)
      {
         localDW->obj.pStatistic->pCumSumRev[i] = 0.0F;
      }

      localDW->obj.pStatistic->pCumRevIndex = 1.0F;
   }

   /* End of InitializeConditions for MATLABSystem: '<S2>/MovingAverage' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void GradeEstimation_MovingAverage_Start(DW_MovingAverage_GradeEstimation_T *localDW)
{
   /* Start for MATLABSystem: '<S2>/MovingAverage' */
   localDW->obj.matlabCodegenIsDeleted = true;
   localDW->obj.isInitialized          = 0;
   localDW->obj.NumChannels            = -1;
   localDW->obj.matlabCodegenIsDeleted = false;
   localDW->bitsForTID0.objisempty     = true;
   localDW->obj.isSetupComplete        = false;
   localDW->obj.isInitialized          = 1;
   localDW->obj.NumChannels            = 1;
   localDW->gobj_0.isInitialized       = 0;
   localDW->obj.pStatistic             = &localDW->gobj_0;
   localDW->obj.isSetupComplete        = true;
   localDW->obj.TunablePropsChanged    = false;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void GradeEstimation_MovingAverage(real32_T rtu_0, DW_MovingAverage_GradeEstimation_T *localDW)
{
   real32_T cumRevIndex;
   real32_T csum;
   real32_T csumrev[9];
   real32_T z;
   int32_T z_tmp;

   /* MATLABSystem: '<S2>/MovingAverage' */
   if (localDW->obj.TunablePropsChanged)
   {
      localDW->obj.TunablePropsChanged = false;
   }

   if (localDW->obj.pStatistic->isInitialized != 1)
   {
      localDW->obj.pStatistic->isSetupComplete = false;
      localDW->obj.pStatistic->isInitialized   = 1;
      localDW->obj.pStatistic->pCumSum         = 0.0F;
      localDW->obj.pStatistic->pCumRevIndex    = 1.0F;
      localDW->obj.pStatistic->isSetupComplete = true;
      localDW->obj.pStatistic->pCumSum         = 0.0F;
      for (z_tmp = 0; z_tmp < 9; z_tmp++)
      {
         localDW->obj.pStatistic->pCumSumRev[z_tmp] = 0.0F;
         localDW->obj.pStatistic->pCumSumRev[z_tmp] = 0.0F;
      }

      localDW->obj.pStatistic->pCumRevIndex = 1.0F;
   }

   cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
   csum        = localDW->obj.pStatistic->pCumSum;
   for (z_tmp = 0; z_tmp < 9; z_tmp++)
   {
      csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
   }

   csum += rtu_0;
   z_tmp          = ((int32_T)cumRevIndex) - 1;
   z              = csumrev[z_tmp] + csum;
   csumrev[z_tmp] = rtu_0;
   if (cumRevIndex != 9.0F)
   {
      cumRevIndex++;
   }
   else
   {
      cumRevIndex = 1.0F;
      csum        = 0.0F;
      for (z_tmp = 7; z_tmp >= 0; z_tmp--)
      {
         csumrev[z_tmp] += csumrev[z_tmp + 1];
      }
   }

   localDW->obj.pStatistic->pCumSum = csum;
   for (z_tmp = 0; z_tmp < 9; z_tmp++)
   {
      localDW->obj.pStatistic->pCumSumRev[z_tmp] = csumrev[z_tmp];
   }

   localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
   localDW->VsVSE_m_AvgDeltaAlt          = z / 10.0F;

   /* End of MATLABSystem: '<S2>/MovingAverage' */
}

/*
 * System initialize for atomic system:
 *    '<S9>/Debouncer'
 *    '<S50>/Debouncer'
 *    '<S51>/Debouncer'
 *    '<S52>/Debouncer'
 *    '<S58>/Debouncer'
 *    '<S60>/Debouncer'
 *    '<S65>/Debouncer'
 */
void GradeEstimation_Debouncer_Init(boolean_T *rty_Fault)
{
   *rty_Fault = false;
}

/*
 * Output and update for atomic system:
 *    '<S9>/Debouncer'
 *    '<S50>/Debouncer'
 *    '<S51>/Debouncer'
 *    '<S52>/Debouncer'
 *    '<S58>/Debouncer'
 *    '<S60>/Debouncer'
 *    '<S65>/Debouncer'
 */
void GradeEstimation_Debouncer(boolean_T rtu_sw, boolean_T *rty_Output, boolean_T *rty_Fault,
                               DW_Debouncer_GradeEstimation_T *localDW, real32_T rtp_Debounce_Time,
                               boolean_T rtp_Demat_Duration_Check, real32_T rtp_Dematuration_Time, boolean_T rtp_Fault_Check,
                               boolean_T rtp_Mat_Duration_Check, real32_T rtp_Maturation_Time, real32_T rtp_Recovery_Time)
{
   boolean_T tmp;

   /* Chart: '<S9>/Debouncer' */
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
      localDW->bitsForTID0.is_c1_SignalDebouncingLogic        = GradeEstimation_IN_Off;
      *rty_Output                                             = false;
      localDW->bitsForTID0.is_Off                             = GradeEstimation_IN_Normal;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c1_SignalDebouncingLogic)
      {
         case GradeEstimation_IN_Debounce:
            if ((((real32_T)localDW->temporalCounter_i1) >= (rtp_Debounce_Time * 100.0F)) && rtp_Fault_Check)
            {
               localDW->bitsForTID0.is_Debounce                 = GradeEstimation_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_Off;
               *rty_Output                                      = false;
               localDW->bitsForTID0.is_Off                      = GradeEstimation_IN_Fault;
               localDW->temporalCounter_i1                      = 0U;
               *rty_Fault                                       = true;
            }
            else if (((uint32_T)localDW->bitsForTID0.is_Debounce) == GradeEstimation_IN_Off_g)
            {
               if (((real32_T)localDW->temporalCounter_i2) >= (rtp_Dematuration_Time * 100.0F))
               {
                  localDW->bitsForTID0.is_Debounce                 = GradeEstimation_IN_NO_ACTIVE_CHILD;
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_Off;
                  *rty_Output                                      = false;
                  localDW->bitsForTID0.is_Off                      = GradeEstimation_IN_Normal;
               }
               else
               {
                  if (rtu_sw)
                  {
                     localDW->bitsForTID0.is_Debounce = GradeEstimation_IN_On_h;
                     localDW->temporalCounter_i2      = 0U;
                  }
               }
            }
            else if (((real32_T)localDW->temporalCounter_i2) >= (rtp_Maturation_Time * 100.0F))
            {
               localDW->bitsForTID0.is_Debounce                 = GradeEstimation_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_On;
               *rty_Output                                      = true;
            }
            else
            {
               if (!rtu_sw)
               {
                  localDW->bitsForTID0.is_Debounce = GradeEstimation_IN_Off_g;
                  localDW->temporalCounter_i2      = 0U;
               }
            }
            break;

         case GradeEstimation_IN_Off:
            *rty_Output = false;
            if (rtu_sw && (!rtp_Mat_Duration_Check))
            {
               *rty_Fault                                       = false;
               localDW->bitsForTID0.is_Off                      = GradeEstimation_IN_NO_ACTIVE_CHILD;
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_On;
               *rty_Output                                      = true;
            }
            else if (((uint32_T)localDW->bitsForTID0.is_Off) == GradeEstimation_IN_Fault)
            {
               if (((real32_T)localDW->temporalCounter_i1) >= (rtp_Recovery_Time * 100.0F))
               {
                  *rty_Fault                  = false;
                  localDW->bitsForTID0.is_Off = GradeEstimation_IN_Normal;
               }
            }
            else
            {
               if (rtp_Mat_Duration_Check && rtu_sw)
               {
                  localDW->bitsForTID0.is_Off                      = GradeEstimation_IN_NO_ACTIVE_CHILD;
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_Debounce;
                  localDW->temporalCounter_i1                      = 0U;
                  localDW->bitsForTID0.is_Debounce                 = GradeEstimation_IN_On_h;
                  localDW->temporalCounter_i2                      = 0U;
               }
            }
            break;

         default:
            *rty_Output = true;
            tmp         = !rtu_sw;
            if (tmp && rtp_Demat_Duration_Check)
            {
               localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_Debounce;
               localDW->temporalCounter_i1                      = 0U;
               localDW->bitsForTID0.is_Debounce                 = GradeEstimation_IN_Off_g;
               localDW->temporalCounter_i2                      = 0U;
            }
            else
            {
               if ((!rtp_Demat_Duration_Check) && tmp)
               {
                  localDW->bitsForTID0.is_c1_SignalDebouncingLogic = GradeEstimation_IN_Off;
                  *rty_Output                                      = false;
                  localDW->bitsForTID0.is_Off                      = GradeEstimation_IN_Normal;
               }
            }
            break;
      }
   }

   /* End of Chart: '<S9>/Debouncer' */
}

/*
 * Output and update for atomic system:
 *    '<S13>/Chart'
 *    '<S14>/Chart'
 *    '<S70>/Chart'
 *    '<S71>/Chart'
 *    '<S87>/Chart'
 *    '<S88>/Chart'
 */
void GradeEstimation_Chart(boolean_T *rty_f_initialize_LateralJerkEstimation, DW_Chart_GradeEstimation_T *localDW)
{
   /* Chart: '<S13>/Chart' */
   if (((uint32_T)localDW->bitsForTID0.is_active_c5_Fourth_Order_Cheby2_Filter) == 0U)
   {
      localDW->bitsForTID0.is_active_c5_Fourth_Order_Cheby2_Filter = 1;
      localDW->bitsForTID0.is_c5_Fourth_Order_Cheby2_Filter        = GradeEstimation_IN_Initialize;
      *rty_f_initialize_LateralJerkEstimation                      = true;
   }
   else if (((uint32_T)localDW->bitsForTID0.is_c5_Fourth_Order_Cheby2_Filter) == GradeEstimation_IN_Initialize)
   {
      if (*rty_f_initialize_LateralJerkEstimation)
      {
         localDW->bitsForTID0.is_c5_Fourth_Order_Cheby2_Filter = GradeEstimation_IN_Running;
         *rty_f_initialize_LateralJerkEstimation               = false;
      }
   }
   else
   {
      *rty_f_initialize_LateralJerkEstimation = false;
   }

   /* End of Chart: '<S13>/Chart' */
}

/*
 * Output and update for enable system:
 *    '<S13>/Coe1FilterGenerator'
 *    '<S14>/Coe1FilterGenerator'
 *    '<S70>/Coe1FilterGenerator'
 *    '<S71>/Coe1FilterGenerator'
 *    '<S87>/Coe1FilterGenerator'
 *    '<S88>/Coe1FilterGenerator'
 */
void GradeEstimation_Coe1FilterGenerator(boolean_T rtu_Enable, real_T rty_Filter_Num[5], real_T rty_Filter_Den[5])
{
   static const real_T tmp[5] = {0.086541899034217856, -0.32267429893055383, 0.47308975540587822, -0.32267429893055388,
                                 0.08654189903421787};

   static const real_T tmp_0[5] = {1.0, -3.5713756221389472, 4.8054754636030026, -2.8858226567315532, 0.6525477708807037};

   int32_T i;

   /* Outputs for Enabled SubSystem: '<S13>/Coe1FilterGenerator' incorporates:
    *  EnablePort: '<S16>/Enable'
    */
   if (rtu_Enable)
   {
      /* MATLAB Function: '<S16>/FindFilterCoeff' */
      for (i = 0; i < 5; i++)
      {
         rty_Filter_Num[i] = tmp[i];
         rty_Filter_Den[i] = tmp_0[i];
      }

      /* End of MATLAB Function: '<S16>/FindFilterCoeff' */
   }

   /* End of Outputs for SubSystem: '<S13>/Coe1FilterGenerator' */
}

/* System initialize for referenced model: 'GradeEstimation' */
void GradeEstimation_Init(DW_GradeEstimation_f_T *localDW)
{
   /* InitializeConditions for Delay: '<S2>/Delay1' */
   localDW->Delay1_DSTATE = 1.0E-5F;

   /* InitializeConditions for UnitDelay: '<S8>/Unit Delay3' */
   localDW->UnitDelay3_DSTATE = 0.01F;

   /* SystemInitialize for Chart: '<S65>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_l);

   /* SystemInitialize for Chart: '<S60>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_b);

   /* SystemInitialize for Chart: '<S58>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_h);

   /* SystemInitialize for Chart: '<S50>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_p);

   /* SystemInitialize for Chart: '<S52>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_o);
   GradeEstimation_MovingAverage_Init(&localDW->MovingAverage);
   GradeEstimation_MovingAverage_Init(&localDW->MovingAverage_p);

   /* SystemInitialize for Chart: '<S9>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_ly);

   /* SystemInitialize for Chart: '<S51>/Debouncer' */
   GradeEstimation_Debouncer_Init(&localDW->Fault_i);
}

/* Start for referenced model: 'GradeEstimation' */
void GradeEstimation_Start(DW_GradeEstimation_f_T *localDW)
{
   /* Start for MATLABSystem: '<S2>/MovingAverage' */
   GradeEstimation_MovingAverage_Start(&localDW->MovingAverage);
   GradeEstimation_MovingAverage_Start(&localDW->MovingAverage_p);
}

/* Output and update for referenced model: 'GradeEstimation' */
void GradeEstimation(const real32_T *rtu_VsVSE_mps_VehicleSpeed, const real32_T *rtu_VsVSE_mps2_VehicleRawLongAccel,
                     const real32_T *rtu_VsGPS_m_GPSAltitude, const uint64_T *rtu_VsSYS_ms_SystemTime,
                     const boolean_T *rtu_VsVSE_b_UseGPSInput, const real32_T *rtu_VsVSE_rad_VCSSideslip,
                     const boolean_T *rtu_VsGPS_b_GPSValidity, const enum_quality_factor_T *rtu_VeVCAN_IMUValidity,
                     const real32_T *rtu_VsVSE_sec_SystemExecutionTime, real32_T *rty_VsVSE_pct_EstimatedGrade,
                     enum_quality_factor_T *rty_VsVSE_EstimatedGradeQF, enum_accuracy_level_T *rty_VsVSE_EstimatedGradeAccuracy,
                     DW_GradeEstimation_f_T *localDW)
{
   /* local block i/o variables */
   real32_T rtb_Substract_Alt;
   real32_T rtb_IMU_Est_Grade_SideSlip;
   real32_T A;
   real32_T sin_alpha;
   real32_T rtb_Integrator;
   real_T rtb_Abs;
   real_T rtb_Fused_n;
   real32_T rtb_Filt_Lateral_Acceleration_h;
   real32_T rtb_Ax_Vx_g5;
   boolean_T rtb_Transition;
   boolean_T rtb_Compare_j;
   boolean_T rtb_Compare_b3;
   boolean_T rtb_Compare_hg;
   boolean_T rtb_Compare_bu;
   boolean_T rtb_LogicalOperator_g;
   real32_T rtb_delta_Alt_pre;
   int32_T rtb_IMU_Enable;
   int32_T rtb_GNMM_Enable;
   enum_accuracy_level_T rtb_Accuracy_Level;
   real_T u0;
   real32_T Integrator_Ax_tmp;

   /* Chart: '<S71>/Chart' */
   GradeEstimation_Chart(&localDW->f_initialize_LateralJerkEstimation_e, &localDW->sf_Chart_dl);

   /* Outputs for Enabled SubSystem: '<S71>/Coe1FilterGenerator' */
   GradeEstimation_Coe1FilterGenerator(localDW->f_initialize_LateralJerkEstimation_e, localDW->filter_discrete_num_l,
                                       localDW->filter_discrete_denom_j);

   /* End of Outputs for SubSystem: '<S71>/Coe1FilterGenerator' */

   /* Chart: '<S88>/Chart' */
   GradeEstimation_Chart(&localDW->f_initialize_LateralJerkEstimation, &localDW->sf_Chart_g);

   /* Outputs for Enabled SubSystem: '<S88>/Coe1FilterGenerator' */
   GradeEstimation_Coe1FilterGenerator(localDW->f_initialize_LateralJerkEstimation, localDW->filter_discrete_num,
                                       localDW->filter_discrete_denom);

   /* End of Outputs for SubSystem: '<S88>/Coe1FilterGenerator' */

   /* Chart: '<S70>/Chart' */
   GradeEstimation_Chart(&localDW->f_initialize_LateralJerkEstimation_o, &localDW->sf_Chart_d);

   /* Outputs for Enabled SubSystem: '<S70>/Coe1FilterGenerator' */
   GradeEstimation_Coe1FilterGenerator(localDW->f_initialize_LateralJerkEstimation_o, localDW->filter_discrete_num_d,
                                       localDW->filter_discrete_denom_e3);

   /* End of Outputs for SubSystem: '<S70>/Coe1FilterGenerator' */

   /* Chart: '<S87>/Chart' */
   GradeEstimation_Chart(&localDW->f_initialize_LateralJerkEstimation_b, &localDW->sf_Chart_e);

   /* Outputs for Enabled SubSystem: '<S87>/Coe1FilterGenerator' */
   GradeEstimation_Coe1FilterGenerator(localDW->f_initialize_LateralJerkEstimation_b, localDW->filter_discrete_num_a,
                                       localDW->filter_discrete_denom_e);

   /* End of Outputs for SubSystem: '<S87>/Coe1FilterGenerator' */

   /* Chart: '<S65>/Debouncer' incorporates:
    *  Abs: '<S45>/Abs'
    *  Abs: '<S45>/Abs1'
    *  Constant: '<S61>/Constant'
    *  Constant: '<S62>/Constant'
    *  Delay: '<S45>/Delay2'
    *  Logic: '<S45>/Logical Operator1'
    *  RelationalOperator: '<S61>/Compare'
    *  RelationalOperator: '<S62>/Compare'
    *  Sum: '<S45>/Add4'
    */
   GradeEstimation_Debouncer(
      (fabsf(*rtu_VsVSE_rad_VCSSideslip) > 0.03F) || (fabsf((*rtu_VsVSE_rad_VCSSideslip) - localDW->Delay2_DSTATE) >= 0.003F),
      &localDW->Output, &localDW->Fault_l, &localDW->sf_Debouncer_c, 0.3F, true, 0.05F, false, true, 0.05F, 1.0F);

   /* Saturate: '<S43>/IMUAccLimit' */
   if ((*rtu_VsVSE_mps2_VehicleRawLongAccel) > 8.0F)
   {
      rtb_Filt_Lateral_Acceleration_h = 8.0F;
   }
   else if ((*rtu_VsVSE_mps2_VehicleRawLongAccel) < -8.0F)
   {
      rtb_Filt_Lateral_Acceleration_h = -8.0F;
   }
   else
   {
      rtb_Filt_Lateral_Acceleration_h = *rtu_VsVSE_mps2_VehicleRawLongAccel;
   }

   /* End of Saturate: '<S43>/IMUAccLimit' */

   /* DiscreteTransferFcn: '<S77>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S70>/Data Type Conversion'
    */
   localDW->LowPassFilter_tmp =
      (((((real_T)rtb_Filt_Lateral_Acceleration_h) - (localDW->filter_discrete_denom_e3[1] * localDW->LowPassFilter_states[0])) -
        (localDW->filter_discrete_denom_e3[2] * localDW->LowPassFilter_states[1])) -
       (localDW->filter_discrete_denom_e3[3] * localDW->LowPassFilter_states[2])) -
      (localDW->filter_discrete_denom_e3[4] * localDW->LowPassFilter_states[3]);
   rtb_Abs = ((((localDW->filter_discrete_num_d[0] * localDW->LowPassFilter_tmp) +
                (localDW->filter_discrete_num_d[1] * localDW->LowPassFilter_states[0])) +
               (localDW->filter_discrete_num_d[2] * localDW->LowPassFilter_states[1])) +
              (localDW->filter_discrete_num_d[3] * localDW->LowPassFilter_states[2])) +
             (localDW->filter_discrete_num_d[4] * localDW->LowPassFilter_states[3]);

   /* Switch: '<S77>/Switch' incorporates:
    *  Abs: '<S77>/Abs'
    *  Constant: '<S77>/Constant'
    *  Constant: '<S79>/Constant'
    *  DiscreteTransferFcn: '<S77>/LowPass Filter'
    *  RelationalOperator: '<S79>/Compare'
    */
   if (fabs(rtb_Abs) <= 1.0E-10)
   {
      rtb_Abs = 0.0;
   }

   /* End of Switch: '<S77>/Switch' */

   /* Chart: '<S60>/Debouncer' incorporates:
    *  Abs: '<S45>/Abs3'
    *  Abs: '<S45>/Abs4'
    *  Constant: '<S63>/Constant'
    *  Constant: '<S64>/Constant'
    *  DataTypeConversion: '<S77>/Data Type Conversion'
    *  Delay: '<S45>/Delay3'
    *  Logic: '<S45>/Logical Operator3'
    *  RelationalOperator: '<S63>/Compare'
    *  RelationalOperator: '<S64>/Compare'
    *  Sum: '<S45>/Add6'
    */
   GradeEstimation_Debouncer((fabsf((real32_T)rtb_Abs) >= 3.0F) && (fabsf(((real32_T)rtb_Abs) - localDW->Delay3_DSTATE) >= 0.03F),
                             &localDW->Output_g, &localDW->Fault_b, &localDW->sf_Debouncer_h, 0.3F, true, 0.05F, false, true,
                             0.05F, 1.0F);

   /* DiscreteTransferFcn: '<S82>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S71>/Data Type Conversion'
    */
   localDW->LowPassFilter_tmp_p =
      (((((real_T)(*rtu_VsVSE_mps_VehicleSpeed)) - (localDW->filter_discrete_denom_j[1] * localDW->LowPassFilter_states_h[0])) -
        (localDW->filter_discrete_denom_j[2] * localDW->LowPassFilter_states_h[1])) -
       (localDW->filter_discrete_denom_j[3] * localDW->LowPassFilter_states_h[2])) -
      (localDW->filter_discrete_denom_j[4] * localDW->LowPassFilter_states_h[3]);
   rtb_Fused_n = ((((localDW->filter_discrete_num_l[0] * localDW->LowPassFilter_tmp_p) +
                    (localDW->filter_discrete_num_l[1] * localDW->LowPassFilter_states_h[0])) +
                   (localDW->filter_discrete_num_l[2] * localDW->LowPassFilter_states_h[1])) +
                  (localDW->filter_discrete_num_l[3] * localDW->LowPassFilter_states_h[2])) +
                 (localDW->filter_discrete_num_l[4] * localDW->LowPassFilter_states_h[3]);

   /* Switch: '<S82>/Switch' incorporates:
    *  Abs: '<S82>/Abs'
    *  Constant: '<S82>/Constant'
    *  Constant: '<S84>/Constant'
    *  DiscreteTransferFcn: '<S82>/LowPass Filter'
    *  RelationalOperator: '<S84>/Compare'
    */
   if (fabs(rtb_Fused_n) <= 1.0E-10)
   {
      rtb_Fused_n = 0.0;
   }

   /* End of Switch: '<S82>/Switch' */

   /* DataTypeConversion: '<S82>/Data Type Conversion' */
   rtb_Filt_Lateral_Acceleration_h = (real32_T)rtb_Fused_n;

   /* Abs: '<S47>/Abs5' incorporates:
    *  DataTypeConversion: '<S82>/Data Type Conversion'
    */
   rtb_Integrator = fabsf((real32_T)rtb_Fused_n);

   /* Chart: '<S58>/Debouncer' incorporates:
    *  Constant: '<S56>/Constant'
    *  Constant: '<S57>/Constant'
    *  Logic: '<S47>/Logical Operator2'
    *  RelationalOperator: '<S56>/Compare'
    *  RelationalOperator: '<S57>/Compare'
    */
   GradeEstimation_Debouncer((rtb_Integrator >= 0.02F) && (rtb_Integrator <= 2.0F), &localDW->Output_h, &localDW->Fault_h,
                             &localDW->sf_Debouncer_d, 0.3F, true, 0.05F, false, true, 0.05F, 1.0F);

   /* Chart: '<S50>/Debouncer' incorporates:
    *  Abs: '<S46>/Abs2'
    *  Abs: '<S46>/Abs3'
    *  Constant: '<S48>/Constant'
    *  Constant: '<S49>/Constant'
    *  DataTypeConversion: '<S77>/Data Type Conversion'
    *  DataTypeConversion: '<S82>/Data Type Conversion'
    *  Logic: '<S46>/Logical Operator1'
    *  RelationalOperator: '<S48>/Compare'
    *  RelationalOperator: '<S49>/Compare'
    */
   GradeEstimation_Debouncer((fabsf((real32_T)rtb_Fused_n) < 0.02F) && (fabsf((real32_T)rtb_Abs) <= 0.15F), &localDW->Output_a,
                             &localDW->Fault_p, &localDW->sf_Debouncer_k, 0.3F, true, 0.05F, false, true, 0.05F, 1.0F);

   /* Chart: '<S52>/Debouncer' */
   GradeEstimation_Debouncer(localDW->Output_a, &localDW->Output_p, &localDW->Fault_o, &localDW->sf_Debouncer_km, 0.3F, true,
                             0.05F, false, true, 0.05F, 1.0F);

   /* Chart: '<S14>/Chart' */
   GradeEstimation_Chart(&localDW->f_initialize_LateralJerkEstimation_d, &localDW->sf_Chart_o);

   /* Outputs for Enabled SubSystem: '<S14>/Coe1FilterGenerator' */
   GradeEstimation_Coe1FilterGenerator(localDW->f_initialize_LateralJerkEstimation_d, localDW->filter_discrete_num_m,
                                       localDW->filter_discrete_denom_jh);

   /* End of Outputs for SubSystem: '<S14>/Coe1FilterGenerator' */

   /* Chart: '<S13>/Chart' */
   GradeEstimation_Chart(&localDW->f_initialize_LateralJerkEstimation_p, &localDW->sf_Chart);

   /* Outputs for Enabled SubSystem: '<S13>/Coe1FilterGenerator' */
   GradeEstimation_Coe1FilterGenerator(localDW->f_initialize_LateralJerkEstimation_p, localDW->filter_discrete_num_k,
                                       localDW->filter_discrete_denom_n);

   /* End of Outputs for SubSystem: '<S13>/Coe1FilterGenerator' */

   /* Sum: '<S2>/Add2' incorporates:
    *  Delay: '<S2>/Delay10'
    */
   rtb_Substract_Alt = (*rtu_VsGPS_m_GPSAltitude) - localDW->Delay10_DSTATE;

   /* MATLABSystem: '<S2>/MovingAverage' */
   GradeEstimation_MovingAverage(rtb_Substract_Alt, &localDW->MovingAverage);

   /* Delay: '<S2>/Delay1' */
   rtb_delta_Alt_pre = localDW->Delay1_DSTATE;

   /* DiscreteTransferFcn: '<S96>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S82>/Data Type Conversion'
    *  DataTypeConversion: '<S88>/Data Type Conversion'
    *  Delay: '<S85>/Delay1'
    *  Sum: '<S85>/Add'
    */
   localDW->LowPassFilter_tmp_n = (((((real_T)((real32_T)(((real32_T)rtb_Fused_n) - localDW->Delay1_DSTATE_a[0]))) -
                                     (localDW->filter_discrete_denom[1] * localDW->LowPassFilter_states_p[0])) -
                                    (localDW->filter_discrete_denom[2] * localDW->LowPassFilter_states_p[1])) -
                                   (localDW->filter_discrete_denom[3] * localDW->LowPassFilter_states_p[2])) -
                                  (localDW->filter_discrete_denom[4] * localDW->LowPassFilter_states_p[3]);
   rtb_Fused_n = ((((localDW->filter_discrete_num[0] * localDW->LowPassFilter_tmp_n) +
                    (localDW->filter_discrete_num[1] * localDW->LowPassFilter_states_p[0])) +
                   (localDW->filter_discrete_num[2] * localDW->LowPassFilter_states_p[1])) +
                  (localDW->filter_discrete_num[3] * localDW->LowPassFilter_states_p[2])) +
                 (localDW->filter_discrete_num[4] * localDW->LowPassFilter_states_p[3]);

   /* Switch: '<S96>/Switch' incorporates:
    *  Abs: '<S96>/Abs'
    *  Constant: '<S96>/Constant'
    *  Constant: '<S98>/Constant'
    *  DiscreteTransferFcn: '<S96>/LowPass Filter'
    *  RelationalOperator: '<S98>/Compare'
    */
   if (fabs(rtb_Fused_n) <= 1.0E-10)
   {
      rtb_Fused_n = 0.0;
   }

   /* End of Switch: '<S96>/Switch' */

   /* DataTypeConversion: '<S96>/Data Type Conversion' */
   rtb_Integrator = (real32_T)rtb_Fused_n;

   /* DiscreteIntegrator: '<S85>/DiscreteTime Integrator' incorporates:
    *  DataTypeConversion: '<S77>/Data Type Conversion'
    */
   Integrator_Ax_tmp      = 0.005F * ((real32_T)rtb_Abs);
   localDW->Integrator_Ax = Integrator_Ax_tmp + localDW->DiscreteTimeIntegrator_DSTATE;

   /* DiscreteTransferFcn: '<S91>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S87>/Data Type Conversion'
    *  Delay: '<S85>/Delay6'
    *  Sum: '<S85>/Add1'
    */
   localDW->LowPassFilter_tmp_m = (((((real_T)((real32_T)(localDW->Integrator_Ax - localDW->Delay6_DSTATE[0]))) -
                                     (localDW->filter_discrete_denom_e[1] * localDW->LowPassFilter_states_px[0])) -
                                    (localDW->filter_discrete_denom_e[2] * localDW->LowPassFilter_states_px[1])) -
                                   (localDW->filter_discrete_denom_e[3] * localDW->LowPassFilter_states_px[2])) -
                                  (localDW->filter_discrete_denom_e[4] * localDW->LowPassFilter_states_px[3]);
   rtb_Fused_n = ((((localDW->filter_discrete_num_a[0] * localDW->LowPassFilter_tmp_m) +
                    (localDW->filter_discrete_num_a[1] * localDW->LowPassFilter_states_px[0])) +
                   (localDW->filter_discrete_num_a[2] * localDW->LowPassFilter_states_px[1])) +
                  (localDW->filter_discrete_num_a[3] * localDW->LowPassFilter_states_px[2])) +
                 (localDW->filter_discrete_num_a[4] * localDW->LowPassFilter_states_px[3]);

   /* Switch: '<S91>/Switch' incorporates:
    *  Abs: '<S91>/Abs'
    *  Constant: '<S91>/Constant'
    *  Constant: '<S93>/Constant'
    *  DiscreteTransferFcn: '<S91>/LowPass Filter'
    *  RelationalOperator: '<S93>/Compare'
    */
   if (fabs(rtb_Fused_n) <= 1.0E-10)
   {
      rtb_Fused_n = 0.0;
   }

   /* End of Switch: '<S91>/Switch' */

   /* Sum: '<S85>/Add5' incorporates:
    *  DataTypeConversion: '<S91>/Data Type Conversion'
    */
   rtb_Ax_Vx_g5 = ((real32_T)rtb_Fused_n) - rtb_Integrator;

   /* Product: '<S85>/Divide6' incorporates:
    *  Constant: '<S85>/Constant3'
    */
   rtb_Integrator = (real32_T)((real_T)(10.0 * ((real_T)(*rtu_VsVSE_sec_SystemExecutionTime))));

   /* Saturate: '<S85>/Saturation' */
   if (rtb_Integrator > 0.2F)
   {
      rtb_Integrator = 0.2F;
   }
   else
   {
      if (rtb_Integrator < 0.001F)
      {
         rtb_Integrator = 0.001F;
      }
   }

   /* End of Saturate: '<S85>/Saturation' */

   /* Product: '<S85>/Divide3' incorporates:
    *  Constant: '<S85>/Constant1'
    *  Product: '<S85>/Divide2'
    */
   rtb_Ax_Vx_g5 = (rtb_Ax_Vx_g5 / 9.803F) / rtb_Integrator;

   /* Trigonometry: '<S85>/Sin3' incorporates:
    *  Constant: '<S85>/Constant'
    *  Sum: '<S85>/Add2'
    */
   u0 = sin(1.5707963267948966 - ((real_T)rtb_Ax_Vx_g5));

   /* Saturate: '<S85>/Saturation2' */
   if (u0 > 0.999)
   {
      u0 = 0.999;
   }
   else
   {
      if (u0 < 0.001)
      {
         u0 = 0.001;
      }
   }

   /* End of Saturate: '<S85>/Saturation2' */

   /* Product: '<S85>/Divide4' incorporates:
    *  Constant: '<S85>/Constant6'
    *  Product: '<S85>/Divide9'
    *  Trigonometry: '<S85>/Sin'
    */
   rtb_IMU_Est_Grade_SideSlip = (real32_T)((real_T)(((real_T)((real32_T)((real_T)(((real_T)sinf(rtb_Ax_Vx_g5)) / u0)))) * 100.0));
   GradeEstimation_MovingAverage(rtb_IMU_Est_Grade_SideSlip, &localDW->MovingAverage_p);

   /* MATLAB Function: '<S86>/IMUBasedGradeEstimatonAx' */
   if ((localDW->Output) && (!localDW->Output_g))
   {
      rtb_Ax_Vx_g5 = rtb_IMU_Est_Grade_SideSlip;
   }
   else if ((!localDW->Output) && (localDW->Output_g))
   {
      rtb_Ax_Vx_g5 = localDW->MovingAverage_p.VsVSE_m_AvgDeltaAlt;
   }
   else
   {
      rtb_Ax_Vx_g5 = rtb_IMU_Est_Grade_SideSlip;
   }

   if ((localDW->Output) && (localDW->Output_g))
   {
      rtb_Ax_Vx_g5 = (0.5F * rtb_IMU_Est_Grade_SideSlip) + (0.5F * localDW->MovingAverage_p.VsVSE_m_AvgDeltaAlt);
   }

   /* End of MATLAB Function: '<S86>/IMUBasedGradeEstimatonAx' */

   /* Product: '<S85>/Divide5' incorporates:
    *  Constant: '<S85>/Constant1'
    *  DataTypeConversion: '<S91>/Data Type Conversion'
    *  Product: '<S85>/Divide1'
    */
   rtb_Integrator = (((real32_T)rtb_Fused_n) / 9.803F) / rtb_Integrator;

   /* Trigonometry: '<S85>/Sin2' incorporates:
    *  Constant: '<S85>/Constant2'
    *  Sum: '<S85>/Add3'
    */
   u0 = sin(1.5707963267948966 - ((real_T)rtb_Integrator));

   /* Outputs for Enabled SubSystem: '<S86>/StationaryHold' incorporates:
    *  EnablePort: '<S101>/Enable'
    */
   /* Logic: '<S86>/Logical Operator1' */
   if (!localDW->Output_p)
   {
      /* MATLAB Function: '<S86>/IMUBasedSwitchLogic' */
      if (localDW->Output_a)
      {
         /* Saturate: '<S85>/Saturation1' */
         if (u0 > 0.999)
         {
            u0 = 0.999;
         }
         else
         {
            if (u0 < 0.001)
            {
               u0 = 0.001;
            }
         }

         /* End of Saturate: '<S85>/Saturation1' */

         /* Gain: '<S101>/Gain' incorporates:
          *  Constant: '<S85>/Constant6'
          *  Product: '<S85>/Divide7'
          *  Product: '<S85>/Divide8'
          *  Trigonometry: '<S85>/Sin1'
          */
         localDW->Estimated_Grade_Percentage_p =
            (real32_T)((real_T)(((real_T)((real32_T)((real_T)(((real_T)sinf(rtb_Integrator)) / u0)))) * 100.0));
      }
      else
      {
         /* Gain: '<S101>/Gain' */
         localDW->Estimated_Grade_Percentage_p = rtb_Ax_Vx_g5;
      }

      /* End of MATLAB Function: '<S86>/IMUBasedSwitchLogic' */
   }

   /* End of Logic: '<S86>/Logical Operator1' */
   /* End of Outputs for SubSystem: '<S86>/StationaryHold' */

   /* MATLAB Function: '<S69>/MATLABFunction' */
   if (!localDW->bitsForTID0.first_time_stamp_temp_not_empty)
   {
      localDW->first_time_stamp_temp                       = *rtu_VsSYS_ms_SystemTime;
      localDW->bitsForTID0.first_time_stamp_temp_not_empty = true;
   }

   /* Product: '<S69>/Multiply' incorporates:
    *  Constant: '<S69>/microsecTosec'
    *  DataTypeConversion: '<S69>/Data Type Conversion'
    *  MATLAB Function: '<S69>/MATLABFunction'
    *  Sum: '<S69>/Add'
    */
   rtb_Integrator = ((real32_T)((uint64_T)((*rtu_VsSYS_ms_SystemTime) - localDW->first_time_stamp_temp))) * 1.0E-6F;

   /* Abs: '<S2>/Abs7' incorporates:
    *  Delay: '<S2>/Delay12'
    *  Sum: '<S2>/Add9'
    */
   rtb_Ax_Vx_g5 = fabsf(rtb_Integrator - localDW->Delay12_DSTATE);

   /* DiscreteTransferFcn: '<S22>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S14>/Data Type Conversion'
    *  Sum: '<S2>/Add10'
    *  UnitDelay: '<S2>/Unit Delay2'
    */
   localDW->LowPassFilter_tmp_pq = (((((real_T)((real32_T)(rtb_Filt_Lateral_Acceleration_h - localDW->UnitDelay2_DSTATE))) -
                                      (localDW->filter_discrete_denom_jh[1] * localDW->LowPassFilter_states_d[0])) -
                                     (localDW->filter_discrete_denom_jh[2] * localDW->LowPassFilter_states_d[1])) -
                                    (localDW->filter_discrete_denom_jh[3] * localDW->LowPassFilter_states_d[2])) -
                                   (localDW->filter_discrete_denom_jh[4] * localDW->LowPassFilter_states_d[3]);
   rtb_Fused_n = ((((localDW->filter_discrete_num_m[0] * localDW->LowPassFilter_tmp_pq) +
                    (localDW->filter_discrete_num_m[1] * localDW->LowPassFilter_states_d[0])) +
                   (localDW->filter_discrete_num_m[2] * localDW->LowPassFilter_states_d[1])) +
                  (localDW->filter_discrete_num_m[3] * localDW->LowPassFilter_states_d[2])) +
                 (localDW->filter_discrete_num_m[4] * localDW->LowPassFilter_states_d[3]);

   /* Switch: '<S22>/Switch' incorporates:
    *  Abs: '<S22>/Abs'
    *  Constant: '<S22>/Constant'
    *  Constant: '<S24>/Constant'
    *  DiscreteTransferFcn: '<S22>/LowPass Filter'
    *  RelationalOperator: '<S24>/Compare'
    */
   if (fabs(rtb_Fused_n) <= 1.0E-10)
   {
      rtb_Fused_n = 0.0;
   }

   /* End of Switch: '<S22>/Switch' */

   /* MATLAB Function: '<S8>/GradeEstimation' incorporates:
    *  DataTypeConversion: '<S22>/Data Type Conversion'
    *  UnitDelay: '<S8>/Unit Delay3'
    */
   if (((real_T)rtb_Ax_Vx_g5) < 0.001)
   {
      rtb_Ax_Vx_g5 = 0.001F;
   }

   A = ((real32_T)rtb_Fused_n) / rtb_Ax_Vx_g5;
   if (A > 8.0F)
   {
      A = 8.0F;
   }

   if (A < -8.0F)
   {
      A = -8.0F;
   }

   if (rtb_Filt_Lateral_Acceleration_h < 0.02F)
   {
      rtb_Ax_Vx_g5 = ((0.5F * A) * (rtb_Ax_Vx_g5 * rtb_Ax_Vx_g5)) + (rtb_Filt_Lateral_Acceleration_h * rtb_Ax_Vx_g5);
      if (fabsf(rtb_Ax_Vx_g5) <= 1.0E-6F)
      {
         sin_alpha = 0.001F;
         A         = 0.999F;
      }
      else
      {
         if (((real_T)rtb_Ax_Vx_g5) < 0.001)
         {
            A = 0.001F;
         }
         else
         {
            A = rtb_Ax_Vx_g5;
         }

         sin_alpha = localDW->MovingAverage.VsVSE_m_AvgDeltaAlt / A;
         if (((real_T)rtb_Ax_Vx_g5) < 0.001)
         {
            A = 0.001F;
         }
         else
         {
            A = rtb_Ax_Vx_g5;
         }

         A = rtb_Ax_Vx_g5 / A;
      }
   }
   else
   {
      rtb_Ax_Vx_g5 *= rtb_Filt_Lateral_Acceleration_h;
      A = sqrtf((localDW->MovingAverage.VsVSE_m_AvgDeltaAlt * localDW->MovingAverage.VsVSE_m_AvgDeltaAlt) +
                (rtb_Ax_Vx_g5 * rtb_Ax_Vx_g5));
      if (((real_T)A) < 0.001)
      {
         sin_alpha = 0.001F;
         A         = 0.001F;
      }
      else
      {
         sin_alpha = A;
      }

      sin_alpha = localDW->MovingAverage.VsVSE_m_AvgDeltaAlt / sin_alpha;
      A         = rtb_Ax_Vx_g5 / A;
   }

   if (rtb_Ax_Vx_g5 > 0.05F)
   {
      if (((real_T)A) < 0.001)
      {
         A = 0.001F;
      }

      localDW->UnitDelay3_DSTATE = (sin_alpha / A) * 100.0F;
   }

   /* End of MATLAB Function: '<S8>/GradeEstimation' */

   /* DiscreteTransferFcn: '<S17>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S13>/Data Type Conversion'
    *  UnitDelay: '<S8>/Unit Delay3'
    */
   localDW->LowPassFilter_tmp_h =
      (((((real_T)localDW->UnitDelay3_DSTATE) - (localDW->filter_discrete_denom_n[1] * localDW->LowPassFilter_states_j[0])) -
        (localDW->filter_discrete_denom_n[2] * localDW->LowPassFilter_states_j[1])) -
       (localDW->filter_discrete_denom_n[3] * localDW->LowPassFilter_states_j[2])) -
      (localDW->filter_discrete_denom_n[4] * localDW->LowPassFilter_states_j[3]);
   rtb_Fused_n = ((((localDW->filter_discrete_num_k[0] * localDW->LowPassFilter_tmp_h) +
                    (localDW->filter_discrete_num_k[1] * localDW->LowPassFilter_states_j[0])) +
                   (localDW->filter_discrete_num_k[2] * localDW->LowPassFilter_states_j[1])) +
                  (localDW->filter_discrete_num_k[3] * localDW->LowPassFilter_states_j[2])) +
                 (localDW->filter_discrete_num_k[4] * localDW->LowPassFilter_states_j[3]);

   /* Switch: '<S17>/Switch' incorporates:
    *  Abs: '<S17>/Abs'
    *  Constant: '<S17>/Constant'
    *  Constant: '<S19>/Constant'
    *  DiscreteTransferFcn: '<S17>/LowPass Filter'
    *  RelationalOperator: '<S19>/Compare'
    */
   if (fabs(rtb_Fused_n) <= 1.0E-10)
   {
      rtb_Fused_n = 0.0;
   }

   /* End of Switch: '<S17>/Switch' */

   /* Logic: '<S45>/Logical Operator4' */
   rtb_Transition = ((localDW->Output_g) || (localDW->Output));

   /* Chart: '<S9>/Debouncer' incorporates:
    *  MATLAB Function: '<S7>/GPSAltitudeJumpCheck'
    */
   GradeEstimation_Debouncer(fabsf(rtb_delta_Alt_pre - localDW->MovingAverage.VsVSE_m_AvgDeltaAlt) > 0.002F, &localDW->Output_e,
                             &localDW->Fault_ly, &localDW->sf_Debouncer, 0.3F, true, 0.05F, false, true, 0.05F, 1.0F);

   /* RelationalOperator: '<S104>/Compare' incorporates:
    *  Constant: '<S104>/Constant'
    */
   rtb_Compare_j = (((uint32_T)(*rtu_VeVCAN_IMUValidity)) == ACCURATED);

   /* Chart: '<S6>/IMUDebouncer' */
   if (localDW->temporalCounter_i1 < MAX_uint32_T)
   {
      localDW->temporalCounter_i1++;
   }

   if (((uint32_T)localDW->temporalCounter_i2) < 511U)
   {
      localDW->temporalCounter_i2 = (uint16_T)(((uint32_T)localDW->temporalCounter_i2) + 1U);
   }

   if (((uint32_T)localDW->bitsForTID0.is_active_c21_GradeEstimation) == 0U)
   {
      localDW->bitsForTID0.is_active_c21_GradeEstimation = 1;
      localDW->bitsForTID0.is_c21_GradeEstimation        = GradeEstimation_IN_Check_On_Initial;
      localDW->bitsForTID0.Debounced_IMU                 = true;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c21_GradeEstimation)
      {
         case GradeEstimation_IN_Check_Off:
            if (((uint32_T)localDW->bitsForTID0.is_Check_Off) == GradeEstimation_IN_Fault_a)
            {
               if (((uint32_T)localDW->temporalCounter_i2) >= 300U)
               {
                  localDW->bitsForTID0.Fault        = false;
                  localDW->bitsForTID0.is_Check_Off = GradeEstimation_IN_Normal_l;
               }
            }
            else
            {
               if (rtb_Compare_j)
               {
                  localDW->bitsForTID0.is_Check_Off           = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
                  localDW->bitsForTID0.is_c21_GradeEstimation = GradeEstimation_IN_Debounce_Fault;
                  localDW->temporalCounter_i1                 = 0U;
                  localDW->bitsForTID0.is_Debounce_Fault      = GradeEstimation_IN_On_a;
                  localDW->temporalCounter_i2                 = 0U;
               }
            }
            break;

         case GradeEstimation_IN_Check_On:
            if (!rtb_Compare_j)
            {
               localDW->bitsForTID0.is_c21_GradeEstimation = GradeEstimation_IN_Debounce_Fault;
               localDW->temporalCounter_i1                 = 0U;
               localDW->bitsForTID0.is_Debounce_Fault      = GradeEstimation_IN_Off_j;
               localDW->temporalCounter_i2                 = 0U;
            }
            else
            {
               if ((((real_T)localDW->temporalCounter_i1) * 0.01) >= GradeEstimation_IMU_Recovery_Time)
               {
                  localDW->bitsForTID0.Debounced_IMU = true;
               }
            }
            break;

         case GradeEstimation_IN_Check_On_Initial:
            localDW->bitsForTID0.is_c21_GradeEstimation = GradeEstimation_IN_Check_On;
            localDW->temporalCounter_i1                 = 0U;
            break;

         default:
            if (localDW->temporalCounter_i1 >= 5U)
            {
               localDW->bitsForTID0.is_Debounce_Fault      = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
               localDW->bitsForTID0.is_c21_GradeEstimation = GradeEstimation_IN_Check_Off;
               localDW->temporalCounter_i1                 = 0U;
               localDW->bitsForTID0.Debounced_IMU          = false;
               localDW->bitsForTID0.is_Check_Off           = GradeEstimation_IN_Fault_a;
               localDW->temporalCounter_i2                 = 0U;
               localDW->bitsForTID0.Fault                  = true;
            }
            else if (((uint32_T)localDW->bitsForTID0.is_Debounce_Fault) == GradeEstimation_IN_Off_j)
            {
               if (((uint32_T)localDW->temporalCounter_i2) >= 2U)
               {
                  localDW->bitsForTID0.is_Debounce_Fault      = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
                  localDW->bitsForTID0.is_c21_GradeEstimation = GradeEstimation_IN_Check_Off;
                  localDW->temporalCounter_i1                 = 0U;
                  localDW->bitsForTID0.Debounced_IMU          = false;
                  localDW->bitsForTID0.is_Check_Off           = GradeEstimation_IN_Normal_l;
               }
               else
               {
                  if (rtb_Compare_j)
                  {
                     localDW->bitsForTID0.is_Debounce_Fault = GradeEstimation_IN_On_a;
                     localDW->temporalCounter_i2            = 0U;
                  }
               }
            }
            else if (((uint32_T)localDW->temporalCounter_i2) >= 2U)
            {
               localDW->bitsForTID0.is_Debounce_Fault      = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
               localDW->bitsForTID0.is_c21_GradeEstimation = GradeEstimation_IN_Check_On;
               localDW->temporalCounter_i1                 = 0U;
            }
            else
            {
               if (!rtb_Compare_j)
               {
                  localDW->bitsForTID0.is_Debounce_Fault = GradeEstimation_IN_Off_j;
                  localDW->temporalCounter_i2            = 0U;
               }
            }
            break;
      }
   }

   /* End of Chart: '<S6>/IMUDebouncer' */

   /* Chart: '<S6>/GNMMDebouncer' */
   if (localDW->temporalCounter_i1_d < MAX_uint32_T)
   {
      localDW->temporalCounter_i1_d++;
   }

   if (((uint32_T)localDW->temporalCounter_i2_c) < 511U)
   {
      localDW->temporalCounter_i2_c = (uint16_T)(((uint32_T)localDW->temporalCounter_i2_c) + 1U);
   }

   if (((uint32_T)localDW->bitsForTID0.is_active_c6_GradeEstimation) == 0U)
   {
      localDW->bitsForTID0.is_active_c6_GradeEstimation = 1;
      localDW->bitsForTID0.is_c6_GradeEstimation        = GradeEstimation_IN_Check_On_Initial;
      localDW->bitsForTID0.Debounced_GNMM               = true;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c6_GradeEstimation)
      {
         case GradeEstimation_IN_Check_Off:
            if (((uint32_T)localDW->bitsForTID0.is_Check_Off_e) == GradeEstimation_IN_Fault_a)
            {
               if (((uint32_T)localDW->temporalCounter_i2_c) >= 300U)
               {
                  localDW->bitsForTID0.Fault_k        = false;
                  localDW->bitsForTID0.is_Check_Off_e = GradeEstimation_IN_Normal_l;
               }
            }
            else
            {
               if (*rtu_VsGPS_b_GPSValidity)
               {
                  localDW->bitsForTID0.is_Check_Off_e        = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
                  localDW->bitsForTID0.is_c6_GradeEstimation = GradeEstimation_IN_Debounce_Fault;
                  localDW->temporalCounter_i1_d              = 0U;
                  localDW->bitsForTID0.is_Debounce_Fault_g   = GradeEstimation_IN_On_a;
                  localDW->temporalCounter_i2_c              = 0U;
               }
            }
            break;

         case GradeEstimation_IN_Check_On:
            if (!(*rtu_VsGPS_b_GPSValidity))
            {
               localDW->bitsForTID0.is_c6_GradeEstimation = GradeEstimation_IN_Debounce_Fault;
               localDW->temporalCounter_i1_d              = 0U;
               localDW->bitsForTID0.is_Debounce_Fault_g   = GradeEstimation_IN_Off_j;
               localDW->temporalCounter_i2_c              = 0U;
            }
            else
            {
               if ((((real_T)localDW->temporalCounter_i1_d) * 0.01) >= GradeEstimation_GNMM_Recovery_Time)
               {
                  localDW->bitsForTID0.Debounced_GNMM = true;
               }
            }
            break;

         case GradeEstimation_IN_Check_On_Initial:
            localDW->bitsForTID0.is_c6_GradeEstimation = GradeEstimation_IN_Check_On;
            localDW->temporalCounter_i1_d              = 0U;
            break;

         default:
            if (localDW->temporalCounter_i1_d >= 5U)
            {
               localDW->bitsForTID0.is_Debounce_Fault_g   = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
               localDW->bitsForTID0.is_c6_GradeEstimation = GradeEstimation_IN_Check_Off;
               localDW->temporalCounter_i1_d              = 0U;
               localDW->bitsForTID0.Debounced_GNMM        = false;
               localDW->bitsForTID0.is_Check_Off_e        = GradeEstimation_IN_Fault_a;
               localDW->temporalCounter_i2_c              = 0U;
               localDW->bitsForTID0.Fault_k               = true;
            }
            else if (((uint32_T)localDW->bitsForTID0.is_Debounce_Fault_g) == GradeEstimation_IN_Off_j)
            {
               if (((uint32_T)localDW->temporalCounter_i2_c) >= 2U)
               {
                  localDW->bitsForTID0.is_Debounce_Fault_g   = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
                  localDW->bitsForTID0.is_c6_GradeEstimation = GradeEstimation_IN_Check_Off;
                  localDW->temporalCounter_i1_d              = 0U;
                  localDW->bitsForTID0.Debounced_GNMM        = false;
                  localDW->bitsForTID0.is_Check_Off_e        = GradeEstimation_IN_Normal_l;
               }
               else
               {
                  if (*rtu_VsGPS_b_GPSValidity)
                  {
                     localDW->bitsForTID0.is_Debounce_Fault_g = GradeEstimation_IN_On_a;
                     localDW->temporalCounter_i2_c            = 0U;
                  }
               }
            }
            else if (((uint32_T)localDW->temporalCounter_i2_c) >= 2U)
            {
               localDW->bitsForTID0.is_Debounce_Fault_g   = GradeEstimation_IN_NO_ACTIVE_CHILD_c;
               localDW->bitsForTID0.is_c6_GradeEstimation = GradeEstimation_IN_Check_On;
               localDW->temporalCounter_i1_d              = 0U;
            }
            else
            {
               if (!(*rtu_VsGPS_b_GPSValidity))
               {
                  localDW->bitsForTID0.is_Debounce_Fault_g = GradeEstimation_IN_Off_j;
                  localDW->temporalCounter_i2_c            = 0U;
               }
            }
            break;
      }
   }

   /* End of Chart: '<S6>/GNMMDebouncer' */

   /* Chart: '<S51>/Debouncer' incorporates:
    *  Logic: '<S46>/Logical Operator4'
    */
   GradeEstimation_Debouncer((localDW->Output_p) && (localDW->Output_a), &localDW->Output_k, &localDW->Fault_i,
                             &localDW->sf_Debouncer_e, 0.3F, true, 0.05F, false, true, 0.05F, 1.0F);

   /* MATLAB Function: '<S6>/DetermineIMUEnable' incorporates:
    *  DataTypeConversion: '<S6>/Data Type Conversion2'
    *  DataTypeConversion: '<S6>/Data Type Conversion6'
    */
   rtb_IMU_Enable = 0;
   if (localDW->bitsForTID0.Debounced_IMU)
   {
      rtb_IMU_Enable = 1;
   }

   if (localDW->bitsForTID0.Fault)
   {
      rtb_IMU_Enable = 0;
   }
   else
   {
      if (!localDW->bitsForTID0.Debounced_IMU)
      {
         rtb_IMU_Enable = 0;
      }
   }

   /* End of MATLAB Function: '<S6>/DetermineIMUEnable' */

   /* MATLAB Function: '<S6>/DetermineGPSEnable' incorporates:
    *  DataTypeConversion: '<S6>/Data Type Conversion1'
    */
   rtb_GNMM_Enable = 0;
   if (*rtu_VsVSE_b_UseGPSInput)
   {
      rtb_GNMM_Enable = localDW->bitsForTID0.Debounced_GNMM ? 1 : 0;
   }

   /* End of MATLAB Function: '<S6>/DetermineGPSEnable' */

   /* MATLAB Function: '<S6>/GradeEstimationSelectedSource' */
   if ((rtb_IMU_Enable == 0) && (rtb_GNMM_Enable == 0))
   {
      rtb_GNMM_Enable = 3;
   }
   else
   {
      rtb_GNMM_Enable = (int32_T)(((rtb_GNMM_Enable == 1) && (!localDW->Output_e)) ? 1 : 0);
   }

   if ((localDW->Output_k) || (rtb_Filt_Lateral_Acceleration_h <= 2.0F))
   {
      rtb_GNMM_Enable = 0;
   }

   if ((rtb_IMU_Enable == 1) && (localDW->Output_e))
   {
      rtb_GNMM_Enable = 0;
   }

   if ((rtb_IMU_Enable == 0) && (localDW->Output_e))
   {
      rtb_GNMM_Enable = 3;
   }

   /* End of MATLAB Function: '<S6>/GradeEstimationSelectedSource' */

   /* MATLAB Function: '<S6>/SwitchingDetected' incorporates:
    *  Delay: '<S6>/Delay8'
    */
   u0 = ((real_T)rtb_GNMM_Enable) - localDW->Delay8_DSTATE;
   if (u0 >= 1.0)
   {
      rtb_Compare_j = true;
   }
   else
   {
      rtb_Compare_j = (u0 <= -1.0);
   }

   /* End of MATLAB Function: '<S6>/SwitchingDetected' */

   /* MATLAB Function: '<S25>/AccuracyLevelDeternimation' */
   rtb_Compare_b3 = !rtb_Transition;
   if (((((!rtb_Compare_j) && rtb_Compare_b3) && (rtb_GNMM_Enable != 3)) && (rtb_Filt_Lateral_Acceleration_h > 2.0F)) ||
       (localDW->Output_k))
   {
      rtb_Accuracy_Level = HIGH_ACCURATED;
   }
   else
   {
      rtb_Accuracy_Level = NO_ACCURATED;
   }

   if ((rtb_Compare_j && rtb_Compare_b3) || ((rtb_Filt_Lateral_Acceleration_h <= 2.0F) && (!localDW->Output_k)))
   {
      rtb_Accuracy_Level = MEDIUM_ACCURATED;
   }

   if ((rtb_GNMM_Enable == 3) || rtb_Transition)
   {
      rtb_Accuracy_Level = NO_ACCURATED;
   }

   /* End of MATLAB Function: '<S25>/AccuracyLevelDeternimation' */

   /* Chart: '<S25>/AccuracyLevelDebouncer' */
   if (((uint32_T)localDW->temporalCounter_i1_i) < 7U)
   {
      localDW->temporalCounter_i1_i = (uint8_T)(((uint32_T)localDW->temporalCounter_i1_i) + 1U);
   }

   if (((uint32_T)localDW->bitsForTID0.is_active_c8_GradeEstimation) == 0U)
   {
      localDW->bitsForTID0.is_active_c8_GradeEstimation = 1;
      localDW->bitsForTID0.is_c8_GradeEstimation        = GradeEstimation_IN_Check_Off;
      localDW->temporalCounter_i1_i                     = 0U;
      *rty_VsVSE_EstimatedGradeAccuracy                 = NO_ACCURATED;
   }
   else
   {
      switch (localDW->bitsForTID0.is_c8_GradeEstimation)
      {
         case GradeEstimation_IN_Check_Off:
            *rty_VsVSE_EstimatedGradeAccuracy = NO_ACCURATED;
            if ((((uint32_T)localDW->temporalCounter_i1_i) >= 5U) && (((uint32_T)rtb_Accuracy_Level) == HIGH_ACCURATED))
            {
               localDW->bitsForTID0.is_c8_GradeEstimation = GradeEstimation_IN_Check_On1;
               localDW->temporalCounter_i1_i              = 0U;
               *rty_VsVSE_EstimatedGradeAccuracy          = HIGH_ACCURATED;
            }
            else
            {
               if ((((uint32_T)localDW->temporalCounter_i1_i) >= 5U) && (((uint32_T)rtb_Accuracy_Level) == MEDIUM_ACCURATED))
               {
                  localDW->bitsForTID0.is_c8_GradeEstimation = GradeEstimation_IN_Check_On;
                  localDW->temporalCounter_i1_i              = 0U;
                  *rty_VsVSE_EstimatedGradeAccuracy          = MEDIUM_ACCURATED;
               }
            }
            break;

         case GradeEstimation_IN_Check_On:
            *rty_VsVSE_EstimatedGradeAccuracy = MEDIUM_ACCURATED;
            if ((((uint32_T)localDW->temporalCounter_i1_i) >= 5U) && (((uint32_T)rtb_Accuracy_Level) == NO_ACCURATED))
            {
               localDW->bitsForTID0.is_c8_GradeEstimation = GradeEstimation_IN_Check_Off;
               localDW->temporalCounter_i1_i              = 0U;
               *rty_VsVSE_EstimatedGradeAccuracy          = NO_ACCURATED;
            }
            else
            {
               if ((((uint32_T)localDW->temporalCounter_i1_i) >= 5U) && (((uint32_T)rtb_Accuracy_Level) == HIGH_ACCURATED))
               {
                  localDW->bitsForTID0.is_c8_GradeEstimation = GradeEstimation_IN_Check_On1;
                  localDW->temporalCounter_i1_i              = 0U;
                  *rty_VsVSE_EstimatedGradeAccuracy          = HIGH_ACCURATED;
               }
            }
            break;

         default:
            *rty_VsVSE_EstimatedGradeAccuracy = HIGH_ACCURATED;
            if ((((uint32_T)localDW->temporalCounter_i1_i) >= 5U) && (((uint32_T)rtb_Accuracy_Level) == MEDIUM_ACCURATED))
            {
               localDW->bitsForTID0.is_c8_GradeEstimation = GradeEstimation_IN_Check_On;
               localDW->temporalCounter_i1_i              = 0U;
               *rty_VsVSE_EstimatedGradeAccuracy          = MEDIUM_ACCURATED;
            }
            else
            {
               if ((((uint32_T)localDW->temporalCounter_i1_i) >= 5U) && (((uint32_T)rtb_Accuracy_Level) == NO_ACCURATED))
               {
                  localDW->bitsForTID0.is_c8_GradeEstimation = GradeEstimation_IN_Check_Off;
                  localDW->temporalCounter_i1_i              = 0U;
                  *rty_VsVSE_EstimatedGradeAccuracy          = NO_ACCURATED;
               }
            }
            break;
      }
   }

   /* End of Chart: '<S25>/AccuracyLevelDebouncer' */

   /* Chart: '<S26>/Initialization_Trigger' */
   if (((uint32_T)localDW->bitsForTID0.is_active_c5_Initialization_Trigger) == 0U)
   {
      localDW->bitsForTID0.is_active_c5_Initialization_Trigger = 1;
      localDW->bitsForTID0.is_c5_Initialization_Trigger        = GradeEstimation_IN_Initialize_n;
      localDW->bitsForTID0.f_initialize                        = true;
   }
   else if (((uint32_T)localDW->bitsForTID0.is_c5_Initialization_Trigger) == GradeEstimation_IN_Initialize_n)
   {
      if (localDW->bitsForTID0.f_initialize)
      {
         localDW->bitsForTID0.is_c5_Initialization_Trigger = GradeEstimation_IN_Running_g;
         localDW->bitsForTID0.f_initialize                 = false;
      }
   }
   else
   {
      localDW->bitsForTID0.f_initialize = false;
   }

   /* End of Chart: '<S26>/Initialization_Trigger' */

   /* Outputs for Enabled SubSystem: '<S26>/Initialization' incorporates:
    *  EnablePort: '<S30>/Enable'
    */
   if (localDW->bitsForTID0.f_initialize)
   {
      /* MATLAB Function: '<S30>/MATLAB Function' */
      localDW->diff_num[0]   = 0.724336267F;
      localDW->diff_denom[0] = 1.0F;
      localDW->diff_num[1]   = 0.724336267F;
      localDW->diff_denom[1] = -0.822694957F;
      localDW->diff_num[2]   = -0.724336267F;
      localDW->diff_denom[2] = -0.98551327F;
      localDW->diff_num[3]   = -0.724336267F;
      localDW->diff_denom[3] = 0.837181628F;
   }

   /* End of Outputs for SubSystem: '<S26>/Initialization' */

   /* Switch: '<S6>/Switch2' incorporates:
    *  Constant: '<S6>/Constant1'
    *  Constant: '<S6>/Constant8'
    */
   if (rtb_Compare_j)
   {
      rtb_IMU_Enable = 2;
   }
   else
   {
      rtb_IMU_Enable = 5;
   }

   /* End of Switch: '<S6>/Switch2' */

   /* Product: '<S111>/delta rise limit' */
   rtb_Ax_Vx_g5 = (real32_T)((real_T)(((real_T)rtb_IMU_Enable) * 0.0099999997764825821));

   /* RelationalOperator: '<S103>/Compare' incorporates:
    *  Constant: '<S103>/Constant'
    */
   rtb_Transition = (rtb_GNMM_Enable < 2);

   /* Outputs for Enabled SubSystem: '<S6>/NoAvailableSourceHold' incorporates:
    *  EnablePort: '<S110>/Enable'
    */
   if (rtb_Transition)
   {
      /* Gain: '<S110>/Gain' incorporates:
       *  Delay: '<S110>/Delay8'
       */
      localDW->Estimated_Grade_Percentage = localDW->Delay8_DSTATE_i[0];
   }

   /* End of Outputs for SubSystem: '<S6>/NoAvailableSourceHold' */

   /* Sum: '<S111>/Difference Inputs1' incorporates:
    *  UnitDelay: '<S111>/Delay Input2'
    *
    * Block description for '<S111>/Difference Inputs1':
    *
    *  Add in CPU
    *
    * Block description for '<S111>/Delay Input2':
    *
    *  Store in Global RAM
    */
   rtb_delta_Alt_pre = localDW->Estimated_Grade_Percentage - localDW->DelayInput2_DSTATE;

   /* Switch: '<S113>/Switch2' incorporates:
    *  RelationalOperator: '<S113>/LowerRelop1'
    */
   if (rtb_delta_Alt_pre <= rtb_Ax_Vx_g5)
   {
      /* Switch: '<S6>/Switch4' incorporates:
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant3'
       */
      if (rtb_Compare_j)
      {
         rtb_IMU_Enable = -2;
      }
      else
      {
         rtb_IMU_Enable = -5;
      }

      /* End of Switch: '<S6>/Switch4' */

      /* Product: '<S111>/delta fall limit' */
      rtb_Ax_Vx_g5 = (real32_T)((real_T)(((real_T)rtb_IMU_Enable) * 0.0099999997764825821));

      /* Switch: '<S113>/Switch' incorporates:
       *  RelationalOperator: '<S113>/UpperRelop'
       */
      if (rtb_delta_Alt_pre >= rtb_Ax_Vx_g5)
      {
         rtb_Ax_Vx_g5 = rtb_delta_Alt_pre;
      }

      /* End of Switch: '<S113>/Switch' */
   }

   /* End of Switch: '<S113>/Switch2' */

   /* Sum: '<S111>/Difference Inputs2' incorporates:
    *  UnitDelay: '<S111>/Delay Input2'
    *
    * Block description for '<S111>/Difference Inputs2':
    *
    *  Add in CPU
    *
    * Block description for '<S111>/Delay Input2':
    *
    *  Store in Global RAM
    */
   localDW->DelayInput2_DSTATE += rtb_Ax_Vx_g5;

   /* Saturate: '<S6>/Grade_Limit4' incorporates:
    *  UnitDelay: '<S111>/Delay Input2'
    *
    * Block description for '<S111>/Delay Input2':
    *
    *  Store in Global RAM
    */
   if (localDW->DelayInput2_DSTATE > 157.89473F)
   {
      *rty_VsVSE_pct_EstimatedGrade = 157.89473F;
   }
   else if (localDW->DelayInput2_DSTATE < -157.89473F)
   {
      *rty_VsVSE_pct_EstimatedGrade = -157.89473F;
   }
   else
   {
      *rty_VsVSE_pct_EstimatedGrade = localDW->DelayInput2_DSTATE;
   }

   /* End of Saturate: '<S6>/Grade_Limit4' */

   /* DiscreteFilter: '<S26>/DiscreteFilter' */
   localDW->DiscreteFilter_tmp =
      (((*rty_VsVSE_pct_EstimatedGrade) - (localDW->diff_denom[1] * localDW->DiscreteFilter_states[0])) -
       (localDW->diff_denom[2] * localDW->DiscreteFilter_states[1])) -
      (localDW->diff_denom[3] * localDW->DiscreteFilter_states[2]);
   rtb_delta_Alt_pre =
      (((localDW->diff_num[0] * localDW->DiscreteFilter_tmp) + (localDW->diff_num[1] * localDW->DiscreteFilter_states[0])) +
       (localDW->diff_num[2] * localDW->DiscreteFilter_states[1])) +
      (localDW->diff_num[3] * localDW->DiscreteFilter_states[2]);

   /* Logic: '<S33>/Logical Operator' incorporates:
    *  Constant: '<S33>/Constant1'
    *  Constant: '<S33>/Constant2'
    *  DiscreteFilter: '<S26>/DiscreteFilter'
    *  RelationalOperator: '<S33>/Equal'
    *  RelationalOperator: '<S33>/Equal1'
    */
   rtb_Compare_j = ((rtb_delta_Alt_pre >= -40.0F) && (rtb_delta_Alt_pre <= 40.0F));

   /* RelationalOperator: '<S34>/Compare' incorporates:
    *  Constant: '<S34>/Constant'
    */
   rtb_Compare_b3 = (((uint32_T)(*rtu_VeVCAN_IMUValidity)) == ACCURATED);

   /* RelationalOperator: '<S35>/Compare' incorporates:
    *  Constant: '<S35>/Constant'
    */
   rtb_Compare_hg = (rtb_Filt_Lateral_Acceleration_h <= 2.0F);

   /* RelationalOperator: '<S36>/Compare' incorporates:
    *  Constant: '<S36>/Constant'
    */
   rtb_Compare_bu = (rtb_GNMM_Enable != 3);

   /* Logic: '<S32>/Logical Operator' incorporates:
    *  Constant: '<S32>/Constant1'
    *  Constant: '<S32>/Constant2'
    *  RelationalOperator: '<S32>/Equal'
    *  RelationalOperator: '<S32>/Equal1'
    */
   rtb_LogicalOperator_g = (((*rty_VsVSE_pct_EstimatedGrade) >= -140.350876F) && ((*rty_VsVSE_pct_EstimatedGrade) <= 140.350876F));

   /* If: '<S29>/If' incorporates:
    *  Constant: '<S29>/Constant'
    *  Constant: '<S29>/Constant1'
    *  Constant: '<S29>/Constant2'
    *  Constant: '<S29>/Constant3'
    *  Inport: '<S37>/In1'
    *  Inport: '<S38>/In1'
    *  Inport: '<S39>/In1'
    *  Inport: '<S40>/In1'
    */
   if (((((((*rtu_VsGPS_b_GPSValidity) || rtb_Compare_b3) && rtb_LogicalOperator_g) && rtb_Compare_j) && (!rtb_Compare_hg)) &&
        rtb_Compare_bu) ||
       (((localDW->Output_k) && rtb_Compare_hg) && rtb_Compare_bu))
   {
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      *rty_VsVSE_EstimatedGradeQF = ACCURATED;

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem1' */
   }
   else if (((((*rtu_VsGPS_b_GPSValidity) || rtb_Compare_b3) && (!rtb_LogicalOperator_g)) && rtb_Compare_j) && rtb_Compare_bu)
   {
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      *rty_VsVSE_EstimatedGradeQF = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem2' */
   }
   else if ((((((*rtu_VsGPS_b_GPSValidity) || rtb_Compare_b3) && rtb_LogicalOperator_g) && (!rtb_Compare_j)) && rtb_Compare_bu) ||
            (((!localDW->Output_k) && rtb_Compare_hg) && rtb_Compare_bu))
   {
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      *rty_VsVSE_EstimatedGradeQF = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      *rty_VsVSE_EstimatedGradeQF = UNDEFINED;

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem4' */
   }

   /* End of If: '<S29>/If' */

   /* Update for Delay: '<S45>/Delay2' */
   localDW->Delay2_DSTATE = *rtu_VsVSE_rad_VCSSideslip;

   /* Update for DiscreteTransferFcn: '<S77>/LowPass Filter' */
   localDW->LowPassFilter_states[3] = localDW->LowPassFilter_states[2];
   localDW->LowPassFilter_states[2] = localDW->LowPassFilter_states[1];
   localDW->LowPassFilter_states[1] = localDW->LowPassFilter_states[0];
   localDW->LowPassFilter_states[0] = localDW->LowPassFilter_tmp;

   /* Update for Delay: '<S45>/Delay3' incorporates:
    *  DataTypeConversion: '<S77>/Data Type Conversion'
    */
   localDW->Delay3_DSTATE = (real32_T)rtb_Abs;

   /* Update for DiscreteTransferFcn: '<S82>/LowPass Filter' */
   localDW->LowPassFilter_states_h[3] = localDW->LowPassFilter_states_h[2];
   localDW->LowPassFilter_states_h[2] = localDW->LowPassFilter_states_h[1];
   localDW->LowPassFilter_states_h[1] = localDW->LowPassFilter_states_h[0];
   localDW->LowPassFilter_states_h[0] = localDW->LowPassFilter_tmp_p;

   /* Update for Delay: '<S2>/Delay10' */
   localDW->Delay10_DSTATE = *rtu_VsGPS_m_GPSAltitude;

   /* Update for Delay: '<S2>/Delay1' */
   localDW->Delay1_DSTATE = localDW->MovingAverage.VsVSE_m_AvgDeltaAlt;
   for (rtb_IMU_Enable = 0; rtb_IMU_Enable < 9; rtb_IMU_Enable++)
   {
      /* Update for Delay: '<S85>/Delay1' */
      localDW->Delay1_DSTATE_a[rtb_IMU_Enable] = localDW->Delay1_DSTATE_a[rtb_IMU_Enable + 1];

      /* Update for Delay: '<S85>/Delay6' */
      localDW->Delay6_DSTATE[rtb_IMU_Enable] = localDW->Delay6_DSTATE[rtb_IMU_Enable + 1];
   }

   /* Update for Delay: '<S85>/Delay1' */
   localDW->Delay1_DSTATE_a[9] = rtb_Filt_Lateral_Acceleration_h;

   /* Update for DiscreteTransferFcn: '<S96>/LowPass Filter' */
   localDW->LowPassFilter_states_p[3] = localDW->LowPassFilter_states_p[2];
   localDW->LowPassFilter_states_p[2] = localDW->LowPassFilter_states_p[1];
   localDW->LowPassFilter_states_p[1] = localDW->LowPassFilter_states_p[0];
   localDW->LowPassFilter_states_p[0] = localDW->LowPassFilter_tmp_n;

   /* Update for DiscreteIntegrator: '<S85>/DiscreteTime Integrator' */
   localDW->DiscreteTimeIntegrator_DSTATE = Integrator_Ax_tmp + localDW->Integrator_Ax;

   /* Update for Delay: '<S85>/Delay6' */
   localDW->Delay6_DSTATE[9] = localDW->Integrator_Ax;

   /* Update for DiscreteTransferFcn: '<S91>/LowPass Filter' */
   localDW->LowPassFilter_states_px[3] = localDW->LowPassFilter_states_px[2];
   localDW->LowPassFilter_states_px[2] = localDW->LowPassFilter_states_px[1];
   localDW->LowPassFilter_states_px[1] = localDW->LowPassFilter_states_px[0];
   localDW->LowPassFilter_states_px[0] = localDW->LowPassFilter_tmp_m;

   /* Update for Delay: '<S2>/Delay12' */
   localDW->Delay12_DSTATE = rtb_Integrator;

   /* Update for UnitDelay: '<S2>/Unit Delay2' */
   localDW->UnitDelay2_DSTATE = rtb_Filt_Lateral_Acceleration_h;

   /* Update for DiscreteTransferFcn: '<S22>/LowPass Filter' */
   localDW->LowPassFilter_states_d[3] = localDW->LowPassFilter_states_d[2];
   localDW->LowPassFilter_states_d[2] = localDW->LowPassFilter_states_d[1];
   localDW->LowPassFilter_states_d[1] = localDW->LowPassFilter_states_d[0];
   localDW->LowPassFilter_states_d[0] = localDW->LowPassFilter_tmp_pq;

   /* Update for DiscreteTransferFcn: '<S17>/LowPass Filter' */
   localDW->LowPassFilter_states_j[3] = localDW->LowPassFilter_states_j[2];
   localDW->LowPassFilter_states_j[2] = localDW->LowPassFilter_states_j[1];
   localDW->LowPassFilter_states_j[1] = localDW->LowPassFilter_states_j[0];
   localDW->LowPassFilter_states_j[0] = localDW->LowPassFilter_tmp_h;

   /* Update for Delay: '<S6>/Delay8' */
   localDW->Delay8_DSTATE = (real_T)rtb_GNMM_Enable;

   /* Update for Enabled SubSystem: '<S6>/NoAvailableSourceHold' incorporates:
    *  EnablePort: '<S110>/Enable'
    */
   if (rtb_Transition)
   {
      /* Update for Delay: '<S110>/Delay8' */
      localDW->Delay8_DSTATE_i[0] = localDW->Delay8_DSTATE_i[1];
      localDW->Delay8_DSTATE_i[1] = localDW->Delay8_DSTATE_i[2];

      /* Switch: '<S6>/Switch5' incorporates:
       *  Constant: '<S102>/Constant'
       *  RelationalOperator: '<S102>/Compare'
       */
      if (rtb_GNMM_Enable >= 1)
      {
         /* Update for Delay: '<S110>/Delay8' incorporates:
          *  DataTypeConversion: '<S17>/Data Type Conversion'
          */
         localDW->Delay8_DSTATE_i[2] = (real32_T)rtb_Fused_n;
      }
      else
      {
         /* Update for Delay: '<S110>/Delay8' */
         localDW->Delay8_DSTATE_i[2] = localDW->Estimated_Grade_Percentage_p;
      }

      /* End of Switch: '<S6>/Switch5' */
   }

   /* End of Update for SubSystem: '<S6>/NoAvailableSourceHold' */

   /* Update for DiscreteFilter: '<S26>/DiscreteFilter' */
   localDW->DiscreteFilter_states[2] = localDW->DiscreteFilter_states[1];
   localDW->DiscreteFilter_states[1] = localDW->DiscreteFilter_states[0];
   localDW->DiscreteFilter_states[0] = localDW->DiscreteFilter_tmp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
