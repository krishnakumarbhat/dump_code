% clear workspace
clc;
close all;

% give appropriate path to .mat file which has decoded log info
load('C:\Users\uf0l00\workspace\logs\K\flr7_paused.mat');

% after loading change variable name brr in next line to whatever variable name the .mat
% file is loaded into such as pcap, mudp, mf4, brr
% and also change sensor number and stream version based on log
% draIntLog = aptivData.Sensor_1_SRR7P_V2.Stream_46.dra_internals;
StaticAlignData = Log_00001.Sensor_1_FLR8.Stream_2.alignment_data.static_alignment_data;
DynAlignData = pcap.Sensor_5_Unknown_Sensor.Stream_2_Version_7.alignment_data.dynamic_alignment_data;
RcStream = pcap.Sensor_5_Unknown_Sensor.Stream_20_Version_47;
DetStream = pcap.Sensor_5_Unknown_Sensor.Stream_1_Version_16;
DraCoreLogData = pcap.Sensor_5_Unknown_Sensor.Stream_45_Version_15.dra_core_data;

% creates a file named "psp_input.bin" in the same path as this .mat
% file
fileID = fopen('psp_input.bin', 'w');
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

fwrite(fileID, StaticAlignData.yaw(4), "float32");
fwrite(fileID, StaticAlignData.pitch(4), "float32");
fwrite(fileID, StaticAlignData.plate_angle_deg_scs(4), "float32");
fwrite(fileID, StaticAlignData.plate_distance(4), "float32");
fwrite(fileID, StaticAlignData.polarity(4), "float32");
fwrite(fileID, StaticAlignData.horz_angle_min(4), "float32");
fwrite(fileID, StaticAlignData.horz_angle_max(4), "float32");
fwrite(fileID, StaticAlignData.vert_angle_min(4), "float32");
fwrite(fileID, StaticAlignData.vert_angle_max(4), "float32");
fwrite(fileID, StaticAlignData.plate_lat_position(4), "float32");
fwrite(fileID, StaticAlignData.mount_loc(4), "uint8");
fwrite(fileID, StaticAlignData.align_cmd(4), "uint8");
fwrite(fileID, StaticAlignData.f_data_valid(4), "uint8");

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
% uint8_t align_cmd;
% float32_t short_track_target_height;
% float32_t short_track_target_range_rate;
% float32_t az_scf_kf_covariance[4];
% float32_t el_roll_kf_covariance[4];
% uint8_t short_track_exit_condition;
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

fwrite(fileID, DynAlignData.initial_vacs_boresight_az_estimated(4), "float32");
fwrite(fileID, DynAlignData.initial_vacs_boresight_el_estimated(4), "float32");
fwrite(fileID, DynAlignData.initial_vacs_boresight_rl_estimated(4), "float32");
fwrite(fileID, DynAlignData.initial_speed_compensation_factor(4), "float32");
fwrite(fileID, DynAlignData.max_abs_misalignment_az(4), "float32");
fwrite(fileID, DynAlignData.max_abs_misalignment_el_sky(4), "float32");
fwrite(fileID, DynAlignData.max_abs_misalignment_el_ground(4), "float32");
fwrite(fileID, DynAlignData.initial_num_updates_az(4), "uint32");
fwrite(fileID, DynAlignData.initial_num_updates_el(4), "uint32");
fwrite(fileID, DynAlignData.initial_num_updates_rl(4), "uint32");
fwrite(fileID, DynAlignData.initial_align_quality_factor_az(4), "uint8");
fwrite(fileID, DynAlignData.initial_align_quality_factor_el(4), "uint8");
fwrite(fileID, DynAlignData.align_cmd(4), "uint8");
fwrite(fileID, DynAlignData.short_track_target_height(4), "float32");
fwrite(fileID, DynAlignData.short_track_target_range_rate(4), "float32");
fwrite(fileID, DynAlignData.az_scf_kf_covariance(4, :), "float32");
fwrite(fileID, DynAlignData.el_roll_kf_covariance(4, :), "float32");
fwrite(fileID, DynAlignData.short_track_exit_condition(4), "uint8");
fwrite(fileID, DynAlignData.iso_sensor_x_posn(4), "float32");
fwrite(fileID, DynAlignData.iso_sensor_y_posn(4), "float32");
fwrite(fileID, DynAlignData.iso_sensor_z_posn(4), "float32");
fwrite(fileID, DynAlignData.iso_sensor_yaw(4), "float32");
fwrite(fileID, DynAlignData.iso_sensor_pitch(4), "float32");
fwrite(fileID, DynAlignData.iso_sensor_roll(4), "float32");
fwrite(fileID, DynAlignData.distance_rear_axle_to_front_bumper(4), "float32");
fwrite(fileID, DynAlignData.mount_loc(4), "uint8");
fwrite(fileID, DynAlignData.coordinate_system_input(4), "uint8");
fwrite(fileID, DynAlignData.f_data_valid(4), "uint8");
fwrite(fileID, DynAlignData.operation_mode_status(4), "uint8");
fwrite(fileID, DynAlignData.alignment_handler_out.auto_align_status(4), "uint8");
fwrite(fileID, DynAlignData.alignment_handler_out.aacurrent_azimuth(4), "float32");
fwrite(fileID, DynAlignData.alignment_handler_out.aacurrent_elevation(4), "float32");

% RC_GLOB_TS_STRUCT_TYPE
% uint32_t ts_nanosecs;
% uint32_t ts_secs;
% uint8_t ts_status;

fwrite(fileID, RcStream.middle_of_dwell_ts.ts_nanosecs(4), "uint32");
fwrite(fileID, RcStream.middle_of_dwell_ts.ts_secs(4), "uint32");
fwrite(fileID, RcStream.middle_of_dwell_ts.ts_status(4), "uint8");

% int16_t avg_mmic_onchip_temp;
% uint16_t scan_index;
% u9p7_T range_coverage;
% uint8_t operation_mode_status;
% uint8_t toi_data_qualifier;
fwrite(fileID, RcStream.avg_mmic_onchip_temp(4), "uint16");
fwrite(fileID, DetStream.det_list_property.lookindex(4), "uint16");
fwrite(fileID, DetStream.det_list_property.range_coverage(4), "uint16");
fwrite(fileID, DraCoreLogData.vacs_boresight_az_kf_internal(4), "float32");
fwrite(fileID, DraCoreLogData.vacs_boresight_el_kf_internal(4), "float32");
fwrite(fileID, DraCoreLogData.n_updates_azimuth_initial(4), "uint32");

fclose(fileID);

% =========================================================================
% FILE REVISION HISTORY - To be filled by the project team
% -------------------------------------------------------------------------
%
% REVISION         AID               SUMMARY OF CHANGES
% -------------------------------------------------------------------------
%      1      AthulNath RS         First version
%
% -------------------------------------------------------------------------
% =========================================================================

% END OF FILE------------------------------------------------------------%
