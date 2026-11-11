/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_ERROR_H
#define MARS_ERROR_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_public_types.h"
/**********************************************************************************************************************
 * MARS ERROR LAYOUT
 *********************************************************************************************************************/
#define MARS_FLAGS_BIT_OFFSET       22u
#define MARS_FLAGS_BIT_MASK         0x03uL

#define MARS_ERROR_L2_BIT_OFFSET    16u
#define MARS_ERROR_L2_BIT_MASK      0x3FuL

#define MARS_ERROR_L1_BIT_OFFSET    12u
#define MARS_ERROR_L1_BIT_MASK      0x0FuL

#define MARS_ERROR_L0_BIT_OFFSET    8u
#define MARS_ERROR_L0_BIT_MASK      0x0FuL /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "Macro used in the error handling implementation as per concept separation on layers" */

#define MARS_ERROR_ID_BIT_OFFSET    0u
#define MARS_ERROR_ID_BIT_MASK      0xFFuL

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**
 * @brief Hook function for handling MARS errors.
 *
 * This function is called when an error occurs in the MARS system. It allows
 * for custom handling of errors based on the return value and instance ID.
 *
 * @param ret_val The return value indicating the error type.
 * @param instance_id The ID of the instance where the error occurred.
 */
// extern void mars_error_hook(const uint32 ret_val, const uint32 instance_id);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/**********************************************************************************************************************
 * MARS ERROR LAYOUT
 *********************************************************************************************************************/
/** @def MARS_API_ID_BIT_OFFSET
 *  @brief Bit offset for API ID in error codes.
 */
#define MARS_API_ID_BIT_OFFSET      24u
#define MARS_API_ID_BIT_MASK        0xFFu /* polyspace MISRA-C-2023:2.5 [No action planned:Low] "Macro not used in the core API, but in the host application" */

/** @def MARS_API_ID_BIT_MASK
 *  @brief Bit mask for API ID in error codes.
 */

/**********************************************************************************************************************
 * MARS API IDs
 *********************************************************************************************************************/
/** @def MARS_API_ID_READ_REGISTER
 *  @brief API ID for reading a register.
 */
#define MARS_API_ID_READ_REGISTER               (1UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_WRITE_REGISTER
 *  @brief API ID for writing to a register.
 */
#define MARS_API_ID_WRITE_REGISTER              (2UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_INIT
 *  @brief API ID for initialization.
 */
#define MARS_API_ID_INIT                        (3UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_INIT_DEBUG
 *  @brief API ID for debug initialization.
 */
#define MARS_API_ID_INIT_DEBUG                  (4UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_QSPI_CONFIG
 *  @brief API ID for QSPI configuration.
 */
#define MARS_API_ID_QSPI_CONFIG                 (5UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_ACTIVATE_FIRMWARE
 *  @brief API ID for activating firmware.
 */
#define MARS_API_ID_ACTIVATE_FIRMWARE           (6UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_UPLOAD_FIRMWARE
 *  @brief API ID for uploading firmware.
 */
#define MARS_API_ID_UPLOAD_FIRMWARE             (7UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_TRIGGER_FRAME
 *  @brief API ID for triggering a frame.
 */
#define MARS_API_ID_TRIGGER_FRAME               (8UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_RESET
 *  @brief API ID for resetting the system.
 */
#define MARS_API_ID_RESET                       (9UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_PROFILER_TABLE_0_READ_RAW
 *  @brief API ID for reading raw data from profiler table 0.
 */
#define MARS_API_ID_PROFILER_TABLE_0_READ_RAW   (10UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_PROFILER_TABLE_0_WRITE_RAW
 *  @brief API ID for writing raw data to profiler table 0.
 */
#define MARS_API_ID_PROFILER_TABLE_0_WRITE_RAW  (11UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_PROFILER_TABLE_1_READ_RAW
 *  @brief API ID for reading raw data from profiler table 1.
 */
#define MARS_API_ID_PROFILER_TABLE_1_READ_RAW   (12UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_PROFILER_TABLE_1_WRITE_RAW
 *  @brief API ID for writing raw data to profiler table 1.
 */
#define MARS_API_ID_PROFILER_TABLE_1_WRITE_RAW  (13UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_READ_BIST_RESULT
 *  @brief API ID for reading BIST results.
 */
