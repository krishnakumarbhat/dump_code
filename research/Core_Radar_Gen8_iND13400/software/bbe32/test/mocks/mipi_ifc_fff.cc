/*===========================================================================*/
/**
 * @file mipi_ifc_fff.cc
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
 * Fake function declarations for mipi_ifc.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "mipi_ifc_fff.h"
/*===========================================================================*
 * Fake value functions - mipi_ifc functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(Appl_Mipi_Idm_Config, Radar_Look_T);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_IDM_Stat_Init, Mem_Pool_T *);
DEFINE_FAKE_VOID_FUNC(Appl_IDM_Stat_Process, Radar_Look_T);
DEFINE_FAKE_VOID_FUNC(Appl_MIPI_One_Time_Init);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_MIPI_Chirp_End_Timestamp, uint32_t);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_MIPI_Chirp_Count);

extern "C"
{
}
