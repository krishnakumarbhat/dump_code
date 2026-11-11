/*===========================================================================*/
/**
 * @file crc32.h
 *
 * @crc32 header
 *
 * @version version:         00.00.01
 * @author  derived_by:      Carlos Ruiz
 * @date    date_modified:   07-19-2022
 *
 *------------------------------------------------------------------------------
 *
 * @copyright 2022 Indie Semiconductor.
 *
 * This file is proprietary to Indie Semiconductor.
 * All rights reserved. Reproduction or distribution, in whole
 * or in part, is forbidden except by express written permission
 * of Indie Semiconductor.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESCRIPTION:
 *
 * @crc32 Header file
 *
 * @section FULL DESCRIPTION:
 *
 * @crc32 Header file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Desing document location here
 *
 *   - Requirements Document(s):
 *     - @Requirements document location here
 *
 *   - Applicable Standards:
 *     - @Standards here
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef CRC32_H_
#define CRC32_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

/* Define IDs API*/

/** CRC32 Init API */
#define CRC32_SID_INIT                          ((uint8) 0x00U)

/** CRC32 Get Run Time CRC API */
#define CRC32_SID_GET_RUN_TIME_CRC              ((uint8) 0x01U)

/* NVM Virgin CRC detection macros - used to identify uninitialized/erased NVM data */
#define NVM_CRC_ERASED_VALUE (0xFFFFFFFFUL)
#define NVM_CRC_EMPTY_VALUE  (0UL)
#define IS_VIRGIN_CRC(value) (((value) == NVM_CRC_ERASED_VALUE) || ((value) == NVM_CRC_EMPTY_VALUE))

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/

/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/
void CRC32_Init(void);
uint32_t CRC32_GetRunTimeCRC32(uint8_t *pBuf ,uint16_t length);
uint32_t crc32_sw(const uint32_t initialVal, const uint8_t *const data, const uint32_t size);
/*===========================================================================*
* Exported Inline Function Definitions and #define Function-Like Macros
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* CRC32_H_*/
