clear all;
close all;
clc;
% Load the mat file which has the different stream data(rdd, cdc , status stream)
% This need to generated using MATLAB Parsing scripts with pacap logs as input
load('vehicle_log_v5.1.1.mat');

AF_BIN_FILE_GENERATION = 0;
% Update the sensor and stream version number based on the log data
log_rdd = Log_00001.Sensor_5_FLR8.Stream_4;
veh_data = Log_00001.Sensor_5_FLR8.Stream_5;

% Always check the sync of RDD and CDC stream indices %
index_to_be_tested = 20;

%%%%%%%%%%% Generates-RDD-Stream-Bin-File%%%%%%%%%%%

% Always check the sync of RDD and CDC stream indices%
index_to_be_tested = 20;
fileID = fopen('rdd_input.bin', 'w');
end_index = index_to_be_tested;
avg_temp = zeros(1, end_index);
for k = index_to_be_tested:end_index
   fwrite(fileID, log_rdd.rdd_data.cfar_corr_coeff(k, :), 'float32');
   fixed_rbinest = log_rdd.rdd_data.rdd1_rbinest(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, fixed_rbinest, 'int32');
   fixed_dbinest = log_rdd.rdd_data.rdd1_dbinest(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, fixed_dbinest, 'int32');
   fixed_abinest = log_rdd.rdd_data.rdd1_abinest(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, fixed_abinest, 'int32');
   fwrite(fileID, log_rdd.rdd_data.rdd2_thold_2nd_pass(k, :), 'uint32');
   rdd2_range = log_rdd.rdd_data.rdd2_range(k, :) .* 2^21; %     s10p21_T
   fwrite(fileID, rdd2_range, 'int32');
   rdd2_range_rate = log_rdd.rdd_data.rdd2_range_rate(k, :) .* 2^21; % s10p21_T
   fwrite(fileID, rdd2_range_rate, 'int32');
   rdd2_snr = log_rdd.rdd_data.rdd2_snr(k, :) .* 2^23;        %     s8p23_T
   fwrite(fileID, rdd2_snr, 'int32');
   fwrite(fileID, log_rdd.rdd_data.bwdep_cr_resp(k, :), 'uint32');
   fwrite(fileID, log_rdd.rdd_data.bwdep_sensitivity_thold(k, :), 'uint32');
   fwrite(fileID, log_rdd.rdd_data.af_sensitivity_thold(k, :), 'uint32');
   fwrite(fileID, log_rdd.rdd_data.bwdep_hvc_thold (k, :), 'uint32');
   fwrite(fileID, log_rdd.rdd_data.bwdep_mb_thold(k, :), 'uint32');
   fwrite(fileID, log_rdd.rdd_data.cfar_thold(k, :), 'uint32');
   fwrite(fileID, log_rdd.rdd_data.rdd1_bv(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.cfar_nf_est(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_max_per_range_bin(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_signal_thold_first_pass(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_first_pass_thold(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.nci_bexp(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_rdop_amp(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_rindx(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_dindx(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_aindx(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd1_num_detect(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd2_num_detect(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.K_Unused16_1(k, :), 'uint16');
   fwrite(fileID, log_rdd.rdd_data.rdd2_sp_fail_flag(k, :), 'uint8');
   fwrite(fileID, log_rdd.rdd_data.below_sp_thold(k, :), 'uint8');
   fwrite(fileID, log_rdd.rdd_data.below_zdb_thold(k, :), 'uint8');
   fwrite(fileID, log_rdd.rdd_data.below_hvc_thold(k, :), 'uint8');
   fwrite(fileID, log_rdd.rdd_data.min_chirp_scaling(k, :), 'uint8');
   fwrite(fileID, log_rdd.rdd_data.rdd1_neighbor_det_flag(k, :), 'uint8');
   fwrite(fileID, log_rdd.rdd_data.K_Unused8_1(k, :), 'uint8');
end
fclose(fileID);

%%%%%%%%%%% Generates-Look data-Bin-File%%%%%%%%%%%
fileID = fopen('look_data_input.bin', 'w');
end_index = index_to_be_tested;
for k = index_to_be_tested:end_index
   fwrite(fileID, log_rdd.look_data.start_dwell_nanosec(k, :), 'uint32');
   fwrite(fileID, log_rdd.look_data.start_dwell_sec(k, :), 'uint32');
   fwrite(fileID, log_rdd.look_data.end_dwell_nanosec(k, :), 'uint32');
   fwrite(fileID, log_rdd.look_data.end_dwell_sec(k, :), 'uint32');
   fwrite(fileID, log_rdd.look_data.mid_dwell_nanosec(k, :), 'uint32');
   fwrite(fileID, log_rdd.look_data.mid_dwell_sec(k, :), 'uint32');
   fwrite(fileID, log_rdd.look_data.look_id(k, :), 'uint16');
   fwrite(fileID, log_rdd.look_data.scan_type(k, :), 'uint16');
   fwrite(fileID, log_rdd.look_data.look_index(k, :), 'uint16');
   fwrite(fileID, log_rdd.look_data.scan_index(k, :), 'uint16');
   fwrite(fileID, log_rdd.look_data.start_dwell_status(k, :), 'uint8');
   fwrite(fileID, log_rdd.look_data.end_dwell_status(k, :), 'uint8');
   fwrite(fileID, log_rdd.look_data.mid_dwell_status(k, :), 'uint8');
   fwrite(fileID, log_rdd.look_data.K_Unused8_1(k, :), 'uint8');
end
fclose(fileID);
%%%%%%%%%%% Generates STREAM Hdr bin file%%%%%%%%%%%
fileID = fopen('stream_hdr.bin', 'w');
end_index = index_to_be_tested;
for k = index_to_be_tested:end_index
   fwrite(fileID, log_rdd.stream_hdr.size(k), 'uint32');
   fwrite(fileID, log_rdd.stream_hdr.version(k), 'uint16');
   fwrite(fileID, log_rdd.stream_hdr.checksum(k), 'uint16');
   fwrite(fileID, log_rdd.stream_hdr.scan_index(k), 'uint16');
   fwrite(fileID, log_rdd.stream_hdr.error_info(k), 'uint16');
   fwrite(fileID, log_rdd.stream_hdr.module_time_ms(k), 'uint32');
end
fclose(fileID);

% This rdd_stream_input.bin is used for AF_SIL testing
%%%%%%%%%%% Generates-RDD-Stream-Bin-File%%%%%%%%%%%

% Always check the sync of RDD and CDC stream indices%
if AF_BIN_FILE_GENERATION
   fileID = fopen('rdd_stream_input.bin', 'w');
   end_index = index_to_be_tested;
   avg_temp = zeros(1, end_index);
   for k = index_to_be_tested:end_index

      %%%%%%%%%%%%%%%% stream_hdr data %%%%%%%%%%%%%%%%
      fwrite(fileID, log_rdd.stream_hdr.size(k), 'uint32');
      fwrite(fileID, log_rdd.stream_hdr.version(k), 'uint16');
      fwrite(fileID, log_rdd.stream_hdr.checksum(k), 'uint16');
      fwrite(fileID, log_rdd.stream_hdr.scan_index(k), 'uint16');
      fwrite(fileID, log_rdd.stream_hdr.error_info(k), 'uint16');
      fwrite(fileID, log_rdd.stream_hdr.module_time_ms(k), 'uint32');

      %%%%%%%%%%%%%%%% look data %%%%%%%%%%%%%%%%

      fwrite(fileID, log_rdd.look_data.start_dwell_nanosec(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.start_dwell_sec(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.end_dwell_nanosec(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.end_dwell_sec(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.mid_dwell_nanosec(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.mid_dwell_sec(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.look_id(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.scan_type(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.scan_index(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.look_index(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.start_dwell_status(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.end_dwell_status(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.mid_dwell_status(k, :), 'uint16');
      fwrite(fileID, log_rdd.look_data.K_Unused8_1(k, :), 'uint16');
      %%%%%%%%%%%%%%%% RDD data %%%%%%%%%%%%%%%%
      fwrite(fileID, log_rdd.rdd_data.cfar_corr_coeff(k, :), 'float32');
      fixed_rbinest = log_rdd.rdd_data.rdd1_rbinest(k, :) .* 2^21; % s10p21_T
      fwrite(fileID, fixed_rbinest, 'int32');
      fixed_dbinest = log_rdd.rdd_data.rdd1_dbinest(k, :) .* 2^21; % s10p21_T
      fwrite(fileID, fixed_dbinest, 'int32');
      fixed_abinest = log_rdd.rdd_data.rdd1_abinest(k, :) .* 2^21; % s10p21_T
      fwrite(fileID, fixed_abinest, 'int32');
      fwrite(fileID, log_rdd.rdd_data.rdd2_thold_2nd_pass(k, :), 'uint32');
      rdd2_range = log_rdd.rdd_data.rdd2_range(k, :) .* 2^21; %     s10p21_T
      fwrite(fileID, rdd2_range, 'int32');
      rdd2_range_rate = log_rdd.rdd_data.rdd2_range_rate(k, :) .* 2^21; % s10p21_T
      fwrite(fileID, rdd2_range_rate, 'int32');
      rdd2_snr = log_rdd.rdd_data.rdd2_snr(k, :) .* 2^23;        %     s8p23_T
      fwrite(fileID, rdd2_snr, 'int32');
      fwrite(fileID, log_rdd.rdd_data.bwdep_cr_resp(k, :), 'uint32');
      fwrite(fileID, log_rdd.rdd_data.bwdep_sensitivity_thold(k, :), 'uint32');
      fwrite(fileID, log_rdd.rdd_data.af_sensitivity_thold(k, :), 'uint32');
      fwrite(fileID, log_rdd.rdd_data.bwdep_hvc_thold (k, :), 'uint32');
      fwrite(fileID, log_rdd.rdd_data.bwdep_mb_thold(k, :), 'uint32');
      fwrite(fileID, log_rdd.rdd_data.cfar_thold(k, :), 'uint32');
      fwrite(fileID, log_rdd.rdd_data.rdd1_bv(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.cfar_nf_est(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_max_per_range_bin(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_signal_thold_first_pass(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_first_pass_thold(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.nci_bexp(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_rdop_amp(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_rindx(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_dindx(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_aindx(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd1_num_detect(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd2_num_detect(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.K_Unused16_1(k, :), 'uint16');
      fwrite(fileID, log_rdd.rdd_data.rdd2_sp_fail_flag(k, :), 'uint8');
      fwrite(fileID, log_rdd.rdd_data.below_sp_thold(k, :), 'uint8');
      fwrite(fileID, log_rdd.rdd_data.min_chirp_scaling(k, :), 'uint8');
      fwrite(fileID, log_rdd.rdd_data.rdd1_neighbor_det_flag(k, :), 'uint8');
      fwrite(fileID, log_rdd.rdd_data.K_Unused8_1(k, :), 'uint8');

      %%%%%%%%%%%%%%%% Rfft data %%%%%%%%%%%%%%%%
      fwrite(fileID, log_rdd.rfft_data.first_interfered_chirp(k, :), 'int16');
      fwrite(fileID, log_rdd.rfft_data.gating_window(k, :), 'int16');
      fwrite(fileID, log_rdd.rfft_data.idm_cfar_thold(k, :), 'uint16');
      fwrite(fileID, log_rdd.rfft_data.interfered_samples_per_chirp(k, :), 'uint16');
      fwrite(fileID, log_rdd.rfft_data.idm_first_chirp_idx(k), 'uint16');
      fwrite(fileID, log_rdd.rfft_data.K_Unused16_1(k), 'uint16'); % do we need this ?

   end
   fclose(fileID);
end
