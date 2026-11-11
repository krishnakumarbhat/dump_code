#ifndef AFBB_MEMMAP_H
#define AFBB_MEMMAP_H
/*===========================================================================*/
/**
 * @file
 * @brief Define memory mapping for AFBB data structures and functions
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
 * NOTE: preference is to get this file by #including "afbb_include.h" rather
 * than directly including it.
 *
 * For global AF data structures, 2 #defines are provide to control the
 * behavior:
 * 1. AF_MEM_<varname>_ON_MEMPOOL
 *   - This will have an integer value like 0, 1, or 2 (use the helper defines
 *     indicated):
 *   - 0 (AF_MEMPOOL_DISABLE) indiciates that the variable will not be stored
 *     on the mempool
 *   - 1 (AF_MEMPOOL_DRAM) indicates that the variable will be stored in the
 *     DRAM mempool
 *   - 2 (AF_MEMPOOL_SRAM) indicates that the variable will be stored in the
 *     SRAM mempool
 * 2. AF_MEM_<varname>_SECTION
 *   - This will be a string value indicating the ELF section to which the
 *     variable will be assigned
 *   - This variable only takes effect when <varname>_ON_MEMPOOL is 0
 * NOTE: There is no point assigning structures smaller than
 * sizeof(AF_Internal_Mem_Info_T) bytes to the mempool because each one will
 * add an entry to AF_Internal_Mem_Info.
 *
 * For functions, a few general section labels will be used. It is somewhat
 * adhoc, so see the comments below for relative priority.
 * There are some helper macros to allow functions to be grouped together using
 * these section labels:
 *  - MAKEFN_PROFILE_SEC(): This will ensure that a function can be profiled
 *    accurately.
 *  - MAKEFN_REQUIRED_SEC(): This will ensure that a function will be placed in
 *    the selected memory region.
 *     - In particular, use this on the first function in each group if you did
 *       not use MAKEFN_PROFILE_SEC().
 *     - Also, use this when the call graph transitions from one group to
 *       another and you want to ensure that the function gets assigned to the
 *       correct region rather than being inlined.
 *  - MAKEFN_PREFERRED_SEC(): This will make a function part of a group but
 *    allow it to be inlined.
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
#define AF_MEMPOOL_DISABLE    (0)
#define AF_MEMPOOL_DRAM       (1)
#define AF_MEMPOOL_SRAM       (2)
#define AF_MEM_IRAM0_TEXT     ".iram0.text"
#define AF_MEM_DRAM0_BSS      ".dram0.bss"
#define AF_MEM_DRAM0_DATA     ".dram0.data"
#define AF_MEM_DRAM0_RODATA   ".dram0.rodata"
#define AF_MEM_DRAM1_BSS      ".dram1.bss"
#define AF_MEM_DRAM1_DATA     ".dram1.data"
#define AF_MEM_DRAM1_RODATA   ".dram1.rodata"
#define AF_MEM_SRAM0_TEXT     ".sram0.text"
#define AF_MEM_SRAM0_BSS      ".sram0.bss"
#define AF_MEM_SRAM0_DATA     ".sram0.data"
#define AF_MEM_SRAM0_RODATA   ".sram0.rodata"
#define AF_MEM_SRAM1_BSS      ".sram1.bss"
#define AF_MEM_SRAM1_DATA     ".sram1.data"
#define AF_MEM_SRAM1_RODATA   ".sram1.rodata"
#define AF_MEM_DEFAULT_BSS    AF_MEM_DRAM0_BSS
#define AF_MEM_DEFAULT_DATA   AF_MEM_DRAM0_DATA
#define AF_MEM_DEFAULT_RODATA AF_MEM_DRAM0_RODATA
#if CHANDRA_B0
   #define AF_MEM_DEFAULT_TEXT AF_MEM_IRAM0_TEXT
#else
   #define AF_MEM_DEFAULT_TEXT AF_MEM_SRAM0_TEXT
#endif

/* Function attributes */
#define ATTRIBUTE_FUNC_INLINE         /* section is don't care */ inline
#define MAKEFN_PROFILE_SEC(fngroup)   __attribute__((section(AF_MEM_FN_##fngroup##_SECTION), noinline))
#define MAKEFN_REQUIRED_SEC(fngroup)  __attribute__((section(AF_MEM_FN_##fngroup##_SECTION), noinline))
#define MAKEFN_PREFERRED_SEC(fngroup) __attribute__((section(AF_MEM_FN_##fngroup##_SECTION)))

