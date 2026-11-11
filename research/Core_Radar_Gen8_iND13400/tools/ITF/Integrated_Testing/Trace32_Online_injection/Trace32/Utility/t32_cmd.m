%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: t32_cmd
%   Passes TRACE32 command to TRACE32 for execution. Any valid TRACE32
%   is allowed, including the start of a *.cmm script via the DO command
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% T32EXTERN int  T32_Cmd(const char *Command);

function [status] = t32_cmd(t32lib, command, num_tries)

   if ~exist('num_tries', 'var')
      num_tries = 1;
   end

   if num_tries < 1
      num_tries = 1;
   end

   status = 1; % Set status to non-zero for while loop
   while num_tries > 0 && status ~= 0
      status = calllib(t32lib, 'T32_Cmd', command);
      num_tries = num_tries - 1;
   end

end
