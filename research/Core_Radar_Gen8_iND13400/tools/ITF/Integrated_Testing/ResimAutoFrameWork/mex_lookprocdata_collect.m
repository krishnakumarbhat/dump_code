% %%% API for collecting RFFT Mex data from the lookprocessing module %%
%  Name: mex_lookprocdata_collect()
%   This function creates the stucture of look processing for Mex
%  Inputs:
%   look_string
%
%  Outputs:
%  Lookproc_mex_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [Lookproc_mex_out] = mex_lookprocdata_collect(look_string, download_data_set)

   Lookproc_mex_out = struct();
   if ~download_data_set
      % load intermediate outputs from mex
      load('Mex_Executable_Specs\Data\current_state_dfft.mat');
   else
      % load intermediate outputs from mex
      load('mex_output\current_state_dfft.mat');
   end
   Lookproc_mex_out.range_fft_decomp = rfftResult; % Raw RFFT without min chirp scaling
   Lookproc_mex_out.range_fft_mcs = rfftOutput_emb; % RFFT with min chirp scaling applied
   Lookproc_mex_out.dopp_fft_decomp = dfftResult_emb;
   Lookproc_mex_out.min_chirp_scaling = range_end_min_shift;
   Lookproc_mex_out.rdop_avg_NCI = nciResult_ang;

   Lookproc_mex_out.dopp_fft_decomp = permute(Lookproc_mex_out.dopp_fft_decomp, [3, 1, 2]);

end
