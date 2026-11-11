/*
 * File: SelectHostLongAccel_data.c
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

#include "SelectHostLongAccel.h"
#include "SelectHostLongAccel_private.h"

/* Constant parameters (default storage) */
const ConstP_SelectHostLongAccel_T SelectHostLongAccel_ConstP = {
   /* Expression: k_HostAccelGrade_Filt_Time_ms_z
    * Referenced by: '<S1>/k_HostAccelGrade_Filt_Time_ms'
    */
   {550.0F, 550.0F, 550.0F, 550.0F, 200.0F, 200.0F, 200.0F},

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/k_HostAccelGrade_Filt_Time_ms'
    *   '<S1>/k_IMULonAccPri_Filt_Time_ms'
    *   '<S1>/k_Road_Grade_Accel_Filt_Time'
    */
   {-10.0F, 0.0F, 2.0F, 5.0F, 10.0F, 60.0F, 250.0F},

   /* Expression: k_IMULonAccPri_Filt_Time_ms_z
    * Referenced by: '<S1>/k_IMULonAccPri_Filt_Time_ms'
    */
   {848.0F, 848.0F, 848.0F, 848.0F, 400.0F, 400.0F, 400.0F},

   /* Expression: k_Road_Grade_Accel_Filt_Time_z
    * Referenced by: '<S1>/k_Road_Grade_Accel_Filt_Time'
    */
   {2000.0F, 2000.0F, 2000.0F, 2000.0F, 1000.0F, 1000.0F, 1000.0F}};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
