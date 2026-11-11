% status = t32_wait_for_bbe_breakpoint(t32lib, timeout_in_secs, disable_print)
%   Call CMM script to wait for BBE to hit a breakpoint
%
% INPUTS:
%   t32_lib
%   timeout_in_secs - Time to wait for breakpoint
%   disable_print     - set non-zero to disable print statements
% OUTPUTS:
%   status - 0 for success, non-zero for error
function status = t32_wait_for_bbe_breakpoint(t32lib, timeout_in_secs, disable_print)

   if ~exist('disable_print', 'var')
      disable_print = 0;
   end

   seconds_to_wait = 0.05; % Check every second for script completion
   retry_count = timeout_in_secs / seconds_to_wait;
   wait_command = sprintf('DO %s.cmm', mfilename('fullpath'));
   status = run_cmm_script(t32lib, wait_command, seconds_to_wait, retry_count, disable_print);
end
