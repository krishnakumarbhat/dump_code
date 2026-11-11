% %%% API for collecting CFAR Spec data from the CFAR module %%
%  Name: mex_cfardata_collect()
%   This function creates the stucture of CFAR for Spec
%  Inputs:
%   look_string
%
%  Outputs:
% CFAR_spec_out
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function   [CFAR_spec_out] = spec_cfardata_collect(look_string)

   CFAR_spec_out = struct();

   % load intermediate outputs from spec
   load(['.\Executable_Specs\Data\IQ_data_' look_string, '_' look_string, '_CFAR.mat']);

   CFAR_spec_out.CFAR_NF_est = nf_estimate;
   CFAR_spec_out.CFAR_thold = cfar_threshold;

end
