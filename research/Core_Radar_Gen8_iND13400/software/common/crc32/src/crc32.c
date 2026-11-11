/*===========================================================================*/
/**
 * @file crc32.c
 *
 * @crc32 source
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
 * @crc32 source file
 *
 * @section FULL DESCRIPTION:
 *
 * @crc32 source file
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "crc32.h"

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/

#define CRC32_REVERSED_VALUE    (0xEDB88320UL)
#define CRC32_TABLE_SIZE        (256U)

/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

static uint32_t CRC32_Table[CRC32_TABLE_SIZE];

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/**
 * @name          CRC32_Init
 * @service ID:   0x00
 * @requirements: Requirement IDs here
 * @design:       Design reference here
 * @brief         crc32 table initialization
 * @param [in]    None
 * @param [out]   None
 * @return        None
 */
void CRC32_Init(void)
{
    uint32_t c;

    for (uint32_t i = 0U; i < CRC32_TABLE_SIZE; i++) {
        c = i;
        for (uint32_t j = 0U; j < 8U; j++) {
            if ((c & 0x01U)!= 0U){
                  c = CRC32_REVERSED_VALUE ^ (c >> 1U);
            }else{
                  c = c >> 1U;
            }
        }
        CRC32_Table[i] = c;
    }
}

/**
 * @name          CRC32_GetRunTimeCRC32
 * @service ID:   0x01
 * @requirements: Requirement IDs here
 * @design:       Design reference here
 * @brief         Get CRC32 of the array input
 * @param [in]    *pBuf Pointer to array input
 * @param [in]    length size of array input
 * @param [out]   None
 * @return        retCRCValue crc32 calculated
 */

uint32_t CRC32_GetRunTimeCRC32(uint8_t *pBuf ,uint16_t length)
{
    uint32_t retCRCValue = 0xFFFFFFFFU;
    for (uint16_t i = 0; i < length; i++){
        retCRCValue=CRC32_Table[(retCRCValue ^ pBuf[i]) & 0xFFU] ^ (retCRCValue >> 8U);
    }
    return (retCRCValue^UINT32_MAX);
}



/*===========================================================================*
 *  Local Function Definitions
 *===========================================================================*/
 uint32_t crc32_sw(const uint32_t initialVal, const uint8_t *const data, const uint32_t size)
{
   uint32_t j;
   uint32_t i;
   uint32_t crc;
   uint32_t mask;
   crc = ~initialVal;
   for (i = 0U; i < size; i++)
   {
      crc = crc ^ data[i];
      for (j = 0U; j < 8U; j++)
      {
         mask = (crc & 1U) ? 0xFFFFFFFFU : 0x00000000U;
         crc  = (crc >> 1U) ^ (0xEDB88320U & mask);
      }
   }
   return ~crc;
}
