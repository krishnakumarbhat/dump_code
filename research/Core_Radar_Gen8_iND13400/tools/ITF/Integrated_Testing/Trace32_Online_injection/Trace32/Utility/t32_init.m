%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: t32_init()
%   This function initializes the driver and establishes the connection to
%   the TRACE32 display driver.
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [error] = t32_init(t32lib)

   status = calllib(t32lib, 'T32_Init');
   error = errorCheck(t32lib, 'T32_Init', status);

   if error == 0
      status = calllib(t32lib, 'T32_Attach', 1);
      error = errorCheck(t32lib, 'T32_Attach', status);
   end

end
