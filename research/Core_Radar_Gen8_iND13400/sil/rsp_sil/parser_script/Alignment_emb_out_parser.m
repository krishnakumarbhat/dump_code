clc;
close all;

% give appropriate path to .mat file which has decoded log info
data = load('C:\Users\sj779s\Downloads\v2_bench_log\Alignment_log.mat');

% after loading data, update following script based on sensor number and stream version based on log
% file is loaded into such as pcap, mudp, mf4, brr
dra = data.pcap.Sensor_4_Unknown_Sensor.Stream_45_Version_12;
sra = data.pcap.Sensor_4_Unknown_Sensor.Stream_9_Version_10;

% scan index to be logged in .bin files.update startIdx to required value for testing is being consider.
startIdx = 1;
endIdx = startIdx; % forces loop to log only one value

% creates a file named "da_out_emb.txt" in the same path as this .mat
% file
fileID = fopen('da_out_emb.txt', 'w');

for idx = startIdx:endIdx
   % read version
   fprintf(fileID, "version_major: %d\n", dra.dra_core_data.version_major(idx));
   fprintf(fileID, "version_minor: %d\n", dra.dra_core_data.version_minor(idx));
   fprintf(fileID, "version_patch: %d\n", dra.dra_core_data.version_patch(idx));
   % read  dra_core_data
   fprintf(fileID, "raw_speed: %d\n", dra.dra_core_data.raw_speed(idx));
   fprintf(fileID, "estimated_speed: %f\n", dra.dra_core_data.estimated_speed(idx));
   fprintf(fileID, "raw_yawrate: %d\n", dra.dra_core_data.raw_yawrate(idx));
   fprintf(fileID, "estimated_yawrate: %d\n", dra.dra_core_data.estimated_yawrate(idx));
   fprintf(fileID, "estimated_yaw_rate_bias: %d\n", dra.dra_core_data.estimated_yaw_rate_bias(idx));
   fprintf(fileID, "vcs_sensor_long_posn: %f\n", dra.dra_core_data.vcs_sensor_long_posn(idx));
   fprintf(fileID, "vcs_sensor_lat_posn: %f\n", dra.dra_core_data.vcs_sensor_lat_posn(idx));
   fprintf(fileID, "sensor_height_over_ground: %f\n", dra.dra_core_data.sensor_height_over_ground(idx));
   fprintf(fileID, "alignment_index: %d\n", dra.dra_core_data.alignment_index(idx));
   fprintf(fileID, "vwrapping: %d\n", dra.dra_core_data.vwrapping(idx));
   fprintf(fileID, "vacs_boresight_az_nominal: %f\n", dra.dra_core_data.vacs_boresight_az_nominal(idx));
   fprintf(fileID, "vacs_boresight_az_initial: %f\n", dra.dra_core_data.vacs_boresight_az_initial(idx));
   fprintf(fileID, "vacs_boresight_az_kf_internal: %f\n", dra.dra_core_data.vacs_boresight_az_kf_internal(idx));
   fprintf(fileID, "vacs_boresight_az_estimated: %f\n", dra.dra_core_data.vacs_boresight_az_estimated(idx));
   fprintf(fileID, "vacs_boresight_az_variance: %d\n", dra.dra_core_data.vacs_boresight_az_variance(idx));
   fprintf(fileID, "vacs_boresight_el_nominal: %f\n", dra.dra_core_data.vacs_boresight_el_nominal(idx));
   fprintf(fileID, "vacs_boresight_el_initial: %f\n", dra.dra_core_data.vacs_boresight_el_initial(idx));
   fprintf(fileID, "vacs_boresight_el_kf_internal: %f\n", dra.dra_core_data.vacs_boresight_el_kf_internal(idx));
   fprintf(fileID, "vacs_boresight_el_estimated: %f\n", dra.dra_core_data.vacs_boresight_el_estimated(idx));
   fprintf(fileID, "vacs_boresight_el_variance: %d\n", dra.dra_core_data.vacs_boresight_el_variance(idx));
   fprintf(fileID, "vacs_boresight_roll_nominal: %f\n", dra.dra_core_data.vacs_boresight_roll_nominal(idx));
   fprintf(fileID, "speed_compensation_factor_initial: %f\n", dra.dra_core_data.speed_compensation_factor_initial(idx));
   fprintf(fileID, "speed_compensation_factor_estimated: %f\n", dra.dra_core_data.speed_compensation_factor_estimated(idx));
   fprintf(fileID, "avg_spd_since_start: %f\n", dra.dra_core_data.avg_spd_since_start(idx));
   fprintf(fileID, "avg_spd_running_az_scf: %f\n", dra.dra_core_data.avg_spd_running_az_scf(idx));
   fprintf(fileID, "avg_spd_running_el: %f\n", dra.dra_core_data.avg_spd_running_el(idx));
   fprintf(fileID, "total_time_running_az_scf: %f\n", dra.dra_core_data.total_time_running_az_scf(idx));
   fprintf(fileID, "total_time_running_el: %f\n", dra.dra_core_data.total_time_running_el(idx));
   fprintf(fileID, "total_time_since_start: %f\n", dra.dra_core_data.total_time_since_start(idx));
   fprintf(fileID, "total_distance_running_az_scf: %f\n", dra.dra_core_data.total_distance_running_az_scf(idx));
   fprintf(fileID, "total_distance_running_el: %f\n", dra.dra_core_data.total_distance_running_el(idx));
   fprintf(fileID, "total_distance_since_start: %f\n", dra.dra_core_data.total_distance_since_start(idx));
   fprintf(fileID, "alignment_complete_percent_az: %f\n", dra.dra_core_data.alignment_complete_percent_az(idx));
   fprintf(fileID, "alignment_complete_percent_el: %f\n", dra.dra_core_data.alignment_complete_percent_el(idx));
   fprintf(fileID, "estimated_standard_deviation_az: %f\n", dra.dra_core_data.estimated_standard_deviation_az(idx));
   fprintf(fileID, "estimated_standard_deviation_el: %f\n", dra.dra_core_data.estimated_standard_deviation_el(idx));
   fprintf(fileID, "estimated_pos_error_bound_az: %f\n", dra.dra_core_data.estimated_pos_error_bound_az(idx));
   fprintf(fileID, "estimated_neg_error_bound_az: %f\n", dra.dra_core_data.estimated_neg_error_bound_az(idx));
   fprintf(fileID, "estimated_pos_error_bound_el: %f\n", dra.dra_core_data.estimated_pos_error_bound_el(idx));
   fprintf(fileID, "estimated_neg_error_bound_el: %f\n", dra.dra_core_data.estimated_neg_error_bound_el(idx));
   fprintf(fileID, "alignment_mode: %d\n", dra.dra_core_data.alignment_mode(idx));
   fprintf(fileID, "mounting_location: %d\n", dra.dra_core_data.mounting_location(idx));
   fprintf(fileID, "azimuth_estimation_qf: %d\n", dra.dra_core_data.azimuth_estimation_qf(idx));
   fprintf(fileID, "elevation_estimation_qf: %d\n", dra.dra_core_data.elevation_estimation_qf(idx));
   fprintf(fileID, "scf_estimation_qf: %d\n", dra.dra_core_data.scf_estimation_qf(idx));
   fprintf(fileID, "error_status_combined: %d\n", dra.dra_core_data.error_status_combined(idx));
   fprintf(fileID, "error_status_initialization: %d\n", dra.dra_core_data.error_status_initialization(idx));
   fprintf(fileID, "error_status_excessive_blockage: %d\n", dra.dra_core_data.error_status_excessive_blockage(idx));
   fprintf(fileID, "error_status_interference: %d\n", dra.dra_core_data.error_status_interference(idx));
   fprintf(fileID, "error_status_detection_input: %d\n", dra.dra_core_data.error_status_detection_input(idx));
   fprintf(fileID, "error_status_vehicle_input: %d\n", dra.dra_core_data.error_status_vehicle_input(idx));
   fprintf(fileID, "error_status_scf_out_of_bounds: %d\n", dra.dra_core_data.error_status_scf_out_of_bounds(idx));
   fprintf(fileID, "error_status_az_est_out_of_bounds: %d\n", dra.dra_core_data.error_status_az_est_out_of_bounds(idx));
   fprintf(fileID, "error_status_el_est_out_of_bounds: %d\n", dra.dra_core_data.error_status_el_est_out_of_bounds(idx));
   fprintf(fileID, "blockage_value: %d\n", dra.dra_core_data.blockage_value(idx));
   fprintf(fileID, "blockage_status: %d\n\n", dra.dra_core_data.blockage_status(idx));

