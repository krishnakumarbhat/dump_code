/*
 * File: Speed_Arbitration_and_IMU_Fusion_data.c
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
#include "Speed_Arbitration_and_IMU_Fusion_private.h"

/* Constant parameters (default storage) */
const ConstP_Speed_Arbitration_and_IMU_Fusion_T Speed_Arbitration_and_IMU_Fusion_ConstP = {
   /* Computed Parameter: Constant_Value_j
    * Referenced by: '<S18>/Constant'
    */
   {1.0F, 0.0F, 0.0F, 1.0F}};

/* Invariant block signals (default storage) */
const ConstB_Speed_Arbitration_and_IMU_Fusion_h_T Speed_Arbitration_and_IMU_Fusion_ConstB = {
   HIGH, /* '<S25>/In1' */

   /* Start of '<S23>/calc_accuracy_level_under_low_confidence' */
   {
      LOW /* '<S26>/In1' */
   },

   /* End of '<S23>/calc_accuracy_level_under_low_confidence' */

   /* Start of '<S23>/calc_accuracy_level_under_medium_confidence' */
   {
      MEDIUM /* '<S27>/In1' */
   }
   /* End of '<S23>/calc_accuracy_level_under_medium_confidence' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
