% %%% API for collecting BW Dependent Spec data from the BWDP module %%
%  Name: mex_BWdata_collect()
%   This function creates the stucture of BW for Spec
%  Inputs:
%   look_string
%
%  Outputs:
% BW_spec_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function   [BW_spec_out] = spec_BWdata_collect(look_string)

   BW_spec_out = struct();

   % load intermediate outputs from Spec
   load(['.\Executable_Specs\Data\IQ_data_' look_string, '_' look_string, '_BWDP.mat']);

   BW_spec_out.CR_Response = cr_resp';
   BW_spec_out.Sensitivity_Threshold = sensitivity_threshold';
   BW_spec_out.HVC_Threshold = hvc_threshold';
   BW_spec_out.MB_Threshold = mb_threshold';

end
