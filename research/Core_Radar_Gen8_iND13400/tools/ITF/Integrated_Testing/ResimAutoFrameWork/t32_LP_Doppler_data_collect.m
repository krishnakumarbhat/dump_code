% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_lookprocDoppler_collect()
%   This function collects the DFFT, NCI and CI embedded data from the t32
%  Inputs:
%   look_type
%   smc_cal
%   LookProc_embed_out
%   LookProc_embed_debug_signal
%
%  Outputs:
%   LookProc_embed_out
%   LookProc_embed_debug_signal
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status, LookProc_embed_out,  LookProc_embed_debug_signal] = t32_LP_Doppler_data_collect(LookProc_embed_out, LookProc_embed_debug_signal, look_type, t32lib, smc_cal)

   global DFFT_BUFFER_DEPTH
   global NCI_BUFFER_DEPTH

   % Set this to 1 to also collect the intermediate outputs of the AA.
   % NOTE: this slows the collection down
   collect_aa_outputs = 0;

   num_chirps = smc_cal.Configuration.BB_Configuration.K_FRAME.VALUE(look_type);
   rbins_used = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   max_chirps = smc_cal.Configuration.BB_Configuration.K_MAX.VALUE;
   max_dfft_size = smc_cal.Configuration.BB_Configuration.MAX_DOPPLER_FFT_SIZE.VALUE;
   num_rx_channels = smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE;
   num_tx_channels = smc_cal.Configuration.BB_Configuration.NUM_TX_CHANNELS.VALUE;
   max_detections = smc_cal.Configuration.BB_Configuration.MAX_DETS_FIRST_PASS.VALUE;
   num_angles = smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE;

   doppler_compression_lvl = 6;
   range_compression_lvl = 10;
   DFFT_BUFFER_DEPTH = 3;
   NCI_BUFFER_DEPTH = 4;

   rdop_avg_NCI = zeros(rbins_used, num_angles, max_dfft_size);
   rdop_nci_bexp = zeros(rbins_used, num_angles);

   if 1 == collect_aa_outputs
      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set AA_Execute_RBIN0');
      if 0 ~= status
         warning("Could not set breakpoint for AA_Execute_RBIN0");
      end

      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set AA_Execute');
      if 0 ~= status
         warning("Could not set breakpoint for AA_Execute");
      end

      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set AA_Execute_On_Prior_Data');
      if 0 ~= status
         warning("Could not set breakpoint for AA_Execute_On_Prior_Data");
      end

      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set AA_Execute_On_RBINLAST_Prior_Data');
      if 0 ~= status
         warning("Could not set breakpoint for AA_Execute_On_Prior_Data");
      end

      status = t32_cmd(t32lib, 'Intercom R52 Var.Break.Set IPC_Sp_Post_Proc_Buf_Read_Addr; /Write');
      if 0 ~= status
         warning("Could not set breakpoint for AA_Execute_On_Prior_Data");
      else
         warning("Stopping the R52 to prevent starting a new frame.");
      end

      aa_data = struct();
      aa_data.nci = struct();
      aa_data.ci = struct();
      aa_data.nci.log2_inputs = zeros(rbins_used, max_dfft_size);
      aa_data.ci.log2_inputs = zeros(rbins_used, max_dfft_size);

      aa_data.nci.num_det = zeros(rbins_used, 1);
      aa_data.nci.out_sort = zeros(rbins_used, 1024);
      aa_data.nci.out_thresh = zeros(rbins_used, 1024);
      aa_data.nci.out_dets = zeros(rbins_used, 1024);
      aa_data.nci.out_bitmap = zeros(rbins_used, 256);
      aa_data.nci.log2_data_pre = zeros(rbins_used, 1024);
      aa_data.nci.log2_data_curr = zeros(rbins_used, 1024);
      aa_data.nci.log2_data_next = zeros(rbins_used, 1024);

      aa_data.ci.num_det = zeros(rbins_used, 1);
      aa_data.ci.out_sort = zeros(rbins_used, 1024);
      aa_data.ci.out_thresh = zeros(rbins_used, 1024);
      aa_data.ci.out_dets = zeros(rbins_used, 1024);
      aa_data.ci.out_bitmap = zeros(rbins_used, 256);
      aa_data.ci.log2_data_pre = zeros(rbins_used, 1024);
      aa_data.ci.log2_data_curr = zeros(rbins_used, 1024);
      aa_data.ci.log2_data_next = zeros(rbins_used, 1024);

   end

   last_update = 0;

   % This will disable debug outputs that come from the t32_write_data function.
   % If there are other debug statements added - set this to 0,
   % print_update will overwrite the line, so the screen isn't overwhelmed with bin updates.
   disable_write_outputs = 1;

   for k = 1:rbins_used
      % When this function is called, the BBE debugger is expected to be
      % halted and at the break point for the Doppler Processing start.
      % So, we must call GO,
      % then wait for the breakpoint to be hit - that breakpoint will
      % be the Circular_Buffer_Update breakpoint, where the data for each
      % range bin will be updated.
      t32_cmd(t32lib, 'Intercom BBE32 Go');
      status = t32_wait_for_bbe_breakpoint(t32lib, 120);

      if status ~= 0
         break
      end

      % Capture DFFT
      dfft_index = mod(k - 1, DFFT_BUFFER_DEPTH);
      dopp_emb_name = ['(*dp_dfft_bv_output_buffer) [', num2str(dfft_index), ']'];
      [status, dfft_data] = t32_read_mem(t32lib, dopp_emb_name, 1);

      if status ~= 0
         break
      end

      dfft_comp_data_temp_i16(k, :) = (typecast(dfft_data, 'int16'));
      dfft_comp_data_temp_u16(k, :) = (typecast(dfft_data, 'uint16'));

      [status, rdop_avg_NCI, rdop_nci_bexp] = Read_NCI_Data(t32lib, k, NCI_BUFFER_DEPTH, num_angles, max_dfft_size, rdop_avg_NCI, rdop_nci_bexp);

      if status ~= 1
         break
      end

      last_update = print_update('Collected data for rangebin', last_update, k, rbins_used);

      if disable_write_outputs == 0
         % For the print_update function, if other prints are enabled, need to set last_update to 0
         % so that the function doesn't overwrite any print info.
         last_update = 0;
      end
   end

   t32_cmd(t32lib, 'Intercom BBE32 Go');
   status = t32_wait_for_bbe_breakpoint(t32lib, 120);

   if status == 0
      [status, rdop_avg_NCI, rdop_nci_bexp] = Read_NCI_Data(t32lib, rbins_used + 1, NCI_BUFFER_DEPTH, num_angles, max_dfft_size, rdop_avg_NCI, rdop_nci_bexp);
   end

   % Accounts for the circular buffer update between the last two first
   % pass execute calls.
   t32_cmd(t32lib, 'Intercom BBE32 Go');
   if status == 1
      status = t32_wait_for_bbe_breakpoint(t32lib, 120);
   end

   % At this point, should still be at the Circular_Buffer_Update
   % breakpoint, this is the last one, and the next Go statement will
   % run until the BBE is at signal processing done state where we can
   % collect AF and RDD thresholds from the output RDD_Data and Detection
   % structures.

   if status == 0
      % [LookProc_embed_out.dfft_decomp_data, LookProc_embed_debug_signal.dfft_comp_data_u64] = decomp_dfft_data(dfft_comp_data_temp_u16, max_dfft_size, rbins_used, num_rx_channels, doppler_compression_lvl, 0);
      [dfft_decomp_data, scaled_nci, dop_out_comp_defito] = multiangle_data_analysis(dfft_comp_data_temp_i16, rdop_avg_NCI, rdop_nci_bexp, max_dfft_size, num_angles, rbins_used, doppler_compression_lvl);
      LookProc_embed_debug_signal.dfft_comp_data = dop_out_comp_defito;
      LookProc_embed_out.dopp_fft_decomp = dfft_decomp_data;
      LookProc_embed_out.scaled_nci = scaled_nci;
      LookProc_embed_out.rdop_avg_NCI = rdop_avg_NCI;
      LookProc_embed_out.nci_bexp = rdop_nci_bexp;

   end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Read_NCI_Data
