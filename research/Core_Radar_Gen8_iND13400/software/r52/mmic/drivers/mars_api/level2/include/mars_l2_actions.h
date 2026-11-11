/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L2_ACTIONS_H
#define MARS_L2_ACTIONS_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mars_types.h"
#include "mars_scratchpad_config.h"

/**********************************************************************************************************************
 * GLOBAL VARIABLE DECLARATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void mars_action_init(mars_instance_t *const mars_self);

extern mars_sft_err_n_t mars_action_sft_is_active(mars_instance_t *const mars_self);

extern void mars_action_ssi_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_ssi_resp, const uint16 mars_ssi_resp_var_h, const uint32 mars_ssi_resp_var_l);
extern Mars_ReturnType mars_action_ssi_set_mode( mars_instance_t *const mars_self, const mars_ssi_config_t ssi_mode);

extern Mars_ReturnType mars_action_scp_send_update_command(mars_instance_t *const mars_self, mars_scratchpad_cfg_t *const mars_scp_cfg_ref);

extern Mars_ReturnType mars_action_control_cw(mars_instance_t *const mars_self, const uint32 var_h, const uint32 var_l);

extern void mars_action_sts_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_sts_resp, const uint16 mars_sts_resp_var_h, const uint32 mars_sts_resp_var_l);

extern Mars_ReturnType mars_action_frame_start( mars_instance_t *const mars_self, const mars_frame_timestamp_t timestamp, const mars_mipi_metadata_reg_t metadata_reg);
extern Mars_ReturnType mars_action_mars_configure_param_check(const mars_instance_t *const mars_self, const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config,
                                                              const mars_rfdist_mode_t *const rfdist_mode, const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config,
                                                              const mars_chirp_config_t *const chrp_config, const mars_chirp_mode_t *const chrp_mode, const mars_gp_config_t *const gp_config,
                                                              const mars_mipi_diag_t *const mipi_diag);
extern Mars_ReturnType mars_action_config_read_param_check(const mars_instance_t *const mars_self,const mars_tx_config_t *const tx_config,const mars_rx_config_t *const rx_config,const mars_rfdist_mode_t *const rfdist_mode,
                               const mars_bias_noise_filter_t *const bias_noise_filter,const mars_mipi_config_t *const mipi_config,const mars_chirp_config_t *const chrp_config,
                               const mars_chirp_mode_t *const chrp_mode,const mars_gp_config_t *const gp_config,const mars_frame_counter_t *const frame_counter,
                               const mars_mipi_diag_t *const mipi_diag,const mars_fusa_fs_t *const maf_fusa_fs);
extern Mars_ReturnType mars_action_config_read_parse_scp_data(const mars_instance_t *const mars_self,const mars_scratchpad_cfg_t *const mars_scp_cfg, mars_tx_config_t *const tx_config, mars_rx_config_t *const rx_config, mars_rfdist_mode_t *const rfdist_mode,
                                mars_bias_noise_filter_t *const bias_noise_filter,mars_mipi_config_t *const mipi_config, mars_chirp_config_t *const chrp_config,
                               mars_chirp_mode_t *const chrp_mode, mars_mipi_diag_t *const mipi_diag, mars_fusa_fs_t *const maf_fusa_fs);
extern Mars_ReturnType mars_action_read_diag_raw_chunk( mars_instance_t *const mars_self,
                                                       const uint32 mem_start_addr,
                                                       const uint32 chunk_count,
                                                       mars_diag_health_state_t *const sample_states,
                                                       uint32 *const sample_raws,
                                                       uint8 *const sample_counters);
extern Mars_ReturnType mars_action_config_read_gp_registers( mars_instance_t *const mars_self, mars_gp_config_t *const gp_config);
extern Mars_ReturnType mars_action_scp_cal_set_mlbx_response(const mars_instance_t *const mars_self, const uint8 mars_scp_resp, const uint16 mars_scp_resp_var_h, const uint32 mars_scp_resp_var_l);
extern Mars_ReturnType mars_action_scp_configbist_set_mlbx_response(mars_instance_t *const mars_self, const uint8 mars_configbist_resp, const uint16 mars_configbist_resp_var_h,
    const uint32 mars_configbist_resp_var_l);
extern Mars_ReturnType mars_action_update_diag_set_mlbx_response(const mars_instance_t *const mars_self, const uint8 mars_scp_resp, const uint16 mars_scp_resp_var_h, const uint32 mars_scp_resp_var_l);
extern Mars_ReturnType mars_action_read_maf_version( mars_instance_t *const mars_self, uint32* const maf_version);
extern Mars_ReturnType mars_action_check_maf_state(mars_instance_t *const mars_self, const uint32 timeout);
extern Mars_ReturnType mars_action_phase_lut_write_raw( mars_instance_t *const mars_self, const uint16 lut_values[MARS_PHASE_LUT_NO_OF_ELEMENTS]);
extern Mars_ReturnType mars_action_phase_lut_read_raw( mars_instance_t *const mars_self, uint16 lut_values[MARS_PHASE_LUT_NO_OF_ELEMENTS]);
extern Mars_ReturnType mars_action_clear_sft_err_set_mlbx_response(const mars_instance_t *const mars_self, const uint8 mars_resp, const uint16 mars_resp_var_h, const uint32 mars_resp_var_l);
extern Mars_ReturnType mars_action_check_memory_range(const uint32 address, const uint32 size);
extern Mars_ReturnType mars_action_send_sft_pin_test_command( mars_instance_t *const mars_self, const mars_sft_set_en state);
extern Mars_ReturnType mars_action_check_sft_pin_status(mars_instance_t *const mars_self, const mars_sft_set_en state);
extern Mars_ReturnType mars_action_wait_frame_ready(mars_instance_t *const mars_self, const uint32 timeout);
extern Mars_ReturnType mars_action_check_sft_registers( mars_instance_t *const mars_self, mars_bist_result_t *const results);
extern Mars_ReturnType mars_action_read_hw_registers( mars_instance_t *const mars_self, mars_bist_result_t *const results);
extern Mars_ReturnType mars_action_read_diagnostic_memory( mars_instance_t *const mars_self, mars_bist_result_t *const results);
extern Mars_ReturnType mars_action_configure_gp_registers( mars_instance_t *const mars_self, const mars_gp_config_t *const gp_config);
extern Mars_ReturnType mars_action_maf_activate( mars_instance_t *const mars_self, const mars_activation_t activation_type);
extern Mars_ReturnType mars_action_maf_activation_check( mars_instance_t *const mars_self);
extern Mars_ReturnType mars_action_check_maf_version(mars_instance_t *const mars_self);
extern Mars_ReturnType mars_action_check_upload_firmware_params_check(const mars_instance_t *const mars_self, const uint32 offset, const mars_firmware_size_t length, const mars_firmware_data_t *const firmware_data, mars_api_check_error_en *const param_index);
extern Mars_ReturnType mars_action_zhv_generate_setup(mars_instance_t *const mars_self);
extern Mars_ReturnType mars_action_zhv_generate_cleanup(mars_instance_t *const mars_self);
#ifndef MARS_DEBUG_SUPPORT_DISABLED
extern Mars_ReturnType mars_action_init_debug_gpio_reset_write(mars_instance_t *const mars_self);
#endif
extern Mars_ReturnType mars_action_init_gpio_reset_write(mars_instance_t *const mars_self);
extern Mars_ReturnType mars_action_check_init_status(mars_instance_t *const mars_self);
extern void mars_action_configure_scp(mars_scratchpad_cfg_t *const mars_scp_cfg, const mars_tx_config_t *const tx_config, const mars_rx_config_t *const rx_config, const mars_rfdist_mode_t *const rfdist_mode,
                               const mars_bias_noise_filter_t *const bias_noise_filter, const mars_mipi_config_t *const mipi_config, const mars_chirp_config_t *const chrp_config,
                               const mars_chirp_mode_t *const chrp_mode, const mars_mipi_diag_t *const mipi_diag, const mars_fusa_fs_t *const maf_fusa_fs);
extern Mars_ReturnType mars_action_allow_api_call( mars_instance_t *const mars_self, const mars_driver_status_t drv_state, const uint32 op_mode, const uint32 min_fw_ver, const uint32 max_fw_ver);
extern Mars_ReturnType mars_action_scp_read_back( mars_instance_t *const mars_self, const uint32 subcmd, uint32 *const dst, const uint32 words);


#endif /* DOXYGEN_SHOULD_SKIP_THIS */
#endif /* MARS_L2_ACTIONS_H */
