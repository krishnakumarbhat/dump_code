/**
 * @file Driver_CRC.c
 * Driver CRC for R52 using ARMv8 builtin CRC instruction
 *
 * @date    Date created:   01-10-2025
 *
 * @copyright (c) indie Semiconductor 2025. All rights reserved.
 * Information within this file is indie Semiconductor confidential and proprietary.
 */

/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Mars_Driver_CRC.h"
#include <arm_acle.h>
#include <mars_public_types.h>

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
#define MARS_WORDS_LEN_IN_BYTES (4u)
/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/


/*===========================================================================*
 * Local Function Declarations
 *===========================================================================*/

static int32_t mars_crc32_armv8_initialize(void);
static int32_t mars_crc32_armv8_calculate(const uint8_t * const data, const uint32_t length,  const uint8_t polynomial, const uint32_t initial_seed, uint32_t * const crc);
/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
/**
 * @brief         Driver function pointer table
 * @design        GID-333514
 */

const MARS_CRC_DRIVER MARS_CPU_CRC_DRIVER = {&mars_crc32_armv8_initialize, &mars_crc32_armv8_calculate};

/*===========================================================================*
 * Local Function Definitions
 *===========================================================================*/


/**
 * @brief         initialization for ARMv8 HW machine instruction based CRC calculation
 * @return        ARM_DRIVER_OK unconditionally
 * @design        GID-335391 GID-335409
 */
static int32_t mars_crc32_armv8_initialize(void)
{
    return (int32_t)ARM_DRIVER_OK;
}

/**
 * @brief         calculate CRC with HW acceleration using CRC machine instruction of the ARMv8 ISA
 * @param [in]    data pointer to input data array
 * @param [in]    length length of data array in bytes
 * @param [in]    polynomial only supported 0x04C11DB7 that is the IEEE802.3 CRC32 poly
 * @param [in]    initial_seed init seed of the CRC calculation
 * @param [out]   crc calculated CRC
 * @return        ARM_DRIVER_OK if successful ARM_DRIVER_ERROR_PARAMETER if failed
 * @design        GID-333523 GID-335398 GID-335404
 */
static int32_t mars_crc32_armv8_calculate(const uint8_t * const data, const uint32_t length,  const uint8_t polynomial, const uint32_t initial_seed, uint32_t * const crc)
{
    int32_t ret_val = (int32_t)ARM_DRIVER_OK;
    if ((polynomial == ARM_MARS_CRC_CRC32_POLY_04C11DB7H)
        && (data != NULL_PTR)
        && (crc != NULL_PTR)
        && ((length % 4) == 0)
        && (length > 0))
    {
        const uint32_t idx = length / MARS_WORDS_LEN_IN_BYTES;

        *crc = initial_seed;
        /* Loop invariant: i less than  idx, and idx multiply 4 is equal to length ensures that data[i*4..i*4+3] is within [0..length-1] */
        for (uint32_t i = 0u; i < idx; i++)
        {
            /* polyspace-begin CERT-C:EXP36-C,EXP39-C [Justified:Medium] "uint8* parameter is maintained for compatibility to CMSIS CRC" */
            /* polyspace-begin MISRA-C-2023:11.3 [Justified:Medium] "uint8* parameter is maintained for compatibility to CMSIS CRC" */
            /* polyspace-begin CWE:704,119,843 [Justified:Medium] "uint8* parameter is maintained for compatibility to CMSIS CRC" */
            const uint32_t* const word_ptr = (const uint32_t*)(&data[i * MARS_WORDS_LEN_IN_BYTES]); /* polyspace RTE:OVFL [Not a defect:Low] "The operation based on validated input parameters to be within bounds at the caller functions" */
            /* polyspace-end CERT-C:EXP36-C,EXP39-C [Justified:Medium] "uint8* parameter is maintained for compatibility to CMSIS CRC" */
            /* polyspace-end MISRA-C-2023:11.3 [Justified:Medium] "uint8* parameter is maintained for compatibility to CMSIS CRC" */
            /* polyspace-end CWE:704,119,843 [Justified:Medium] "uint8* parameter is maintained for compatibility to CMSIS CRC" */
            /* the __crc32w instruction already Reflects the Bits order, and since that in B0 we are using NOT-Reflected configuration, we have to reflect the data back */
            /* using the Windriver intrinsic to access the CRC instruction of the ARMv8 ISA */
            *crc = __crc32w(*crc, __builtin_bitreverse32(*word_ptr)); /* polyspace RTE:IDP [Not a defect:Medium] "The operation based on validated input parameters to be within bounds at the caller functions" */
        }

        *crc ^=0xFFFFFFFFuL;
        *crc = __builtin_bitreverse32(*crc);
    }
    else
    {
        ret_val = ARM_DRIVER_ERROR_PARAMETER;
    }
    return ret_val;
}