#define MARS_API_ID_READ_BIST_RESULT            (14UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CONFIGURE_BIST
 *  @brief API ID for configuring BIST.
 */
#define MARS_API_ID_CONFIGURE_BIST              (15UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_START_CW
 *  @brief API ID for starting continuous wave mode.
 */
#define MARS_API_ID_START_CW                    (16UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_STOP_CW
 *  @brief API ID for stopping continuous wave mode.
 */
#define MARS_API_ID_STOP_CW                     (17UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CONFIGURE
 *  @brief API ID for configuring the system.
 */
#define MARS_API_ID_CONFIGURE                   (18UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_READ_STATUS
 *  @brief API ID for reading system status.
 */
#define MARS_API_ID_READ_STATUS                 (19UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_READ_DRIVER_STATUS
 *  @brief API ID for reading driver status.
 */
#define MARS_API_ID_READ_DRIVER_STATUS          (20UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_ENABLE_TESTPATTERN
 *  @brief API ID for enabling test pattern.
 */
#define MARS_API_ID_ENABLE_TESTPATTERN          (21UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_DISABLE_TESTPATTERN
 *  @brief API ID for disabling test pattern.
 */
#define MARS_API_ID_DISABLE_TESTPATTERN         (22UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_PHASE_LUT_WRITE_RAW
 *  @brief API ID for writing raw data to phase LUT.
 */
#define MARS_API_ID_PHASE_LUT_WRITE_RAW         (23UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_PHASE_LUT_READ_RAW
 *  @brief API ID for reading raw data from phase LUT.
 */
#define MARS_API_ID_PHASE_LUT_READ_RAW          (24UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_GET_API_VERSION
 *  @brief API ID for getting API version.
 */
#define MARS_API_ID_GET_API_VERSION             (25UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CAL_CTRL_WRITE
 *  @brief API ID for writing calibration control.
 */
#define MARS_API_ID_CAL_CTRL_WRITE              (26UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_UPDATE_DIAG_VALUES
 *  @brief API ID for updating diagnostic values.
 */
#define MARS_API_ID_UPDATE_DIAG_VALUES          (27UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_READ_UID
 *  @brief API ID Read Unique ID
 */
#define MARS_API_ID_READ_UID                    (28UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_READ_DIAG_RAW
 *  @brief API ID for reading diagnostic raw values.
 */
#define MARS_API_ID_READ_DIAG_RAW               (29UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CLR_RECOV_SFT_ERRORS
 *  @brief API ID for clearing all recoverable safety errors.
 */
#define MARS_API_ID_CLR_RECOV_SFT_ERRORS        (30UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_ZHV_READ
 *  @brief API ID for ZHV Read errors
 */
#define MARS_API_ID_ZHV_READ                    (31UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_ZHV_WRITE
 *  @brief API ID for ZHV Write errors
 */
#define MARS_API_ID_ZHV_WRITE                   (32UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_READ_MEMORY
 *  @brief API ID Reading Mars Memory
 */
#define MARS_API_ID_READ_MEMORY                 (33UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_WRITE_MEMORY
 *  @brief API ID Writing Mars Memory
 */
#define MARS_API_ID_WRITE_MEMORY                (34UL  << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CHECK_SFT_PIN
 *  @brief API ID for checking safety pin status.
 */
#define MARS_API_ID_CHECK_SFT_PIN               (35UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_ZHV_GENERATE
 *  @brief API ID for Generate ZHV data
 */
#define MARS_API_ID_ZHV_GENERATE                (36UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CONFIGURE_BIST_READ
 *  @brief API ID for reading back BIST configuration from MAF
 */
#define MARS_API_ID_CONFIGURE_BIST_READ         (37UL << MARS_API_ID_BIT_OFFSET)

/** @def MARS_API_ID_CAL_CTRL_READ
 *  @brief API ID for reading back calibration control from MAF
 */
#define MARS_API_ID_CAL_CTRL_READ               (38UL << MARS_API_ID_BIT_OFFSET)


/** @def MARS_API_ID_CONFIGURE_READ
 *  @brief API ID for reading back configuration from MAF
 */
#define MARS_API_ID_CONFIGURE_READ              (39UL << MARS_API_ID_BIT_OFFSET)
#endif /* MARS_ERROR_H */
