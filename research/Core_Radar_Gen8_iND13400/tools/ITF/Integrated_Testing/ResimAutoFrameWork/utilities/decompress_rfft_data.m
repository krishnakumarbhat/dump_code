% this file decompressed the rfft data from Embedded dump which is dumped from sysmem
% which has output of range processing processing in FITO mode, that has
% layed out data this way
%       |--32bits--|--32bits---|--32bits---|---32bits--|
%  *    chrp0 rbin0|chrp1 rbin0|chrp2 rbin0|chrp3 rbin0|
%  *    ...............................................
%  *    ............................... |chrp1020 rbin0|
%  *
%  *    chrp0 rbin1|chrp1 rbin1|chrp2 rbin1|chrp3 rbin1|
%  *    ...............................................
%  *    ............................... |chrp1020 rbin1|
%  *
%  *    chrp0 rbin419|chrp1 rbin419|chrp2 rbin419|chrp3 rbin419|
%  *    .....................................................
%  *    ......................................|chrp1020 rbin419|
%
function [decomp_data] = decompress_rfft_data(comp_rfft_data_raw, min_chirp_scaling, num_chirp, num_range_used, clevel, num_rx, plot_or_not)

   rfft_raw = comp_rfft_data_raw;
   rfft_u16 = typecast(rfft_raw, "uint16");

   if clevel == 10
      words_per_sample = 2; % 2 16bit words i.e. 4 bytes

      x = rfft_u16(1:2:end); % high
      y = rfft_u16(2:2:end); % low

      xx = x(1:num_chirp * num_range_used);
      yy = y(1:num_chirp * num_range_used);

      for j = 1:num_chirp
         xx21(j, :) = xx(j:num_chirp:end);
         yy21(j, :) = yy(j:num_chirp:end);
      end

      xx3 = xx21;
      yy3 = yy21;

      xx4 = reshape(xx3, [], 1);
      yy4 = reshape(yy3, [], 1);

      idata_lin(1:2:num_chirp * num_range_used * 2) = xx4';
      idata_lin(2:2:num_chirp * num_range_used * 2) = yy4';

      q = [0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15];
      q = reshape([q * 2; q * 2 + 1], 1, []) + 1;
      zero_pad = zeros(6, num_chirp);
      bit_and_value = 31;
   elseif clevel == 7
      words_per_sample = 4; % 4 16bit words i.e. 8 bytes

      x = rfft_u16(1:4:end); % high
      y = rfft_u16(2:4:end); % low
      z = rfft_u16(3:4:end); % low
      a = rfft_u16(4:4:end); % low

      xx = x(1:num_chirp * num_range_used);
      yy = y(1:num_chirp * num_range_used);
      zz = z(1:num_chirp * num_range_used);
      aa = a(1:num_chirp * num_range_used);

      for j = 1:num_chirp
         xx21(j, :) = xx(j:num_chirp:end);
         yy21(j, :) = yy(j:num_chirp:end);
         zz21(j, :) = zz(j:num_chirp:end);
         aa21(j, :) = aa(j:num_chirp:end);
      end

      xx3 = xx21;
      yy3 = yy21;
      zz3 = zz21;
      aa3 = aa21;

      xx4 = reshape(xx3, [], 1);
      yy4 = reshape(yy3, [], 1);
      zz4 = reshape(zz3, [], 1);
      aa4 = reshape(aa3, [], 1);

      idata_lin(1:4:num_chirp * num_range_used * 4) = xx4';
      idata_lin(2:4:num_chirp * num_range_used * 4) = yy4';
      idata_lin(3:4:num_chirp * num_range_used * 4) = zz4';
      idata_lin(4:4:num_chirp * num_range_used * 4) = aa4';

      q = [0, 8, 16, 24, 4, 12, 20, 28
           1, 9, 17, 25, 5, 13, 21, 29
           2, 10, 18, 26, 6, 14, 22, 30
           3, 11, 19, 27, 7, 15, 23, 31];
      % q = reshape([q * 4; q * 4 + 1; q * 4 + 2; q * 4 + 3], 1, []) + 1;
      q = reshape(q, 1, []) + 1;
      zero_pad = zeros(4, num_chirp);
      bit_and_value = 31;
   else
      error('Unsupported compression level');
   end

   bytes_per_sample = words_per_sample * 2;
   fft_size = num_range_used; % 2^nextpow2(chirp_length);
   n_bytes = 2 * length(idata_lin); % input data from embedded is expected to be 16bit numbers
   odata = zeros(num_rx, fft_size, num_chirp);

   if n_bytes ~= (fft_size * num_chirp * bytes_per_sample)
      warning('Data size expected is %d bytes, while embedded data size is %d bytes', fft_size * num_chirp * bytes_per_sample, n_bytes);
   end

   addr = reshape(1:words_per_sample * num_chirp, words_per_sample, []);

   for j = 1:fft_size
      % idata_chirp          = uint16([idata(q+1+(j-1)*words_per_sample*fft_size);zeros(6,fft_size)]);
      addr_lo = bitand(addr - 1, bit_and_value) + 1;
      addr_lo_log(j, :, :) = addr_lo;

      addr_descramble = addr - addr_lo + q(addr_lo);
      addr_descample_log(j, :, :) = addr_descramble;

      addr = addr + words_per_sample * num_chirp;
      addr_log(j, :, :) = addr;

      idata_chirp = uint16([idata_lin(addr_descramble); zero_pad]);
      idata_chirp_log(j, :, :) = idata_chirp;

      [data_r, data_i, shft] = dcmp_unpack(idata_chirp, int16(num_chirp == 4), int16(clevel));
      [x, ~, ~] = decompression (complex(double(data_r) / 2^15, double(data_i) / 2^15), double(shft), double(min_chirp_scaling), 1, clevel, 0, 0, 0);
      odata(:, j, :) = x;
   end

   odata = odata(1:num_rx, :, :) * 2^15;
   decomp_data = odata;

   rx0_rfft = squeeze(decomp_data(1, :, :));
   rx1_rfft = squeeze(decomp_data(2, :, :));
   rx2_rfft = squeeze(decomp_data(3, :, :));
   rx3_rfft = squeeze(decomp_data(4, :, :));

   if plot_or_not == 1
      figure(1);
      mesh(abs(rx0_rfft));
      figure(2);
      mesh(abs(rx1_rfft));
      figure(3);
      mesh(abs(rx2_rfft));
      figure(4);
      mesh(abs(rx3_rfft));
   end
end
