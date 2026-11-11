%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: reset_core()
%   Send the reset sequence.
%
% Return Variables:
%   N/A
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [] = reset_core(t32lib)
   % This is the reset process to restart the board.
   t32_cmd(t32lib, 'System.ResetTarget', 1);
   t32_cmd(t32lib, 'System.Mode.Prepare', 1);
   t32_cmd(t32lib, 'System.Mode.Attach', 1);
end
