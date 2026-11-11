/*===========================================================================*/
/**
 * @file exceptions_fake.h
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
 * Fake/Mock declarations for exceptions.c unit testing.
 */
/*==========================================================================*/
#ifndef EXCEPTIONS_FAKE_H_
#define EXCEPTIONS_FAKE_H_

/* Poison ipc_data.h include guard so the real ipc_data.h types are not
 * processed during unit testing (stub types are provided below). */
#define IPC_DATA_H

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* ---------- Stub types for host testing ---------- */
   typedef uint32_t uint32;
   typedef uint8_t uint8;

/* Stub Xtensa XEA exception cause constants */
#define EXCCAUSE_ILLEGAL               (0U)
#define EXCCAUSE_INSTR_ERROR           (1U)
#define EXCCAUSE_LOAD_STORE_ERROR      (2U)
#define EXCCAUSE_DIVIDE_BY_ZERO        (3U)
#define EXCCAUSE_PC_ERROR              (4U)
#define EXCCAUSE_PRIVILEGED            (5U)
#define EXCCAUSE_UNALIGNED             (6U)
#define EXCCAUSE_INSTR_DATA_ERROR      (7U)
#define EXCCAUSE_LOAD_STORE_DATA_ERROR (8U)
#define EXCCAUSE_INSTR_ADDR_ERROR      (9U)
#define EXCCAUSE_LOAD_STORE_ADDR_ERROR (10U)
#define EXCCAUSE_ITLB_MISS             (11U)
#define EXCCAUSE_ITLB_MULTIHIT         (12U)
#define EXCCAUSE_INSTR_RING            (13U)
#define EXCCAUSE_INSTR_PROHIBITED      (14U)
#define EXCCAUSE_DTLB_MISS             (15U)
#define EXCCAUSE_DTLB_MULTIHIT         (16U)
#define EXCCAUSE_LOAD_STORE_RING       (17U)
#define EXCCAUSE_LOAD_PROHIBITED       (18U)
#define EXCCAUSE_STORE_PROHIBITED      (19U)

   /* Stub frame types */
   typedef struct
   {
      uint32_t pc;
      uint32_t ps;
      uint32_t a[64];
   } UserFrame;
   typedef struct
   {
      uint32_t pc;
      uint32_t ps;
   } ExcFrame;

#define XCHAL_HAVE_XEA3 (0)

   /* Stub IPC buffer access */
   typedef struct
   {
      uint32_t BBE32_Exception_Cause;
      uint32_t BBE32_Exception_Ccount;
      uint32_t Exception_VADDR;
      uint32_t Exception_PS;
      uint32_t Exception_EPC1;
   } D2M_Debug_Msg_T;

   typedef struct
   {
      D2M_Debug_Msg_T D2M_Debug_Msg;
      UserFrame UserFrame;
   } IPC_Shared_Buffers_T;

   static IPC_Shared_Buffers_T stub_ipc_buffer = {0};

/* Stub Xtensa runtime intrinsics */
#define XT_RSR_EXCCAUSE() (0U)
#define XT_RSR_CCOUNT()   (0U)
#define XT_RSR_EXCVADDR() (0U)
#define XT_RSR_PS()       (0U)
#define XT_RSR_EPC1()     (0U)

   /* Stub function declarations */
   typedef void (*xtos_handler_func_t)(void *);

   DECLARE_FAKE_VALUE_FUNC(xtos_handler_func_t, xtos_set_exception_handler, uint32_t, xtos_handler_func_t, void *);
   DECLARE_FAKE_VALUE_FUNC(uintptr_t, Get_Ipc_Shared_Buffer_Base_Address);

   /* Initialize stub so Get_Ipc_Shared_Buffer_Base_Address returns valid pointer */
   static inline uintptr_t stub_get_ipc_buffer(void)
   {
      return (uintptr_t)&stub_ipc_buffer;
   }

#define FFF_FAKES_EXCEPTIONS_LIST(op)                                                                                             \
   op(xtos_set_exception_handler);                                                                                                \
   op(Get_Ipc_Shared_Buffer_Base_Address)

#ifdef __cplusplus
}
#endif

#endif /* EXCEPTIONS_FAKE_H_ */
