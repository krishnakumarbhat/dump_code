% %%% API for collecting t32(embedded) data from the Radar Sensor %%
%  Name: t32_AFdata_collect()
%   This function collects the embedded data from the t32 for all the SPBB
%   modules
%  Inputs:
%   look_string
%
%  Outputs:
%   AF_output_embed
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status, AF_output_embed] = t32_AFdata_collect(look_type, t32lib)

   % Angle Finding

   AF_output_embed = struct();

   [status, num_af_det] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].payload.det_data.af_data.num_af_det', 1);
   AF_output_embed.num_af_det = typecast(num_af_det, 'int32');
   for i = 1:num_af_det(look_type)
      [status, ran] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.ran', i, status, 'single', t32lib);
      AF_output_embed.ran(i) = ran;
      [status, vel] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.vel', i, status, 'single', t32lib);
      AF_output_embed.vel(i) = vel;
      [status, pow] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.pow', i, status, 'single', t32lib);
      AF_output_embed.pow(i) = pow;
      [status, snr] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.snr', i, status, 'single', t32lib);
      AF_output_embed.snr(i) = snr;
      [status, theta] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.theta', i, status, 'single', t32lib);
      AF_output_embed.theta(i) = theta;
      [status, phi] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.phi', i, status, 'single', t32lib);
      AF_output_embed.phi(i) = phi;
      [status, az_conf] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.az_conf', i, status, 'int8', t32lib);
      AF_output_embed.az_conf(i) = az_conf;
      [status, el_conf] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.el_conf', i, status, 'int8', t32lib);
      AF_output_embed.el_conf(i) = el_conf;
      [status, f_single_target] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.f_single_target', i, status, 'int8', t32lib);
      AF_output_embed.f_single_target(i) = f_single_target;
      [status, f_superres_target] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.f_superres_target', i, status, 'int8', t32lib);
      AF_output_embed.f_superres_target(i) = f_superres_target;
      [status, f_bistatic] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.f_bistatic', i, status, 'int8', t32lib);
      AF_output_embed.f_bistatic(i) = f_bistatic;
      [status, spec_res] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.spec_res', i, status, 'single', t32lib);
      AF_output_embed.spec_res(i) = spec_res;
      [status, rdd_idx] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.rdd_idx', i, status, 'int16', t32lib);
      AF_output_embed.rdd_idx(i) = rdd_idx;
      [status, rcs] = Read_Array_Value('IPC_D2M_Buffer[0].payload.det_data.af_data.rcs', i, status, 'single', t32lib);
      AF_output_embed.rcs(i) = rcs;
   end

   function [status, value] = Read_Array_Value(value_name, index, status, type, t32lib)
      index = 0;
      if status == 0
         value_to_read = sprintf('%s[%d]', value_name, index);
         [status, buffer] = t32_read_mem(t32lib, value_to_read, 1);
         if status == 0
            value = typecast(buffer, type);
         end
      end
   end

end
