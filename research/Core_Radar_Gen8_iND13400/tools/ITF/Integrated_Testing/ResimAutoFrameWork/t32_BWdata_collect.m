% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_BWdata_collect()
%   This function collects the BW dependent threshold embedded data from the t32
%  Inputs:
%   look_type
%   smc_cal
%
%  Outputs:
%   BW_embed_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status, BW_embed_out] = t32_BWdata_collect(look_type, t32lib, smc_cal)

   BW_embed_out = struct();

   [status, CR_Response] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.bwdep_cr_resp', 1);
   if status ~= 0
      fprintf("Error reading CR_Response");
   end

   [status, Sensitivity_Threshold] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.bwdep_sensitivity_thold', 1);
   if status ~= 0
      fprintf("Error reading Sensitivity_Threshold");
   end

   [status, HVC_Threshold] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.bwdep_hvc_thold', 1);
   if status ~= 0
      fprintf("Error reading HVC_Threshold");
   end

   [status, MB_Threshold] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.bwdep_mb_thold', 1);
   if status ~= 0
      fprintf("Error reading MB_Threshold");
   end

   if 0 == status
      CR_Response = typecast(CR_Response, 'uint32');
      Sensitivity_Threshold = typecast(Sensitivity_Threshold, 'uint32');
      HVC_Threshold = typecast(HVC_Threshold, 'uint32');
      MB_Threshold = typecast(MB_Threshold, 'uint32');

      BW_embed_out.CR_Response = CR_Response;
      BW_embed_out.Sensitivity_Threshold = Sensitivity_Threshold;
      BW_embed_out.HVC_Threshold = HVC_Threshold;
      BW_embed_out.MB_Threshold = MB_Threshold;
   end
end
