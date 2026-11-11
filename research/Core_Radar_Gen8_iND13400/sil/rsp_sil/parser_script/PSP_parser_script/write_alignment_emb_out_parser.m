function write_alignment_emb_out_parser(dracore_data, sa_stream_data, frame_idx, exe_dir)

   % creates a file named "da_out_emb.txt" in the same path as this .mat
   % file

   if ~isempty(exe_dir)
      file_name = fullfile(exe_dir, "da_out_emb.txt");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   for k = frame_idx:frame_idx

      % read version
      fprintf(fileID, "version_major: %d\n", dracore_data.version_major(k));
      fprintf(fileID, "version_minor: %d\n", dracore_data.version_minor(k));
      fprintf(fileID, "version_patch: %d\n", dracore_data.version_patch(k));
      % read  dra_core_data
      fprintf(fileID, "raw_speed: %d\n", dracore_data.raw_speed(k));
      fprintf(fileID, "estimated_speed: %f\n", dracore_data.estimated_speed(k));
      fprintf(fileID, "raw_yawrate: %d\n", dracore_data.raw_yawrate(k));
      fprintf(fileID, "estimated_yawrate: %d\n", dracore_data.estimated_yawrate(k));
      fprintf(fileID, "estimated_yaw_rate_bias: %d\n", dracore_data.estimated_yaw_rate_bias(k));
      fprintf(fileID, "vcs_sensor_long_posn: %f\n", dracore_data.vcs_sensor_long_posn(k));
      fprintf(fileID, "vcs_sensor_lat_posn: %f\n", dracore_data.vcs_sensor_lat_posn(k));
      fprintf(fileID, "sensor_height_over_ground: %f\n", dracore_data.sensor_height_over_ground(k));
      fprintf(fileID, "alignment_index: %d\n", dracore_data.alignment_index(k));
      fprintf(fileID, "vwrapping: %d\n", dracore_data.vwrapping(k));
      fprintf(fileID, "vacs_boresight_az_nominal: %f\n", dracore_data.vacs_boresight_az_nominal(k));
      fprintf(fileID, "vacs_boresight_az_initial: %f\n", dracore_data.vacs_boresight_az_initial(k));
      fprintf(fileID, "vacs_boresight_az_kf_internal: %f\n", dracore_data.vacs_boresight_az_kf_internal(k));
      fprintf(fileID, "vacs_boresight_az_estimated: %f\n", dracore_data.vacs_boresight_az_estimated(k));
      fprintf(fileID, "vacs_boresight_az_variance: %d\n", dracore_data.vacs_boresight_az_variance(k));
      fprintf(fileID, "vacs_boresight_el_nominal: %f\n", dracore_data.vacs_boresight_el_nominal(k));
      fprintf(fileID, "vacs_boresight_el_initial: %f\n", dracore_data.vacs_boresight_el_initial(k));
      fprintf(fileID, "vacs_boresight_el_kf_internal: %f\n", dracore_data.vacs_boresight_el_kf_internal(k));
      fprintf(fileID, "vacs_boresight_el_estimated: %f\n", dracore_data.vacs_boresight_el_estimated(k));
      fprintf(fileID, "vacs_boresight_el_variance: %d\n", dracore_data.vacs_boresight_el_variance(k));
      fprintf(fileID, "vacs_boresight_roll_nominal: %f\n", dracore_data.vacs_boresight_roll_nominal(k));
      fprintf(fileID, "speed_compensation_factor_initial: %f\n", dracore_data.speed_compensation_factor_initial(k));
      fprintf(fileID, "speed_compensation_factor_estimated: %f\n", dracore_data.speed_compensation_factor_estimated(k));
      fprintf(fileID, "avg_spd_since_start: %f\n", dracore_data.avg_spd_since_start(k));
      fprintf(fileID, "avg_spd_running_az_scf: %f\n", dracore_data.avg_spd_running_az_scf(k));
      fprintf(fileID, "avg_spd_running_el: %f\n", dracore_data.avg_spd_running_el(k));
      fprintf(fileID, "total_time_running_az_scf: %f\n", dracore_data.total_time_running_az_scf(k));
      fprintf(fileID, "total_time_running_el: %f\n", dracore_data.total_time_running_el(k));
      fprintf(fileID, "total_time_since_start: %f\n", dracore_data.total_time_since_start(k));
      fprintf(fileID, "total_distance_running_az_scf: %f\n", dracore_data.total_distance_running_az_scf(k));
      fprintf(fileID, "total_distance_running_el: %f\n", dracore_data.total_distance_running_el(k));
      fprintf(fileID, "total_distance_since_start: %f\n", dracore_data.total_distance_since_start(k));
      fprintf(fileID, "alignment_complete_percent_az: %f\n", dracore_data.alignment_complete_percent_az(k));
      fprintf(fileID, "alignment_complete_percent_el: %f\n", dracore_data.alignment_complete_percent_el(k));
      fprintf(fileID, "estimated_standard_deviation_az: %f\n", dracore_data.estimated_standard_deviation_az(k));
      fprintf(fileID, "estimated_standard_deviation_el: %f\n", dracore_data.estimated_standard_deviation_el(k));
      fprintf(fileID, "estimated_pos_error_bound_az: %f\n", dracore_data.estimated_pos_error_bound_az(k));
      fprintf(fileID, "estimated_neg_error_bound_az: %f\n", dracore_data.estimated_neg_error_bound_az(k));
      fprintf(fileID, "estimated_pos_error_bound_el: %f\n", dracore_data.estimated_pos_error_bound_el(k));
      fprintf(fileID, "estimated_neg_error_bound_el: %f\n", dracore_data.estimated_neg_error_bound_el(k));
      fprintf(fileID, "alignment_mode: %d\n", dracore_data.alignment_mode(k));
      fprintf(fileID, "mounting_location: %d\n", dracore_data.mounting_location(k));
      fprintf(fileID, "azimuth_estimation_qf: %d\n", dracore_data.azimuth_estimation_qf(k));
      fprintf(fileID, "elevation_estimation_qf: %d\n", dracore_data.elevation_estimation_qf(k));
      fprintf(fileID, "scf_estimation_qf: %d\n", dracore_data.scf_estimation_qf(k));
      fprintf(fileID, "error_status_combined: %d\n", dracore_data.error_status_combined(k));
      fprintf(fileID, "error_status_initialization: %d\n", dracore_data.error_status_initialization(k));
      fprintf(fileID, "error_status_excessive_blockage: %d\n", dracore_data.error_status_excessive_blockage(k));
      fprintf(fileID, "error_status_interference: %d\n", dracore_data.error_status_interference(k));
      fprintf(fileID, "error_status_detection_input: %d\n", dracore_data.error_status_detection_input(k));
      fprintf(fileID, "error_status_vehicle_input: %d\n", dracore_data.error_status_vehicle_input(k));
      fprintf(fileID, "error_status_scf_out_of_bounds: %d\n", dracore_data.error_status_scf_out_of_bounds(k));
      fprintf(fileID, "error_status_az_est_out_of_bounds: %d\n", dracore_data.error_status_az_est_out_of_bounds(k));
      fprintf(fileID, "error_status_el_est_out_of_bounds: %d\n", dracore_data.error_status_el_est_out_of_bounds(k));
      fprintf(fileID, "blockage_value: %d\n", dracore_data.blockage_value(k));
      fprintf(fileID, "blockage_status: %d\n\n", dracore_data.blockage_status(k));

   end % end of for loop used for index count

   fclose(fileID);

   % creates a file named "sa_out_emb.txt" in the same path as this .mat
   % file

   if ~isempty(exe_dir)
      file_name = fullfile(exe_dir, "sa_out_emb.txt");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   for k = frame_idx:frame_idx

      % read version
      fprintf(fileID, "version_major: %f\n", sa_stream_data.static_align_stream_output.version_major(k));
      fprintf(fileID, "version_minor: %f\n", sa_stream_data.static_align_stream_output.version_minor(k));
      fprintf(fileID, "version_patch: %f\n", sa_stream_data.static_align_stream_output.version_patch(k));
      % read  static_align_output
      fprintf(fileID, "qf_az: %f\n", sa_stream_data.static_align_output.qf_az(k));
      fprintf(fileID, "qf_el: %f\n", sa_stream_data.static_align_output.qf_el(k));
      fprintf(fileID, "status_vert_misalign_ang: %f\n", sa_stream_data.static_align_output.status_vert_misalign_ang(k));
      fprintf(fileID, "status_of_plate: %f\n", sa_stream_data.static_align_output.status_of_plate(k));
      fprintf(fileID, "vert_misalign_ang: %f\n", sa_stream_data.static_align_output.vert_misalign_ang(k));
      fprintf(fileID, "horiz_misalign_ang: %f\n", sa_stream_data.static_align_output.horiz_misalign_ang(k));
      fprintf(fileID, "status_horiz_misalign_ang: %f\n", sa_stream_data.static_align_output.status_horiz_misalign_ang(k));
      fprintf(fileID, "std_azimuth: %f\n", sa_stream_data.static_align_output.std_azimuth(k));
      fprintf(fileID, "std_amplitude: %f\n", sa_stream_data.static_align_output.std_amplitude(k));
      fprintf(fileID, "std_elevation: %f\n", sa_stream_data.static_align_output.std_elevation(k));
      fprintf(fileID, "std_range: %f\n", sa_stream_data.static_align_output.std_range(k));
      fprintf(fileID, "std_r_dot: %f\n", sa_stream_data.static_align_output.std_r_dot(k));
      fprintf(fileID, "complete_percentage: %f\n\n", sa_stream_data.static_align_output.complete_percentage(k));

   end % end of for loop used for index count

   fclose(fileID);

   % =========================================================================
   % FILE REVISION HISTORY - To be filled by the project team
   % -------------------------------------------------------------------------
   %
   % REVISION         AID               SUMMARY OF CHANGES
   % -------------------------------------------------------------------------
   %      1        AthulNath RS           First version
   %
   % -------------------------------------------------------------------------
   % =========================================================================

   % END OF FILE ------------------------------------------------------------%
