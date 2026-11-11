%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: T32_WriteVariableValue()
%   This function sets the integer value for a specified variable name.
%   If the value does not fit into the variable, it is truncated to the
%   size of the variable.
%
% Return Variables:
%   0 for ok, otherwise Error value
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status] = t32_write_var(t32lib, name, value)

   [varAddress, varSize] = t32_get_symbol(t32lib, name);

   access = hex2dec('40');
   % access = hex2dec('c0');

   if value < 0
      if varSize == 1
         value = int8(value);
      elseif varSize == 2
         value = int16(value);
      else
         value = int32(value);
      end
   else
      if varSize == 1
         value = uint8(value);
      elseif varSize == 2
         value = uint16(value);
      else
         value = uint32(value);
      end
   end

   value = typecastarray(value, 'uint8');
   pValue = libpointer('uint8Ptr', value);
   varSize = int32(varSize);

   % T32EXTERN T32_WriteMemory(uint32_t Address, int Access, uint8_t *pBuffer, int Size);
   status = calllib(t32lib, 'T32_WriteMemory', varAddress, access, pValue, varSize);
   errorCheck(t32lib, 'T32_WriteVariableValue', status);
   clear pValue;

end
