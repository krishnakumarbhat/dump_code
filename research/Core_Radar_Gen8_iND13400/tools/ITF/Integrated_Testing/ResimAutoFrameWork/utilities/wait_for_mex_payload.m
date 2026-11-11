% wait_for_mex_payload.m
% Helper: waits for a variable to appear in the base workspace with a timeout.
% If the variable holds a payload, returns the payload; for boolean flags, returns logical.
% Usage:
%   val = wait_for_mex_payload('RunTest_rfft_ready', 600);
%   payload = wait_for_mex_payload('RunTest_post_mipi_payload', 300);
%
% Inputs:
%   varName     - Name of the variable to watch in base workspace (char/string)
%   timeoutSec  - Timeout in seconds (numeric)
%
% Output:
%   val         - The value of the variable when present and non-empty; empty [] if timed out
%
function val = wait_for_mex_payload(varName, timeoutSec)
   startT = tic;
   val = [];
   while true
      if evalin('base', sprintf('exist(''%s'',''var'')', varName))
         val = evalin('base', varName);
         % Proceed when variable exists and is non-empty (for payloads);
         % for logical flags, accept true/false (non-empty numeric/logical)
         if ~isempty(val) || islogical(val) || isnumeric(val)
            break
         end
      end
      pause(0.5);
      if toc(startT) > timeoutSec
         error('[Async##Warn] Timeout waiting for %s.\n', varName);
         break
      end
   end
end
