% This is the decompression routine provided for Gen8 range and doppler
% decompression. Should only be used for 64bit, decompression.
%
% Inputs:
% u16 format of compressed data, num of rx channels, dfft size, rangebins
% used , compression level,
%
% Outputs:
% outDfft is the expected decompressed results.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [outDfft, dfftComp_u64] = decomp_dfft_data(dfft_comp_data_temp_u16, max_dfft_size, rbins_used, num_rx_channels, cmp_lvl, plot_true)

   q = [0, 8, 16, 24, 4, 12, 20, 28; ...
        1, 9, 17, 25, 5, 13, 21, 29; ...
        2, 10, 18, 26, 6, 14, 22, 30; ...
        3, 11, 19, 27, 7, 15, 23, 31];
   qq = [];
   for i = 1:(max_dfft_size) / 8
      qq = [qq, q + ((i - 1) * 32)];
   end

   q = qq;

   dfftComp_u64 = uint64(zeros(rbins_used, max_dfft_size, num_rx_channels));

   last_update = 0; % Prime the printout

   % decompression for entire range doppler fft cube
   for k = 1:rbins_used % choose num of rbin you want to decompress
      for rx_idx = 1:num_rx_channels
         rbin_dfft_perrx_u16 = dfft_comp_data_temp_u16(k, ((rx_idx - 1) * max_dfft_size * 4 + 1):(rx_idx) * max_dfft_size * 4);
         bv_mode6_fl = reshape(rbin_dfft_perrx_u16, 4, []);
         bv_mode6_defito = bv_mode6_fl(q + 1 + (1 - 1) * 4 * max_dfft_size);
         bv_mode6_axi = uint16([bv_mode6_defito; zeros(4, size(bv_mode6_fl, 2))]);
         [data_r, data_i, shft] = dcmp_unpack(bv_mode6_axi, int16(1), int16(cmp_lvl));
         [bv_decomp, ~, ~] = decompression (2^-15 * complex(double(data_r), double(data_i)), double(shft), 0, 0, cmp_lvl, 0, 0, 0);
         outDfft(k, :, [1:4] + 4 * (rx_idx - 1)) =   squeeze(bv_decomp).' / 2^15;

         for dopp = 1:max_dfft_size
            dfftComp_u64(k, dopp, rx_idx) = typecast(bv_mode6_defito(1:4, dopp), 'uint64');
         end
      end

      % If other debug statements are added, overwrite last_update to 0 after this call.
      last_update = print_update('Decompressing data for rangebin', last_update, k, rbins_used);
   end

   if plot_true
      % Plot the 16 cdm
      for  cdm_idx = 1:16
         figure(cdm_idx);
         mesh(20 * log10(abs(outDfft(:, :, cdm_idx))));
         xlabel('Doppler Bin Index');
         ylabel('range index');
         zlabel('Power (dB)');
      end
   end

end
