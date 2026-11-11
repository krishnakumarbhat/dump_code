#ifndef RANGE_PROCESS_IFC_FFF_H
#define RANGE_PROCESS_IFC_FFF_H
/*===========================================================================*/
/**
 * @file range_process_ifc_fff.h
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
 * Mocking functions for range_process_ifc using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "range_process_ifc.h"
/*===========================================================================*
 * Fake value functions - range_process_ifc functions
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(bool, Appl_Range_Process_Init, Radar_Look_T);
DECLARE_FAKE_VALUE_FUNC(Appl_Range_Return_Values_T, Check_For_Range_Process_Complete_Timeout_Check, Mem_Pool_T *);
DECLARE_FAKE_VOID_FUNC(Appl_Range_Process_Chirp_Callback, void *);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_Range_Procesing_Done_Time);

/* List of fakes used by this unit tester */
#define FFF_FAKES_RANGE_PROCESS_IFC_LIST(FAKE)                                                                                    \
   FAKE(Appl_Range_Process_Init)                                                                                                  \
   FAKE(Check_For_Range_Process_Complete_Timeout_Check)                                                                           \
   FAKE(Appl_Range_Process_Chirp_Callback)                                                                                        \
   FAKE(Get_Range_Procesing_Done_Time)

#endif /* RANGE_PROCESS_IFC_FFF_H */
