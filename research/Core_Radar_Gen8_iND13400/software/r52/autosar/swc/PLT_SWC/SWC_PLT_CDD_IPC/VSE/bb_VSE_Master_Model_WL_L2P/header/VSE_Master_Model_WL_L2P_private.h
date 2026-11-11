/*
 * File: VSE_Master_Model_WL_L2P_private.h
 *
 * Code generated for Simulink model 'VSE_Master_Model_WL_L2P'.
 *
 * Model version                  : 1.1208
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:08:25 2026
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

#ifndef RTW_HEADER_VSE_Master_Model_WL_L2P_private_h_
   #define RTW_HEADER_VSE_Master_Model_WL_L2P_private_h_
   #include "VSE_Master_Model_WL_L2P.h"
   #include "rtwtypes.h"
   #ifndef UCHAR_MAX
      #include <limits.h>
   #endif

   #if (UCHAR_MAX != (0xFFU)) || (SCHAR_MAX != (0x7F))
   // #error Code was generated for compiler with different sized uchar/char. \
// Consider adjusting Test hardware word size settings on the \
// Hardware Implementation pane to match your compiler word sizes as \
// defined in limits.h of the compiler. Alternatively, you can \
// select the Test hardware is the same as production hardware option and \
// select the Enable portable word sizes option on the Code Generation > \
// Verification pane for ERT based targets, which will disable the \
// preprocessor word size checks.
   #endif

   #if (USHRT_MAX != (0xFFFFU)) || (SHRT_MAX != (0x7FFF))
   // #error Code was generated for compiler with different sized ushort/short. \
// Consider adjusting Test hardware word size settings on the \
// Hardware Implementation pane to match your compiler word sizes as \
// defined in limits.h of the compiler. Alternatively, you can \
// select the Test hardware is the same as production hardware option and \
// select the Enable portable word sizes option on the Code Generation > \
// Verification pane for ERT based targets, which will disable the \
// preprocessor word size checks.
   #endif

   #if (UINT_MAX != (0xFFFFFFFFU)) || (INT_MAX != (0x7FFFFFFF))
   // #error Code was generated for compiler with different sized uint/int. \
// Consider adjusting Test hardware word size settings on the \
// Hardware Implementation pane to match your compiler word sizes as \
// defined in limits.h of the compiler. Alternatively, you can \
// select the Test hardware is the same as production hardware option and \
// select the Enable portable word sizes option on the Code Generation > \
// Verification pane for ERT based targets, which will disable the \
// preprocessor word size checks.
   #endif

   #if (ULONG_MAX != (0xFFFFFFFFU)) || (LONG_MAX != (0x7FFFFFFF))
   // #error Code was generated for compiler with different sized ulong/long. \
// Consider adjusting Test hardware word size settings on the \
// Hardware Implementation pane to match your compiler word sizes as \
// defined in limits.h of the compiler. Alternatively, you can \
// select the Test hardware is the same as production hardware option and \
// select the Enable portable word sizes option on the Code Generation > \
// Verification pane for ERT based targets, which will disable the \
// preprocessor word size checks.
   #endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern void VSE_Master_Model_WL_L2P_Chart(boolean_T *rty_f_initialize_JerkEstimation, DW_Chart_VSE_Master_Model_WL_L2P_T *localDW);
extern void VSE_Master_Model_WL_L2P_DifferentiatorGenerator(boolean_T rtu_Enable, real_T rty_Differentiator_Num[8],
                                                            real_T rty_Differentiator_Den[8]);
extern void VSE_Master_Model_WL_L2P_FilterGenerator(boolean_T rtu_Enable, real_T rty_Filter_Num[5], real_T rty_Filter_Den[5]);
extern void VSE_Master_Model_WL_L2P_Initialization(boolean_T rtu_Enable, real32_T rty_diff_num[4], real32_T rty_diff_den[4]);
extern void VSE_Master_Model_WL_L2P_Initialization_Trigger(boolean_T *rty_f_initialize,
                                                           DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T *localDW);
extern void VSE_Master_Model_WL_L2P_IfActionSubsystem1(
   real32_T rtu_In1, real32_T rtu_In1_j, real32_T rtu_In1_f, real32_T rtu_In1_fr, real32_T rtu_In1_c, enum_road_type_T rtu_In1_a,
   boolean_T rtu_In1_k, boolean_T rtu_In1_b, boolean_T rtu_In1_fe, boolean_T rtu_In1_e, boolean_T rtu_In1_i, real32_T rtu_In1_jz,
   boolean_T rtu_In1_bp, boolean_T rtu_In1_kf, real32_T rtu_In1_ir, boolean_T rtu_In1_n, real32_T rtu_In1_na,
   enum_quality_factor_T rtu_In1_d, boolean_T rtu_In1_o, real32_T rtu_In1_km, enum_quality_factor_T rtu_In1_g,
   enum_quality_factor_T rtu_In1_jf, boolean_T rtu_In1_fy, boolean_T rtu_In1_ik, real32_T rtu_In1_m, real32_T rtu_In1_ef,
   real32_T *rty_Out1, real32_T *rty_Out1_j, real32_T *rty_Out1_f, enum_quality_factor_T *rty_Out1_fr,
   enum_quality_factor_T *rty_Out1_c, boolean_T *rty_Out1_a, boolean_T *rty_Out1_k, real32_T *rty_Out1_b, real32_T *rty_Out1_fe,
   real32_T *rty_Out1_e, real32_T *rty_Out1_i, real32_T *rty_Out1_jz, real32_T *rty_Out1_bp, enum_road_type_T *rty_Out1_kf,
   boolean_T *rty_Out1_ir, boolean_T *rty_Out1_n, boolean_T *rty_Out1_na, boolean_T *rty_Out1_d, boolean_T *rty_Out1_o,
   boolean_T *rty_Out1_km, boolean_T *rty_Out1_g, real32_T *rty_Out1_jf, boolean_T *rty_Out1_fy, real32_T *rty_Out1_ik,
   enum_quality_factor_T *rty_Out1_m, boolean_T *rty_Out1_ef);
extern void VSE_Master_Model_WL_L2P_MATLABFunction(boolean_T rtu_fault_flag, real32_T rtu_fault_maturation_time_seconds,
                                                   real32_T rtu_fault_dematuration_time_seconds, boolean_T *rty_final_fault,
                                                   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T *localDW);

#endif /* RTW_HEADER_VSE_Master_Model_WL_L2P_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
