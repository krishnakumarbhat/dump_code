% %%% API for collecting BW Dependent Mex data from the BW module %%
%  Name: mex_BWdata_collect()
%   This function creates the stucture of BW for Mex
%  Inputs:
%   look_string
%
%  Outputs:
%  BW_mex_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function   [BW_mex_out] = mex_BWdata_collect(look_string, download_data_set)

   BW_mex_out = struct();

   if ~download_data_set
      % load intermediate outputs from mex
      load('Mex_Executable_Specs\Data\current_state_dfft.mat');
   else
      % load intermediate outputs from downloaded mex outputs
      load('mex_output\current_state_dfft.mat');
   end
   BW_mex_out.CR_Response = cr_response.';
   BW_mex_out.Sensitivity_Threshold = thold_sensitivity.';
   BW_mex_out.HVC_Threshold = thold_hvc.';
   BW_mex_out.MB_Threshold = thold_mb.';

end