%   This function reads the NCI based on the current iteration counter.
%   The NCI data is 1 bin behind the doppler.
%  Inputs:
%   t32lib - t32 library handle
%   doppler_idx - current 1 based doppler index
%   nci_buffer_depth - The depth of the NCI buffer in the embedded
%   rdop_avg_NCI - The full rdop_avg_NCI structure for all range bins
%  Outputs:
%   status - 0 for success, non-zero for failure.
%   rdop_avg_NCI - The full rdop_avg_NCI structure for all range bins with the
%                  current nci_index updated.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status, rdop_avg_NCI, rdop_nci_bexp] = Read_NCI_Data(t32lib, doppler_idx, nci_buffer_depth, num_angles, max_dfft_size, rdop_avg_NCI, rdop_nci_bexp)
   if doppler_idx > 1
      nci_index = doppler_idx - 1;
      % This index is 0 based, but doppler_idx is 1 based:
      %    doppler_idx - 1 is matlab index.
      %    doppler_idx - 2 is c-based index
      nci_index_embed = mod(doppler_idx - 2, nci_buffer_depth);
      nci_bexp_index_embed = mod(doppler_idx - 2, nci_buffer_depth);

      nci_emb_name = ['(*(dp_rdop_avg_nci_data))[', num2str(nci_index_embed), ']'];
      [status1, rdop_avg_array] = t32_read_mem(t32lib, nci_emb_name, 1);

      nci_bexp_emb_name = ['(*(dp_nci_bexp))[', num2str(nci_bexp_index_embed), ']'];
      [status2, nci_bexp_array] = t32_read_mem(t32lib, nci_bexp_emb_name, 1);

      status = (status1 == 0 && status2 == 0);

      if status == 1
         rdop_avg_uint16 = (typecast(rdop_avg_array, 'uint16'));
         nci_bexp_uint16 = (typecast(nci_bexp_array, 'uint16'));
         rdop_avg_NCI(nci_index, :, :) = double(reshape(rdop_avg_uint16, [max_dfft_size, num_angles]))';
         temp = double(reshape(nci_bexp_uint16, [num_angles, num_angles]))';
         rdop_nci_bexp(nci_index, 1:num_angles) = temp(:, 1);
      end

   else
      status = 1;
   end

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Read_CI_Data
%   This function reads the CI based on the current iteration counter.
%   The CI data is 1 bin behind the doppler.
%  Inputs:
%   t32lib - t32 library handle
%   doppler_idx - current 1 based doppler index
%   ci_buffer_depth - The depth of the CI buffer in the embedded
%   rdop_avg_CI - The full rdop_avg_CI structure for all range bins
%  Outputs:
%   status - 0 for success, non-zero for failure.
%   rdop_avg_CI - The full rdop_avg_CI structure for all range bins with the
%                  current ci_index updated.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status, rdop_avg_CI] = Read_CI_Data(t32lib, doppler_idx, ci_buffer_depth, rdop_avg_CI)
   if doppler_idx > 1
      ci_index = doppler_idx - 1;
      % This index is 0 based, but doppler_idx is 1 based:
      %    doppler_idx - 1 is matlab index.
      %    doppler_idx - 2 is c-based index
      ci_index_embed = mod(doppler_idx - 2, ci_buffer_depth);

      ci_emb_name = ['(*(ci_rdop_avg_data))[', num2str(ci_index_embed), ']'];
      [status, rdop_avg_array_ci] = t32_read_mem(t32lib, ci_emb_name, 1);

      if status == 0
         rdop_avg_ci_uint16 = (typecast(rdop_avg_array_ci, 'uint16'));
         rdop_avg_CI(ci_index, :) = double(rdop_avg_ci_uint16);
      end
   else
      status = 0;
   end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Read_AA_Data
