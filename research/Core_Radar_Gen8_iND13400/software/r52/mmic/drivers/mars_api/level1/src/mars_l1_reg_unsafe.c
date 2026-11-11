/* @copyright 2024 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1.h"
#include "mars_l1_raw.h"
#include "mars_regs_gen.h"

/**********************************************************************************************************************
 * LOCAL MACROS
 *********************************************************************************************************************/
#define MARS_REG_MODULE_IDX_SHIFT (26u)
#define MARS_REG_OFFSET_SHIFT (14u)
#define MARS_REG_WIDTH_SHIFT (8u)

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         Write Mars register with optional checking the integrity of the written values
 * @param[in]     mars_self pointer to mars instance variable
 * @param[in]     reg_id encoded register and field data
 * @param[in]     value the register or field value to be written
 * @param[in]     chk control if integrity chec shall be performed
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-345138 GID-345135 GID-345135
 */

Mars_ReturnType mars_write_reg_raw( mars_instance_t *const mars_self, uint32 reg_id, const uint32 value, const mars_safe_chk_en chk)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const uint32 module_idx = reg_id >> MARS_REG_MODULE_IDX_SHIFT;          /* module index denotes  the Mars peripheral */
    const uint32 reg_offset = ((reg_id >> MARS_REG_OFFSET_SHIFT) & 0xFFCu); /* calculate register offset within the peripheral */
    const uint32 width = ((reg_id >> MARS_REG_WIDTH_SHIFT) & 0xFFu);
    const uint32 start_bit = (reg_id & 0xFFu);

    /* check if parameters are valid and within range */
    if ((mars_self != NULL_PTR) && (module_idx < MARS_MODULES) && (reg_offset <= mars_module_desc[module_idx].max_offset) && (start_bit < 32) && ((start_bit + width) <= 32) && (width > 0))
    {
        const uint32 addr = mars_module_desc[module_idx].base_address + reg_offset;
        uint32 tmp_first = 0;

        if (width == 32)
        {
            tmp_first = value;
            /* if a complete 32 bits register value shall be written then it is done in a direct memory write */
            ret_val = mars_l1_write_mem_raw_lt4(mars_self, &tmp_first, addr, 1, chk);
        }
        else
        {
            /* if a field value shall be written then it is done in two steps:
             * first read the register
             * then mask the value and write back */
            if (value < (1UL << width))
            {
                ret_val = mars_l1_read_mem_unsafe_block(mars_self, addr, &tmp_first, 0, MARS_L1_SSI_RESET_CRC); 

                if (ret_val == MARS_E_OK)
                {
                    tmp_first &= ~(uint32)((1UL << (start_bit + width)) - (1UL << start_bit)); /* polyspace RTE:SHF,OVFL [No action planned:Low] "Shift-by-32 needed when field extends to bit 31 (start_bit+width==32). The result is consistent on target platform" */
                    tmp_first |= (value << start_bit); /* polyspace RTE:OVFL [Not a defect:Medium] "The operation operands applied to DRS" */
                    ret_val = mars_l1_write_mem_raw_lt4(mars_self, &tmp_first, addr, 1, chk);
                }
            }
            else
            {
                mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_REG_INVALID_SIZE);
            }
        }

    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Read Mars register without checking the integrity of the read values
 * @param[in]     mars_self pointer to mars instance variable
 * @param[in]     reg_id encoded register and field data
 * @param[in]     value pointer to the  register or field value to be read to
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-345144 GID-345212
 */
Mars_ReturnType mars_read_reg_raw( mars_instance_t *const mars_self, const uint32 reg_id, uint32 *const value)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const uint32 module_idx = reg_id >> MARS_REG_MODULE_IDX_SHIFT;          /* module index denotes  the Mars peripheral */
    const uint32 reg_offset = ((reg_id >> MARS_REG_OFFSET_SHIFT) & 0xFFCu); /* calculate register offset within the peripheral */
    const uint32 width = ((reg_id >> MARS_REG_WIDTH_SHIFT) & 0xFFu);
    const uint32 start_bit = (reg_id & 0xFFu);

    /* check if parameters are valid and within range */
    if ((mars_self != NULL_PTR) && (reg_offset <= mars_module_desc[module_idx].max_offset) && (start_bit < 32) && (module_idx < MARS_MODULES) && ((start_bit + width) <= 32) && (width > 0))
    {
        const uint32 addr = mars_module_desc[module_idx].base_address + reg_offset;
        uint32 tmp_first = 0;

        ret_val = mars_l1_read_mem_raw(mars_self, addr, &tmp_first, 1uL);
        
        if (ret_val == MARS_E_OK)
        {
            if (width < 32u)
            {
                const uint32 shift = (MARS_32_BITS - width) % MARS_32_BITS;
                tmp_first >>= start_bit;
                tmp_first &= (MARS_MAX_32_BITS_VALUE >> shift);
            }
            *value = tmp_first;
        }
    }
    else
    { /* polyspace RTE:UNR [Not a defect:Low] "Null pointer check for unit level testability" */
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}

/**
 * @brief         Read Mars register with checking the integrity of the read values safely 
 * @param[in]     mars_self pointer to mars instance variable
 * @param[in]     reg_id encoded register and field data
 * @param[in]     value pointer to the  register or field value to be read to
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-477569 GID-477572
 */
Mars_ReturnType mars_read_reg_raw_safe( mars_instance_t *const mars_self, const uint32 reg_id, uint32 *const value)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const uint32 module_idx = reg_id >> MARS_REG_MODULE_IDX_SHIFT;          /* module index denotes  the Mars peripheral */
    const uint32 reg_offset = ((reg_id >> MARS_REG_OFFSET_SHIFT) & 0xFFCu); /* calculate register offset within the peripheral */
    const uint32 width = ((reg_id >> MARS_REG_WIDTH_SHIFT) & 0xFFu);
    const uint32 start_bit = (reg_id & 0xFFu);

    /* check if parameters are valid and within range */
    if ((mars_self != NULL_PTR) && (start_bit < 32) && ((start_bit + width) <= 32) && (module_idx < MARS_MODULES) && (reg_offset <= mars_module_desc[module_idx].max_offset) && (width > 0))
    {
        uint32 tmp_first = 0;
        const uint32 addr = mars_module_desc[module_idx].base_address + reg_offset;

        ret_val = mars_l1_read_mem_raw_check(mars_self, addr, &tmp_first, 1uL);
        
        if (ret_val == MARS_E_OK)
        {
            if (width < 32u)
            {
                tmp_first >>= start_bit;
                const uint32 shift = (MARS_32_BITS - width) % MARS_32_BITS;
                tmp_first &= (MARS_MAX_32_BITS_VALUE >> shift);
            }
            *value = tmp_first;
        }
    }
    else
    {
        mars_set_l1_error_information(&ret_val, MARS_NO_DATA, MARS_ERROR_L1_REG, MARS_L1_E_NOT_OK_PARAM);
    }

    return ret_val;
}
