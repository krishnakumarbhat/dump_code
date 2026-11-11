/*===========================================================================*\
 * FILE: Std_Types.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Mock AUTOSAR standard types for unit testing.
\*===========================================================================*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Prevent real AUTOSAR Platform_Types.h from being included to avoid type conflicts */
#ifndef PLATFORM_TYPES_H
   #define PLATFORM_TYPES_H
#endif

#include <stdbool.h>
#include <stdint.h>

/* AUTOSAR integer types */
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

/* AUTOSAR floating point types */
typedef float float32;
typedef double float64;

/* AUTOSAR boolean type */
typedef uint8_t boolean;
#ifndef TRUE
   #define TRUE ((boolean)1u)
#endif
#ifndef FALSE
   #define FALSE ((boolean)0u)
#endif

/* AUTOSAR return types */
typedef uint8_t Std_ReturnType;
typedef uint8_t StatusType;

#define E_OK     ((Std_ReturnType)0u)
#define E_NOT_OK ((Std_ReturnType)1u)

#define STD_ON  1u
#define STD_OFF 0u

/* AUTOSAR version info type */
typedef struct
{
   uint16 vendorID;
   uint16 moduleID;
   uint8 sw_major_version;
   uint8 sw_minor_version;
   uint8 sw_patch_version;
} Std_VersionInfoType;

#endif /* STD_TYPES_H */