%   This function reads the AA intermediate data based on the current iteration counter.
%   The AA data is 1 bin behind the doppler.
%  Inputs:
%   t32lib - t32 library handle
%   doppler_idx - current 1 based doppler index
%   nci_buffer_depth - The depth of the NCI buffer in the embedded
%   rdop_avg_NCI - The full rdop_avg_NCI structure for all range bins
%  Outputs:
%   status - 0 for success, non-zero for failure.
%   rdop_avg_NCI - The full rdop_avg_NCI structure for all range bins with the
%                  current nci_index updated.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status, aa_data] = Read_AA_Data(t32lib, doppler_idx, aa_data)
   inbuf0_addr = hex2dec('84200000');
   inbuf1_addr = inbuf0_addr + 4096;
   inbuf2_addr = inbuf1_addr + 4096;
   inbuf3_addr = inbuf2_addr + 4096;

   aa_index = doppler_idx - 2;

   if doppler_idx > 2
      if doppler_idx == 3   % First range bin is different - NCI is processed first but current data will be in INBUF1
         % First time first pass runs - go to get to the start of the CI processing
         t32_cmd(t32lib, 'Intercom BBE32 Go');
         status = t32_wait_for_bbe_breakpoint(t32lib, 120);

         if status == 0
            [status, aa_data.nci] = Read_AA_Results_Data(t32lib, aa_index, aa_data.nci, inbuf1_addr);
         end

         if status == 0
            % Run past the CI processing.
            t32_cmd(t32lib, 'Intercom BBE32 Go');
            status = t32_wait_for_bbe_breakpoint(t32lib, 120);
         end

         if status == 0
            [status, aa_data.ci] = Read_AA_Results_Data(t32lib, aa_index, aa_data.ci, inbuf1_addr);
         end
      else
         [status, ci_running] = t32_read_mem(t32lib, 'Rdd_Fp_Internal_Data.prior_rbin_data_ci', 1);

         if status == 0
            t32_cmd(t32lib, 'Intercom BBE32 Go');
            status = t32_wait_for_bbe_breakpoint(t32lib, 120);
         end

         if status == 0
            if ci_running == 1
               [status, aa_data.ci] = Read_AA_Results_Data(t32lib, aa_index, aa_data.ci, inbuf2_addr);
               ci_running = 0;
            else
               [status, aa_data.nci] = Read_AA_Results_Data(t32lib, aa_index, aa_data.nci, inbuf2_addr);
               ci_running = 1;
            end
         end

         if status == 0
            t32_cmd(t32lib, 'Intercom BBE32 Go');
            status = t32_wait_for_bbe_breakpoint(t32lib, 120);
         end

         if status == 0
            if ci_running == 1
               [status, aa_data.ci] = Read_AA_Results_Data(t32lib, aa_index, aa_data.ci, inbuf2_addr);
            else
               [status, aa_data.nci] = Read_AA_Results_Data(t32lib, aa_index, aa_data.nci, inbuf2_addr);
            end
         end
      end
   else
      status = 0;
   end

