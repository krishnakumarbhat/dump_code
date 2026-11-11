/**************************************************************************
 * Copyright 2025 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        FailSafe \n
 * \b File-Revision:      1.0 \n
 * \b Classification:     CONFIDENTIAL \n
 *
 ***************************************************************************
 *
 *  Module Name:  FS_IntHndlr.c
 *
 *  Description:
 *    This file contains interrupt handler functions for safety mechanisms
 *    including SM043 MIPI AHB-S Parity Error handling
 *
 **************************************************************************/

/**************************************************************************
 * #Include files
 *************************************************************************/
#include "FS_IntHndlr.h"
#include "FailSafe_Callout.h"
#include "Rte_SWC_PLT_CDD_FailSafe.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "SWC_PLT_CDD_MCU_Safety.h"
#include "artie_sfrs.h"
#include "chandra_sfrs_base.h"
#include "dsp_sfrs.h"
#include "ra_sfrs.h"
#include "retention_ram_data.h"
#include "sysctrl_sfrs.h"
#include "sysmem_sfrs.h"
#include <stdint.h>
/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

#define PTR_RA           ((volatile RA_SFRS_t *)RA_base)
#define DSP              ((volatile DSP_SFRS_t *)DSP_base)
#define SYSMEM           ((volatile SYSMEM_SFRS_t *)SYSMEM_base)
#define RA_SS1_THRESHOLD 3u
#define ARTIE_REGS       ((volatile ARTIE_SFRS_t *)ARTIE_base)
#define CRG_RESET_REQ    ((volatile uint32_t *)((uintptr_t)CRG_base + 0x0CU))
/* Use reset monitor definitions from SWC_PLT_CDD_MCU_Safety.h.
 * Keep fallbacks for compile paths where FRC bits are not exported. */
#ifndef CTL_RMON_FRC_RA
   #define CTL_RMON_FRC_RA (1U << 16)
#endif
#ifndef CTL_RMON_FRC_MIPI
   #define CTL_RMON_FRC_MIPI (1U << 17)
#endif
#ifndef CTL_RMON_FRC_DSP
   #define CTL_RMON_FRC_DSP (1U << 18)
#endif
#ifndef CTL_RMON_FRC_REF
   #define CTL_RMON_FRC_REF (1U << 19)
#endif
/* FUSA_SP_IRQ_STS bits */
#define FUSA_IRQ_PARITH             (0x1U) /* PARITH */
#define FUSA_IRQ_ERROR_CORRECTED    (0x2U) /* ERRC */
#define FUSA_IRQ_FIV                (0x4U) /* FIV */
#define FUSA_IRQ_FINSV              (0x8U) /* FINSV */
#define FUSA_STATUS_MASK            (0x0000CU)
#define FUSA_IRQ_CLR_MASK           (0x3FU)
#define PFAULT_INFO_HI_ECC_ERROR    (0x00100000U)
#define PFAULT_INFO_LO_PARITY_ERROR (0x00008000U)
#define SYSCTRL                     ((volatile SYSCTRL_SFRS_t *)SYSCTRL_base)

/**************************************************************************
 * Global variables
 *************************************************************************/
volatile uint8_t sysmem0_ecc_temp = 0;
volatile uint8_t sysmem1_ecc_temp = 0;

volatile RA_R52_IRQ_Backup_t RA_R52_IRQ_backup = {0};
volatile uint8_t RA_R52_ERROR_Failure_State    = CODED_FALSE;
volatile uint8_t RA_R52_FUSA_Failure_State     = CODED_FALSE;

volatile RA_R52_IRQ_Backup_t *const ptrRA = &RA_R52_IRQ_backup;

volatile uint8 SM_064_RA_AXI_M_IN_PARITY_Cnt  = 0U;
volatile uint8 SM_065_RA_AXI_M_OUT_PARITY_Cnt = 0U;
volatile uint8 SM_066_RA_AXI_STREAM_MON_Cnt   = 0U;
volatile uint8 SM_067_RA_CMD_MON_Cnt          = 0U;
volatile uint8 SM_068_RA_CQ_OVF_MON_Cnt       = 0U;
volatile uint8 SM_069_RA_CQMEM_ECC_Cnt        = 0U;
volatile uint8 SM_070_RA_DATAPATH_MON_Cnt     = 0U;
volatile uint8 SM_071_DPMEM_ECC_Cnt           = 0U;
volatile uint8 SM_072_RA_EST_MUX_MON_Cnt      = 0U;
volatile uint8 SM_073_RA_ESTMEM_ECC_Cnt       = 0U;
volatile uint8 SM_074_RA_FSM_MONITOR_Cnt      = 0U;
volatile uint8 SM_075_RA_IDXMEX_ECC_Cnt       = 0U;
volatile uint8 SM_076_RA_CMD_MON_Cnt          = 0U;
volatile uint8 SM_077_RA_OUT_ADDR_MONITOR_Cnt = 0U;
volatile uint8 SM_079_RA_PHMEM_ECC_Cnt        = 0U;
volatile uint8 SM_080_RA_SLV_ERR_MON_Cnt      = 0U;
volatile uint8 SM_081_RA_WCMEM_ECC_Cnt        = 0U;
volatile uint8 SM_082_RA_WWDG_IS_Cnt          = 0U;
volatile uint8 SM_083_RA_WWDG_OS_Cnt          = 0U;
volatile uint8 SM_084_RA_WWDG_PS_Cnt          = 0U;

volatile uint8_t int_cnt = 0U;

static void FS_RA_Reset_Request(void)
{
   *CRG_RESET_REQ |= 0x00000001U;
   *CRG_RESET_REQ &= ~0x00000001U;
}

#define STS_P0_ECC_SEC_CNT_MASK         (0xFFFF)
#define STS_P1_ECC_SEC_CNT_MASK         (0xFFFF)
#define SYSMEM_PORT0_SEC_DED_STAT1_ADDR (*((volatile uint32_t *)(SYSMEM_base + 0x18)))
#define SYSMEM_PORT1_SEC_DED_STAT1_ADDR (*((volatile uint32_t *)(SYSMEM_base + 0x10C)))
#define CLR_ARTIE_MEM_IRQ               (0x3F) /* Clear all Artiemem IRQs */

/* Register definitions for AXI-M and AXI-S Correctable Error Handling */
#define R52_CEE_LIM_CTRL0  (*((volatile uint32_t *)0x89003100U))
#define R52_CEE_LIM_CTRL1  (*((volatile uint32_t *)0x89003104U))
#define R52_CEE_CNT_STAT0  (*((volatile uint32_t *)0x89003114U))
#define R52_CEE_CNT_STAT1  (*((volatile uint32_t *)0x89003118U))
#define R52_CEE_SNAP_CTRL  (*((volatile uint32_t *)0x89003110U))
#define R52_CEE_IRQ_STAT   (*((volatile uint32_t *)0x8900312CU))
#define R52_CEE_CLEAR_CTRL (*((volatile uint32_t *)0x89003128U))

