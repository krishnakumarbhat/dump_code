%
% @Description : load .mat file decoded from parsing vehicle log in this
% file and generate a bin file which has operation mode and data qualifier
% inside header stream and TOI stream/TOI DS stream respectively from
% vehicle log in binary format
%
% ------------------------------------------------------------------------
%
%  Copyright (C) 2024 Aptiv. All rights reserved.
%  Aptiv Sensitve Business : Restricted Aptiv information. Do not disclose
%
% ------------------------------------------------------------------------
%
% =======================================================================*/

% clear workspace
clc;
close all;

% give appropriate path to .mat file which has decoded log info
data = load("C:\Users\uf0l00\Downloads\pcap_bench_log.mat");

% after loading data, update following script base on sensor number and stream version based on log
% file is loaded into such as pcap, mudp, mf4, brr

% creates a file named "da_input.bin" in the same path as this .mat
% file
fileID = fopen("da_input.bin", "w");

% read and write sensor_mount_ornt_yaw from status stream
yaw = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_ornt_yaw;
fwrite(fileID, yaw(1), "float32");

% read and write sensor_mount_ornt_yaw from status stream
pitch = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_ornt_pitch;
fwrite(fileID, pitch(1), "float32");

% read and write sensor_mount_ornt_yaw from status stream
roll = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_ornt_roll;
fwrite(fileID, roll(1), "float32");

% read and write sensor_mount_ornt_yaw from status stream
pos_x = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_pos_x;
fwrite(fileID, pos_x(1), "float32");

% read and write sensor_mount_ornt_yaw from status stream
pos_y = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_pos_y;
fwrite(fileID, pos_y(1), "float32");

% read and write sensor_mount_ornt_yaw from status stream
pos_z = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_pos_z;
fwrite(fileID, pos_z(1), "float32");

% read and write sensor_mount_ornt_yaw from status stream
mount_location = data.pcap.Sensor_1_SRR7P_V2.Stream_3_Version_1.sensor_mount_location;
fwrite(fileID, mount_location(1), "uint8");

fclose(fileID);

% =========================================================================
% FILE REVISION HISTORY - To be filled by the project team
% -------------------------------------------------------------------------
%
% REVISION         AID               SUMMARY OF CHANGES
% -------------------------------------------------------------------------
%      1        Keerthana Raju        First version
%
% -------------------------------------------------------------------------
% =========================================================================

% END OF FILE ------------------------------------------------------------%
