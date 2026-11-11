#ifndef MPU_H
#define MPU_H
/*===========================================================================*/
/**
 * @file mpu.h
 *
 * DSP application memory protection header file
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
/*==========================================================================*/
#ifdef __XTENSA__
   #include "fixmac.h"
   #include <xtensa/tie/xt_bben.h>
   #include <xtensa/xtruntime.h>
#endif /* __XTENSA__ */

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /* ========================================================================== */
   /*                         Exported Variables                                 */
   /* ========================================================================== */
#ifdef __XTENSA__
   extern uint32_t MPU_Entry_Count;
   extern struct xthal_MPU_entry MPU_Map_Readback[XCHAL_MPU_ENTRIES];

   extern uint64_t __SYSMEM0_VIEW0_START_ADDR;
   extern uint64_t __SYSMEM0_VIEW0_END_ADDR;
   extern uint64_t __SYSMEM0_VIEW1_START_ADDR;
   extern uint64_t __SYSMEM1_VIEW0_START_ADDR;
   extern uint64_t __SYSMEM1_SHARED;
   extern uint64_t __SYSMEM1_VIEW1_START_ADDR;
   extern uint64_t __BBE_DRAM0_START_ADDR;
   extern uint64_t __BBE_DRAM1_START_ADDR;
   extern uint64_t __BBE_IRAM_START_ADDR;
   extern uint64_t __UNUSED_POST_BBE_MEM;
   extern uint64_t __PERIPHERAL_START_ADDR;
   extern uint64_t __UNUSED_POST_PERIPHERAL_START_ADDR;

   #define SYSMEM0_VIEW0_START_ADDR          ((const uint64_t)(&(__SYSMEM0_VIEW0_START_ADDR)))
   #define SYSMEM0_VIEW0_END_ADDR            ((const uint64_t)(&(__SYSMEM0_VIEW0_END_ADDR)))
   #define SYSMEM0_VIEW1_START_ADDR          ((const uint64_t)(&(__SYSMEM0_VIEW1_START_ADDR)))
   #define SYSMEM1_VIEW0_START_ADDR          ((const uint64_t)(&(__SYSMEM1_VIEW0_START_ADDR)))
   #define SYSMEM1_SHARED                    ((const uint64_t)(&(__SYSMEM1_SHARED)))
   #define SYSMEM1_VIEW1_START_ADDR          ((const uint64_t)(&(__SYSMEM1_VIEW1_START_ADDR)))
   #define BBE_DRAM0_START_ADDR              ((const uint64_t)(&(__BBE_DRAM0_START_ADDR)))
   #define BBE_DRAM1_START_ADDR              ((const uint64_t)(&(__BBE_DRAM1_START_ADDR)))
   #define BBE_IRAM_START_ADDR               ((const uint64_t)(&(__BBE_IRAM_START_ADDR)))
   #define UNUSED_POST_BBE_MEM               ((const uint64_t)(&(__UNUSED_POST_BBE_MEM)))
   #define PERIPHERAL_START_ADDR             ((const uint64_t)(&(__PERIPHERAL_START_ADDR)))
   #define UNUSED_POST_PERIPHERAL_START_ADDR ((const uint64_t)(&(__UNUSED_POST_PERIPHERAL_START_ADDR)))
#endif /* __XTENSA__ */

   /* ========================================================================== */
   /*                      Function Declarations                                 */
   /* ========================================================================== */

   extern void Read_Mpu_Configuration(void);
   extern bool Mpu_Initialize(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