/* Macros for AXI-S Correctable Error Handling (ErrEvent[0]) */
#define CTL_R52_CEE_LIM0_VAL                0x00000000U
#define CTL_R52_CEE_LIM0_MASK               0x0000FFFFU
#define ERREVT_0_CEE_IRQ_STAT_BIT           0U
#define ERREVT_0_CEE_SNAP_CTRL_BIT          0U
#define ERREVT_0_CEE_CNT_STAT0_MASK         0x0000FFFFU
#define ERREVT_0_CEE_IRQ_FIRED              0x00000001U // Bit 0 indicates R52 errevent[0]
#define ERREVT_0_CEE_CLEAR_CTRL_IRQ_CLR_BIT 15U         // offset for IRQ_CLR bit in CLEAR_CTRL register for ErrEvent[0]
#define ERREVT_0_CEE_CLEAR_CTRL_CLR_BIT     0U          // offset for CLR bit in CLEAR_CTRL register for ErrEvent[0]
#define ERREVT_0_CEE_CLEAR_CTRL_CNT_CLR_BIT 7U          // offset for CNT_CLR bit in CLEAR_CTRL register for ErrEvent[0]

/* Macros for AXI-S Correctable Error Handling (ErrEvent[1]) */
#define CTL_R52_CEE_LIM2_MASK                0x0000FFFFU
#define CTL_R52_CEE_LIM2_VAL                 0x00000000U
#define ERREVT0_2_CEE_IRQ_STAT_BIT           2U
#define ERREVT0_2_CEE_SNAP_CTRL_BIT          2U
#define ERREVT0_2_CEE_CNT_STAT1_MASK         0x0000FFFFU
#define ERREVT0_2_CEE_IRQ_FIRED              0x00000004U // Bit 2 indicates R52 errevent0[2]
#define ERREVT0_2_CEE_CLEAR_CTRL_IRQ_CLR_BIT 17U         // offset for IRQ_CLR bit in CLEAR_CTRL register for ErrEvent0[2]
#define ERREVT0_2_CEE_CLEAR_CTRL_CLR_BIT     2U          // offset for general CLR bit in CLEAR_CTRL register for ErrEvent0[2]
#define ERREVT0_2_CEE_CLEAR_CTRL_CNT_CLR_BIT 9U          // offset for CNT_CLR bit in CLEAR_CTRL register for ErrEvent0[2]

#ifdef UNIT_TEST
volatile SYSMEM_SFRS_t sysmem_sfrs_ut;
volatile uint32_t sysmem_port0_sec_ded_stat1_ut = 0U;
volatile uint32_t sysmem_port1_sec_ded_stat1_ut = 0U;
volatile uint32_t r52_cee_lim_ctrl0_ut          = 0U;
volatile uint32_t r52_cee_lim_ctrl1_ut          = 0U;
volatile uint32_t r52_cee_cnt_stat0_ut          = 0U;
volatile uint32_t r52_cee_cnt_stat1_ut          = 0U;
volatile uint32_t r52_cee_snap_ctrl_ut          = 0U;
volatile uint32_t r52_cee_irq_stat_ut           = 0U;
volatile uint32_t r52_cee_clear_ctrl_ut         = 0U;

   #undef SYSMEM
   #define SYSMEM ((volatile SYSMEM_SFRS_t *)&sysmem_sfrs_ut)

   #undef SYSMEM_PORT0_SEC_DED_STAT1_ADDR
   #define SYSMEM_PORT0_SEC_DED_STAT1_ADDR (sysmem_port0_sec_ded_stat1_ut)

   #undef SYSMEM_PORT1_SEC_DED_STAT1_ADDR
   #define SYSMEM_PORT1_SEC_DED_STAT1_ADDR (sysmem_port1_sec_ded_stat1_ut)

   #undef R52_CEE_LIM_CTRL0
   #define R52_CEE_LIM_CTRL0 (r52_cee_lim_ctrl0_ut)

   #undef R52_CEE_LIM_CTRL1
   #define R52_CEE_LIM_CTRL1 (r52_cee_lim_ctrl1_ut)

   #undef R52_CEE_CNT_STAT0
   #define R52_CEE_CNT_STAT0 (r52_cee_cnt_stat0_ut)

   #undef R52_CEE_CNT_STAT1
   #define R52_CEE_CNT_STAT1 (r52_cee_cnt_stat1_ut)

   #undef R52_CEE_SNAP_CTRL
   #define R52_CEE_SNAP_CTRL (r52_cee_snap_ctrl_ut)

   #undef R52_CEE_IRQ_STAT
   #define R52_CEE_IRQ_STAT (r52_cee_irq_stat_ut)

   #undef R52_CEE_CLEAR_CTRL
   #define R52_CEE_CLEAR_CTRL (r52_cee_clear_ctrl_ut)
#endif

#ifdef UNIT_TEST

volatile ARTIE_SFRS_t artie_sfrs_ut;

   /* Override ARTIE register pointer */
   #undef ARTIE_REGS
   #define ARTIE_REGS ((volatile ARTIE_SFRS_t *)&artie_sfrs_ut)

#endif
#define SHIFT_PFAULT_HI_IN_MEMERROR (20U)

