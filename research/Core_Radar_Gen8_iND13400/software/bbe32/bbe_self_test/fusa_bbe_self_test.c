/**
 * @file fusa_bbe_self_test.c
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fusa BBE Self Test Implementation.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "fusa_bbe_self_test.h"
#include "api/timing_helpers.h"
#include "main_application.h"
#include "stl_utils.h"
#include <stdint.h>
/* ========================================================================== */
/*                         Xtensa Include Files                              */
/* ========================================================================== */
#ifdef __XTENSA__
   #include "api/bbe_helpers.h"

extern uint64_t __SYSMEM0_VIEW0_START_ADDR;
extern uint64_t __BBE_DRAM0_START_ADDR;
extern uint64_t __BBE_DRAM1_START_ADDR;
extern uint64_t __BBE_IRAM_START_ADDR;

   #define SYSMEM0_VIEW0_START_ADDR ((const uint64_t)(&(__SYSMEM0_VIEW0_START_ADDR)))
   #define BBE_DRAM0_START_ADDR     ((const uint64_t)(&(__BBE_DRAM0_START_ADDR)))
   #define BBE_DRAM1_START_ADDR     ((const uint64_t)(&(__BBE_DRAM1_START_ADDR)))
   #define BBE_IRAM_START_ADDR      ((const uint64_t)(&(__BBE_IRAM_START_ADDR)))
#endif
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* Can define this to output timing info for each step */
//#define STL_SUBROUTINE_PROFILE_STAGES

/** @brief PIF interface width in bytes */
#define STL_PIF_WIDTH 0x00000080U

/** @brief Total number of STL test routines */
#define NUM_SUBROUTINE 14U

/** @brief Unmapped address for MPU fault test */
#define MPU_TEST_ADDRESS 0x60000000U

#define FUSA_BBE_DRAM0_START_ADDR BBE_DRAM0_START_ADDR
#define FUSA_BBE_DRAM0_END_ADDR   BBE_DRAM1_START_ADDR
#define FUSA_BBE_DRAM1_START_ADDR BBE_DRAM1_START_ADDR
#define FUSA_BBE_DRAM1_END_ADDR   BBE_IRAM_START_ADDR
#define FUSA_BBE_SRAM_START_ADDR  SYSMEM0_VIEW0_START_ADDR
#define FUSA_BBE_SRAM_END_ADDR    BBE_DRAM0_START_ADDR
#define FUSA_BBE_ALIGNMENT_BYTES  128U

/**
 * @brief Valid test subroutines mask for pass/fail determination
 * @details Mask matches which tests actually execute:
 *          - 0x3FFFU (all 14 tests) when profiling disabled
 *          - 0x3FEFU (skip bit 4) when profiling enabled, as xtstl_er() test is known to fail
 */
#ifndef ENABLE_PROFILE_TIMING_OUTPUTS
   #define VALID_TEST_BITS (0x3FFFU)
#else
   #define VALID_TEST_BITS (0x3FEFU)
#endif

#ifdef STL_SUBROUTINE_PROFILE_STAGES
volatile uint32_t STL_Subroutine_Execute_Time[NUM_SUBROUTINE] = {0};

   #define UPDATE_PROFILE_INFO(x)                                                                                                 \
      do                                                                                                                          \
      {                                                                                                                           \
         STL_Subroutine_Execute_Time[x] = (Timing_Helpers_Get_Timestamp() - start_time);                                          \
         start_time                     = Timing_Helpers_Get_Timestamp();                                                         \
      } while (0)

   #define INIT_PROFILE_INFO() uint32_t start_time = Timing_Helpers_Get_Timestamp()

#else
   #define UPDATE_PROFILE_INFO(x)                                                                                                 \
      do                                                                                                                          \
      {                                                                                                                           \
      } while (0)
   #define INIT_PROFILE_INFO()                                                                                                    \
      do                                                                                                                          \
      {                                                                                                                           \
      } while (0)
#endif

/* ========================================================================== */
/*                             Global Variables                               */
/* ========================================================================== */

/**
 * @brief Test buffer for DRAM1 ECC protection validation
 * @details Aligned to buffer size for xtstl_dram_prot() requirements
 */
uint32_t *Dram1_Test_Buf_Ptr = NULL;
/**
 * @brief Test buffer for system RAM validation
 * @details Used for external interrupt and PIF interface testing
 */
