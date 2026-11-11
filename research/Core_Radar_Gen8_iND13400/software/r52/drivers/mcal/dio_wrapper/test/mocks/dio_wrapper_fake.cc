/*===========================================================================*/
/**
 * @file dio_wrapper_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake function definitions for DIO wrapper module using FFF.
 *
 * @section ABBR ABBREVIATIONS:
 *   - DIO - Digital Input/Output
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - TODO: Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - TODO: Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#include "dio_wrapper_fake.h"

/*===========================================================================*
 * Fake value functions - DIO wrapper functions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(Dio_WriteChannel, Dio_ChannelType, Dio_LevelType);
DEFINE_FAKE_VALUE_FUNC(Dio_LevelType, Dio_ReadChannel, Dio_ChannelType);
