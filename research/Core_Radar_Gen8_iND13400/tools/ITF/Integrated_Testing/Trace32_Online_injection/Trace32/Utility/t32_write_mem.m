%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: T32_WriteMemory()
%   %   Writes data to target memory. The size of the data block is not limited.
%   This function should be used to access variables and make other not time
%   critical memory writes.
%
% access: memory access specifier
%   Bit 0 4 Memory class
%   Bit 6 Set for emulation memory access (dual port access)
%   Bit 7 Set to enable verify after write
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [] = t32_write_mem(t32lib, address, buffer, buffer_size)

   access = hex2dec('c0');

   buffer = uint32(buffer);
   buffer = typecastarray(buffer, 'uint8');
   pbuffer = libpointer('uint8Ptr', buffer);

   % T32EXTERN T32_WriteMemory(uint32_t Address, int Access, uint8_t *pBuffer, int Size);
   status = calllib(t32lib, 'T32_WriteMemory', address, access, pbuffer, buffer_size);
   errorCheck(t32lib, 'T32_WriteMemory', status);

   clear pbuffer;

end
