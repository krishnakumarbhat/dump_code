#include "boot.ld"
#include "common.ld"

/**
*  NOTE: To place any piece of SW in TCM, use attribute to map to a section name and place that section immediately  after section: ".tcm_code_main".
*  When LTO is enabled order of the section is honored and we cannot address it with library names.
*  main() should be in TCM since MPU is configured after main to give execute permissions for sysmem.
*
*  .artie_mem_code and .artie_mem_bss will be used for any piece of SW to place in artie mem
*
*   PBL (xrw) : ORIGIN = 0x00000000, LENGTH = 0x00010000 is defined in boot.ld and reused in the application as TCMA. 
*   Only place .bss in PBL(TCMA) Section
*/
SECTIONS
{
   GROUP: {
      .null_guard (BSS) : {
         . = . + 0x40; /* 64-byte guard page: prevents use of NULL address */
      }
      .tcma_mem_bss (BSS):{
         KEEP(*(.tcma_mem_bss))
      }
   } > PBL /*TCMA(PBL) Memory is reused in Application*/

   GROUP: {
      .rdd_reserve (BSS) : {
         ARTIE_MEM = .;
          . = . + 100;
      }
      .artie_mem_bss (BSS):{
         KEEP(*(.artie_mem_bss))
      }
      .artie_mem_code (TEXT):{
         *(.artie_mem_code)
      }
   } > ARTIE_MEM


   /* All code from all objects goes to R52_SYSMEM */
   .text (TEXT) : {
      *(.vectors)
      KEEP(*(.versionInfo))
      *(.EL2Reset)
      *(.EL1Reset)
      } > R52_TCM

   /* OS interrupt vector constants: each file targets > R52_TCM */
   #include "vLinkGen_Inc_OS_INTVEC_CONST.ld"
   #include "vLinkGen_Inc_OS_INTVEC_CORE0_CONST.ld"

   .tcm_code_main (TEXT):{
         KEEP(*(.tcm_code_main))
   }> R52_TCM

   .text2 (TEXT) : {
      *(.StartupCommon)
      *(.init)
      *(.fini)
      libstartup.a(.text)
      libcdiab.a(.text)
      libcdinkum.a(.text)
      libllvmc.a(.text)
      libimpl.a(.text)
      libchar.a(.text)
   } > R52_TCM

   .os_tcm_code (TEXT) : {
      *(.OS_ASSEMBLY_CODE)
      Os_Hal_Context.o(.OS_CODE)
   } > R52_TCM

   GROUP: {

     .eth_bss (BSS) : {
         *(.eth_descriptor_tx)
         *(.eth_buffer_tx)
         *(.eth_descriptor_rx)
         *(.eth_buffer_rx)
     }
   } > SYSMEM0_DATA_ETH

   /* OS exception/interrupt vector code + all task stacks: each file targets > R52_TCM */
   #include "vLinkGen_Inc_OS_EXCVEC_CORE0_CODE.ld"
   #include "vLinkGen_Inc_OS_INTVEC_CODE.ld"
   _OS_CORE0_STACKS_START = _OS_STACK_Appl_IPC_Task_VAR_ALL_START;
   #include "vLinkGen_Inc_OS_STACK_Appl_IPC_Task_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Appl_Task_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Appl_Task_Communication_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Appl_Task_Fast_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Appl_Task_High_Prio_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Appl_Task_Logging_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_BSW_Task_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Error_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Init_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Isr_Core_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Kernel_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Shutdown_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Startup_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio0_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio190_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio200_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio210_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Task_Prio4294967295_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_OsCore0_Protection_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Radar_Ctrl_Task_VAR.ld"
   #include "vLinkGen_Inc_OS_STACK_Appl_BackgroundTask_VAR.ld"
   _OS_CORE0_STACKS_LIMIT = _OS_STACK_Radar_Ctrl_Task_VAR_ALL_LIMIT;


   GROUP : {

      .ARM.extab (TEXT) : {
         *(".ARM.extab*" ".gnu.linkonce.armextab.*")
      }
      __exidx_start = .;
      .ARM.exidx (TEXT) : {
         *(".ARM.exidx*" ".gnu.linkonce.armexidx.*")
      }
      __exidx_end = .;
      .gcc_except_table (TEXT) : {
         *(.gcc_except_table, ".gcc_except_table.*")
      }
      .sdata2 (TEXT)  : {    /* small CONST area for some targets */
         *(.sdata2, ".sdata2.*")
         . = (. + 7) & ~7;
      }

      .rodata (DATA) : {
         *(.rodata, ".rodata.*")
      }

      /* constructor and destructor function ptrs                 */
      .ctors ALIGN(8) (TEXT) : { ctordtor.o(.ctors) *(.ctors) }
      .init_array ALIGN(8) (TEXT) : { ctordtor.o(.init_array) *(.init_array) }
      .dtors ALIGN(8) (TEXT) : { ctordtor.o(.dtors) *(.dtors) }
      .fini_array ALIGN(8) (TEXT) : { ctordtor.o(.fini_array) *(.fini_array) }
      .copytable : {} /* the copytable */

   } > R52_SYSMEM

   /* OS kernel + hook + intvec code: each file targets > R52_TCM */
   . = ALIGN(128);
   #include "vLinkGen_Inc_OS_CODE.ld"
   #include "vLinkGen_Inc_OS_USER_CODE.ld"
   #include "vLinkGen_Inc_OS_INTVEC_CORE0_CODE.ld"

   .text (TEXT) : {
      *(.text, ".text.*")
   } > R52_SYSMEM

   .boot_shared_data (BSS): {
      KEEP(*(.boot_interface))
   } > BOOT_SHARED_DATA

   .retention_ram ALIGN(128) (BSS):
   {
      KEEP(*(.retention_ram_data)) /* NOINIT RAM  used to store the data*/
   } > NOINIT_RAM

      GROUP:
   {
      .logging_bss (BSS) :
      {
         *(.logging.bss)
      }
      .Rte_Data_QM.bss (BSS) :
      {
         . = ALIGN(8);
         *(.Rte_No_Init_QM.bss)
         . = ALIGN(8);
      }

      .logging.data (DATA) :
      {
         *(.logging.data)
      }
      .Rte_Data_QM.data (DATA) :
      {
         . = ALIGN(8);
         *(.Rte_No_Init_QM.data)
         . = ALIGN(8);
      }
   } > SYSMEM0_R52_QM

   /* OS const sections: each file targets > SYSMEM0_R52_DATA */
   #include "vLinkGen_Inc_OS_CONST.ld"
   #include "vLinkGen_Inc_OS_GLOBALSHARED_CONST.ld"
   #include "vLinkGen_Inc_OS_USER_CONST.ld"

   /* OS var sections: ROM-init copies target > R52_TCM, RAM data targets > SYSMEM0_R52_DATA (self-contained) */
   #include "vLinkGen_Inc_OS_DATA_SHARED_VAR.ld"
   #include "vLinkGen_Inc_OS_GLOBALSHARED_VAR.ld"
   #include "vLinkGen_Inc_OS_DATA_CORE0_VAR.ld"
   #include "vLinkGen_Inc_OS_OsCore0_ASIL_VAR.ld"
   #include "vLinkGen_Inc_OS_OsCore_Qm_VAR.ld"

   GROUP : {
      __DATA_ROM  = .;
      __DATA_RAM  = .;
      .data (DATA)    : { * (.data, ".data.*") }
      .got (DATA)     : {}
      .sdata (DATA)   : { *(.sdata, ".sdata.*") }
      __DATA_END  = .;
   } > SYSMEM0_R52_DATA

   GROUP : {
      __BSS_START = .;

      /* Allocate uninitialized sections.             */
      .sbss (BSS)     : { *(.sbss, ".sbss.*") }
     
      .bss (BSS)  : { *(.bss, ".bss.*") }
      __BSS_END   = .;

      /* Any remaining space will be used as a heap.          */
      __HEAP_START    = .;
      . = . + 0x200;
      __HEAP_END    = .;

      __SP_END = .;
      . = . + 0x1000;
      __SP_INIT = .;

      . = . + 0x200;
      __SP_IRQ_START = .;

      . = . + 0x100;
      __EL2StackTop = .;

   } > SYSMEM0_R52_DATA


   .ipc_sections_m2d(BSS) :
   {
    *(.ipc_r52_to_dsp)
    *(.ipc_radar_data_status)
   } >SYSMEM_IPC_M2D

   .Crypto_iNDI13400_IPC_Section ALIGN(16) (BSS) :
   {
      . = ALIGN(16);
      KEEP(*(.Crypto_iNDI13400_IPC_Section))
      . = ALIGN(16);
      KEEP(*(.Crypto_iNDI13400_IPC_Section.Align16Var1))
      . = ALIGN(16);
      KEEP(*(.Crypto_iNDI13400_IPC_Section.Align16Var2))
   } > R52_SYSMEM


   .Crypto_iNDI13400_KeyStruct_MetaData ALIGN(16) (BSS) :
   {
      . = ALIGN(16);
      KEEP(*(.Crypto_iNDI13400_KeyStruct_MetaData))
   } > R52_SYSMEM

   .Crypto_iNDI13400_KeyStruct_InitData ALIGN(16) (DATA) :
   {
      . = ALIGN(16);
      KEEP(*(.Crypto_iNDI13400_KeyStruct_InitData))
   } > R52_SYSMEM
	
   .Crypto_iNDI13400_TestData ALIGN(16) (DATA) :
    {
        . = ALIGN(16);
        KEEP(*(.Crypto_iNDI13400_TestData)) 

    } > R52_SYSMEM

   .ipc_sections (BSS) :
   {
      *(.ipc_metadata_section)
   } > SYSMEM_IPC_SHARED
}

