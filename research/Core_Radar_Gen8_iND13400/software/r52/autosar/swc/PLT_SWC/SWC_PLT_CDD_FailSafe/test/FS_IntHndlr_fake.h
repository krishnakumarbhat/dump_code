/*===========================================================================*/
/**
 * @file FS_IntHndlr_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 *
 * Mocking functions for the FS_IntHndlr.c FFF
 *
/*===========================================================================*/
#ifndef FS_IntHndlr_FAKE_H
#define FS_IntHndlr_FAKE_H
#include "Rte_Type.h"
#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif

   /*===========================================================================*
    * Fake global variables
    *===========================================================================*/
   extern volatile uint32 MIPI_Err_Fusa_Counter;
   extern volatile uint32 MIPI_Chp_Fusa_Counter;

   /* Reset Monitor registers for unit testing */
   extern volatile uint32 IRQ_RMON;
   extern volatile uint32 IRQ_RMON_NOMASK;
   extern volatile uint32 MCU_SAFETY_MISC0_IRQ_MASKED_STAT;
   extern volatile uint32 CTL_RMON;

   /*===========================================================================*
    * Fake function declarations for FS_IntHndlr.c
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, Dt_ECU_ResetReasonType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault,
                           const Dt_ECC_Correctable_Error_Counters *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_FailSafe_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM,
                           uint8, uint8);
   DECLARE_FAKE_VOID_FUNC(FS_RA_Process_Failure_Cnts);

#ifdef __cplusplus
}
#endif

/*===========================================================================*
 * Macro to reset all fakes in FS_IntHndlr module
 *===========================================================================*/
#define FFF_FAKES_FUSA_HANDLER_LIST(FAKE)                                                                                         \
   FAKE(FailSafe_Log_ResetReason)                                                                                                 \
   FAKE(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault)                                         \
   FAKE(Rte_Call_SWC_PLT_CDD_FailSafe_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM)                                     \
   FAKE(FS_RA_Process_Failure_Cnts)

#endif /* FS_IntHndlr_FAKE_H */
