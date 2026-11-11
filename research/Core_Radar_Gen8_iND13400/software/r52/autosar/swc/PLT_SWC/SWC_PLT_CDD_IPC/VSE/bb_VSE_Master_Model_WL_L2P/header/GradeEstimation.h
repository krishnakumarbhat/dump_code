/*
 * File: GradeEstimation.h
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

#ifndef RTW_HEADER_GradeEstimation_h_
   #define RTW_HEADER_GradeEstimation_h_
   #include <math.h>
   #ifndef GradeEstimation_COMMON_INCLUDES_
      #define GradeEstimation_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* GradeEstimation_COMMON_INCLUDES_ */

   #include "GradeEstimation_types.h"

/* Block signals and states (default storage) for system '<S2>/MovingAverage' */
typedef struct
{
   dsp_private_SlidingWindowAverageCG_GradeEstimation_T gobj_0; /* '<S2>/MovingAverage' */
   dsp_private_SlidingWindowAverageCG_GradeEstimation_T gobj_1; /* '<S2>/MovingAverage' */
   dsp_simulink_MovingAverage_GradeEstimation_T obj;            /* '<S2>/MovingAverage' */
   real32_T VsVSE_m_AvgDeltaAlt;                                /* '<S2>/MovingAverage' */
   struct
   {
      uint_T objisempty:1; /* '<S2>/MovingAverage' */
   } bitsForTID0;
} DW_MovingAverage_GradeEstimation_T;

/* Block signals and states (default storage) for system '<S9>/Debouncer' */
typedef struct
{
   uint32_T temporalCounter_i1; /* '<S9>/Debouncer' */
   uint32_T temporalCounter_i2; /* '<S9>/Debouncer' */
   struct
   {
      uint_T is_c1_SignalDebouncingLogic:2;        /* '<S9>/Debouncer' */
      uint_T is_Off:2;                             /* '<S9>/Debouncer' */
      uint_T is_Debounce:2;                        /* '<S9>/Debouncer' */
      uint_T is_active_c1_SignalDebouncingLogic:1; /* '<S9>/Debouncer' */
   } bitsForTID0;
} DW_Debouncer_GradeEstimation_T;

/* Block signals and states (default storage) for system '<S13>/Chart' */
typedef struct
{
   struct
   {
      uint_T is_c5_Fourth_Order_Cheby2_Filter:2;        /* '<S13>/Chart' */
      uint_T is_active_c5_Fourth_Order_Cheby2_Filter:1; /* '<S13>/Chart' */
   } bitsForTID0;
} DW_Chart_GradeEstimation_T;

