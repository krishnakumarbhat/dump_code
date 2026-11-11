%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: flash_and_start(t32lib, smcFileName, uscFileName, hexpath, M7Elfpath, BBEElfpath)
%   Flash the device with the specified files.
%
%   Will wait up to 200 seconds for initial setup of Trace32 to complete.
%   Will wait up to 200 seconds for flashing to complete.
%   Will wait up to 10 seconds for Trace32 layout of ARM core.
%   Will wait up to 10 seconds for start of application.
%
% Inputs:
%   t32lib Trace32 instance
%   parentDirectory - for specifying the path
%   Sensor_path - for variant
% Return Variables:
%   N/A
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status] = flash_and_start(t32lib, parentDirectory, sensor_type)
   filename = sprintf("%s\\%s_config.cmm", parentDirectory, sensor_type);
   if ~exist(filename, "file")
      error("Missing the CMM script %s for loading this variant.", filename);
   end

   seconds_to_wait = 5;
   times_to_try = 40;

   % ; Execute flash script
   flash_command = sprintf('DO start_powerview.cmm CPU=ind13400 R52 BBE32 USER_CONFIG=%s', filename);
   status = run_cmm_script(t32lib, flash_command, seconds_to_wait, times_to_try);
   seconds_to_wait = 1;
end
