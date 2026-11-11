#include "mars_api_fake.h"

DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_phase_lut_write_raw, mars_instance_t *, const mars_phase_lut_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_phase_lut_read_raw, mars_instance_t *, mars_phase_lut_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_init_debug, mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_init, mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_register, mars_instance_t *, mars_reg_id_t, mars_reg_value_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_reg_safe,const mars_instance_t *, uint32 , uint32 * );
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_write_register, mars_instance_t *, mars_reg_id_t, mars_reg_value_t);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_memory, mars_instance_t *, mars_address_t, mars_value_t *, mars_size_t);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_write_memory, mars_instance_t *, mars_address_t, const mars_value_t *, mars_size_t);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_status,mars_instance_t *, mars_rdrstatus_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_qspi_config,mars_instance_t *, const mars_ssi_config_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_upload_firmware,mars_instance_t *, const mars_firmware_data_t *, uint32 , mars_firmware_size_t );
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_activate_firmware,mars_instance_t *, mars_activation_t );
//DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_temperature,mars_instance_t *, mars_temp_id_t , mars_temperatures_t *);
//DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_id,const mars_instance_t *, mars_device_id_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_uid, mars_instance_t *, mars_uid_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_get_api_version,const mars_instance_t *, mars_api_sw_version_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_driver_status, mars_instance_t *, mars_driver_status_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_start_cw,mars_instance_t * , mars_tx_channel_t , mars_raw_phase_t , mars_fs_frequency_t );
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_stop_cw,mars_instance_t *, mars_tx_channel_t );
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_disable_testpattern, mars_instance_t *, mars_tp_adc_channel_t);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_enable_testpattern, mars_instance_t *, mars_tp_adc_channel_t, const mars_tp_config_t *, mars_tp_clr_mode_t);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_bist_result, mars_instance_t *, mars_bist_result_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_gpio_sft_read,const mars_instance_t * , mars_gpio_level_en *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_configure_bist,mars_instance_t * , const uint32 *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_cal_ctrl_write, mars_instance_t *, const mars_cal_control_t *);
//DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_analog_diag,mars_instance_t * , const uint32 *  , mars_adcs_t * );
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_profiler_table_0_write_raw, mars_instance_t *, uint16, uint16, const mars_pt0_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_profiler_table_0_read_raw, mars_instance_t *, uint16, uint16, mars_pt0_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_profiler_table_1_read_raw, mars_instance_t *, uint16, uint16, mars_pt1_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_profiler_table_1_write_raw, mars_instance_t *, uint16, uint16, const mars_pt1_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_configure,mars_instance_t * , const mars_tx_config_t * , const mars_rx_config_t * , const mars_rfdist_mode_t * ,
                               const mars_bias_noise_filter_t * , const mars_mipi_config_t * , const mars_chirp_config_t * ,
                               const mars_chirp_mode_t * , const mars_gp_config_t * , const mars_frame_counter_t * ,
                               const mars_mipi_diag_t * ,const mars_fusa_fs_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_trigger_frame,mars_instance_t * , mars_frame_timestamp_t  , mars_mipi_metadata_reg_t  );                              
DEFINE_FAKE_VOID_FUNC(mars_action_IRQE_SFT_ERR_N,mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType,mars_reset,mars_instance_t * , mars_reset_t );
DEFINE_FAKE_VALUE_FUNC(mars_sft_err_n_t,mars_action_sft_is_active,const mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_mem_safe, mars_instance_t *, uint32, uint32 *, uint32);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_write_mem_safe, mars_instance_t *, const uint32 *, uint32, uint32);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_update_diagnostic_values, mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_read_diag_raw, mars_instance_t *, uint32, uint32, mars_diag_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_check_sft_pin, mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_clear_recoverable_sft_errors, mars_instance_t *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_zhv_read, mars_instance_t *, uint32 *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_zhv_write, mars_instance_t *, const uint32 *);
DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, mars_zhv_generate, mars_instance_t *, uint32 *, uint32);

//DEFINE_FAKE_VOID_FUNC(ensureInterruptsNotMasked);