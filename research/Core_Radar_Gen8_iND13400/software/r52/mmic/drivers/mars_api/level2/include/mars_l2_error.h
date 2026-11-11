/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L2_ERROR_H
#define MARS_L2_ERROR_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_public_types.h"
#include "mars_error.h"
/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void mars_set_l2_error_information(Mars_ReturnType *const ret_val_ptr, const uint32 instance_id, const uint32 flags, const uint32 error_l2, const uint32 error_id);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/**********************************************************************************************************************
 * MARS ERROR L2
 *********************************************************************************************************************/
#define MARS_ERROR_L2_MBL               (1UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Boot Loader Error Type - Error IDs defined in the mars_mbl_error_en */
#define MARS_ERROR_L2_MAF               (2UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Application Firmware Error Type - Error IDs defined in the mars_maf_error_en */
#define MARS_ERROR_L2_UNUSED_MDF        (3UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Unused Error Type */ /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "Unused Error ID kept for design" */
#define MARS_ERROR_L2_SSI               (4UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars SSI Error Type - Error IDs defined in the mars_ssi_error_en */
#define MARS_ERROR_L2_SCP               (5UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Scratch-pad Configure Error Type - Error IDs defined in the mars_scp_error_en */
#define MARS_ERROR_L2_PCW               (6UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Pure CW Error Type - Error IDs defined in the mars_pcw_error_en */
#define MARS_ERROR_L2_STS               (7UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Status Error Type - Error IDs defined in the mars_sts_error_en */
#define MARS_ERROR_L2_API_CHECK         (8UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars API Check Error Type - Error IDs defined in the mars_api_check_error_en */
#define MARS_ERROR_L2_SCP_CAL_STATE     (9UL  << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Scratch-pad Calibration State Alignment error - Error IDs defined in MAF documentation */
#define MARS_ERROR_L2_UPDATE_DIAG       (10UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Update Diagnostic Values Error Type - Error IDs defined in the mars_update_diag_error_en */
#define MARS_ERROR_L2_FRAME             (12UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Trigger Frame Error Type - Error IDs defined in the mars_trigger_frame_error_en */
#define MARS_ERROR_L2_READ_BIST         (13UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Read BIST Error Type - Error IDs defined in the mars_read_bist_error_en */
#define MARS_ERROR_L2_READ_DIAG_RAW     (14UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Read Diagnostic Raw Error Type - Error IDs defined in the mars_read_diag_raw_error_en */
#define MARS_ERROR_L2_CLEAR_SFT_ERR     (15UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Clear Recoverable Safety Error Type - Error IDs defined in the mars_clear_sft_error_en */
#define MARS_ERROR_L2_TEST_SFT_PIN      (16UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars SFT Test Error Type - Error IDs defined in the mars_sft_test_error_en */
#define MARS_ERROR_L2_FRM_WAIT          (17UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Wait for Frame complete Error Type - Error IDs defined in the mars_wait_frame_error_en */
#define MARS_ERROR_L2_RD_BACK           (18UL << MARS_ERROR_L2_BIT_OFFSET)    /*!< Mars Read-Back Error Type - Error IDs defined in the mars_rd_back_error_en */

/**********************************************************************************************************************
 * MARS ERROR IDs LEVEL 2
 *********************************************************************************************************************/

