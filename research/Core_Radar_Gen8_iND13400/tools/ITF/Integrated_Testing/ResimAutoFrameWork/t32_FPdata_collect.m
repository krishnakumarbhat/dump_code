% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_Firstpsasdata_collect()
%   This function collects Firstpass embedded data from the t32
%  Inputs:
%   look_type
%   smc_cal
%   LookProc_embed_out
%
%  Outputs:
%   Firstpass_embed_out
%   Firstpass_embed_debug_signal
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status, Firstpass_embed_out, Firstpass_embed_debug_signal] = t32_FPdata_collect(look_type, t32lib, smc_cal, LookProc_embed_out, LookProc_embed_debug_signal)

   num_rx_antennas = smc_cal.Configuration.BB_Configuration.NUM_RX_ANTENNAS.VALUE;
   rbins_used = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   ddm_shift = smc_cal.SMC.Look_Processing.k_ddma_doppler_bin_shift.VALUE(look_type);
   nrx = smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE;
   ntx = smc_cal.Configuration.BB_Configuration.NUM_TX_CHANNELS.VALUE;

   Firstpass_embed_out = struct();
   Firstpass_embed_debug_signal = struct();

   [status, rbinest] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_rbinest', 1);
   if status ~= 0
      fprintf("Error reading rdd1_rbinest");
   end

   [status, dbinest] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_dbinest', 1);
   if status ~= 0
      fprintf("Error reading rdd1_dbinest");
   end

   [status, abinest] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_abinest', 1);
   if status ~= 0
      fprintf("Error reading rdd1_abinest");
   end

   %% max_per_range_bin
   for j = 0:rbins_used - 1
      max_per_range_bin_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_max_per_range_bin[', num2str(j), '] '];
      [status, max_per_range_bin] = t32_read_mem(t32lib, max_per_range_bin_emb_name, 1);
      max_per_range_bin_out(j + 1, :) = typecast(max_per_range_bin, 'uint16');
   end

   if status ~= 0
      fprintf("Error reading rdd1_max_per_range_bin");
   end

   %% Signal thold first pass
   for j = 0:rbins_used - 1
      sig_thold_first_pass_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_signal_thold_first_pass[', num2str(j), '] '];
      [status, sig_thold_first_pass] = t32_read_mem(t32lib, sig_thold_first_pass_emb_name, 1);
      sig_thold_first_pass_out(j + 1, :) = typecast(sig_thold_first_pass, 'uint16');
   end

   if status ~= 0
      fprintf("Error reading rdd1_signal_thold_first_pass");
   end

   %% first_pass_thold
   for j = 0:rbins_used - 1
      first_pass_thold_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_first_pass_thold[', num2str(j), '] '];
      [status, first_pass_thold] = t32_read_mem(t32lib, first_pass_thold_emb_name, 1);
      first_pass_thold_out(j + 1, :) = typecast(first_pass_thold, 'uint16');
   end

   if status ~= 0
      fprintf("Error reading rdd1_first_pass_thold");
   end

   %% Block exponent
   for j = 0:rbins_used - 1
      nci_bexp_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.nci_bexp[', num2str(j), '] '];
      [status, nci_bexp] = t32_read_mem(t32lib, nci_bexp_emb_name, 1);
      nci_bexp_out(j + 1, :) = typecast(nci_bexp, 'uint16');
   end

   if status ~= 0
      fprintf("Error reading nci_bexp");
   end

   [status, rdop_amp] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_rdop_amp', 1);
   if status ~= 0
      fprintf("Error reading rdd1_rdop_amp");
   end

   [status, rindx] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_rindx', 1);
   if status ~= 0
      fprintf("Error reading rdd1_rindx");
   end

   [status, dindx] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_dindx', 1);
   if status ~= 0
      fprintf("Error reading rdd1_dindx");
   end

   [status, aindx] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_aindx', 1);
   if status ~= 0
      fprintf("Error reading rdd1_aindx");
   end

   [status, bv] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_bv', 1);
   if status ~= 0
      fprintf("Error reading rdd1_bv");
   end

   [status, num_detect] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_num_detect', 1);
   if status ~= 0
      fprintf("Error reading rdd1_num_detect");
   end

   if 0 == status

      Firstpass_embed_out.numDetected = typecast(num_detect, 'uint16');

      rindx = typecast(rindx, 'uint16');
      dindx = typecast(dindx, 'uint16');
      aindx = typecast(aindx, 'uint16');
      rdop_amp = typecast(rdop_amp, 'uint16');
      rbinest = typecast(rbinest, 'int32');
      dbinest = typecast(dbinest, 'int32');
      abinest = typecast(abinest, 'int32');
      if Firstpass_embed_out.numDetected > 0

         for i = 1:Firstpass_embed_out.numDetected
            Firstpass_embed_out.rindx(i) = rindx(i);
            Firstpass_embed_out.dindx(i) = dindx(i);
            Firstpass_embed_out.aindx(i) = aindx(i);
            Firstpass_embed_out.rdop_amp(i) = rdop_amp(i);
            Firstpass_embed_out.rbinest(i) = rbinest(i);
            Firstpass_embed_out.dbinest(i)  = dbinest(i);
            Firstpass_embed_out.abinest(i)  = abinest(i);
         end

         Firstpass_embed_out.rindx = Firstpass_embed_out.rindx.';
         Firstpass_embed_out.dindx = Firstpass_embed_out.dindx.';
         Firstpass_embed_out.aindx = Firstpass_embed_out.aindx.';
         Firstpass_embed_out.rdop_amp = Firstpass_embed_out.rdop_amp.';
         Firstpass_embed_out.rbinest = Firstpass_embed_out.rbinest.';
         Firstpass_embed_out.dbinest = Firstpass_embed_out.dbinest.';
         Firstpass_embed_out.abinest = Firstpass_embed_out.abinest.';

         bv_uint32 = typecast(bv, 'uint32');
         bv_targets = bv_uint32(1:(num_rx_antennas * 2) * Firstpass_embed_out.numDetected);
         bv_comp = reshape(bv_targets, num_rx_antennas * 2, Firstpass_embed_out.numDetected);

         bv_uint16 = typecast(bv, 'uint16');
         bv_targets_u16 = bv_uint16(1:(4 * num_rx_antennas) * Firstpass_embed_out.numDetected);
         bv_comp_u16 = reshape(bv_targets_u16, 4 * num_rx_antennas, Firstpass_embed_out.numDetected);

         bv_int16 = typecast(bv, 'int16');
         bv_targets_i16 = bv_int16(1:(4 * num_rx_antennas) * Firstpass_embed_out.numDetected);
         bv_comp_i16 = reshape(bv_targets_i16, 2, 2 * num_rx_antennas, Firstpass_embed_out.numDetected);

         Firstpass_embed_debug_signal.bv = bv_comp;
         Firstpass_embed_debug_signal.bv_u16 = bv_comp_u16;
         Firstpass_embed_debug_signal.bv_i16 = bv_comp_i16;

         % Allocate with correct width
         fp_bv_decomp = zeros(2, ntx * nrx, Firstpass_embed_out.numDetected);

         for n = 1:Firstpass_embed_out.numDetected
            det_words = bv_comp_i16(:, :, n);
            [d, ovf] = decompress_data(det_words, 0, 6);
            fp_bv_decomp(1:2, 1:size(d, 2), n) = d;
         end
         Firstpass_embed_debug_signal.decomp_bv = reshape(fp_bv_decomp, ntx * num_rx_antennas, Firstpass_embed_out.numDetected);
         ddmshifted_dindx = verify_fp_bv_selection(Firstpass_embed_out, Firstpass_embed_debug_signal, LookProc_embed_out, LookProc_embed_debug_signal, smc_cal, look_type);
         Firstpass_embed_debug_signal.ddmshifted_dindx = ddmshifted_dindx;
      else
         Firstpass_embed_out.rindx = [];
         Firstpass_embed_out.dindx = [];
         Firstpass_embed_out.aindx = [];
         Firstpass_embed_out.rdop_amp = [];
         Firstpass_embed_out.rbinest = [];
         Firstpass_embed_out.dbinest = [];
         Firstpass_embed_out.abinest = [];

      end

      % Clip the leading and trailing range bins so the final outputs contain
      % processed range bins only - (Embedded doesn't process the leading and trailing range bins)
      max_per_range_bin_out = max_per_range_bin_out(2:end - 1, :);
      sig_thold_first_pass_out = sig_thold_first_pass_out(2:end - 1, :);
      first_pass_thold_out = first_pass_thold_out(2:end - 1, :);

      Firstpass_embed_out.max_per_range_bin = max_per_range_bin_out;
      Firstpass_embed_out.sig_thold_1st_pass = sig_thold_first_pass_out;
      Firstpass_embed_out.first_pass_thold = first_pass_thold_out;
      %% Moved to debug signal as it's not part of the spec output
      Firstpass_embed_debug_signal.nci_bexp = nci_bexp_out;
      Firstpass_embed_debug_signal.bv = reshape(bv_comp_i16, 32, Firstpass_embed_out.numDetected);
      Firstpass_embed_debug_signal.bv = Firstpass_embed_debug_signal.bv';
   end

end
