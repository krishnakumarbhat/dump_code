%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This API basically does the comparison of look processing data between Spec, Mex and Embedded
% It uses error plot to display the result using relative or absolute error mechanism to compute the delta.
% Name: LookProcOutput_compare()
% inputs:
%  Lookproc_spec_out
%  Lookproc_mex_out
%  LookProc_embed_out
%  look_string
% outputs:
%  fail_count
%  pass_count

%%% TODO: Below comparison was dummy in this file, needs better formulaization and display the compare plots for LP module
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [fail_count, pass_count] = LookProcOutput_compare(Lookproc_spec_out, Lookproc_mex_out, LookProc_embed_out, look_string, smc_cal)

   csv_path = fullfile(fileparts(mfilename('fullpath')), '..', 'Trace32_Online_injection', 'Files', 'Variables_In_ITF_Reports', 'Look_Processing.csv');
   lookproc_tol_data = readcell(csv_path);

   pass_count = 0;
   total_count = 0;
   fail_count = 0;

   % When embedded output is absent (e.g. Spec vs Mex only mode), skip all
   % embedded comparisons/plots and only run the Spec vs Mex comparisons.
   has_spec = ~isempty(Lookproc_spec_out);
   has_mex = ~isempty(Lookproc_mex_out);
   has_embed = ~isempty(LookProc_embed_out);

   tol_rfft = lookproc_tol_data{strcmp(lookproc_tol_data(:, 1), 'range_fft'), 4};
   tol_dfft = lookproc_tol_data{strcmp(lookproc_tol_data(:, 1), 'range_doppler_array'), 4};
   tol_nci = lookproc_tol_data{strcmp(lookproc_tol_data(:, 1), 'rdop_avg'), 4};

   if has_spec && has_mex
      % RFFT_Spec_vs_Mex
      [rfft_decomp_error, rfft_decomp_error_log, max_spec_rfft, max_mex_rfft] = measure_error_calc(Lookproc_spec_out.range_fft, Lookproc_mex_out.range_fft_decomp, 1, 'range_fft_decomp');

      fig1 = figure();
      for ch = 1:smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE
         subplot(2, 2, ch);
         mesh(squeeze(rfft_decomp_error_log(:, ch, :)));
         hold on;
         [X, Y] = meshgrid(1:size(rfft_decomp_error_log, 3), 1:size(rfft_decomp_error_log, 1));
         tolerance_plane = tol_rfft * ones(size(X));
         tol_label = sprintf('%d dB', tol_rfft);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');
         hold off;
         title(sprintf('RFFT Spec vs. Mex - Channel %d', ch));
         xlabel('Chirp number');
         ylabel('Range index');
         zlabel('Error in dB');
      end
      sgtitle('RFFT Spec vs. Mex - All Channels');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Spec: %.3f', max_spec_rfft), sprintf('Max Mex: %.3f', max_mex_rfft)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowable error
      number_errors = sum(rfft_decomp_error_log > tol_rfft, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % RFFT_Spec_vs_Embed
   if has_spec && has_embed
      [rfft_decomp_error, rfft_decomp_error_log, max_spec_rfft, max_embed_rfft] = measure_error_calc(Lookproc_spec_out.range_fft, LookProc_embed_out.range_fft_decomp, 1, 'range_fft_decomp');

      fig2 = figure();
      for ch = 1:smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE
         subplot(2, 2, ch);
         mesh(squeeze(rfft_decomp_error_log(:, ch, :)));
         hold on;
         [X, Y] = meshgrid(1:size(rfft_decomp_error_log, 3), 1:size(rfft_decomp_error_log, 1));
         tolerance_plane = tol_rfft * ones(size(X));
         tol_label = sprintf('%d dB', tol_rfft);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('RFFT Spec vs. Embed - Channel %d', ch));
         xlabel('Chirp number');
         ylabel('Range index');
         zlabel('Error in dB');
      end
      sgtitle('RFFT Spec vs. Embed - All Channels');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Spec: %.3f', max_spec_rfft), sprintf('Max Embed: %.3f', max_embed_rfft)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowable error
      number_errors = sum(rfft_decomp_error_log > tol_rfft, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % RFFT_Mex_vs_Embed
   if has_mex && has_embed
      [rfft_decomp_error, rfft_decomp_error_log, max_mex_rfft, max_embed_rfft] = measure_error_calc(Lookproc_mex_out.range_fft_decomp, LookProc_embed_out.range_fft_decomp, 1, 'range_fft_decomp');

      fig3 = figure();
      for ch = 1:smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE
         subplot(2, 2, ch);
         mesh(squeeze(rfft_decomp_error_log(:, ch, :)));
         hold on;
         [X, Y] = meshgrid(1:size(rfft_decomp_error_log, 3), 1:size(rfft_decomp_error_log, 1));
         tolerance_plane = tol_rfft * ones(size(X));
         tol_label = sprintf('%d dB', tol_rfft);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');
         hold off;
         title(sprintf('RFFT Mex vs. Embed - Channel %d', ch));
         xlabel('Chirp number');
         ylabel('Range index');
         zlabel('Error in dB');
      end
      legend('show', 'Location', 'northeast');
      sgtitle('RFFT Mex vs. Embed - All Channels');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Mex: %.3f', max_mex_rfft), sprintf('Max Embed: %.3f', max_embed_rfft)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowable error
      number_errors = sum(rfft_decomp_error_log > ...
                          tol_rfft, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   if has_spec && has_mex

      % DFFT Spec vs Mex
      fig4 = figure();
      [dfft_decomp_error, dfft_decomp_error_log, max_spec_dfft, max_mex_dfft] = measure_error_calc(Lookproc_spec_out.dopp_fft, Lookproc_mex_out.dopp_fft_decomp, 1, 'dopp_fft_decomp');

      for ch = 1:smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE
         subplot(4, 2, ch);
         mesh(squeeze(dfft_decomp_error_log(:, ch, :)));
         hold on;
         [X, Y] = meshgrid(1:size(dfft_decomp_error_log, 3), 1:size(dfft_decomp_error_log, 1));
         tolerance_plane = tol_dfft * ones(size(X));
         tol_label = sprintf('%d dB', tol_dfft);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('DFFT Spec vs. Mex - Channel %d', ch));
         xlabel('Chirp Number');
         ylabel('range index');
         zlabel('Error in dB');
      end
      sgtitle('DFFT Spec vs. Mex - All Channels');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Spec: %.3f', max_spec_dfft), sprintf('Max Mex: %.3f', max_mex_dfft)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowed error
      number_errors = sum(dfft_decomp_error_log > tol_dfft, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % DFFT_Spec_vs_Embed
   if has_spec && has_embed
      fig5 = figure();
      [dfft_decomp_error, dfft_decomp_error_log, max_spec_dfft, max_embed_dfft] = measure_error_calc(Lookproc_spec_out.dopp_fft, LookProc_embed_out.dopp_fft_decomp, 1, 'dopp_fft_decomp');

      for ch = 1:smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE
         subplot(4, 2, ch);
         mesh(squeeze(dfft_decomp_error_log(:, ch, :)));
         hold on;
         [X, Y] = meshgrid(1:size(dfft_decomp_error_log, 3), 1:size(dfft_decomp_error_log, 1));
         tolerance_plane = tol_dfft * ones(size(X));
         tol_label = sprintf('%d dB', tol_dfft);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('DFFT Spec vs. Embed - Channel %d', ch));
         xlabel('Chirp Number');
         ylabel('range index');
         zlabel('Error in dB');
      end
      sgtitle('DFFT Spec vs. Embed - All Channels');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Spec: %.3f', max_spec_dfft), sprintf('Max Embed: %.3f', max_embed_dfft)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowed error
      number_errors = sum(dfft_decomp_error_log > tol_dfft, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % DFFT Mex vs Embed
   if has_mex && has_embed
      fig6 = figure();
      [dfft_decomp_error, dfft_decomp_error_log, max_mex_dfft, max_embed_dfft] = measure_error_calc(Lookproc_mex_out.dopp_fft_decomp, LookProc_embed_out.dopp_fft_decomp, 1, 'dopp_fft_decomp');

      for ch = 1:smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE
         subplot(4, 2, ch);
         mesh(squeeze(dfft_decomp_error_log(:, ch, :)));
         hold on;
         [X, Y] = meshgrid(1:size(dfft_decomp_error_log, 3), 1:size(dfft_decomp_error_log, 1));
         tolerance_plane = tol_dfft * ones(size(X));
         tol_label = sprintf('%d dB', tol_dfft);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('DFFT Mex vs. Embed - Channel %d', ch));
         xlabel('Chirp Number');
         ylabel('range index');
         zlabel('Error in dB');
      end
      sgtitle('DFFT Mex vs. Embed - All Channels');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Mex: %.3f', max_mex_dfft), sprintf('Max Embed: %.3f', max_embed_dfft)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowed error
      number_errors = sum(dfft_decomp_error_log > tol_dfft, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % Spec-based comparisons: only if Spec outputs are available
   if has_spec && has_mex

      % NCI Spec vs Mex
      [delta_mex_embed, delta_mex_embed_log, max_spec_nci, max_mex_nci] = measure_error_calc(Lookproc_spec_out.rdop_avg_NCI, Lookproc_mex_out.rdop_avg_NCI, 1, 'rdop_avg_NCI');

      fig7 = figure();
      for angle = 1:smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE
         subplot(4, 2, angle);
         mesh(squeeze(delta_mex_embed_log(:, angle, :)));
         hold on;
         [X, Y] = meshgrid(1:size(delta_mex_embed_log, 3), 1:size(delta_mex_embed_log, 1));
         tolerance_plane = tol_nci * ones(size(X));
         tol_label = sprintf('%d dB', tol_nci);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('Rdop Avg Spec vs. Mex - Angle %d', angle));
         xlabel('doppler index');
         ylabel('range index');
         zlabel('Error in dB');
      end
      sgtitle('NCI Spec vs. Mex - All Angles');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Spec: %.3f', max_spec_nci), sprintf('Max Mex: %.3f', max_mex_nci)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowed error
      number_errors = sum(delta_mex_embed_log > tol_nci, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % NCI Spec vs Embed
   if has_spec && has_embed
      [delta_mex_embed, delta_mex_embed_log, max_spec_nci, max_embed_nci] = measure_error_calc(Lookproc_spec_out.rdop_avg_NCI, LookProc_embed_out.rdop_avg_NCI, 1, 'rdop_avg_NCI');

      fig8 = figure();
      for angle = 1:smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE
         subplot(4, 2, angle);
         mesh(squeeze(delta_mex_embed_log(:, angle, :)));
         hold on;
         [X, Y] = meshgrid(1:size(delta_mex_embed_log, 3), 1:size(delta_mex_embed_log, 1));
         tolerance_plane = tol_nci * ones(size(X));
         tol_label = sprintf('%d dB', tol_nci);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('Rdop Avg Spec vs. Embed - Angle %d', angle));
         xlabel('doppler index');
         ylabel('range index');
         zlabel('Error in dB');
      end
      sgtitle('NCI Spec vs. Embed - All Angles');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Spec: %.3f', max_spec_nci), sprintf('Max Embed: %.3f', max_embed_nci)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowed error
      number_errors = sum(delta_mex_embed_log > tol_nci, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end

   % NCI Mex vs Embed
   if has_mex && has_embed
      [delta_mex_embed, delta_mex_embed_log, max_mex_nci, max_embed_nci] = measure_error_calc(Lookproc_mex_out.rdop_avg_NCI, LookProc_embed_out.rdop_avg_NCI, 1, 'rdop_avg_NCI');

      fig9 = figure();
      for angle = 1:smc_cal.Configuration.BB_Configuration.ANGLE_BINS_USED.VALUE
         subplot(4, 2, angle);
         mesh(squeeze(delta_mex_embed_log(:, angle, :)));
         hold on;
         [X, Y] = meshgrid(1:size(delta_mex_embed_log, 3), 1:size(delta_mex_embed_log, 1));
         tolerance_plane = tol_nci * ones(size(X));
         tol_label = sprintf('%d dB', tol_nci);
         surf(X, Y, tolerance_plane, 'FaceAlpha', 0.3, 'FaceColor', 'r', 'EdgeColor', 'none');

         hold off;
         title(sprintf('Rdop Avg Mex vs. Embed - Angle %d', angle));
         xlabel('doppler index');
         ylabel('range index');
         zlabel('Error in dB');
      end
      sgtitle('NCI Mex vs. Embed - All Angles');
      dim = [0 0.8 0.1 0.2];
      str_rfft = {sprintf('Max Mex: %.3f', max_mex_nci), sprintf('Max Embed: %.3f', max_embed_nci)};
      annotation('textbox', dim, 'String', str_rfft, 'FitBoxToText', 'on', 'FontSize', 9, 'BackgroundColor', [0.85 1 0.85], 'EdgeColor', 'black');
      dim = [0.99 0.98 0.001 0.001];
      str_tol = ['Tolerance: ' tol_label];
      annotation('textbox', dim, 'String', str_tol, 'FitBoxToText', 'on', 'FontSize', 9, 'HorizontalAlignment', 'right', 'BackgroundColor', [1 0.85 0.85], 'EdgeColor', 'black');

      % Compare against allowed error
      number_errors = sum(delta_mex_embed_log > tol_nci, "all");

      if number_errors <= 0
         pass_count = pass_count + 1;
         total_count = total_count + 1;
      else
         fail_count = fail_count + 1;
         total_count = total_count + 1;
      end
   end
   out_dir = ['Look_Proc_Output_' look_string];
   % Remove any stale directory from a previous run so old reports never linger
   if exist(out_dir, 'dir')
      rmdir(out_dir, 's');
   end
   mkdir(out_dir);

   % Spec vs Mex figures (available whenever Spec outputs were provided)
   if has_spec && has_mex
      save_lookproc_figure(fig1, out_dir, 'RFFT_Spec_vs_Mex');
      save_lookproc_figure(fig4, out_dir, 'DFFT_Spec_vs_Mex');
      save_lookproc_figure(fig7, out_dir, 'NCI_Spec_vs_Mex');
   end
   if has_spec && has_embed
      save_lookproc_figure(fig2, out_dir, 'RFFT_Spec_vs_Embed');
      save_lookproc_figure(fig5, out_dir, 'DFFT_Spec_vs_Embed');
      save_lookproc_figure(fig8, out_dir, 'NCI_Spec_vs_Embed');
   end
   if has_mex && has_embed
      save_lookproc_figure(fig3, out_dir, 'RFFT_Mex_vs_Embed');
      save_lookproc_figure(fig6, out_dir, 'DFFT_Mex_vs_Embed');
      save_lookproc_figure(fig9, out_dir, 'NCI_Mex_vs_Embed');
   end
end

function save_lookproc_figure(fig_handle, out_dir, name)
   % Save a figure as both .fig and .jpg when the handle is valid.
   if isempty(fig_handle) || ~isvalid(fig_handle)
      return
   end
   saveas(fig_handle, fullfile(out_dir, name), 'fig');
   saveas(fig_handle, fullfile(out_dir, name), 'jpg');
end