/** @typedef mars_mbl_error_en
 *  @brief Enumeration for Mars Boot Loader errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_MBL_NO_ERROR = 0u,                /*!< [value 0] Mars Boot Loader - No Error */
    MARS_L2_MBL_OTPM_ERROR = 1u,              /*!< [value 1] Mars Boot Loader - OTPM Error */
    MARS_L2_MBL_WRITE_SEC_REG_ERROR = 2u,     /*!< [value 2] Mars Boot Loader - Write Secure Register Error */
    MARS_L2_MBL_BOR_ERROR = 3u,               /*!< [value 3] Mars Boot Loader - BOR Error */
    MARS_L2_MBL_ADDITIONAL_CMD_ERROR = 4u,    /*!< [value 4] Mars Boot Loader - MBL Error in Additional OTPM commands */
    MARS_L2_MBL_CLOCK_CORE_ERROR = 5u,        /*!< [value 5] Mars Boot Loader - Clock core Error */
    MARS_L2_MBL_CLOCK_SYS_ERROR = 6u,         /*!< [value 6] Mars Boot Loader - Clock system Error */
    MARS_L2_MBL_NO_CLOCK_SET_ERROR = 0x8000u, /*!< [value 0x8000] Mars Boot Loader - No clock set Error */
    MARS_L2_MBL_PMU_TASK_ERROR = 8u,          /*!< [value 8] Mars Boot Loader - PMU Task failed during booting */
    MARS_L2_MBL_PMU_BIST_ERROR = 9u,          /*!< [value 9] Mars Boot Loader - PMU BIST failed during booting */
    MARS_L2_MBL_MCU_TASK_ERROR = 10u,         /*!< [value 10] Mars Boot Loader - UNUSED error value, kept from future extensions and to maintain the layout unchanged between updates */
    MARS_L2_MBL_MCU_MLBX_ERROR = 11u,         /*!< [value 11] Mars Boot Loader - UNUSED error value, kept from future extensions and to maintain the layout unchanged between updates */
    MARS_L2_MBL_UNKNOWN_ERROR = 12u,          /*!< [value 12] Mars Boot Loader - Unknown Error */
    MARS_L2_MBL_DFT_ERROR = 13u,              /*!< [value 13] Mars Boot Loader - DFT verification failed */
    MARS_L2_MBL_REF_PLL_ERROR = 14u,          /*!< [value 14] Mars Boot Loader - UNUSED error value, kept from future extensions and to maintain the layout unchanged between updates */
    MARS_L2_MBL_ADC_PLL_ERROR = 15u,          /*!< [value 15] Mars Boot Loader - UNUSED error value, kept from future extensions and to maintain the layout unchanged between updates */
} mars_mbl_error_en;

/** @typedef mars_maf_error_en
 *  @brief Enumeration for Mars Application Firmware errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_MAF_NO_ERROR = 0u,                  /*!< [value 0] Mars Application Firmware - No Error */
    MARS_L2_MAF_KEY_INCORRECT_ERROR = 1u,       /*!< [value 1] Mars Application Firmware - Incorrect Security Key Error */
    MARS_L2_MAF_CRC_INCORRECT_ERROR = 2u,       /*!< [value 2] Mars Application Firmware - Incorrect CRC Error */
    MARS_L2_MAF_RADAR_READY_TIMEOUT_ERROR = 3u, /*!< [value 3] Mars Application Firmware - Radar Ready timeout expired Error */
    MARS_L2_MAF_VERSION_MISMATCH_ERROR = 4u,    /*!< [value 4] Mars Application Firmware - Version mismatch Error */
    MARS_L2_MAF_UNKNOWN_ERROR = 5u,              /*!< [value 5] Mars Application Firmware - Unknown Error */
    MARS_L2_MAF_NOT_UPLOAD_ERROR = 6u,          /*!< [value 6] Mars Application Firmware - MAF not uploaded Error */
    MARS_L2_MAF_SECURE_MAF_ERROR = 7u,          /*!< [value 7] Mars Application Firmware - Secure MAF Error */
    MARS_L2_MAF_CRC_ERROR = 8u                  /*!< [value 8] Mars Application Firmware - CRC error detected by MAF */
} mars_maf_error_en;


