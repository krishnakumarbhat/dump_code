% %%% API for collecting Secondpass Spec data from the Secondpass module %%
%  Name: spec_Secondpassdata_collect()
%   This function creates the stucture of Secondpass for Spec
%  Inputs:
%   look_string
%
%  Outputs:
%   Secondpass_spec_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [Secondpass_spec_out, Secondpass_spec_debug_signal] = spec_Secondpassdata_collect(look_string, Firstpass_spec_out)

   Secondpass_spec_out = struct();
   Secondpass_embed_out_temp = struct();
   Secondpass_spec_debug_signal = struct();

   % load intermediate outputs from Spec
   load(['.\Executable_Specs\Data\IQ_data_' look_string, '_' look_string, '_SecondPass.mat']);
   Secondpass_spec_out.numDetected = rdd_output.numDetected - sum(rdd_output.SP_fail_flag);
   % Just Initialize to avoid structure mismatch issues.
   Secondpass_spec_out.range = [];
   Secondpass_spec_out.range_rate = [];
   Secondpass_spec_out.snr = [];
   Secondpass_spec_out.sp_fail_flag = rdd_output.second_pass_fail_flag';
   Secondpass_spec_out.below_sp_thold = rdd_output.below_SP_thold';
   Secondpass_spec_out.thold_2nd_pass = rdd_output.secondpass_threshold_rbin;

   % Clip the leading and trailing range bins so the final outputs contain
   % processed range bins only - (Embedded doesn't process the leading and trailing range bins)
   Secondpass_spec_out.thold_2nd_pass = Secondpass_spec_out.thold_2nd_pass(2:end - 1, :);

   if Secondpass_spec_out.numDetected > 0
      % Load firstpass outputs to get the reconstructed indices
      n_r = numel(Firstpass_spec_out.rindx);
      n_d = numel(Firstpass_spec_out.dindx);
      n_a = numel(Firstpass_spec_out.aindx);
      n = min([n_r, n_d, n_a, Firstpass_spec_out.numDetected]);
      j = 1;
      for i = 1:n
         if Secondpass_spec_out.sp_fail_flag(i) == 0
            Secondpass_spec_debug_signal.rindx(j) = Firstpass_spec_out.rindx(i);
            Secondpass_spec_debug_signal.dindx(j) = Firstpass_spec_out.dindx(i);
            Secondpass_spec_debug_signal.aindx(j) = Firstpass_spec_out.aindx(i);
            Secondpass_spec_out_temp.range(j) = rdd_output.range(i);
            Secondpass_spec_out_temp.range_rate(j) = rdd_output.range_rate(i);
            Secondpass_spec_out_temp.snr(j) = rdd_output.SNR(i);
            Secondpass_spec_out_temp.sp_fail_flag(j) = Secondpass_spec_out.sp_fail_flag(i);
            Secondpass_spec_out_temp.below_sp_thold(j) = Secondpass_spec_out.below_sp_thold(i);
            j = j + 1;
         end
      end
      Secondpass_spec_debug_signal.rindx = Secondpass_spec_debug_signal.rindx';
      Secondpass_spec_debug_signal.dindx = Secondpass_spec_debug_signal.dindx';
      Secondpass_spec_debug_signal.aindx = Secondpass_spec_debug_signal.aindx';
      Secondpass_spec_out.range = Secondpass_spec_out_temp.range';
      Secondpass_spec_out.range_rate = Secondpass_spec_out_temp.range_rate';
      Secondpass_spec_out.snr = Secondpass_spec_out_temp.snr';
      Secondpass_spec_out.sp_fail_flag = Secondpass_spec_out_temp.sp_fail_flag';
      Secondpass_spec_out.below_sp_thold = Secondpass_spec_out_temp.below_sp_thold';
   else
      Secondpass_spec_debug_signal.rindx = [];
      Secondpass_spec_debug_signal.dindx = [];
      Secondpass_spec_debug_signal.aindx = [];
      Secondpass_spec_out.range = []';
      Secondpass_spec_out.range_rate = [];
      Secondpass_spec_out.snr = [];
      Secondpass_spec_out.sp_fail_flag = [];
      Secondpass_spec_out.below_sp_thold = [];
   end
end
