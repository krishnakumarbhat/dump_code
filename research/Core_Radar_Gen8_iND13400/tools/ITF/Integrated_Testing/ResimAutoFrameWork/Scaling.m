% %%% API for scaling the mex output %%
%  Name: Scaling()
%  This function provides the scaled output for mex Sweep BW Module
%
%  Inputs:
%  BW_mex_out, smc_cal, look_string,
%
%  Outputs:
%  BW_mex_out
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [BW_mex_out, CFAR_mex_out, FP_mex_out, SP_mex_out, LookProc_mex_out, ...
    LookProc_embed_out, CFAR_embed_out, BW_embed_out, FP_embed_out, SP_embed_out] = Scaling( ...
                                                                                            BW_mex_out, CFAR_mex_out, FP_mex_out, SP_mex_out, LookProc_mex_out, ...
                                                                                            LookProc_embed_out, CFAR_embed_out, BW_embed_out, FP_embed_out, SP_embed_out, ...
                                                                                            Firstpass_mex_debug_signal, spec_mex_only)

   if nargin < 12 || isempty(spec_mex_only)
      spec_mex_only = false;
   end

   Scaling_Compensation_Mex = (48 - Firstpass_mex_debug_signal.nci_bexp + 1);
   Scaling_Compensation_MCS_Mex = LookProc_mex_out.min_chirp_scaling;
   scalePow2_Mex = 2.^double(Scaling_Compensation_Mex);
   scalePow2_MCS_Mex = 2.^double(Scaling_Compensation_MCS_Mex);
   scalePow2_MCS_bexp_Mex = 2.^double(Scaling_Compensation_Mex - Scaling_Compensation_MCS_Mex);

   if ~spec_mex_only
      Scaling_Compensation_Embed = (48 - LookProc_embed_out.nci_bexp + 1);
      Scaling_Compensation_MCS_Embed = double(LookProc_embed_out.min_chirp_scale);
      scalePow2_Embed = 2.^double(Scaling_Compensation_Embed);
      scalePow2_MCS_Embed = 2.^double(Scaling_Compensation_MCS_Embed);
      scalePow2_MCS_bexp_Embed = 2.^double(Scaling_Compensation_Embed - Scaling_Compensation_MCS_Embed);
   end

   for i = 1:FP_mex_out.numDetected
      block_multiplier_mex(i) = scalePow2_MCS_bexp_Mex(FP_mex_out.rindx(i) + 1, FP_mex_out.aindx(i) + 1);
   end
   block_multiplier_mex = block_multiplier_mex.';

   if ~spec_mex_only
      for i = 1:FP_embed_out.numDetected
         block_multiplier_embed(i) = scalePow2_MCS_bexp_Mex(FP_embed_out.rindx(i) + 1, FP_embed_out.aindx(i) + 1);
      end
      block_multiplier_embed = block_multiplier_embed.';
   end

   %% Embed Look Proc Scaling
   if ~spec_mex_only
      LookProc_embed_out.range_fft_decomp = LookProc_embed_out.range_fft_decomp ./ scalePow2_MCS_Embed;
      LookProc_embed_out.dopp_fft_decomp = (LookProc_embed_out.dopp_fft_decomp ./ scalePow2_MCS_Embed) / 2^8;
      LookProc_embed_out.rdop_avg_NCI = (LookProc_embed_out.rdop_avg_NCI .* scalePow2_MCS_bexp_Embed) / 2^8;
   end

   %% Mex Look Proc Scaling
   LookProc_mex_out.range_fft_decomp = LookProc_mex_out.range_fft_decomp ./ scalePow2_MCS_Mex;
   LookProc_mex_out.dopp_fft_decomp = (LookProc_mex_out.dopp_fft_decomp ./ scalePow2_MCS_Mex) / 2^8;
   LookProc_mex_out.rdop_avg_NCI = (LookProc_mex_out.rdop_avg_NCI .* scalePow2_MCS_bexp_Mex) / 2^8;

   %% Mex SweepBw Scaling
   BW_mex_out.CR_Response =  BW_mex_out.CR_Response * 2^23 ./ scalePow2_MCS_Mex;
   BW_mex_out.Sensitivity_Threshold = BW_mex_out.Sensitivity_Threshold * 2^23 ./ scalePow2_MCS_Mex;
   BW_mex_out.HVC_Threshold = BW_mex_out.HVC_Threshold * 2^23 ./ scalePow2_MCS_Mex;
   BW_mex_out.MB_Threshold = BW_mex_out.MB_Threshold * 2^23 ./ scalePow2_MCS_Mex;

   %% Embed SweepBw Scaling
   if ~spec_mex_only
      BW_embed_out.CR_Response =  BW_embed_out.CR_Response ./ scalePow2_MCS_Embed;
      BW_embed_out.Sensitivity_Threshold = BW_embed_out.Sensitivity_Threshold ./ scalePow2_MCS_Embed;
      BW_embed_out.HVC_Threshold = BW_embed_out.HVC_Threshold ./ scalePow2_MCS_Embed;
      BW_embed_out.MB_Threshold = BW_embed_out.MB_Threshold ./ scalePow2_MCS_Embed;
   end

   %% Embed CFAR Scaling
   if ~spec_mex_only
      CFAR_embed_out.CFAR_NF_est =  CFAR_embed_out.CFAR_NF_est .* scalePow2_MCS_bexp_Embed / 2^8;
      CFAR_embed_out.CFAR_thold =  double(CFAR_embed_out.CFAR_thold) .* scalePow2_MCS_bexp_Embed / 2^8;
   end

   %% Mex CFAR Scaling
   CFAR_mex_out.CFAR_NF_est =  CFAR_mex_out.CFAR_NF_est .* scalePow2_MCS_bexp_Mex / 2^8;
   CFAR_mex_out.CFAR_thold =  CFAR_mex_out.CFAR_thold .* scalePow2_MCS_bexp_Mex / 2^8;

   %%% Embed First Pass Scaling
   if ~spec_mex_only
      FP_embed_out.rbinest = double(FP_embed_out.rbinest) / 2^21;
      FP_embed_out.dbinest = double(FP_embed_out.dbinest) / 2^21;
      FP_embed_out.abinest = double(FP_embed_out.abinest) / 2^21;
      FP_embed_out.rdop_amp = double(FP_embed_out.rdop_amp) .* block_multiplier_embed / 2^8;
      FP_embed_out.max_per_range_bin = double(FP_embed_out.max_per_range_bin) .* scalePow2_MCS_bexp_Embed(2:end - 1, :) / 2^8;
      FP_embed_out.sig_thold_1st_pass = double(FP_embed_out.sig_thold_1st_pass) .* scalePow2_MCS_bexp_Embed(2:end - 1, :) / 2^8;
      FP_embed_out.first_pass_thold = double(FP_embed_out.first_pass_thold) .* scalePow2_MCS_bexp_Embed(2:end - 1, :) / 2^8;
   end

   %%% Mex First Pass Scaling
   FP_mex_out.rdop_amp = double(FP_mex_out.rdop_amp) .* block_multiplier_mex  / 2^8;
   FP_mex_out.max_per_range_bin = FP_mex_out.max_per_range_bin .* scalePow2_MCS_bexp_Mex(2:end - 1, :) / 2^8;
   FP_mex_out.sig_thold_1st_pass = FP_mex_out.sig_thold_1st_pass .* scalePow2_MCS_bexp_Mex(2:end - 1, :) * 2^(16 - 8);
   FP_mex_out.first_pass_thold = FP_mex_out.first_pass_thold .* scalePow2_MCS_bexp_Mex(2:end - 1, :)  / 2^8;

   %%% Mex Second Pass Scaling
   SP_mex_out.thold_2nd_pass = SP_mex_out.thold_2nd_pass * 2^23 * 2 ./ scalePow2_MCS_Mex  / 2^8;

   %%% Embed Second Pass Scaling
   if ~spec_mex_only
      SP_embed_out.range = double(SP_embed_out.range) / 2^21;
      SP_embed_out.range_rate = double(SP_embed_out.range_rate) / 2^21;
      SP_embed_out.snr = double(SP_embed_out.snr) / 2^23;
      SP_embed_out.thold_2nd_pass = double(SP_embed_out.thold_2nd_pass) * 2 ./ scalePow2_MCS_Embed  / 2^8;
   end

end
