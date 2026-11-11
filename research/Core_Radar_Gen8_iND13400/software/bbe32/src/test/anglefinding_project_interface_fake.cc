/*===========================================================================*/
/**
 * @file anglefinding_project_interface_fake.cc
 *
 * FFF fake definitions for anglefinding_project_interface.c unit tests.
 */
/*==========================================================================*/
#include "anglefinding_project_interface_fake.h"

DEFINE_FFF_GLOBALS

uint32_t xtos_enabled      = 0U;
uint32_t xtos_vpri_enabled = 0xFFFFFFFFU;

/* Xtensa runtime */
DEFINE_FAKE_VALUE_FUNC(int, xtos_set_interrupt_handler, int, xtos_handler, void *, void **);
DEFINE_FAKE_VALUE_FUNC(int, xtos_interrupt_enable, int);
DEFINE_FAKE_VOID_FUNC(xtos_interrupt_clear, int);

/* AF building block functions */
static Angle_Finding_Input_T g_af_input_data;
static Angle_Finding_Output_T g_af_output_data;

Angle_Finding_Input_T *Get_af_input_data_ptr_custom(void)
{
   return &g_af_input_data;
}

Angle_Finding_Output_T *Get_af_output_data_ptr_custom(void)
{
   return &g_af_output_data;
}

DEFINE_FAKE_VALUE_FUNC(Angle_Finding_Input_T *, Get_af_input_data_ptr);
DEFINE_FAKE_VALUE_FUNC(Angle_Finding_Output_T *, Get_af_output_data_ptr);
DEFINE_FAKE_VALUE_FUNC(AF_Retval_T, Angle_Finding_Execute, Angle_Finding_Input_T *, Angle_Finding_Output_T *);
DEFINE_FAKE_VALUE_FUNC(size_t, Get_AF_Internal_Memory_Pointers, AF_Internal_Mem_Info_T **);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Alloc, Mem_Pool_T *, uint32_t, void **);
DEFINE_FAKE_VALUE_FUNC(AF_Retval_T, AF_Fascia_Compensation, float32_t *, float32_t *, size_t, size_t);
#if (AF_DOWNSELECTION_ENABLE_L == 1U)
DEFINE_FAKE_VALUE_FUNC(AF_Retval_T, AF_Downselection_Execute, AF_DownSelection_In_Out_Params_T *);
DEFINE_FAKE_VALUE_FUNC(AF_Internal_Mem_Info_T *, Get_DS_Internal_memory_pointers);
#endif

/* Timing helpers */
DEFINE_FAKE_VALUE_FUNC(uint32_t, AF_Get_Timing_Counter);
DEFINE_FAKE_VALUE_FUNC(uint32_t, AF_Get_Timing_Delta, uint32_t, uint32_t);
DEFINE_FAKE_VALUE_FUNC(float32_t, Fake_Timing_Helpers_Get_Time_Sec_Float, uint32_t);
DEFINE_FAKE_VALUE_FUNC(uint32_t, AF_Accumulate_Profiling_Counter, uint32_t, uint32_t *);
