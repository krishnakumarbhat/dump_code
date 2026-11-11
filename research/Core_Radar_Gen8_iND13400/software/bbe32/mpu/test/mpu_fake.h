/*===========================================================================*/
/**
 * @file mpu_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock declarations for mpu.c unit testing.
 */
/*==========================================================================*/
#ifndef MPU_FAKE_H_
#define MPU_FAKE_H_

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* ---------- Stub Xtensa HAL types and constants ---------- */
   typedef uint32_t uint32;
   typedef uint8_t uint8;

#define XTHAL_SUCCESS (0)
#define XTHAL_INVALID (-1)

   /* Stub MPU entry structure - matches real xthal_MPU_entry field layout */
   struct xthal_MPU_entry
   {
      uint32_t as; /* virtual address / status word */
      uint32_t at; /* attribute word (access rights + memory type) */
   };

#define XCHAL_MPU_ENTRIES (14) /* must be >= the number of entries in Mpu_Initialize's mpumap[] (14) */

/* Address stubs */
#define SYSMEM0_VIEW0_START_ADDR          (0x00800000U)
#define SYSMEM0_VIEW0_END_ADDR            (0x00900000U)
#define SYSMEM0_VIEW1_START_ADDR          (0x00A00000U)
#define SYSMEM1_VIEW0_START_ADDR          (0x00B00000U)
#define SYSMEM1_SHARED                    (0x00C00000U)
#define SYSMEM1_VIEW1_START_ADDR          (0x00D00000U)
#define BBE_DRAM0_START_ADDR              (0x00E00000U)
#define BBE_DRAM1_START_ADDR              (0x00F00000U)
#define BBE_IRAM_START_ADDR               (0x01000000U)
#define UNUSED_POST_BBE_MEM               (0x01100000U)
#define PERIPHERAL_START_ADDR             (0x01200000U)
#define UNUSED_POST_PERIPHERAL_START_ADDR (0x01300000U)

/* Memory access rights stubs */
#define XTHAL_AR_NONE   (0x0U)
#define XTHAL_AR_RWXrwx (0x1U)
#define XTHAL_AR_RWrw   (0x2U)
#define XTHAL_AR_RXrx   (0x3U)

/* Memory type stubs */
#define XTHAL_MEM_DEVICE        (0x0U)
#define XTHAL_MEM_WRITEBACK     (0x1U)
#define XTHAL_MEM_NON_CACHEABLE (0x2U)

/* MPU entry macro stub */
#define XTHAL_MPU_ENTRY(vaddr, valid, rights, type)                                                                               \
   {                                                                                                                              \
      (uint32_t)(vaddr), ((uint32_t)(rights) | ((uint32_t)(type) << 8U))                                                          \
   }

   /* Fake HAL functions */
   DECLARE_FAKE_VALUE_FUNC(int32_t, xthal_read_map, struct xthal_MPU_entry *);
   DECLARE_FAKE_VOID_FUNC(xthal_write_map, const struct xthal_MPU_entry *, uint32_t);
   DECLARE_FAKE_VALUE_FUNC(int32_t, xthal_check_map, const struct xthal_MPU_entry *, uint32_t);

#define FFF_FAKES_MPU_LIST(op)                                                                                                    \
   op(xthal_read_map);                                                                                                            \
   op(xthal_write_map);                                                                                                           \
   op(xthal_check_map)

#ifdef __cplusplus
}
#endif

#endif /* MPU_FAKE_H_ */
