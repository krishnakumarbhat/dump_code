/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_API_H
#define MARS_API_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "mars_regs_gen.h"
#include "mars_types.h"
/**********************************************************************************************************************
 * GLOBAL MACROS
 *********************************************************************************************************************/
#define MARS_API_VERSION_MAJOR 2u
#define MARS_API_VERSION_MINOR 4u
#define MARS_API_VERSION_PATCH 3u

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**
 * @brief         Initialize MARS API driver
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_init(mars_instance_t *const mars_self);

/**
 * @brief         Initialize MARS API driver and force the chip to debug mode.
 *                Debug mode is a special operation where the chip is omitting power-up HW tests.
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
#ifndef MARS_DEBUG_SUPPORT_DISABLED
Mars_ReturnType mars_init_debug(mars_instance_t *const mars_self);
#endif

/**
 * @brief         Read the results of the BIST
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   results results from BIST
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_read_bist_result( mars_instance_t *const mars_self, mars_bist_result_t *const results);

/**
 * @brief         Configures BIST performed during the next Frame Tx
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    test_id multi-select bitfield identifier(s) of the the test
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_configure_bist(mars_instance_t *const mars_self, const mars_bist_config_t test_id);

/**
 * @brief         Reads back the actual BIST configuration from MAF
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   test_id actual MAF configuration of the built in self tests
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_configure_bist_read( mars_instance_t *const mars_self, mars_bist_config_t test_id);

/**
 * @brief         Starts CW transmission. See also mars_convert_frequency_phys_to_raw and mars_convert_phase_phys_to_raw
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel TX channel ID is the channel index in the range of 0..3
 * @param [in]    raw_phase CW phase value in 9 bits resolution, that is the index to the phase LUT
 *                see mars_convert_phase_phys_to_raw to use physical values in degrees.
 * @param [in]    raw_frequency CW frequency raw value valid range [8039082..10223616]
 *                see mars_convert_frequency_phys_to_raw to use physical values in Hz.
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_start_cw(mars_instance_t *const mars_self, const mars_tx_channel_t channel, const mars_raw_phase_t raw_phase, const mars_fs_frequency_t raw_frequency);

/**
 * @brief         Writes Phase Look Up Table to Mars. The function writes the complete table (512 entries).
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    lut_values array of 14 bit LUT values (7 bit I x 7 bit Q)
 * @return        MARS_E_OK if successful MARS_API_ID_PHASE_LUT_WRITE_RAW errors if failed
 */
Mars_ReturnType mars_phase_lut_write_raw( mars_instance_t *const mars_self, const uint16 lut_values[4][PHASE_LUT_NO_OF_ENTRIES]);

/**
 * @brief         Read Phase Look Up Table from Mars. . The function reads the complete table (512 entries).
 *                The caller function shall ensure that sufficient memory is available for reading in 32bitsx512 = 2KBytes memory.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   lut_values array of 14 bit LUT values (7 bit I x 7 bit Q)
 * @return        MARS_E_OK if successful MARS_API_ID_PHASE_LUT_READ_RAW errors if failed
 */
Mars_ReturnType mars_phase_lut_read_raw( mars_instance_t *const mars_self, uint16 lut_values[4][PHASE_LUT_NO_OF_ENTRIES]);

