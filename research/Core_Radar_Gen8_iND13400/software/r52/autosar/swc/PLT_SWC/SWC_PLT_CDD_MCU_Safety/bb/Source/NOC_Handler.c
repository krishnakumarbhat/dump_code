/*===========================================================================*/
/**
 * NOC_Handler.c
 *
 * This file includes definitions for SM_052.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *
 * This file includes definitions for NOC interrupt handling.
 *
 * ABBREVIATIONS:
 *   List any abbreviations, precede each with a dash ('-').
 *
 * TRACEABILITY INFO:
 *   - Design Document(s):
 *     - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *   - Requirements Document(s):
 *     - 511-SRS_Radar/CMP_SRS_CoreRadar_MCU_Configuration_And_Supervision
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

#include "NOC_Handler.h"

static Dt_NOC_Fault_Info_T NOC_fault_info; /* static: only used within this translation unit (MISRA Rule 8.9) */
static uint8 NOC_chandra_latent_isr_executed_flag = NOC_STATUS_NOT_SET;
static uint8 NOC_artie_latent_isr_executed_flag   = NOC_STATUS_NOT_SET;
static uint8 NOC_small_latent_isr_executed_flag   = NOC_STATUS_NOT_SET;

/******************************************************************************
 * Name:  Clear_StickyDiag_MissionFault_registers
 *    Clears sticky diagnostic registers in FUSA_CTRL block and the Bist Clear register for all NOCs
 *
 * Shared Variables: none
 *
 * Parameters: void
 *
 * Return Value: void
 *
 ******************************************************************************/
void Clear_StickyDiag_MissionFault_registers(void)
{
   /* Writing '1' clears corresponding sticky bits; registers are auto-clearing. */
   STICKY_DIAG_CTRL0_ADDR = STICKY_DIAG_CLEAR_ALL_BITS;
   STICKY_DIAG_CTRL1_ADDR = STICKY_DIAG_CLEAR_ALL_BITS;
   STICKY_DIAG_CTRL2_ADDR = STICKY_DIAG_CLEAR_ALL_BITS;

   CHANDRA_NOC_CLEAR_ADDR = NOC_MISSION_CLEAR_BIT; /* Clear CHANDRA mission fault sticky bits if applicable */
   SMALL_NOC_CLEAR_ADDR   = NOC_MISSION_CLEAR_BIT; /* Clear SMALL mission fault sticky bits if applicable */
   ARTIE_NOC_CLEAR_ADDR   = NOC_MISSION_CLEAR_BIT; /* Clear ARTIE mission fault sticky bits if applicable */
}

void NOC_Run_Bist_Chandra(void)
{
   NOC_chandra_latent_isr_executed_flag = NOC_STATUS_NOT_SET;

   /* Step 1: Set CHANDRA BistControl.AutoMission (bit 24).
    * When set, hardware automatically returns to mission mode after BIST completes.
    * BISTCONTROL.TIMEOUT0 (bits 15:0) and TIMEOUT1 (bits 23:16) remain at reset
    * defaults (0xFFFF / 0xFF), providing hardware-bounded BIST execution time. */
   CHANDRA_NOC_BIST_CONTROL_ADDR |= (uint32_t)NOC_BIST_AUTOMISSION_BIT;

   /* Step 2: Write BIST start value to CHANDRA BistStart register to trigger BIST */
   CHANDRA_NOC_BIST_START_ADDR = BIST_START_VALUE;
}

void NOC_Run_Bist_Small(void)
{
   NOC_small_latent_isr_executed_flag = NOC_STATUS_NOT_SET;

   /* Step 1: Set SMALL BistControl.AutoMission (bit 24).
    * When set, hardware automatically returns to mission mode after BIST completes.
    * BISTCONTROL.TIMEOUT0 (bits 15:0) and TIMEOUT1 (bits 23:16) remain at reset
    * defaults (0xFFFF / 0xFF), providing hardware-bounded BIST execution time. */
   SMALL_NOC_BIST_CONTROL_ADDR |= (uint32_t)NOC_BIST_AUTOMISSION_BIT;

   /* Step 2: Write BIST start value to SMALL BistStart register to trigger BIST */
   SMALL_NOC_BIST_START_ADDR = BIST_START_VALUE;
}

