/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#include "r52_l0_crc.h"
#include "r52_l0_util.h"
/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
static Mars_ReturnType mars_l0_crc_init(mars_driver_data_t driver_data);
static Mars_ReturnType mars_l0_crc_calculate(mars_driver_data_t driver_data, const uint32 *const data, const uint32 size, uint32 *const crc);

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
/*!< Layer 0 abstraction for the CRC driver  */
mars_l0_crc_t r52_l0_crc = {.init = &mars_l0_crc_init, .calculate = &mars_l0_crc_calculate}; /* polyspace VARIABLE:ALL [No action planned:Low] "Required for Mars instance definition" */

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**
 * @brief         Initialize Layer 0 CRC driver
 * @param[out]     driver_data pointer to the driver data array, used to store the layer 0 data
 * @return        MARS_E_OK
 * @design        GID-273081 GID-329159 GID-329165
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_crc_init(mars_driver_data_t driver_data)
{
    (void)driver_data;

    return MARS_E_OK;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */

/**
 * @brief         Calculates CRC value on the input data array. Poly 0x04C11DB7u, seed 0xFFFFFFFFu.
 * @param[inout]  driver_data pointer to the driver data array, used to store the layer 0 data
 * @param [in]    data pointer to input data array
 * @param [in]    size length of data array in bytes
 * @param [out]   crc calculated CRC
 * @return        MARS_E_OK if successful MARS_L0/Driver ErrorID if failed
 * @design        GID-273085 GID-329162 GID-329168
 */
/* polyspace-begin MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-begin CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
static Mars_ReturnType mars_l0_crc_calculate(mars_driver_data_t driver_data, const uint32 *const data, const uint32 size, uint32 *const crc)
{
    int32_t ret_v_drv = ARM_DRIVER_OK;
    Mars_ReturnType ret_val = MARS_E_OK;

    (void)driver_data;

    if ((NULL_PTR != data) && (NULL_PTR != crc))
    {
        const uint32 initial_seed = 0xFFFFFFFFu;

        ret_v_drv = MARS_CPU_CRC_DRIVER.CalculateCRC32((const uint8 *)data, size, ARM_MARS_CRC_CRC32_POLY_04C11DB7H, initial_seed, (uint32_t* const)crc); /* polyspace MISRA-C-2023:11.3 [No action planned:Medium] "Cast required as per the design of the CRC interface" */

        if (ret_v_drv == ARM_DRIVER_OK)
        {
            ret_val = MARS_E_OK;
        }
        else
        {
            ret_val = MARS_ERROR_DRIVER_CRC | mars_convert_negative_errors(ret_v_drv, MARS_ERROR_ID_BIT_MASK);
        }
    }
    else
    {
        ret_val = MARS_ERROR_L0_CRC | MARS_L0_E_NOT_OK_PARAM;
    }

    return ret_val;
}
/* polyspace-end MISRA-C-2023:8.13 [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
/* polyspace-end CERT-C:DCL13-C [Justified:Low] "The pointer referenced data might be are modified when another driver is used" */