/**
 * @brief         Stops CW transmission
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel TX channel ID is the channel index in the range of 0..3
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_stop_cw(mars_instance_t *const mars_self, const mars_tx_channel_t channel);

/**
 * @brief         Activates Mars firmware
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    activation_type type of activation
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_activate_firmware(mars_instance_t *const mars_self, const mars_activation_t activation_type);

/**
 * @brief         Loads firmware in Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    firmware_data binary data of the mars application firmware
 * @param [in]    offset start index of the mars application firmware in bytes (32-bit, byte offset from start of MAF)
 * @param [in]    length length of the binary data in bytes
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_upload_firmware(mars_instance_t *const mars_self, const mars_firmware_data_t *const firmware_data, const uint32 offset, const mars_firmware_size_t length);

/**
 * @brief         Initiates Frame transmission
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    timestamp millisecond time when Fram Tx is expected to be due
 * @param [in]    metadata_reg User defined 16bits value passed in the MIPI metadata of the frame
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_trigger_frame(mars_instance_t *const mars_self, const mars_frame_timestamp_t timestamp, const mars_mipi_metadata_reg_t metadata_reg);

/**
 * @brief         Reads device UUID information from the chip
 *                This information is available only after MAF has been successfully loaded and executed.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   id device ID information for detailed information check mars_uid_t
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_read_uid( mars_instance_t *const mars_self, mars_uid_t *const id);

/**
 * @brief         Reads device status information from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   status device status information
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_read_status(mars_instance_t *const mars_self, mars_rdrstatus_t *const status);

/**
 * @brief         Reads status information from the driver
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   status driver status information
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_read_driver_status( mars_instance_t *const mars_self, mars_driver_status_t *const status);

/**
 * @brief         Configures Mars chip stationary configuration
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    tx_config Configuration of TX parameters
 * @param [in]    rx_config configuration of RX parameters
 * @param [in]    rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [in]    bias_noise_filter configuration of Bias Noise Filter control
 * @param [in]    mipi_config configuration of MIPI
 * @param [in]    chrp_config configuration of chirp and frame parameters
 * @param [in]    chrp_mode chirp mode configuration
 * @param [in]    gp_config configuration of GP0 & GP1 pins
 * @param [in]    frame_counter initial frame counter value, incremented by Mars automatically
 * @param [in]    mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [in]    maf_fusa_fs Fstart used in MAF FUSA functions
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_configure(mars_instance_t *const mars_self, const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, const mars_rfdist_mode_t *const rfdist_mode,
                               const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config, const mars_chirp_config_t *const chrp_config,
                               const mars_chirp_mode_t *const chrp_mode, const mars_gp_config_t *const gp_config, const mars_frame_counter_t *const frame_counter,
                               const mars_mipi_diag_t *const mipi_diag, const mars_fusa_fs_t *const maf_fusa_fs);

/**
 * @brief         Reads back Mars chip stationary configuration
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   tx_config Configuration of TX parameters
 * @param [out]   rx_config configuration of RX parameters
 * @param [out]   rfdist_mode configuration of RF distribution mode (Single, Master, Slave)
 * @param [out]    bias_noise_filter configuration of Bias Noise Filter control*
 * @param [out]   mipi_config configuration of MIPI
 * @param [out]   chrp_config configuration of chirp and frame parameters
 * @param [out]   chrp_mode chirp mode configuration
 * @param [out]   gp_config configuration of GP0 & GP1 pins
 * @param [out]   frame_counter initial frame counter value, incremented by Mars automatically
 * @param [out]   mipi_diag array of up to 16 Mars register addresses, their content will be returned in MIPI metadata
 * @param [out]   maf_fusa_fs Fstart used in MAF FUSA functions
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_configure_read( mars_instance_t *const mars_self, mars_tx_config_t *const tx_config, mars_rx_config_t *const rx_config, mars_rfdist_mode_t *const rfdist_mode,
                               mars_bias_noise_filter_t *const bias_noise_filter, mars_mipi_config_t *const mipi_config, mars_chirp_config_t *const chrp_config,
                               mars_chirp_mode_t *const chrp_mode, mars_gp_config_t *const gp_config, mars_frame_counter_t *const frame_counter,
                               mars_mipi_diag_t *const mipi_diag, mars_fusa_fs_t *const maf_fusa_fs);

/**
 * @brief         Resets the Mars chip or recovers the API driver state.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    reset     type of reset; one of MARS_RESET_HARD, MARS_RESET_SOFT,
 *                          MARS_RESET_FORCE_LOW, or MARS_RESET_STATUS (see mars_reset_t)
 * @return        MARS_E_OK if successful, E_NOT_OK if failed.
 *                Returns error 0x0908000c (MARS_API_ID_RESET | MARS_ERROR_L2_API_CHECK |
 *                MARS_L2_API_CHECK_DRIVER_STATUS_ERROR) if the driver has not been initialized.
 */
