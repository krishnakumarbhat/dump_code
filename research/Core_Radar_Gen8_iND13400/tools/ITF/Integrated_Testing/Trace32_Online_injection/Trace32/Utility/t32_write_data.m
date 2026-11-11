% [status] = t32_write_data(t32lib, symbolName, data, disable_print)
%   This Function writes data to target memory. The size of the data
%   block is not limited.
%
% access: memory access specifier
%   Bit 6 Set for emulation memory access (dual port access)
%   Bit 7 Set to enable verify after write
%
% Return Variables:
%   N/A
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status] = t32_write_data(t32lib, symbolName, data, disable_print)

   if ~exist('disable_print', 'var')
      disable_print = 0;
   end

   % get address and size of symbol
   [address, symbolSize] = t32_get_symbol(t32lib, symbolName);

   % data is uint8 buffer in flattened 1 Dimension
   sample_size = size(data, 1);  % 420*1020*size(uint32)

   % access specifier
   access = hex2dec('40');

   if disable_print == 0
      fprintf('Writing data to %s...\n', symbolName);
      tic; % start timer
   end

   %% write data
   pBuffer = libpointer('uint8Ptr', data);

   % T32EXTERN int  T32_WriteMemory (uint32_t Address, int Access, uint8_t *pBuffer, int Size);
   status = calllib(t32lib, 'T32_WriteMemory', address, access, pBuffer, sample_size);
   errorCheck(t32lib, 't32_write_data', status);

   %%
   if disable_print == 0
      writeTime = toc; % stop timer
      fprintf('Memory Write to %s Finished in %3.3f seconds.\n', symbolName, writeTime);
   end

   clear pBuffer; % remove pointer

end
