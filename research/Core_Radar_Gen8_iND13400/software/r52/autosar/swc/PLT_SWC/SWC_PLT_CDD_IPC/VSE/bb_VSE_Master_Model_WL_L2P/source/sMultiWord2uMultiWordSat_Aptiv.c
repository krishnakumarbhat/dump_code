/*
 * File: sMultiWord2uMultiWordSat_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "sMultiWord2uMultiWordSat_Aptiv.h"
#include "rtwtypes.h"

void sMultiWord2uMultiWordSat_Aptiv(const uint64_T u1[], int32_T n1, uint64_T y[], int32_T n)
{
   uint64_T ys;
   int32_T n1m1;
   boolean_T doSaturation;
   int32_T nc;
   n1m1         = n1 - 1;
   ys           = ((u1[n1m1] & 9223372036854775808ULL) != 0ULL) ? MAX_uint64_T : 0ULL;
   doSaturation = (ys != 0ULL);
   while ((!doSaturation) && (n1m1 >= n))
   {
      doSaturation = (u1[n1m1] != 0ULL);
      n1m1--;
   }

   if (doSaturation)
   {
      ys = ~ys;
      for (n1m1 = 0; n1m1 < n; n1m1++)
      {
         y[n1m1] = ys;
      }
   }
   else
   {
      nc = (n1 < n) ? n1 : n;
      for (n1m1 = 0; n1m1 < nc; n1m1++)
      {
         y[n1m1] = u1[n1m1];
      }

      while (n1m1 < n)
      {
         y[n1m1] = ys;
         n1m1++;
      }
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
