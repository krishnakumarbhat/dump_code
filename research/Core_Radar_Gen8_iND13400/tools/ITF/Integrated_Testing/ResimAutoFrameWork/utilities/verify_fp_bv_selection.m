%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: verify_fp_bv_selection
%   Validate the selected compressed bvs in the RDD stream match the corresponding
%   range/doppler index in the collected range/doppler beamvectors.
%
%   If the compressed bvs do not match, also run the comparison on the decompressed
%   beamvectors to isolate if the entire BV is incorrect.
%
%  Inputs:
%   FP_embed_out_in - First pass outputs used for ITF validation
%   FP_embed_out_debug_in - First pass outputs used for debugging -
%                           Used for the 64 bit version of the compressed bvs and decompressed bvs
%   LookProc_embed_out - Look processing outputs, compressed and decompressed DFFT outputs
%   ddm_shift - DDM shift from the SMC
%
%  Outputs:
%   ddm_shifted_didx - Array of the DDM shifted index for the detection indices
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ddm_shifted_didx] = verify_fp_bv_selection(FP_embed_out_in, FP_embed_out_debug_in, LookProc_embed_out, LookProc_embed_debug_signal, smc_cal, look_type)

   LookProc_embed_out.dopp_fft_decomp = permute(LookProc_embed_out.dopp_fft_decomp, [1, 3, 2]);
   LookProc_embed_debug_signal.dfft_comp_data = reshape(LookProc_embed_debug_signal.dfft_comp_data, 420, 8, 512, 4);
   LookProc_embed_debug_signal.dfft_comp_data = permute(LookProc_embed_debug_signal.dfft_comp_data, [1, 2, 4, 3]);

   bvIdxShift  =   smc_cal.SMC.Look_Processing.k_ddma_bin_shifts.VALUE(look_type, :);
   numDopp     =   smc_cal.Configuration.BB_Configuration.DOPPLER_FFT_SIZE.VALUE(look_type);

   for x = 1:FP_embed_out_in.numDetected
      ddm_shifted_didx(1:4, x) = mod(FP_embed_out_in.dindx(x) + uint16(bvIdxShift), uint16(numDopp)) + 1;
      exp_bv_dcmp(1:8, x) = squeeze(LookProc_embed_out.dopp_fft_decomp(FP_embed_out_in.rindx(x) + 1, ddm_shifted_didx(1, x), :));
      exp_bv_dcmp(9:16, x) = squeeze(LookProc_embed_out.dopp_fft_decomp(FP_embed_out_in.rindx(x) + 1, ddm_shifted_didx(2, x), :));
      exp_bv_dcmp(17:24, x) = squeeze(LookProc_embed_out.dopp_fft_decomp(FP_embed_out_in.rindx(x) + 1, ddm_shifted_didx(3, x), :));
      exp_bv_dcmp(25:32, x) = squeeze(LookProc_embed_out.dopp_fft_decomp(FP_embed_out_in.rindx(x) + 1, ddm_shifted_didx(4, x), :));

      exp_bv_cmp(1:2, 1:4, 1, x) = squeeze(LookProc_embed_debug_signal.dfft_comp_data(FP_embed_out_in.rindx(x) + 1, 1:2, :, ddm_shifted_didx(1, x)));
      exp_bv_cmp(1:2, 1:4, 2, x) = squeeze(LookProc_embed_debug_signal.dfft_comp_data(FP_embed_out_in.rindx(x) + 1, 1:2, :, ddm_shifted_didx(2, x)));
      exp_bv_cmp(1:2, 1:4, 3, x) = squeeze(LookProc_embed_debug_signal.dfft_comp_data(FP_embed_out_in.rindx(x) + 1, 1:2, :, ddm_shifted_didx(3, x)));
      exp_bv_cmp(1:2, 1:4, 4, x) = squeeze(LookProc_embed_debug_signal.dfft_comp_data(FP_embed_out_in.rindx(x) + 1, 1:2, :, ddm_shifted_didx(4, x)));
   end

   exp_bv_cmp_temp = reshape(exp_bv_cmp, 32, FP_embed_out_in.numDetected);
   for i = 1:FP_embed_out_in.numDetected
      exp_bv_cmp_exp_u16(1:32, i) = typecast(exp_bv_cmp_temp(:, i), 'uint16');
   end

   [mismatch_cmp_bv, mismatch_det_cmp_index] = find((exp_bv_cmp_exp_u16) ~= FP_embed_out_debug_in.bv_u16);

   if isempty(mismatch_cmp_bv) && isempty(mismatch_det_cmp_index)
      fprintf('FP BV match the expected BV from the Doppler spectrum.\n');
   else
      detection_indices = unique(mismatch_det_cmp_index);
      FP_embed_out_in.mismatch_range_idx = FP_embed_out_in.rindx(detection_indices);
      FP_embed_out_in.mismatch_dopp_idx = FP_embed_out_in.dindx(detection_indices);

      fprintf('FP Compressed BV DO NOT match the expected BV from the Doppler spectrum.\n');

      for i = 1:length(detection_indices)
         fprintf('Range, doppler = %d, %d\n', FP_embed_out_in.mismatch_range_idx(i), FP_embed_out_in.mismatch_dopp_idx(i));
         bv_mismatched = sprintf("%d ", mismatch_cmp_bv(detection_indices(i) == mismatch_det_cmp_index));
         fprintf("    Mismatched BV indices = %s\n", bv_mismatched);

         % This code can be used to determine if the mismatched BV is in the datacube
         % The picked and expected prints will allow searching in the datacube for the beamvector.
         % This is helpful for determining if the selection process is getting valid data from the wrong memory
         if 0
            bv_mismatched = mismatch_cmp_bv(detection_indices(i) == mismatch_det_cmp_index);
            if bv_mismatched < 5
               fprintf("picked = %016X expected = %016X\n", FP_embed_out_in.bv(bv_mismatched, i), LookProc_embed_debug_signal.dfft_comp_data_u64(FP_embed_out_in.mismatch_range_idx(i) + 1, FP_embed_out_in.mismatch_dopp_idx(i) + 1, bv_mismatched));
               picked = FP_embed_out_in.bv(bv_mismatched, i);
               expected = LookProc_embed_debug_signal.dfft_comp_data_u64(FP_embed_out_in.mismatch_range_idx(i) + 1, FP_embed_out_in.mismatch_dopp_idx(i) + 1, bv_mismatched);
            end
         end
      end

      % If the compressed beamvectors match, there is no reason to compare the decompressed.
      % If, however, there is a mismatch, the error reporting can be a bit more useful here,
      % as the individual vectors are compared which might isolate the issue.

      [mismatch_bv, mismatch_det_index] = find(exp_bv_dcmp ~= FP_embed_out_debug_in.decomp_bv);

      if isempty(mismatch_bv) && isempty(mismatch_det_index)
         fprintf('FP BV match the expected BV from the Doppler spectrum.\n');
      else
         detection_indices = unique(mismatch_det_index);
         FP_embed_out_in.mismatch_range_idx = FP_embed_out_in.rindx(detection_indices);
         FP_embed_out_in.mismatch_dopp_idx = FP_embed_out_in.dindx(detection_indices);

         fprintf('FP BV DO NOT match the expected BV from the Doppler spectrum.\n');

         for i = 1:length(detection_indices)
            fprintf('Range, doppler = %d, %d\n', FP_embed_out_in.mismatch_range_idx(i), FP_embed_out_in.mismatch_dopp_idx(i));
            bv_mismatched = sprintf("%d ", mismatch_bv(detection_indices(i) == mismatch_det_index));
            fprintf("    Mismatched BV indices = %s\n", bv_mismatched);
         end
      end
   end

end
