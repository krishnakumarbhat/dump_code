#ifndef _SWC_CDD_FAILSAFE_H_
#define _SWC_CDD_FAILSAFE_H_

/**************************************************************************
 * Copyright 2019 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        FailSafe \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:fjvnnx  %derived_by: fjvnnx % \n
 * \b Classification:     CONFIDENTIAL \n
 * %date_modified: 23/07/2025 %
 *
 *
 *
 ***************************************************************************
 *
 *  Module Name:  SWC_CDD_FailSafe.h
 *
 *  Description:
 *    Header file for SWC_CDD_FailSafe.c
 *
 *
 **************************************************************************/
/*=====================================================================================================================*
 * PREPROCESSOR DIRECTIVES
 *=====================================================================================================================*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS ------------------------------------------------------------------------------*/

#include "reuse.h"

/*====================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*====================================================================================================================*/

/**********************************************************************************************************************\
 * #define constants
\**********************************************************************************************************************/
/*Macro to check 30 Sec timeout*/

/*Reset Reason Macros*/
#define MAX_RESET_COUNTER_VAL (255U)

/*Exception Reason Macros*/
#define CDATA_EXCEPTION_REASON (*Rte_CData_ExceptionReason_DefaultValue())

/*List of exception type ranges*/
#define IS_IT_SW_EXCEPTION(X) (((200U <= X) && (X <= 254U)) ? 1U : 0U)

/*Cores ID for exception logging */
#define CORE0 (0u)
#define CORE1 (1u)
#define CORE2 (2u)

#define INT_WDG_OFF 0xFF00014AU
#define TICK_5MS    5U

#define PREV_INDX       1U
#define CNTR_INDEX_ZERO 0U
#define RESET_CNTR      0U

/*  FAIL_SAFE_CONFIGURATION  */

#ifndef MAX_RESET_REASONS
   #define MAX_RESET_REASONS (uint8_t)5
#endif

#ifndef MAX_EXCEPTIONS
   #define MAX_EXCEPTIONS (uint8_t)3
#endif

#ifndef MAX_REG_CHECK_FAILURE
   #define MAX_REG_CHECK_FAILURE (uint8_t)35
#endif

/* SPF Registers which will be saved during Exceptions */
#ifndef MCSRR0_REG
   #define MCSRR0_REG (uint32_t)570
#endif

#ifndef SRR0_REG
   #define SRR0_REG (uint32_t)26
#endif

#ifndef ESR_REG
   #define ESR_REG (uint32_t)62
#endif

#ifndef MCSR_REG
   #define MCSR_REG (uint32_t)572
#endif

#ifndef DEAR_REG
   #define DEAR_REG (uint32_t)61
#endif

#define CMPU_ESR  ((uint32_t)62)
#define CMPU_MCAR ((uint32_t)573)

#define MULTIPLE_FAULTS_STORAGE_SIZE 10
#define NO_FCRU_REPETATIVE_RESET     0xFF

/*macro to check if a bit is set*/
#define IsResetRawBitSet(var, bit) (0U != ((var) & (1U << (bit))))
/*macro to check external wdg reset */
/* #define FAILSAFE_DEBUG_ON 1 */
/* STRUCTS -------------------------------------------------------------------*/
typedef struct Memory_Exception_Info_Tag
{
   uint8 ExceptionType;
   uint32 ExceptionCausingAddress;
   uint32 ExceptionStatusRegister;
   uint8 IsMemException_Occured;
   uint32 MemoryExceptionAddress;
   uint32 StackPointer;
} Memory_Exception_Info_T;

typedef struct FailSafe_ResetReason_Tag
{
   uint8 reset_reason_info[MAX_RESET_REASONS];
   uint8 reset_counter;
   uint8 last_cycle_reset;
   uint8 reset_reason_crnt_indx;
   uint8 repetitive_reset_counter;
   uint8 RFE_Repetitive_Reset_Counter;
   Memory_Exception_Info_T FailSafeExceptionReason;
   uint16 wdg_failed_SE_info[5];
   uint8 StaticRegCheckFailureInfo[35];
   Dt_NOC_Fault_Info_T NOC_LatentIntFault_Info;
} FailSafe_ResetReason_T;

