/*
 * File: look1_iflf_linlc_Aptiv.c
 *
 * Code generated for Simulink model 'SelectHostLongAccel'.
 *
 * Model version                  : 1.178
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:06:28 2026
 */

#include "look1_iflf_linlc_Aptiv.h"
#include "rtwtypes.h"

real32_T look1_iflf_linlc_Aptiv(real32_T u0, const real32_T bp0[], const real32_T table[], uint32_T maxIndex)
{
   real32_T frac;
   uint32_T bpIdx;

   /* Column-major Lookup 1-D
      Canonical function name: look1_iflf_linlc
      Search method: 'linear'
      Use previous index: 'off'
      Interpolation method: 'Linear point-slope'
      Extrapolation method: 'Clip'
      Use last breakpoint for index at or above upper limit: 'off'
      Remove protection against out-of-range input in generated code: 'off'
    */
   /* Prelookup - Index and Fraction
      Index Search method: 'linear'
      Extrapolation method: 'Clip'
      Use previous index: 'off'
      Use last breakpoint for index at or above upper limit: 'off'
      Remove protection against out-of-range input in generated code: 'off'
    */
   if (u0 <= bp0[0U])
   {
      bpIdx = 0U;
      frac  = 0.0F;
   }
   else if (u0 < bp0[maxIndex])
   {
      /* Linear Search */
      for (bpIdx = (maxIndex >> 1U); u0 < bp0[bpIdx]; bpIdx--)
      {
      }

      while (u0 >= bp0[bpIdx + 1U])
      {
         bpIdx++;
      }

      frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
   }
   else
   {
      bpIdx = maxIndex - 1U;
      frac  = 1.0F;
   }

   /* Column-major Interpolation 1-D
      Canonical function name: intrp1d_fu32fl
      Interpolation method: 'Linear point-slope'
      Use last breakpoint for index at or above upper limit: 'off'
      Overflow mode: 'wrapping'
    */
   return ((table[bpIdx + 1U] - table[bpIdx]) * frac) + table[bpIdx];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
