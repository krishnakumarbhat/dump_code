/*  Register blacklist for API level register access
    entries on this list are not permitted to be read by the application
    in order to avoid incorrect system behavior.

    @copyright 2025 indie Semiconductor.
    * This item is considered confidential and shall not be used, modified,
    * or distributed without prior written consent from Indie Semiconductor. */

/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l1_raw.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_regs_gen.h"

/**********************************************************************************************************************
 * LOCAL VARIABLE DECLARATION
 *********************************************************************************************************************/
 static const uint32 MARS_BLACKLIST[] = {
    0x31010uL,  /*MARS_R_ASYNC_BANK_ASYNC_MC_DATA_OUT_CTRL*/
    0x35144uL,  /*MARS_R_CPU_SYS_MCU_ERR_EN_CTRL*/
    0x39014uL,  /*MARS_R_CPLL_BANK_DBG_DIGTUNE_LSB*/
    0x39018uL,  /*MARS_R_CPLL_BANK_DBG_DIGTUNE_MSB*/
    0x39004uL,  /*MARS_R_CPLL_BANK_DBG_FINE_STEP_LSB*/
    0x39008uL,  /*MARS_R_CPLL_BANK_DBG_FINE_STEP_MSB*/
    0x3900CuL,  /*MARS_R_CPLL_BANK_DBG_DIVCTR_SAMPLE_LSB*/
    0x39010uL,  /*MARS_R_CPLL_BANK_DBG_DIVCTR_SAMPLE_MSB*/
    0x35700uL,  /*MARS_R_CPU_SYS_MLBX_ASSIGN_LOWP_L*/
    0x35704uL,  /*MARS_R_CPU_SYS_MLBX_ASSIGN_LOWP_H*/ 
    0x35708uL,  /*MARS_R_CPU_SYS_MLBX_ASSIGN_HIGHP_L*/
    0x3570CuL,  /*MARS_R_CPU_SYS_MLBX_ASSIGN_HIGHP_H*/
    0x35710uL,  /*MARS_R_CPU_SYS_MLBX_RELEASE_L*/
    0x35714uL,  /*MARS_R_CPU_SYS_MLBX_RELEASE_H*/
    0x35144uL,  /*MARS_F_CPU_SYS_MLBX_ASSIGN_PAR_ERR_EN*/
    0x31010uL,  /*MARS_F_ASYNC_BANK_ASYNC_MC_DATA_OUT_RD & MARS_F_ASYNC_BANK_ASYNC_MC_DATA_OUT_RD_R*/
    0x31014uL,  /*MARS_R_ASYNC_BANK_ASYNC_MC_DATA_OUT01*/
    0x31018uL,  /*MARS_R_ASYNC_BANK_ASYNC_MC_DATA_OUT23*/
    0x3B038uL,  /*MARS_R_SSI_BANK_TXUICR*/
    0x3B03CuL,  /*MARS_R_SSI_BANK_RXOICR */
    0x3B040uL,  /*MARS_R_SSI_BANK_SPIMECR*/
    0x3B044uL,  /*MARS_R_SSI_BANK_AHBECR*/
    0x3B048uL   /*MARS_R_SSI_BANK_ICR*/        
};


/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/**
 * @brief Checks if a given register symbol is blacklisted
 *
 * This function checks whether the provided register symbol (represented by its ID)
 * is in the blacklist. It ignores the lower 16 bits of the ID, which contain
 * bit field metadata.
 *
 * @param reg_id The 32-bit register symbol ID to check
 * @return Mars_ReturnType MARS_E_OK if the symbol is not blacklisted, E_NOT_OK if it is
 8 @design GID-345214 GID-345232 GID-345235
 */
Mars_ReturnType mars_l1_check_blacklisted_symbol(const uint32 reg_id) /* polyspace GUIDELINE:SC18 [No action planned:Low] "Fixing the language scope will affect the readability of the function" */
{
    Mars_ReturnType ret_val = MARS_E_OK;

    const uint32 reg_id_masked = reg_id >> MARS_16_BITS;
    if ((reg_id_masked == (MARS_R_ASYNC_BANK_ASYNC_MC_DATA_OUT_CTRL >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MCU_ERR_EN_CTRL >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPLL_BANK_DBG_DIGTUNE_LSB >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPLL_BANK_DBG_DIGTUNE_MSB >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPLL_BANK_DBG_FINE_STEP_LSB >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPLL_BANK_DBG_FINE_STEP_MSB >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPLL_BANK_DBG_DIVCTR_SAMPLE_LSB >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPLL_BANK_DBG_DIVCTR_SAMPLE_MSB >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MLBX_ASSIGN_LOWP_L >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MLBX_ASSIGN_LOWP_H >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MLBX_ASSIGN_HIGHP_L >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MLBX_ASSIGN_HIGHP_H >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MLBX_RELEASE_L >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_CPU_SYS_MLBX_RELEASE_H >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_ASYNC_BANK_ASYNC_MC_DATA_OUT01 >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_ASYNC_BANK_ASYNC_MC_DATA_OUT23 >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_SSI_BANK_TXUICR >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_SSI_BANK_RXOICR >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_SSI_BANK_SPIMECR >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_SSI_BANK_AHBECR >> MARS_16_BITS)) ||
        (reg_id_masked == (MARS_R_SSI_BANK_ICR >> MARS_16_BITS)))
    {
        ret_val = MARS_L1_E_NOT_OK;
    }
    return ret_val;
}

/**
 * @brief Checks if a given address is blacklisted
 *
 * This function checks whether the provided 32-bit address is in the blacklist.
 * It performs a direct comparison of the full address.
 *
 * @param address The 32-bit address to check
 * @return Mars_ReturnType MARS_E_OK if the address is not blacklisted, E_NOT_OK if it is
 * @design GID-345241 GID-345229 GID-345238
 */
Mars_ReturnType mars_l1_check_blacklisted_address(const uint32 address)
{
    Mars_ReturnType ret_val = MARS_E_OK;

    for (uint32 index = 0; index < (sizeof(MARS_BLACKLIST) / sizeof(MARS_BLACKLIST[0])); index++)
    {
        if (address == MARS_BLACKLIST[index])
        {
            ret_val = MARS_L1_E_NOT_OK;
            break;
        }
    }
    return ret_val;
}


/**
 * @brief Checks if a given address is blacklisted
 *
 * This function checks whether the memory range includes the specified address.
 * It iterates through the addresses to verify whether they are included within the memory block.
 *
 * @param start_address The 32-bit start address to check
 * @param size The size of the memory range in bytes
 * @return Mars_ReturnType MARS_E_OK if the address is not blacklisted, E_NOT_OK if it is
 * @design  GID-421606 GID-421520 GID-421524
 */
Mars_ReturnType mars_l1_check_blacklisted_in_range_address(const uint32 start_address,const uint32 size)
{
    Mars_ReturnType ret_val = MARS_E_OK;
    const uint32 end_address = start_address + size - 1u;

    for (uint32 index = 0; index < (sizeof(MARS_BLACKLIST) / sizeof(MARS_BLACKLIST[0])); index++)
    {
        if ((start_address <= MARS_BLACKLIST[index]) && (MARS_BLACKLIST[index] <= end_address))
        {
            ret_val = MARS_L1_E_NOT_OK;
            break;
        }
    }
    return ret_val;
}

