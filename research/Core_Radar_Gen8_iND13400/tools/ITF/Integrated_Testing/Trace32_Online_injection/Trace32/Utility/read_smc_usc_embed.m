%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: read_smc_usc_embed(t32lib)
%   Application specific function to read smc and usc version from embedded
%   software
%
% Inputs:
%   t32lib Trace32 instance
% Return Variables:
% status :  0 for ok, otherwise Error value
% smc_cal_data is going to return the smc of the flashed embedded software
% usc_cal_data is going to return the usc of the flashed embedded software
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status, Embed_smc_val, Embed_usc_val] = read_smc_usc_embed(t32lib)

   [status, smc_array.sec_comp] = t32_read_mem(t32lib, 'SMC_Cal_Data.Header2_Info.section_compatibility', 1);
   if status ~= 0
      fprintf("Error reading smc section_compatibility");
   end
   if status == 0
      [status, smc_array.platform] = t32_read_mem(t32lib, 'SMC_Cal_Data.Header2_Info.platform', 1);
      if status ~= 0
         fprintf("Error reading smc platform");
      end
   end
   if status == 0
      [status, smc_array.customer] = t32_read_mem(t32lib, 'SMC_Cal_Data.Header2_Info.customer', 1);
      if status ~= 0
         fprintf("Error reading smc customer");
      end
   end
   if status == 0
      [status, smc_array.version] = t32_read_mem(t32lib, 'SMC_Cal_Data.Header2_Info.version', 1);
      if status ~= 0
         fprintf("Error reading smc version");
      end
   end
   if status == 0
      [status, usc_array.sec_comp] = t32_read_mem(t32lib, 'USC_Cal_Data.Header2_Info.section_compatibility', 1);
      if status ~= 0
         fprintf("Error reading usc sec_comp");
      end
   end
   if status == 0
      [status, usc_array.platform] = t32_read_mem(t32lib, 'USC_Cal_Data.Header2_Info.platform', 1);
      if status ~= 0
         fprintf("Error reading usc platform");
      end
   end
   if status == 0
      [status, usc_array.customer] = t32_read_mem(t32lib, 'USC_Cal_Data.Header2_Info.customer', 1);
      if status ~= 0
         fprintf("Error reading usc customer");
      end
   end
   if status == 0
      [status, usc_array.version] = t32_read_mem(t32lib, 'USC_Cal_Data.Header2_Info.version', 1);
      if status ~= 0
         fprintf("Error reading usc version");
      end
   end
   if 0 == status

      Embed_smc_val.sec_comp = typecast(smc_array.sec_comp, 'uint8');
      Embed_smc_val.platform = typecast(smc_array.platform, 'uint8');
      Embed_smc_val.customer = typecast(smc_array.customer, 'uint8');
      Embed_smc_val.version = typecast(smc_array.version, 'uint16');
      Embed_usc_val.sec_comp = typecast(usc_array.sec_comp, 'uint8');
      Embed_usc_val.platform = typecast(usc_array.platform, 'uint8');
      Embed_usc_val.customer = typecast(usc_array.customer, 'uint8');
      Embed_usc_val.version = typecast(usc_array.version, 'uint16');
   else
      Embed_smc_val.sec_comp = 0;
      Embed_smc_val.platform = 0;
      Embed_smc_val.customer = 0;
      Embed_smc_val.version = 0;
      Embed_usc_val.sec_comp = 0;
      Embed_usc_val.platform = 0;
      Embed_usc_val.customer = 0;
      Embed_usc_val.version = 0;
   end
end
