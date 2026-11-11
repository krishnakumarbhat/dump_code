/*
 * File: ABS_TCS_Algorithm_types.h
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
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

#ifndef RTW_HEADER_ABS_TCS_Algorithm_types_h_
   #define RTW_HEADER_ABS_TCS_Algorithm_types_h_
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

   /* Custom Type definition for MATLAB Function: '<S79>/MATLAB Function' */
   #ifndef struct_tag_spGKsvEVm7uA89hv31XX4LH
      #define struct_tag_spGKsvEVm7uA89hv31XX4LH

struct tag_spGKsvEVm7uA89hv31XX4LH
{
   uint32_T MissingPlacement;
   uint32_T ComparisonMethod;
};

   #endif /*struct_tag_spGKsvEVm7uA89hv31XX4LH*/

   #ifndef typedef_spGKsvEVm7uA89hv31XX4LH_ABS_TCS_Algorithm_T
      #define typedef_spGKsvEVm7uA89hv31XX4LH_ABS_TCS_Algorithm_T

typedef struct tag_spGKsvEVm7uA89hv31XX4LH spGKsvEVm7uA89hv31XX4LH_ABS_TCS_Algorithm_T;

   #endif /*typedef_spGKsvEVm7uA89hv31XX4LH_ABS_TCS_Algorithm_T*/

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

   #ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E_ABS_TCS_Algorithm_T
      #define typedef_sJCxfmxS8gBOONUZjbjUd9E_ABS_TCS_Algorithm_T

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E_ABS_TCS_Algorithm_T;

   #endif /*typedef_sJCxfmxS8gBOONUZjbjUd9E_ABS_TCS_Algorithm_T*/

   #ifndef typedef_dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T
      #define typedef_dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T

typedef struct
{
   int32_T isInitialized;
   boolean_T isSetupComplete;
   boolean_T TunablePropsChanged;
   real32_T ForgettingFactor;
   real32_T pwN;
   real32_T pmN;
   real32_T plambda;
} dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T;

   #endif /*typedef_dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T*/

   #ifndef typedef_cell_wrap_ABS_TCS_Algorithm_T
      #define typedef_cell_wrap_ABS_TCS_Algorithm_T

typedef struct
{
   uint32_T f1[8];
} cell_wrap_ABS_TCS_Algorithm_T;

   #endif /*typedef_cell_wrap_ABS_TCS_Algorithm_T*/

   #ifndef typedef_dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T
      #define typedef_dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T

typedef struct
{
   boolean_T matlabCodegenIsDeleted;
   int32_T isInitialized;
   boolean_T isSetupComplete;
   boolean_T TunablePropsChanged;
   cell_wrap_ABS_TCS_Algorithm_T inputVarSize;
   real32_T ForgettingFactor;
   dsp_private_ExponentialMovingAverage_ABS_TCS_Algorithm_T *pStatistic;
   int32_T NumChannels;
} dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T;

   #endif /*typedef_dsp_simulink_MovingAverage_ABS_TCS_Algorithm_T*/
#endif    /* RTW_HEADER_ABS_TCS_Algorithm_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
