%% %%%%%%%%%%%%%%%% API for Wait for power cycle %%%%%%%%%%%%%%%%%%%%
% Name: wait_for_powercycle()
%   Function waits 20 seconds to allow powercycle of the unit.
%   Pressing enter allows early exit.
%   Otherwise, function aborts the ITF run.
%
% INPUTS:
%   None
% OUTPUTS:
%   None
function wait_for_powercycle(timeout)

   if ~exist('timeout', 'var')
      timeout = 5;
   end

   t = timer('StartDelay', timeout, 'TimerFcn', @timeFunc);
   prompt_wrap = '*************************************************';
   fprintf('\n%s\n  Press enter to confirm power cycle complete..  \n%s\n', prompt_wrap, prompt_wrap);
   start(t);
   response = input('', 's');
   stop(t);
   delete(t);

   if ~isempty(response) && strcmp(response, '1')
      warning('Running without confirmed power cycle');
   end
end

function timeFunc(~, ~)
   robot = java.awt.Robot;
   robot.keyPress(java.awt.event.KeyEvent.VK_1);
   robot.keyRelease(java.awt.event.KeyEvent.VK_1);
   robot.keyPress(java.awt.event.KeyEvent.VK_ENTER);
   robot.keyRelease(java.awt.event.KeyEvent.VK_ENTER);
end
