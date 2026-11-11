/*
 * File: Wheel_Counts_To_Linear_Speed.h
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

#ifndef RTW_HEADER_Wheel_Counts_To_Linear_Speed_h_
   #define RTW_HEADER_Wheel_Counts_To_Linear_Speed_h_
   #include <math.h>
   #ifndef Wheel_Counts_To_Linear_Speed_COMMON_INCLUDES_
      #define Wheel_Counts_To_Linear_Speed_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* Wheel_Counts_To_Linear_Speed_COMMON_INCLUDES_ */

   #include "Wheel_Counts_To_Linear_Speed_types.h"

/* Block signals and states (default storage) for model 'Wheel_Counts_To_Linear_Speed' */
typedef struct
{
   uint64_T ResettableDelay_DSTATE;     /* '<S45>/Resettable Delay' */
   uint64_T UnitDelay1_DSTATE;          /* '<S40>/Unit Delay1' */
   uint64_T UnitDelay1_DSTATE_o;        /* '<S7>/Unit Delay1' */
   uint64_T UnitDelay1_DSTATE_l;        /* '<S18>/Unit Delay1' */
   uint64_T UnitDelay1_DSTATE_e;        /* '<S29>/Unit Delay1' */
   uint64_T ResettableDelay_DSTATE_p;   /* '<S34>/Resettable Delay' */
   uint64_T ResettableDelay_DSTATE_j;   /* '<S23>/Resettable Delay' */
   uint64_T ResettableDelay_DSTATE_m;   /* '<S12>/Resettable Delay' */
   real32_T filter_num[3];              /* '<S47>/MATLAB Function' */
   real32_T filter_den[3];              /* '<S47>/MATLAB Function' */
   real32_T filter_num_f[3];            /* '<S36>/MATLAB Function' */
   real32_T filter_den_e[3];            /* '<S36>/MATLAB Function' */
   real32_T filter_num_n[3];            /* '<S25>/MATLAB Function' */
   real32_T filter_den_b[3];            /* '<S25>/MATLAB Function' */
   real32_T filter_num_h[3];            /* '<S14>/MATLAB Function' */
   real32_T filter_den_p[3];            /* '<S14>/MATLAB Function' */
   real32_T DiscreteFilter_states[2];   /* '<S46>/Discrete Filter' */
   real32_T DiscreteFilter_states_o[2]; /* '<S35>/Discrete Filter' */
   real32_T DiscreteFilter_states_i[2]; /* '<S24>/Discrete Filter' */
   real32_T DiscreteFilter_states_j[2]; /* '<S13>/Discrete Filter' */
   real32_T UnitDelay2_DSTATE;          /* '<S41>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_c;        /* '<S40>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_f;        /* '<S7>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_k;        /* '<S18>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_b;        /* '<S29>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_m;        /* '<S30>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_m3;       /* '<S19>/Unit Delay2' */
   real32_T UnitDelay2_DSTATE_i;        /* '<S8>/Unit Delay2' */
   real32_T DiscreteFilter_tmp;         /* '<S46>/Discrete Filter' */
   real32_T DiscreteFilter_tmp_c;       /* '<S35>/Discrete Filter' */
   real32_T DiscreteFilter_tmp_a;       /* '<S24>/Discrete Filter' */
   real32_T DiscreteFilter_tmp_n;       /* '<S13>/Discrete Filter' */
   uint32_T UnitDelay_DSTATE;           /* '<S40>/Unit Delay' */
   uint32_T UnitDelay_DSTATE_a;         /* '<S7>/Unit Delay' */
   uint32_T UnitDelay_DSTATE_f;         /* '<S18>/Unit Delay' */
   uint32_T UnitDelay_DSTATE_k;         /* '<S29>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_p;          /* '<S13>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_fz;         /* '<S24>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_b;          /* '<S35>/Unit Delay' */
   uint8_T UnitDelay_DSTATE_ku;         /* '<S46>/Unit Delay' */
   uint8_T ResettableDelay_DSTATE_n;    /* '<S4>/Resettable Delay' */
   uint8_T UnitDelay3_DSTATE;           /* '<S40>/Unit Delay3' */
   uint8_T UnitDelay4_DSTATE;           /* '<S40>/Unit Delay4' */
   uint8_T UnitDelay5_DSTATE;           /* '<S40>/Unit Delay5' */
   uint8_T ResettableDelay_DSTATE_i;    /* '<S1>/Resettable Delay' */
   uint8_T UnitDelay3_DSTATE_m;         /* '<S7>/Unit Delay3' */
   uint8_T UnitDelay4_DSTATE_p;         /* '<S7>/Unit Delay4' */
   uint8_T UnitDelay5_DSTATE_d;         /* '<S7>/Unit Delay5' */
   uint8_T ResettableDelay_DSTATE_mw;   /* '<S2>/Resettable Delay' */
   uint8_T UnitDelay3_DSTATE_mx;        /* '<S18>/Unit Delay3' */
   uint8_T UnitDelay4_DSTATE_k;         /* '<S18>/Unit Delay4' */
   uint8_T UnitDelay5_DSTATE_c;         /* '<S18>/Unit Delay5' */
   uint8_T ResettableDelay_DSTATE_g;    /* '<S3>/Resettable Delay' */
   uint8_T UnitDelay3_DSTATE_e;         /* '<S29>/Unit Delay3' */
   uint8_T UnitDelay4_DSTATE_d;         /* '<S29>/Unit Delay4' */
   uint8_T UnitDelay5_DSTATE_f;         /* '<S29>/Unit Delay5' */
   uint8_T icLoad;                      /* '<S4>/Resettable Delay' */
   uint8_T icLoad_a;                    /* '<S45>/Resettable Delay' */
   uint8_T DiscreteFilter_icLoad;       /* '<S46>/Discrete Filter' */
   uint8_T icLoad_j;                    /* '<S1>/Resettable Delay' */
   uint8_T icLoad_k;                    /* '<S2>/Resettable Delay' */
   uint8_T icLoad_g;                    /* '<S3>/Resettable Delay' */
   uint8_T icLoad_e;                    /* '<S34>/Resettable Delay' */
   uint8_T DiscreteFilter_icLoad_o;     /* '<S35>/Discrete Filter' */
   uint8_T icLoad_n;                    /* '<S23>/Resettable Delay' */
   uint8_T DiscreteFilter_icLoad_d;     /* '<S24>/Discrete Filter' */
   uint8_T icLoad_eq;                   /* '<S12>/Resettable Delay' */
   uint8_T DiscreteFilter_icLoad_a;     /* '<S13>/Discrete Filter' */
} DW_Wheel_Counts_To_Linear_Speed_f_T;