#if defined(FLR8)

   /* define AF_MEM_<varname>_ON_MEMPOOL for all FLR8 variables */
   #define AF_MEM_RDD_DET_ON_MEMPOOL           (AF_MEMPOOL_DRAM)
   #define AF_MEM_RDD_ANGLE_DATA_S1_ON_MEMPOOL (AF_MEMPOOL_SRAM)
   #define AF_MEM_RDD_ANGLE_DATA_S4_ON_MEMPOOL (AF_MEMPOOL_SRAM)
   #define AF_MEM_RDD_ANGLE_DATA_S5_ON_MEMPOOL (AF_MEMPOOL_SRAM)
   #define AF_MEM_ANGLE_DATA_ON_MEMPOOL        (AF_MEMPOOL_DRAM)
   #define AF_MEM_ANGLE_DATA_S4_ON_MEMPOOL     (AF_MEMPOOL_DRAM)
   #define AF_MEM_ANGLE_DATA_S5_ON_MEMPOOL     (AF_MEMPOOL_DRAM)
   #define AF_MEM_AF_USC_ON_MEMPOOL            (AF_MEMPOOL_DISABLE) /* keep in DRAM as it is small and frequently accessed */
   #define AF_MEM_AF_MEM_ON_MEMPOOL            (AF_MEMPOOL_SRAM)
   #define AF_MEM_AF_MEM_POOL_ON_MEMPOOL       (AF_MEMPOOL_DRAM)
   #define AF_MEM_AF_DATA_ON_MEMPOOL           (AF_MEMPOOL_DRAM)
   // these could go in SRAM - especially if flr8_flag_calibration_monitoring is disabled
   #define AF_MEM_CALMAT_UPDATE_DATA_ON_MEMPOOL  (AF_MEMPOOL_DRAM)
   #define AF_MEM_CAL_MONITORING_STAT_ON_MEMPOOL (AF_MEMPOOL_DRAM)

   /* define AF_MEM_<varname>_SECTION for all FLR8 BSS variables */
   #define AF_MEM_RDD_DET_SECTION             AF_MEM_DEFAULT_BSS
   #define AF_MEM_RDD_ANGLE_DATA_S1_SECTION   AF_MEM_DEFAULT_BSS
   #define AF_MEM_RDD_ANGLE_DATA_S4_SECTION   AF_MEM_DEFAULT_BSS
   #define AF_MEM_RDD_ANGLE_DATA_S5_SECTION   AF_MEM_DEFAULT_BSS
   #define AF_MEM_ANGLE_DATA_SECTION          AF_MEM_DEFAULT_BSS
   #define AF_MEM_ANGLE_DATA_S4_SECTION       AF_MEM_DEFAULT_BSS
   #define AF_MEM_ANGLE_DATA_S5_SECTION       AF_MEM_DEFAULT_BSS
   #define AF_MEM_AF_USC_SECTION              AF_MEM_DRAM0_BSS /* keep in DRAM as it is small and frequently accessed */
   #define AF_MEM_AF_MEM_SECTION              AF_MEM_DEFAULT_BSS
   #define AF_MEM_AF_MEM_POOL_SECTION         AF_MEM_DEFAULT_BSS
   #define AF_MEM_AF_DATA_SECTION             AF_MEM_DEFAULT_BSS
   #define AF_MEM_CALMAT_UPDATE_DATA_SECTION  AF_MEM_DEFAULT_BSS
   #define AF_MEM_CAL_MONITORING_STAT_SECTION AF_MEM_DEFAULT_BSS
   // special case for af_input_data/af_output_data - these probably shouldn't be on mempool
   #define AF_MEM_AF_INPUT_DATA_SECTION  AF_MEM_SRAM0_BSS
   #define AF_MEM_AF_OUTPUT_DATA_SECTION AF_MEM_SRAM0_BSS

   /* define AF_MEM_<varname>_SECTION for all FLR8 data variables */
   #define AF_MEM_AF_CTX0_SECTION              AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_CRX0_SECTION              AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_CAL0_C1_SECTION           AF_MEM_SRAM1_DATA
   #define AF_MEM_AF_GAINPATFINE_SECTION       AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_THOLD_SENSITIVITY_SECTION AF_MEM_DRAM1_DATA
   #define AF_MEM_AF_FFT_REV_SECTION           AF_MEM_DRAM0_DATA /* keep in DRAM, used by all FFT stages */
   #define AF_MEM_AF_FFT_W_SECTION             AF_MEM_DRAM0_DATA /* keep in DRAM, used by all FFT stages */
   // these could go in SRAM - especially if flr8_flag_lut_stageone is disabled
   #define AF_MEM_AF_CHAMBER_EL_PLANE_SECTION AF_MEM_DRAM1_DATA
   #define AF_MEM_AF_AZ_LUT_SECTION           AF_MEM_DRAM1_DATA
   #define AF_MEM_AF_AZ_SIN_LUT_SECTION       AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_EL_LUT_SECTION           AF_MEM_DRAM1_DATA
   #define AF_MEM_AF_EL_SIN_LUT_SECTION       AF_MEM_SRAM1_DATA
   #define AF_MEM_AF_AZ_SEARCH_RANGE_SECTION  AF_MEM_DRAM1_DATA
   #define AF_MEM_AF_EL_SEARCH_OFFSET_SECTION AF_MEM_DRAM1_DATA

   /* define AF_MEM_<varname>_SECTION for FLR8 Test data */
   #define AF_MEM_INIT_AF_SSC_SECTION                   AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_ORDER_BV_SECTION                  AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_HOST_SPEED_SECTION                AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_NUM_RDD_DET_SECTION               AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_RAN_SECTION                       AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_VEL_SECTION                       AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_SNR_SECTION                       AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_CMP_BV_SECTION                    AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_F_PEAK_DET_SECTION                AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_RDOP_AMP_SECTION                  AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_RINDX_SECTION                     AF_MEM_SRAM1_DATA
   #define AF_MEM_AF_NCI_BEXP_SECTION                   AF_MEM_SRAM1_DATA
   #define AF_MEM_AF_CR_RESP_STUB_SECTION               AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_DET_BWDEP_CR_RESP_SECTION         AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_RDOP_AMP_SCALED_SECTION            AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_COUNT_SECTION                  AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_THETA_SECTION                  AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_PHI_SECTION                    AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_POW_SECTION                    AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_BV2MPRB_SECTION                     AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_RCS_AZ_ROLLOFF_LIMIT_SECTION        AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_RCS_EL_ROLLOFF_LIMIT_SECTION        AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_FLAG_FLIP_AZIMUTH_ROLLOFF_SECTION   AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_FLAG_FLIP_ELEVATION_ROLLOFF_SECTION AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_GAIN_ROLLOFF_AZ_RECIPROCAL_SECTION  AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_GAIN_ROLLOFF_EL_RECIPROCAL_SECTION  AF_MEM_DEFAULT_DATA
   #define AF_MEM_DS_TESTING                            AF_MEM_SRAM1_DATA

   /* define AF_MEM_FN_<fngroup>_SECTION for */
   #define AF_MEM_FN_AFTOP_SECTION     AF_MEM_DEFAULT_TEXT /* Top-level functions for AF - generally Low Prio */
   #define AF_MEM_FN_AFTEST_SECTION    AF_MEM_DEFAULT_TEXT /* Low Priority Test code - not generally linked in */
   #define AF_MEM_FN_INITDET_SECTION   AF_MEM_DEFAULT_TEXT /* Medium Priority */
   #define AF_MEM_FN_BVDECOMP_SECTION  AF_MEM_IRAM0_TEXT   /* Top Priority */
   #define AF_MEM_FN_UNFOLD_SECTION    AF_MEM_DEFAULT_TEXT /* Very High Priority */
   #define AF_MEM_FN_UNFOLD_CM_SECTION AF_MEM_DEFAULT_TEXT /* Very High Priority */
   #define AF_MEM_FN_ELFFT_SECTION     AF_MEM_DEFAULT_TEXT /* Very High Priority */
   #define AF_MEM_FN_SYNTHFFT_SECTION  AF_MEM_DEFAULT_TEXT /* High Priority */
   #define AF_MEM_FN_AFERRMAG_SECTION  AF_MEM_IRAM0_TEXT   /* Top High Priority */
   #define AF_MEM_FN_MAINSTAGE_SECTION AF_MEM_DEFAULT_TEXT /* Medium Priority - Stage 1 */
   #define AF_MEM_FN_REMSTAGE_SECTION  AF_MEM_DEFAULT_TEXT /* Low Priority - Other stages */
   #define AF_MEM_FN_RCS_SECTION       AF_MEM_DEFAULT_TEXT
   #define AF_MEM_FN_AFDS_SECTION      AF_MEM_DEFAULT_TEXT
   #define AF_MEM_FN_AFFC_SECTION      AF_MEM_DEFAULT_TEXT

