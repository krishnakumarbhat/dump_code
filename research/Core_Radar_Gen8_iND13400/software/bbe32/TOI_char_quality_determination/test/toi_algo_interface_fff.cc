/*===========================================================================*/
/**
 * @file toi_algo_interface_fff.cc
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
 * Fake function definitions for toi_algo_interface.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "toi_algo_interface_fff.h"
/*===========================================================================*
 * Fake value functions - toi_algo_interface functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(TOI_Parameters_Init);
DEFINE_FAKE_VALUE_FUNC(int32_t, Get_Downselected_Det_Count);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Payload_CRC_Mismatch_Err);
DEFINE_FAKE_VALUE_FUNC(TOI_Input_Params_T *, Get_TOI_Init_Parameters);
DEFINE_FAKE_VALUE_FUNC(TOI_Output_Params_T *, Get_TOI_Output_Parameters);