/** @typedef mars_sft_error_en
 *  @brief Enumeration for Mars SFT errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_SFT_NO_ERROR = 0x00u,                         /*!< [value 0x00] No error */
    MARS_L2_SFT_BOR_POWER_ERROR = 0x01u,                  /*!< [value 0x01] [bit 0] BOR Power error */
    MARS_L2_SFT_PLL_ERROR = 0x02u,                        /*!< [value 0x02] [bit 1] Ref-PLL error */
    MARS_L2_SFT_MCU_ERROR = 0x04u,                        /*!< [value 0x04] [bit 2] MCU error detected */
    MARS_L2_SFT_LOGEN_ERROR = 0x08u,                      /*!< [value 0x08] [bit 3] LOGEN error */
    MARS_L2_SFT_RXADC_ERROR = 0x10u,                      /*!< [value 0x10] [bit 4] Rx-ADC error */
    MARS_L2_SFT_FRM_ERROR = 0x20u,                        /*!< [value 0x20] [bit 5] Frame control error */
    MARS_L2_SFT_ASYNC_ERROR = 0x40u,                      /*!< [value 0x40] [bit 6] Async unit error */
    MARS_L2_SFT_PROFILER_ERROR = 0x80u,                   /*!< [value 0x80] [bit 7] Profiler unit error */
    MARS_L2_SFT_ENA_ERROR = 0x100u,                       /*!< [value 0x100] [bit 8] Enable unit error */
    MARS_L2_SFT_SYS_ADC_PLL_UNLOCK = 0x200u,              /*!< [value 0x200] [bit 9] Sys ADC PLL Unlock */
    MARS_L2_SFT_MCU_SUBSYSTEM_ERROR = 0x400u,             /*!< [value 0x400] [bit 10] MCU subsystem error */
    MARS_L2_SFT_CSI2_ERROR = 0x800u,                      /*!< [value 0x800] [bit 11] CSI2 error */
    MARS_L2_SFT_SSI_ERROR = 0x1000u,                      /*!< [value 0x1000] [bit 12] SSI error */
    MARS_L2_SFT_CHIRP_LINEARITY_OR_SYNTH_ERROR = 0x2000u, /*!< [value 0x2000] [bit 13] Chirp linearity or synthesizer lock indication error */
    MARS_L2_SFT_RFE_SFT_ERROR = 0x4000u,                  /*!< [value 0x4000] [bit 14] RFE Safety */
    MARS_L2_SFT_BIST_ERROR = 0x8000u,                     /*!< [value 0x8000] [bit 15] Bist/DFT/TE safety error */
    MARS_L2_SFT_IRQ_ERROR = 0xFFFFu,                      /*!< [value 0xFFFF] Notification from the SFT_IRQ */
} mars_sft_error_en;

/** @typedef mars_ssi_error_en
 *  @brief Enumeration for Mars SSI errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_SSI_NO_ERROR = 0u,              /*!< [value 0] SSI - No Error */
    MARS_L2_SSI_OPERATION_MODE_ERROR = 1u   /*!< [value 2] SSI - Invalid Operation Mode Reported */
} mars_ssi_error_en;

