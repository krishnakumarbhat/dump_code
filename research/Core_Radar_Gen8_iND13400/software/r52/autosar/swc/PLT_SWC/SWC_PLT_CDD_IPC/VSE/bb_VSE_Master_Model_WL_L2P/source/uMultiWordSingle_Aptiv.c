/*
 * File: uMultiWordSingle_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "uMultiWordSingle_Aptiv.h"
#include "rtwtypes.h"
#include <math.h>

real32_T uMultiWordSingle_Aptiv(const uint64_T u1[], int32_T n1, int32_T e1)
{
   real32_T y;
   int32_T i;
   int32_T exp_0;
   y     = 0.0F;
   exp_0 = e1;
   for (i = 0; i < n1; i++)
   {
      y += (real32_T)ldexp((real_T)((real32_T)u1[i]), exp_0);
      exp_0 += 64;
   }

   return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
