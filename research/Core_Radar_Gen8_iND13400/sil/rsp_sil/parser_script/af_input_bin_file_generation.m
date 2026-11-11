clear all;
close all;
clc;

% Get the directory of the current script
scriptFullPath = mfilename('fullpath');
[scriptDir, ~, ~] = fileparts(scriptFullPath);

% Define variant
variant = 'flr8';

% % This need to generated using MATLAB Parsing scripts with pacap logs as input
load('output.mat');
scan_index_under_test = 605;

% Update the sensor and stream version number based on the log data
log_rdd_stream = output.Sensor_1_Unknown_Sensor.Stream_4_Version_11;
log_veh_stream   = output.Sensor_1_Unknown_Sensor.Stream_5_Version_2;
log_detection_stream = output.Sensor_1_Unknown_Sensor.Stream_1_Version_5;

%% RDD Stream bin file generation

% Construct folder path relative to the script location
folderPath = fullfile(scriptDir, '..', 'data_bin', 'af_data', variant, 'rdd_data');
folderPath = fullfile(folderPath);  % Normalize path

fileName = 'rdd_stream_input.bin';
fullFilePath = fullfile(folderPath, fileName);

% Check if the folder exists
if ~exist(folderPath, 'dir')
   mkdir(folderPath);  % Create folder if it doesn't exist
end

% Check if the file exists
if exist(fullFilePath, 'file')
   delete(fullFilePath);  % Delete existing file
end

% Open the file for writing (creates a new file)
fileID = fopen(fullFilePath, 'w');

rdd_scan_index = log_rdd_stream.stream_hdr.scan_index;
index_to_be_tested = find(rdd_scan_index == scan_index_under_test);

end_index = index_to_be_tested;
avg_temp = zeros(1, end_index);

