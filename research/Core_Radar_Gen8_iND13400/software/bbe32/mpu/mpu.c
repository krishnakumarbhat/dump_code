/**
 * @file mpu.c
 *
 * DSP application memory protection unit implementation file
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
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
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "mpu.h"

/* ========================================================================== */
/*                         Global Variables                                   */
/* ========================================================================== */
uint32_t MPU_Entry_Count = 0U;
struct xthal_MPU_entry __attribute__((section(".sram0.bss"))) MPU_Map_Readback[XCHAL_MPU_ENTRIES];
/* ========================================================================== */
/*                      Function Declarations                                 */
/* ========================================================================== */
/**
 *  @b Description
 *  @n
 *    Read the existing MPU configuration for sanity check.
 *
 * @return void.
 */
void Read_Mpu_Configuration(void)
{
   int32_t halStatus = xthal_read_map((struct xthal_MPU_entry *)MPU_Map_Readback);
   if (halStatus == XTHAL_SUCCESS)
   {
      uint32_t i = 0;
      for (; i < XCHAL_MPU_ENTRIES; i++)
      {
         MPU_Entry_Count++;
      }
   }
}

/**
 *  @b Description
 *  @n
 *    Write the MPU table.
 *
 * @return void.
 */
bool Mpu_Initialize(void)
{
   int32_t halstatus;
   bool status                           = true;
   const struct xthal_MPU_entry mpumap[] = {
      XTHAL_MPU_ENTRY(0x0, 1, XTHAL_AR_NONE, XTHAL_MEM_DEVICE),                           // unused
      XTHAL_MPU_ENTRY(SYSMEM0_VIEW0_START_ADDR, 1, XTHAL_AR_RWXrwx, XTHAL_MEM_WRITEBACK), // sram0 - view 0
      XTHAL_MPU_ENTRY(SYSMEM0_VIEW0_END_ADDR, 1, XTHAL_AR_RWrw, XTHAL_MEM_WRITEBACK),     // sram1 - view 0
      XTHAL_MPU_ENTRY(SYSMEM0_VIEW1_START_ADDR, 1, XTHAL_AR_NONE, XTHAL_MEM_DEVICE),      // sram0 - view 1-3
      XTHAL_MPU_ENTRY(SYSMEM1_VIEW0_START_ADDR, 1, XTHAL_AR_RWXrwx, XTHAL_MEM_WRITEBACK), // sram1 - view 0
      XTHAL_MPU_ENTRY(SYSMEM1_SHARED, 1, XTHAL_AR_RWrw, XTHAL_MEM_DEVICE),                // sram1 - view 0 , 16k bytes
      XTHAL_MPU_ENTRY(SYSMEM1_VIEW1_START_ADDR, 1, XTHAL_AR_NONE, XTHAL_MEM_DEVICE),      // sram1 - view 1-3
      XTHAL_MPU_ENTRY(BBE_DRAM0_START_ADDR, 1, XTHAL_AR_RWrw, XTHAL_MEM_DEVICE),          // dram0
      XTHAL_MPU_ENTRY(BBE_DRAM1_START_ADDR, 1, XTHAL_AR_RWrw, XTHAL_MEM_DEVICE),          // dram1
#if (defined(ENABLE_SQT_TEST_STUBS)) /*For testing sm 22 enabling write access for IRAM*/
      XTHAL_MPU_ENTRY(BBE_IRAM_START_ADDR, 1, XTHAL_AR_RWXrwx, XTHAL_MEM_DEVICE), // iram0 - ECC test mode
#else
      XTHAL_MPU_ENTRY(BBE_IRAM_START_ADDR, 1, XTHAL_AR_RXrx, XTHAL_MEM_DEVICE), // iram0 - production
#endif
      XTHAL_MPU_ENTRY(UNUSED_POST_BBE_MEM, 1, XTHAL_AR_NONE, XTHAL_MEM_DEVICE),   // unused
      XTHAL_MPU_ENTRY(PERIPHERAL_START_ADDR, 1, XTHAL_AR_RWrw, XTHAL_MEM_DEVICE), // periph
      // TODO: Map crc base address with linker files
      XTHAL_MPU_ENTRY(0x91600000, 1, XTHAL_AR_RWrw, XTHAL_MEM_DEVICE),                        // CRC
      XTHAL_MPU_ENTRY(UNUSED_POST_PERIPHERAL_START_ADDR, 1, XTHAL_AR_NONE, XTHAL_MEM_DEVICE), // unused
   };

   uint32_t mpumap_size = sizeof(mpumap) / sizeof(mpumap[0]);
   struct xthal_MPU_entry mpumap_readback[XCHAL_MPU_ENTRIES];
   /** Should be called first to check the map*/
   halstatus = xthal_check_map(mpumap, mpumap_size);
   if (halstatus == XTHAL_SUCCESS)
   {
      xthal_write_map(mpumap, mpumap_size);
      halstatus = xthal_read_map(mpumap_readback);
      if (halstatus == XTHAL_SUCCESS)
      {
         /** Check the read-back map again */
         halstatus = xthal_check_map(mpumap_readback, mpumap_size);
      }
      else
      {
         /** Check the read-back map again */
         halstatus = xthal_check_map(mpumap_readback, mpumap_size);
         if (halstatus != XTHAL_SUCCESS)
         {
            status = false;
         }
         else
         {
            for (uint8_t i = 1; i < mpumap_size; i++)
            {
               /* Check if the mpu addresses are present in ascending order*/
               if (mpumap_readback[i].as <= mpumap_readback[i - 1].as)
               {
                  status = false;
               }
            }
         }
      }
   }
   else
   {
      status = false;
   }
   return status;
}
