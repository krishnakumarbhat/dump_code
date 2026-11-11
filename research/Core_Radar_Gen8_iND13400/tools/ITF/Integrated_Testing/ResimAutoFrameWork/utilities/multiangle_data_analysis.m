function [dop_out_decomp_fpga, nci_vectors_scaled_fpga, dop_out_comp_fpga] =  multiangle_data_analysis(dfft_comp_data_temp_i16, rdop_avg_NCI, rdop_nci_bexp, ndfft, nang, nbins, dop_comp_lvl)
   % model_dop_file: path to model output file with doppler output, must be in binary format int16
   % model_nci_file: path to model output file with doppler output, must be in binary format int16
   % model_bexp_file: path to model output file with doppler output, must be in binary format int16
   % fpga_dop_file: path to FPGA dump file with doppler output, must be in binary format int16
   % fpga_nci_file: path to FPGA dump file with NCIs output, must be in binary format int16
   % fpga_bexp_file: path to FPGA dump file with NCIs bexp output, must be in binary format int16
   % nchirps: number of chirps
   % chirpl: chirp length
   % nang: Number of angles to analyze (usually 8 or 16)
   % nbins: Number of range bins to analyze, it is a subset of chirpl/2.
   % inc_range: indicates if the Range output is included in the dump or not
   % dop_comp_lvl: compression level used for Doppler output
   % skip_fpga_dump: if 1 only the model file is analyzed

   nchirps = ndfft;
   estimators_flip_bexp = 1;
   nrx = 4;

   cmp_sizes = [4, 4, 3, 3, 2, 2];
   n_samples_mode = 0;
   cmp_size = cmp_sizes(dop_comp_lvl);

   % Get fpga data

   data_dop_fpga = dfft_comp_data_temp_i16; % fread(fid, 'int16');
   dop_out_comp_fpga = zeros(nbins, 8, nrx * nchirps, 'int16');
   dop_out_decomp_fpga = complex(zeros(nbins, nrx * 2, nchirps));
   nci_vectors_fpga = zeros(nbins, nang, nchirps);
   nci_bexps_fpga = zeros(nbins, nang);

   switch cmp_size
      case 2
         q = reshape(0:15, 4, [])';
         q = q(:)';
         qq = [];
         for i = 1:(nchirps * nrx) / 16
            qq = [qq, q + ((i - 1) * 16)];
         end
         q = [qq * 2; qq * 2 + 1];

         q_prx = q(1:2, 1:nchirps);

         for j = 1:nbins
            data_dop_fpga_rbin = data_dop_fpga(j, :);
            dop_out_comp_fpga(j, :, :) = int16([data_dop_fpga_rbin(q + 1 + (1 - 1) * cmp_size * nchirps * nrx); zeros(6, nchirps * nrx)]);
         end

         for j = 1:nbins
            data_dop_fpga_rbin = squeeze(data_dop_fpga(j, :));
            for rx = 1:nrx
               data_dop_fpga_rbin_prx(rx, :) = data_dop_fpga_rbin((nchirps * cmp_size * (rx - 1) + 1):nchirps * cmp_size * (rx));
               temp_var = data_dop_fpga_rbin_prx(rx, :);
               dop_out_comp_fpga_prx(j, rx, 1:8, 1:nchirps) = int16([temp_var(q_prx + 1); zeros(6, nchirps)]);
            end
         end

      case 3
         q = [0, 8, 16, 24, 3, 11, 19, 27, 6, 14, 22, 30, 33, 41, 49, 57; ...
              1, 9, 17, 25, 4, 12, 20, 28, 7, 15, 23, 31, 34, 42, 50, 58; ...
              2, 10, 18, 26, 5, 13, 21, 29, 32, 40, 48, 56, 35, 43, 51, 59];
         qq = [];
         for i = 1:(nchirps * nrx) / 16
            qq = [qq, q + ((i - 1) * 64)];
         end
         q = qq;

         for j = 1:nbins

            dop_out_comp_fpga(j, :, :) = int16([(data_dop_fpga(q + 1 + (j - 1) * 4 * nchirps * nrx)); zeros(5, nchirps * nrx)]);
         end
      case 4
         q = [0, 8, 16, 24, 4, 12, 20, 28; ...
              1, 9, 17, 25, 5, 13, 21, 29; ...
              2, 10, 18, 26, 6, 14, 22, 30; ...
              3, 11, 19, 27, 7, 15, 23, 31];
         qq = [];
         for i = 1:(nchirps * nrx) / 8
            qq = [qq, q + ((i - 1) * 32)];
         end
         q = qq;
         for j = 1:nbins
            dop_out_comp_fpga(j, :, :) = int16([data_dop_fpga(q + 1 + (j - 1) * cmp_size * nchirps * nrx); zeros(4, nchirps * nrx)]);
         end
      case 6
         q = [0, 8, 16, 24, 6, 14, 22, 30; ...
              1, 9, 17, 25, 7, 15, 23, 31; ...
              2, 10, 18, 26, 32, 40, 48, 56; ...
              3, 11, 19, 27, 33, 41, 49, 57; ...
              4, 12, 20, 28, 34, 42, 50, 58; ...
              5, 13, 21, 29, 35, 43, 51, 59];
         qq = [];
         for i = 1:(nchirps * nrx) / 8
            qq = [qq, q + ((i - 1) * 64)];
         end
         q = qq;
         for j = 1:nbins
            dop_out_comp_fpga(j, :, :) = int16([data_dop_fpga(q + 1 + (j - 1) * 8 * nchirps * nrx); zeros(2, nchirps * nrx)]);
         end
      case 8
         for j = 1:nbins
            dop_out_comp_fpga(j, :, :) = int16(reshape(data_dop_fpga((1:nchirps * nrx * cmp_size) + (j - 1) * cmp_size * nchirps * nrx), cmp_size, []));
         end
   end

   % Decompress Doppler output from FPGA
   for n = 1:nbins
      for i = 1:nrx % Decompression needed for plotting
         [dop_out_decomp_fpga(n, ((i - 1) * 2 + 1):2 * i, :), ~] = decompress_data(squeeze(dop_out_comp_fpga(n, :, ((i - 1) * nchirps + 1):i * nchirps)), 0, dop_comp_lvl);

      end

      [dop_out_decomp_fpga_prx(n, 1:2, :), ~] = decompress_data(squeeze(dop_out_comp_fpga_prx(n, 1, 1:8, 1:nchirps)), 0, dop_comp_lvl);
      [dop_out_decomp_fpga_prx(n, 3:4, :), ~] = decompress_data(squeeze(dop_out_comp_fpga_prx(n, 2, 1:8, 1:nchirps)), 0, dop_comp_lvl);
      [dop_out_decomp_fpga_prx(n, 5:6, :), ~] = decompress_data(squeeze(dop_out_comp_fpga_prx(n, 3, 1:8, 1:nchirps)), 0, dop_comp_lvl);
      [dop_out_decomp_fpga_prx(n, 7:8, :), ~] = decompress_data(squeeze(dop_out_comp_fpga_prx(n, 4, 1:8, 1:nchirps)), 0, dop_comp_lvl);
   end

   nci_vectors_fpga = rdop_avg_NCI; % (nbins, nang, nchirps);
   nci_bexps_fpga = rdop_nci_bexp; % zeros(nbins, nang);

   % Format NCI vectors
   % The format of the Bexp depends on the configuration of estimators_flip_bexp
   mult_fpga = zeros(nbins, nang);
   nci_vectors_scaled_fpga = zeros(nbins, nang, nchirps);

   for n = 1:nbins
      if estimators_flip_bexp == 0
         mult_fpga(n, :) = 2.^(squeeze(nci_bexps_fpga(n, :)) - 15);
      else
         mult_fpga(n, :) = 2.^(-(squeeze(nci_bexps_fpga(n, :)) - 48));
      end
   end

   for i = 1:nbins
      aux = squeeze(nci_vectors_fpga(i, :, :))';
      nci_vectors_scaled_fpga(i, :, :) = (aux .* repmat(squeeze(mult_fpga(i, :)), nchirps, 1))';
   end

   sel_bin = 1;
   figure;
   subplot(4, 2, 1);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 1, :))));
   subplot(4, 2, 2);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 2, :))));
   subplot(4, 2, 3);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 3, :))));
   subplot(4, 2, 4);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 4, :))));
   subplot(4, 2, 5);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 5, :))));
   subplot(4, 2, 6);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 6, :))));
   subplot(4, 2, 7);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 7, :))));
   subplot(4, 2, 8);
   mesh(db(squeeze(dop_out_decomp_fpga(:, 8, :))));

   figure;
   subplot(4, 2, 1);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 1, :))));
   subplot(4, 2, 2);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 2, :))));
   subplot(4, 2, 3);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 3, :))));
   subplot(4, 2, 4);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 4, :))));
   subplot(4, 2, 5);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 5, :))));
   subplot(4, 2, 6);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 6, :))));
   subplot(4, 2, 7);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 7, :))));
   subplot(4, 2, 8);
   mesh(db(squeeze(nci_vectors_scaled_fpga(1:420, 8, :))));
end
