/*===========================================================================*\
 * FILE: Std_Types.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2024 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Mock header providing AUTOSAR standard types for unit testing.
\*===========================================================================*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int32_t sint32;

typedef uint8_t Std_ReturnType;

#define E_OK     ((Std_ReturnType)0u)
#define E_NOT_OK ((Std_ReturnType)1u)

#endif /* STD_TYPES_H */
