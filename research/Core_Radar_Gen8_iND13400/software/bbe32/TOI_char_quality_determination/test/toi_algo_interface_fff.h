#ifndef TOI_ALGO_INTERFACE_FFF_H
#define TOI_ALGO_INTERFACE_FFF_H
/*===========================================================================*/
/**
 * @file toi_algo_interface_fff.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for toi_algo_interface using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "toi_algo_interface.h"
/*===========================================================================*
 * Fake value functions - toi_algo_interface functions
 *===========================================================================*/
DECLARE_FAKE_VOID_FUNC(TOI_Parameters_Init);
DECLARE_FAKE_VALUE_FUNC(int32_t, Get_Downselected_Det_Count);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Payload_CRC_Mismatch_Err);
DECLARE_FAKE_VALUE_FUNC(TOI_Input_Params_T *, Get_TOI_Init_Parameters);
DECLARE_FAKE_VALUE_FUNC(TOI_Output_Params_T *, Get_TOI_Output_Parameters);

/* List of fakes used by this unit tester */
#define FFF_FAKES_TOI_ALGO_INTERFACE_LIST(FAKE)                                                                                   \
   FAKE(TOI_Parameters_Init)                                                                                                      \
   FAKE(Get_Downselected_Det_Count)                                                                                               \
   FAKE(Get_Payload_CRC_Mismatch_Err)                                                                                             \
   FAKE(Get_TOI_Init_Parameters)                                                                                                  \
   FAKE(Get_TOI_Output_Parameters)

#endif /* TOI_ALGO_INTERFACE_FFF_H */
