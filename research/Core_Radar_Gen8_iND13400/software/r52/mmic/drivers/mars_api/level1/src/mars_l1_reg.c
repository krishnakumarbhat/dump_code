/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"
#include "mars_l1_raw.h"

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         write a register or bit field value to Mars and check integrity
 * @param         mars_self mars driver instance reference
 * @param         reg_id symbolic value that denotes register and bitfield info
 * @param         value to be written to the register or bitfield
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-278667 GID-286573 GID-344885
 */
Mars_ReturnType mars_write_reg_safe( mars_instance_t *const mars_self, const uint32 reg_id, const uint32 value)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if (mars_self != NULL_PTR)
    {
        /* If a candidate register is in the blacklist then we do not allow write access */
        ret_val = mars_l1_check_blacklisted_symbol(reg_id);

        if (ret_val == MARS_E_OK)
        {
            /* this is a write with safe check */
            ret_val = mars_write_reg_raw(mars_self, reg_id, value, MARS_L1_SAFE_CHK);
        }
        else
        {
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_REG_BLACKLISTED);
        }
    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         read a register or bit field value from Mars and check integrity
 * @param         mars_self mars driver instance reference
 * @param         reg_id symbolic value that denotes register and bitfield info
 * @param         value pointer to memory location in host memory where the Mars register value will be written
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-344877 GID-278669 GID-286475
 */
Mars_ReturnType mars_read_reg_safe( mars_instance_t *const mars_self, const uint32 reg_id, uint32 *const value)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    if ((mars_self != NULL_PTR) && (value != NULL_PTR))
    {
        /* If a candidate register is in the blacklist then we do not allow read access */
        ret_val = mars_l1_check_blacklisted_symbol(reg_id);

        if (ret_val == MARS_E_OK)
        {
            /* this is a read with safe check */
            ret_val = mars_read_reg_raw_safe(mars_self, reg_id, value);
        }
        else
        {
            mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_REG_BLACKLISTED);
        }
    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}
