/*===========================================================================*/
/**
 * @file Platform_Types.h
 *
 * Platform_Types
 *
 *
 * Platform specific type definitions for ARM32
 * -----------------------------------------------------------------------------
 *
 * copyright (c)2024 indie Semiconductor, all rights reserved.
 * This software is copyright protected and proprietary of indie Semiconductor.
 * indie Semiconductor grants to you only those rights as set out in the
 * license conditions.
 *
 * 
 * -----------------------------------------------------------------------------
 *
 *
 *
 */

/*===========================================================================*/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*===========================================================================*
 * Includes
*===========================================================================*/

/* polyspace-begin MISRA-C-2023:2.3,2.5,5.4 [No action planned:Low] "Unused macros part of the platform types, required to be kept for future implementation and compatibility" */
/* polyspace-begin CERT-C:DCL23-C [No action planned:Low] "Duplicated datatypes accepted as part of the platform types, to ensure compatibility between multiple targets and compilers" */

/*===========================================================================*
* Global Constants
*===========================================================================*/
/* AUTOSAR release 4.3.0 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION      (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION      (3u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION   (0u)
/* Component Version Information */
#define PLATFORM_SW_MAJOR_VERSION       (4u)
#define PLATFORM_SW_MINOR_VERSION       (3u)
#define PLATFORM_SW_PATCH_VERSION       (0u)

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
#define MSB_FIRST 0
#define LSB_FIRST 1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1

#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST


#ifndef TRUE
#define TRUE (1U)
#endif
#ifndef FALSE
#define FALSE (0U)
#endif

#ifndef SINT8_MIN
#define SINT8_MIN ((sint8)-128)
#endif

#ifndef SINT8_MAX
#define SINT8_MAX ((sint8)127)
#endif

#ifndef UINT8_MIN
#define UINT8_MIN ((uint8)0U)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX ((uint8)255U)
#endif

#ifndef SINT16_MIN
#define SINT16_MIN ((sint16)-32768)
#endif

#ifndef SINT16_MAX
#define SINT16_MAX ((sint16)32767)
#endif

#ifndef UINT16_MIN
#define UINT16_MIN ((uint16)0U)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX ((uint16)65535U)
#endif

#ifndef SINT32_MIN
#define SINT32_MIN ((sint32)-2147483648)
#endif

#ifndef SINT32_MAX
#define SINT32_MAX ((sint32)2147483647)
#endif

#ifndef UINT32_MIN
#define UINT32_MIN ((uint32)0U)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX ((uint32)4294967295U)
#endif

#ifndef SINT64_MIN
#define SINT64_MIN ((sint64)-9223372036854775808LL)
#endif

#ifndef SINT64_MAX
#define SINT64_MAX ((sint64)9223372036854775807LL)
#endif

#ifndef UINT64_MIN
#define UINT64_MIN ((uint64)0U)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX ((uint64)18446744073709551615ULL)
#endif

/*===========================================================================*
* Global Function Macros
*===========================================================================*/

/*===========================================================================*
* Global Datatypes and Structures
*===========================================================================*/

/* polyspace-begin Custom:3.1 [No action planned:Mid] "Platform-specific integer mappings required for portability across compilers and targets" */
typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;

typedef signed char   sint8;
typedef signed short  sint16;
typedef signed int    sint32;

#define PLATFORM_SUPPORT_SINT64_UINT64
typedef unsigned long long int    uint64;
typedef signed long long int    sint64;

typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;
typedef signed long sint8_least;
typedef signed long sint16_least;
typedef signed long sint32_least;

typedef _Bool boolean;

/* polyspace+2 Custom:3.3 [No action planned:Mid] "Platform-specific integer mappings required for portability across compilers and targets" */
typedef  void * voidPtr;
typedef const void * ConstVoidPtr;

/* polyspace+2 Custom:3.2 [No action planned:Mid] "Platform-specific integer mappings required for portability across compilers and targets" */
typedef float float32;
typedef double float64;
/* polyspace-end Custom:3.1 [No action planned:Mid] "Platform-specific integer mappings required for portability across compilers and targets" */
/*===========================================================================*
* Global Data
*===========================================================================*/

/*===========================================================================*
* Global Function Prototypes
*===========================================================================*/

/*===========================================================================*
* Global Inline Functions
*===========================================================================*/

/* polyspace-end MISRA-C-2023:2.3,2.5,5.4 [No action planned:Low] "Unused macros part of the platform types, required to be kept for future implementation and compatibility" */
/* polyspace-end CERT-C:DCL23-C [No action planned:Low] "Duplicated datatypes accepted as part of the platform types, to ensure compatibility between multiple targets and compilers" */

#endif /* PLATFORM_TYPES_H */
