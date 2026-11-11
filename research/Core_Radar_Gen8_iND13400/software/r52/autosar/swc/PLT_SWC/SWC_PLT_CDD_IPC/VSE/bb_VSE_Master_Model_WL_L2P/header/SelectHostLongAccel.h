/*
 * File: SelectHostLongAccel.h
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

#ifndef RTW_HEADER_SelectHostLongAccel_h_
   #define RTW_HEADER_SelectHostLongAccel_h_
   #ifndef SelectHostLongAccel_COMMON_INCLUDES_
      #define SelectHostLongAccel_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* SelectHostLongAccel_COMMON_INCLUDES_ */

   #include "SelectHostLongAccel_types.h"

/* Block signals and states (default storage) for model 'SelectHostLongAccel' */
typedef struct
{
   real32_T diff_num[4];              /* '<S13>/FindDifferentiatorCoeff' */
   real32_T diff_denom[4];            /* '<S13>/FindDifferentiatorCoeff' */
   real32_T Differentiator_states[3]; /* '<S10>/Differentiator' */
   real32_T UnitDelay3_DSTATE;        /* '<S1>/Unit Delay3' */
   real32_T UnitDelay2_DSTATE;        /* '<S1>/Unit Delay2' */
   real32_T UnitDelay1_DSTATE;        /* '<S1>/Unit Delay1' */
   real32_T UnitDelay_DSTATE;         /* '<S1>/Unit Delay' */
   real32_T UnitDelay5_DSTATE;        /* '<S1>/Unit Delay5' */
   real32_T UnitDelay4_DSTATE;        /* '<S1>/Unit Delay4' */
   real32_T UnitDelay_DSTATE_d;       /* '<S9>/Unit Delay' */
   real32_T UnitDelay_DSTATE_m;       /* '<S7>/Unit Delay' */
   real32_T UnitDelay_DSTATE_j;       /* '<S5>/Unit Delay' */
   real32_T Differentiator_tmp;       /* '<S10>/Differentiator' */
   struct
   {
      uint_T is_c2_SelectHostLongAccel:2;        /* '<S10>/Chart' */
      uint_T is_active_c2_SelectHostLongAccel:1; /* '<S10>/Chart' */
      uint_T f_initialize_DtrmnVehStationary:1;  /* '<S10>/Chart' */
   } bitsForTID0;
} DW_SelectHostLongAccel_f_T;

typedef struct
{
   DW_SelectHostLongAccel_f_T rtdw;
} MdlrefDW_SelectHostLongAccel_T;

extern void SelectHostLongAccel(const boolean_T *rtu_VehicleSpeedVSOSig_SNA, const real32_T *rtu_ego_longitudinal_accel,
                                const boolean_T *rtu_LongAcceleration_BSM_SNA, const real32_T *rtu_ego_vehicle_speed_signed,
                                const uint8_T *rtu_filt_veh_speed_over_ground_qf, const uint8_T *rtu_raw_long_accel_qf_primary_in,
                                real32_T *rty_Host_Long_Accel_mpss, real32_T *rty_Road_Grade_Accel,
                                real32_T *rty_IMULongAccelFilt_mpss, real32_T *rty_HostLongAccelFilt_mpss,
                                uint8_T *rty_Road_Grade_Accel_QF, DW_SelectHostLongAccel_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S1>/Long_Accel_Selector_Switch' : Eliminated due to constant selection input
 * Block '<Root>/k_Select_Host_Long_Accel' : Unused code path elimination
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
 * '<Root>' : 'SelectHostLongAccel'
 * '<S1>'   : 'SelectHostLongAccel/Select_Host_Long_Accel'
 * '<S2>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/FilterGain'
 * '<S3>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/Filter_Gain'
 * '<S4>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/Filter_Gain1'
 * '<S5>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/HostAccelGrade_Filter'
 * '<S6>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/Host_Long_Accel_Filter_Init'
 * '<S7>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/IMULonAcc_Filter'
 * '<S8>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/Long_Accel_Init'
 * '<S9>'   : 'SelectHostLongAccel/Select_Host_Long_Accel/Road_Grade_Accel_Filter'
 * '<S10>'  : 'SelectHostLongAccel/Select_Host_Long_Accel/Subsystem'
 * '<S11>'  : 'SelectHostLongAccel/Select_Host_Long_Accel/calc_Road_Grade_Accel_QF'
 * '<S12>'  : 'SelectHostLongAccel/Select_Host_Long_Accel/Subsystem/Chart'
 * '<S13>'  : 'SelectHostLongAccel/Select_Host_Long_Accel/Subsystem/Differentiator Generator'
 * '<S14>'  : 'SelectHostLongAccel/Select_Host_Long_Accel/Subsystem/Differentiator Generator/FindDifferentiatorCoeff'
 */
#endif /* RTW_HEADER_SelectHostLongAccel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
