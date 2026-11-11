/*
 * File: uMultiWordShr_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "uMultiWordShr_Aptiv.h"
#include "rtwtypes.h"

void uMultiWordShr_Aptiv(const uint64_T u1[], int32_T n1, uint32_T n2, uint64_T y[], int32_T n)
{
   int32_T nb;
   int32_T i;
   uint64_T yi;
   uint64_T u1i;
   int32_T nc;
   uint32_T nr;
   uint32_T nl;
   int32_T i1;
   nb = (int32_T)((uint32_T)(n2 >> 6));
   i  = 0;
   if (nb < n1)
   {
      nc = n + nb;
      if (nc > n1)
      {
         nc = n1;
      }

      nr = n2 - (((uint32_T)nb) << 6);
      if (nr > 0U)
      {
         nl  = 64U - nr;
         u1i = u1[nb];
         for (i1 = nb + 1; i1 < nc; i1++)
         {
            yi   = (u1i >> nr);
            u1i  = u1[i1];
            y[i] = (u1i << nl) | yi;
            i++;
         }

         yi = (u1i >> nr);
         if (nc < n1)
         {
            yi |= (u1[nc] << nl);
         }

         y[i] = yi;
         i++;
      }
      else
      {
         for (i1 = nb; i1 < nc; i1++)
         {
            y[i] = u1[i1];
            i++;
         }
      }
   }

   while (i < n)
   {
      y[i] = 0ULL;
      i++;
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