uint32_t *Sysram_Test_Buf_Ptr = NULL;
/**
 * @brief Indices for each self-test subroutine and error bit positions
 * Improves readability and maintainability by replacing magic numbers
 */
typedef enum
{
   FUSA_BBE_SELFTEST_ARSTALL = 0,
   FUSA_BBE_SELFTEST_DRAM1,
   FUSA_BBE_SELFTEST_DRAM0,
   FUSA_BBE_SELFTEST_DSP_BBE32,
   FUSA_BBE_SELFTEST_ER,
   FUSA_BBE_SELFTEST_EXTERNINT,
   FUSA_BBE_SELFTEST_INSTFETCH,
   FUSA_BBE_SELFTEST_IRAM0_L32R,
   FUSA_BBE_SELFTEST_LOADSTORE,
   FUSA_BBE_SELFTEST_MPU,
   FUSA_BBE_SELFTEST_MPU_ENTRY,
   FUSA_BBE_SELFTEST_REGFILE_LOADSTORE,
   FUSA_BBE_SELFTEST_SR,
   FUSA_BBE_SELFTEST_WIN_ROT,
   FUSA_BBE_SELFTEST_NUM_ROUTINES,
   // Error Bit Positions (for buffer/range checks)
   FUSA_BBE_ERRBIT_DRAM0_RANGE = 14U,
   FUSA_BBE_ERRBIT_DRAM1_RANGE = 15U,
   FUSA_BBE_ERRBIT_SRAM_RANGE  = 16U,
   FUSA_BBE_ERRBIT_DRAM0_ALIGN = 17U,
   FUSA_BBE_ERRBIT_DRAM1_ALIGN = 18U,
   FUSA_BBE_ERRBIT_SRAM_ALIGN  = 19U
} FusaBbeSelfTestRoutineIdx;

// ---- Function Declarations ----
static void Fusa_BBE_Check_Buffer(uintptr_t buf_addr, uint32_t range_start, uint32_t range_end, int range_bit, int align_bit,
                                  uint32_t *error_code);

/* ========================================================================== */
/*                          Function Definitions                             */
/* ========================================================================== */

/**
 *  @b Description
 *  @n
 *       Executes the Fusa BBE self-test .
 *
 * This function performs the Built-In Self-Test (BIST) for the BBE
 * to verify its functional safety and integrity. It runs a series of diagnostic checks
 * and returns the result indicating whether any errors were detected during the self-test.
 *
 * @retval
 *  uint32_t
 *         Returns the error status of the self-test execution.
 *         Possible values:
 *           - 0: No error detected.
 *           - non-zero: Error detected during self-test.
 *          Each bit in the returned value corresponds to a specific subroutine failure.
 *            -bit 0: xtstl_arstall failure | bit 1: xtstl_dram_prot failure for DRAM1 | bit 2: xtstl_dram_prot failure for DRAM0
 *            -bit 3: xtstl_dsp_bbe32_all_noDspOpts failure | bit 4: xtstl_er failure | bit 5: xtstl_externint failure | bit 6:
 * xtstl_instfetch failure -bit 7: xtstl_iram0_l32r failure | bit 8: xtstl_loadstore failure | bit 9: xtstl_mpu failure | bit 10:
 * xtstl_mpu_entry failure -bit 11: xtstl_regfile_loadstore failure | bit 12: xtstl_sr failure | bit 13: xtstl_win_rot failure.
 * @note This function should be called during system startup or as part of periodic
 *       safety monitoring routines.
 */