typedef struct
{
   DW_Wheel_Counts_To_Linear_Speed_f_T rtdw;
} MdlrefDW_Wheel_Counts_To_Linear_Speed_T;

extern void Wheel_Counts_To_Linear_Speed_MATLABFunction(const uint8_T *rtu_pres_whl_count, uint8_T rtu_prev_whl_count,
                                                        uint8_T *rty_wheel_ticks);
extern void Wheel_Counts_To_Linear_Speed_MATLABFunction1(real32_T rtu_whl_tck_bsd_lin_spd, uint8_T rtu_HasScndTckEncountered_u8,
                                                         real32_T rtu_inst_whl_tck_bsd_lin_spd,
                                                         real32_T *rty_combined_whl_tck_bsd_lin_spd);
extern void Wheel_Counts_To_Linear_Speed_MATLABFunction_i(
   uint8_T rtu_wheel_ticks, const real32_T *rtu_whl_radius_m, const real32_T *rtu_CPR, const real32_T *rtu_last_estimated_spd,
   const real32_T *rtu_last_differen_estimated_spd, const uint64_T *rtu_curr_time, real32_T rtu_delta_time,
   uint8_T rtu_IsFirstPulseEncountered_in, real32_T rtu_pred_lin_spd_in, uint64_T rtu_time_in, uint32_T rtu_counter_20cyc_in,
   uint8_T rtu_wheel_tck_count_in, uint8_T rtu_SecondPlsEncountered_in, uint8_T *rty_IsFirstPulseEncountered,
   real32_T *rty_pred_lin_spd, uint64_T *rty_time_out, uint32_T *rty_counter_20cyc, uint8_T *rty_wheel_tck_count,
   uint8_T *rty_SecondPlsEncountered_out);
extern void Wheel_Counts_To_Linear_Speed_MATLABFunction_l(uint8_T rtu_wheel_ticks, real32_T rtu_delta_time,
                                                          const real32_T *rtu_whl_radius_m, const real32_T *rtu_CPR,
                                                          real32_T rtu_pred_lin_spd_in, real32_T *rty_pred_lin_spd);
