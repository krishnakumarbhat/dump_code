#ifndef APPL_SWEEPBW_IFC_FFF_H
#define APPL_SWEEPBW_IFC_FFF_H
/*===========================================================================*/
/**
 * @file appl_sweepbw_ifc_fff.h
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
 * Mocking functions for appl_sweepbw_ifc using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_sweepbw_ifc.h"
/*===========================================================================*
 * Fake value functions - appl_sweepbw_ifc functions
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Sweep_Bw_Init, Radar_Look_T);
DECLARE_FAKE_VOID_FUNC(Appl_Sweep_Bw_Execute, RDD_Data_T *);

/* List of fakes used by this unit tester */
#define FFF_FAKES_APPL_SWEEPBW_IFC_LIST(FAKE)                                                                                     \
   FAKE(Appl_Sweep_Bw_Init)                                                                                                       \
   FAKE(Appl_Sweep_Bw_Execute)

#endif /* APPL_SWEEPBW_IFC_FFF_H */
