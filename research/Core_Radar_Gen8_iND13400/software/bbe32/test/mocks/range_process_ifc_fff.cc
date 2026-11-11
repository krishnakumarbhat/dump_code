/*===========================================================================*/
/**
 * @file range_process_ifc_fff.cc
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
 * Fake function declarations for range_process_ifc.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "range_process_ifc_fff.h"
/*===========================================================================*
 * Fake value functions - range_process_ifc functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Range_Process_Init, Radar_Look_T);
DEFINE_FAKE_VALUE_FUNC(Appl_Range_Return_Values_T, Check_For_Range_Process_Complete_Timeout_Check, Mem_Pool_T *);
DEFINE_FAKE_VOID_FUNC(Appl_Range_Process_Chirp_Callback, void *);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Range_Procesing_Done_Time);

extern "C"
{
}