extern void Wheel_Counts_To_Linear_Speed_Initialization(uint8_T rtu_Enable, real32_T rty_filt_num[3], real32_T rty_filt_den[3]);
extern void Wheel_Counts_To_Linear_Speed_Init(DW_Wheel_Counts_To_Linear_Speed_f_T *localDW);
extern void Wheel_Counts_To_Linear_Speed(const uint8_T *rtu_VsVCAN_nu_WheelCount_FL, const uint8_T *rtu_VsVCAN_nu_WheelCount_FR,
                                         const uint8_T *rtu_VsVCAN_nu_WheelCount_RL, const uint8_T *rtu_VsVCAN_nu_WheelCount_RR,
                                         const real32_T *rtu_KsVSE_m_WheelRadius, const uint64_T *rtu_VsVCAN_us_SysTimer,
                                         const real32_T *rtu_VsVCAN_nu_CountsPerRevol,
                                         const real32_T *rtu_VsVSE_mps_LastEstimWhlSpd,
                                         const real32_T *rtu_VsVSE_mps2_LastDifferentiatedWhlSpd,
                                         real32_T *rty_whl_tck_bsd_lin_spd_fl, real32_T *rty_whl_tck_bsd_lin_spd_fr,
                                         real32_T *rty_whl_tck_bsd_lin_spd_rl, real32_T *rty_whl_tck_bsd_lin_spd_rr,
                                         boolean_T *rty_WhlTckIsZeroForLongerDuration,
                                         DW_Wheel_Counts_To_Linear_Speed_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Abs' : Eliminated since data is unsigned
 * Block '<S12>/Abs1' : Eliminated since data is unsigned
 * Block '<S21>/Abs' : Eliminated since data is unsigned
 * Block '<S23>/Abs1' : Eliminated since data is unsigned
 * Block '<S32>/Abs' : Eliminated since data is unsigned
 * Block '<S34>/Abs1' : Eliminated since data is unsigned
 * Block '<S43>/Abs' : Eliminated since data is unsigned
 * Block '<S45>/Abs1' : Eliminated since data is unsigned
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
 * '<Root>' : 'Wheel_Counts_To_Linear_Speed'
 * '<S1>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl'
 * '<S2>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr'
 * '<S3>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl'
 * '<S4>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr'
 * '<S5>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/MATLAB Function'
 * '<S6>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/MATLAB Function1'
 * '<S7>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/Subsystem'
 * '<S8>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/inst_tick_to_lin_spd'
 * '<S9>'   : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/Subsystem/MATLAB Function'
 * '<S10>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/Subsystem/if_vse_time_is_used'
 * '<S11>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/inst_tick_to_lin_spd/MATLAB Function'
 * '<S12>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/inst_tick_to_lin_spd/Subsystem'
 * '<S13>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/inst_tick_to_lin_spd/second_order_butterworth_filter'
 * '<S14>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization'
 * '<S15>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fl/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization/MATLAB
 * Function'
 * '<S16>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/MATLAB Function'
 * '<S17>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/MATLAB Function1'
 * '<S18>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/Subsystem'
 * '<S19>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/inst_tick_to_lin_spd'
 * '<S20>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/Subsystem/MATLAB Function'
 * '<S21>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/Subsystem/if_vse_time_is_used'
 * '<S22>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/inst_tick_to_lin_spd/MATLAB Function'
 * '<S23>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/inst_tick_to_lin_spd/Subsystem'
 * '<S24>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/inst_tick_to_lin_spd/second_order_butterworth_filter'
 * '<S25>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization'
 * '<S26>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_fr/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization/MATLAB
 * Function'
 * '<S27>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/MATLAB Function'
 * '<S28>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/MATLAB Function1'
 * '<S29>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/Subsystem'
 * '<S30>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/inst_tick_to_lin_spd'
 * '<S31>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/Subsystem/MATLAB Function'
 * '<S32>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/Subsystem/if_vse_time_is_used'
 * '<S33>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/inst_tick_to_lin_spd/MATLAB Function'
 * '<S34>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/inst_tick_to_lin_spd/Subsystem'
 * '<S35>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/inst_tick_to_lin_spd/second_order_butterworth_filter'
 * '<S36>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization'
 * '<S37>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rl/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization/MATLAB
 * Function'
 * '<S38>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/MATLAB Function'
 * '<S39>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/MATLAB Function1'
 * '<S40>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/Subsystem'
 * '<S41>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/inst_tick_to_lin_spd'
 * '<S42>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/Subsystem/MATLAB Function'
 * '<S43>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/Subsystem/if_vse_time_is_used'
 * '<S44>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/inst_tick_to_lin_spd/MATLAB Function'
 * '<S45>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/inst_tick_to_lin_spd/Subsystem'
 * '<S46>'  : 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/inst_tick_to_lin_spd/second_order_butterworth_filter'
 * '<S47>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization'
 * '<S48>'  :
 * 'Wheel_Counts_To_Linear_Speed/wheel_count_to_lin_spd_rr/inst_tick_to_lin_spd/second_order_butterworth_filter/Initialization/MATLAB
 * Function'
 */
#endif /* RTW_HEADER_Wheel_Counts_To_Linear_Speed_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
