clc;
clear all;
close all;
% Read the data:
fid = fopen('rdd_out_sil.txt', 'rt');
rdd_out_sil = textscan(fid, '%s%[^\n]');
fclose(fid);
rdd_out_sil = [rdd_out_sil{:}];
% % Convert to numeric:
rdd1_num_detect_sil = sscanf(rdd_out_sil{1, 2}, '%d');
rindx_sil = sscanf(rdd_out_sil{2, 2}, '%d');
dindx_sil = sscanf(rdd_out_sil{3, 2}, '%d');
rdop_amp_sil = sscanf(rdd_out_sil{4, 2}, '%d');
rbinest_sil = sscanf(rdd_out_sil{5, 2}, '%d');
dbinest_sil = sscanf(rdd_out_sil{6, 2}, '%d');
num_detect_sil = sscanf(rdd_out_sil{7, 2}, '%d');
rdd2_range_sil = sscanf(rdd_out_sil{8, 2}, '%d');
rdd2_range_sil = rdd2_range_sil / (2^21);
rdd2_range_rate_sil = sscanf(rdd_out_sil{9, 2}, '%d');
rdd2_range_rate_sil = rdd2_range_rate_sil / (2^21);
rdd2_snr_sil = sscanf(rdd_out_sil{10, 2}, '%d');

% Read the data:
fid = fopen('rdd_out_emb.txt', 'rt');
rdd_out_emb = textscan(fid, '%s%[^\n]');
fclose(fid);
rdd_out_emb = [rdd_out_emb{:}];
% % Convert to numeric:
rdd1_num_detect_emb = sscanf(rdd_out_emb{1, 2}, '%d');
rindx_emb = sscanf(rdd_out_emb{2, 2}, '%d');
dindx_emb = sscanf(rdd_out_emb{3, 2}, '%d');
rdop_amp_emb = sscanf(rdd_out_emb{4, 2}, '%d');
rbinest_emb = sscanf(rdd_out_emb{5, 2}, '%d');
dbinest_emb = sscanf(rdd_out_emb{6, 2}, '%d');
num_detect_emb = sscanf(rdd_out_emb{7, 2}, '%d');
rdd2_range_emb = sscanf(rdd_out_emb{8, 2}, '%d');
rdd2_range_emb = rdd2_range_emb / (2^21);
rdd2_range_rate_emb = sscanf(rdd_out_emb{9, 2}, '%d');
rdd2_range_rate_emb = rdd2_range_rate_emb / (2^21);
rdd2_snr_emb = sscanf(rdd_out_emb{10, 2}, '%d');

%% Deviation
rdd2_num_detect_dev = num_detect_emb - num_detect_sil;
rindx_dev = abs(rindx_emb - rindx_sil)';
dindx_dev = abs(dindx_emb - dindx_sil)';
rdop_amp_dev = (abs(20 * log10(rdop_amp_emb) - 20 * log10(rdop_amp_sil)))';
rbinest_dev = (abs((rbinest_emb / (2^21)) - (rbinest_sil / (2^21))))';
dbinest_dev = (abs((dbinest_emb / (2^21)) - (dbinest_sil / (2^21))))';
rdd2_range_dev = abs(rdd2_range_emb - rdd2_range_sil);
rdd2_range_rate_dev = abs(rdd2_range_rate_emb - rdd2_range_rate_sil);
rdd2_snr_dev = abs(20 * log10(rdd2_snr_emb) - 20 * log10(rdd2_snr_sil));
clearvars rdd_out_emb  rdd_out_sil rindx_emb dindx_emb rdop_amp_emb rbinest_emb dbinest_emb rdd2_range_emb rdd2_range_rate_emb rdd2_snr_emb rindx_sil dindx_sil rdop_amp_sil rbinest_sil dbinest_sil rdd2_range_sil rdd2_range_rate_sil rdd2_snr_sil;
