/*
 * File: GradeEstimation_types.h
 *
 * Code generated for Simulink model 'GradeEstimation'.
 *
 * Model version                  : 1.10380
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:08 2026
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

#ifndef RTW_HEADER_GradeEstimation_types_h_
   #define RTW_HEADER_GradeEstimation_types_h_
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

   #ifndef DEFINED_TYPEDEF_FOR_enum_accuracy_level_T_
      #define DEFINED_TYPEDEF_FOR_enum_accuracy_level_T_

typedef uint8_T enum_accuracy_level_T;

      /* enum enum_accuracy_level_T */
      #define NO_ACCURATED     ((enum_accuracy_level_T)0U) /* Default value */
      #define MEDIUM_ACCURATED ((enum_accuracy_level_T)1U)
      #define HIGH_ACCURATED   ((enum_accuracy_level_T)2U)
   #endif

   #ifndef typedef_dsp_private_SlidingWindowAverageCG_GradeEstimation_T
      #define typedef_dsp_private_SlidingWindowAverageCG_GradeEstimation_T

typedef struct
{
   int32_T isInitialized;
   boolean_T isSetupComplete;
   real32_T pCumSum;
   real32_T pCumSumRev[9];
   real32_T pCumRevIndex;
} dsp_private_SlidingWindowAverageCG_GradeEstimation_T;

   #endif /*typedef_dsp_private_SlidingWindowAverageCG_GradeEstimation_T*/

   #ifndef typedef_cell_wrap_GradeEstimation_T
      #define typedef_cell_wrap_GradeEstimation_T

typedef struct
{
   uint32_T f1[8];
} cell_wrap_GradeEstimation_T;

   #endif /*typedef_cell_wrap_GradeEstimation_T*/

   #ifndef typedef_dsp_simulink_MovingAverage_GradeEstimation_T
      #define typedef_dsp_simulink_MovingAverage_GradeEstimation_T

typedef struct
{
   boolean_T matlabCodegenIsDeleted;
   int32_T isInitialized;
   boolean_T isSetupComplete;
   boolean_T TunablePropsChanged;
   cell_wrap_GradeEstimation_T inputVarSize;
   dsp_private_SlidingWindowAverageCG_GradeEstimation_T *pStatistic;
   int32_T NumChannels;
} dsp_simulink_MovingAverage_GradeEstimation_T;

   #endif /*typedef_dsp_simulink_MovingAverage_GradeEstimation_T*/

   /* Custom Type definition for MATLAB Function: '<S8>/GradeEstimation' */
   #ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
      #define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
   uint32_T SafeEq;
   uint32_T Absolute;
   uint32_T NaNBias;
   uint32_T NaNWithFinite;
   uint32_T FiniteWithNaN;
   uint32_T NaNWithNaN;
};

   #endif /*struct_tag_skA4KFEZ4HPkJJBOYCrevdH*/

   #ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH_GradeEstimation_T
      #define typedef_skA4KFEZ4HPkJJBOYCrevdH_GradeEstimation_T

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH_GradeEstimation_T;

   #endif /*typedef_skA4KFEZ4HPkJJBOYCrevdH_GradeEstimation_T*/

   #ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
      #define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
   boolean_T CaseSensitivity;
   boolean_T StructExpand;
   char_T PartialMatching[6];
   boolean_T IgnoreNulls;
};

   #endif /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

   #ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E_GradeEstimation_T
      #define typedef_sJCxfmxS8gBOONUZjbjUd9E_GradeEstimation_T

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E_GradeEstimation_T;

   #endif /*typedef_sJCxfmxS8gBOONUZjbjUd9E_GradeEstimation_T*/
#endif    /* RTW_HEADER_GradeEstimation_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
