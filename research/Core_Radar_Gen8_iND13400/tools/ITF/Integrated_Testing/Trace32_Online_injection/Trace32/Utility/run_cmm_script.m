% [timeout] = run_cmm_script(t32lib, script_name, wait_time_in_secs, retry_count, disable_print)
%   Run a CMM script and wait for completion
%
%   Total time for wait is wait_time_in_secs * retry_count.
%
% Inputs:
%   t32lib            - Trace32 instance
%   script_name       - Name of the CMM script to run
%   wait_time_in_secs - Wait time between script status requests
%   retry_count       - Number of attempts
%   disable_print     - set non-zero to disable print statements
%
% Return Variables:
%   timeout - Set to 1 if the script never returns successful completion.
function [timeout] = run_cmm_script(t32lib, script_name, wait_time_in_secs, retry_count, disable_print)

   if ~exist('disable_print', 'var')
      disable_print = 0;
   end

   disable_practice_print = 1;
   state = t32_cmd(t32lib, script_name);

   if state == 0
      if disable_print ~= 0
         fprintf("Running Command: %s\n", script_name);
      end
      state = t32_get_practice_state(t32lib, disable_practice_print);
      count = 0;
      while state ~= 0 && count < retry_count
         pause(wait_time_in_secs);
         state = t32_get_practice_state(t32lib, disable_practice_print);

         if state ~= 0
            count = count + 1;
            if disable_print ~= 0
               fprintf(' %d of %d seconds elapsed\n', count * wait_time_in_secs, wait_time_in_secs * retry_count);
            end
         end
      end
   end

   if state == 0  % script is not running
      if disable_print ~= 0
         fprintf(" Finished Script.\n");
      end
      timeout = 0;
   else
      if disable_print ~= 0
         fprintf(2, " Script timed out.\n");
      end
      timeout = 1;
   end
end
