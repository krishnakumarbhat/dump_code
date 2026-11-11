%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: errorCheck
%   Check for function call errors.
%
% Return Variables:
%   none
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [error] = errorCheck(t32lib, name, status, disable_print)
   error = status ~= 0;
   if ~exist('disable_print', 'var')
      % third parameter does not exist, so default it to something
      disable_print = 0;
   end

   if disable_print == 0 && error
      fprintf(2, '\n%s command failed...\n\n', name);
   end
end
