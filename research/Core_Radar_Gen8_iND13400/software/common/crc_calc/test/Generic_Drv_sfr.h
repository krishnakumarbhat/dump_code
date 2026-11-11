/*===========================================================================*/
/**
 * @file Generic_Drv_sfr.h
 *
 * Unit-test stub replacing the real SDK CRC / platform SFR headers.
 * Provides B0-variant CRC_SFRS_t layout (4-channel CRC engine) plus
 * all platform-level types and constants consumed by crc_calc.c.
 *
 * This header is resolved *before* any SDK header via strip_include_prefix
 * in Bazel, so it shadows:
 *   - Generic_Drv_sfr.h   (CRC register layout, CRC_base)
 *   - Driver_Common.h      (ARM_DRIVER_* error codes)
 *   - reuse.h              (boolean, uint8, uint32, …)
 */
/*==========================================================================*/
#pragma once

#include <stdbool.h>
#include <stdint.h>

/*===========================================================================*
 * Block SDK sub-headers that the stub replaces
 *===========================================================================*/
#ifndef DRIVER_COMMON_H
   #define DRIVER_COMMON_H
#endif
#ifndef REUSE_H
   #define REUSE_H
#endif

/*===========================================================================*
 * Platform type aliases (normally from reuse.h / Compiler_Cfg.h)
 *===========================================================================*/
#ifndef boolean
typedef unsigned char boolean;
#endif
#ifndef uint8
typedef uint8_t uint8;
#endif
#ifndef uint16
typedef uint16_t uint16;
#endif
#ifndef uint32
typedef uint32_t uint32;
#endif

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;

typedef float float32_t;
typedef double float64_t;

typedef uint8_t bitfield8_t;
typedef uint16_t bitfield16_t;
typedef uint32_t bitfield32_t;

/*===========================================================================*
 * ARM CMSIS-Driver error / status codes (normally from Driver_Common.h)
 *===========================================================================*/
#define ARM_DRIVER_VERSION_MAJOR_MINOR(major, minor) (((major) << 8) | (minor))
#define ARM_DRIVER_OK                                0
#define ARM_DRIVER_ERROR                             (-1)
#define ARM_DRIVER_ERROR_BUSY                        (-2)
#define ARM_DRIVER_ERROR_TIMEOUT                     (-3)
#define ARM_DRIVER_ERROR_UNSUPPORTED                 (-4)
#define ARM_DRIVER_ERROR_PARAMETER                   (-5)
#define ARM_DRIVER_ERROR_SPECIFIC                    (-6)

/*===========================================================================*
 * HW-version selector – force B0 path
 *===========================================================================*/
#define CHANDRA_SFR_HW_VERSION  0xB0U /* != 0xA0U  → selects B0 code */
#define CRC_HARDWARE_A0_VARIANT 0U
#define CRC_HARDWARE_VARIANT    1U /* != CRC_HARDWARE_A0_VARIANT   */

/*===========================================================================*
 * CRC channel CTL union – B0 per-channel layout
 * (mirrors sdk/R52/cmsis-drivers/CMSIS/chandra_b0/sfr/crc_sfrs.h)
 *===========================================================================*/
typedef union
{
   struct
   {
      uint32_t PAR:2;        /* bits [1:0]   – parallelism          */
      uint32_t BYTE_REV:1;   /* bit  [2]     – byte reverse         */
      uint32_t BIT_REV:1;    /* bit  [3]     – bit reverse          */
      uint32_t BYTE_SHIFT:2; /* bits [5:4]   – byte shift           */
      uint32_t:10;           /* bits [15:6]  – reserved             */
      uint32_t OUT_REV:1;    /* bit  [16]    – output reverse       */
      uint32_t:1;            /* bit  [17]    – reserved             */
      uint32_t OUT_POL:1;    /* bit  [18]    – output polarity      */
      uint32_t:5;            /* bits [23:19] – reserved             */
      uint32_t POLY:3;       /* bits [26:24] – polynomial select    */
      uint32_t:5;            /* bits [31:27] – reserved             */
   } f;
   uint32_t r;
} CRC_CH_CTL_t;

/* SDK uses per-channel typedef names – alias them all to the same layout */
typedef CRC_CH_CTL_t CRC_CH0_CTL_t;
typedef CRC_CH_CTL_t CRC_CH1_CTL_t;
typedef CRC_CH_CTL_t CRC_CH2_CTL_t;
typedef CRC_CH_CTL_t CRC_CH3_CTL_t;

/*===========================================================================*
 * B0 CRC Special-Function-Register block (4-channel)
 *===========================================================================*/
typedef struct
{
   CRC_CH0_CTL_t CH0_CTL; /* +0x000 */
   uint32_t CH0_INIT;     /* +0x004 */
   uint32_t CH0_OUT;      /* +0x008 */
   uint8_t _RESERVED_00C[4];
   uint32_t CH0_XIN0; /* +0x010 */
   uint32_t CH0_XIN1; /* +0x014 */
   uint32_t CH0_XIN2; /* +0x018 */
   uint32_t CH0_XIN3; /* +0x01C */

   CRC_CH1_CTL_t CH1_CTL; /* +0x020 */
   uint32_t CH1_INIT;     /* +0x024 */
   uint32_t CH1_OUT;      /* +0x028 */
   uint8_t _RESERVED_02C[4];
   uint32_t CH1_XIN0; /* +0x030 */
   uint32_t CH1_XIN1; /* +0x034 */
   uint32_t CH1_XIN2; /* +0x038 */
   uint32_t CH1_XIN3; /* +0x03C */

   CRC_CH2_CTL_t CH2_CTL; /* +0x040 */
   uint32_t CH2_INIT;     /* +0x044 */
   uint32_t CH2_OUT;      /* +0x048 */
   uint8_t _RESERVED_04C[4];
   uint32_t CH2_XIN0; /* +0x050 */
   uint32_t CH2_XIN1; /* +0x054 */
   uint32_t CH2_XIN2; /* +0x058 */
   uint32_t CH2_XIN3; /* +0x05C */

   CRC_CH3_CTL_t CH3_CTL; /* +0x060 */
   uint32_t CH3_INIT;     /* +0x064 */
   uint32_t CH3_OUT;      /* +0x068 */
   uint8_t _RESERVED_06C[4];
   uint32_t CH3_XIN0; /* +0x070 */
   uint32_t CH3_XIN1; /* +0x074 */
   uint32_t CH3_XIN2; /* +0x078 */
   uint32_t CH3_XIN3; /* +0x07C */
} CRC_SFRS_t;

/*===========================================================================*
 * CRC base-address macro – points to a testable RAM instance.
 * Only used inside  #ifndef UNIT_TEST  in crc_calc.c, so we define it
 * for completeness but ptr_crc is provided by the test harness instead.
 *===========================================================================*/
static CRC_SFRS_t g_crc_stub_sfrs;
#undef CRC_base
#define CRC_base ((uintptr_t)&g_crc_stub_sfrs)
#undef CRC
#define CRC ((__IO CRC_SFRS_t *)&g_crc_stub_sfrs)

/*===========================================================================*
 * __IO qualifier (volatile in real SDK)
 *===========================================================================*/
#ifndef __IO
   #define __IO volatile
#endif
