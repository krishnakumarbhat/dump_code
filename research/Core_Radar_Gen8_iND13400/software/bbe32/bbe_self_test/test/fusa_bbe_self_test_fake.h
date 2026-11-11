/*===========================================================================*/
/**
 * @file fusa_bbe_self_test_fake.h
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
 * Fake/Mock declarations for fusa_bbe_self_test unit testing.
 */
/*==========================================================================*/
#ifndef FUSA_BBE_SELF_TEST_FAKE_H_
#define FUSA_BBE_SELF_TEST_FAKE_H_

/* Block real STL header to prevent conflicting xtstl_* declarations */
#define _stl_utils_h_

/* Block real mem_pool.h to prevent conflicting type definitions */
#define MEM_POOL_H

#include "fff.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* ---------- Stub types not available on unit test host ---------- */
   typedef uint32_t uint32;
   typedef uint8_t uint8;

   /* Stub BBE STL function prototypes */
   typedef uint32_t xtstl_dram_prot_mem_type;
#define STL_PIF_WIDTH    0x00000080U
#define NUM_SUBROUTINE   14U
#define MPU_TEST_ADDRESS 0x60000000U

#define XTSTL_PASS            0x50415353U
#define XTSTL_FAIL            0x4641494CU
#define XTSTL_DRAM0_BUF_BYTES 128U
#define XTSTL_DRAM1_BUF_BYTES 128U

   /* Host test address map used by range/alignment checks in fusa_bbe_self_test.c */
#define SYSMEM0_VIEW0_START_ADDR ((uint64_t)0x82000000ULL)
#define BBE_DRAM0_START_ADDR     ((uint64_t)0x84000000ULL)
#define BBE_DRAM1_START_ADDR     ((uint64_t)0x86000000ULL)
#define BBE_IRAM_START_ADDR      ((uint64_t)0x88000000ULL)

   /* STL functions — use int return type to match real stl_utils.h */
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_arstall);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_dram_prot, uint32_t *, uint32_t);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_dsp_bbe32_all_noDspOpts, uint32_t);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_er);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_externint, uint32_t *, uint32_t);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_instfetch);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_iram0_l32r);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_loadstore, uint32_t *);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_mpu);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_mpu_entry, uint32_t *);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_regfile_loadstore, uint32_t *);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_sr);
   DECLARE_FAKE_VALUE_FUNC(int, xtstl_win_rot);

   /* Memory pool types (matching real mem_pool.h field names) */
   typedef enum Memory_Pool_Return_Tag
   {
      MEM_POOL_SUCCESS = 0u,
      MEM_POOL_FAILURE = 1u,
   } Memory_Pool_Return_T;

   typedef struct Mem_Pool_Tag
   {
      uint8_t *base_addr;
      uint32_t size;
      uint32_t max_size;
   } Mem_Pool_T;

   DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Alloc, Mem_Pool_T *, uint32_t, void **);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Timestamp);
   DECLARE_FAKE_VOID_FUNC(BBE_Helpers_Trigger_Watchdog);

   /* vector_clear stub (real one uses Xtensa SIMD intrinsics) */
   static inline uint32_t vector_clear(void *dest, size_t bytes)
   {
      if (dest != NULL)
      {
         memset(dest, 0, bytes);
      }
      return 0U;
   }

#define FFF_FAKES_FUSA_BBE_SELF_TEST_LIST(op)                                                                                     \
   op(xtstl_arstall);                                                                                                             \
   op(xtstl_dram_prot);                                                                                                           \
   op(xtstl_dsp_bbe32_all_noDspOpts);                                                                                             \
   op(xtstl_er);                                                                                                                  \
   op(xtstl_externint);                                                                                                           \
   op(xtstl_instfetch);                                                                                                           \
   op(xtstl_iram0_l32r);                                                                                                          \
   op(xtstl_loadstore);                                                                                                           \
   op(xtstl_mpu);                                                                                                                 \
   op(xtstl_mpu_entry);                                                                                                           \
   op(xtstl_regfile_loadstore);                                                                                                   \
   op(xtstl_sr);                                                                                                                  \
   op(xtstl_win_rot);                                                                                                             \
   op(Mem_Pool_Alloc);                                                                                                            \
   op(Timing_Helpers_Get_Timestamp);                                                                                              \
   op(BBE_Helpers_Trigger_Watchdog)

#ifdef __cplusplus
}
#endif

#endif /* FUSA_BBE_SELF_TEST_FAKE_H_ */
