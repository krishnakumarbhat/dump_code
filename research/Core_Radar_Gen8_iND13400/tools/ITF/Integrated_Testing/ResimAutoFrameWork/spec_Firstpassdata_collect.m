% %%% API for collecting Firstpass Spec data from the Firstpass module %%
%  Name: specmex_Firstpassdata_collect()
%   This function creates the stucture of Firstpass for Spec
%  Inputs:
%   look_string
%
%  Outputs:
%   Firstpass_spec_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [Firstpass_spec_out] = spec_Firstpassdata_collect(look_string)

   Firstpass_spec_out = struct();

   % load intermediate outputs from Spec
   load(['.\Executable_Specs\Data\IQ_data_' look_string, '_' look_string, '_FirstPass.mat']);

   Firstpass_spec_out.numDetected = rdd_output.numDetected;
   Firstpass_spec_out.rindx = rdd_output.rindx';
   Firstpass_spec_out.dindx = rdd_output.dindx';
   Firstpass_spec_out.aindx = rdd_output.aindx';
   Firstpass_spec_out.rdop_amp = rdd_output.rdop_amp';
   Firstpass_spec_out.rbinest  = rdd_output.rbinest';
   Firstpass_spec_out.dbinest = rdd_output.dbinest';
   Firstpass_spec_out.abinest = rdd_output.abinest';
   Firstpass_spec_out.max_per_range_bin = rdd_output.max_per_range_bin;
   Firstpass_spec_out.sig_thold_1st_pass = rdd_output.signal_threshold_first_pass;
   Firstpass_spec_out.first_pass_thold = rdd_output.firstpass_threshold;

   % Clip the leading and trailing range bins so the final outputs contain
   % processed range bins only - (Embedded doesn't process the leading and trailing range bins)
   Firstpass_spec_out.max_per_range_bin = Firstpass_spec_out.max_per_range_bin(2:end - 1, :);
   Firstpass_spec_out.sig_thold_1st_pass = Firstpass_spec_out.sig_thold_1st_pass(2:end - 1, :);
   Firstpass_spec_out.first_pass_thold = Firstpass_spec_out.first_pass_thold(2:end - 1, :);

   % % To be enabled further.
   %    load(['.\Executable_Specs\Data\IQ_data_' look_string, '_' look_string, '_LookProcessing.mat']);
   %    bins_undergone_REST = nonzeros(find(outputRestBinFlag));
   %    Firstpass_spec_out.bins_undergone_REST = bins_undergone_REST - 1;
   %    Firstpass_spec_out.bv = rdd_output.finalDetList.bv;

   % Removing trailing zeros in structures
   Firstpass_spec_out.rindx = Firstpass_spec_out.rindx(1:Firstpass_spec_out.numDetected);
   Firstpass_spec_out.dindx = Firstpass_spec_out.dindx(1:Firstpass_spec_out.numDetected);
   Firstpass_spec_out.aindx = Firstpass_spec_out.aindx(1:Firstpass_spec_out.numDetected);
   Firstpass_spec_out.rdop_amp = Firstpass_spec_out.rdop_amp(1:Firstpass_spec_out.numDetected);
   Firstpass_spec_out.rbinest = Firstpass_spec_out.rbinest(1:Firstpass_spec_out.numDetected);
   Firstpass_spec_out.dbinest = Firstpass_spec_out.dbinest(1:Firstpass_spec_out.numDetected);
   Firstpass_spec_out.abinest = Firstpass_spec_out.abinest(1:Firstpass_spec_out.numDetected);

end
