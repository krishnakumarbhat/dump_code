/**
 * @file mpu_r52.c
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
 * Main DSP application state machine implementation.
 *
 * @section ABBR ABBREVIATIONS:
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *   - Requirements Document(s):
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 * @section DFS DEVIATIONS FROM STANDARDS:
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "mpu_r52.h"

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
/* Linker-provided symbols (addresses are their values) */
extern const uint32_t __R52_TCMA_NULL_GUARD_BASE__[];
extern const uint32_t __R52_TCMA_NULL_GUARD_LIMIT__[];
extern const uint32_t __R52_TCMA_BASE__[];
extern const uint32_t __R52_TCMA_LIMIT__[];
extern const uint32_t __R52_TCMBC_BASE__[];
extern const uint32_t __R52_TCMBC_LIMIT__[];
extern const uint32_t __SYSMEM0_R52_SYSMEM_BASE__[];
extern const uint32_t __SYSMEM0_R52_SYSMEM_LIMIT__[];

extern const uint32_t __SYSMEM0_R52_DATA_BASE__[];
extern const uint32_t __SYSMEM0_R52_DATA_LIMIT__[];

extern const uint32_t __ARTIE_MEM_BASE__[];
extern const uint32_t __ARTIE_MEM_LIMIT__[];

extern const uint32_t __SYSMEM1_R52_DATA_BASE__[];
extern const uint32_t __SYSMEM1_R52_DATA_LIMIT__[];

/* MAIR encodings you used:
   - Normal Non-Cacheable   = 0x44 (Outer=NC=0b0100, Inner=NC=0b0100)
   - Device-nGnRE           = 0x04
   - Normal Write-Back NT   = 0xFF (Outer=WB-NT=0b1111, Inner=WB-NT=0b1111)
*/
#define MAIR_ATTR_NORMAL_NC    0x44u
#define MAIR_ATTR_DEVICE_nGnRE 0x04u
#define MAIR_ATTR_NORMAL_WB_NT 0xFFu  /* Normal Memory, Outer/Inner Write-Back non-transient (R=1,W=1) */

/* ====== Packing (32-byte granularity) ====== */
#define MPU_ADDR_GRAN_MASK (~0x3Fu)
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

static void __attribute((section(".StartupCommon"))) Enable_Mpu_El1(void);
bool __attribute((section(".StartupCommon"))) Mpu_Program_Region_Params(uint8_t region, uint32_t base, uint32_t end_incl,
                                             uint8_t sh, uint8_t ap, uint8_t xn,
                                             uint8_t attridx, bool enable);
void __attribute((section(".StartupCommon"))) Mpu_Dsb_Isb(void);

/*===========================================================================*
 * Global MPU Region Configuration Table
 *===========================================================================*/
const Mpu_Region_Config_t mpu_regions[] = {
   /* Region 0: R52_TCM (B/C) — from linker */
   {.base_sym = __R52_TCMBC_BASE__,                  .limit_sym = __R52_TCMBC_LIMIT__,           .region = 0, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RW_USER_RW, .xn = 0, .attridx = 0, .enable = true, .padding = {0, 0}},
   /* Region 1: NULL guard page — no write/execute access to prevent NULL pointer usage */
   {.base_sym = __R52_TCMA_NULL_GUARD_BASE__,         .limit_sym = __R52_TCMA_NULL_GUARD_LIMIT__,  .region = 1, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RO_USER_NO, .xn = 1, .attridx = 0, .enable = true, .padding = {0, 0}},
   /* Region 2: TCM A (0x00000040..0x0000FFFF) — after null guard */
   {.base_sym = __R52_TCMA_BASE__,                   .limit_sym = __R52_TCMA_LIMIT__,            .region = 2, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RW_USER_RW, .xn = 0, .attridx = 0, .enable = true, .padding = {0, 0}},
   /* Region 3: SysMem0 (R52 Code Space) — from linker */
   {.base_sym = __SYSMEM0_R52_SYSMEM_BASE__,           .limit_sym = __SYSMEM0_R52_SYSMEM_LIMIT__,    .region = 3, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RW_USER_RW, .xn = 0, .attridx = 0, .enable = true, .padding = {0, 0}},
   /* Region 4:  SysMem0 (R52 Data/bss Space) — from linker*/
   {.base_sym = __SYSMEM0_R52_DATA_BASE__,        .limit_sym = __SYSMEM0_R52_DATA_LIMIT__,  .region = 4, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RW_USER_RW, .xn = 1, .attridx = 0, .enable = true, .padding = {0, 0}},
   /* Region 5:  Artie memory region - from linker*/
   {.base_sym = __ARTIE_MEM_BASE__,        .limit_sym = __ARTIE_MEM_LIMIT__,  .region = 5, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RW_USER_RW, .xn = 1, .attridx = 0, .enable = true, .padding = {0, 0}},
   /* Region 6:  sysmem 1 R52 regions */
   {.base_sym = __SYSMEM1_R52_DATA_BASE__,        .limit_sym = __SYSMEM1_R52_DATA_LIMIT__,  .region = 6, .sh = MPU_SH_NON_SHAREABLE, .ap = MPU_AP_PRIV_RW_USER_RW, .xn = 1, .attridx = 0, .enable = true, .padding = {0, 0}}

};

const uint32_t mpu_num_regions = sizeof(mpu_regions) / sizeof(mpu_regions[0]);

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

