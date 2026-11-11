#ifndef CRC_CALC_MOCKS_H_
#define CRC_CALC_MOCKS_H_

/*===========================================================================*/
/**
 * @file crc_calc_mocks.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocking functions for the crc_calc.c file
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
#endif
#include "crc_calc.h"
#include "fff.h"

   /*===========================================================================*
    * FAKE VALUE FUNCTIONS for crc_calc.c
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Crc_CalculateCRC32_HW, const uint8_t *, uint32_t, uint32_t, bool);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Crc_CalculateCRC32_Channel1, const uint8_t *, uint32_t, uint32_t, bool);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Compute_CRC32_SW, uint8_t *, uint32_t, uint32_t, bool);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Calc_M2D_Buf_Crc, volatile const M2D_Msg_T *);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Calc_D2M_Buf_Crc_Chn_X, volatile D2M_Msg_T *, uint8_t);

   /*===========================================================================*
    * FAKE VOID FUNCTIONS for crc_calc.c
    *===========================================================================*/

#ifdef __cplusplus
}
#endif

/* Reset fake functions */
#define FFF_FAKES_CRC_CALC_LIST(FAKE)                                                                                             \
   FAKE(Crc_CalculateCRC32_HW)                                                                                                    \
   FAKE(Compute_CRC32_SW)                                                                                                         \
   FAKE(Crc_CalculateCRC32_Channel1)                                                                                              \
   FAKE(Calc_M2D_Buf_Crc)                                                                                                         \
   FAKE(Calc_D2M_Buf_Crc_Chn_X)

#endif /* CRC_CALC_MOCKS_H_ */
