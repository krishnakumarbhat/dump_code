/*===========================================================================*/
/**
 * @file bbe32_main_fake.h
 *
 * Fake declarations for bbe32/main.c unit tests
 */
/*==========================================================================*/
#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

   /* Fake for Register_Exception_Handlers */
   DECLARE_FAKE_VOID_FUNC(Register_Exception_Handlers);

   /* Fake for Mpu_Initialize (returns bool) */
   DECLARE_FAKE_VALUE_FUNC(bool, Mpu_Initialize);

   /* Fake for Read_Mpu_Configuration */
   DECLARE_FAKE_VOID_FUNC(Read_Mpu_Configuration);

   /* Fake for Main_Application (never returns in production, returns void in test) */
   DECLARE_FAKE_VOID_FUNC(Main_Application);

   /* Fakes for Xtensa memory ECC initialization */
   DECLARE_FAKE_VOID_FUNC(xtos_memep_initrams);
   DECLARE_FAKE_VOID_FUNC(xtos_memep_enable, int);

   /* Fake for Get_Current_Lookindex */
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_Current_Lookindex);

#ifdef __cplusplus
}
#endif
