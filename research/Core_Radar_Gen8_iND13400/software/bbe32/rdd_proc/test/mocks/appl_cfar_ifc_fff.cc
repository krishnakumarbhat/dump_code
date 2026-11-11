/*===========================================================================*/
/**
 * @file appl_cfar_ifc_fff.cc
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
 * Fake function declarations for appl_cfar_ifc.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_cfar_ifc_fff.h"
/*===========================================================================*
 * Fake value functions - appl_cfar_ifc functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Cfar_Init, Radar_Look_T);
DEFINE_FAKE_VOID_FUNC(Appl_Cfar_Execute, uint16_t, RDD_Data_T *);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_CFAR_Memory_Init, Mem_Pool_T *);

extern "C"
{
}