for k = index_to_be_tested:end_index
   fwrite(fileID, log_rdd_stream.stream_hdr.size(k), 'uint32');
   fwrite(fileID, log_rdd_stream.stream_hdr.version(k), 'uint16');
   fwrite(fileID, log_rdd_stream.stream_hdr.checksum(k), 'uint16');
   fwrite(fileID, log_rdd_stream.stream_hdr.scan_index(k), 'uint16');
   fwrite(fileID, log_rdd_stream.stream_hdr.error_info(k), 'uint16');
   fwrite(fileID, log_rdd_stream.stream_hdr.module_time_ms(k), 'uint32');

   fwrite(fileID, log_rdd_stream.look_data.look_id(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.look_data.scan_type(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.look_data.scan_index(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.look_data.K_Unused16_1(k, :), 'uint16');

   fwrite(fileID, log_rdd_stream.rdd_data.bwdep_cr_resp(k, :), 'uint32');
   fwrite(fileID, log_rdd_stream.rdd_data.bwdep_sensitivity_thold(k, :), 'uint32');
   fwrite(fileID, log_rdd_stream.rdd_data.af_sensitivity_thold(k, :), 'uint32');
   fwrite(fileID, log_rdd_stream.rdd_data.bwdep_hvc_thold (k, :), 'uint32');
   fwrite(fileID, log_rdd_stream.rdd_data.bwdep_mb_thold(k, :), 'uint32');
   fixed_rbinest = log_rdd_stream.rdd_data.rdd1_rbinest(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, fixed_rbinest, 'int32');
   fixed_dbinest = log_rdd_stream.rdd_data.rdd1_dbinest(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, fixed_dbinest, 'int32');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd2_thold_2nd_pass(k, :), 'uint32');
   rdd2_range = log_rdd_stream.rdd_data.rdd2_range(k, :) .* 2^21; %     s10p21_T
   fwrite(fileID, rdd2_range, 'int32');
   rdd2_range_rate = log_rdd_stream.rdd_data.rdd2_range_rate(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, rdd2_range_rate, 'int32');
   rdd2_snr = log_rdd_stream.rdd_data.rdd2_snr(k, :) .* 2^23;        %     s8p23_T
   fwrite(fileID, rdd2_snr, 'int32');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_bv(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.cfar_nf_est(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.cfar_thold(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.cfar_nf_est_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.cfar_thold_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_max_per_range_bin(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_max_per_range_bin_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_signal_thold_first_pass(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_signal_thold_first_pass_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_first_pass_thold(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_first_pass_thold_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_rdop_amp(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_rdop_amp_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_rindx(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_dindx(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_dindx_ci(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd1_num_detect(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd2_num_detect(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.nci_bexp(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.ci_bexp(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.K_Unused16_1(k, :), 'uint16');
   fwrite(fileID, log_rdd_stream.rdd_data.ci_detections_flag(k, :), 'uint8');
   fwrite(fileID, log_rdd_stream.rdd_data.rdd2_sp_fail_flag(k, :), 'uint8');
   fwrite(fileID, log_rdd_stream.rdd_data.min_chirp_scaling(k, :), 'uint8');
   fwrite(fileID, log_rdd_stream.rdd_data.below_sp_thold(k, :), 'uint8');
   fwrite(fileID, log_rdd_stream.rdd_data.K_Unused8_1(k, :), 'uint8');
end
fclose(fileID);

%% Generates-Vse-Stream-Bin-File

% Construct folder path relative to the script location
folderPath = fullfile(scriptDir, '..', 'data_bin', 'af_data', variant, 'vse_data');
folderPath = fullfile(folderPath);  % Normalize path

fileName = 'vse_stream_input.bin';
fullFilePath = fullfile(folderPath, fileName);

% Check if the folder exists
if ~exist(folderPath, 'dir')
   mkdir(folderPath);  % Create folder if it doesn't exist
end

% Check if the file exists
if exist(fullFilePath, 'file')
   delete(fullFilePath);  % Delete existing file
end

% Open the file for writing (creates a new file)
fileID = fopen(fullFilePath, 'w');

% Always check the sync of RDD and VSE stream indices%
vse_scan_idx = log_veh_stream.stream_hdr.scan_index;
m = find(vse_scan_idx == scan_index_under_test);

index_to_be_tested = m;
end_index = index_to_be_tested;

for k = index_to_be_tested:end_index
   %%%%%%%%%%%%%%%% Vse stream data %%%%%%%%%%%%%%%%
   % Veh_Raw_Data_T layout (matches updated Vse_Stream_T)
   fwrite(fileID, log_veh_stream.veh_raw_data.system_time_secs(k, :), 'uint32');
   fwrite(fileID, log_veh_stream.veh_raw_data.system_time_nanosecs(k, :), 'uint32');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_vehicle_speed(k, :), 'float');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_yaw_rate(k, :), 'float');
   fwrite(fileID, log_veh_stream.veh_raw_data.steering_whl_angle(k, :), 'float');
   fwrite(fileID, log_veh_stream.veh_raw_data.steering_whl_speed_deg_per_s(k, :), 'float');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_lateral_accel(k, :), 'float');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_longitudinal_accel(k, :), 'float');
   fwrite(fileID, log_veh_stream.veh_raw_data.vehspeedcompfac_ka(k, :), 'float');
   fwrite(fileID, 0, 'uint16'); % K_Unused16_1
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_vehicle_speed_qf(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_yaw_rate_qf(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.vehicle_standstill(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.steering_whl_angle_qf(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_lateral_accel_qf(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.ego_longitudinal_accel_qf(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.gear_pos(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.vehspeedcompfac_ka_qf(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.turn_signal(k, :), 'uint8');
   fwrite(fileID, log_veh_stream.veh_raw_data.K_Unused8_1(k, :), 'uint8');

end
fclose(fileID);

%% AF output text file generation for the scan index under test

% Always check the sync of RDD and Detection stream indices%
af_emb_scan_idx = log_detection_stream.stream_hdr.scan_index;
m = find(af_emb_scan_idx == scan_index_under_test);

index_to_be_tested = m;

%%%%%%%%% PRINT AF Detection Outputs %%%%%%%%%%
file_id = fopen('af_det_out_emb.txt', 'w');
fprintf(file_id, "num_af_det  : ");
num_af_det = log_detection_stream.af_data.num_af_det(index_to_be_tested);
fprintf(file_id, "%d ", num_af_det);
fprintf(file_id, "\n");
fprintf(file_id, "ran : ");
for i = 1:num_af_det
   fprintf(file_id, "%f, ", log_detection_stream.af_data.ran(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "vel : ");
for i = 1:num_af_det
   fprintf(file_id, "%f, ", log_detection_stream.af_data.vel(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "pow : ");
for i = 1:num_af_det
   fprintf(file_id, "%f ", log_detection_stream.af_data.pow(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "snr : ");
for i = 1:num_af_det
   fprintf(file_id, "%f, ", log_detection_stream.af_data.snr(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "theta : ");
for i = 1:num_af_det
   fprintf(file_id, "%f, ", log_detection_stream.af_data.theta(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "phi : ");
for i = 1:num_af_det
   fprintf(file_id, "%f, ", log_detection_stream.af_data.phi(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "rcs : ");
for i = 1:num_af_det
   fprintf(file_id, "%f ", log_detection_stream.af_data.rcs(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "spec_res : ");
for i = 1:num_af_det
   fprintf(file_id, "%f, ", log_detection_stream.af_data.spec_res(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "rdd_idx : ");
for i = 1:num_af_det
   fprintf(file_id, "%d, ", log_detection_stream.af_data.rdd_idx(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "az_conf : ");
for i = 1:num_af_det
   fprintf(file_id, "%d, ", log_detection_stream.af_data.az_conf(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "el_conf : ");
for i = 1:num_af_det
   fprintf(file_id, "%d, ", log_detection_stream.af_data.el_conf(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "f_single_target : ");
for i = 1:num_af_det
   fprintf(file_id, "%d, ", log_detection_stream.af_data.f_single_target(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "f_superres_target : ");
for i = 1:num_af_det
   fprintf(file_id, "%d, ", log_detection_stream.af_data.f_superres_target(index_to_be_tested, i));
end
fprintf(file_id, "\n");

% fprintf(file_id, "f_1az2el : ");
% for i = 1:num_af_det
%    fprintf(file_id, "%d ", log_detection_stream.af_data.f_1az2el(index_to_be_tested, i));
% end
% fprintf(file_id, "\n");

fprintf(file_id, "f_bistatic : ");
for i = 1:num_af_det
   fprintf(file_id, "%d, ", log_detection_stream.af_data.f_bistatic(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fclose(file_id);
