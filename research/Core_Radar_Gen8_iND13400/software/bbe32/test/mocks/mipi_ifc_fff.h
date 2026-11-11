#ifndef MIPI_IFC_FFF_H
#define MIPI_IFC_FFF_H
/*===========================================================================*/
/**
 * @file mipi_ifc_fff.h
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
 * Mocking functions for mipi_ifc using FFF.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "mipi_ifc.h"
/*===========================================================================*
 * Fake value functions - mipi_ifc functions
 *===========================================================================*/
DECLARE_FAKE_VOID_FUNC(Appl_Mipi_Idm_Config, Radar_Look_T);
DECLARE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_IDM_Stat_Init, Mem_Pool_T *);
DECLARE_FAKE_VOID_FUNC(Appl_IDM_Stat_Process, Radar_Look_T);
DECLARE_FAKE_VOID_FUNC(Appl_MIPI_One_Time_Init);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_MIPI_Chirp_End_Timestamp, uint32_t);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_MIPI_Chirp_Count);

/* List of fakes used by this unit tester */
#define FFF_FAKES_MIPI_IFC_LIST(FAKE)                                                                                             \
   FAKE(Appl_Mipi_Idm_Config)                                                                                                     \
   FAKE(Appl_IDM_Stat_Init)                                                                                                       \
   FAKE(Appl_IDM_Stat_Process)                                                                                                    \
   FAKE(Appl_MIPI_One_Time_Init)                                                                                                  \
   FAKE(Get_MIPI_Chirp_End_Timestamp)                                                                                             \
   FAKE(Get_MIPI_Chirp_Count)

#endif /* MIPI_IFC_FFF_H */
