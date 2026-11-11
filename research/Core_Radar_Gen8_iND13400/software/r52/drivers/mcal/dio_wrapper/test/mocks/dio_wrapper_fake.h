#ifndef DIO_WRAPPER_FAKE_H_
#define DIO_WRAPPER_FAKE_H_

/*===========================================================================*/
/**
 * @file dio_wrapper_fake.h
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
 * Fake functions for the DIO wrapper module using FFF
 *
 * @section ABBR ABBREVIATIONS:
 *   - DIO - Digital Input/Output
 *   - FFF - Fake Function Framework
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

#ifdef __cplusplus
extern "C"
{
#endif

/*===========================================================================*
 * C Header Files
 *===========================================================================*/

/* Note: Include dio_wrapper.h from the real implementation to get types */
#include "dio.h"

   /*===========================================================================*
    * Fake value functions - DIO wrapper functions
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(Dio_WriteChannel, Dio_ChannelType, Dio_LevelType);
   DECLARE_FAKE_VALUE_FUNC(Dio_LevelType, Dio_ReadChannel, Dio_ChannelType);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */
#define FFF_FAKES_DIO_WRAPPER_LIST(FAKE)                                                                                          \
   FAKE(Dio_WriteChannel)                                                                                                         \
   FAKE(Dio_ReadChannel)
#endif /* DIO_WRAPPER_FAKE_H_ */
