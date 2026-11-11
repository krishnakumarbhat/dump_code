%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Unpacking the compressed data packets
%
% Inputs:
% for 4ch and 2ch configs. Supports
% the 32,48,64,96 and 128 bit decompression need.
% clevel sets the compression level of input data.
%
% Outputs:
% Real and imaginery numbers with shift needed for decompression routine to
% be run after .
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [data_r, data_i, shft] = dcmp_unpack(idata_chirp, is_4_ch, clevel)

   bits = [4:7 32:33 48:49 64:67 96:99
           11:14 36:37 52:53 72:75 104:107
           18:21 40:41 56:57 80:83 112:115
           25:28 44:45 60:61 88:91 120:123
           8:10 34:35 50:51 68:71 100:103 0  % final 0 is to give length of 16
           15:17 38:39 54:55 76:79 108:111 0
           22:24 42:43 58:59 84:87 116:119 0
           29:31 46:47 62:63 92:95 124:127 0];
   nbit = [16 16 16 16 15 15 15 15   % 128B
           15 15 15 15 15 15 15 15   % 128A
           12 12 12 12 11 11 11 11   % 96B
           11 11 11 11 11 11 11 11   % 96A
           8  8  8  8  7  7  7  7   % 64B
           7  7  7  7  7  7  7  7   % 64A
           5  6  6  6  5  5  5  5   % 48C
           6  6  6  6  5  5  5  5   % 48B
           5  5  5  5  5  5  5  5   % 48A
           3  4  4  4  3  3  3  3   % 32B
           4  4  4  4  3  3  3  3]; % 32A
   bits_shft = [0:3];
   switch clevel
      case 2
         bits_shft = [bits_shft 99];
      case 4
         bits_shft = [bits_shft 67];
      case 6
         bits_shft = [bits_shft 49];
      case 7
         bits_shft = [bits_shft 33];
      case 9
         bits_shft = [bits_shft 33];
      case 10
         bits_shft = [bits_shft 7];
   end

   x = bitand(2^16 - 1, 2^16 + double(idata_chirp(:)));
   bdata = zeros(16, numel(x));
   for k = 0:15
      bdata(1 + k, :) = bitshift(bitand(x, bitshift(1, k)), -k);
   end
   bdata = reshape(bdata, 128, []);
   d = zeros(8, size(bdata, 2));

   for k = 1:8
      nb = nbit(clevel, k);
      msb = 2^(nb - 1);
      d(k, :) = bitxor(2.^(0:(nb - 1)) * bdata(1 + bits(k, 1:nb), :), msb) - msb;
      d(k, :) = 2.^(16 - nb) * d(k, :);
   end
   shft = 2.^(0:(numel(bits_shft) - 1)) * bdata(1 + bits_shft, :);

   data_r = int16(d(1:4, :));
   data_i = int16(d(5:8, :));
   shft = int16(shft);

end
