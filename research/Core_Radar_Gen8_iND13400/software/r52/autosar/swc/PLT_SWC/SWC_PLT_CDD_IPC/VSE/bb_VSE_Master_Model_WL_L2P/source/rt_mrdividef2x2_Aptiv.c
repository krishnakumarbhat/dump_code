/*
 * File: rt_mrdividef2x2_Aptiv.c
 *
 * Code generated for Simulink model 'Speed_Arbitration_and_IMU_Fusion'.
 *
 * Model version                  : 1.1412
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:59 2026
 */

#include "rt_mrdividef2x2_Aptiv.h"
#include "rtwtypes.h"
#include <math.h>

void rt_mrdividef2x2_Aptiv(const real32_T u0[4], const real32_T u1[4], real32_T y[4])
{
   int32_T r1;
   int32_T r2;
   real32_T a21;
   real32_T a22;
   int32_T y_tmp;
   real32_T a22_tmp;
   int32_T y_tmp_0;
   if (fabsf(u1[1]) > fabsf(u1[0]))
   {
      r1 = 1;
      r2 = 0;
   }
   else
   {
      r1 = 0;
      r2 = 1;
   }

   a21      = u1[r2] / u1[r1];
   a22_tmp  = u1[2 + r1];
   a22      = u1[2 + r2] - (a22_tmp * a21);
   y_tmp    = (r1 << 1);
   y[y_tmp] = u0[0] / u1[r1];
   r2 <<= 1;
   y[r2] = (u0[2] - (y[y_tmp] * a22_tmp)) / a22;
   y[y_tmp] -= y[r2] * a21;
   y_tmp_0    = 1 + y_tmp;
   y[y_tmp_0] = u0[1] / u1[r1];
   y_tmp++;
   y[1 + r2]  = (u0[3] - (y[y_tmp] * a22_tmp)) / a22;
   y[y_tmp_0] = y[y_tmp] - (y[r2 + 1] * a21);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
