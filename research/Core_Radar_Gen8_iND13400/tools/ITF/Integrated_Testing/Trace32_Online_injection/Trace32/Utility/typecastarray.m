%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: typecastarray()
%   This function sets typecasts and reshapes the array.
%
% Return Variables:
%   newArray
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [newArray] = typecastarray(Array, type)

   array = permute(Array, [2 1]);
   arrayDim = num2cell(size(array));
   castArray = reshape(typecast(array(:), type), [], arrayDim{2:end});
   newArray = permute(castArray, [2 1]);

end
