%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This is the decompression routine provided for Gen8 range and doppler
% decompression. This should support 32bit, 48bit, 64bit, 96bit and 128bit
% decompression. rnd_mode should be set to same settings as RA, in order
% for outputs to match.
%
% Inputs:
% y and shft are generated out of unpacking routine that is run prior.
%
% Outputs:
% x is the expected decompressed results.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [x, o_prbs1_st, o_prbs2_st] = decompression (y, shft,  min_shft, ums, lvl, rnd_mode, i_prbs1_st, i_prbs2_st)
   % shft is the block exponent, and min_shft the minimum block exponent of a group of blocks
   % There is no prevision for gain reduction or amplification beyond minimum b.e.
   % ums is the enable for the minimum shift adjustment

   % rnd_mode 0: no dithering
   % rnd_mode 1: 0.5 lsb append
   % rnd_mode >=2: random dithering
   if rnd_mode >= 2
      rnd_mode = uint32(2);
   end

   NBR = 5;

   [szr, szc] = size(y);

   switch szr
      case 2
         nb = [15, 15, 15, 15
               15, 15, 14, 14
               11, 11, 11, 11
               11, 11, 10, 10
               7,  7,  7, 7
               7,  7,  6, 6];
         e = [4, 5, 4, 5, 4, 5];
         assert(lvl < 7, 'Only six compression levels available with 2 channels');
      case 4
         nb = [16, 16, 16, 16, 15, 15, 15, 15   % 128B
               15, 15, 15, 15, 15, 15, 15, 15   % 128A
               12, 12, 12, 12, 11, 11, 11, 11   % 96B
               11, 11, 11, 11, 11, 11, 11, 11   % 96A
               8, 8, 8, 8, 7, 7, 7, 7    % 64B
               7, 7, 7, 7, 7, 7, 7, 7    % 64A
               5, 6, 6, 6, 5, 5, 5, 5    % 48C
               6, 6, 6, 6, 5, 5, 5, 5    % 48B
               5, 5, 5, 5, 5, 5, 5, 5    % 48A
               3, 4, 4, 4, 3, 3, 3, 3    % 32B
               4, 4, 4, 4, 3, 3, 3, 3];  % 32A

         e = [4, 5, 4, 5, 4, 5, 5, 4, 5, 5, 4];
      otherwise
         nb = 0;
         assert(0, 'For 1 or 3 channels, use 2 or 4 with the upper most at zero');
   end

   aux = double(shft - min_shft * ums);
   w = y ./ 2.^aux;

   if i_prbs1_st ~= 0
      [o_prbs1_st, rndr] = prbs_run([31, 28], i_prbs1_st, 20, NBR, szr, szc);
   else
      o_prbs1_st = 0;
      rndr = zeros(szr, szc);
   end

   if i_prbs2_st ~= 0
      [o_prbs2_st, rndi] = prbs_run([31, 28], i_prbs2_st, 20, NBR, szr, szc);
   else
      o_prbs2_st = 0;
      rndi = zeros(szr, szc);
   end

   rnd = (([rndr; rndi] + 0.5) / 2^NBR * (rnd_mode == 2) + 0.5 * (rnd_mode == 1)) ./ 2.^(nb(lvl, :)' - 1) ./ 2.^(aux);

   rnd = rnd(1:end / 2, :) + 1i * rnd(end / 2 + 1:end, :);

   x = w + rnd;

end

function [gen, rnd_vec] = prbs_run(poly, gen, ubits, nbits, P, L)
   rnd_vec = zeros(P, L);
   for k = 1:L
      for j = 1:P
         rnd_vec(j, k) = bitand(bitshift(gen, -(j - 1) * nbits), 2^nbits - 1);
      end
      for i = 1:ubits
         new_bit = bitand(bitxor(bitshift(gen, -poly(1) + 1), bitshift(gen, -poly(2) + 1)), 1);
         gen     = bitand(bitor(gen * 2, new_bit), 2^(poly(1)) - 1);
      end
   end
end
