#ifndef CRC_MOCKS_H
#define CRC_MOCKS_H
/*===========================================================================*/
/**
 * @file Crc_mocks.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for the Crc FFF
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
   #include "Crc.h"
   #include "Rte_SWC_PLT_CDD_MCU_Safety.h"
   #include "Std_Types.h"
   #include "fff.h"
   /*===========================================================================*
    * C Header Files
    *===========================================================================*/
   /*===========================================================================*
    * Fake value functions - Crc functions
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Crc_CalculateCRC32, Crc_DataRefType, uint32, uint32, boolean);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo,
                           Rte_DT_Dt_StaticRegCheckFailureInfo_0 *);
   #ifdef __cplusplus
}
   #endif
#endif
#define FFF_FAKES_CRC_LIST(FAKE) FAKE(Crc_CalculateCRC32)

#endif /* CRC_MOCKS_H */
