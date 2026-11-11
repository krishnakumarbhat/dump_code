%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: t32_read_mem()
%   Read data from target memory. The size of the data block is not limited.
%   This function should be used to access variables and make other not time
%   critical memory reads.
%   -------------------------------access---------------------------------%
%   access: memory access specifier
%   Bit 0-4 Memory class, see "Conventions for Target Memory Access"
%   Bit 6 Set for emulation memory access (dual port access)
%   Bit 7 Set to enable verify after write
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% T32EXTERN int  T32_ReadMemory     (uint32_t Address, int Access, uint8_t *pBuffer, int Size);
function [status, buffer] = t32_read_mem(t32lib, symbolName, disable_print)

   if ~exist('disable_print', 'var')
      disable_print = 0;
   end

   buffer = 0;

   [address, symbolSize, status] = t32_get_symbol(t32lib, symbolName);
   access = hex2dec('c0');
   if status == 0
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
end
