%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name:  T32_Exit()
%   This function ends the connection to the TRACE32 display driver. This
%   command should always be called before ending the application.
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [] = t32_exit(t32lib, close)

   if ~close
      fprintf('\nClosing...\n');
      t32_terminate(t32lib);
   end
   status = calllib(t32lib, 'T32_Exit');
   unloadlibrary(t32lib);
   errorCheck(t32lib, 'T32_Exit', status);
   fprintf('Finished TRACE32!\n');

end
