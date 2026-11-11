/*
 * File: MultiWordUnsignedWrap_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "MultiWordUnsignedWrap_Aptiv.h"
#include "rtwtypes.h"

void MultiWordUnsignedWrap_Aptiv(const uint64_T u1[], int32_T n1, uint32_T n2, uint64_T y[])
{
   int32_T n1m1;
   int32_T i;
   n1m1 = n1 - 1;
   for (i = 0; i < n1m1; i++)
   {
      y[i] = u1[i];
   }

   y[n1m1] = ((1ULL << (64U - n2)) - 1ULL) & u1[n1m1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
