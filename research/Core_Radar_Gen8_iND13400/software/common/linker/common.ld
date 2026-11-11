MEMORY
{
   /* SYSMEM0 Total size is 2MB */

   /* NOTE: MPU configuration in mpu_r52.c automatically reads memory region symbols from this linker file.
    *
    * For R52 at \software\r52\startup\mpu_r52.c:
    * The MPU table uses linker symbols (e.g., __R52_SYSMEM_BASE__, __R52_SYSMEM_LIMIT__) to configure regions,
    * eliminating the need for manual address updates when memory layout changes.
    *
    *
    * MPU Region Mapping:
    * Only mapped memory regions from linker file are used in MPU table. unmapped memory regions(eg: peripherals, gaps)
    * are automatically accessed as Device memory after enabling background regions.
    * All memory regions where any piece of SW that required for R52 is placed, are configured as Normal memory.
    * Required symbols are defined in r52.ld.
    *
    * Note: Origin address of R52 code is changed to start of TCM address to enable LTO build
    * Note: R52_TCMB remapped in boot from 0x00100000 to 0x7FFE0000
    * and   R52_TCMC remapped in boot from 0x00200000 to 0x7FFF0000
    * RETENTION_RAM for NOINIT RAM Boot_Shared_Data 1k allocated at 0x7FFE0000 in boot.ld
    */
#ifdef Enable_PHY_100Mb /* 100Mb PHY configuration */
       /* Satellite CAN */
   R52_TCM (xrw) :ORIGIN = 0x7FFE0400, LENGTH = 0x12C00/*75*/			
   R52_TCM_STACK (xrw) : ORIGIN = 0x7FFF3000, LENGTH = 0xD000/*52*/			
   R52_SYSMEM (xrw) : ORIGIN = 0x80000000, LENGTH = 0xBFC00/*767*/			
   SYSMEM0_TRACKER (xrw) :ORIGIN = 0x800BFC00, LENGTH = 0x5000/*20*/			
   SYSMEM_IPC_D2M  (xrw) :ORIGIN = 0x800C4C00, LENGTH = 0x73C00/*463*/			
   SYSMEM0_DATA_ETH  (xrw) :ORIGIN = 0x80138800, LENGTH = 0x26C00/*155*/			
   SYSMEM0_R52_DATA  (xrw) : ORIGIN = 0x8015F400, LENGTH = 0x94400/*593*/			
   SYSMEM0_R52_QM (xrw) :ORIGIN = 0x801F3800, LENGTH = 0xC800/*50*/			


#else /* 1Gb PHY configuration */
   #ifdef VEH_SOMEIP /*High Det Build*/
      R52_TCM (xrw)        : ORIGIN = 0x7FFE0400, LENGTH = 0x00012C00 /* 75k */
      R52_TCM_STACK (xrw)  : ORIGIN = 0x7FFF3000, LENGTH = 0x0000D000 /* 52k */
      R52_SYSMEM (xrw) : ORIGIN = 0x80000000, LENGTH = 0x00086000 /* 536k */
      SYSMEM0_TRACKER (xrw) : ORIGIN = 0x80086000, LENGTH = 0x00002800 /* 10k */
      SYSMEM_IPC_D2M       (xrw) : ORIGIN = 0x80088800, LENGTH = 0x000D3800 /* 846k */
      SYSMEM0_DATA_ETH     (xrw) : ORIGIN = 0x8015C000, LENGTH = 0x00006400 /* 25k */
      SYSMEM0_R52_DATA     (xrw) : ORIGIN = 0x80162400, LENGTH = 0x00091400 /* 581k */
      SYSMEM0_R52_QM (xrw) : ORIGIN = 0x801F3800, LENGTH = 0x0000C800 /* 50k */
   #else /*all other builds */
      R52_TCM (xrw)        : ORIGIN = 0x7FFE0400, LENGTH = 0x00012C00 /* 75k */
      R52_TCM_STACK (xrw)  : ORIGIN = 0x7FFF3000, LENGTH = 0x0000D000 /* 52k */
      R52_SYSMEM (xrw) : ORIGIN = 0x80000000, LENGTH = 0x000B6000 /* 728k */
      SYSMEM0_TRACKER (xrw) : ORIGIN = 0x800B6000, LENGTH = 0x00041000 /* 260k */
      SYSMEM_IPC_D2M       (xrw) : ORIGIN = 0x800F7000, LENGTH = 0x0007C400 /* 497k */
      SYSMEM0_DATA_ETH     (xrw) : ORIGIN = 0x80173400, LENGTH = 0x00006000 /* 24k */
      SYSMEM0_R52_DATA     (xrw) : ORIGIN = 0x80179400, LENGTH = 0x0007A400 /* 489k */
      SYSMEM0_R52_QM (xrw) : ORIGIN = 0x801F3800, LENGTH = 0x0000C800 /* 50k */
      #endif
#endif

   /*SYSMEM1 Total size is 2MB */
   SYSMEM1_BBE32 (xrw)        : ORIGIN = 0x82000000, LENGTH = 0x001F3580
   SYSMEM1_ENET_PKT (xrw)     : ORIGIN = 0x821F3580, LENGTH = 0x00009800
   SYSMEM_IPC_SHARED (rw)     : ORIGIN = 0x821FCD80, LENGTH = 0x00000280
   SYSMEM_IPC_M2D (rw)        : ORIGIN = 0x821FD000, LENGTH = 0x00003000
/* A2.0.1 hardware with Chandra B0 */
#ifdef TRACKER_DISABLED
   BBE32_DTCM0 (xrw)    : ORIGIN =  0x84020000, LENGTH = 59K /*5KB reseved for F360 Tracker for standalone build*/
#else
   BBE32_DTCM0 (xrw)    : ORIGIN =  0x84020000, LENGTH = 64K
#endif
   BBE32_DTCM1 (xrw)    : ORIGIN =  0x84030000, LENGTH = 64K
   BBE32_ITCM (xrw)     : ORIGIN =  0x84040000, LENGTH = 256K /* ChandraB0 has 256KB DSP IRAM*/
   
   ARTIE_MEM (xrw)      : ORIGIN =  0x91800000, LENGTH = 128K
}

