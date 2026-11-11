/*
 * File: Speed_Arbitration_and_IMU_Fusion_private.h
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

#ifndef RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_private_h_
   #define RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_private_h_
   #include "multiword_types.h"
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

/* Constant parameters (default storage) */
typedef struct
{
   /* Computed Parameter: Constant_Value_j
    * Referenced by: '<S18>/Constant'
    */
   real32_T Constant_Value_j[4];
} ConstP_Speed_Arbitration_and_IMU_Fusion_T;

/* Constant parameters (default storage) */
extern const ConstP_Speed_Arbitration_and_IMU_Fusion_T Speed_Arbitration_and_IMU_Fusion_ConstP;
extern const ConstB_Speed_Arbitration_and_IMU_Fusion_h_T Speed_Arbitration_and_IMU_Fusion_ConstB;

#endif /* RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
