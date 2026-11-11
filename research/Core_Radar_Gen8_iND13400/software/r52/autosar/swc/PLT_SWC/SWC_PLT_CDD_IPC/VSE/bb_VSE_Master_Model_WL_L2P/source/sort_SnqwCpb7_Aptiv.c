/*
 * File: sort_SnqwCpb7_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "sort_SnqwCpb7_Aptiv.h"
#include "rtwtypes.h"

/* Function for MATLAB Function: '<S79>/MATLAB Function' */
void sort_SnqwCpb7_Aptiv(real32_T x[4])
{
   real32_T x4[4];
   int32_T i1;
   int32_T i2;
   int32_T i3;
   int32_T i4;
   int8_T perm_idx_3;
   int8_T perm_idx_2;
   int8_T perm_idx_1;
   int8_T perm_idx_0;
   real32_T tmp;
   real32_T tmp_0;
   x4[0] = x[0];
   x4[1] = x[1];
   x4[2] = x[2];
   x4[3] = x[3];
   if (x[0] >= x[1])
   {
      i1 = 1;
      i2 = 2;
   }
   else
   {
      i1 = 2;
      i2 = 1;
   }

   if (x[2] >= x[3])
   {
      i3 = 3;
      i4 = 4;
   }
   else
   {
      i3 = 4;
      i4 = 3;
   }

   tmp   = x4[i1 - 1];
   tmp_0 = x4[i3 - 1];
   if (tmp >= tmp_0)
   {
      if (x4[i2 - 1] >= tmp_0)
      {
         perm_idx_0 = (int8_T)i1;
         perm_idx_1 = (int8_T)i2;
         perm_idx_2 = (int8_T)i3;
         perm_idx_3 = (int8_T)i4;
      }
      else if (x4[i2 - 1] >= x4[i4 - 1])
      {
         perm_idx_0 = (int8_T)i1;
         perm_idx_1 = (int8_T)i3;
         perm_idx_2 = (int8_T)i2;
         perm_idx_3 = (int8_T)i4;
      }
      else
      {
         perm_idx_0 = (int8_T)i1;
         perm_idx_1 = (int8_T)i3;
         perm_idx_2 = (int8_T)i4;
         perm_idx_3 = (int8_T)i2;
      }
   }
   else
   {
      tmp_0 = x4[i4 - 1];
      if (tmp >= tmp_0)
      {
         if (x4[i2 - 1] >= tmp_0)
         {
            perm_idx_0 = (int8_T)i3;
            perm_idx_1 = (int8_T)i1;
            perm_idx_2 = (int8_T)i2;
            perm_idx_3 = (int8_T)i4;
         }
         else
         {
            perm_idx_0 = (int8_T)i3;
            perm_idx_1 = (int8_T)i1;
            perm_idx_2 = (int8_T)i4;
            perm_idx_3 = (int8_T)i2;
         }
      }
      else
      {
         perm_idx_0 = (int8_T)i3;
         perm_idx_1 = (int8_T)i4;
         perm_idx_2 = (int8_T)i1;
         perm_idx_3 = (int8_T)i2;
      }
   }

   x[0] = x4[perm_idx_0 - 1];
   x[1] = x4[perm_idx_1 - 1];
   x[2] = x4[perm_idx_2 - 1];
   x[3] = x4[perm_idx_3 - 1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
