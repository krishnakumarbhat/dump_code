/*
 * File: Signal_Arbitration_Common.h
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

#ifndef RTW_HEADER_Signal_Arbitration_Common_h_
   #define RTW_HEADER_Signal_Arbitration_Common_h_
   #ifndef Signal_Arbitration_Common_COMMON_INCLUDES_
      #define Signal_Arbitration_Common_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* Signal_Arbitration_Common_COMMON_INCLUDES_ */

   #include "Signal_Arbitration_Common_types.h"

/* Block signals and states (default storage) for model 'Signal_Arbitration_Common' */
typedef struct
{
   struct
   {
      uint_T is_c1_Signal_Arbitration_Common:2;        /* '<S1>/Initial_Arbitration_Chart' */
      uint_T is_active_c1_Signal_Arbitration_Common:1; /* '<S1>/Initial_Arbitration_Chart' */
   } bitsForTID0;

   uint8_T priority_1_counter_msec; /* '<S1>/Initial_Arbitration_Chart' */
   uint8_T priority_2_counter_msec; /* '<S1>/Initial_Arbitration_Chart' */
   uint8_T priority_3_counter_msec; /* '<S1>/Initial_Arbitration_Chart' */
} DW_Signal_Arbitration_Common_f_T;

typedef struct
{
   DW_Signal_Arbitration_Common_f_T rtdw;
} MdlrefDW_Signal_Arbitration_Common_T;

extern void Signal_Arbitration_Common_IfActionSubsystem1(const real32_T *rtu_In1, const enum_quality_factor_T *rtu_In1_d,
                                                         selected_signal_number_T rtu_In1_f, real32_T *rty_Out1,
                                                         enum_quality_factor_T *rty_Out1_d, selected_signal_number_T *rty_Out1_f);
extern void Signal_Arbitration_Common_Init(selected_signal_number_T *rty_selected_signal_number);
extern void Signal_Arbitration_Common(const real32_T *rtu_signal_priority_1, const real32_T *rtu_signal_priority_2,
                                      const real32_T *rtu_signal_priority_3, const enum_quality_factor_T *rtu_signal_priority_1_qf,
                                      const enum_quality_factor_T *rtu_signal_priority_2_qf,
                                      const enum_quality_factor_T *rtu_signal_priority_3_qf, real32_T *rty_selected_signal,
                                      enum_quality_factor_T *rty_selected_signal_qf,
                                      selected_signal_number_T *rty_selected_signal_number,
                                      DW_Signal_Arbitration_Common_f_T *localDW);

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
 * '<Root>' : 'Signal_Arbitration_Common'
 * '<S1>'   : 'Signal_Arbitration_Common/Signal_Arbitration'
 * '<S2>'   : 'Signal_Arbitration_Common/Signal_Arbitration/Final_Arbitration'
 * '<S3>'   : 'Signal_Arbitration_Common/Signal_Arbitration/Initial_Arbitration_Chart'
 * '<S4>'   : 'Signal_Arbitration_Common/Signal_Arbitration/Final_Arbitration/If Action Subsystem1'
 * '<S5>'   : 'Signal_Arbitration_Common/Signal_Arbitration/Final_Arbitration/If Action Subsystem2'
 * '<S6>'   : 'Signal_Arbitration_Common/Signal_Arbitration/Final_Arbitration/If Action Subsystem3'
 * '<S7>'   : 'Signal_Arbitration_Common/Signal_Arbitration/Final_Arbitration/If Action Subsystem4'
 */
#endif /* RTW_HEADER_Signal_Arbitration_Common_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