typedef struct
{
   /* SM_003: AA_MEM_ECC */
   uint8 aa_mem_sec; /* SM_003 */

   /* SM_005: ARTIE_MEM_ECC */
   uint8 artie_mem_sec;

   /* SM_011: CSI2_ECC */
   uint8 csi2_sec; /* SM_011 */

   /* SM_017: DSP OPIF ECC (SEC) */
   uint8 dsp_opif_sec;      /* SM_017 */
   uint8 dsp_idma_sec;      /* SM_017 */
   uint8 dsp_iram_sec_axis; /* SM_017 */

   /* SM_019..SM_022: DSP ECC */
   uint8 dsp_dcache_sec; /* SM_019 */
   uint8 dsp_dram_sec;   /* SM_020 */
   uint8 dsp_icache_sec; /* SM_021 */
   uint8 dsp_iram_sec;   /* SM_022 */

   /* RA memories ECC (correctable/SEC) */
   uint8 ra_cqmem_sec;  /* SM_069 */
   uint8 ra_dpmem_sec;  /* SM_071 */
   uint8 ra_estmem_sec; /* SM_073 */
   uint8 ra_idxmem_sec; /* SM_075 */
   uint8 ra_phmem_sec;  /* SM_079 */
   uint8 ra_wcmem_sec;  /* SM_081 */
   /* SM_085: SP_AXI_M (correctable) */
   uint8 sp_axi_m_corr; /* SM_085 */

   /* SM_086: SP_AXI_S (correctable) */
   uint8 sp_axi_s_corr; /* SM_086 */

   /* SM_090: SYSMEM_ECC */
   uint8 sysmem0_sec; /* SM_090 */
   uint8 sysmem1_sec; /* SM_090 */
   /* Optional: “not recorded / overflow” bucket if your HW exposes it */
   uint8 not_recorded;
} CorrectableFaultCounters_t;

/* UNIONS --------------------------------------------------------------------*/

/* OTHER TYPEDEFS ------------------------------------------------------------*/

/* GLOBAL VARIABLES ----------------------------------------------------------*/
extern uint32_t FCCU_Multiple_Fault_List[MULTIPLE_FAULTS_STORAGE_SIZE];

/* Function Prototypes------------------------------------------------------------------------------------------------*/

FailSafe_ResetReason_T *Get_Platform_ResetReason_Info(void);
void Log_ResetReason(uint16 reset_reason);
void Log_ResetReason_Info(uint8 reset_reason);
void FailSafe_Init(void);
void FailSafe_Main_50ms(void);
extern void FailSafe_Log_ResetReason(uint16 reset_reason);
void Failsafe_WriteToNvMAndPerformReset(uint16 reset_reason);
void Log_ExceptionReason_Info(Dt_Memory_Exception_Info_T *Exception_Context, uint16 Resnum);
void Log_NOCFaultReason_Info(Dt_NOC_Fault_Info_T *NOCFaultInfo, uint16 Resnum);
void Failsafe_clear_Exception_SharedData(void);
void Log_ResetReason_Info_at_Startup(uint8 reset_reason);
#if (TRUE == ENABLE_SIT_TEST_STUBS)
void FailSafe_Integration_Test(void);
#endif
#if (TRUE == ENABLE_SQT_TEST_STUBS)
void Failsafe_SW_Quality_test(void);
#endif
/************************************************************************************************************************************
 *  Revision History
 *
 *   Date        SCR         Name             Description
 *   ----        ----        ----------- ---------------------------------------------------------------------------------------
 *
 *
 *
 * 13-Sep-2022 EEG-1267  Niveditha    Modify reset reason strategy to define Platform and Customer project boundary
 * related macros & Variables
 *
 * *************************************************************************************************************************************************/
#endif /* End _SWC_CDD_FAILSAFE_H_ */
