function write_psp_data(rc_data, dynalign_data, staticalign_data, dracore_data, toi_data, af_data, psp_bin_file_path)

   if ~isempty(psp_bin_file_path)
      file_name = fullfile(psp_bin_file_path, "psp_input.bin");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   % Static align data
   %   float32_t yaw;
   %   float32_t pitch;
   %   float32_t plate_angle_deg_scs;
   %   float32_t plate_distance;
   %   float32_t polarity;
   %   float32_t horz_angle_min;
   %   float32_t horz_angle_max;
   %   float32_t vert_angle_min;
   %   float32_t vert_angle_max;
   %   float32_t plate_lat_position;
   %   uint8_t mount_loc;
   %   uint8_t align_cmd;
   %   uint8_t f_data_valid;
   %   uint8_t K_Unused8_1;

   fwrite(fileID, staticalign_data.yaw(4), "float32");
   fwrite(fileID, staticalign_data.pitch(4), "float32");
   fwrite(fileID, staticalign_data.plate_angle_deg_scs(4), "float32");
   fwrite(fileID, staticalign_data.plate_distance(4), "float32");
   fwrite(fileID, staticalign_data.polarity(4), "float32");
   fwrite(fileID, staticalign_data.horz_angle_min(4), "float32");
   fwrite(fileID, staticalign_data.horz_angle_max(4), "float32");
   fwrite(fileID, staticalign_data.vert_angle_min(4), "float32");
   fwrite(fileID, staticalign_data.vert_angle_max(4), "float32");
   fwrite(fileID, staticalign_data.plate_lat_position(4), "float32");
   fwrite(fileID, staticalign_data.mount_loc(4), "uint8");
   fwrite(fileID, staticalign_data.align_cmd(4), "uint8");
   fwrite(fileID, staticalign_data.f_data_valid(4), "uint8");

   % Dynamic align data
   % float32_t initial_vacs_boresight_az_estimated;
   % float32_t initial_vacs_boresight_el_estimated;
   % float32_t initial_vacs_boresight_rl_estimated;
   % float32_t initial_speed_compensation_factor;
   % float32_t max_abs_misalignment_az;
   % float32_t max_abs_misalignment_el_sky;
   % float32_t max_abs_misalignment_el_ground;
   % uint32_t initial_num_updates_az;
   % uint32_t initial_num_updates_el;
   % uint32_t initial_num_updates_rl;
   % uint8_t initial_align_quality_factor_az;
   % uint8_t initial_align_quality_factor_el;
   % uint8_t align_%
   % float32_t short_track_target_height;
   % float32_t short_track_target_range_rate;
   % float32_t az_scf_kf_covariance[4];
   % float32_t el_roll_kf_covariance[4];
   % uint8_t short_track_exit_condi%
   % float32_t iso_sensor_x_posn;
   % float32_t iso_sensor_y_posn;
   % float32_t iso_sensor_z_posn;
   % float32_t iso_sensor_yaw;
   % float32_t iso_sensor_pitch;
   % float32_t iso_sensor_roll;
   % float32_t distance_rear_axle_to_front_bumper;
   % uint8_t mount_loc;
   % uint8_t coordinate_system_input;
   % uint8_t f_data_valid;
   % uint8_t operation_mode_status;
   % Alignment_Handler_Output_T alignment_handler_out;
   % uint8_t auto_align_status;
   % float32_t aacurrent_azimuth;
   % float32_t aacurrent_elevation;

   fwrite(fileID, dynalign_data.initial_vacs_boresight_az_estimated(4), "float32");
   fwrite(fileID, dynalign_data.initial_vacs_boresight_el_estimated(4), "float32");
   fwrite(fileID, dynalign_data.initial_vacs_boresight_rl_estimated(4), "float32");
   fwrite(fileID, dynalign_data.initial_speed_compensation_factor(4), "float32");
   fwrite(fileID, dynalign_data.max_abs_misalignment_az(4), "float32");
   fwrite(fileID, dynalign_data.max_abs_misalignment_el_sky(4), "float32");
   fwrite(fileID, dynalign_data.max_abs_misalignment_el_ground(4), "float32");
   fwrite(fileID, dynalign_data.initial_num_updates_az(4), "uint32");
   fwrite(fileID, dynalign_data.initial_num_updates_el(4), "uint32");
   fwrite(fileID, dynalign_data.initial_num_updates_rl(4), "uint32");
   fwrite(fileID, dynalign_data.initial_align_quality_factor_az(4), "uint8");
   fwrite(fileID, dynalign_data.initial_align_quality_factor_el(4), "uint8");
   fwrite(fileID, dynalign_data.align_cmd(4), "uint8");
   fwrite(fileID, dynalign_data.short_track_target_height(4), "float32");
   fwrite(fileID, dynalign_data.short_track_target_range_rate(4), "float32");
   fwrite(fileID, dynalign_data.az_scf_kf_covariance(4, :), "float32");
   fwrite(fileID, dynalign_data.el_roll_kf_covariance(4, :), "float32");
   fwrite(fileID, dynalign_data.short_track_exit_condition(4), "uint8");
   fwrite(fileID, dynalign_data.iso_sensor_x_posn(4), "float32");
   fwrite(fileID, dynalign_data.iso_sensor_y_posn(4), "float32");
   fwrite(fileID, dynalign_data.iso_sensor_z_posn(4), "float32");
   fwrite(fileID, dynalign_data.iso_sensor_yaw(4), "float32");
   fwrite(fileID, dynalign_data.iso_sensor_pitch(4), "float32");
   fwrite(fileID, dynalign_data.iso_sensor_roll(4), "float32");
   fwrite(fileID, dynalign_data.distance_rear_axle_to_front_bumper(4), "float32");
   fwrite(fileID, dynalign_data.mount_loc(4), "uint8");
   fwrite(fileID, dynalign_data.coordinate_system_input(4), "uint8");
   fwrite(fileID, dynalign_data.f_data_valid(4), "uint8");
   fwrite(fileID, dynalign_data.operation_mode_status(4), "uint8");
   fwrite(fileID, dracore_data.vacs_boresight_az_kf_internal(4), "float32");
   fwrite(fileID, dracore_data.vacs_boresight_el_kf_internal(4), "float32");
   fwrite(fileID, dracore_data.n_updates_azimuth_initial(4), "uint32");

   % RC_GLOB_TS_STRUCT_TYPE
   % uint32_t ts_nanosecs;
   % uint32_t ts_secs;
   % uint8_t ts_status;

   % fwrite(fileID, rc_data.middle_of_dwell_ts.ts_status(1), "uint8");
   % fwrite(fileID, rc_data.middle_of_dwell_ts.ts_nanosecs(1), "uint32");
   % fwrite(fileID, rc_data.middle_of_dwell_ts.ts_secs(1), "uint32");

   % int16_t avg_mmic_onchip_temp;
   % uint16_t scan_index;
   % u9p7_T range_coverage;

   %  fwrite(fileID, rc_data.avg_mmic_onchip_temp(1), "int16");
   fwrite(fileID, af_data.det_list_property.lookindex(1), "uint16");
   fwrite(fileID, af_data.det_list_property.range_coverage(1), "uint16");

   % int16_t avg_mmic_onchip_temp;
   % uint16_t scan_index;
   % u9p7_T range_coverage;
   fwrite(fileID, dynalign_data.operation_mode_status(1), "uint8");
   % fwrite(fileID, toi_data.data_qualifier(1), "uint8");
   fwrite(fileID, 0, "uint8");
   fwrite(fileID, 0, "uint8");
   fwrite(fileID, 0, "uint8");

   fclose(fileID);

end