/* Block signals and states (default storage) for model 'GradeEstimation' */
typedef struct
{
   DW_MovingAverage_GradeEstimation_T MovingAverage_p; /* '<S2>/MovingAverage' */
   DW_Chart_GradeEstimation_T sf_Chart_g;              /* '<S88>/Chart' */
   DW_Chart_GradeEstimation_T sf_Chart_e;              /* '<S87>/Chart' */
   DW_Chart_GradeEstimation_T sf_Chart_dl;             /* '<S71>/Chart' */
   DW_Chart_GradeEstimation_T sf_Chart_d;              /* '<S70>/Chart' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer_c;      /* '<S65>/Debouncer' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer_h;      /* '<S60>/Debouncer' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer_d;      /* '<S58>/Debouncer' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer_km;     /* '<S52>/Debouncer' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer_e;      /* '<S51>/Debouncer' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer_k;      /* '<S50>/Debouncer' */
   DW_Chart_GradeEstimation_T sf_Chart_o;              /* '<S14>/Chart' */
   DW_Chart_GradeEstimation_T sf_Chart;                /* '<S13>/Chart' */
   DW_Debouncer_GradeEstimation_T sf_Debouncer;        /* '<S9>/Debouncer' */
   DW_MovingAverage_GradeEstimation_T MovingAverage;   /* '<S2>/MovingAverage' */
   real_T filter_discrete_num[5];                      /* '<S95>/FindFilterCoeff' */
   real_T filter_discrete_denom[5];                    /* '<S95>/FindFilterCoeff' */
   real_T filter_discrete_num_a[5];                    /* '<S90>/FindFilterCoeff' */
   real_T filter_discrete_denom_e[5];                  /* '<S90>/FindFilterCoeff' */
   real_T filter_discrete_num_l[5];                    /* '<S81>/FindFilterCoeff' */
   real_T filter_discrete_denom_j[5];                  /* '<S81>/FindFilterCoeff' */
   real_T filter_discrete_num_d[5];                    /* '<S76>/FindFilterCoeff' */
   real_T filter_discrete_denom_e3[5];                 /* '<S76>/FindFilterCoeff' */
   real_T filter_discrete_num_m[5];                    /* '<S21>/FindFilterCoeff' */
   real_T filter_discrete_denom_jh[5];                 /* '<S21>/FindFilterCoeff' */
   real_T filter_discrete_num_k[5];                    /* '<S16>/FindFilterCoeff' */
   real_T filter_discrete_denom_n[5];                  /* '<S16>/FindFilterCoeff' */
   real_T LowPassFilter_states[4];                     /* '<S77>/LowPass Filter' */
   real_T LowPassFilter_states_h[4];                   /* '<S82>/LowPass Filter' */
   real_T LowPassFilter_states_p[4];                   /* '<S96>/LowPass Filter' */
   real_T LowPassFilter_states_px[4];                  /* '<S91>/LowPass Filter' */
   real_T LowPassFilter_states_d[4];                   /* '<S22>/LowPass Filter' */
   real_T LowPassFilter_states_j[4];                   /* '<S17>/LowPass Filter' */
   real_T Delay8_DSTATE;                               /* '<S6>/Delay8' */
   real_T LowPassFilter_tmp;                           /* '<S77>/LowPass Filter' */
   real_T LowPassFilter_tmp_p;                         /* '<S82>/LowPass Filter' */
   real_T LowPassFilter_tmp_n;                         /* '<S96>/LowPass Filter' */
   real_T LowPassFilter_tmp_m;                         /* '<S91>/LowPass Filter' */
   real_T LowPassFilter_tmp_pq;                        /* '<S22>/LowPass Filter' */
   real_T LowPassFilter_tmp_h;                         /* '<S17>/LowPass Filter' */
   uint64_T first_time_stamp_temp;                     /* '<S69>/MATLABFunction' */
   real32_T diff_num[4];                               /* '<S30>/MATLAB Function' */
   real32_T diff_denom[4];                             /* '<S30>/MATLAB Function' */
   real32_T Delay1_DSTATE_a[10];                       /* '<S85>/Delay1' */
   real32_T Delay6_DSTATE[10];                         /* '<S85>/Delay6' */
   real32_T DiscreteFilter_states[3];                  /* '<S26>/DiscreteFilter' */
   real32_T Delay8_DSTATE_i[3];                        /* '<S110>/Delay8' */
   real32_T Integrator_Ax;                             /* '<S85>/DiscreteTime Integrator' */
   real32_T Estimated_Grade_Percentage;                /* '<S110>/Gain' */
   real32_T Estimated_Grade_Percentage_p;              /* '<S101>/Gain' */
   real32_T Delay2_DSTATE;                             /* '<S45>/Delay2' */
   real32_T Delay3_DSTATE;                             /* '<S45>/Delay3' */
   real32_T Delay10_DSTATE;                            /* '<S2>/Delay10' */
   real32_T Delay1_DSTATE;                             /* '<S2>/Delay1' */
   real32_T DiscreteTimeIntegrator_DSTATE;             /* '<S85>/DiscreteTime Integrator' */
   real32_T Delay12_DSTATE;                            /* '<S2>/Delay12' */
   real32_T UnitDelay2_DSTATE;                         /* '<S2>/Unit Delay2' */
   real32_T UnitDelay3_DSTATE;                         /* '<S8>/Unit Delay3' */
   real32_T DelayInput2_DSTATE;                        /* '<S111>/Delay Input2' */
   real32_T DiscreteFilter_tmp;                        /* '<S26>/DiscreteFilter' */
   uint32_T temporalCounter_i1;                        /* '<S6>/IMUDebouncer' */
   uint32_T temporalCounter_i1_d;                      /* '<S6>/GNMMDebouncer' */
   struct
   {
      uint_T is_c21_GradeEstimation:3;              /* '<S6>/IMUDebouncer' */
      uint_T is_c6_GradeEstimation:3;               /* '<S6>/GNMMDebouncer' */
      uint_T is_Check_Off:2;                        /* '<S6>/IMUDebouncer' */
      uint_T is_Debounce_Fault:2;                   /* '<S6>/IMUDebouncer' */
      uint_T is_Check_Off_e:2;                      /* '<S6>/GNMMDebouncer' */
      uint_T is_Debounce_Fault_g:2;                 /* '<S6>/GNMMDebouncer' */
      uint_T is_c5_Initialization_Trigger:2;        /* '<S26>/Initialization_Trigger' */
      uint_T is_c8_GradeEstimation:2;               /* '<S25>/AccuracyLevelDebouncer' */
      uint_T is_active_c21_GradeEstimation:1;       /* '<S6>/IMUDebouncer' */
      uint_T is_active_c6_GradeEstimation:1;        /* '<S6>/GNMMDebouncer' */
      uint_T is_active_c5_Initialization_Trigger:1; /* '<S26>/Initialization_Trigger' */
      uint_T is_active_c8_GradeEstimation:1;        /* '<S25>/AccuracyLevelDebouncer' */
      uint_T Debounced_IMU:1;                       /* '<S6>/IMUDebouncer' */
      uint_T Fault:1;                               /* '<S6>/IMUDebouncer' */
      uint_T Debounced_GNMM:1;                      /* '<S6>/GNMMDebouncer' */
      uint_T Fault_k:1;                             /* '<S6>/GNMMDebouncer' */
      uint_T f_initialize:1;                        /* '<S26>/Initialization_Trigger' */
      uint_T first_time_stamp_temp_not_empty:1;     /* '<S69>/MATLABFunction' */
   } bitsForTID0;

   uint16_T temporalCounter_i2;                    /* '<S6>/IMUDebouncer' */
   uint16_T temporalCounter_i2_c;                  /* '<S6>/GNMMDebouncer' */
   uint8_T temporalCounter_i1_i;                   /* '<S25>/AccuracyLevelDebouncer' */
   boolean_T f_initialize_LateralJerkEstimation;   /* '<S88>/Chart' */
   boolean_T f_initialize_LateralJerkEstimation_b; /* '<S87>/Chart' */
   boolean_T f_initialize_LateralJerkEstimation_e; /* '<S71>/Chart' */
   boolean_T f_initialize_LateralJerkEstimation_o; /* '<S70>/Chart' */
   boolean_T Output;                               /* '<S65>/Debouncer' */
   boolean_T Fault_l;                              /* '<S65>/Debouncer' */
   boolean_T Output_g;                             /* '<S60>/Debouncer' */
   boolean_T Fault_b;                              /* '<S60>/Debouncer' */
   boolean_T Output_h;                             /* '<S58>/Debouncer' */
   boolean_T Fault_h;                              /* '<S58>/Debouncer' */
   boolean_T Output_p;                             /* '<S52>/Debouncer' */
   boolean_T Fault_o;                              /* '<S52>/Debouncer' */
   boolean_T Output_k;                             /* '<S51>/Debouncer' */
   boolean_T Fault_i;                              /* '<S51>/Debouncer' */
   boolean_T Output_a;                             /* '<S50>/Debouncer' */
   boolean_T Fault_p;                              /* '<S50>/Debouncer' */
   boolean_T f_initialize_LateralJerkEstimation_d; /* '<S14>/Chart' */
   boolean_T f_initialize_LateralJerkEstimation_p; /* '<S13>/Chart' */
   boolean_T Output_e;                             /* '<S9>/Debouncer' */
   boolean_T Fault_ly;                             /* '<S9>/Debouncer' */
} DW_GradeEstimation_f_T;