end % end of for loop used for index count

fclose(fileID);

% creates a file named "sa_out_emb.txt" in the same path as this .mat
% file
fileID = fopen('sa_out_emb.txt', 'w');

for idx = startIdx:endIdx
   % read version
   fprintf(fileID, "version_major: %f\n", sra.static_align_stream_output.version_major(idx));
   fprintf(fileID, "version_minor: %f\n", sra.static_align_stream_output.version_minor(idx));
   fprintf(fileID, "version_patch: %f\n", sra.static_align_stream_output.version_patch(idx));
   % read  static_align_output
   fprintf(fileID, "qf_az: %f\n", sra.static_align_output.qf_az(idx));
   fprintf(fileID, "qf_el: %f\n", sra.static_align_output.qf_el(idx));
   fprintf(fileID, "status_vert_misalign_ang: %f\n", sra.static_align_output.status_vert_misalign_ang(idx));
   fprintf(fileID, "status_of_plate: %f\n", sra.static_align_output.status_of_plate(idx));
   fprintf(fileID, "vert_misalign_ang: %f\n", sra.static_align_output.vert_misalign_ang(idx));
   fprintf(fileID, "horiz_misalign_ang: %f\n", sra.static_align_output.horiz_misalign_ang(idx));
   fprintf(fileID, "status_horiz_misalign_ang: %f\n", sra.static_align_output.status_horiz_misalign_ang(idx));
   fprintf(fileID, "std_azimuth: %f\n", sra.static_align_output.std_azimuth(idx));
   fprintf(fileID, "std_amplitude: %f\n", sra.static_align_output.std_amplitude(idx));
   fprintf(fileID, "std_elevation: %f\n", sra.static_align_output.std_elevation(idx));
   fprintf(fileID, "std_range: %f\n", sra.static_align_output.std_range(idx));
   fprintf(fileID, "std_r_dot: %f\n", sra.static_align_output.std_r_dot(idx));
   fprintf(fileID, "complete_percentage: %f\n\n", sra.static_align_output.complete_percentage(idx));

end % end of for loop used for index count

fclose(fileID);

% =========================================================================
% FILE REVISION HISTORY - To be filled by the project team
% -------------------------------------------------------------------------
%
% REVISION         AID               SUMMARY OF CHANGES
% -------------------------------------------------------------------------
%      1        Abhimanyu            First version
%
% -------------------------------------------------------------------------
% =========================================================================

% END OF FILE ------------------------------------------------------------%
