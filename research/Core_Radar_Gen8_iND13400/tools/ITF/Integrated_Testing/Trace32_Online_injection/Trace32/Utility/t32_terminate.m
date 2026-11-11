%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: T32_Terminate()
%   This function terminates the connected TRACE32 instance.
%
% Return Variables:
%   0 for ok, otherwise Error value
%   retval: TRACE32 instance returns this value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [] = t32_terminate(t32lib)

   retval = uint32(0);
   t32_cmd(t32lib, 'Intercom BBE32 quit');
   status = calllib(t32lib, 'T32_Terminate', retval);
   % errorCheck(t32lib, 'T32_Terminate', status)

end
