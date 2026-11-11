/*
 * File: uMultiWord2uMultiWordSat_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "uMultiWord2uMultiWordSat_Aptiv.h"
#include "rtwtypes.h"

void uMultiWord2uMultiWordSat_Aptiv(const uint64_T u1[], int32_T n1, uint64_T y[], int32_T n)
{
   int32_T i;
   boolean_T doSaturation = false;
   int32_T nc;
   i = n1 - 1;
   while ((!doSaturation) && (i >= n))
   {
      doSaturation = (u1[i] != 0ULL);
      i--;
   }

   if (doSaturation)
   {
      for (i = 0; i < n; i++)
      {
         y[i] = MAX_uint64_T;
      }
   }
   else
   {
      nc = (n1 < n) ? n1 : n;
      for (i = 0; i < nc; i++)
      {
         y[i] = u1[i];
      }

      while (i < n)
      {
         y[i] = 0ULL;
         i++;
      }
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
