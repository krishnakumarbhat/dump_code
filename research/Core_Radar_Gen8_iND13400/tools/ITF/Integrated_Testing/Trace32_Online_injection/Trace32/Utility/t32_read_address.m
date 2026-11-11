%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: t32_read_address()
%   Read data from a specified memory address. The size of the data block is not limited.
%
%   -------------------------------access---------------------------------%
%   access: memory access specifier
%   Bit 0-4 Memory class, see "Conventions for Target Memory Access"
%   Bit 6 Set for emulation memory access (dual port access)
%   Bit 7 Set to enable verify after write
%
% Inputs
%   t32lib - T32 library reference
%   address - Base address to read
%   symbolSize - Size of data to read (bytes)
%   disable_print (optional) - Set to 1 to disable - prints enabled by default
%
% Outputs
%   status - 0 for success, otherwise failure
%   buffer - Data read from memory - will be 8 bit values, needs to be typecasted
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% T32EXTERN int  T32_ReadMemory     (uint32_t Address, int Access, uint8_t *pBuffer, int Size);
function [status, buffer] = t32_read_address(t32lib, address, symbolSize, disable_print)

   if ~exist('disable_print', 'var')
      disable_print = 0;
   end

   buffer = 0;

   access = hex2dec('c0');
   ptr = libpointer('uint8Ptr', zeros(symbolSize, 1, 'uint8'));

   tic; % start timer
   status = calllib(t32lib, 'T32_ReadMemory', address, access, ptr, symbolSize);
   timer = toc; % stop timer

   if disable_print == 0
      fprintf('RDAR Read Finished in %3.3f seconds.\n', timer);
   end
   errorCheck(t32lib, 'T32_ReadMemory', status);
   if status == 0
      buffer = ptr.Value;
   end

end
