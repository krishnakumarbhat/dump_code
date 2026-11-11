% %%% API for collecting RFFT Spec data from the lookprocessing module %%
%  Name: spec_lookprocdata_collect()
%   This function creates the stucture of look processing for Spec
%  Inputs:
%   look_string
%
%  Outputs:
% Lookproc_spec_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [Lookproc_spec_out] = spec_lookprocdata_collect(look_string)

   Lookproc_spec_out = struct();

   % load intermediate outputs from spec
   load(['.\Executable_Specs\Data\IQ_data_' look_string, '_' look_string, '_LookProcessing.mat']);

   Lookproc_spec_out.range_fft = permute(range_fft, [2 3 1]);
   Lookproc_spec_out.dopp_fft = permute(dopp_fft, [2 3 1]);
   Lookproc_spec_out.rdop_avg_NCI = permute(rdop_avg, [1 3 2]);
   Lookproc_spec_out.min_chirp_scaling = totalScaling;

end