uint32_t Fusa_BBE_Check_Execute(void)
{
   uint32_t sr_ret_val[NUM_SUBROUTINE];

   /**
    * @brief Test buffer for DRAM0 ECC protection validation
    * @details Aligned to buffer size for xtstl_dram_prot() & xtstl_regfile_loadstore() requirements
    */
   uint32_t dram0_test_buf[(XTSTL_DRAM0_BUF_BYTES / sizeof(uint32_t))] __attribute__((aligned(XTSTL_DRAM0_BUF_BYTES)));
   /** @brief L32EX/S32EX operation enable flag */
   uint32_t externint_ex_ops_en = 1U;

   /** @brief Data index for DSP BBE32 test */
   uint32_t dataIndex = 0U;

   /** @brief Pointer to dummy memory location for MPU operations */
   uint32_t *mpu_dummy_pointer = (uint32_t *)MPU_TEST_ADDRESS;

   /* Initialize all return values to PASS */
   for (uint8_t i = 0U; i < NUM_SUBROUTINE; i++)
   {
      sr_ret_val[i] = XTSTL_PASS;
   }
   /* Clear test buffers to ensure clean state */
   vector_clear(dram0_test_buf, XTSTL_DRAM0_BUF_BYTES);
   vector_clear(Dram1_Test_Buf_Ptr, XTSTL_DRAM1_BUF_BYTES);
   vector_clear(Sysram_Test_Buf_Ptr, STL_PIF_WIDTH);

   /* Initialize the fusa_error_code to 0 to indicate no error at the start of the test */
   uint32_t fusa_error_code = 0U;

   INIT_PROFILE_INFO();

   sr_ret_val[FUSA_BBE_SELFTEST_ARSTALL] = xtstl_arstall();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_ARSTALL);

   sr_ret_val[FUSA_BBE_SELFTEST_DRAM1] = xtstl_dram_prot(Dram1_Test_Buf_Ptr, XTSTL_DRAM1_BUF_BYTES);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_DRAM1);

   sr_ret_val[FUSA_BBE_SELFTEST_DRAM0] = xtstl_dram_prot(dram0_test_buf, XTSTL_DRAM0_BUF_BYTES);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_DRAM0);

   sr_ret_val[FUSA_BBE_SELFTEST_DSP_BBE32] = xtstl_dsp_bbe32_all_noDspOpts(dataIndex);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_DSP_BBE32);

   /** The function "xtstl_er" is the function that checks external registers (ERs) example
    * Debug modules, Performance counters, Other external logic blocks,  performs a non-intrusive test on one ER
    * If the values match, the test passes. If they don’t, it means there might be a fault in the ERI data path. */

   sr_ret_val[FUSA_BBE_SELFTEST_ER] = xtstl_er();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_ER);

   sr_ret_val[FUSA_BBE_SELFTEST_EXTERNINT] = xtstl_externint(Sysram_Test_Buf_Ptr, externint_ex_ops_en);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_EXTERNINT);

   sr_ret_val[FUSA_BBE_SELFTEST_INSTFETCH] = xtstl_instfetch();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_INSTFETCH);

   sr_ret_val[FUSA_BBE_SELFTEST_IRAM0_L32R] = xtstl_iram0_l32r();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_IRAM0_L32R);

   sr_ret_val[FUSA_BBE_SELFTEST_LOADSTORE] = xtstl_loadstore(dram0_test_buf);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_LOADSTORE);

   sr_ret_val[FUSA_BBE_SELFTEST_MPU] = xtstl_mpu();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_MPU);

   sr_ret_val[FUSA_BBE_SELFTEST_MPU_ENTRY] = xtstl_mpu_entry(mpu_dummy_pointer);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_MPU_ENTRY);

   sr_ret_val[FUSA_BBE_SELFTEST_REGFILE_LOADSTORE] = xtstl_regfile_loadstore(dram0_test_buf);
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_REGFILE_LOADSTORE);

   sr_ret_val[FUSA_BBE_SELFTEST_SR] = xtstl_sr();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_SR);

   sr_ret_val[FUSA_BBE_SELFTEST_WIN_ROT] = xtstl_win_rot();
   UPDATE_PROFILE_INFO(FUSA_BBE_SELFTEST_WIN_ROT);

   Fusa_BBE_Check_Buffer((uintptr_t)Dram1_Test_Buf_Ptr, FUSA_BBE_DRAM1_START_ADDR, FUSA_BBE_DRAM1_END_ADDR,
                         FUSA_BBE_ERRBIT_DRAM1_RANGE, FUSA_BBE_ERRBIT_DRAM1_ALIGN, &fusa_error_code);

   Fusa_BBE_Check_Buffer((uintptr_t)dram0_test_buf, FUSA_BBE_DRAM0_START_ADDR, FUSA_BBE_DRAM0_END_ADDR,
                         FUSA_BBE_ERRBIT_DRAM0_RANGE, FUSA_BBE_ERRBIT_DRAM0_ALIGN, &fusa_error_code);

   Fusa_BBE_Check_Buffer((uintptr_t)Sysram_Test_Buf_Ptr, FUSA_BBE_SRAM_START_ADDR, FUSA_BBE_SRAM_END_ADDR,
                         FUSA_BBE_ERRBIT_SRAM_RANGE, FUSA_BBE_ERRBIT_SRAM_ALIGN, &fusa_error_code);
   /**
    * Iterates through the subroutine results array and checks if each subroutine passed.
    * If any subroutine result is not XTSTL_PASS, sets the corresponding bit in fusa_error_code.
    * Each bit position corresponds to the subroutine index that failed.
    */
   for (uint8_t i = 0U; i < NUM_SUBROUTINE; i++)
   {
      if (XTSTL_PASS != sr_ret_val[i])
      {
         fusa_error_code |= (1 << i);
      }
   }

   return fusa_error_code;
}

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 *  @b Description
 *  @n
 *   Allocate temporary objects to the dram1 and sram1 memory pool
 *
 * @param[in]  mem_pool_dram1 - Pointer to the dram1 memory pool object
 * @param[in]  mem_pool_sram1 - Pointer to the sram1 memory pool object
 *
 * @return true for success, false for failure
 *
 **/
