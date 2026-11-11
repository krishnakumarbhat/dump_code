/**
 * @file performance_monitor_ifc.c
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
 * Functions for performance monitor wrapper definitions and implementations.
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
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "performance_monitor_ifc.h"
#include <string.h>

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /* ========================================================================== */
   /*                              Macros                                        */
   /* ========================================================================== */

   /* ========================================================================== */
   /*                         Type Definitions                                   */
   /* ========================================================================== */
   typedef struct Cache_Counters_Tag
   {
      uint32_t cache_hit_count;
      uint32_t cache_miss_count;
      uint32_t cache_hit_count_max;
      uint32_t cache_miss_count_max;
      uint32_t cache_hit_count_prev;
      uint32_t cache_miss_count_prev;
   } Cache_Counters_T;

   /* ========================================================================== */
   /*                            Global Variables                                */
   /* ========================================================================== */
   Cache_Counters_T __attribute__((section(".sram0.bss"))) I_Cache_Counters = {0};
   Cache_Counters_T __attribute__((section(".sram0.bss"))) D_Cache_Counters = {0};

   /*===========================================================================*
    * Local Function Prototypes
    *===========================================================================*/

   /*===========================================================================*
    * Static function Definitions
    *===========================================================================*/
   /**
    *  @b Description
    *  @n
    *      Update cache counters and max values.
    *
    *  @param[inout] cache_ptr Pointer to cache counters structure
    *  @param[in] cache_hit_cnt Cache hit count value
    *  @param[in] cache_miss_cnt Cache miss count value
    *
    *  @retval
    *      N/A
    */
   static void Update_Cache_Counters(Cache_Counters_T *cache_ptr, uint32_t cache_hit_count, uint32_t cache_miss_count)
   {
      cache_ptr->cache_hit_count  = cache_hit_count - cache_ptr->cache_hit_count_prev;
      cache_ptr->cache_miss_count = cache_miss_count - cache_ptr->cache_miss_count_prev;

      cache_ptr->cache_hit_count_max  = MAX(cache_ptr->cache_hit_count, cache_ptr->cache_hit_count_max);
      cache_ptr->cache_miss_count_max = MAX(cache_ptr->cache_miss_count, cache_ptr->cache_miss_count_max);

      cache_ptr->cache_hit_count_prev  = cache_hit_count;
      cache_ptr->cache_miss_count_prev = cache_miss_count;
   }

   /*===========================================================================*
    * Global function Definitions
    *===========================================================================*/
   /**
    *  @b Description
    *  @n
    *      Initialize the performance monitor info.
    *
    *  @retval
    *      N/A
    */
   void Initialize_Perfmon_Info(void)
   {
      memset(&D_Cache_Counters, 0, sizeof(D_Cache_Counters));
      memset(&I_Cache_Counters, 0, sizeof(I_Cache_Counters));
      PerfMon_Helpers_ICache_Counter_Init();
      PerfMon_Helpers_DCache_Counter_Init();
   }

   /**
    *  @b Description
    *  @n
    *      Update cache counters and max values.
    *
    *  @param[inout] dcache_ptr Pointer to the IPC data cache info structure
    *  @param[inout] icache_ptr Pointer to the IPC instruction cache info structure
    *
    *  @retval
    *      N/A
    */
   void Update_IPC_Perfmon_Info(BBE_Cache_Info_T *dcache_ptr, BBE_Cache_Info_T *icache_ptr)
   {
      if ((dcache_ptr != NULL) && (icache_ptr != NULL))
      {
         Update_Cache_Counters(&D_Cache_Counters, PerfMon_Helpers_Get_DCache_Hit_Counter(),
                               PerfMon_Helpers_Get_DCache_Miss_Counter());
         Update_Cache_Counters(&I_Cache_Counters, PerfMon_Helpers_Get_ICache_Hit_Counter(),
                               PerfMon_Helpers_Get_ICache_Miss_Counter());

         dcache_ptr->cache_hit_count      = D_Cache_Counters.cache_hit_count;
         dcache_ptr->cache_miss_count     = D_Cache_Counters.cache_miss_count;
         dcache_ptr->cache_hit_count_max  = D_Cache_Counters.cache_hit_count_max;
         dcache_ptr->cache_miss_count_max = D_Cache_Counters.cache_miss_count_max;

         icache_ptr->cache_hit_count      = I_Cache_Counters.cache_hit_count;
         icache_ptr->cache_miss_count     = I_Cache_Counters.cache_miss_count;
         icache_ptr->cache_hit_count_max  = I_Cache_Counters.cache_hit_count_max;
         icache_ptr->cache_miss_count_max = I_Cache_Counters.cache_miss_count_max;
      }
   }

#ifdef __cplusplus
}
#endif /* __cplusplus */