typedef struct
{
   DW_GradeEstimation_f_T rtdw;
} MdlrefDW_GradeEstimation_T;

extern void GradeEstimation_MovingAverage_Init(DW_MovingAverage_GradeEstimation_T *localDW);
extern void GradeEstimation_MovingAverage_Start(DW_MovingAverage_GradeEstimation_T *localDW);
extern void GradeEstimation_MovingAverage(real32_T rtu_0, DW_MovingAverage_GradeEstimation_T *localDW);
extern void GradeEstimation_Debouncer_Init(boolean_T *rty_Fault);
extern void GradeEstimation_Debouncer(boolean_T rtu_sw, boolean_T *rty_Output, boolean_T *rty_Fault,
                                      DW_Debouncer_GradeEstimation_T *localDW, real32_T rtp_Debounce_Time,
                                      boolean_T rtp_Demat_Duration_Check, real32_T rtp_Dematuration_Time,
                                      boolean_T rtp_Fault_Check, boolean_T rtp_Mat_Duration_Check, real32_T rtp_Maturation_Time,
                                      real32_T rtp_Recovery_Time);
extern void GradeEstimation_Chart(boolean_T *rty_f_initialize_LateralJerkEstimation, DW_Chart_GradeEstimation_T *localDW);
extern void GradeEstimation_Coe1FilterGenerator(boolean_T rtu_Enable, real_T rty_Filter_Num[5], real_T rty_Filter_Den[5]);
extern void GradeEstimation_Init(DW_GradeEstimation_f_T *localDW);
extern void GradeEstimation_Start(DW_GradeEstimation_f_T *localDW);
extern void GradeEstimation(const real32_T *rtu_VsVSE_mps_VehicleSpeed, const real32_T *rtu_VsVSE_mps2_VehicleRawLongAccel,
                            const real32_T *rtu_VsGPS_m_GPSAltitude, const uint64_T *rtu_VsSYS_ms_SystemTime,
                            const boolean_T *rtu_VsVSE_b_UseGPSInput, const real32_T *rtu_VsVSE_rad_VCSSideslip,
                            const boolean_T *rtu_VsGPS_b_GPSValidity, const enum_quality_factor_T *rtu_VeVCAN_IMUValidity,
                            const real32_T *rtu_VsVSE_sec_SystemExecutionTime, real32_T *rty_VsVSE_pct_EstimatedGrade,
                            enum_quality_factor_T *rty_VsVSE_EstimatedGradeQF,
                            enum_accuracy_level_T *rty_VsVSE_EstimatedGradeAccuracy, DW_GradeEstimation_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S111>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Propagation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GradeEstimation'
 * '<S1>'   : 'GradeEstimation/GradeEstimation'
 * '<S2>'   : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation'
 * '<S3>'   : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation'
 * '<S4>'   : 'GradeEstimation/GradeEstimation/GradeEstimationPre'
 * '<S5>'   : 'GradeEstimation/GradeEstimation/IMUGradeEstimation'
 * '<S6>'   : 'GradeEstimation/GradeEstimation/SwitchingLogic'
 * '<S7>'   : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/AltitudeJumpCheck'
 * '<S8>'   : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst'
 * '<S9>'   : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/AltitudeJumpCheck/AltitudeJumpDebouncerCheck'
 * '<S10>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/AltitudeJumpCheck/GPSAltitudeJumpCheck'
 * '<S11>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/AltitudeJumpCheck/AltitudeJumpDebouncerCheck/Debouncer'
 * '<S12>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/GradeEstimation'
 * '<S13>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFGNMMOut'
 * '<S14>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFSubsVxGNMM'
 * '<S15>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFGNMMOut/Chart'
 * '<S16>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFGNMMOut/Coe1FilterGenerator'
 * '<S17>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFGNMMOut/LongitudinalDynamicFilter'
 * '<S18>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFGNMMOut/Coe1FilterGenerator/FindFilterCoeff'
 * '<S19>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFGNMMOut/LongitudinalDynamicFilter/Compare To
 * Constant'
 * '<S20>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFSubsVxGNMM/Chart'
 * '<S21>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFSubsVxGNMM/Coe1FilterGenerator'
 * '<S22>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFSubsVxGNMM/LongitudinalDynamicFilter'
 * '<S23>'  :
 * 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFSubsVxGNMM/Coe1FilterGenerator/FindFilterCoeff'
 * '<S24>'  : 'GradeEstimation/GradeEstimation/GNMMGradeEstimation/GPSBasedGradeEst/LPFSubsVxGNMM/LongitudinalDynamicFilter/Compare
 * To Constant'
 * '<S25>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/AccuracyLevelCheck'
 * '<S26>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade'
 * '<S27>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/AccuracyLevelCheck/AccuracyLevelDebouncer'
 * '<S28>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/AccuracyLevelCheck/AccuracyLevelDeternimation'
 * '<S29>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor'
 * '<S30>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/Initialization'
 * '<S31>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/Initialization_Trigger'
 * '<S32>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/SignalRangeCheck'
 * '<S33>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/SignalRateCheck'
 * '<S34>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/Compare To
 * Constant1'
 * '<S35>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/Compare To
 * Constant2'
 * '<S36>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/Compare To
 * Constant3'
 * '<S37>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S38>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/If
 * Action Subsystem2'
 * '<S39>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S40>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/DecideQualityFactor/If
 * Action Subsystem4'
 * '<S41>'  : 'GradeEstimation/GradeEstimation/GradeEstimationEvaluation/PlausibilityCheckLibraryBlockGrade/Initialization/MATLAB
 * Function'
 * '<S42>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck'
 * '<S43>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing'
 * '<S44>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed Check'
 * '<S45>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck'
 * '<S46>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed Check/Subsystem'
 * '<S47>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem1'
 * '<S48>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/Compare To Constant2'
 * '<S49>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/Compare To Constant4'
 * '<S50>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/StationaryCheck'
 * '<S51>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/StationaryCheck1'
 * '<S52>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/StationaryHold'
 * '<S53>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/StationaryCheck/Debouncer'
 * '<S54>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/StationaryCheck1/Debouncer'
 * '<S55>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem/StationaryHold/Debouncer'
 * '<S56>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem1/Compare To Constant'
 * '<S57>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem1/Compare To Constant1'
 * '<S58>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem1/LowSpeed_Check'
 * '<S59>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/Stationary and Low Speed
 * Check/Subsystem1/LowSpeed_Check/Debouncer'
 * '<S60>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/AxDebouncerCheck'
 * '<S61>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/Compare To Constant'
 * '<S62>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/Compare To Constant1'
 * '<S63>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/Compare To Constant2'
 * '<S64>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/Compare To Constant3'
 * '<S65>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/SideSlipDebouncerCheck'
 * '<S66>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/AxDebouncerCheck/Debouncer'
 * '<S67>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationPre/LowSpeedStationaryCheck/TransitionCheck/SideSlipDebouncerCheck/Debouncer'
 * '<S68>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/2ndOrderButterworthFilter'
 * '<S69>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/ElapsedTime'
 * '<S70>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFAx'
 * '<S71>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFVx'
 * '<S72>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/2ndOrderButterworthFilter/FilterCoefficientGenerator'
 * '<S73>'  :
 * 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/2ndOrderButterworthFilter/FilterCoefficientGenerator/FindFilterCoeff'
 * '<S74>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/ElapsedTime/MATLABFunction'
 * '<S75>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFAx/Chart'
 * '<S76>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFAx/Coe1FilterGenerator'
 * '<S77>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFAx/LongitudinalDynamicFilter'
 * '<S78>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFAx/Coe1FilterGenerator/FindFilterCoeff'
 * '<S79>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFAx/LongitudinalDynamicFilter/Compare To
 * Constant'
 * '<S80>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFVx/Chart'
 * '<S81>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFVx/Coe1FilterGenerator'
 * '<S82>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFVx/LongitudinalDynamicFilter'
 * '<S83>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFVx/Coe1FilterGenerator/FindFilterCoeff'
 * '<S84>'  : 'GradeEstimation/GradeEstimation/GradeEstimationPre/SignalPreProcessing/LPFVx/LongitudinalDynamicFilter/Compare To
 * Constant'
 * '<S85>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre'
 * '<S86>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimation_SourceSelection'
 * '<S87>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsAx'
 * '<S88>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsVx'
 * '<S89>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsAx/Chart'
 * '<S90>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsAx/Coe1FilterGenerator'
 * '<S91>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsAx/LongitudinalDynamicFilter'
 * '<S92>'  :
 * 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsAx/Coe1FilterGenerator/FindFilterCoeff'
 * '<S93>'  :
 * 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsAx/LongitudinalDynamicFilter/Compare To
 * Constant'
 * '<S94>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsVx/Chart'
 * '<S95>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsVx/Coe1FilterGenerator'
 * '<S96>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsVx/LongitudinalDynamicFilter'
 * '<S97>'  :
 * 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsVx/Coe1FilterGenerator/FindFilterCoeff'
 * '<S98>'  :
 * 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimationPre/LPFSubsVx/LongitudinalDynamicFilter/Compare To
 * Constant'
 * '<S99>'  : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimation_SourceSelection/IMUBasedGradeEstimatonAx'
 * '<S100>' : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimation_SourceSelection/IMUBasedSwitchLogic'
 * '<S101>' : 'GradeEstimation/GradeEstimation/IMUGradeEstimation/IMUBasedGradeEstimation_SourceSelection/StationaryHold'
 * '<S102>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/Compare To Constant'
 * '<S103>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/Compare To Constant2'
 * '<S104>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/Compare To Constant3'
 * '<S105>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/DetermineGPSEnable'
 * '<S106>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/DetermineIMUEnable'
 * '<S107>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/GNMMDebouncer'
 * '<S108>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/GradeEstimationSelectedSource'
 * '<S109>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/IMUDebouncer'
 * '<S110>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/NoAvailableSourceHold'
 * '<S111>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/Rate Limiter Dynamic'
 * '<S112>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/SwitchingDetected'
 * '<S113>' : 'GradeEstimation/GradeEstimation/SwitchingLogic/Rate Limiter Dynamic/Saturation Dynamic'
 */
#endif /* RTW_HEADER_GradeEstimation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
