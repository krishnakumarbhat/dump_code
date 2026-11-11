clc;
clear all;
close all;

%% Enable to print thresholds corresponding to detection range bins only
load('vehicle_log_v5.1.1.mat');
index_to_be_tested = 20; % The particlar index in the log will be used for

sensor_type = 'FLR8'; % Sensor type
workbook_path = ['.\workbook\', sensor_type];

cd("..\..\..\tools\ITF\Integrated_Testing\ResimAutoFrameWork");
download_smc_usc(workbook_path, sensor_type);

%%
addpath(workbook_path);
smc_info = dir(fullfile([workbook_path, '\smc_cal*.mat']));
load(smc_info.name);
usc_info = dir(fullfile([workbook_path, '\usc_cal*.mat']));
load(usc_info.name);

cd("..\..\..\..\sil\rsp_sil\parser_script");

log_rdd = Log_00001.Sensor_5_FLR8.Stream_4;

% get the look id from log
look = log_rdd.look_data.look_id(index_to_be_tested) + 1;

[SMC, USC] = Update_smc_usc_params(smc_cal, usc_cal.USC.Signal_Calibrations, look);
RANGE_BINS = smc_cal.Configuration.BB_Configuration.MAX_RANGE_BINS.VALUE;
ANGLE_BINS = smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE;
NUM_VIRTUAL_ANTENNA = (smc_cal.Configuration.BB_Configuration.NUM_RX_ANTENNAS.VALUE * smc_cal.Configuration.BB_Configuration.NUM_TX_CHANNELS.VALUE);
rdd1_num_detect = log_rdd.rdd_data.rdd1_num_detect(index_to_be_tested);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Print rdd outputs in text file
num_detect = log_rdd.rdd_data.rdd1_num_detect(index_to_be_tested);
file_id = fopen('rdd_bv_emb.txt', 'w');
for i = 1:num_detect * NUM_VIRTUAL_ANTENNA
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_bv(index_to_be_tested, i));
   if mod(i, 32) == 0
      fprintf(file_id, "\n");
   end
end
fclose(file_id);

file_id = fopen('rdd_thr_emb.txt', 'w');
fprintf(file_id, "cr_resp ");
for i = 1:RANGE_BINS
   fprintf(file_id, "%d ", log_rdd.rdd_data.bwdep_cr_resp(index_to_be_tested, i));
end
fprintf(file_id, "\n");
fprintf(file_id, "sens_thold ");
for i = 1:RANGE_BINS
   fprintf(file_id, "%d ", log_rdd.rdd_data.bwdep_sensitivity_thold(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "bwdep_hvc_thold ");
for i = 1:RANGE_BINS
   fprintf(file_id, "%d ", log_rdd.rdd_data.bwdep_hvc_thold(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "bwdep_mb_thold ");
for i = 1:RANGE_BINS
   fprintf(file_id, "%d ", log_rdd.rdd_data.bwdep_mb_thold(index_to_be_tested, i));
end
fprintf(file_id, "\n");

fprintf(file_id, "max_per_range_bin ");
for i = 1:RANGE_BINS
   for j = 1:ANGLE_BINS
      fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_max_per_range_bin(index_to_be_tested, (i - 1) * ANGLE_BINS + j));
   end
end
fprintf(file_id, "\n");

fprintf(file_id, "Sig_Thold_FP ");
for i = 1:RANGE_BINS
   for j = 1:ANGLE_BINS
      fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_signal_thold_first_pass(index_to_be_tested, (i - 1) * ANGLE_BINS + j));
   end
end
fprintf(file_id, "\n");

fprintf(file_id, "FP_Thold ");
for i = 1:RANGE_BINS
   for j = 1:ANGLE_BINS
      fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_first_pass_thold(index_to_be_tested, (i - 1) * ANGLE_BINS + j));
   end
end
fprintf(file_id, "\n");

fprintf(file_id, "rdd2_thold_2nd_pass ");
for i = 1:RANGE_BINS
   for j = 1:ANGLE_BINS
      fprintf(file_id, "%d ", log_rdd.rdd_data.rdd2_thold_2nd_pass(index_to_be_tested, (i - 1) * ANGLE_BINS + j));
   end
end
fprintf(file_id, "\n");

file_id = fopen('rdd_out_emb.txt', 'w');
fprintf(file_id, "rdd1_num_detect ");
rdd1_num_detect = log_rdd.rdd_data.rdd1_num_detect(index_to_be_tested);
fprintf(file_id, "%d ", rdd1_num_detect);
fprintf(file_id, "\n");
fprintf(file_id, "rindx ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_rindx(index_to_be_tested, i));
end
fprintf(file_id, "\n");
fprintf(file_id, "dindx ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_dindx(index_to_be_tested, i));
end

fprintf(file_id, "\n");
fprintf(file_id, "aindx ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_aindx(index_to_be_tested, i));
end

fprintf(file_id, "\n");
fprintf(file_id, "rdop_amp ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_rdop_amp(index_to_be_tested, i));
end
fprintf(file_id, "\n");
fprintf(file_id, "rbinest ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_rbinest(index_to_be_tested, i) * 2^21);
end
fprintf(file_id, "\n");
fprintf(file_id, "dbinest ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_dbinest(index_to_be_tested, i) * 2^21);
end
fprintf(file_id, "\n");

fprintf(file_id, "abinest ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd1_abinest(index_to_be_tested, i) * 2^21);
end
fprintf(file_id, "\n");

%%%%%%%%% RDD Second Pass %%%%%%%%%%%%%%%
fprintf(file_id, "rdd2_num_detect ");
rdd2_num_detect = log_rdd.rdd_data.rdd2_num_detect(index_to_be_tested);
fprintf(file_id, "%d ", rdd2_num_detect);
fprintf(file_id, "\n");

fprintf(file_id, "rdd2_range ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd2_range(index_to_be_tested, i) * 2^21);
end
fprintf(file_id, "\n");

fprintf(file_id, "rdd2_range_rate ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd2_range_rate(index_to_be_tested, i) * 2^21);
end
fprintf(file_id, "\n");

fprintf(file_id, "rdd2_snr ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd2_snr(index_to_be_tested, i) * 2^23);
end
fprintf(file_id, "\n");

fprintf(file_id, "rdd2_sp_fail_flag ");
for i = 1:rdd1_num_detect
   fprintf(file_id, "%d ", log_rdd.rdd_data.rdd2_sp_fail_flag(index_to_be_tested, i));
end
fprintf(file_id, "\n");

%% commenting this because it can be used for AF testing%%
%%%%%%%%% PRINT AF Detection Outputs %%%%%%%%%%
m = log_rdd.stream_hdr.scan_index(index_to_be_tested);
log_detection_stream = output.Sensor_1_Unknown_Sensor.Stream_1_Version_5;
af_scan_index = log_detection_stream.stream_hdr.scan_index;

index_to_be_tested = find(af_scan_index == m);

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
%    fprintf(file_id, "%d, ", log_detection_stream.af_data.f_bistatic(index_to_be_tested, i));
% end
% fprintf(file_id, "\n");
%
% fclose(file_id);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
