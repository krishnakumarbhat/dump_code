/*===========================================================================*/
/**
 * @file bbe32_static_register_validation_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock declarations for bbe32_static_register_validation unit testing.
 */
/*==========================================================================*/
#ifndef BBE32_STATIC_REGISTER_VALIDATION_FAKE_H_
#define BBE32_STATIC_REGISTER_VALIDATION_FAKE_H_

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* ======================================================================
    * Block production headers that pull in platform-specific or deeply
    * transitive includes unavailable on x86_64 host.
    *
    * BBE32_STATIC_REGISTER_VALIDATION_H - blocks real register address macros
    * IPC_DSP_H  - blocks core-macros.h (missing on host) and many func decls
    * IPC_DATA_H - blocks complex stream types with deep transitive deps
    * CRC_CALC_H - blocks Driver_Common.h and transitive deps
    * ====================================================================== */
#define BBE32_STATIC_REGISTER_VALIDATION_H
#define IPC_DSP_H
#define IPC_DATA_H
#define CRC_CALC_H

   /* Stub primitive types (normally from Std_Types.h / reuse.h) */
   typedef uint32_t uint32;
   typedef uint8_t uint8;

/* Stub coded values (from reuse.h — uses #ifndef, so pre-defining here wins) */
#define CODED_TRUE  (0xAAU)
#define CODED_FALSE (0x55U)

/* Macros matching the source file */
#define FS_STARTUP_DELAY      (20)
#define FS_WAIT_150MS         (3)
#define MAX_NO_REGISTER_BBE32 ((uint32)16)
#define DATA_LENGTH           ((uint8)4)

   /* Stub register addresses - mapped to local RAM for host testing */
   static uint32_t stub_reg_mem[32] = {0};
#define AUX_ACC_ECC_CTRL0   ((uint32_t)(uintptr_t)&stub_reg_mem[0])
#define AUX_ACC_ECC_CTRL1   ((uint32_t)(uintptr_t)&stub_reg_mem[1])
#define AUX_ACC_ECC_CTRL2   ((uint32_t)(uintptr_t)&stub_reg_mem[2])
#define AUX_ACC_RAM_CTRL0   ((uint32_t)(uintptr_t)&stub_reg_mem[3])
#define IRQ_ERR_ENA_CTRL0   ((uint32_t)(uintptr_t)&stub_reg_mem[4])
#define R52_ERR_IRQ_ENA_2   ((uint32_t)(uintptr_t)&stub_reg_mem[5])
#define R52_FUNC_IRQ_ENA    ((uint32_t)(uintptr_t)&stub_reg_mem[6])
#define COMP_PRBS_1         ((uint32_t)(uintptr_t)&stub_reg_mem[7])
#define COMP_PRBS_2         ((uint32_t)(uintptr_t)&stub_reg_mem[8])
#define DECOMP_PRBS_1       ((uint32_t)(uintptr_t)&stub_reg_mem[9])
#define DECOMP_PRBS_2       ((uint32_t)(uintptr_t)&stub_reg_mem[10])
#define MON_TIMER_IN_CTRL   ((uint32_t)(uintptr_t)&stub_reg_mem[11])
#define MON_TIMER_PROC_CTRL ((uint32_t)(uintptr_t)&stub_reg_mem[12])
#define MON_TIMER_OUT_CTRL  ((uint32_t)(uintptr_t)&stub_reg_mem[13])
#define IDMA_TRIGGER_ENA    ((uint32_t)(uintptr_t)&stub_reg_mem[14])
#define DSP_FUSA_IRQ_ENA    ((uint32_t)(uintptr_t)&stub_reg_mem[15])

   /* -----------------------------------------------------------------
    * Minimal D2M_Msg_T stub (from ipc_data.h)
    * Only the field accessed by the source is needed:
    *   d2m_msg_ptr->payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag
    * ----------------------------------------------------------------- */
   typedef struct Diag_Data_Tag
   {
      uint8_t fusa_bbe32_reg_readback_test_fault_flag;
   } Diag_Data_T;

   typedef struct D2M_Payload_Tag
   {
      Diag_Data_T diag_data;
   } D2M_Payload_T;

   typedef struct D2M_Msg_Tag
   {
      D2M_Payload_T payload;
   } D2M_Msg_T;

   /* Fake function declarations */
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Compute_CRC32_SW, uint8_t *, uint32_t, uint32_t, bool);
   DECLARE_FAKE_VOID_FUNC(Ipc_Functional_Reset);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_One_50ms_DSP_Delay);
   DECLARE_FAKE_VALUE_FUNC(volatile D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);

#define FFF_FAKES_BBE32_STATIC_REG_LIST(op)                                                                                       \
   op(Compute_CRC32_SW);                                                                                                          \
   op(Ipc_Functional_Reset);                                                                                                      \
   op(Get_One_50ms_DSP_Delay);                                                                                                    \
   op(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer)

#ifdef __cplusplus
}
#endif

#endif /* BBE32_STATIC_REGISTER_VALIDATION_FAKE_H_ */
