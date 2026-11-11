/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L1_RAW_H
#define MARS_L1_RAW_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_l1_error.h"
#include "mars_types.h"

typedef enum
{
    MARS_L1_SAFE_CHK = 0,
    MARS_L1_SAFE_NO_CHK = 1,
    MARS_L1_SAFE_CHK_MLBX = 2
} mars_safe_chk_en;  /* GID-349523 */

typedef enum
{
    MARS_L1_SSI_RESET_CRC = 0,
    MARS_L1_SSI_KEEP_CRC = 1
} mars_ssi_crc_reset_en;

extern Mars_ReturnType mars_l1_read_mem_raw( mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 r_size);
extern Mars_ReturnType mars_l1_read_mem_raw_check( mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 r_size); 
extern Mars_ReturnType mars_l1_write_mem_raw( mars_instance_t *const mars_self, const uint32 *const src, const uint32 dst, const uint32 w_size, const mars_safe_chk_en chk);
extern Mars_ReturnType mars_l1_write_mem_raw_lt4(mars_instance_t *const mars_self, const uint32 *const src, const uint32 dst, const uint32 w_size, const mars_safe_chk_en chk);
extern Mars_ReturnType mars_l1_read_mem_unsafe_block(mars_instance_t *const mars_self, const uint32 src, uint32 *const dst, const uint32 size_idx, const mars_ssi_crc_reset_en crc_ctrl);

extern Mars_ReturnType mars_write_reg_raw( mars_instance_t *const mars_self, uint32 reg_id, const uint32 value, const mars_safe_chk_en chk);
extern Mars_ReturnType mars_read_reg_raw( mars_instance_t *const mars_self, const uint32 reg_id, uint32 *const value);
extern Mars_ReturnType mars_read_reg_raw_safe( mars_instance_t *const mars_self, const uint32 reg_id, uint32 *const value);


extern Mars_ReturnType mars_l1_check_blacklisted_symbol(const uint32 reg_id);
extern Mars_ReturnType mars_l1_check_blacklisted_address(const uint32 address);
extern Mars_ReturnType mars_l1_check_blacklisted_in_range_address(const uint32 start_address,const uint32 size);
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* MARS_L1_RAW_H */