__ILUT_FLASH_START_ADDRESS = 0x0006F000;
__ILUT_FLASH_BLOCK_SIZE = 0x00001000;

__SPC_FLASH_START_ADDRESS = 0x0006E000;
__SPC_FLASH_BLOCK_SIZE = 0x00001000;

__USC_FLASH_START_ADDRESS = 0x00070000;
__USC_FLASH_BLOCK_SIZE = 0x00010000;

__SMC_FLASH_START_ADDRESS = 0x00080000;
__SMC_FLASH_BLOCK_SIZE = 0x00040000;

__CUSTOMER_CALS_FLASH_START_ADDRESS = 0x000C0000;
__CUSTOMER_CALS_FLASH_BLOCK_SIZE = 0x00010000;

__KEYS_FLASH_START_ADDRESS = 0x000D0000;
__KEYS_FLASH_BLOCK_SIZE = 0x0000B000;

__MARS_FW_FLASH_START_ADDRESS = 0x000DB000;
__MARS_FW_FLASH_BLOCK_SIZE = 0x00020000;

__KEYS_BACKUP_FLASH_START_ADDRESS = 0x000FB000;
__KEYS_BACKUP_FLASH_BLOCK_SIZE = 0x0000B000;

__APP_FLASH_START_ADDRESS = 0x00136000;
__APP_FLASH_BLOCK_SIZE = 0x0024A000;

__APP_RESERVED_FLASH_START_ADDRESS = 0x00380000;
__APP_RESERVED_FLASH_BLOCK_SIZE = 0x00040000;

__NVM_PARTITION_B_FLASH_START_ADDRESS = 0x003C0000;
__NVM_PARTITION_B_FLASH_BLOCK_SIZE = 0x00020000;

__NVM_PARTITION_A_FLASH_START_ADDRESS = 0x003E0000;
__NVM_PARTITION_A_FLASH_BLOCK_SIZE = 0x00020000;
