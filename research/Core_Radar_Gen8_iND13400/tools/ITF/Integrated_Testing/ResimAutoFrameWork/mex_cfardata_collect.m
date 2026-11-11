% %%% API for collecting CFAR Mex data from the CFAR module %%
%  Name: mex_cfardata_collect()
%   This function creates the stucture of CFAR for Mex
%  Inputs:
%   look_string
%
%  Outputs:
% CFAR_mex_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function   [CFAR_mex_out] = mex_cfardata_collect(look_string, download_data_set)

   CFAR_mex_out = struct();

   if ~download_data_set
      % load intermediate outputs from mex
      load('Mex_Executable_Specs\Data\current_state_dfft.mat');
   else
      % load intermediate outputs from downloaded mex outputs
      load('mex_output\current_state_dfft.mat');
   end
   CFAR_mex_out.CFAR_NF_est = finalDetList.NF_est;
   CFAR_mex_out.CFAR_thold = finalDetList.CFAR_thold;

end
