%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: t32_config()
%   This function configs the communication driver of the API.
%   -NODE, PACKLEN, PORT, TIMEOUT, HOSTPORT
%
% Return Variables:
%   t32lib: TRACE32 Remote API DLL
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [t32lib] = t32_config()

   %                                          ISPC ISUNIX ISMAC ARCHSTR
   % 64-Bit Platforms
   %  PCWIN64  - Microsoft Windows on x64      1     0     0   win64
   %  GLNXA64  - Linux on x86_64               0     1     0   glnxa64
   %  MACI64   - Apple Mac OS X on x86_64      0     1     1   maci64

   if strcmp(computer, 'PCWIN64')
      t32lib = 't32api64';
   elseif strcmp(computer, 'PCWIN')
      t32lib = 't32api';
   end

   if not(libisloaded(t32lib))

      loadlibrary(t32lib, 't32.h'); % Load TRACE32 Remote API DLL
   end

   % libfunctions(t32lib,'-full') %lists all dll functions

   % Defines on which host the TRACE32 display drivers runs
   status = calllib(t32lib, 'T32_Config', 'NODE=', 'localhost');
   errorCheck(t32lib, 'T32_WriteVariableValue', status);

   % PACKLEN = 1024 (maximum data package length)
   % Enables and allows form API remote control configuration
   status = calllib(t32lib, 'T32_Config', 'PACKLEN=', '1024');
   errorCheck(t32lib, 'T32_Config', status);

   % Defines the UDP port for communciating with API
   % change port to 20001 for SMP trace32 instance
   status = calllib(t32lib, 'T32_Config', 'PORT=', '20000'); % default Port is 20000
   errorCheck(t32lib, 'T32_Config', status);

end
