#ifndef APPL_SP_IFC_FFF_H
#define APPL_SP_IFC_FFF_H
/*===========================================================================*/
/**
 * @file appl_sp_ifc_fff.h
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
 * Mocking functions for appl_sp_ifc using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_sp_ifc.h"
/*===========================================================================*
 * Fake value functions - appl_sp_ifc functions
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Second_Pass_Init, Radar_Look_T);
DECLARE_FAKE_VOID_FUNC(Appl_Second_Pass_Execute, RDD_Data_T *);

/* List of fakes used by this unit tester */
#define FFF_FAKES_APPL_SP_IFC_LIST(FAKE)                                                                                          \
   FAKE(Appl_Second_Pass_Init)                                                                                                    \
   FAKE(Appl_Second_Pass_Execute)

#endif /* APPL_SP_IFC_FFF_H */
