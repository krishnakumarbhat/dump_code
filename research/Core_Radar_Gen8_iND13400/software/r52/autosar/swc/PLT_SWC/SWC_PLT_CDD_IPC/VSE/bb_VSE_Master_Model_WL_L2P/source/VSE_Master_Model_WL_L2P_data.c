/*
 * File: VSE_Master_Model_WL_L2P_data.c
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

#include "VSE_Master_Model_WL_L2P.h"
#include "VSE_Master_Model_WL_L2P_private.h"

/* Invariant block signals (default storage) */
const ConstB_VSE_Master_Model_WL_L2P_T VSE_Master_Model_WL_L2P_ConstB = {
   UNDEFINED /* '<S1>/Data Type Conversion4' */
};

/* Constant parameters (default storage) */
const ConstP_VSE_Master_Model_WL_L2P_T VSE_Master_Model_WL_L2P_ConstP = {
   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant13'
    *   '<S1>/Constant15'
    *   '<S1>/Constant2'
    *   '<S1>/Constant26'
    *   '<S1>/Constant28'
    *   '<S1>/Constant32'
    *   '<S1>/Constant35'
    *   '<S1>/Constant5'
    *   '<S1>/Unit Delay1'
    *   '<S4>/Constant'
    *   '<S4>/Constant1'
    *   '<S4>/Constant10'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S15>/Constant'
    *   '<S15>/Constant1'
    *   '<S16>/Constant'
    *   '<S16>/Constant1'
    *   '<S17>/Constant1'
    *   '<S18>/Constant1'
    *   '<S19>/Constant1'
    *   '<S20>/Constant1'
    *   '<S21>/Constant1'
    *   '<S22>/Constant1'
    *   '<S23>/Constant1'
    *   '<S24>/Constant1'
    *   '<S25>/Constant1'
    *   '<S36>/Unit Delay'
    *   '<S36>/Unit Delay1'
    *   '<S40>/Delay'
    *   '<S41>/Delay'
    *   '<S42>/Delay'
    *   '<S43>/Delay'
    *   '<S44>/Delay'
    *   '<S45>/Delay'
    *   '<S46>/Delay'
    *   '<S47>/Delay'
    *   '<S48>/Delay'
    *   '<S49>/Delay'
    *   '<S50>/Delay'
    *   '<S51>/Delay'
    *   '<S52>/Delay'
    *   '<S53>/Delay'
    *   '<S56>/k_rws_angle_not_activated_rad'
    *   '<S57>/k_rws_angle_speed_not_activated_rps'
    *   '<S58>/k_rws_angle_not_activated_rad'
    *   '<S63>/k_rws_angle_speed_not_activated_rps'
    *   '<S106>/diff_num'
    *   '<S106>/diff_den'
    *   '<S118>/diff_num'
    *   '<S118>/diff_den'
    *   '<S130>/diff_num'
    *   '<S130>/diff_den'
    *   '<S142>/diff_num'
    *   '<S142>/diff_den'
    *   '<S154>/diff_num'
    *   '<S154>/diff_den'
    *   '<S166>/diff_num'
    *   '<S166>/diff_den'
    *   '<S214>/diff_num'
    *   '<S214>/diff_den'
    *   '<S216>/Constant'
    *   '<S226>/diff_num'
    *   '<S226>/diff_den'
    *   '<S228>/Constant'
    *   '<S238>/diff_num'
    *   '<S238>/diff_den'
    *   '<S240>/Constant'
    *   '<S250>/diff_num'
    *   '<S250>/diff_den'
    *   '<S262>/diff_num'
    *   '<S262>/diff_den'
    *   '<S275>/diff_num'
    *   '<S275>/diff_den'
    *   '<S287>/diff_num'
    *   '<S287>/diff_den'
    *   '<S299>/diff_num'
    *   '<S299>/diff_den'
    */
   0.0F,

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant29'
    *   '<S1>/default_gps_comp_factor'
    *   '<S26>/Constant1'
    */
   1.0F,

   /* Pooled Parameter (Expression: SystemExecutionTime)
    * Referenced by:
    *   '<S1>/Constant43'
    *   '<S1>/Constant44'
    */
   0.01F,

   /* Computed Parameter: VsVCAN_nu_CountsPerRevol_Value
    * Referenced by: '<S1>/VsVCAN_nu_CountsPerRevol'
    */
   96.0F,

   /* Computed Parameter: Constant40_Value
    * Referenced by: '<S1>/Constant40'
    */
   200.0F,

   /* Expression: k_speed_acceptable_abs_diff_mps
    * Referenced by: '<S1>/Constant'
    */
   3.0F,

   /* Computed Parameter: Constant1_Value
    * Referenced by: '<S1>/Constant1'
    */
   4.0F,

   /* Expression: k_yawrate_acceptable_abs_diff_IfStandstillBiasIsNotLearned_rps
    * Referenced by: '<S1>/Constant36'
    */
   0.25F,

   /* Computed Parameter: Constant34_Value
    * Referenced by: '<S1>/Constant34'
    */
   2.0F,

   /* Expression: k_yawrate_acceptable_abs_diff_rps
    * Referenced by: '<S1>/Constant20'
    */
   0.0349F,

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant25'
    *   '<S1>/Constant27'
    *   '<S1>/Constant31'
    */
   0.5F,

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant14'
    *   '<S1>/Constant22'
    */
   2.5F,

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant11'
    *   '<S1>/Constant21'
    *   '<S1>/Constant23'
    *   '<S1>/Constant30'
    *   '<S1>/Constant33'
    *   '<S1>/Constant4'
    *   '<S1>/Constant41'
    *   '<S1>/Constant42'
    *   '<S1>/default_f_use_gps_comp_factor'
    *   '<S1>/Unit Delay2'
    *   '<S4>/Constant4'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    */
   0,

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Unit Delay'
    *   '<S4>/Constant2'
    *   '<S4>/Constant3'
    *   '<S4>/Constant6'
    *   '<S59>/validity_default'
    *   '<S60>/validity_default'
    *   '<S61>/validity_default'
    *   '<S62>/validity_default'
    *   '<S105>/Constant3'
    *   '<S117>/Constant3'
    *   '<S129>/Constant3'
    *   '<S141>/Constant3'
    *   '<S153>/Constant3'
    *   '<S165>/Constant3'
    *   '<S213>/Constant3'
    *   '<S225>/Constant3'
    *   '<S237>/Constant3'
    *   '<S249>/Constant3'
    *   '<S261>/Constant3'
    *   '<S274>/Constant3'
    *   '<S286>/Constant3'
    *   '<S298>/Constant3'
    *   '<S64>/Constant'
    *   '<S65>/Constant'
    *   '<S66>/Constant'
    *   '<S67>/Constant'
    *   '<S68>/Constant'
    *   '<S69>/Constant'
    *   '<S70>/Constant'
    *   '<S71>/Constant'
    *   '<S72>/Constant'
    *   '<S73>/Constant'
    *   '<S74>/Constant'
    *   '<S75>/Constant'
    *   '<S76>/Constant'
    *   '<S77>/Constant'
    */
   UNDEFINED,

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant12'
    *   '<S105>/Constant'
    *   '<S117>/Constant'
    *   '<S129>/Constant'
    *   '<S141>/Constant'
    *   '<S153>/Constant'
    *   '<S165>/Constant'
    *   '<S180>/Constant'
    *   '<S183>/Constant'
    *   '<S186>/Constant'
    *   '<S189>/Constant'
    *   '<S192>/Constant'
    *   '<S195>/Constant'
    *   '<S198>/Constant'
    *   '<S201>/Constant'
    *   '<S204>/Constant'
    *   '<S207>/Constant'
    *   '<S210>/Constant'
    *   '<S213>/Constant'
    *   '<S225>/Constant'
    *   '<S237>/Constant'
    *   '<S249>/Constant'
    *   '<S261>/Constant'
    *   '<S274>/Constant'
    *   '<S286>/Constant'
    *   '<S298>/Constant'
    *   '<S110>/Constant'
    *   '<S122>/Constant'
    *   '<S134>/Constant'
    *   '<S146>/Constant'
    *   '<S158>/Constant'
    *   '<S170>/Constant'
    *   '<S218>/Constant'
    *   '<S230>/Constant'
    *   '<S242>/Constant'
    *   '<S254>/Constant'
    *   '<S266>/Constant'
    *   '<S279>/Constant'
    *   '<S291>/Constant'
    *   '<S303>/Constant'
    */
   ACCURATED};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