Memory_Pool_Return_T Appl_BBE_Self_Test_Memory_Init(Mem_Pool_T *mem_pool_dram1, Mem_Pool_T *mem_pool_sram1)
{
   Memory_Pool_Return_T ret_val_dram1 = MEM_POOL_FAILURE;
   Memory_Pool_Return_T ret_val_sram1 = MEM_POOL_FAILURE;
   Memory_Pool_Return_T ret_val       = MEM_POOL_FAILURE;

   ret_val_dram1 = Mem_Pool_Alloc(mem_pool_dram1, XTSTL_DRAM1_BUF_BYTES, (void **)&Dram1_Test_Buf_Ptr);
   ret_val_sram1 = Mem_Pool_Alloc(mem_pool_sram1, STL_PIF_WIDTH, (void **)&Sysram_Test_Buf_Ptr);

   if (ret_val_dram1 == MEM_POOL_SUCCESS && ret_val_sram1 == MEM_POOL_SUCCESS)
   {
      ret_val = MEM_POOL_SUCCESS;
   }
   else
   {
      ret_val = MEM_POOL_FAILURE;
   }

   return ret_val;
}

/**
 *  @b Description
 *  @n
 *      Determines BBE self-test pass/fail status by masking result with VALID_TEST_BITS.
 *
 * @param[in]  self_test_result - Raw bitfield from Fusa_BBE_Check_Execute() where each bit represents a test (0=pass, 1=fail).
 *
 * @retval CODED_FALSE - Self-test passed (no valid bits set)
 * @retval CODED_TRUE  - Self-test failed (one or more valid bits set)
 */
uint8_t Update_FUSA_BBE_Self_Test_Fault_Flag(uint32_t self_test_result)
{
   /* Fail-safe: assume error unless proven otherwise */
   uint8_t ret_val = CODED_TRUE;

   if (0U == (self_test_result & VALID_TEST_BITS))
   {
      /* Self-test passed */
      ret_val = CODED_FALSE;
   }
   return ret_val;
}

// ---- Buffer Check Helper ----
/**
 * @brief Checks if a buffer address is within a valid memory range and properly aligned.
 *
 * This helper function validates that the provided buffer address falls within the specified
 * memory range and meets the required alignment. If the address is out of range or misaligned,
 * the corresponding error bits are set in the error code. Used for FUSA BBE self-test routines
 * to ensure test buffers are correctly allocated and safe for hardware access.
 *
 * @param buf_addr     Buffer address to check
 * @param range_start  Start address of valid range
 * @param range_end    End address of valid range
 * @param range_bit    Error bit to set if out of range
 * @param align_bit    Error bit to set if misaligned
 * @param error_code   Pointer to error code variable to update
 */
static void Fusa_BBE_Check_Buffer(uintptr_t buf_addr, uint32_t range_start, uint32_t range_end, int range_bit, int align_bit,
                                  uint32_t *error_code)
{
   if (!(buf_addr >= range_start && buf_addr < range_end))
   {
      *error_code |= (1U << range_bit);
   }
   if (0U != (buf_addr % FUSA_BBE_ALIGNMENT_BYTES))
   {
      *error_code |= (1U << align_bit);
   }
}
