% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_cfardata_collect()
%   This function collects the cfar embedded data from the t32
%  Inputs:
%   look_type
%   smc_cal
%
%  Outputs:
%   CFAR_embed_out
%   CFAR_embed_debug_signal
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status, CFAR_embed_out, CFAR_embed_debug_signal] = t32_cfardata_collect(look_type, t32lib, smc_cal)

   CFAR_embed_out = struct();
   CFAR_embed_debug_signal = struct();

   num_angles = smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE;
   rbins_used = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   cfar_nf_est_out = zeros(rbins_used, num_angles);

   %% cfar_nf_est
   for j = 0:rbins_used - 1
      cfar_nf_est_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.cfar_nf_est[', num2str(j), '] '];
      [status, cfar_nf_est] = t32_read_mem(t32lib, cfar_nf_est_emb_name, 1);
      cfar_nf_est_out(j + 1, :) = typecast(cfar_nf_est, 'uint16');
   end

   if status ~= 0
      fprintf("Error reading cfar_nf_est\n");
   end

   %% cfar_thold
   for j = 0:rbins_used - 1
      cfar_thold_emb_name = ['IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.cfar_thold[', num2str(j), '] '];
      [status, cfar_thold] = t32_read_mem(t32lib, cfar_thold_emb_name, 1);
      cfar_thold_out(j + 1, :) = typecast(cfar_thold, 'uint32');
   end
   if status ~= 0
      fprintf("Error reading cfar_thold\n");
   end
   if 0 == status
      CFAR_embed_out.CFAR_NF_est = cfar_nf_est_out;
      CFAR_embed_out.CFAR_thold = cfar_thold_out;
   end
end
