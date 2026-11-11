%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: initialize_trace32(workingDirectory)
%   This command attaches to open instances of T32, and kills them, then
%   starts a new instance. Waits up to 5 seconds for the attach to happen
%   and if unable to attach sets an error.
%
% Return Variables:
%   N/A
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function t32lib = initialize_trace32(workingDirectory)
   fprintf("STARTING TRACE32 PLEASE WAIT\n");

   % Connect to and kill any open instances of the ARM T32.
   t32lib = t32_config();
   t32_init(t32lib);
   t32_exit(t32lib, 0);

   startPowerviewScript = '\_start_powerview_itf.bat';
   cmdString = strcat(workingDirectory, startPowerviewScript);
   system(cmdString);

   fprintf("Connecting to the T32 instance.\n");

   t32lib = t32_config();
   status = t32_init(t32lib);
   if status
      error("Failed to attach to the instance.");
   else
      fprintf("Successfully connected to the Trace32 instance\n");
   end
end