#elif defined(SRR8P)

   /* define AF_MEM_<varname>_ON_MEMPOOL for all SRR8 variables */
   #define AF_MEM_RDD_DET_ON_MEMPOOL                    (AF_MEMPOOL_DRAM)
   #define AF_MEM_RDD_ANGLE_DATA_S1_ON_MEMPOOL          (AF_MEMPOOL_DRAM)
   #define AF_MEM_RDD_ANGLE_DATA_S4_ON_MEMPOOL          (AF_MEMPOOL_SRAM)
   #define AF_MEM_RDD_ANGLE_DATA_S5_ON_MEMPOOL          (AF_MEMPOOL_SRAM)
   #define AF_MEM_ANGLE_DATA_ON_MEMPOOL                 (AF_MEMPOOL_DISABLE)
   #define AF_MEM_ANGLE_DATA_S4_ON_MEMPOOL              (AF_MEMPOOL_DISABLE)
   #define AF_MEM_ANGLE_DATA_S5_ON_MEMPOOL              (AF_MEMPOOL_DISABLE)
   #define AF_MEM_AF_SSC_ON_MEMPOOL                     (AF_MEMPOOL_DISABLE) /* keep in DRAM for performance */
   #define AF_MEM_AF_USC_ON_MEMPOOL                     (AF_MEMPOOL_DISABLE) /* keep in DRAM as it is small and frequently accessed */
   #define AF_MEM_AF_MEM_ON_MEMPOOL                     (AF_MEMPOOL_SRAM)
   #define AF_MEM_AF_MEM_POOL_ON_MEMPOOL                (AF_MEMPOOL_DRAM)
   #define AF_MEM_AF_DATA_ON_MEMPOOL                    (AF_MEMPOOL_DISABLE)

   /* define AF_MEM_<varname>_SECTION for all SRR8 BSS variables */
   #define AF_MEM_RDD_DET_SECTION                       AF_MEM_DEFAULT_BSS
   #define AF_MEM_RDD_ANGLE_DATA_S1_SECTION             AF_MEM_DEFAULT_BSS
   #define AF_MEM_RDD_ANGLE_DATA_S4_SECTION             AF_MEM_DEFAULT_BSS
   #define AF_MEM_RDD_ANGLE_DATA_S5_SECTION             AF_MEM_DEFAULT_BSS
   #define AF_MEM_ANGLE_DATA_SECTION                    AF_MEM_DRAM0_BSS
   #define AF_MEM_ANGLE_DATA_S4_SECTION                 AF_MEM_DRAM0_BSS
   #define AF_MEM_ANGLE_DATA_S5_SECTION                 AF_MEM_DRAM1_BSS /* keep in DRAM for performance */
   #define AF_MEM_AF_SSC_SECTION                        AF_MEM_DRAM0_BSS /* keep in DRAM for performance */
   #define AF_MEM_AF_USC_SECTION                        AF_MEM_DRAM0_BSS /* keep in DRAM as it is small and frequently accessed */
   #define AF_MEM_AF_MEM_SECTION                        AF_MEM_DEFAULT_BSS
   #define AF_MEM_AF_MEM_POOL_SECTION                   AF_MEM_DEFAULT_BSS
   #define AF_MEM_AF_DATA_SECTION                       AF_MEM_DRAM0_BSS
   // special case for af_input_data/af_output_data - these probably shouldn't be on mempool
   #define AF_MEM_AF_INPUT_DATA_SECTION                 AF_MEM_SRAM0_BSS
   #define AF_MEM_AF_OUTPUT_DATA_SECTION                AF_MEM_SRAM0_BSS

   /* define AF_MEM_<varname>_SECTION for all SRR8 data variables */
   #define AF_MEM_AF_CTX0_SECTION                       AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_CRX0_SECTION                       AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_CAL0_C1_SECTION                    AF_MEM_SRAM0_DATA
   #define AF_MEM_AF_CTX1_SECTION                       AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_CRX1_SECTION                       AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_CAL1_C1_SECTION                    AF_MEM_SRAM0_DATA
   #define AF_MEM_AF_GAINPATFINE_SECTION                AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_THOLD_SENSITIVITY_SECTION          AF_MEM_DRAM0_DATA
   #define AF_MEM_AF_FFT_REV_SECTION                    AF_MEM_DRAM0_DATA /* keep in DRAM, used by all FFT stages */
   #define AF_MEM_AF_FFT_W_SECTION                      AF_MEM_DRAM0_DATA /* keep in DRAM, used by all FFT stages */

   /* define AF_MEM_<varname>_SECTION for SRR8 Test data */
   #define AF_MEM_INIT_AF_SSC_SECTION                   AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_ORDER_BV_SECTION                  AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_HOST_SPEED_SECTION                AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_NUM_RDD_DET_SECTION               AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_RAN_SECTION                       AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_VEL_SECTION                       AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_SNR_SECTION                       AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_CMP_BV_SECTION                    AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_F_PEAK_DET_SECTION                AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_RDOP_AMP_SECTION                  AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_RINDX_SECTION                     AF_MEM_SRAM1_DATA
   #define AF_MEM_AF_NCI_BEXP_SECTION                   AF_MEM_SRAM1_DATA
   #define AF_MEM_AF_CR_RESP_STUB_SECTION               AF_MEM_SRAM1_DATA
   #define AF_MEM_RDD_DET_BWDEP_CR_RESP_SECTION         AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_RDOP_AMP_SCALED_SECTION            AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_COUNT_SECTION                  AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_THETA_SECTION                  AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_PHI_SECTION                    AF_MEM_DEFAULT_DATA
   #define AF_MEM_AF_DET_POW_SECTION                    AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_BV2MPRB_SECTION                     AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_RCS_AZ_ROLLOFF_LIMIT_SECTION        AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_RCS_EL_ROLLOFF_LIMIT_SECTION        AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_FLAG_FLIP_AZIMUTH_ROLLOFF_SECTION   AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_FLAG_FLIP_ELEVATION_ROLLOFF_SECTION AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_GAIN_ROLLOFF_AZ_RECIPROCAL_SECTION  AF_MEM_DEFAULT_DATA
   #define AF_MEM_K_GAIN_ROLLOFF_EL_RECIPROCAL_SECTION  AF_MEM_DEFAULT_DATA
   #define AF_MEM_DS_TESTING                            AF_MEM_SRAM1_DATA

   /* define AF_MEM_FN_<fngroup>_SECTION for */
   #define AF_MEM_FN_AFTOP_SECTION                      AF_MEM_DEFAULT_TEXT /* Top-level functions for AF - generally Low Prio */
   #define AF_MEM_FN_AFTEST_SECTION                     AF_MEM_DEFAULT_TEXT /* Low Priority Test code - not generally linked in */
   #define AF_MEM_FN_INITDET_SECTION                    AF_MEM_DEFAULT_TEXT /* Medium Priority */
   #define AF_MEM_FN_BVDECOMP_SECTION                   AF_MEM_IRAM0_TEXT   /* Top Priority */
   #define AF_MEM_FN_UNFOLD_SECTION                     AF_MEM_IRAM0_TEXT   /* Topmost Priority */
   #define AF_MEM_FN_ELFFT_SECTION                      AF_MEM_IRAM0_TEXT   /* Very High Priority */
   #define AF_MEM_FN_SYNTHFFT_SECTION                   AF_MEM_DEFAULT_TEXT /* Very High Priority */
   #define AF_MEM_FN_MAINSTAGE_SECTION                  AF_MEM_DEFAULT_TEXT /* Medium Priority - Stage 1 */
   #define AF_MEM_FN_REMSTAGE_SECTION                   AF_MEM_DEFAULT_TEXT /* Low Priority - Other stages */
   #define AF_MEM_FN_RCS_SECTION                        AF_MEM_DEFAULT_TEXT
   #define AF_MEM_FN_AFDS_SECTION                       AF_MEM_DEFAULT_TEXT /* Post-AF Downselection */
   #define AF_MEM_FN_AFFC_SECTION                       AF_MEM_DEFAULT_TEXT /* Post-AF Fascia Compensation */

#else

   #error unknown variant definition (expected flr8 or srr8p)

#endif /* defined(FLR8) or defined(SRR8P) */

#endif /* AFBB_MEMMAP_H */
