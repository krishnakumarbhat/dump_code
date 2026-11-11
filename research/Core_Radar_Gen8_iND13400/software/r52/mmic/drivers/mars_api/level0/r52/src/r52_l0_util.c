/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#include "r52_l0_util.h"



/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PUBLIC FUNCTIONS
 *********************************************************************************************************************/


/**
 * @brief         Checks if the Radar API is compatible to the underlying drivers
 * @param [in]    actual the actual driver version of the CMSIS driver
 * @param [in]    expected expected driver version that the Radar API is compatible with
 * @return        MARS_E_OK if Radar API is compatible with the actual driver, MARS_L0_E_DRV_MISMATCH otherwise
 * @design        GID-367886 GID-367888 GID-367883
 */
Mars_ReturnType mars_check_driver_version(const mars_driver_version_t actual, const mars_driver_version_t expected)
{
    Mars_ReturnType ret_val = MARS_L0_E_DRV_MISMATCH;
    if ((actual.api & 0xFF00u) == (expected.api  & 0xFF00u))
    {
        if ((actual.drv & 0xFF00u) == (expected.drv & 0xFF00u))
        {
            ret_val = MARS_E_OK;
        }
    }
    return ret_val;
}

/**
 * @brief         Converts negative return values from CMSIS drivers to positive error codes defined in the Radar API.
 * @param [in]    ret_v_drv the return value from the CMSIS driver function, which can be positive (indicating success) or negative (indicating an error)
 * @param [in]    driver_error_mask the bitmask to extract the relevant error code
 * @return        The converted error code, which is a positive value defined in the Radar API.
 * @design        GID-505754 GID-505755 GID-505756
 */
Mars_ReturnType mars_convert_negative_errors(const sint32 ret_v_drv,const uint32 driver_error_mask) /* polyspace GUIDELINE:SC04 [No action planned:Medium] "The function is used by all driver errors ro convert from CMSIS negative return values to Radar API positive return values." */
{
    Mars_ReturnType ret_val = 0x80000000u; 
    if (ret_v_drv >= 0)
    {
        ret_val = ((uint32)ret_v_drv & driver_error_mask);
    }
    else
    {
        if( ret_v_drv > SINT32_MIN)
        {
            uint32 unsigned_ret_v_drv = (uint32)(- ret_v_drv);
            unsigned_ret_v_drv = ~unsigned_ret_v_drv + 1; /* Two's complement to convert to positive error code */
            ret_val = (unsigned_ret_v_drv & driver_error_mask);
        }  
    }
    return ret_val;
}

