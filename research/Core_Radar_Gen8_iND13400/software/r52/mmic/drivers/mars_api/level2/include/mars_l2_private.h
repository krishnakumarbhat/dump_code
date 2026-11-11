/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L2_PRIVATE_H
#define MARS_L2_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_types.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/**********************************************************************************************************************
 * GLOBAL MACROS
 *********************************************************************************************************************/

/* ****************************
 * MARS SELF WRAPPER
 * ****************************/
#define MARS_DATA_DRIVER_STATUS mars_self->Mars_Data.Mars_Status.Mars_Data_drvStatus
#define MARS_DATA_MBL_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_mblError
#define MARS_DATA_MAF_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_mafError
#define MARS_DATA_SFT_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_sftError
#define MARS_DATA_SSI_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_ssiError
#define MARS_DATA_SCP_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_scpError
#define MARS_DATA_PCW_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_pcwError
#define MARS_DATA_STS_ERROR mars_self->Mars_Data.Mars_Status.Mars_Data_stsError
#define MARS_DATA_MCU_STATUS mars_self->Mars_Data.Mars_Status.Mars_Data_mcuStatus
#define MARS_DATA_CTRL_STATUS mars_self->Mars_Data.Mars_Status.Mars_Data_ctrlStatus
#define MARS_DATA_OP_MODE_STATUS mars_self->Mars_Data.Mars_Status.Mars_Data_opModeStatus
#define MARS_DATA_FW_VERSION mars_self->Mars_Data.Mars_Status.Mars_Data_fwVersion.maf_version
#define MARS_DATA_BUFFER_MAF_SRC_ADDR mars_self->Mars_Data.Mars_Buffer.firmware_srcAddr
#define MARS_DATA_BUFFER_MAF_START_ADDR mars_self->Mars_Data.Mars_Buffer.firmware_startAddr
#define MARS_DATA_BUFFER_MAF_SIZE mars_self->Mars_Data.Mars_Buffer.firmware_size
#define MARS_DATA_BUFFER_MAF_CRC mars_self->Mars_Data.Mars_Buffer.firmware_crc
#define MARS_DATA_BUFFER_SCP_ERROR mars_self->Mars_Data.Mars_Buffer.scp_error
#define MARS_DATA_BUFFER_FRESHNESS_COUNTER_DIAG mars_self->Mars_Data.Mars_Buffer.freshnessCounterDiag
#define MARS_DATA_BUFFER_DRIVER_DATA mars_self->Mars_Data.Mars_Buffer.driver_data

/* polyspace-begin CERT-C:PRE00-C [No action planned:Low] "Macro designed over inline functions" */
/* polyspace-begin MISRA-C-2023:D4.9 [No action planned:Low] "Macro designed over inline functions" */
#define MARS_GET_BIT_VALUE(value, bit) (((value) >> (bit)) & 1u)
#define MARS_BYTES_TO_WORDS(bytes) (uint32)(((bytes) / sizeof(uint32)))
#define MARS_FW_VERSION(hw, variant, major, minor, patch) (uint32)(((hw << 28u) & 0xF0000000u) |((variant << 24u) & 0x0F000000u) |((major << 16u) & 0xFF0000u) | ((minor << 8u) & 0xFF00u) | ((patch << 0u) & 0xFFu))
/* polyspace-end CERT-C:PRE00-C [No action planned:Low] "Macro designed over inline functions" */
/* polyspace-end MISRA-C-2023:D4.9 [No action planned:Low] "Macro designed over inline functions" */

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern uint32 mars_calculate_lut_parity(const uint32 parity_data);
extern uint32 mars_calculate_frm_cnt_parity(const uint16 parity_data);
extern uint32 mars_scp_get_first_error(const mars_data_buffer_scp_error_t *const err_bits);
extern Mars_ReturnType mars_api_parameter_check(const uint16 offset, mars_api_check_error_en *const param_index, const uint32 profile_table_size, const uint32 size, ConstVoidPtr const table);
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
#endif /* MARS_L2_PRIVATE_H */
