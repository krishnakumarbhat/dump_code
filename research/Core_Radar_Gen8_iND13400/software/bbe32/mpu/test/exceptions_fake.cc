/*===========================================================================*/
/**
 * @file exceptions_fake.cc
 *
 * FFF fake definitions for exceptions.c unit tests.
 */
/*==========================================================================*/
#include "exceptions_fake.h"

DEFINE_FAKE_VALUE_FUNC(xtos_handler_func_t, xtos_set_exception_handler, uint32_t, xtos_handler_func_t, void *);
DEFINE_FAKE_VALUE_FUNC(uintptr_t, Get_Ipc_Shared_Buffer_Base_Address);
