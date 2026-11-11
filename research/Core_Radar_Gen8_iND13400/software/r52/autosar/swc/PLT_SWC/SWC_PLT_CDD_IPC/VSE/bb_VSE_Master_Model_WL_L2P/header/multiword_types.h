/*
 * File: multiword_types.h
 *
 * Code generated for Simulink model 'ABS_TCS_Algorithm'.
 *
 * Model version                  : 1.1225
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:05:31 2026
 */

#ifndef MULTIWORD_TYPES_H
   #define MULTIWORD_TYPES_H
   #include "rtwtypes.h"

/*
 * MultiWord supporting definitions
 */
typedef long long longlong_T;

/*
 * MultiWord types
 */
typedef struct
{
   uint64_T chunks[2];
} int128m_T;

typedef struct
{
   uint64_T chunks[2];
} uint128m_T;

typedef struct
{
   uint64_T chunks[3];
} int192m_T;

typedef struct
{
   uint64_T chunks[3];
} uint192m_T;

#endif /* MULTIWORD_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
