% %%% API for collecting Secondpass Mex data from the Secondpass module
%  Name: mex_Secondpassdata_collect()
%   This function creates the stucture of Secondpass for Mex
%  Inputs:
%   look_string
%
%  Outputs:
%   SP_mex_output
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [SP_mex_output, SP_mex_debug_signal] = mex_Secondpassdata_collect(look_string, Firstpass_mex_out, download_data_set)

   SP_mex_output = struct();
   SP_mex_output_temp = struct();
   SP_mex_debug_signal = struct();

   if ~download_data_set
      % load intermediate outputs from mex
      load('Mex_Executable_Specs\Data\current_state_dfft.mat');
   else
      % load intermediate outputs from downloaded mex outputs
      load('mex_output\current_state_dfft.mat');
   end
   SP_mex_output.numDetected = rdd_output.num_rdd_det;
   SP_mex_output.range = rdd_output.ran;
   SP_mex_output.range_rate = rdd_output.vel;
   SP_mex_output.snr = rdd_output.snr;
   SP_mex_output.sp_fail_flag = finalDetList.SP_fail_flag;
   SP_mex_output.below_sp_thold = finalDetList.below_SP_thold;
   SP_mex_output.thold_2nd_pass = finalDetList.secondpass_threshold_rbin;

   % Clip the leading and trailing range bins so the final outputs contain
   % processed range bins only - (Embedded doesn't process the leading and trailing range bins)
   SP_mex_output.thold_2nd_pass = SP_mex_output.thold_2nd_pass(2:end - 1, :);

   % Load firstpass outputs to get the reconstructed indices
   n_r = numel(Firstpass_mex_out.rindx);
   n_d = numel(Firstpass_mex_out.dindx);
   n_a = numel(Firstpass_mex_out.aindx);
   n = min([n_r, n_d, n_a, Firstpass_mex_out.numDetected]);

   SP_mex_output.sp_fail_flag = SP_mex_output.sp_fail_flag(1:n);
   j = 1;

   for i = 1:n
      if SP_mex_output.sp_fail_flag(i) == 0
         SP_mex_debug_signal.rindx(j) = Firstpass_mex_out.rindx(i);
         SP_mex_debug_signal.dindx(j) = Firstpass_mex_out.dindx(i);
         SP_mex_debug_signal.aindx(j) = Firstpass_mex_out.aindx(i);
         SP_mex_output_temp.sp_fail_flag(j) = SP_mex_output.sp_fail_flag(i);
         SP_mex_output_temp.below_sp_thold(j) = SP_mex_output.below_sp_thold(i);
         j = j + 1;
      end
   end
   SP_mex_debug_signal.rindx = SP_mex_debug_signal.rindx';
   SP_mex_debug_signal.dindx = SP_mex_debug_signal.dindx';
   SP_mex_debug_signal.aindx = SP_mex_debug_signal.aindx';

   SP_mex_output.sp_fail_flag = SP_mex_output_temp.sp_fail_flag';
   SP_mex_output.below_sp_thold = SP_mex_output_temp.below_sp_thold';

end