void NOC_Run_Bist_Artie(void)
{
   NOC_artie_latent_isr_executed_flag = NOC_STATUS_NOT_SET;

   /* Step 1: Set ARTIE BistControl.AutoMission (bit 24).
    * When set, hardware automatically returns to mission mode after BIST completes.
    * BISTCONTROL.TIMEOUT0 (bits 15:0) and TIMEOUT1 (bits 23:16) remain at reset
    * defaults (0xFFFF / 0xFF), providing hardware-bounded BIST execution time. */
   ARTIE_NOC_BIST_CONTROL_ADDR |= (uint32_t)NOC_BIST_AUTOMISSION_BIT;

   /* Step 2: Write BIST start value to ARTIE BistStart register to trigger BIST */
   ARTIE_NOC_BIST_START_ADDR = BIST_START_VALUE;
}

void NOC_Verify_Chandra_LatentIsr_Execution(void)
{
   if (NOC_chandra_latent_isr_executed_flag == NOC_STATUS_NOT_SET)
   {
      NOC_fault_info.LatentFault0 = CHANDRA_NOC_LATENT_COM_FAULT_00_ADDR;
      NOC_fault_info.LatentFault1 = CHANDRA_NOC_LATENT_COM_FAULT_01_ADDR;
      NOC_fault_info.LatentFault2 = CHANDRA_NOC_LATENT_COM_FAULT_02_ADDR;
      NOC_fault_info.LatentFault3 = CHANDRA_NOC_LATENT_COM_FAULT_03_ADDR;
      Log_NOCLatentIntFault_Info(&NOC_fault_info, MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
   }

   NOC_chandra_latent_isr_executed_flag = NOC_STATUS_NOT_SET;
}

void NOC_Verify_Artie_LatentIsr_Execution(void)
{
   if (NOC_artie_latent_isr_executed_flag == NOC_STATUS_NOT_SET)
   {
      NOC_fault_info.LatentFault0 = ARTIE_NOC_LATENT_COM_FAULT_00_ADDR;
      NOC_fault_info.LatentFault1 = ARTIE_NOC_LATENT_COM_FAULT_01_ADDR;
      NOC_fault_info.LatentFault2 = ARTIE_NOC_LATENT_COM_FAULT_02_ADDR;
      NOC_fault_info.LatentFault3 = ARTIE_NOC_LATENT_COM_FAULT_03_ADDR;
      Log_NOCLatentIntFault_Info(&NOC_fault_info, MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
   }

   NOC_artie_latent_isr_executed_flag = NOC_STATUS_NOT_SET;
}

void NOC_Verify_Small_LatentIsr_Execution(void)
{
   if (NOC_small_latent_isr_executed_flag == NOC_STATUS_NOT_SET)
   {
      NOC_fault_info.LatentFault0 = SMALL_NOC_LATENT_COM_FAULT_00_ADDR;
      NOC_fault_info.LatentFault1 = SMALL_NOC_LATENT_COM_FAULT_01_ADDR;
      NOC_fault_info.LatentFault2 = SMALL_NOC_LATENT_COM_FAULT_02_ADDR;
      NOC_fault_info.LatentFault3 = SMALL_NOC_LATENT_COM_FAULT_03_ADDR;
      Log_NOCLatentIntFault_Info(&NOC_fault_info, MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
   }

   NOC_small_latent_isr_executed_flag = NOC_STATUS_NOT_SET;
}

void Os_Isr_CNOC_Latent_Fusa_Handler(void)
{
   NOC_chandra_latent_isr_executed_flag = NOC_STATUS_SET;
   if ((CHANDRA_NOC_BIST_STATUS_ADDR & NOC_BIST_FAILED_BIT) == NOC_BIST_FAILED_BIT)
   {
      NOC_fault_info.LatentFault0 = CHANDRA_NOC_LATENT_COM_FAULT_00_ADDR;
      NOC_fault_info.LatentFault1 = CHANDRA_NOC_LATENT_COM_FAULT_01_ADDR;
      NOC_fault_info.LatentFault2 = CHANDRA_NOC_LATENT_COM_FAULT_02_ADDR;
      NOC_fault_info.LatentFault3 = CHANDRA_NOC_LATENT_COM_FAULT_03_ADDR;
      Log_NOCLatentIntFault_Info(&NOC_fault_info, MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT);
   }
   /* Restore CHANDRA BistControl.AutoMission to reset state after sequence completes */
   CHANDRA_NOC_BIST_CONTROL_ADDR &= ~(uint32_t)NOC_BIST_AUTOMISSION_BIT;

   CHANDRA_NOC_CLEAR_ADDR = NOC_BIST_CLEAR_BIT; /* Clear BIST status registers to prepare for next BIST run; only required when
                                                   AutoMission == 0, but does not harm when AutoMission == 1 */
}

void Os_Isr_ANOC_Latent_Fusa_Handler(void)
{
   NOC_artie_latent_isr_executed_flag = NOC_STATUS_SET;

   if ((ARTIE_NOC_BIST_STATUS_ADDR & NOC_BIST_FAILED_BIT) == NOC_BIST_FAILED_BIT)
   {
      NOC_fault_info.LatentFault0 = ARTIE_NOC_LATENT_COM_FAULT_00_ADDR;
      NOC_fault_info.LatentFault1 = ARTIE_NOC_LATENT_COM_FAULT_01_ADDR;
      NOC_fault_info.LatentFault2 = ARTIE_NOC_LATENT_COM_FAULT_02_ADDR;
      NOC_fault_info.LatentFault3 = ARTIE_NOC_LATENT_COM_FAULT_03_ADDR;
      Log_NOCLatentIntFault_Info(&NOC_fault_info, MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT);
   }

   /* Restore ARTIE BistControl.AutoMission to reset state after sequence completes */
   ARTIE_NOC_BIST_CONTROL_ADDR &= ~(uint32_t)NOC_BIST_AUTOMISSION_BIT;

   /* Clear BIST status registers to prepare for next BIST run; only required when AutoMission == 0, but does not harm when
    * AutoMission == 1 */
   ARTIE_NOC_CLEAR_ADDR = NOC_BIST_CLEAR_BIT;
}

void Os_Isr_SNOC_Latent_Fusa_Handler(void)
{
   NOC_small_latent_isr_executed_flag = NOC_STATUS_SET;

   if ((SMALL_NOC_BIST_STATUS_ADDR & NOC_BIST_FAILED_BIT) == NOC_BIST_FAILED_BIT)
   {
      NOC_fault_info.LatentFault0 = SMALL_NOC_LATENT_COM_FAULT_00_ADDR;
      NOC_fault_info.LatentFault1 = SMALL_NOC_LATENT_COM_FAULT_01_ADDR;
      NOC_fault_info.LatentFault2 = SMALL_NOC_LATENT_COM_FAULT_02_ADDR;
      NOC_fault_info.LatentFault3 = SMALL_NOC_LATENT_COM_FAULT_03_ADDR;
      Log_NOCLatentIntFault_Info(&NOC_fault_info, MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(MCU_FCRU_FAULT_58_SMALL_NOC_FAULT);
   }

   /* Restore SMALL NOC BistControl.AutoMission to reset state after sequence completes */
   SMALL_NOC_BIST_CONTROL_ADDR &= ~(uint32_t)NOC_BIST_AUTOMISSION_BIT;

   SMALL_NOC_CLEAR_ADDR = NOC_BIST_CLEAR_BIT; /* Clear BIST status registers to prepare for next BIST run; only required when
                                                 AutoMission == 0, but does not harm when AutoMission == 1 */
}
