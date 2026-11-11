/*===========================================================================*/
/**
 * @file appl_sweepbw_ifc_fff.cc
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
 * Fake function declarations for appl_sweepbw_ifc.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_sweepbw_ifc_fff.h"
/*===========================================================================*
 * Fake value functions - appl_sweepbw_ifc functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Sweep_Bw_Init, Radar_Look_T);
DEFINE_FAKE_VOID_FUNC(Appl_Sweep_Bw_Execute, RDD_Data_T *);

extern "C"
{
}