/** @typedef mars_scp_error_en
 *  @brief Enumeration for Mars Mailbox Scratchpad command errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_SCP_NO_ERROR = 0u,                     /*!< [value 0] Mailbox Scratchpad command - No Error */
    MARS_L2_SCP_CRC_INCORRECT_ERROR = 1u,          /*!< [value 1] Mailbox Scratchpad command - CRC Check Error */
    MARS_L2_SCP_PARAMETER_ERROR = 2u,              /*!< [value 2] Mailbox Scratchpad command - Parameter Error */
    MARS_L2_SCP_UNKNOWN_ERROR = 3u,                /*!< [value 3] Mailbox Scratchpad command - Unknown Error */
    MARS_L2_SCP_RFDIST_MODE_ERROR = 4u,            /*!< [value 4] Mailbox Scratchpad command - rfdist_mode cannot be set or invalid */
    MARS_L2_SCP_IFVGA_HPF_MODE_ERROR = 5u,         /*!< [value 5] Mailbox Scratchpad command - HPF_mode cannot be set or invalid */
    MARS_L2_SCP_TX_PH_MODE_ERROR = 6u,             /*!< [value 6] Mailbox Scratchpad command - tx_ph_mode cannot be set or invalid */
    MARS_L2_SCP_TX_OFF_OFFSET_ERROR = 7u,          /*!< [value 7] Mailbox Scratchpad command - tx_off_offset cannot be set or invalid */
    MARS_L2_SCP_TX_ON_OFFSET_ERROR = 8u,           /*!< [value 8] Mailbox Scratchpad command - tx_on_offset cannot be set or invalid */
    MARS_L2_SCP_TX_SEQ_OFFSET_ERROR = 9u,          /*!< [value 9] Mailbox Scratchpad command - tx_seq_offset cannot be set or invalid */
    MARS_L2_SCP_RX_EN_MODE_ERROR = 10u,            /*!< [value 10] Mailbox Scratchpad command - rx_en_mode cannot be set or invalid */
    MARS_L2_SCP_TX_EN_MODE_ERROR = 11u,            /*!< [value 11] Mailbox Scratchpad command - tx_en_mode cannot be set or invalid */
    MARS_L2_SCP_RX_IFVGA_STAGE_ERROR = 12u,         /*!< [value 12] Mailbox Scratchpad command - ifvga_stage1 cannot be set or invalid */
    MARS_L2_SCP_OPS_UNUSED_ERROR = 13u,              /*!< [value 13] Mailbox Scratchpad command - ops_unused cannot be set or invalid */
    MARS_L2_SCP_RX_ADC_MODE_ERROR = 14u,           /*!< [value 14] Mailbox Scratchpad command - rx_adc_mode cannot be set or invalid */
    MARS_L2_SCP_RX_OFF_OFFSET_ERROR = 15u,         /*!< [value 15] Mailbox Scratchpad command - rx_off_offset cannot be set or invalid */
    MARS_L2_SCP_RX_ON_OFFSET_ERROR = 16u,          /*!< [value 16] Mailbox Scratchpad command - rx_on_offset cannot be set or invalid */
    MARS_L2_SCP_RX_SEQ_OFFSET_ERROR = 17u,         /*!< [value 17] Mailbox Scratchpad command - rx_seq_offset cannot be set or invalid */
    MARS_L2_SCP_METADATA_ENABLE_ERROR = 18u,       /*!< [value 18] Mailbox Scratchpad command - metadata_enable cannot be set or invalid */
    MARS_L2_SCP_RX_ADC_SAMP_FRQ_ERROR = 19u,       /*!< [value 19] Mailbox Scratchpad command - rx_adc_samp_frq cannot be set or invalid */
    MARS_L2_SCP_TX_POWER_ERROR = 20u,              /*!< [value 20] Mailbox Scratchpad command - tx_power cannot be set or invalid */
    MARS_L2_SCP_RX_MIXER_GAIN_ERROR = 21u,         /*!< [value 21] Mailbox Scratchpad command - rx_mixer_gain cannot be set or invalid */
    MARS_L2_SCP_RX_IFVGA_GAIN_ERROR = 22u,         /*!< [value 22] Mailbox Scratchpad command - rx_ifvga_gain cannot be set or invalid */
    MARS_L2_SCP_PROFILER_MODE_ERROR = 23u,         /*!< [value 23] Mailbox Scratchpad command - profiler_mode cannot be set or invalid */
    MARS_L2_SCP_MIMO_MODE_ERROR = 24u,             /*!< [value 24] Mailbox Scratchpad command - mimo_mode cannot be set or invalid */
    MARS_L2_SCP_MIPI_DATA_LANES_ERROR = 25u,       /*!< [value 25] Mailbox Scratchpad command - mipi_data_lanes cannot be set or invalid */
    MARS_L2_SCP_MIPI_DATA_RATE_ERROR = 26u,        /*!< [value 26] Mailbox Scratchpad command - mipi_data_rate cannot be set or invalid */
    MARS_L2_SCP_REPEATABLE_CHIRPS_NUM_ERROR = 27u, /*!< [value 27] Mailbox Scratchpad command - repeatable_chirps_num cannot be set or invalid */
    MARS_L2_SCP_CHIRPS_PER_FRAME_ERROR = 28u,      /*!< [value 28] Mailbox Scratchpad command - chirps_per_frame cannot be set or invalid */
    MARS_L2_SCP_VERSION_ERROR = 29u,               /*!< [value 29] Mailbox Scratchpad command - Radar API- MAF config data version mismatch */
    MARS_L2_SCP_T0_END_POINTER_ERROR = 30u,        /*!< [value 30] Mailbox Scratchpad command - t0_end_pointer cannot be set or invalid */
    MARS_L2_SCP_T0_START_POINTER_ERROR = 31u,      /*!< [value 31] Mailbox Scratchpad command - t0_start_pointer cannot be set or invalid */
    MARS_L2_SCP_T1_START_POINTER_ERROR = 32u,      /*!< [value 32] Mailbox Scratchpad command - t1_start_pointer cannot be set or invalid */
    MARS_L2_SCP_UNUSED_1_0_ERROR = 33u,            /*!< [value 33] Mailbox Scratchpad command - This MAF error indication is reserved for later use  */
    MARS_L2_SCP_UNUSED_1_1_ERROR = 34u,            /*!< [value 34] Mailbox Scratchpad command - This MAF error indication is reserved for later use  */
    MARS_L2_SCP_UNUSED_1_2_ERROR = 35u,            /*!< [value 35] Mailbox Scratchpad command - This MAF error indication is reserved for later use  */
    MARS_L2_SCP_UNUSED_1_3_ERROR = 36u,            /*!< [value 36] Mailbox Scratchpad command - This MAF error indication is reserved for later use  */
    MARS_L2_SCP_UNUSED_1_4_ERROR = 37u,            /*!< [value 37] Mailbox Scratchpad command - This MAF error indication is reserved for later use  */
    MARS_L2_SCP_MIPI_DIAG_0_ERROR = 38u,           /*!< [value 38] Mailbox Scratchpad command - Invalid address set for diag index 0 */
    MARS_L2_SCP_MIPI_DIAG_1_ERROR = 39u,           /*!< [value 39] Mailbox Scratchpad command - Invalid address set for diag index 1 */
    MARS_L2_SCP_MIPI_DIAG_2_ERROR = 40u,           /*!< [value 40] Mailbox Scratchpad command - Invalid address set for diag index 2 */
    MARS_L2_SCP_MIPI_DIAG_3_ERROR = 41u,           /*!< [value 41] Mailbox Scratchpad command - Invalid address set for diag index 3 */
    MARS_L2_SCP_MIPI_DIAG_4_ERROR = 42u,           /*!< [value 42] Mailbox Scratchpad command - Invalid address set for diag index 4 */
    MARS_L2_SCP_MIPI_DIAG_5_ERROR = 43u,           /*!< [value 43] Mailbox Scratchpad command - Invalid address set for diag index 5 */
    MARS_L2_SCP_MIPI_DIAG_6_ERROR = 44u,           /*!< [value 44] Mailbox Scratchpad command - Invalid address set for diag index 6 */
    MARS_L2_SCP_MIPI_DIAG_7_ERROR = 45u,           /*!< [value 45] Mailbox Scratchpad command - Invalid address set for diag index 7 */
    MARS_L2_SCP_MIPI_DIAG_8_ERROR = 46u,           /*!< [value 46] Mailbox Scratchpad command - Invalid address set for diag index 8 */
    MARS_L2_SCP_MIPI_DIAG_9_ERROR = 47u,           /*!< [value 47] Mailbox Scratchpad command - Invalid address set for diag index 9 */
    MARS_L2_SCP_MIPI_DIAG_10_ERROR = 48u,          /*!< [value 48] Mailbox Scratchpad command - Invalid address set for diag index 10 */
    MARS_L2_SCP_MIPI_DIAG_11_ERROR = 49u,          /*!< [value 49] Mailbox Scratchpad command - Invalid address set for diag index 11 */
    MARS_L2_SCP_MIPI_DIAG_12_ERROR = 50u,          /*!< [value 50] Mailbox Scratchpad command - Invalid address set for diag index 12 */
    MARS_L2_SCP_MIPI_DIAG_13_ERROR = 51u,          /*!< [value 51] Mailbox Scratchpad command - Invalid address set for diag index 13 */
    MARS_L2_SCP_MIPI_DIAG_14_ERROR = 52u,          /*!< [value 52] Mailbox Scratchpad command - Invalid address set for diag index 14 */
    MARS_L2_SCP_MIPI_DIAG_15_ERROR = 53u,          /*!< [value 53] Mailbox Scratchpad command - Invalid address set for diag index 15 */
    MARS_L2_SCP_PARITY_ERROR = 54u,                /*!< [value 54] Mailbox Scratchpad command - Parity Error */
    MARS_L2_SCP_LAST_ERROR_POS = 55u               /*!< [value 55] Mailbox Scratchpad command - Placeholder for the last error position */
} mars_scp_error_en;

