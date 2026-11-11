#ifndef APPL_CFAR_IFC_FFF_H
#define APPL_CFAR_IFC_FFF_H
/*===========================================================================*/
/**
 * @file appl_cfar_ifc_fff.h
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
 * Mocking functions for appl_cfar_ifc using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "appl_cfar_ifc.h"
/*===========================================================================*
 * Fake value functions - appl_cfar_ifc functions
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Cfar_Init, Radar_Look_T);
DECLARE_FAKE_VOID_FUNC(Appl_Cfar_Execute, uint16_t, RDD_Data_T *);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_CFAR_Memory_Init, Mem_Pool_T *);

/* List of fakes used by this unit tester */
#define FFF_FAKES_APPL_CFAR_IFC_LIST(FAKE)                                                                                        \
   FAKE(Appl_Cfar_Init)                                                                                                           \
   FAKE(Appl_Cfar_Execute)                                                                                                        \
   FAKE(Appl_CFAR_Memory_Init)

#endif /* APPL_CFAR_IFC_FFF_H */
