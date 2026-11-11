/*===========================================================================*/
/**
 * @file Mars_Driver_CRC.h
 * Driver CRC for Chandra using ARMv8 builtin CRC instruction
 *
 * @date    Date created:   01-10-2025
 *
 * @copyright (c) indie Semiconductor 2025. All rights reserved.
 * Information within this file is indie Semiconductor confidential and proprietary.
 *
 */
/*===========================================================================*/

#ifndef MARS_DRIVER_CRC_H_
#define MARS_DRIVER_CRC_H_

#if __ARM_FEATURE_CRC32 != 1
    #error "ARM core is not supporting CRC instructions"
#endif


/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "Driver_Common.h"

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define ARM_MARS_CRC_CRC32_POLY_04C11DB7H (3U) /**< 32-bit 0x04C11DB7u polynomial CRC calculation */
/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

    /**
     * @struct MARS_CRC_DRIVER
     * @requirements    GID-333514
     * @brief           Access structure of the CRC Driver
     */
typedef struct
{
    int32_t (*Initialize)(void);    /**< Pointer to Initialize CRC interface */
    int32_t (*CalculateCRC32)(const uint8_t * const data,
                              const uint32_t length,
                              const uint8_t polynomial,
                              const uint32_t initial_seed,
                              uint32_t * const crc);  /**< Pointer to CRC32 calculation routine */
} MARS_CRC_DRIVER;  /* polyspace Custom:4.2 [No action planned:Mid] "Not Part From the API Code" */

extern const MARS_CRC_DRIVER MARS_CPU_CRC_DRIVER;

#endif /* MARS_DRIVER_CRC_H_ */
