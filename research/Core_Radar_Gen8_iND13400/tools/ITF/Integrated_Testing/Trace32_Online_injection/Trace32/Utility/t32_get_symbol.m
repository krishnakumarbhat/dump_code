%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: T32_GetSymbol(t32lib, symbolName)
%   This function returns the symbol information for a specified symbol name.
%   If the specified symbol was not found, address and size contain(uint32_t)-1.
%
%   t32lib - Instance of the t32 library
%   symbolName - String  name of the symbol to resolve.
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% T32EXTERN int  T32_GetSymbol(const char *SymbolName, uint32_t *pAddress, uint32_t *pSize, uint32_t *pAccess);

function [address, symbolSize, status] = t32_get_symbol(t32lib, symbolName)

   pAddress = libpointer('uint32Ptr', uint32(0));
   pSize = libpointer('uint32Ptr', uint32(0));
   pAccess = libpointer('uint32Ptr', uint32(0));

   status = calllib(t32lib, 'T32_GetSymbol', symbolName, pAddress, pSize, pAccess);
   errorCheck(t32lib, 'T32_GetSymbol', status);

   address = pAddress.Value;
   symbolSize = pSize.Value;
   access = pAccess.Value;

   addressHex = uint32(dec2hex(address));

   % These lines can be used for debugging.
   %    addressHex = uint32(dec2hex(address));
   %    fprintf ('Symbol %s is located at %d, ( 0x%s ) ', symbolName, address, addressHex);
   %    fprintf ('with a size of %d bytes, ( 0x%s )\n', symbolSize, uint32(dec2hex(symbolSize)));

   clear pAddress;
   clear pSize;
   clear pAccess;
end
