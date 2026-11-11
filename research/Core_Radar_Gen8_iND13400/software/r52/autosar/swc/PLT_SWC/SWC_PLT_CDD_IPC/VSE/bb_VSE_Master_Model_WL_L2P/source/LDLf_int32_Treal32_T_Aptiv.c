/*
 * File: LDLf_int32_Treal32_T_Aptiv.c
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#include "LDLf_int32_Treal32_T_Aptiv.h"
#include "rtwtypes.h"

void LDLf_int32_Treal32_T_Aptiv(real32_T out[], real32_T vArray[], int32_T nRows, const real32_T in[])
{
   int32_T c;
   int32_T r;
   int32_T idx1;
   int32_T idx2;
   real32_T mYTmp;
   real32_T mYTmpR;
   boolean_T done;
   int32_T k;
   real32_T prod;
   boolean_T tmp;
   int32_T accum_tmp;
   int32_T exitg1;

   /* S-Function (sdspldl2): '<S28>/LDL Factorization' */
   done = false;

   /* use done to control the for loop return early  */
   /* when non-positive definite eigenvalue is detected */
   c = 0;
   do
   {
      exitg1 = 0;
      tmp    = !done;
      if ((c < nRows) && tmp)
      {
         idx2 = c * nRows;
         for (r = 0; r < c; r++)
         {
            idx1      = r * nRows;
            mYTmp     = out[idx1 + c];
            mYTmpR    = out[idx1 + r];
            vArray[r] = mYTmp * mYTmpR;
         }

         accum_tmp = idx2 + c;
         mYTmp     = in[accum_tmp];
         idx1      = c;
         for (r = 0; r < c; r++)
         {
            prod = out[idx1] * vArray[r];
            mYTmp -= prod;
            idx1 += nRows;
         }

         mYTmpR = mYTmp;
         if (mYTmp <= 0.0F)
         {
            done = true;
         }
         else
         {
            out[accum_tmp] = mYTmp;
            for (r = c + 1; r < nRows; r++)
            {
               accum_tmp = idx2 + r;
               mYTmp     = in[accum_tmp];
               idx1      = r;
               for (k = 0; k < c; k++)
               {
                  prod = out[idx1] * vArray[k];
                  mYTmp -= prod;
                  idx1 += nRows;
               }

               out[accum_tmp] = mYTmp / mYTmpR;
            }
         }

         c++;
      }
      else
      {
         exitg1 = 1;
      }
   } while (exitg1 == 0);

   /* transpose and copy lower sub-triang to upper */
   c = 0;
   while ((c < nRows) && tmp)
   {
      for (r = c + 1; r < nRows; r++)
      {
         mYTmp                = out[(c * nRows) + r];
         out[(r * nRows) + c] = mYTmp;
      }

      c++;
   }

   /* End of S-Function (sdspldl2): '<S28>/LDL Factorization' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
