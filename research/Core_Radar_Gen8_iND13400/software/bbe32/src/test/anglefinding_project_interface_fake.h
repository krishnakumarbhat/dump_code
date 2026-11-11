/*===========================================================================*/
/**
 * @file anglefinding_project_interface_fake.h
 *
 * Fake/stub declarations for anglefinding_project_interface.c unit tests.
 */
/*==========================================================================*/
#pragma once

/* include reuse headers */
#include "fff.h"
#include "reuse.h"

/*---------------------------------------------------------------------------*
 * Block real headers – the compiler still needs to *find* the files (via
 * BUILD deps), but the include guards cause the preprocessor to skip their
 * content.  All required types are provided below.
 *---------------------------------------------------------------------------*/
/* mem_pool.h is not really properly written as a module that can be overridden by FFF */
#define MEM_POOL_H

/* Memory Pool types */
typedef enum
{
   MEM_POOL_SUCCESS = 0,
   MEM_POOL_FAILURE
} Memory_Pool_Return_T;

typedef struct
{
   uint8_t *base;
   uint32_t size;
   uint32_t used;
} Mem_Pool_T;

/* timing helpers are implemented as #define macros that can't directly be overridden by FFF */
#define _TIMING_HELPERS_H_
#define Timing_Helpers_Get_Time_Sec_Float(x) Fake_Timing_Helpers_Get_Time_Sec_Float(x)

/*===========================================================================*
 * Include headers for APIs to be mocked
 *===========================================================================*/
#include "angle_finding_interface.h"
#include "angle_finding_project_interface.h"

/*===========================================================================*
 * FFF mocks
 *===========================================================================*/
typedef void (*xtos_handler)(void *);
DECLARE_FAKE_VALUE_FUNC(int, xtos_set_interrupt_handler, int, xtos_handler, void *, void **);
DECLARE_FAKE_VALUE_FUNC(int, xtos_interrupt_enable, int);
DECLARE_FAKE_VOID_FUNC(xtos_interrupt_clear, int);

DECLARE_FAKE_VALUE_FUNC(Angle_Finding_Input_T *, Get_af_input_data_ptr);
DECLARE_FAKE_VALUE_FUNC(Angle_Finding_Output_T *, Get_af_output_data_ptr);
DECLARE_FAKE_VALUE_FUNC(AF_Retval_T, Angle_Finding_Execute, Angle_Finding_Input_T *, Angle_Finding_Output_T *);
DECLARE_FAKE_VALUE_FUNC(size_t, Get_AF_Internal_Memory_Pointers, AF_Internal_Mem_Info_T **);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Alloc, Mem_Pool_T *, uint32_t, void **);
DECLARE_FAKE_VALUE_FUNC(AF_Retval_T, AF_Fascia_Compensation, float32_t *, float32_t *, size_t, size_t);
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
DECLARE_FAKE_VALUE_FUNC(AF_Retval_T, AF_Downselection_Execute, AF_DownSelection_In_Out_Params_T *);
DECLARE_FAKE_VALUE_FUNC(AF_Internal_Mem_Info_T *, Get_DS_Internal_memory_pointers);
#endif

/* Timing helpers */
DECLARE_FAKE_VALUE_FUNC(uint32_t, AF_Get_Timing_Counter);
DECLARE_FAKE_VALUE_FUNC(uint32_t, AF_Get_Timing_Delta, uint32_t, uint32_t);
DECLARE_FAKE_VALUE_FUNC(float32_t, Fake_Timing_Helpers_Get_Time_Sec_Float, uint32_t);
DECLARE_FAKE_VALUE_FUNC(uint32_t, AF_Accumulate_Profiling_Counter, uint32_t, uint32_t *);
