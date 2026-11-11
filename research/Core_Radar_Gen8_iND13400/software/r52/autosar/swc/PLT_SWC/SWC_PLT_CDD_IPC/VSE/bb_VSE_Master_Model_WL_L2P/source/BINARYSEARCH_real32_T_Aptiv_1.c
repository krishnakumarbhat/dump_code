/*
 * File: BINARYSEARCH_real32_T_Aptiv_1.c
 *
 * Code generated for Simulink model 'VehicleCurvatureAndSideslipEstimation_Simulink'.
 *
 * Model version                  : 1.483
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:07:21 2026
 */

#include "BINARYSEARCH_real32_T_Aptiv_1.h"
#include "rtwtypes.h"

/* Lookup Binary Search Utility BINARYSEARCH_real32_T_Aptiv_1 */
void BINARYSEARCH_real32_T_Aptiv_1(uint32_T *piLeft, uint32_T *piRght, real32_T u, const real32_T *pData, uint32_T iHi)
{
   /* Find the location of current input value in the data table. */
   *piLeft = 0U;
   *piRght = iHi;
   if (u <= pData[0])
   {
      /* Less than or equal to the smallest point in the table. */
      *piRght = 0U;
   }
   else if (u >= pData[iHi])
   {
      /* Greater than or equal to the largest point in the table. */
      *piLeft = iHi;
   }
   else
   {
      uint32_T i;

      /* Do a binary search. */
      while ((*piRght - *piLeft) > 1U)
      {
         /* Get the average of the left and right indices using to Floor rounding. */
         i = (*piLeft + *piRght) >> 1;

         /* Move either the right index or the left index so that */
         /*  LeftDataPoint <= CurrentValue < RightDataPoint */
         if (u < pData[i])
         {
            *piRght = i;
         }
         else
         {
            *piLeft = i;
         }
      }
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
