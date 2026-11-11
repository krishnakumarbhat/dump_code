% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_SPdata_collect()
%   This function collects Secondpass embedded data from the t32
%  Inputs:
%   look_type
%   smc_cal
%
%  Outputs:
%   Secondpass_embed_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status, Secondpass_embed_out, Secondpass_embed_debug_signal] = t32_SPdata_collect(look_type, t32lib, smc_cal, FP_embed_out)

   Secondpass_embed_out = struct();
   Secondpass_embed_out_temp = struct();
   Secondpass_embed_debug_signal = struct();
   rbins_used = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   %% second_pass_thold
   for j = 0:rbins_used - 1
      second_pass_thold_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd2_thold_2nd_pass[', num2str(j), '] '];
      [status, second_pass_thold] = t32_read_mem(t32lib, second_pass_thold_emb_name, 1);
      second_pass_thold_out(j + 1, :) = typecast(second_pass_thold, 'uint32');
   end

   % Clip the leading and trailing range bins so the final outputs contain
   % processed range bins only - (Embedded doesn't process the leading and trailing range bins)
   second_pass_thold_out = second_pass_thold_out(2:end - 1, :);

   [status, range] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd2_range', 1);
   if status ~= 0
      fprintf("Error reading rdd2_range");
   end

   [status, range_rate] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd2_range_rate', 1);
   if status ~= 0
      fprintf("Error reading rdd2_range_rate");
   end

   [status, snr] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd2_snr', 1);
   if status ~= 0
      fprintf("Error reading rdd2_snr");
   end

   [status, num_detect] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd2_num_detect', 1);
   if status ~= 0
      fprintf("Error reading rdd2_num_detect");
   end

   [status, sp_fail_flag] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd2_sp_fail_flag', 1);
   if status ~= 0
      fprintf("Error reading rdd2_sp_fail_flag");
   end

   [status, below_sp_thold] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.below_sp_thold', 1);
   if status ~= 0
      fprintf("Error reading below_sp_thold");
   end

   if 0 == status
      Secondpass_embed_out.numDetected = typecast(num_detect, 'uint16');
      Secondpass_embed_out.range = typecast(range, 'int32');
      Secondpass_embed_out.range_rate = typecast(range_rate, 'int32');
      Secondpass_embed_out.snr = typecast(snr, 'int32');
      Secondpass_embed_out.sp_fail_flag = typecast(sp_fail_flag, 'uint8');
      Secondpass_embed_out.below_sp_thold = typecast(below_sp_thold, 'uint8');

      Secondpass_embed_out.thold_2nd_pass = second_pass_thold_out;
   end
   % Load firstpass outputs to get the reconstructed indices
   n_r = numel(FP_embed_out.rindx);
   n_d = numel(FP_embed_out.dindx);
   n_a = numel(FP_embed_out.aindx);
   n = min([n_r, n_d, n_a, FP_embed_out.numDetected]);

   Secondpass_embed_out.sp_fail_flag = Secondpass_embed_out.sp_fail_flag(1:n);

   j = 1;

   for i = 1:n
      if Secondpass_embed_out.sp_fail_flag(i) == 0
         Secondpass_embed_debug_signal.rindx(j) = FP_embed_out.rindx(i);
         Secondpass_embed_debug_signal.dindx(j) = FP_embed_out.dindx(i);
         Secondpass_embed_debug_signal.aindx(j) = FP_embed_out.aindx(i);
         Secondpass_embed_out_temp.range(j) = Secondpass_embed_out.range(i);
         Secondpass_embed_out_temp.range_rate(j) = Secondpass_embed_out.range_rate(i);
         Secondpass_embed_out_temp.snr(j) = Secondpass_embed_out.snr(i);
         Secondpass_embed_out_temp.sp_fail_flag(j) = Secondpass_embed_out.sp_fail_flag(i);
         Secondpass_embed_out_temp.below_sp_thold(j) = Secondpass_embed_out.below_sp_thold(i);
         j = j + 1;
      end
   end

   Secondpass_embed_debug_signal.rindx = Secondpass_embed_debug_signal.rindx';
   Secondpass_embed_debug_signal.dindx = Secondpass_embed_debug_signal.dindx';
   Secondpass_embed_debug_signal.aindx = Secondpass_embed_debug_signal.aindx';
   Secondpass_embed_out.range = Secondpass_embed_out_temp.range';
   Secondpass_embed_out.range_rate = Secondpass_embed_out_temp.range_rate';
   Secondpass_embed_out.snr = Secondpass_embed_out_temp.snr';
   Secondpass_embed_out.sp_fail_flag = Secondpass_embed_out_temp.sp_fail_flag.';
   Secondpass_embed_out.below_sp_thold = Secondpass_embed_out_temp.below_sp_thold.';
end