/** @typedef mars_pcw_error_en
 *  @brief Enumeration for Mars Pure CW errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_PCW_NO_ERROR = 0u,                /*!< [value 0] Pure CW - No Error */
    MARS_L2_PCW_CONDITION_NOT_MET_ERROR = 1u, /*!< [value 1] Pure CW - Condition (TX ongoing) not met Error */
    MARS_L2_PCW_PARAMETER_ERROR = 2u,         /*!< [value 2] Pure CW - Parameter Error */
    MARS_L2_PCW_UNKNOWN_ERROR = 3u            /*!< [value 3] Pure CW - Unknown Error */
} mars_pcw_error_en;

/** @typedef mars_sts_error_en
 *  @brief Enumeration for Mars Mailbox Status errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_STS_NO_ERROR = 0u,            /*!< [value 0] Mars Mailbox Status - No Error */
    MARS_L2_STS_RDR_SFT_ERROR = 1u,       /*!< [value 1] Mars Mailbox Status - Radar Safety Error */
    MARS_L2_STS_RDR_DET_SFT_ERROR = 2u,   /*!< [value 2] Mars Mailbox Status - Radar Detected Safety Error */
    MARS_L2_STS_UNKNOWN_ERROR = 3u        /*!< [value 3] Mars Mailbox Status - Unknown Error */
} mars_sts_error_en;

