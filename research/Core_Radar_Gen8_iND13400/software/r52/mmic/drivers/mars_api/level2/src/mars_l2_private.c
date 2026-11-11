/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l2_private.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */

/**********************************************************************************************************************
 * GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/**
 * @brief         Calculates parity bit for LUT entry
 * @param [in]    parity_data 32-bit unsigned integer representing the phase LUT entry
 * @return        Parity bit (0 or 1) for the given LUT entry
 * @design        GID-350727
 */
uint32 mars_calculate_lut_parity(const uint32 parity_data)
{
    uint32 parity_tmp = parity_data;
    parity_tmp ^= parity_tmp >> MARS_16_BITS;
    parity_tmp ^= parity_tmp >> MARS_8_BITS;
    parity_tmp ^= parity_tmp >> MARS_4_BITS;
    parity_tmp &= 0x0Fu;
    return (~((uint32)MARS_PARITY_LUT_4BIT >> parity_tmp)) & 1u;
}

/**
 * @brief         Utility function to calculate parity bit on the Frame Counter
 * @param [in]    parity_data Data for parity calculation
  * @return       Parity bits
 * @design        GID-350520
 */
uint32 mars_calculate_frm_cnt_parity(const uint16 parity_data)
{
    uint32 p0 = (uint32)parity_data & 0x00FFu;                  /* Parity for lower 8 bits */
    uint32 p1 = ((uint32)parity_data & 0xFF00u) >> MARS_8_BITS; /* Parity for upper 8 bits */

    p0 ^= p0 >> MARS_8_BITS;
    p1 ^= p1 >> MARS_8_BITS;
    p0 ^= p0 >> MARS_4_BITS;
    p1 ^= p1 >> MARS_4_BITS;
    p0 &= 0x0Fu;
    p1 &= 0x0Fu;
    p0 = ((uint32)MARS_PARITY_LUT_4BIT >> p0) & 1u;
    p1 = ((uint32)MARS_PARITY_LUT_4BIT >> p1) & 1u;
    p0 <<= 16;
    p1 <<= 17;
    return (p0 | p1);
}

/**
 * @brief         Calculates the index of the lowest position '1' bit of the returned Scratchpad error field
 * @param [in]    err_bits Pointer to the error bitfield structure
 * @return        Index of the first error bit or MARS_GETFIRSTERROR_INVALID if none found
 * @design        GID-350730
 */
uint32 mars_scp_get_first_error(const mars_data_buffer_scp_error_t *const err_bits)
{
    uint32 ret_val = MARS_GETFIRSTERROR_INVALID;
    uint32 tmp_bitfield = 0;

    /*Loop data buffer array elements*/
    for (uint32 idx = 0; idx < (sizeof(mars_data_buffer_scp_error_t) / sizeof(uint32)); idx++)
    {
        if (err_bits->word[idx] != 0)
        {
            tmp_bitfield = err_bits->word[idx];
            if ((tmp_bitfield & 0x01uL) != 0)
            {
                /*No error bit set */
                ret_val = 0;
            }
            else
            {
                /*Error detected */
                ret_val = 1uL;
                if ((tmp_bitfield & 0xFFFFuL) == 0)
                {
                    tmp_bitfield >>= 16u;
                    ret_val += 16uL;
                }
                if ((tmp_bitfield & 0xFFuL) == 0)
                {
                    tmp_bitfield >>= 8u;
                    ret_val += 8uL;
                }
                if ((tmp_bitfield & 0x0FuL) == 0)
                {
                    tmp_bitfield >>= 4u;
                    ret_val += 4uL;
                }
                if ((tmp_bitfield & 0x03uL) == 0)
                {
                    tmp_bitfield >>= 2u;
                    ret_val += 2uL;
                }
                ret_val -= tmp_bitfield & 0x01uL;
            }
            ret_val += (MARS_32_BITS * idx);
            break;
        }
    }
    return ret_val;
}

/**
 * @brief         Validates API parameters
 * @param [in]    offset Offset value to be checked
 * @param [inout] param_index Pointer to store the index of the parameter error
 * @param [in]    profile_table_size Size of the profile table
 * @param [in]    size Size to be validated against the profile table
 * @return        MARS_E_OK if parameters are valid, otherwise MARS_E_NOT_OK
 * @design        GID-350736
 */
Mars_ReturnType mars_api_parameter_check(const uint16 offset, mars_api_check_error_en *const param_index, const uint32 profile_table_size, const uint32 size, ConstVoidPtr const table)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    if ((offset % profile_table_size) != 0)
    {
        /* Param Error */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_1;
        ret_val = MARS_E_NOT_OK;
    }
    else if (offset > (MARS_PROFILE_TABLE_LEN - profile_table_size))
    {
        /* Param Error */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_1;
        ret_val = MARS_E_NOT_OK;
    }
    else if (size > (MARS_PROFILE_TABLE_LEN / profile_table_size))
    {
        /* Param Error */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
        ret_val = MARS_E_NOT_OK;
    }
    else if (((MARS_PROFILER_T0_ELEMENT_SIZE_BYTES == profile_table_size) && (size > MARS_PROFILER_T0_MAX_NO_OF_ELEMENTS)) ||
            ((MARS_PROFILER_T1_ELEMENT_SIZE_BYTES == profile_table_size) && (size > MARS_PROFILER_T1_MAX_NO_OF_ELEMENTS)))
    {
        /* Param Error */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
        ret_val = MARS_E_NOT_OK;
    }
    else if ((offset + (size * profile_table_size)) > MARS_PROFILE_TABLE_LEN)
    {
        /* Param Error */
        *param_index = MARS_L2_API_CHECK_PARAM_INDEX_2;
        ret_val = MARS_E_NOT_OK;
    }
    else
    {
        if(table == NULL_PTR)
        {
            /* Param Error */
            *param_index = MARS_L2_API_CHECK_PARAM_INDEX_3;
            ret_val = MARS_E_NOT_OK;
        }
    }
    return ret_val;
}