/* Correctable fault counters */
static Dt_ECC_Correctable_Error_Counters ecc_correctable_cnts = {0};
/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_DSP_Clock_Monitor_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for DSP Clock Monitor failure.
 * This function is triggered when a DSP clock failure is detected
 * by the Clock Monitoring Unit (CMU).
 *
 * Actions:
 * 1. Log the reset reason as DSP clock failure
 *
 * PRECONDITIONS:
 * - DSP Clock Monitor interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_DSP_Clock_Monitor_Handler(void)
{
   /* DSP_CLK_Handler */
   FailSafe_Log_ResetReason(MCU_FAILSAFE_DSP_CLK_FAILURE);
}
/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_RA_Clock_Monitor_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for RA (Radar Accelerator) Clock Monitor failure.
 * This function is triggered when a RA clock failure is detected
 * by the Clock Monitoring Unit (CMU).
 *
 * Actions:
 * 1. Log the reset reason as RA clock failure
 *
 * PRECONDITIONS:
 * - RA Clock Monitor interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_RA_Clock_Monitor_Handler(void)
{
   /* RA_CLK_Handler */
   FailSafe_Log_ResetReason(MCU_FAILSAFE_RA_CLK_FAILURE);
}
/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_Reset_Monitor_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Reset Monitor faults.
 * Reset Monitor of software-serviceable reset faults (RA, MIPI, DSP, REF) will trigger this interrupt.
 *
 * Actions:
 * 1. Log the reset reason as Reset Monitor - RA, MIPI, DSP, REF failure
 *
 * PRECONDITIONS:
 * - Reset Monitor interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_Reset_Monitor_Handler(void)
{
   uint32_t swStatus;
   uint32_t serStatus;

   /* -------------------------------------------------
    * 1. Snapshot status registers, then W1C-clear
    *    only the recognised fault bits (masked writes).
    *    Using the snapshot ensures that any bit arriving
    *    between the read and the write is NOT cleared
    *    (W1C: writing 0 = no-op), so it stays pending
    *    for the next ISR entry.
    * ------------------------------------------------- */
   swStatus = IRQ_RMON;

   CTL_RMON &= ~(CTL_RMON_FRC_RA | CTL_RMON_FRC_MIPI | CTL_RMON_FRC_DSP | CTL_RMON_FRC_REF);
   IRQ_RMON = (IRQ_RMON_RA_BIT | IRQ_RMON_MIPI_BIT | IRQ_RMON_DSP_BIT | IRQ_RMON_REF_BIT);

   serStatus                        = MCU_SAFETY_MISC0_IRQ_MASKED_STAT;
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT = serStatus & IRQ_RMON_SER_BIT; /* W1C: clear only STS_RMON_SER (bit 8) */

   /* -------------------------------------------------
    * 2. Determine fault source and log reset reason.
    *    FailSafe_Log_ResetReason does NOT return
    *    (triggers MCU reset), so the priority order is
    *    implicit: RA > MIPI > DSP > REF > SER.
    *
    *    Use exact value comparison to handle single faults only.
    * ------------------------------------------------- */
   if (swStatus & IRQ_RMON_RA_BIT)
   {
      // CTL_RMON &= ~CTL_RMON_FRC_RA;
      FailSafe_Log_ResetReason(MCU_FAILSAFE_RMON_RA_FAILURE);
   }
   else if (swStatus & IRQ_RMON_MIPI_BIT)
   {
      FailSafe_Log_ResetReason(MCU_FAILSAFE_RMON_MIPI_FAILURE);
   }
   else if (swStatus & IRQ_RMON_DSP_BIT)
   {
      FailSafe_Log_ResetReason(MCU_FAILSAFE_RMON_DSP_FAILURE);
   }
   else if (swStatus & IRQ_RMON_REF_BIT)
   {
      FailSafe_Log_ResetReason(MCU_FAILSAFE_RMON_REF_FAILURE);
   }
   else if (serStatus & IRQ_RMON_SER_BIT)
   {
      FailSafe_Log_ResetReason(MCU_FAILSAFE_RMON_SER_FAILURE);
   }
   else
   {
      /* Spurious IRQ — no recognized source active. Return without
         triggering a reset to avoid an unnecessary ECU restart. */
   }
}
/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_MIPI_Clock_Monitor_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for MIPI Clock Monitor failure.
 * This function is triggered when a MIPI clock failure is detected
 * by the Clock Monitoring Unit (CMU).
 *
 * Actions:
 * 1. Log the reset reason as MIPI clock failure
 *
 * PRECONDITIONS:
 * - MIPI Clock Monitor interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_MIPI_Clock_Monitor_Handler(void)
{
   /* MIPI_CLK_Handler */
   FailSafe_Log_ResetReason(MCU_FAILSAFE_MIPI_CLK_FAILURE);
}
/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_Serial_Clock_Monitor_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 * Retention_Ram_Data - Retention RAM data structure
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Serial (SERDES) Clock Monitor failure.
 * This function is triggered when a Serial clock failure is detected
 * by the Clock Monitoring Unit (CMU).
 *
 * Actions:
 * 1. Store reset reason in retention RAM
 * 2. Log the reset reason as Serial clock failure
 *
 * PRECONDITIONS:
 * - Serial Clock Monitor interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason stored in retention RAM
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_Serial_Clock_Monitor_Handler(void)
{
   /* SERIAL_CLK_Handler */
   Retention_Ram_Data.Exception_data.reset_number = MCU_FAILSAFE_SERIAL_CLK_FAILURE;
   FailSafe_Log_ResetReason(MCU_FAILSAFE_SERIAL_CLK_FAILURE);
}

/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_BBE_SP_FUSA_IRQ_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * DSP - DSP register structure pointer for accessing FUSA_IRQ_STS register
 * FailSafe_Log_ResetReason - Function to log reset reason for diagnostics
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for BBE32 (DSP) Functional Safety errors.
 * This function is triggered when the DSP detects ECC errors on the AXI bus.
 *
 * Safety Mechanism Handled:
 * - SM 017: DSP AXI ECC Error - Detects ECC errors in DSP AXI transactions
 *
 * Actions:
 * 1. Read the DSP FUSA_IRQ_STS register to check for active errors
 * 2. If any error bit is set (FUSA_IRQ_STS != 0), specifically checking for
 *    ECC errors, log the reset reason as FAILSAFE_SM_017_DSP_AXI_ECC
 * 3. This triggers a transition to Safe State (SS1) via the reset mechanism
 *
 * PRECONDITIONS:
 * - BBE32 DSP must be initialized and running
 * - DSP FUSA interrupt must be enabled in the interrupt controller
 * - DSP register pointer must be valid
 *
 * POSTCONDITIONS:
 * - If ECC error detected, reset reason is logged for diagnostic purposes
 * - System will transition to safe state if error is confirmed
 */
/*===========================================================================*/

void Os_Isr_BBE_SP_FUSA_IRQ_Handler(void)
{
#ifndef UNIT_TEST

   uint32_t fusa_status;
   fusa_status = DSP->FUSA_IRQ_STS;

   /* ==========================================================
    * DED ECC
    * ========================================================== */
   if (((DSP->PFAULT_INFO_HI & PFAULT_INFO_HI_ECC_ERROR) != 0U) && ((DSP->FUSA_IRQ_STS & FUSA_IRQ_FIV) != 0U))
   {
      FailSafe_Log_ResetReason(FAILSAFE_SM_020_DSP_DRAM_ECC);
   }
   /* ==========================================================
    * CSR Parity
    * ========================================================== */
   else if (((DSP->PFAULT_INFO_LO & PFAULT_INFO_LO_PARITY_ERROR) != 0U) && ((DSP->FUSA_IRQ_STS & FUSA_STATUS_MASK) != 0U))
   {
      FailSafe_Log_ResetReason(FAILSAFE_SM_018_DSP_CSR_PARITY);
   }
   /* ==========================================================
    * SEC ECC
    * ========================================================== */
   else if ((fusa_status & FUSA_IRQ_ERROR_CORRECTED) != 0U)
   {
      ecc_correctable_cnts.dsp_dram_sec++;

      (void)Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&ecc_correctable_cnts);

      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);
   }
   /* ==========================================================
    * AXI ECC
    * ========================================================== */
   else if ((fusa_status & (1U << FUSA_IRQ_FIV)) != 0U)
   {
      FailSafe_Log_ResetReason(FAILSAFE_SM_017_DSP_AXI_ECC);
   }
   DSP->FUSA_IRQ_CLR = FUSA_IRQ_CLR_MASK;
#endif
}
#ifndef UNIT_TEST