/* Definitions of identifiers used by sbrk.c, init.c, and the different
 * crt0.s files. Their purpose is to control initialization and memory
 * allocation. (DATA_ROM and DATA_RAM are the same in this file; when used
 * with the LOAD specification they are used to copy initialized data from
 * "rom" to "ram" at system startup and will be different. See the Linker
 * section of the User's Guide for details.)
 *
 * __HEAP_START : Used by sbrk.c. Start of memory used by malloc() etc.
 * __HEAP_END   : Used by sbrk.c. End of heap memory
 * __SP_INIT    : Used by crt0.s. Initial address of stack pointer
 * __SP_END     : Used by sbrk.c. Only used when stack probing
 * __DATA_ROM   : Used by init.c. Address of initialized data in ROM
 * __DATA_RAM   : Used by init.c. Address of initialized data in RAM
 * __DATA_END   : Used by init.c. End of allocated initialized data
 * __BSS_START  : Used by init.c. Start of uninitialized data
 * __BSS_END    : Used by init.c. End of data to be cleared
 * ------------------------------------------------------------------------ */

/*
 * Added these variables within the section to make sure that heap and
 * stack memory is reserved and not overwritten
*/

/*
__EL2StackTop = ADDR(SYSMEM0_R52_DATA)+SIZEOF(SYSMEM0_R52_DATA);
__SP_IRQ_START = __EL2StackTop-0x100;
__SP_INIT   = __SP_IRQ_START-0x200;
__SP_END    = __SP_INIT-0x800;  // Stack is 2KB.
__HEAP_END  = __SP_END;         // Heap contiguous with stack.
*/
_start     = EL2_Reset_Handler;

