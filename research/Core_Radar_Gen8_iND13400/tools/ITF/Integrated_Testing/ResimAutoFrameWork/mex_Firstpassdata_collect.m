% %%% API for collecting Firstpass Mex data from the Firstpass module %%
%  Name: mex_Firstpassdata_collect()
%   This function creates the stucture of Firstpass for Mex
%  Inputs:
%   look_string
%
%  Outputs:
%   Firstpass_mex_out, Firstpass_mex_debug_signal
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  [Firstpass_mex_out, Firstpass_mex_debug_signal] = mex_Firstpassdata_collect(look_string, download_data_set)

   Firstpass_mex_out = struct();
   Firstpass_mex_debug_signal = struct();

   if ~download_data_set
      % load intermediate outputs from mex
      load('Mex_Executable_Specs\Data\current_state_dfft.mat');
   else
      % load intermediate outputs from downloaded mex outputs
      load('mex_output\current_state_dfft.mat');
   end

   Firstpass_mex_out.numDetected = finalDetList.numDetected;

   if Firstpass_mex_out.numDetected > 0
      for i = 1:Firstpass_mex_out.numDetected
         Firstpass_mex_out.rindx(i) = finalDetList.rindx(i);
         Firstpass_mex_out.dindx(i) = finalDetList.dindx(i);
         Firstpass_mex_out.aindx(i) = finalDetList.aindx(i);
         Firstpass_mex_out.rdop_amp(i) = finalDetList.rdop_amp(i);
         Firstpass_mex_out.rbinest(i) = finalDetList.rbinest(i);
         Firstpass_mex_out.dbinest(i) = finalDetList.dbinest(i);
         Firstpass_mex_out.abinest(i) = finalDetList.abinest(i);

      end
      Firstpass_mex_out.rindx =  Firstpass_mex_out.rindx.';
      Firstpass_mex_out.dindx = Firstpass_mex_out.dindx.';
      Firstpass_mex_out.aindx = Firstpass_mex_out.aindx.';
      Firstpass_mex_out.rdop_amp = Firstpass_mex_out.rdop_amp.';

      Firstpass_mex_out.rbinest = Firstpass_mex_out.rbinest.';
      Firstpass_mex_out.dbinest = Firstpass_mex_out.dbinest.';
      Firstpass_mex_out.abinest = Firstpass_mex_out.abinest.';

   else
      Firstpass_mex_out.rindx = [];
      Firstpass_mex_out.dindx = [];
      Firstpass_mex_out.aindx = [];
      Firstpass_mex_out.rdop_amp = [];
      Firstpass_mex_out.rbinest = [];
      Firstpass_mex_out.dbinest = [];
      Firstpass_mex_out.abinest = [];
   end
   Firstpass_mex_out.max_per_range_bin = finalDetList.max_per_range_bin;
   Firstpass_mex_out.sig_thold_1st_pass = finalDetList.signal_threshold_first_pass;
   Firstpass_mex_out.first_pass_thold = finalDetList.firstpass_threshold;

   % Clip the leading and trailing range bins so the final outputs contain
   % processed range bins only - (Embedded doesn't process the leading and trailing range bins)
   Firstpass_mex_out.max_per_range_bin = Firstpass_mex_out.max_per_range_bin(2:end - 1, :);
   Firstpass_mex_out.sig_thold_1st_pass = Firstpass_mex_out.sig_thold_1st_pass(2:end - 1, :);
   Firstpass_mex_out.first_pass_thold = Firstpass_mex_out.first_pass_thold(2:end - 1, :);

   Firstpass_mex_debug_signal.nci_bexp = finalDetList.resultBexp;
   Firstpass_mex_debug_signal.bv = finalDetList.bvComp;
end