/** @typedef mars_api_check_error_en
 *  @brief Enumeration for Mars API Check errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_API_CHECK_NO_ERROR = 0u,                    /*!< [value 0] API Check - No Error */
    MARS_L2_API_CHECK_PARAM_INDEX_1 = 1u,               /*!< [value 1] API Check - Parameter index 1 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_2 = 2u,               /*!< [value 2] API Check - Parameter index 2 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_3 = 3u,               /*!< [value 3] API Check - Parameter index 3 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_4 = 4u,               /*!< [value 4] API Check - Parameter index 4 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_5 = 5u,               /*!< [value 5] API Check - Parameter index 5 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_6 = 6u,               /*!< [value 6] API Check - Parameter index 6 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_7 = 7u,               /*!< [value 7] API Check - Parameter index 7 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_8 = 8u,               /*!< [value 8] API Check - Parameter index 8 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_9 = 9u,               /*!< [value 9] API Check - Parameter index 9 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_10 = 10u,             /*!< [value 10] API Check - Parameter index 10 check failed */
    MARS_L2_API_CHECK_PARAM_INDEX_11 = 11u,             /*!< [value 11] API Check - Parameter index 11 check failed */
    MARS_L2_API_CHECK_INVALID_INSTANCE_ERROR = 12u,     /*!< [value 12] API Check - Mars Instance is not defined (NULL) */
    MARS_L2_API_CHECK_DRIVER_STATUS_ERROR = 13u,        /*!< [value 13] API Check - Mars is not in the correct State to allow the API call */
    MARS_L2_API_CHECK_OPERATION_MODE_ERROR = 14u,       /*!< [value 14] API Check - Mars is not in the correct Operation Mode (Normal/Debug) to allow the API call */
    MARS_L2_API_CHECK_MAF_MIN_VER_NOT_COMPATIBLE_ERROR = 15u, /*!< [value 15] API Check - Mars minimum version is incompatible to allow the API call */
    MARS_L2_API_CHECK_MAF_MAX_VER_NOT_COMPATIBLE_ERROR = 16u, /*!< [value 16] API Check - Mars maximum version is incompatible to allow the API call */
    MARS_L2_API_CHECK_MAF_STATE_BUSY_ERROR = 17u        /*!< [value 17] API Check - Mars is busy and cannot process the API call */
} mars_api_check_error_en;

/* polyspace-begin MISRA-C-2023:2.5 [No action planned:Low] "Macro not used in the core API, but in the host application" */
#define MARS_L2_SCP_CAL_STATE_TX_CH_MISALIGNED      1u<<4  /*!< Tx channels misalignment */
#define MARS_L2_SCP_CAL_STATE_TX_PARAM_MISALIGNED   1u<<3  /*!< Tx parameters misalignment */
#define MARS_L2_SCP_CAL_STATE_RX_CH_MISALIGNED      1u<<2  /*!< Rx channels misalignment */
#define MARS_L2_SCP_CAL_STATE_RX_PARAM_MISALIGNED   1u<<1  /*!< Rx parameters misalignment */
#define MARS_L2_SCP_CAL_STATE_BIAS_MISALIGNED       1u<<0  /*!< Bias parameters misalignment */
/* polyspace-end MISRA-C-2023:2.5 [No action planned:Low] "Macro not used in the core API, but in the host application" */

/** @typedef mars_update_diag_error_en
 *  @brief Enumeration for Mars Update Diagnostic Values errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_UPDATE_DIAG_NO_ERROR = 0u,      /*!< [value 0] Update Diagnostic Values - No Error */
    MARS_L2_UPDATE_DIAG_FAILED = 1u,        /*!< [value 1] Update Diagnostic Values - Update Request Failed */
    MARS_L2_UPDATE_DIAG_PROHIBITED = 2u     /*!< [value 2] Update Diagnostic Values - Frame is already running, update request prohibited */
} mars_update_diag_error_en;

