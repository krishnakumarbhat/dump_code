% %%% API for collecting Angle Finding Mex data from the AF module
%  Name: mex_AngleFindingdata_collect()
%   This function creates the stucture of AF for Mex
%  Inputs:
%   look_string
%
%  Outputs:
%   AF_mex_output
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [AF_mex_output] = mex_AngleFindingdata_collect(look_string, download_data_set)

   AF_mex_output = struct();

   if ~download_data_set
      % load intermediate outputs from mex
      load('Mex_Executable_Specs\Data\current_state_af.mat');
   else
      % load intermediate outputs from downloaded mex outputs
      load('mex_output\current_state_af.mat');
   end

   AF_mex_output.num_AF_det = AF_det.num_AF_det;
   AF_mex_output.ran = AF_det.ran(1:AF_det.num_AF_det);
   AF_mex_output.vel = AF_det.vel(1:AF_det.num_AF_det);
   AF_mex_output.pow = AF_det.pow(1:AF_det.num_AF_det);
   AF_mex_output.snr = AF_det.snr(1:AF_det.num_AF_det);
   AF_mex_output.theta = AF_det.theta(1:AF_det.num_AF_det);
   AF_mex_output.phi = AF_det.phi(1:AF_det.num_AF_det);
   AF_mex_output.az_conf = AF_det.az_conf(1:AF_det.num_AF_det);
   AF_mex_output.el_conf = AF_det.el_conf(1:AF_det.num_AF_det);
   AF_mex_output.f_single_target = AF_det.f_single_target(1:AF_det.num_AF_det);
   AF_mex_output.f_superres_target = AF_det.f_superres_target(1:AF_det.num_AF_det);
   AF_mex_output.f_bistatic = AF_det.f_bistatic(1:AF_det.num_AF_det);
   AF_mex_output.spec_res = AF_det.spec_res(1:AF_det.num_AF_det);
   AF_mex_output.rdd_idx = AF_det.rdd_idx(1:AF_det.num_AF_det);
   AF_mex_output.rcs = AF_det.rcs(1:AF_det.num_AF_det);

   fields = fieldnames(AF_mex_output);
   for i = 1:numel(fields)
      AF_mex_output.(fields{i}) = AF_mex_output.(fields{i})';
   end
end
