% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_LP_Range_data_collect()
%   This function collects the Range embedded data from the t32
%  Inputs:
%   look_type
%   t32lib
%   smc_cal
%
%  Outputs:
%   LookProc_embed_out
%   LookProc_embed_debug_signal
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [LookProc_embed_out, LookProc_embed_debug_signal] = t32_LP_Range_data_collect(look_type, t32lib, smc_cal)

   num_chirps = smc_cal.Configuration.BB_Configuration.K_FRAME.VALUE(look_type);
   rbins_used = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   max_chirps = smc_cal.Configuration.BB_Configuration.K_MAX.VALUE;
   max_dfft_size = smc_cal.Configuration.BB_Configuration.MAX_DOPPLER_FFT_SIZE.VALUE;
   num_rx_channels = smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE;
   num_tx_channels = smc_cal.Configuration.BB_Configuration.NUM_TX_CHANNELS.VALUE;
   max_detections = smc_cal.Configuration.BB_Configuration.MAX_DETS_FIRST_PASS.VALUE;
   range_clvl = 10;
   range_clvl_low = 7;
   num_range_bin_lowcomp = 160;

   LookProc_embed_out = struct();
   LookProc_embed_debug_signal = struct();
   [status, range_data] = t32_read_mem(t32lib, 'RangeProc_OutputDataCube', 1);

   if status ~= 0
      fprintf("Error reading Range Processing Output");
   end

   if status == 0
      [status, min_chirp_scaling] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.min_chirp_scaling', 1);
      if status ~= 0
         fprintf("Error reading min_chirp_scaling");
      end
   end

   if status == 0
      [status, mipi_idm_stats] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_debug_data.idm_stat_data', 1);
      if status ~= 0
         fprintf("Error reading idm stats data");
      else
         idm_data_u16 = (typecast(mipi_idm_stats, 'uint16'));
         idm_data = reshape(idm_data_u16, [max_chirps, num_rx_channels * 3]);
         for rx = 1:num_rx_channels
            idm_data_out.idm_polluted_counter(1:max_chirps, rx) = idm_data(:, ((rx - 1) * 3) + 1);
            idm_data_out.idm_accumulator_threshold(1:max_chirps, rx) = idm_data(:, ((rx - 1) * 3) + 2);
            idm_data_out.dc_accumulator(1:max_chirps, rx) = idm_data(1:max_chirps, ((rx - 1) * 3) + 3);

         end
         idm_data_final = idm_data_out;
      end
   end

   if status  == 0

      base_addr_high = num_chirps * num_range_bin_lowcomp * 8; % 8 here is for 64 bit compression.
      low_comp_data = range_data(1:base_addr_high);
      high_comp_data = range_data((base_addr_high + 1):end);
      range_decomp_data_high = decompress_rfft_data(high_comp_data, typecast(min_chirp_scaling, 'uint8'), num_chirps, rbins_used - num_range_bin_lowcomp, range_clvl, num_rx_channels, 1);
      range_decomp_data_low = decompress_rfft_data(low_comp_data, typecast(min_chirp_scaling, 'uint8'), num_chirps, num_range_bin_lowcomp, range_clvl_low, num_rx_channels, 1);
      range_decomp_data = cat(2, range_decomp_data_low, range_decomp_data_high);

      LookProc_embed_out.range_fft = range_data;
      LookProc_embed_out.range_fft_decomp = range_decomp_data;
      LookProc_embed_out.min_chirp_scale = typecast(min_chirp_scaling, 'uint8');
      LookProc_embed_debug_signal.idm_stats = idm_data_final;

      LookProc_embed_out.range_fft_decomp = permute(LookProc_embed_out.range_fft_decomp, [2, 1, 3]);

   end

end
