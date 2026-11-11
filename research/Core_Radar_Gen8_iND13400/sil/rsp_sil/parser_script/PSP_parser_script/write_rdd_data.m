function write_rdd_data(rdd_stream, frame_idx, sil_bin_file_path)
   % Write RDD data to binary file for SIL testing
   % Optimized for SRR8P PCAP format with all fields safely checked

   if ~isempty(sil_bin_file_path)
      file_name = fullfile(sil_bin_file_path, 'rdd_input.bin');
   else
      error('Path is empty!');
   end

   fileID = fopen(file_name, 'w');
   MAX_RANGE_BINS = 385;
   MAX_DETS_FIRST_PASS = 512;

   for k = frame_idx:frame_idx
      % Write all RDD data fields with safety checks for SRR8P format

      % bwdep fields (range bin dependent)
      if isfield(rdd_stream.rdd_data, 'bwdep_cr_resp')
         fwrite(fileID, rdd_stream.rdd_data.bwdep_cr_resp(k, :), 'uint32');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint32');
      end

      if isfield(rdd_stream.rdd_data, 'bwdep_sensitivity_thold')
         fwrite(fileID, rdd_stream.rdd_data.bwdep_sensitivity_thold(k, :), 'uint32');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint32');
      end

      if isfield(rdd_stream.rdd_data, 'af_sensitivity_thold')
         fwrite(fileID, rdd_stream.rdd_data.af_sensitivity_thold(k, :), 'uint32');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint32');
      end

      if isfield(rdd_stream.rdd_data, 'bwdep_hvc_thold')
         fwrite(fileID, rdd_stream.rdd_data.bwdep_hvc_thold(k, :), 'uint32');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint32');
      end

      if isfield(rdd_stream.rdd_data, 'bwdep_mb_thold')
         fwrite(fileID, rdd_stream.rdd_data.bwdep_mb_thold(k, :), 'uint32');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint32');
      end

      % RDD1 estimation fields (detection based)
      if isfield(rdd_stream.rdd_data, 'rdd1_rbinest')
         fixed_rbinest = rdd_stream.rdd_data.rdd1_rbinest(k, :) .* 2^21;
         fwrite(fileID, fixed_rbinest, 'int32');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'int32');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_dbinest')
         fixed_dbinest = rdd_stream.rdd_data.rdd1_dbinest(k, :) .* 2^21;
         fwrite(fileID, fixed_dbinest, 'int32');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'int32');
      end

      % RDD2 threshold and range fields
      if isfield(rdd_stream.rdd_data, 'rdd2_thold_2nd_pass')
         fwrite(fileID, rdd_stream.rdd_data.rdd2_thold_2nd_pass(k, :), 'uint32');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint32');
      end

      if isfield(rdd_stream.rdd_data, 'rdd2_range')
         fixed_range = rdd_stream.rdd_data.rdd2_range(k, :) .* 2^21;
         fwrite(fileID, fixed_range, 'int32');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'int32');
      end

      if isfield(rdd_stream.rdd_data, 'rdd2_range_rate')
         fixed_range_rate = rdd_stream.rdd_data.rdd2_range_rate(k, :) .* 2^21;
         fwrite(fileID, fixed_range_rate, 'int32');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'int32');
      end

      if isfield(rdd_stream.rdd_data, 'rdd2_snr')
         fixed_snr = rdd_stream.rdd_data.rdd2_snr(k, :) .* 2^23;
         fwrite(fileID, fixed_snr, 'int32');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'int32');
      end

      % RDD1 BV field (large array)
      if isfield(rdd_stream.rdd_data, 'rdd1_bv')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_bv(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, 16384), 'uint16');
      end

      % CFAR fields
      if isfield(rdd_stream.rdd_data, 'cfar_nf_est')
         fwrite(fileID, rdd_stream.rdd_data.cfar_nf_est(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'cfar_thold')
         fwrite(fileID, rdd_stream.rdd_data.cfar_thold(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'cfar_nf_est_ci')
         fwrite(fileID, rdd_stream.rdd_data.cfar_nf_est_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'cfar_thold_ci')
         fwrite(fileID, rdd_stream.rdd_data.cfar_thold_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      % RDD1 per-bin fields
      if isfield(rdd_stream.rdd_data, 'rdd1_max_per_range_bin')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_max_per_range_bin(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_max_per_range_bin_ci')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_max_per_range_bin_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_signal_thold_first_pass')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_signal_thold_first_pass(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_signal_thold_first_pass_ci')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_signal_thold_first_pass_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_first_pass_thold')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_first_pass_thold(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_first_pass_thold_ci')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_first_pass_thold_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_rdop_amp')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_rdop_amp(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_rdop_amp_ci')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_rdop_amp_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_rindx')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_rindx(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_dindx')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_dindx(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_dindx_ci')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_dindx_ci(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint16');
      end

      % Detection counts
      if isfield(rdd_stream.rdd_data, 'rdd1_num_detect')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_num_detect(k), 'uint16');
      else
         fwrite(fileID, 0, 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'rdd2_num_detect')
         fwrite(fileID, rdd_stream.rdd_data.rdd2_num_detect(k), 'uint16');
      else
         fwrite(fileID, 0, 'uint16');
      end

      % NCI and CI fields
      if isfield(rdd_stream.rdd_data, 'nci_bexp')
         fwrite(fileID, rdd_stream.rdd_data.nci_bexp(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'ci_bexp')
         fwrite(fileID, rdd_stream.rdd_data.ci_bexp(k, :), 'uint16');
      else
         fwrite(fileID, zeros(1, MAX_RANGE_BINS), 'uint16');
      end

      if isfield(rdd_stream.rdd_data, 'ci_detections_flag')
         fwrite(fileID, rdd_stream.rdd_data.ci_detections_flag(k, :), 'uint8');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint8');
      end

      if isfield(rdd_stream.rdd_data, 'rdd2_sp_fail_flag')
         fwrite(fileID, rdd_stream.rdd_data.rdd2_sp_fail_flag(k, :), 'uint8');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint8');
      end

      if isfield(rdd_stream.rdd_data, 'min_chirp_scaling')
         fwrite(fileID, rdd_stream.rdd_data.min_chirp_scaling(k), 'uint8');
      else
         fwrite(fileID, 0, 'uint8');
      end

      if isfield(rdd_stream.rdd_data, 'below_sp_thold')
         fwrite(fileID, rdd_stream.rdd_data.below_sp_thold(k, :), 'uint8');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint8');
      end

      if isfield(rdd_stream.rdd_data, 'rdd1_neighbor_det_flag')
         fwrite(fileID, rdd_stream.rdd_data.rdd1_neighbor_det_flag(k, :), 'uint8');
      else
         fwrite(fileID, zeros(1, MAX_DETS_FIRST_PASS), 'uint8');
      end

   end

   fclose(fileID);

end
