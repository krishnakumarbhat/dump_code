/*
 * File: uLong2MultiWord_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "uLong2MultiWord_Aptiv.h"
#include "rtwtypes.h"

void uLong2MultiWord_Aptiv(uint64_T u, uint64_T y[], int32_T n)
{
   int32_T i;
   y[0] = u;
   for (i = 1; i < n; i++)
   {
      y[i] = 0ULL;
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
