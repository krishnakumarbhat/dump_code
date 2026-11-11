/*
 * File: rtmodel.h
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

#ifndef RTW_HEADER_rtmodel_h_
   #define RTW_HEADER_rtmodel_h_
   #include "VSE_Master_Model_WL_L2P.h"

   /*
    * ROOT_IO_FORMAT: 0 (Individual arguments)
    * ROOT_IO_FORMAT: 1 (Structure reference)
    * ROOT_IO_FORMAT: 2 (Part of model data structure)
    */
   #define ROOT_IO_FORMAT 0

   /* Macros generated for backwards compatibility  */
   #ifndef rtmGetErrorStatus
      #define rtmGetErrorStatus(rtm) ((void *)0)
   #endif

   #ifndef rtmSetErrorStatus
      #define rtmSetErrorStatus(rtm, val) ((void)0)
   #endif

   #ifndef rtmGetStopRequested
      #define rtmGetStopRequested(rtm) ((void *)0)
   #endif
#endif /* RTW_HEADER_rtmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