/* Some targets use an extra underscore in front of identifiers
 * ------------------------------------------------------------------------ */
___HEAP_START   = __HEAP_START;
___HEAP_END = __HEAP_END;
___SP_INIT  = __SP_INIT;
___SP_END   = __SP_END;
___DATA_ROM = __DATA_ROM;
___DATA_RAM = __DATA_RAM;
___DATA_END = __DATA_END;
___BSS_START    = __BSS_START;
___BSS_END  = __BSS_END;


/*Symbols used to configure MPU table in main.c*/

__R52_TCMA_NULL_GUARD_BASE__  = ADDR(PBL);
__R52_TCMA_NULL_GUARD_LIMIT__ = ADDR(PBL) + SIZEOF(.null_guard) - 1; /* 64 bytes: minimum valid MPU region */
__R52_PBL_SIZE__              = SIZEOF(PBL);
__R52_TCMA_BASE__   = ADDR(PBL) + SIZEOF(.null_guard); /* starts after null guard */
__R52_TCMA_LIMIT__  = ADDR(PBL) + SIZEOF(PBL) - 1;

__R52_TCMBC_BASE__   =  ADDR(R52_TCM);
__R52_TCMBC_LIMIT__  =  ADDR(R52_TCM)+ SIZEOF(R52_TCM)-1;

/* SysMem0 R52 code */
__SYSMEM0_R52_SYSMEM_BASE__   = 0x80000000;
__SYSMEM0_R52_SYSMEM_LIMIT__  = ADDR(R52_SYSMEM) + SIZEOF(R52_SYSMEM) - 1;

/* Sysmem0 R52 data */
__SYSMEM0_R52_DATA_BASE__   = ADDR(SYSMEM_IPC_D2M);
__SYSMEM0_R52_DATA_LIMIT__  = ADDR(SYSMEM0_R52_DATA) + SIZEOF(SYSMEM0_R52_DATA) - 1;

__ARTIE_MEM_BASE__ = ADDR(ARTIE_MEM);
__ARTIE_MEM_LIMIT__ = ADDR(ARTIE_MEM) + SIZEOF(ARTIE_MEM) - 1;

/* Sysmem1 R52 data */
__SYSMEM1_R52_DATA_BASE__   = ADDR(SYSMEM1_ENET_PKT);
__SYSMEM1_R52_DATA_LIMIT__  = ADDR(SYSMEM_IPC_M2D) + SIZEOF(SYSMEM_IPC_M2D) - 1;

/* Systemem0 R52 QM */
__SYSMEM0_R52_QM_BASE__     = ADDR(SYSMEM0_R52_QM);
__SYSMEM0_R52_QM_LIMIT__    = ADDR(SYSMEM0_R52_QM) + SIZEOF(SYSMEM0_R52_QM) -1;