Mars_ReturnType mars_reset(mars_instance_t *const mars_self, const mars_reset_t reset);

/**
 * @brief         Reads Profiler Table 0 from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table read in bytes [0..33776]
 * @param [in]    size number of the table entries to be read. One increment is 16 bytes
 * @param [out]   table table data that is read back from the device
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_profiler_table_0_read_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, mars_pt0_t *const table);

/**
 * @brief         Writes Profiler Table 0 in the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table write in bytes [0..33776]
 * @param [in]    size number of the table entries to be written. One increment is 16 bytes
 * @param [in]    table table data that is written to the device
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_profiler_table_0_write_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, const mars_pt0_t *const table);

/**
 * @brief         Reads Profiler Table 1 from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table read in bytes [0..33784]
 * @param [in]    size number of the table entries to be read. One increment is 8 bytes
 * @param [out]   table table data that is read back from the device
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_profiler_table_1_read_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, mars_pt1_t *const table);

/**
 * @brief         Writes Profiler Table 1 in the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    offset start index of the table write in bytes [0..33784]
 * @param [in]    size number of the table entries to be written. One increment is 8 bytes
 * @param [in]    table table data that is written to the device
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_profiler_table_1_write_raw( mars_instance_t *const mars_self, const uint16 offset, const uint16 size, const mars_pt1_t *const table);

/**
 * @brief         Reads complete register or bitfield from the Mars chip memory map
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    reg_id register and bit field ID
 * @param [out]   value register or bitfield value
 * @return        MARS_E_OK if successful E_NOT_OK if failed E_TIMEOUT in case of timeout
 */
Mars_ReturnType mars_read_register( mars_instance_t *const mars_self, const mars_reg_id_t reg_id, mars_reg_value_t *const value);

/**
 * @brief         Writes complete register or bitfield in the Mars chip memory map
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    reg_id register and bit field ID
 * @param [in]    value register or bitfield value
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_write_register( mars_instance_t *const mars_self, const mars_reg_id_t reg_id, const mars_reg_value_t value);


/**
 * @brief         Reads the content of a Mars memory location
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    address Memory address in Mars
 * @param [out]   value resulting data read from Mars memory
 * @param [in]    size number of 32-bit words to be read
 * @return        MARS_E_OK if successful MARS_E_OK MARS_API_ID_READ_MEMORY errors if failed
 */
Mars_ReturnType mars_read_memory( mars_instance_t *const mars_self, mars_address_t const address, mars_value_t *const value, const mars_size_t size);

/**
 * @brief         Writes data directly into Mars memory
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    address Memory address in Mars
 * @param [in]    value data to be written to Mars memory
 * @param [in]    size number of 32-bit words to be written
 * @return        MARS_E_OK if successful MARS_API_ID_WRITE_MEMORY errors if failed
 */
Mars_ReturnType mars_write_memory( mars_instance_t *const mars_self, mars_address_t const address, const mars_value_t * const  value, const mars_size_t size);

