#ifndef SPBB_MEMMAP_H
#define SPBB_MEMMAP_H
/*===========================================================================*/
/**
 * @file
 * @brief Define memory mapping for SPBB data structures and functions
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2025 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * This file establishes a value for several #define macros that are used
 * throughout the code implementation to determine which section to map various
 * data structures and functions to.
 *
 * NOTE: preference is to get this file by #including "spbb_include.h" rather
 * than directly including it.
 *
 * @section ABBR ABBREVIATIONS:
 *   - None
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * @addtogroup api
 * @{
 */
/*==========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/* Some helper macros for general use */
#define SPBB_MEM_IRAM0_TEXT     ".iram0.text"
#define SPBB_MEM_DRAM0_BSS      ".dram0.bss"
#define SPBB_MEM_DRAM0_DATA     ".dram0.data"
#define SPBB_MEM_DRAM0_RODATA   ".dram0.rodata"
#define SPBB_MEM_DRAM1_BSS      ".dram1.bss"
#define SPBB_MEM_DRAM1_DATA     ".dram1.data"
#define SPBB_MEM_DRAM1_RODATA   ".dram1.rodata"
#define SPBB_MEM_SRAM0_TEXT     ".sram0.text"
#define SPBB_MEM_SRAM0_BSS      ".sram0.bss"
#define SPBB_MEM_SRAM0_DATA     ".sram0.data"
#define SPBB_MEM_SRAM0_RODATA   ".sram0.rodata"
#define SPBB_MEM_SRAM1_BSS      ".sram1.bss"
#define SPBB_MEM_SRAM1_DATA     ".sram1.data"
#define SPBB_MEM_SRAM1_RODATA   ".sram1.rodata"
#define SPBB_MEM_DEFAULT_BSS    SPBB_MEM_DRAM0_BSS
#define SPBB_MEM_DEFAULT_DATA   SPBB_MEM_DRAM0_DATA
#define SPBB_MEM_DEFAULT_RODATA SPBB_MEM_DRAM0_RODATA
#define SPBB_MEM_DEFAULT_TEXT   SPBB_MEM_IRAM0_TEXT

/* Function attributes */
#define ATTRIBUTE_FUNC_INLINE /* section is don't care */ inline

/* Memory mapping for command arrays */
#define SPBB_MEM_RANGE_PROCESS_A_COMMAND_ARRAY   (SPBB_MEM_SRAM0_RODATA)
#define SPBB_MEM_REST_DOPPLER_A_COMMAND_ARRAY    (SPBB_MEM_SRAM0_RODATA)
#define SPBB_MEM_NONREST_DOPPLER_A_COMMAND_ARRAY (SPBB_MEM_SRAM0_RODATA)

#endif /* SPBB_MEMMAP_H */
