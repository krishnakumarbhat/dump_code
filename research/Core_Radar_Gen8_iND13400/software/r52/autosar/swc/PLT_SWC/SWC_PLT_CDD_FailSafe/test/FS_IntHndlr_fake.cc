/*===========================================================================*/
/**
 * @file FS_IntHndlr_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 *
 * Fake function implementations for FS_IntHndlr.c unit tests
 *
 *
 */
/*===========================================================================*/
#include "FS_IntHndlr_fake.h"
#include "retention_ram_data.h"

/*===========================================================================*
 * Define fake global variables
 *===========================================================================*/
volatile uint32 MIPI_Err_Fusa_Counter = 0;
volatile uint32 MIPI_Chp_Fusa_Counter = 0;

/* Fake Retention RAM Data - used by Serial Clock Monitor Handler */
Retention_Ram_Data_T Retention_Ram_Data = {0};

/* Fake Reset Monitor registers for unit testing */
volatile uint32 IRQ_RMON                         = 0;
volatile uint32 IRQ_RMON_NOMASK                  = 0;
volatile uint32 MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0;
volatile uint32 CTL_RMON                         = 0;

/*===========================================================================*
 * Define fake functions for FS_IntHndlr module
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, Dt_ECU_ResetReasonType);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault,
                       const Dt_ECC_Correctable_Error_Counters *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_FailSafe_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM, uint8,
                       uint8);
DEFINE_FAKE_VOID_FUNC(FS_RA_Process_Failure_Cnts);
