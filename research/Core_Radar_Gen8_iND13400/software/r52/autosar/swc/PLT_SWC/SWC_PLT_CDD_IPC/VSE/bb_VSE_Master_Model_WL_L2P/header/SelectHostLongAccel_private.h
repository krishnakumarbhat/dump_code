/*
 * File: SelectHostLongAccel_private.h
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

#ifndef RTW_HEADER_SelectHostLongAccel_private_h_
   #define RTW_HEADER_SelectHostLongAccel_private_h_
   #include "rtwtypes.h"

/* Constant parameters (default storage) */
typedef struct
{
   /* Expression: k_HostAccelGrade_Filt_Time_ms_z
    * Referenced by: '<S1>/k_HostAccelGrade_Filt_Time_ms'
    */
   real32_T k_HostAccelGrade_Filt_Time_ms_tableData[7];

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/k_HostAccelGrade_Filt_Time_ms'
    *   '<S1>/k_IMULonAccPri_Filt_Time_ms'
    *   '<S1>/k_Road_Grade_Accel_Filt_Time'
    */
   real32_T pooled3[7];

   /* Expression: k_IMULonAccPri_Filt_Time_ms_z
    * Referenced by: '<S1>/k_IMULonAccPri_Filt_Time_ms'
    */
   real32_T k_IMULonAccPri_Filt_Time_ms_tableData[7];

   /* Expression: k_Road_Grade_Accel_Filt_Time_z
    * Referenced by: '<S1>/k_Road_Grade_Accel_Filt_Time'
    */
   real32_T k_Road_Grade_Accel_Filt_Time_tableData[7];
} ConstP_SelectHostLongAccel_T;

/* Constant parameters (default storage) */
extern const ConstP_SelectHostLongAccel_T SelectHostLongAccel_ConstP;

#endif /* RTW_HEADER_SelectHostLongAccel_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
