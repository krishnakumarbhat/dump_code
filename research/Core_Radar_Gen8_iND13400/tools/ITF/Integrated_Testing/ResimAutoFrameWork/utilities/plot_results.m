%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: plot_results()
%   Plot the collected ITF results.
%
%  Inputs:
%   look_string - If not provided, the workspace is cleared and results
%                 for Look_A are plotted. Otherwise, the results for
%                 the selected look_string are shown.
%  Outputs:
%   None
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function plot_results(look_string, sensor_type, testcase_dir_name)

   if ~exist('look_string', 'var')
      clear_all = 1;
   else
      clear_all = 0;
   end

   if clear_all ~= 0
      clc;
      clear all;
      close all;
      look_string = 'Look_A';
      sensor_type = 'FLR8';
   end

   load(['Reports\' testcase_dir_name '\Final_Outputs\Final_Outputs_' look_string '\bwthold_outputs.mat']);
   load(['Reports\' testcase_dir_name '\Final_Outputs\Final_Outputs_' look_string '\cfar_outputs.mat']);
   load(['Reports\' testcase_dir_name '\Final_Outputs\Final_Outputs_' look_string '\cfar_outputs_debug_signal.mat']);
   load(['Reports\' testcase_dir_name '\Final_Outputs\Final_Outputs_' look_string '\firstpass_outputs.mat']);
   load(['Reports\' testcase_dir_name '\Final_Outputs\Final_Outputs_' look_string '\lookproc_outputs.mat']);
   load(['Reports\' testcase_dir_name '\Final_Outputs\Final_Outputs_' look_string '\secondpass_outputs.mat']);

   WorkbookPath = ['./workbook/' sensor_type];
   addpath(WorkbookPath);
   smc_info = dir(fullfile([WorkbookPath, '\smc_cal*.mat']));
   load(smc_info.name);
   usc_info = dir(fullfile([WorkbookPath, '\usc_cal*.mat']));
   load(usc_info.name);

   mprb = double(FP_embed_out.max_per_range_bin) .* (2.^(48 - double(FP_embed_out.nci_bexp)));

   rwin_embedded = round(smc_cal.SMC.Secondpass_Threshold.k_rwin_sll.VALUE * 2^16) / 2^16; % round to fixed point, then back to floating point.
   max_mprb = max(mprb);
   rwin_thold = floor(rwin_embedded * max_mprb);

   second_pass_thold = max(double(BW_embed_out.Sensitivity_Threshold), first_pass_thold + rwin_thold);

   figure('Name', 'NCI Outputs', 'NumberTitle', 'off');
   hold on;
   plot(db(double(CFAR_embed_out.CFAR_NF_est) .* (2.^(48 - double(FP_embed_out.nci_bexp)))));
   plot(db(mprb));
   plot(db(first_pass_thold));
   plot(db(double(BW_embed_out.CR_Response)));
   plot(db(double(second_pass_thold)));

   legend('CFAR Thold', 'CFAR\_NF\_est', 'MPRB', 'First Pass Threshold', 'CR Response', 'Second Pass Threshold');
   title("NCI based CFAR/FP outputs");

   for i = 1:size(LookProc_embed_out.dfft_decomp_data, 3)
      title_str = sprintf("Doppler BV Magnitude - %d", i);
      figure('Name', title_str, 'NumberTitle', 'off');
      mesh(db(LookProc_embed_out.dfft_decomp_data(:, :, i)));
      title(title_str);
   end

   % Plot the NCI spectrum with the detections marked
   figure;
   nciBexp     =   double(FP_embed_out.nci_bexp);
   rindx   =   double(FP_embed_out.rindx);
   dindx   =   double(FP_embed_out.dindx);
   nciDescale  =   LookProc_embed_out.rdop_avg_NCI .* 2.^(48 - nciBexp(:));
   % mesh(db(fullNci))
   imagesc(db(nciDescale));
   hold on;
   scatter(dindx + 1, rindx + 1, 'r');
   hold off;
   xlabel('Doppler bin');
   ylabel('range bin');
   grid on;
   grid minor;
   title('full nci');

end
