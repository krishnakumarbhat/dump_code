/*===========================================================================*/
/**
 * @file appl_sp_ifc_fff.cc
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
 * Fake function declarations for appl_sp_ifc.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_sp_ifc_fff.h"
/*===========================================================================*
 * Fake value functions - appl_sp_ifc functions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Second_Pass_Init, Radar_Look_T);
DEFINE_FAKE_VOID_FUNC(Appl_Second_Pass_Execute, RDD_Data_T *);

extern "C"
{
}
