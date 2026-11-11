/*
 * File: MultiWordSub_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "MultiWordSub_Aptiv.h"
#include "rtwtypes.h"

void MultiWordSub_Aptiv(const uint64_T u1[], const uint64_T u2[], uint64_T y[], int32_T n)
{
   uint64_T yi;
   uint64_T u1i;
   uint64_T borrow = 0ULL;
   int32_T i;
   for (i = 0; i < n; i++)
   {
      u1i    = u1[i];
      yi     = (u1i - u2[i]) - borrow;
      y[i]   = yi;
      borrow = (borrow != 0ULL) ? ((uint64_T)((yi >= u1i) ? 1 : 0)) : ((uint64_T)((yi > u1i) ? 1 : 0));
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