static void FS_RA_ERROR_SM066_Check(void)
{
   uint32_t sm066 = (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.OM_SSS_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.OM_SSL_IRQ_R52_ERR_FLAG;
   SM_066_RA_AXI_STREAM_MON_Cnt += (uint8)(sm066 != 0U);
}

static void FS_RA_ERROR_SM067_Check(void)
{
   SM_067_RA_CMD_MON_Cnt += (uint8)(ptrRA->R52_ERR_IRQ_FLAG_1.f.INVALID_CONFIG_IRQ_R52_ERR_FLAG != 0U);
}

static void FS_RA_ERROR_SM068_Check(void)
{
   SM_068_RA_CQ_OVF_MON_Cnt += (uint8)(ptrRA->R52_ERR_IRQ_FLAG_1.f.CQ_OVF_IRQ_R52_ERR_FLAG != 0U);
}

static void FS_RA_ERROR_SM070_Check(void)
{
   uint32_t sm070 = (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.DECOMP_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.PREPROC_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.FFT_CORE_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.POSPROC_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.PREP_SUM_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.PREP_OFFSET_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.PREP_DIVIDER_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.POSP_SUM_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.POSP_OFFSET_OVF_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.POSP_DIVIDER_ERR_IRQ_R52_ERR_FLAG;
   SM_070_RA_DATAPATH_MON_Cnt += (uint8)(sm070 != 0U);
}

static void FS_RA_ERROR_SM072_Check(void)
{
   uint32_t sm072 = (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.EST_MUX_1_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.EST_MUX_2_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.EST_MUX_3_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_2.f.EST_MUX_4_IRQ_R52_ERR_FLAG;
   SM_072_RA_EST_MUX_MON_Cnt += (uint8)(sm072 != 0U);
}

static void FS_RA_ERROR_SM076_Check(void)
{
   uint32_t sm076 = (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CQMEM_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.WCMEM_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.WCMEM_BUSY_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.IDXMEM_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.IDXMEM_BUSY_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.PHMEM_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.PHMEM_BUSY_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.ESTMEM_1_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.ESTMEM_2_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.ESTMEM_3_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.ESTMEM_4_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CIMEM1_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CIMEM2_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CIMEM3_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CIMEM4_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CIMEM4_AHB_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.DPMEM_MUX_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.CIMEM_MUX_ERR_IRQ_R52_ERR_FLAG;
   SM_076_RA_CMD_MON_Cnt += (uint8)(sm076 != 0U);
}

static void FS_RA_ERROR_SM077_Check(void)
{
   SM_077_RA_OUT_ADDR_MONITOR_Cnt += (uint8)(ptrRA->R52_ERR_IRQ_FLAG_2.f.OUT_ADDR_RANGE_IRQ_R52_ERR_FLAG != 0U);
}

static void FS_RA_ERROR_SM080_Check(void)
{
   uint32_t sm080 = (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.AXI_IN_RESP_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)ptrRA->R52_ERR_IRQ_FLAG_1.f.AXI_OUT_RESP_ERR_IRQ_R52_ERR_FLAG;
   SM_080_RA_SLV_ERR_MON_Cnt += (uint8)(sm080 != 0U);
}

static void FS_RA_ERROR_SM082_Check(void)
{
   SM_082_RA_WWDG_IS_Cnt += (uint8)(ptrRA->R52_ERR_IRQ_FLAG_1.f.IN_STAGE_WDT_IRQ_R52_ERR_FLAG != 0U);
}

static void FS_RA_ERROR_SM083_Check(void)
{
   SM_083_RA_WWDG_OS_Cnt += (uint8)(ptrRA->R52_ERR_IRQ_FLAG_1.f.OUT_STAGE_WDT_IRQ_R52_ERR_FLAG != 0U);
}

static void FS_RA_ERROR_SM084_Check(void)
{
   SM_084_RA_WWDG_PS_Cnt += (uint8)(ptrRA->R52_ERR_IRQ_FLAG_1.f.PROC_STAGE_WDT_IRQ_R52_ERR_FLAG != 0U);
}

static void FS_RA_ERROR_Update_Counters(void)
{
   FS_RA_ERROR_SM066_Check();
   FS_RA_ERROR_SM067_Check();
   FS_RA_ERROR_SM068_Check();
   FS_RA_ERROR_SM070_Check();
   FS_RA_ERROR_SM072_Check();
   FS_RA_ERROR_SM076_Check();
   FS_RA_ERROR_SM077_Check();
   FS_RA_ERROR_SM080_Check();
   FS_RA_ERROR_SM082_Check();
   FS_RA_ERROR_SM083_Check();
   FS_RA_ERROR_SM084_Check();
}

static void FS_RA_FUSA_SM064_Check(void)
{
   SM_064_RA_AXI_M_IN_PARITY_Cnt += (uint8)(ptrRA->R52_FUSA_IRQ_FLAG.f.AXI_IN_PARITY_CHK_IRQ_R52_FUSA_FLAG != 0U);
}

static void FS_RA_FUSA_SM065_Check(void)
{
   SM_065_RA_AXI_M_OUT_PARITY_Cnt += (uint8)(ptrRA->R52_FUSA_IRQ_FLAG.f.AXI_OUT_PARITY_CHK_IRQ_R52_FUSA_FLAG != 0U);
}

static void FS_RA_FUSA_SM069_Check(void)
{
   uint32_t sm069 = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_CQMEM_IRQ_R52_FUSA_FLAG;
   SM_069_RA_CQMEM_ECC_Cnt += (uint8)(sm069 != 0U);
}

static void FS_RA_FUSA_SM071_Check(void)
{
   uint32_t sm071 = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_0_IRQ_R52_FUSA_FLAG |
                    (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_1_IRQ_R52_FUSA_FLAG |
                    (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_2_IRQ_R52_FUSA_FLAG |
                    (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_3_IRQ_R52_FUSA_FLAG;
   SM_071_DPMEM_ECC_Cnt += (uint8)(sm071 != 0U);
}

static void FS_RA_FUSA_SM073_Check(void)
{
   uint32_t sm073 = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_1_IRQ_R52_FUSA_FLAG |
                    (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_2_IRQ_R52_FUSA_FLAG |
                    (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_3_IRQ_R52_FUSA_FLAG |
                    (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_4_IRQ_R52_FUSA_FLAG;
   SM_073_RA_ESTMEM_ECC_Cnt += (uint8)(sm073 != 0U);
}

static void FS_RA_FUSA_SM074_Check(void)
{
   SM_074_RA_FSM_MONITOR_Cnt += (uint8)(ptrRA->R52_FUSA_IRQ_FLAG.f.FSM_ERR_IRQ_R52_FUSA_FLAG != 0U);
}

static void FS_RA_FUSA_SM075_Check(void)
{
   uint32_t sm075 = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_IDXMEM_IRQ_R52_FUSA_FLAG;
   SM_075_RA_IDXMEX_ECC_Cnt += (uint8)(sm075 != 0U);
}

static void FS_RA_FUSA_SM079_Check(void)
{
   uint32_t sm079 = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_PHMEM_IRQ_R52_FUSA_FLAG;
   SM_079_RA_PHMEM_ECC_Cnt += (uint8)(sm079 != 0U);
}

static void FS_RA_FUSA_SM081_Check(void)
{
   uint32_t sm081 = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_WCMEM_IRQ_R52_FUSA_FLAG;
   SM_081_RA_WCMEM_ECC_Cnt += (uint8)(sm081 != 0U);
}

static void FS_RA_FUSA_Update_Counters(void)
{
   FS_RA_FUSA_SM064_Check();
   FS_RA_FUSA_SM065_Check();
   FS_RA_FUSA_SM069_Check();
   FS_RA_FUSA_SM071_Check();
   FS_RA_FUSA_SM073_Check();
   FS_RA_FUSA_SM074_Check();
   FS_RA_FUSA_SM075_Check();
   FS_RA_FUSA_SM079_Check();
   FS_RA_FUSA_SM081_Check();
}

static void FS_RA_FUSA_Clear_ECC_Sec_Counters(void)
{
   uint32_t cqmem_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_CQMEM_IRQ_R52_FUSA_FLAG |
                        (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_CQMEM_IRQ_R52_FUSA_FLAG;
   uint32_t dpmem0_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_DPMEM_0_IRQ_R52_FUSA_FLAG |
                         (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_0_IRQ_R52_FUSA_FLAG;
   uint32_t dpmem1_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_DPMEM_1_IRQ_R52_FUSA_FLAG |
                         (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_1_IRQ_R52_FUSA_FLAG;
   uint32_t dpmem2_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_DPMEM_2_IRQ_R52_FUSA_FLAG |
                         (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_2_IRQ_R52_FUSA_FLAG;
   uint32_t dpmem3_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_DPMEM_3_IRQ_R52_FUSA_FLAG |
                         (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_DPMEM_3_IRQ_R52_FUSA_FLAG;
   uint32_t estmem1_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_1_IRQ_R52_FUSA_FLAG |
                          (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_1_IRQ_R52_FUSA_FLAG;
   uint32_t estmem2_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_2_IRQ_R52_FUSA_FLAG |
                          (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_2_IRQ_R52_FUSA_FLAG;
   uint32_t estmem3_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_3_IRQ_R52_FUSA_FLAG |
                          (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_3_IRQ_R52_FUSA_FLAG;
   uint32_t estmem4_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_ESTMEM_4_IRQ_R52_FUSA_FLAG |
                          (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_ESTMEM_4_IRQ_R52_FUSA_FLAG;
   uint32_t idxmem_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_IDXMEM_IRQ_R52_FUSA_FLAG |
                         (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_IDXMEM_IRQ_R52_FUSA_FLAG;
   uint32_t phmem_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_PHMEM_IRQ_R52_FUSA_FLAG |
                        (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_PHMEM_IRQ_R52_FUSA_FLAG;
   uint32_t wcmem_ecc = (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_SEC_CNT_WCMEM_IRQ_R52_FUSA_FLAG |
                        (uint32_t)ptrRA->R52_FUSA_IRQ_FLAG.f.ECC_DED_WCMEM_IRQ_R52_FUSA_FLAG;

   if (cqmem_ecc != 0U)
   {
      PTR_RA->CQMEM_ECC_CONTROL.f.CQMEM_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->CQMEM_ECC_CONTROL.f.CQMEM_ECC_SEC_CNT_CLR = 0U;
   }

   if (wcmem_ecc != 0U)
   {
      PTR_RA->WCMEM_ECC_CONTROL.f.WCMEM_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->WCMEM_ECC_CONTROL.f.WCMEM_ECC_SEC_CNT_CLR = 0U;
   }

   if (idxmem_ecc != 0U)
   {
      PTR_RA->IDXMEM_ECC_CONTROL.f.IDXMEM_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->IDXMEM_ECC_CONTROL.f.IDXMEM_ECC_SEC_CNT_CLR = 0U;
   }

   if (phmem_ecc != 0U)
   {
      PTR_RA->PHMEM_ECC_CONTROL.f.PHMEM_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->PHMEM_ECC_CONTROL.f.PHMEM_ECC_SEC_CNT_CLR = 0U;
   }

   if (estmem1_ecc != 0U)
   {
      PTR_RA->ESTMEM_1_ECC_CONTROL.f.ESTMEM_1_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->ESTMEM_1_ECC_CONTROL.f.ESTMEM_1_ECC_SEC_CNT_CLR = 0U;
   }

   if (estmem2_ecc != 0U)
   {
      PTR_RA->ESTMEM_2_ECC_CONTROL.f.ESTMEM_2_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->ESTMEM_2_ECC_CONTROL.f.ESTMEM_2_ECC_SEC_CNT_CLR = 0U;
   }

   if (estmem3_ecc != 0U)
   {
      PTR_RA->ESTMEM_3_ECC_CONTROL.f.ESTMEM_3_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->ESTMEM_3_ECC_CONTROL.f.ESTMEM_3_ECC_SEC_CNT_CLR = 0U;
   }

   if (estmem4_ecc != 0U)
   {
      PTR_RA->ESTMEM_4_ECC_CONTROL.f.ESTMEM_4_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->ESTMEM_4_ECC_CONTROL.f.ESTMEM_4_ECC_SEC_CNT_CLR = 0U;
   }

   if (dpmem0_ecc != 0U)
   {
      PTR_RA->DPMEM_0_ECC_CONTROL.f.DPMEM_0_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->DPMEM_0_ECC_CONTROL.f.DPMEM_0_ECC_SEC_CNT_CLR = 0U;
   }

   if (dpmem1_ecc != 0U)
   {
      PTR_RA->DPMEM_1_ECC_CONTROL.f.DPMEM_1_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->DPMEM_1_ECC_CONTROL.f.DPMEM_1_ECC_SEC_CNT_CLR = 0U;
   }

   if (dpmem2_ecc != 0U)
   {
      PTR_RA->DPMEM_2_ECC_CONTROL.f.DPMEM_2_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->DPMEM_2_ECC_CONTROL.f.DPMEM_2_ECC_SEC_CNT_CLR = 0U;
   }

   if (dpmem3_ecc != 0U)
   {
      PTR_RA->DPMEM_3_ECC_CONTROL.f.DPMEM_3_ECC_SEC_CNT_CLR = 1U;
      PTR_RA->DPMEM_3_ECC_CONTROL.f.DPMEM_3_ECC_SEC_CNT_CLR = 0U;
   }
}

void FS_RA_Process_Failure_Cnts(void)
{
   FS_RA_ERROR_Update_Counters();
   FS_RA_FUSA_Update_Counters();

   RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_1.r = 0x00000000U;
   RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_2.r = 0x00000000U;
   RA_R52_IRQ_backup.R52_FUSA_IRQ_FLAG.r  = 0x00000000U;
}

#endif

/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_RA_ERROR_IRQ_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * ptrRA - Pointer to Radar Accelerator (RA) Special Function Registers
 * R52_ERR_IRQ_FLAG_1 - RA error interrupt flag register 1
 * R52_ERR_IRQ_FLAG_2 - RA error interrupt flag register 2
 * SM_0xx counters - Safety Mechanism error counters (volatile globals)
 * RA_SM_Failure - Global flag to indicate RA safety mechanism failure
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Radar Accelerator (RA) operational errors (ISR 77).
 * This function monitors multiple Safety Mechanisms by checking error flags
 * in R52_ERR_IRQ_FLAG_1 and R52_ERR_IRQ_FLAG_2 registers and maintains
 * error counters for fault tolerance.
 *
 * Safety Mechanisms Handled:
 * - SM 066: RA AXI Stream Monitor (OM_SSS_IRQ, OM_SSL_IRQ errors)
 * - SM 067: RA Command Monitor (Invalid configuration errors)
 * - SM 068: RA Command Queue Overflow Monitor
 * - SM 070: RA Datapath Monitor (Overflow errors in decompressor, preprocessor,
 *           FFT core, postprocessor, sum/offset/divider operations)
 * - SM 072: RA Estimation MUX Monitor (EST_MUX 1-4 errors)
 * - SM 076: RA Command Monitor (AHB errors for CQMEM, WCMEM, IDXMEM, PHMEM,
 *           ESTMEM 1-4, CIMEM 1-4, DPMEM MUX, CIMEM MUX)
 * - SM 077: RA Output Address Monitor (Address range errors)
 * - SM 080: RA Slave Error Monitor (AXI input/output response errors)
 * - SM 082: RA Window Watchdog In-Stage (Input stage timeout)
 * - SM 083: RA Window Watchdog Out-Stage (Output stage timeout)
 * - SM 084: RA Window Watchdog Proc-Stage (Processing stage timeout)
 *
 * Actions:
 * 1. Check each error flag in R52_ERR_IRQ_FLAG_1 and R52_ERR_IRQ_FLAG_2
 * 2. Increment the corresponding SM error counter for each detected fault
 * 3. If any SM counter exceeds threshold (>3), set RA_SM_Failure=CODED_TRUE
 *    to trigger Safe State 1 (SS1) transition
 * 4. Clear all error flags by writing 0xFFFFFFFF to both flag registers
 *
 * Fault Tolerance Strategy:
 * - Errors are counted rather than immediately triggering safe state
 * - Threshold of 3 allows for transient fault filtering
 * - Same error must occur >3 times before safety reaction
 *
 * PRECONDITIONS:
 * - Radar Accelerator must be initialized
 * - RA_ERROR interrupt must be enabled in the interrupt controller
 * - ptrRA must point to valid RA register space
 *
 * POSTCONDITIONS:
 * - All checked SM counters updated based on detected errors
 * - RA_SM_Failure set to CODED_TRUE if any counter exceeds threshold
 * - R52_ERR_IRQ_FLAG_1 and R52_ERR_IRQ_FLAG_2 registers cleared
 */
/*===========================================================================*/

void Os_Isr_RA_ERROR_IRQ_Handler(void) /* ISR 77 */
{
#ifndef UNIT_TEST
   uint32_t sm067_or_sm080;
   int_cnt++;
   /* Capture the flag status */
   RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_1.r = PTR_RA->R52_ERR_IRQ_FLAG_1.r;
   RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_2.r = PTR_RA->R52_ERR_IRQ_FLAG_2.r;

   sm067_or_sm080 = (uint32_t)RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_1.f.INVALID_CONFIG_IRQ_R52_ERR_FLAG |
                    (uint32_t)RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_1.f.AXI_IN_RESP_ERR_IRQ_R52_ERR_FLAG |
                    (uint32_t)RA_R52_IRQ_backup.R52_ERR_IRQ_FLAG_1.f.AXI_OUT_RESP_ERR_IRQ_R52_ERR_FLAG;

   /* SM67 and SM80 can leave RA stalled; reset RA before clearing their flags. */
   if (sm067_or_sm080 != 0U)
   {
      FS_RA_Reset_Request();
   }

   RA_R52_ERROR_Failure_State = CODED_TRUE;

   PTR_RA->R52_ERR_IRQ_FLAG_1.r = (uint32)0xFFFFFFFFU; // clear all flags after handling
   PTR_RA->R52_ERR_IRQ_FLAG_2.r = (uint32)0xFFFFFFFFU; // clear all flags after handling
   PTR_RA->R52_FUSA_IRQ_FLAG.r  = (uint32)0xFFFFFFFFU; // clear all flags after handling
#endif
}

/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_RA_FUSA_IRQ_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * ptrRA - Pointer to Radar Accelerator (RA) Special Function Registers
 * R52_FUSA_IRQ_FLAG - RA Functional Safety interrupt flag register
 * SM_0xx counters - Safety Mechanism error counters (volatile globals)
 * RA_SM_Failure - Global flag to indicate RA safety mechanism failure
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Radar Accelerator (RA) Functional Safety errors (ISR 78).
 * This function monitors ECC (Error Correction Code) and parity errors for
 * various RA internal memories to ensure data integrity. It reads the
 * R52_FUSA_IRQ_FLAG register and maintains error counters for fault tolerance.
 *
 * Safety Mechanisms Handled:
 * - SM 064: RA AXI Master Input Parity Check (AXI_IN_PARITY_CHK)
 * - SM 065: RA AXI Master Output Parity Check (AXI_OUT_PARITY_CHK)
 * - SM 069: RA Command Queue Memory ECC (CQMEM SEC/DED errors)
 * - SM 071: RA Data Path Memory ECC (DPMEM 0-3 SEC/DED errors)
 * - SM 073: RA Estimation Memory ECC (ESTMEM 1-4 SEC/DED errors)
 * - SM 074: RA FSM Monitor (Finite State Machine errors)
 * - SM 075: RA Index Memory ECC (IDXMEM SEC/DED errors)
 * - SM 079: RA Phase Memory ECC (PHMEM SEC/DED errors)
 * - SM 081: RA Window Coefficient Memory ECC (WCMEM SEC/DED errors)
 *
 * Note: SEC = Single-bit Error Corrected (correctable)
 *       DED = Double-bit Error Detected (uncorrectable)
 *
 * Actions:
 * 1. Check each FUSA flag in R52_FUSA_IRQ_FLAG register
 * 2. Increment the corresponding SM error counter for each detected fault
 * 3. If any SM counter exceeds threshold (>3), set RA_SM_Failure=CODED_TRUE
 *    to trigger Safe State 1 (SS1) transition
 * 4. Clear all FUSA flags by writing 0xFFFFFFFF to R52_FUSA_IRQ_FLAG register
 *
 * Fault Tolerance Strategy:
 * - Both correctable (SEC) and uncorrectable (DED) errors increment counters
 * - Threshold of 3 allows for transient fault filtering
 * - Multiple memory regions monitored for comprehensive coverage
 *
 * PRECONDITIONS:
 * - Radar Accelerator must be initialized with ECC/parity checking enabled
 * - RA_FUSA interrupt must be enabled in the interrupt controller
 * - ptrRA must point to valid RA register space
 *
 * POSTCONDITIONS:
 * - All checked SM counters updated based on detected errors
 * - RA_SM_Failure set to CODED_TRUE if any counter exceeds threshold
 * - R52_FUSA_IRQ_FLAG register cleared
 */
/*===========================================================================*/

void Os_Isr_RA_FUSA_IRQ_Handler(void)
{
#ifndef UNIT_TEST

   RA_R52_IRQ_backup.R52_FUSA_IRQ_FLAG.r = PTR_RA->R52_FUSA_IRQ_FLAG.r;
   RA_R52_FUSA_Failure_State             = CODED_TRUE;
   FS_RA_FUSA_Clear_ECC_Sec_Counters();

   PTR_RA->R52_FUSA_IRQ_FLAG.r  = (uint32)0xFFFFFFFFU; // clear all flags after handling
   PTR_RA->R52_ERR_IRQ_FLAG_1.r = (uint32)0xFFFFFFFFU; // clear all flags after handling
   PTR_RA->R52_ERR_IRQ_FLAG_2.r = (uint32)0xFFFFFFFFU; // clear all flags after handling

#endif
}

/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_Sysmem0_Fusa_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Sysmem0 FUSA failure.
 * This function is triggered when a Sysmem0 failure is detected.
 *
 * Actions:
 * 1. Log the reset reason as Sysmem1 failure
 *
 * PRECONDITIONS:
 * - Sysmem1 FUSA interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_Sysmem0_Fusa_Handler(void)
{
   /* sysmem0_fusa_irq_handler */
   sysmem0_ecc_temp++;

   /* Read IRQ status to determine actual interrupt source */
   uint32 irq_status = SYSMEM->IRQ_STAT0;

   /* Read SEC counter first to check if errors occurred */
   SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_SNAP_SEC_CNT = 1;
   SYSMEM->PORT0_SEC_CNT_CTRL0.f.CTL_P0_SNAP_SEC_CNT = 0;
   uint16 sec_count                                  = (uint16_t)(SYSMEM_PORT0_SEC_DED_STAT1_ADDR & STS_P0_ECC_SEC_CNT_MASK);

   /* Check DED sticky to see if it's a real uncorrectable error */
   uint32 ded_sticky = SYSMEM->PORT0_SEC_DED_STAT0.f.STS_P0_ECC_DED_STICKY;

   /* Handle Port 0 DED when DED IRQ bit is set and DED sticky is present. */
   if ((irq_status & 0x00000400u) && (ded_sticky != 0u))
   {
      /* Clear SEC counter (DED also increments SEC counter) */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 0;

      /* Clear SEC sticky */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_STICKY = 0;

      /* Clear DED sticky */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 0;

      /* Clear both Port0 SEC/DED IRQ status bits after DED handling */
      SYSMEM->IRQ_STAT0 = 0x00000400;
      /* Real DED error - critical, trigger reset */
      FailSafe_Log_ResetReason(FAILSAFE_SM_090_SYSMEM0);
   }

   /* Handle Port 0 SEC threshold and mixed Port0 IRQ indications as SEC path. */
   else if ((irq_status & 0x00000800u) ||
            ((irq_status & 0x00000400u) && (((irq_status & 0x00000800u) != 0u) || (sec_count > 0u && ded_sticky == 0u))))
   {
      uint16_t sec_increment = (sec_count > 0u) ? sec_count : 1u;

      /* SEC error - increment counter by the hardware count */
      ecc_correctable_cnts.sysmem0_sec += sec_increment;

      /*RTE call to write to NVM */
      (void)Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&ecc_correctable_cnts);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);

      /* Clear SEC hardware counter */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_CNT = 0;

      /* Clear SEC sticky */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_SEC_STICKY = 0;

      /* Clear DED sticky as well to remove stale DED indication from previous runs */
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 1;
      SYSMEM->PORT0_CLEAR_ERR_CTRL0.f.CLR_P0_ECC_DED_STICKY = 0;

      /* Clear both SEC and DED IRQ status bits */
      SYSMEM->IRQ_STAT0 = 0x00000C00;
   }
}
/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_Sysmem1_Fusa_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Sysmem1 FUSA failure.
 * This function is triggered when a Sysmem1 failure is detected.
 *
 * Actions:
 * 1. Log the reset reason as Sysmem1 failure
 *
 * PRECONDITIONS:
 * - Sysmem1 FUSA interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*===========================================================================*/
void Os_Isr_Sysmem1_Fusa_Handler(void)
{
   /* sysmem1_fusa_irq_handler */
   sysmem1_ecc_temp++;

   /* Read IRQ status to determine actual interrupt source */
   uint32 irq_status = SYSMEM->IRQ_STAT0;

   /* Read SEC counter first to check if errors occurred */
   SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_SNAP_SEC_CNT = 1;
   SYSMEM->PORT1_SEC_CNT_CTRL0.f.CTL_P1_SNAP_SEC_CNT = 0;
   uint16 sec_count                                  = (uint16_t)(SYSMEM_PORT1_SEC_DED_STAT1_ADDR & STS_P1_ECC_SEC_CNT_MASK);

   /* Check DED sticky to see if it's a real uncorrectable error */
   uint32 ded_sticky = SYSMEM->PORT1_SEC_DED_STAT0.f.STS_P1_ECC_DED_STICKY;

   /* Handle Port 1 DED when DED IRQ bit is set and DED sticky is present. */
   if ((irq_status & 0x04000000u) && (ded_sticky != 0u))
   {
      /* Clear SEC counter (DED also increments SEC counter) */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT = 0;

      /* Clear SEC sticky */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_STICKY = 0;

      /* Clear DED sticky */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 0;

      /* Clear both Port1 SEC/DED IRQ status bits after DED handling */
      SYSMEM->IRQ_STAT0 = 0x04000000;
      /* Real DED error - critical, trigger reset */
      FailSafe_Log_ResetReason(FAILSAFE_SM_090_SYSMEM1);
   }

   /* Handle Port 1 SEC threshold and mixed Port1 IRQ indications as SEC path. */
   else if ((irq_status & 0x08000000u) ||
            ((irq_status & 0x04000000u) && (((irq_status & 0x08000000u) != 0u) || (sec_count > 0u && ded_sticky == 0u))))
   {
      uint16_t sec_increment = (sec_count > 0u) ? sec_count : 1u;

      /* SEC error - increment counter by the hardware count */
      ecc_correctable_cnts.sysmem1_sec += sec_increment;
      /* RTE call to write to NVM */
      (void)Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&ecc_correctable_cnts);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);

      /* Clear SEC hardware counter */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_CNT = 0;

      /* Clear SEC sticky */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_SEC_STICKY = 0;

      /* Clear DED sticky as well to remove stale DED indication from previous runs */
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 1;
      SYSMEM->PORT1_CLEAR_ERR_CTRL0.f.CLR_P1_ECC_DED_STICKY = 0;

      /* Clear both SEC and DED IRQ status bits */
      SYSMEM->IRQ_STAT0 = 0x0C000000;
   }
}

/*==========================================================================*/
/**
 * FUNCTION: Initalize_CEE_Limit
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Function to Initialize the Threshold limit for correctable errors for AXI-S and AXI-M interfaces.
 * if Correctable error exceed thrshold it will Triggre the HW Interrupt
 *
 * Actions:
 * 1. Set the R52_CEE_LIM_CTRL0 & R52_CEE_LIM_CTRL1 registers with predefined threshold values for AXI-S and AXI-M correctable
 *errors.
 *
 * PRECONDITIONS:
 * - NA.
 *
 * POSTCONDITIONS:
 * - NA.
 */
/*===========================================================================*/

void Initalize_CEE_Limit(void)
{
   /* Initalize CEE Limit for AXI-S */
   R52_CEE_LIM_CTRL0 = ((R52_CEE_LIM_CTRL0 & ~CTL_R52_CEE_LIM0_MASK) |
                        (CTL_R52_CEE_LIM0_VAL & CTL_R52_CEE_LIM0_MASK)); // Updateting Bit(0-15) with 0

   /* Initalize CEE Limit for AXI-M */
   R52_CEE_LIM_CTRL1 = ((R52_CEE_LIM_CTRL1 & ~CTL_R52_CEE_LIM2_MASK) |
                        (CTL_R52_CEE_LIM2_VAL & CTL_R52_CEE_LIM2_MASK)); // Updateting Bit(0-15) with 0
}

/*==========================================================================*/
/**
 * FUNCTION: Monitor_Correctable_Errors
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Function to monitor correctable errors for AXI-S and AXI-M interfaces.
 *
 * Actions:
 * Call Monitor_AXI_S_Correctable_Errors and Monitor_AXI_M_Correctable_Errors functions to check for correctable errors on AXI-S
 *and AXI-M interfaces respectively, update the respective counters and trigger NVM write if any correctable error is detected.
 *
 * PRECONDITIONS:
 * - NA.
 *
 * POSTCONDITIONS:
 * - NA.
 */
/*===========================================================================*/
void Monitor_Correctable_Errors(void)
{
   Monitor_AXI_S_Correctable_Errors();
   Monitor_AXI_M_Correctable_Errors();
}

/*==========================================================================*/
/**
 * FUNCTION: Monitor_AXI_S_Correctable_Errors
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Function to monitor correctable errors for AXI-S interfaces.
 *
 * Actions:
 * Call Monitor_AXI_S_Correctable_Errors function to check for correctable errors on AXI-S interface,
 * update the respective counters and trigger NVM write if any correctable error is detected.
 *
 * PRECONDITIONS:
 * - NA.
 *
 * POSTCONDITIONS:
 * - NA.
 */
/*===========================================================================*/
void Monitor_AXI_S_Correctable_Errors(void)
{
   uint16_t cee_count_axi_s;
   /* Monitor AXI-S correctable errors */
   if ((R52_CEE_IRQ_STAT & (1 << ERREVT_0_CEE_IRQ_STAT_BIT)) == ERREVT_0_CEE_IRQ_FIRED)
   {
      /* Toggle ERREVT0 bit to ‘1’ then back to ‘0’ to take a snapshot of respective correctable counter */
      R52_CEE_SNAP_CTRL = R52_CEE_SNAP_CTRL | (1 << ERREVT_0_CEE_SNAP_CTRL_BIT);
      R52_CEE_SNAP_CTRL = R52_CEE_SNAP_CTRL & ~(1 << ERREVT_0_CEE_SNAP_CTRL_BIT);

      /* Read the count from CEE_CNT_STAT0 Register */
      cee_count_axi_s = R52_CEE_CNT_STAT0 & ERREVT_0_CEE_CNT_STAT0_MASK;

      /* Clear the respective correctable error counters & Interrupts */
      R52_CEE_CLEAR_CTRL = R52_CEE_CLEAR_CTRL | (1 << ERREVT_0_CEE_CLEAR_CTRL_IRQ_CLR_BIT);
      R52_CEE_CLEAR_CTRL = R52_CEE_CLEAR_CTRL | (1 << ERREVT_0_CEE_CLEAR_CTRL_CNT_CLR_BIT);
      R52_CEE_CLEAR_CTRL = R52_CEE_CLEAR_CTRL | (1 << ERREVT_0_CEE_CLEAR_CTRL_CLR_BIT);

      /* Update the ECC correctable fault counters in NVM */
      ecc_correctable_cnts.sp_axi_s_corr += cee_count_axi_s;
      (void)Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&ecc_correctable_cnts);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);
   }
}

/*==========================================================================*/
/**
 * FUNCTION: Monitor_AXI_M_Correctable_Errors
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Function to monitor correctable errors for AXI-M interfaces.
 *
 * Actions:
 * Call Monitor_AXI_M_Correctable_Errors function to check for correctable errors on AXI-M interface,
 * update the respective counters and trigger NVM write if any correctable error is detected.
 *
 * PRECONDITIONS:
 * - NA.
 *
 * POSTCONDITIONS:
 * - NA.
 */
/*===========================================================================*/
void Monitor_AXI_M_Correctable_Errors(void)
{
   uint16_t cee_count_axi_m;
   /* Monitor AXI-M correctable errors */
   if ((R52_CEE_IRQ_STAT & (1 << ERREVT0_2_CEE_IRQ_STAT_BIT)) == ERREVT0_2_CEE_IRQ_FIRED)
   {
      /* Toggle ERREVT0 bit to ‘1’ then back to ‘0’ to take a snapshot of respective correctable counter */
      R52_CEE_SNAP_CTRL = R52_CEE_SNAP_CTRL | (1 << ERREVT0_2_CEE_SNAP_CTRL_BIT);
      R52_CEE_SNAP_CTRL = R52_CEE_SNAP_CTRL & ~(1 << ERREVT0_2_CEE_SNAP_CTRL_BIT);

      cee_count_axi_m = R52_CEE_CNT_STAT1 & ERREVT0_2_CEE_CNT_STAT1_MASK;

      /* Clear the respective correctable error counters & Interrupts */
      R52_CEE_CLEAR_CTRL = R52_CEE_CLEAR_CTRL | (1 << ERREVT0_2_CEE_CLEAR_CTRL_IRQ_CLR_BIT);
      R52_CEE_CLEAR_CTRL = R52_CEE_CLEAR_CTRL | (1 << ERREVT0_2_CEE_CLEAR_CTRL_CNT_CLR_BIT);
      R52_CEE_CLEAR_CTRL = R52_CEE_CLEAR_CTRL | (1 << ERREVT0_2_CEE_CLEAR_CTRL_CLR_BIT);

      /* Update the ECC correctable fault counters in NVM */
      ecc_correctable_cnts.sp_axi_m_corr += cee_count_axi_m;
      (void)Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&ecc_correctable_cnts);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);
   }
}

/*==========================================================================*/
/**
 * FUNCTION: Os_Isr_Artie_Mem_Fusa_Handler
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 * FailSafe_Log_ResetReason - Function to log reset reason
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 * Interrupt handler for Artie Memory FUSA failure.
 * This function is triggered when an Artie Memory failure is detected.
 *
 * Actions:
 * 1. Log the reset reason as Artie Memory failure
 *
 * PRECONDITIONS:
 * - Artie Memory FUSA interrupt must be enabled
 *
 * POSTCONDITIONS:
 * - Reset reason logged for diagnostic purposes
 */
/*==========================================================================*/
void Os_Isr_Artie_Mem_Fusa_Handler(void)
{
   uint16 artie_sec_count = (uint16_t)(ARTIE_REGS->SEC_DED_STAT.f.STS_ECC_SEC_CNT);

   if (ARTIE_REGS->AMEM_IRQ_STATUS.f.AMEM_DED_IRQ_FIRED)
   {
      FailSafe_Log_ResetReason(FAILSAFE_SM_05_ARTIEMEM_ECC);
   }
   else if (ARTIE_REGS->AMEM_IRQ_STATUS.f.AMEM_SEC_IRQ_FIRED)
   {
      uint16_t sec_increment = (artie_sec_count > 0u) ? artie_sec_count : 1u;

      /* SEC error - increment counter by the hardware count */
      ecc_correctable_cnts.artie_mem_sec += sec_increment;
      /* RTE call to write to NVM */
      (void)Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&ecc_correctable_cnts);
      (void)Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);

      /* Clear IRQ bits */
      ARTIE_REGS->AMEM_IRQ_CLR.r = CLR_ARTIE_MEM_IRQ;
   }
   else
   {
      /* do nothing  */
   }
}

/*==========================================================================*/
/**
 * FUNCTION: Get_RA_R52_ERROR_Failure_State
 *===========================================================================
 * RETURN VALUE:
 * uint8_t RA_R52_ERROR_Failure_State
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 */
/*==========================================================================*/
uint8_t Get_RA_R52_ERROR_Failure_State(void)
{
   return RA_R52_ERROR_Failure_State;
}

/*==========================================================================*/
/**
 * FUNCTION: Get_RA_R52_FUSA_Failure_State
 *===========================================================================
 * RETURN VALUE:
 * uint8_t RA_R52_FUSA_Failure_State
 *
 * PARAMETERS:
 * None
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 */
/*==========================================================================*/
uint8_t Get_RA_R52_FUSA_Failure_State(void)
{
   return RA_R52_FUSA_Failure_State;
}

/*==========================================================================*/
/**
 * FUNCTION: Set_RA_R52_ERROR_Failure_State
 *===========================================================================
 * RETURN VALUE:
 * none
 *
 * PARAMETERS:
 * uint8_t value
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 */
/*==========================================================================*/
void Set_RA_R52_ERROR_Failure_State(uint8_t value)
{
   RA_R52_ERROR_Failure_State = value;
}

/*==========================================================================*/
/**
 * FUNCTION: Set_RA_R52_FUSA_Failure_State
 *===========================================================================
 * RETURN VALUE:
 * none
 *
 * PARAMETERS:
 * uint8_t value
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 */
/*==========================================================================*/
void Set_RA_R52_FUSA_Failure_State(uint8_t value)
{
   RA_R52_FUSA_Failure_State = value;
}
