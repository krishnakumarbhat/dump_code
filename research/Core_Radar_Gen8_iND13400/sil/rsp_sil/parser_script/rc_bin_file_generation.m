clear all;
close all;
clc;
% Load the mat file which has the different stream data(rdd, cdc , status stream)
% This need to generated using MATLAB Parsing scripts with pacap logs as input
load('UDP_normal.mat');

% generating the RC Input bin file.

fileID = fopen('rc_input.bin', 'w');
log_data = pcap.Sensor_1_Unknown_Sensor.Stream_20_Version_39;
index_to_be_tested = 1;
end_index = index_to_be_tested;
avg_temp = zeros(1, end_index);
for k = index_to_be_tested:end_index
   fwrite(fileID, log_data.avg_mmic_onchip_temp(k), 'int16');
end
fclose(fileID);