/**
 * @brief         Enables Test Pattern generation in the device
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel ADC channel
 * @param [in]    tp_config Test Pattern config
 * @param [in]    clr_mode Test Pattern Clear Mode
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_enable_testpattern( mars_instance_t *const mars_self, const mars_tp_adc_channel_t channel, const mars_tp_config_t *const tp_config, const mars_tp_clr_mode_t clr_mode);

/**
 * @brief         Disables Test Pattern generation in the device
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    channel ADC channel
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_disable_testpattern( mars_instance_t *const mars_self, const mars_tp_adc_channel_t channel);

/**
 * @brief         Switches between SPI and QSPI mode
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    config QSPI configuration
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_qspi_config(mars_instance_t *const mars_self, const mars_ssi_config_t *const config);

/**
 * @brief         Provides the version of the host API driver
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   version version information
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_get_api_version(const mars_instance_t *const mars_self, mars_api_sw_version_t *const version);

/**
 * @brief         Write the calibration control settings to Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    control bit field that contains the the enable/disable information of Mars calibration features
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_cal_ctrl_write( mars_instance_t *const mars_self, const mars_cal_control_t *const control);

/**
 * @brief         Reads back the calibration control information from Mars
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   control array of 32 bit values used as bit fields to enable/disable individual calibration features
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_cal_ctrl_read( mars_instance_t *const mars_self, mars_cal_control_t *const control);

/**
 * @brief         Requests Mars to update all diagnostic values. This includes both the temperature-type signed values and the voltage-type unsigned diagnostic ADC values.
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful E_NOT_OK if failed
 */
Mars_ReturnType mars_update_diagnostic_values( mars_instance_t *const mars_self);

/**
 * @brief         Reads one or more diag entries of the Mars chip, and returns the value after integrity check.
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    start_idx index number of the first diag entry to be read
 * @param [in]    num_values number of diag entries to be read
 * @param [out]   diag_values array of mars_diag_t values, size of the array is greater or equal to num_values
 * @return        MARS_E_OK if successful, MARS_API_ID_READ_DIAG_RAW errors if failure
 */
Mars_ReturnType mars_read_diag_raw(mars_instance_t *const mars_self, const uint32 start_idx, const uint32 num_values, mars_diag_t *const diag_values);

/**
 * @brief         Clear all recoverable safety errors.
 * @param [in]    mars_self pointer to driver instance structure
 * @return        MARS_E_OK if successful, MARS_API_ID_CLR_RECOV_SFT_ERRORS errors if failure
 */
Mars_ReturnType mars_clear_recoverable_sft_errors( mars_instance_t *const mars_self);

/**
 * @brief         Reads Zero Hour Values from the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   zhv Zero Hour Value data that is read back from the device
 * @return        MARS_E_OK if successful MARS_API_ID_ZHV_READ errors if failed
 */
Mars_ReturnType mars_zhv_read( mars_instance_t *const mars_self, mars_zhv_t zhv);

/**
 * @brief         Writes Zero Hour Values to the chip
 * @param [in]    mars_self pointer to driver instance structure
 * @param [in]    zhv Zero Hour Value data that is to be written to the device
 * @return        MARS_E_OK if successful MARS_API_ID_ZHV_WRITE errors if failed
 */
Mars_ReturnType mars_zhv_write( mars_instance_t *const mars_self, const mars_zhv_t zhv);

/**
 * @brief         Performs check if the physical IO pin SFT_ERR_N is operational and its logical level can be detected by the API
 * @param [in]    mars_self pointer to driver instance structure
 * @return        Mars_ReturnType MARS_E_OK if success, MARS_API_ID_CHK_SFT_PIN set of errors if failing
  */
Mars_ReturnType mars_check_sft_pin( mars_instance_t *const mars_self);


/**
 * @brief         Generates ZHV data (triggers a ZHV generation frame and reads the result)
 * @param [in]    mars_self pointer to driver instance structure
 * @param [out]   zhv Zero Hour Value data that is read back from the device
 * @param [in]    frame_time maximum time to wait for that frame to complete, in milliseconds.
 *                If the frame does not finish within this budget, the call fails with a frame-wait timeout
 * @return        Mars_ReturnType MARS_E_OK if success, MARS_API_ID_ZHV_GENERATE set of errors if failing
 */
Mars_ReturnType mars_zhv_generate(mars_instance_t *const mars_self, mars_zhv_t zhv, const uint32 frame_time);

#endif /* MARS_API_H */