/** @typedef mars_trigger_frame_error_en
 *  @brief Enumeration for Mars Trigger Frame errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_FRAME_NO_ERROR = 0u,    /*!< [value 0] Trigger Frame - No Error */
    MARS_L2_FRAME_MARS_BUSY = 1u,   /*!< [value 1] Trigger Frame - MARS is not ready (busy) */
    MARS_L2_FRAME_BLOCKED_BY_SFT = 2u     /*!< [value 1] Trigger Frame - Blocked because SFT pin is asserted */
} mars_trigger_frame_error_en;

/** @typedef mars_read_bist_error_en
 *  @brief Enumeration for Mars Read BIST errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_READ_BIST_NO_ERROR = 0u,                 /*!< [value 0] Read Bist - No Error */
    MARS_L2_READ_BIST_INVALID_SFT = 1u,              /*!< [value 1] Read Bist - SFT value is invalid (contains 0b00 or 0b11) */
    MARS_L2_READ_BIST_INTEGRITY_CHECK_FAILED = 2u    /*!< [value 2] Read Bist - MAF error status diagnostic value integrity check failed */
} mars_read_bist_error_en;

/** @typedef mars_read_diag_raw_error_en
 *  @brief Enumeration for Mars Read Diagnostic Raw errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_READ_DIAG_RAW_NO_ERROR = 0u,      /*!< [value 0] Read Diagnostic Raw - No Error */
    MARS_L2_READ_DIAG_RAW_SIZE_ERROR = 1u,    /*!< [value 1] Read Diagnostic Raw - Parameter size requested (start index and number) exceeds the maximum size */
} mars_read_diag_raw_error_en;

/** @typedef mars_clear_sft_error_en
 *  @brief Enumeration for Mars Clear Recoverable Safety Errors errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_CLEAR_SFT_ERR_NO_ERROR = 0u,  /*!< [value 0] Clear Safety Errors - No Error */
    MARS_L2_CLEAR_SFT_ERR_FAILED = 1u,    /*!< [value 1] Clear Safety Errors - Mailbox request failed */
} mars_clear_sft_error_en;

/** @typedef mars_test_sft_pin_error_en
 *  @brief Enumeration for Mars test SFT pin errors.
 *  @design GID-502375
 */
typedef enum
{
    MARS_L2_TEST_SFT_PIN_ERR_NO_ERROR = 0u,  /*!< [value 0] Test SFT Pin - No Error */
    MARS_L2_TEST_SFT_PIN_CANNOT_ASSERT = 1u, /*!< [value 1] Test SFT Pin - Cannot assert */
    MARS_L2_TEST_SFT_PIN_CANNOT_DEASSERT = 2u, /*!< [value 2] Test SFT Pin - Cannot deassert */
    MARS_L2_TEST_SFT_PIN_TEST_CMD_FAILED = 3u, /*!< [value 3] Test SFT Pin - Mailbox request failed */
    MARS_L2_TEST_SFT_PIN_IS_ACTIVE = 4u    /*!< [value 4] Test SFT Pin - SFT pin is still active  */
} mars_test_sft_pin_error_en;

/** @typedef mars_wait_frame_error_en
 *  @brief Enumeration for Mars Wait for Frame errors.
 *  @design GID-351007
 */
typedef enum
{
    MARS_L2_FRM_WAIT_NO_ERROR = 0u,    /*!< [value 0] Wait for Frame ready - No Error */
    MARS_L2_FRM_WAIT_TIMEOUT = 1u /*!< [value 1] MARS is not reporting ready within timeout */
} mars_wait_frame_error_en;

/** @typedef mars_rd_back_error_en
 *  @brief Enumeration for Mars Mailbox Read-Back errors.
 *  @design GID-448270
 */
typedef enum
{
    MARS_L2_RD_BACK_NO_ERROR = 0u,          /*!< [value 0] Read-Back - No Error */
    MARS_L2_RD_BACK_PARAMETER_ERROR = 1u,   /*!< [value 1] Read-Back - Parameter Error reported by MAF */
    MARS_L2_RD_BACK_CRC_ERROR = 2u,         /*!< [value 2] Read-Back - CRC mismatch on read-back data */
    MARS_L2_RD_BACK_LENGTH_ERROR = 3u,      /*!< [value 3] Read-Back - Returned data size if longer than the allocated space */
    MARS_L2_RD_BACK_UNKNOWN_ERROR = 4u      /*!< [value 4] Read-Back - Unknown Error */
} mars_rd_back_error_en;

#define MARS_E_NOT_OK   1

#endif /* MARS_L2_ERROR_H */
