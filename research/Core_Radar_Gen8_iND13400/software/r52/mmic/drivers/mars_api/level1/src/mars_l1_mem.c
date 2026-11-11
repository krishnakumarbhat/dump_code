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
 * LOCAL MACRO
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL CONSTANT DECLARATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**
 * @brief         write a word or array of words to Mars memory and check integrity
 * @param         mars_self mars driver instance reference
 * @param         src pointer to host memory where the data will be read from
 * @param         dst Mars memory start address where the data will be written to
 * @param         w_size number of data words to be written to Mars
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-286133 GID-286585 GID-344738
 */
Mars_ReturnType mars_write_mem_safe( mars_instance_t *const mars_self, const uint32 *const src, uint32 dst, const uint32 w_size)
{
    return mars_l1_write_mem_raw(mars_self, src, dst, w_size, MARS_L1_SAFE_CHK);
}

/**
 * @brief         reads a word or array of words from Mars memory. Provided for consistency with write counterpart
 * @param         mars_self mars driver instance reference
 * @param         src Mars memory start address where the data will be read from
 * @param         dst pointer to host memory where the data will be written to
 * @param         r_size number of data words to be read from Mars
 * @return        MARS_E_OK if successful MARS_L1_E_NOT_OK_PARAM if param error MARS_L1/L0 ErrorID if failed
 * @design        GID-286132 GID-286587 GID-344339
 */

Mars_ReturnType mars_read_mem_safe( mars_instance_t *const mars_self, uint32 const src, uint32 *const dst, const uint32 r_size)
{
    return mars_l1_read_mem_raw_check(mars_self, src, dst, r_size);
}
