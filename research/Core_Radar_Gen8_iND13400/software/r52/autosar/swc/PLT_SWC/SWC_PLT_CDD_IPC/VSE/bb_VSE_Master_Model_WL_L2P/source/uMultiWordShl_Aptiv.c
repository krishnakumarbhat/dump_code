/*
 * File: uMultiWordShl_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "uMultiWordShl_Aptiv.h"
#include "rtwtypes.h"

void uMultiWordShl_Aptiv(const uint64_T u1[], int32_T n1, uint32_T n2, uint64_T y[], int32_T n)
{
   int32_T nb;
   int32_T nc;
   int32_T i;
   uint64_T ys;
   uint64_T u1i;
   uint64_T yi;
   uint32_T nr;
   uint32_T nl;
   nb  = (int32_T)((uint32_T)(n2 >> 6));
   ys  = ((u1[n1 - 1] & 9223372036854775808ULL) != 0ULL) ? MAX_uint64_T : 0ULL;
   nc  = (nb > n) ? n : nb;
   u1i = 0ULL;
   for (i = 0; i < nc; i++)
   {
      y[i] = 0ULL;
   }

   if (nb < n)
   {
      nl = n2 - (((uint32_T)nb) << 6);
      nb += n1;
      if (nb > n)
      {
         nb = n;
      }

      nb -= i;
      if (nl > 0U)
      {
         nr = 64U - nl;
         for (nc = 0; nc < nb; nc++)
         {
            yi   = (u1i >> nr);
            u1i  = u1[nc];
            y[i] = (u1i << nl) | yi;
            i++;
         }

         if (i < n)
         {
            y[i] = (u1i >> nr) | (ys << nl);
            i++;
         }
      }
      else
      {
         for (nc = 0; nc < nb; nc++)
         {
            y[i] = u1[nc];
            i++;
         }
      }
   }

   while (i < n)
   {
      y[i] = ys;
      i++;
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
