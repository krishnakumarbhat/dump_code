/*
 * File: uMultiWord2MultiWord_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "uMultiWord2MultiWord_Aptiv.h"
#include "rtwtypes.h"

void uMultiWord2MultiWord_Aptiv(const uint64_T u1[], int32_T n1, uint64_T y[], int32_T n)
{
   int32_T nm;
   int32_T i;
   nm = (n1 < n) ? n1 : n;
   for (i = 0; i < nm; i++)
   {
      y[i] = u1[i];
   }

   if (n > n1)
   {
      for (i = nm; i < n; i++)
      {
         y[i] = 0ULL;
      }
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