static  void __attribute((section(".StartupCommon"))) Mpu_Select_Region(uint8_t region) { __asm volatile("mcr p15,0,%0,c6,c2,1"::"r"((uint32_t)region):"memory"); }
static  void __attribute((section(".StartupCommon"))) Mpu_Write_Prbar(uint32_t v) { __asm volatile("mcr p15,0,%0,c6,c3,0"::"r"(v):"memory"); }
static  void __attribute((section(".StartupCommon"))) Mpu_write_prlar(uint32_t v) { __asm volatile("mcr p15,0,%0,c6,c3,1"::"r"(v):"memory"); }
static  uint32_t __attribute((section(".StartupCommon"))) Mpu_Read_Prlar(void){ uint32_t v; __asm volatile("mrc p15,0,%0,c6,c3,1":"=r"(v)::"memory"); return v; }

/* Convenience: convert symbol to 32-bit value */
static uint32_t __attribute((section(".StartupCommon"))) sym32(const void *s)
{
   return (uint32_t)(uintptr_t)s;
}
static void __attribute((section(".StartupCommon"))) Write_Mair0(uint32_t v)
{
   __asm volatile("mcr p15,0,%0,c10,c2,0" ::"r"(v) : "memory");
}
static void __attribute((section(".StartupCommon"))) Write_Mair1(uint32_t v)
{
   __asm volatile("mcr p15,0,%0,c10,c2,1" ::"r"(v) : "memory");
}


void __attribute((section(".StartupCommon"))) Mpu_Dsb_Isb(void)
{
    __asm volatile("dsb\nisb\n" ::: "memory");
}

static  uint32_t __attribute((section(".StartupCommon"))) Mpu_Make_PRBAR(uint32_t base, uint8_t sh, uint8_t ap, uint8_t xn){
    return (base & MPU_ADDR_GRAN_MASK) | ((uint32_t)(sh&3u)<<3) | ((uint32_t)(ap&3u)<<1) | ((uint32_t)(xn&1u));
}
static  uint32_t __attribute((section(".StartupCommon"))) Mpu_Make_PRLAR(uint32_t limit, uint8_t attridx, bool en){
    return (limit & MPU_ADDR_GRAN_MASK) | ((uint32_t)(attridx & 0xFu)<<1) | (en ? 1u : 0u);
}
static  void __attribute((section(".StartupCommon"))) Mpu_Program_Region_Raw(uint8_t region, uint32_t prbar, uint32_t prlar){
    Mpu_Dsb_Isb();
    Mpu_Select_Region(region);
    uint32_t l = Mpu_Read_Prlar(); l &= ~1u; Mpu_write_prlar(l); /* disable region */
    Mpu_Write_Prbar(prbar);
    Mpu_write_prlar(prlar);
    Mpu_Dsb_Isb();
}
static  bool __attribute((section(".StartupCommon"))) Mpu_Check_Range(uint32_t base, uint32_t end_incl){
    if (end_incl < base) return false;
    return ((end_incl - base) + 1u) >= 32u;
}
 bool __attribute((section(".StartupCommon"))) Mpu_Program_Region_Params(uint8_t region, uint32_t base, uint32_t end_incl,
                                             uint8_t sh, uint8_t ap, uint8_t xn,
                                             uint8_t attridx, bool enable){
    if (!Mpu_Check_Range(base, end_incl)) return false;
    uint32_t prbar = Mpu_Make_PRBAR(base, sh, ap, xn);
    uint32_t prlar = Mpu_Make_PRLAR(end_incl, attridx, enable);
    Mpu_Program_Region_Raw(region, prbar, prlar);
    return true;
}

/******************************************************************************
 * Name:  Mpu_Init
 *   Initializes MPU table from linker file
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 ******************************************************************************/
void __attribute((section(".StartupCommon"))) Mpu_Init(void)
{
   /* ==== Program MAIR (matches your current code) ==== */
   /* MAIR0: Attr0 = Normal NC (0x44), Attr1 = Normal WB-NT (0xFF) */
   uint32_t mair0 = ((uint32_t)MAIR_ATTR_NORMAL_WB_NT << 8) | (uint32_t)MAIR_ATTR_NORMAL_NC;
   Write_Mair0(mair0);

   /* MAIR1: Attr4 = Device-nGnRE (0x04)*/
   uint32_t mair1 = MAIR_ATTR_DEVICE_nGnRE; /* A Attr4=0x04 */
   Write_Mair1(mair1);
   Mpu_Dsb_Isb();

   /* Program all MPU regions from the configuration table */
   for (uint32_t i = 0; i < mpu_num_regions; i++)
   {
      const Mpu_Region_Config_t *config = &mpu_regions[i];
      uint32_t base  = sym32(config->base_sym);
      uint32_t limit = sym32(config->limit_sym);

      (void)Mpu_Program_Region_Params(
         config->region,
         base,
         limit,
         config->sh,
         config->ap,
         config->xn,
         config->attridx,
         config->enable);
   }

   Enable_Mpu_El1();
}

/******************************************************************************
 * Name:  Enable_Mpu_El1
 *   Enables MPU region
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 ******************************************************************************/
void __attribute((section(".StartupCommon"))) Enable_Mpu_El1(void)
{
   __asm__ volatile("mrc p15, 0, r0, c1, c0, 0    \n" // Read System Control Register
                    "orr r0, r0, #0x01           \n"  // Set M bit to enable MPU
                    "orr r0, r0, #0x02           \n"  // Set A bit to enable alignment fault checking
                    "dsb                         \n"  // Ensure all previous loads/stores have completed
                    "mcr p15, 0, r0, c1, c0, 0   \n"  // Write System Control Register
                    :
                    :
                    : "r0", "memory");
}
