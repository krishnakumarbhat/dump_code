/*
 * File: VehicleMassEstimator_2018b_types.h
 *
 * Code generated for Simulink model 'VehicleMassEstimator_2018b'.
 *
 * Model version                  : 1.861
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:07:28 2026
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

#ifndef RTW_HEADER_VehicleMassEstimator_2018b_types_h_
   #define RTW_HEADER_VehicleMassEstimator_2018b_types_h_
   #include "rtwtypes.h"
   #ifndef DEFINED_TYPEDEF_FOR_enum_Presence_Status_
      #define DEFINED_TYPEDEF_FOR_enum_Presence_Status_

typedef uint8_T enum_Presence_Status;

      /* enum enum_Presence_Status */
      #define Neither_Connected    ((enum_Presence_Status)0U) /* Default value */
      #define HW_Connected_Only    ((enum_Presence_Status)1U)
      #define RADAR_Connected_Only ((enum_Presence_Status)2U)
      #define Both_Connected       ((enum_Presence_Status)3U)
      #define Undefined            ((enum_Presence_Status)4U)
   #endif
#endif /* RTW_HEADER_VehicleMassEstimator_2018b_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