end

%  uint16_t num_det;
%  int16_t out_sort[1024];
%  int16_t out_thresh[1024];
%  uint16_t out_dets[1024];
%  uint8_t out_bitmap[256];
%  int16_t log2_data_pre[1024];
%  int16_t log2_data_curr[1024];
%  int16_t log2_data_next[1024];
function [status, aa_data] = Read_AA_Results_Data(t32lib, aa_index, aa_data, inbuf_addr)
   aa_out_mem = '(*(Rdd_Fp_Internal_Data.p_cfar_out)).aa_out.';

   [status, log2_inputs] = t32_read_address(t32lib, inbuf_addr, 2048, 1);

   if status == 0
      [status, num_det] = t32_read_mem(t32lib, strcat(aa_out_mem, 'num_det'), 1);
   end

   if status == 0
      [status, out_sort] = t32_read_mem(t32lib, strcat(aa_out_mem, 'out_sort'), 1);
   end

   if status == 0
      [status, out_thresh] = t32_read_mem(t32lib, strcat(aa_out_mem, 'out_thresh'), 1);
   end

   if status == 0
      [status, out_dets] = t32_read_mem(t32lib, strcat(aa_out_mem, 'out_dets'), 1);
   end

   if status == 0
      [status, out_bitmap] = t32_read_mem(t32lib, strcat(aa_out_mem, 'out_bitmap'), 1);
   end

   if status == 0
      [status, log2_data_pre] = t32_read_mem(t32lib, strcat(aa_out_mem, 'log2_data_pre'), 1);
   end

   if status == 0
      [status, log2_data_curr] = t32_read_mem(t32lib, strcat(aa_out_mem, 'log2_data_curr'), 1);
   end

   if status == 0
      [status, log2_data_next] = t32_read_mem(t32lib, strcat(aa_out_mem, 'log2_data_next'), 1);
   end

   if status == 0
      aa_data.log2_inputs(aa_index, :) = typecast(log2_inputs, 'int16');

      aa_data.num_det(aa_index) = typecast(num_det, 'uint16');
      aa_data.out_sort(aa_index, :) = typecast(out_sort, 'int16');
      aa_data.out_thresh(aa_index, :) = typecast(out_thresh, 'int16');
      aa_data.out_dets(aa_index, :) = typecast(out_dets, 'uint16');
      aa_data.out_bitmap(aa_index, :) = typecast(out_bitmap, 'uint8');
      aa_data.log2_data_pre(aa_index, :) = typecast(log2_data_pre, 'int16');
      aa_data.log2_data_curr(aa_index, :) = typecast(log2_data_curr, 'int16');
      aa_data.log2_data_next(aa_index, :) = typecast(log2_data_next, 'int16');
   end

end
