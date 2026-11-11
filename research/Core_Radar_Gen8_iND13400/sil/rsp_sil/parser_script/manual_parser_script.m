% version 5.2 FLR8 Manual Parser Script to generate output.mat
%% STEPS To Generate output.mat
% Step 1: Update the pcapFilePath for the input bin need to be generate.
% Step 2:Build Gen8 application repo  that used to capture Pcap
%      Copy the streamdefs folder from Gen8 workspace.And Update path here.
% Step 3: Keep a break point at line no 435 in read_pcap_data.m
% " fprintf('Success!\n');" and Run to update output variable from Stream1
% to stream 14
% Till get msg in command window
% "Attempting to parse source 72 stream 14 version 0 for sensor 1.Success!"
% Save output variable as output.mat
% save("output.mat","output");
%%
clear all;
close all;
clc;
pcap = struct();
sourceID = 205; % As per the sensor
sensortext = 'FLR8';
pcapFilePath = "C:\Users\fjh4j4\wkspaces\Gen8_SIL_PCAP\ITC5SE501A-output5.pcap"; % it is a local file path
Streamdefinition_Files = 'C:\Users\fjh4j4\wkspaces\Core_Radar_Gen8_iND13400\bazel-bin\outputs\flr8\streamdefs'; % it is a local file path
pcap = read_pcap_data(pcapFilePath, Streamdefinition_Files);
