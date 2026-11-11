/*
 * File: Speed_Arbitration_and_IMU_Fusion_types.h
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

#ifndef RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_types_h_
   #define RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_types_h_
   #include "multiword_types.h"
   #include "rtwtypes.h"
   #ifndef DEFINED_TYPEDEF_FOR_enum_quality_factor_T_
      #define DEFINED_TYPEDEF_FOR_enum_quality_factor_T_

typedef uint8_T enum_quality_factor_T;

      /* enum enum_quality_factor_T */
      #define UNDEFINED      ((enum_quality_factor_T)0U) /* Default value */
      #define TEMP_UNDEFINED ((enum_quality_factor_T)1U)
      #define NOT_ACCURATED  ((enum_quality_factor_T)2U)
      #define ACCURATED      ((enum_quality_factor_T)3U)
   #endif

   #ifndef DEFINED_TYPEDEF_FOR_enum_accuracy_level_wheelodo_T_
      #define DEFINED_TYPEDEF_FOR_enum_accuracy_level_wheelodo_T_

typedef uint8_T enum_accuracy_level_wheelodo_T;

      /* enum enum_accuracy_level_wheelodo_T */
      #define LOW    ((enum_accuracy_level_wheelodo_T)0U) /* Default value */
      #define MEDIUM ((enum_accuracy_level_wheelodo_T)1U)
      #define HIGH   ((enum_accuracy_level_wheelodo_T)2U)
   #endif

   #ifndef typedef_dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T
      #define typedef_dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T

typedef struct
{
   int32_T isInitialized;
   boolean_T isSetupComplete;
   boolean_T TunablePropsChanged;
   real32_T ForgettingFactor;
   real32_T pwN;
   real32_T pmN;
   real32_T plambda;
} dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T;

   #endif /*typedef_dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T*/

   #ifndef struct_md7896c464216b277e4da792f37573b847
      #define struct_md7896c464216b277e4da792f37573b847

struct md7896c464216b277e4da792f37573b847
{
   int32_T S0_isInitialized;
   real32_T W0_ZERO_STATES[2];
   real32_T W1_POLE_STATES[2];
   int32_T W2_PreviousNumChannels;
   real32_T P0_ICRTP;
   real32_T P1_RTP1COEFF[3];
   real32_T P2_RTP2COEFF[2];
   real32_T P3_RTP3COEFF[2];
   boolean_T P4_RTP_COEFF3_BOOL[2];
   real32_T P5_IC2RTP;
};

   #endif /*struct_md7896c464216b277e4da792f37573b847*/

   #ifndef typedef_dsp_BiquadFilter_0_Speed_Arbitration_and_IMU_Fusion_T
      #define typedef_dsp_BiquadFilter_0_Speed_Arbitration_and_IMU_Fusion_T

typedef struct md7896c464216b277e4da792f37573b847 dsp_BiquadFilter_0_Speed_Arbitration_and_IMU_Fusion_T;

   #endif /*typedef_dsp_BiquadFilter_0_Speed_Arbitration_and_IMU_Fusion_T*/

   #ifndef struct_mdsnwWAKKG2FjwPu0RwkLyb
      #define struct_mdsnwWAKKG2FjwPu0RwkLyb

struct mdsnwWAKKG2FjwPu0RwkLyb
{
   boolean_T matlabCodegenIsDeleted;
   int32_T isInitialized;
   boolean_T isSetupComplete;
   dsp_BiquadFilter_0_Speed_Arbitration_and_IMU_Fusion_T cSFunObject;
};

   #endif /*struct_mdsnwWAKKG2FjwPu0RwkLyb*/

   #ifndef typedef_dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T
      #define typedef_dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T

typedef struct mdsnwWAKKG2FjwPu0RwkLyb dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T;

   #endif /*typedef_dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T*/

   #ifndef typedef_cell_wrap_Speed_Arbitration_and_IMU_Fusion_T
      #define typedef_cell_wrap_Speed_Arbitration_and_IMU_Fusion_T

typedef struct
{
   uint32_T f1[8];
} cell_wrap_Speed_Arbitration_and_IMU_Fusion_T;

   #endif /*typedef_cell_wrap_Speed_Arbitration_and_IMU_Fusion_T*/

   #ifndef typedef_dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T
      #define typedef_dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T

typedef struct
{
   boolean_T matlabCodegenIsDeleted;
   int32_T isInitialized;
   boolean_T isSetupComplete;
   boolean_T TunablePropsChanged;
   cell_wrap_Speed_Arbitration_and_IMU_Fusion_T inputVarSize;
   real32_T ForgettingFactor;
   dsp_private_ExponentialMovingAverage_Speed_Arbitration_and_IMU_Fusion_T *pStatistic;
   int32_T NumChannels;
} dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T;

   #endif /*typedef_dsp_simulink_MovingAverage_Speed_Arbitration_and_IMU_Fusion_T*/

   #ifndef struct_md7LQJVvfXdR2lCSRUQ2sHEH
      #define struct_md7LQJVvfXdR2lCSRUQ2sHEH

struct md7LQJVvfXdR2lCSRUQ2sHEH
{
   boolean_T matlabCodegenIsDeleted;
   int32_T isInitialized;
   boolean_T isSetupComplete;
   cell_wrap_Speed_Arbitration_and_IMU_Fusion_T inputVarSize;
   int32_T NumChannels;
   dspcodegen_BiquadFilter_Speed_Arbitration_and_IMU_Fusion_T *FilterObj;
};

   #endif /*struct_md7LQJVvfXdR2lCSRUQ2sHEH*/

   #ifndef typedef_dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T
      #define typedef_dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T

typedef struct md7LQJVvfXdR2lCSRUQ2sHEH dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T;

   #endif /*typedef_dsp_LowpassFilter_Speed_Arbitration_and_IMU_Fusion_T*/
#endif    /* RTW_HEADER_Speed_Arbitration_and_IMU_Fusion_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
