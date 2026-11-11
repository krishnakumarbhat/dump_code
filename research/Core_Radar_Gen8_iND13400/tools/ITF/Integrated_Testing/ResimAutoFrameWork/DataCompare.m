%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: DataCompare
%   Unified comparison function for ITF report generation.
%   Handles three modes:
%     1. Three-way (Spec vs Mex vs Embed) when all three outputs are provided
%     2. Two-way Mex-vs-Embed when Spec_out is empty and comparison_type_flag == 1
%     3. Two-way legacy (Embed vs Spec) when comparison_type_flag ~= 1
%
% Inputs:
%   EMBED_out              - Embedded output structure
%   Mex_out                - MEX output structure
%   Spec_out               - Exec Spec output structure (empty => Mex-vs-Embed mode)
%   path_to_report_directory - Path where HTML reports are written
%   path_to_USC_data       - USC data path (used to extract radar name)
%   test_case_cnt          - Number of test cases
%   var_data               - Measurement variable definitions (name, range, etc.)
%   testcase_runtime       - Runtime per test case
%   path_to_TV_data        - Test vector data path (used to extract test name)
%   testcase               - Testcase struct (may contain .Filename)
%   CFAR_flag              - Flag for CFAR-specific naming
%   embed_runtime          - Embedded execution time per test case
%   comparison_type_flag   - 1 = three-way or mex-embed, else = two-way legacy
%   workbook               - Workbook version
%   USC_version            - USC calibration version string
%   BB_version             - Building block version string
%
% Return Variables:
%   tc_fail_cnt  - Number of test cases that failed
%   tot_pass_cnt - Total individual pass count
%   tot_fail_cnt - Total individual fail count
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = DataCompare(EMBED_out, Mex_out, Spec_out, path_to_report_directory, path_to_USC_data, test_case_cnt, ...
                                                                 var_data, testcase_runtime, path_to_TV_data, testcase, CFAR_flag, embed_runtime, comparison_type_flag, workbook, USC_version, BB_version)
   global itr

   % Extract display names from paths
   unit = strsplit(path_to_USC_data, '\');
   radar_name = unit{numel(unit)};
   test_name_parts = strsplit(path_to_TV_data, '\');
   test_name = test_name_parts{numel(test_name_parts)};
   test_name_overall = test_name;

   % Determine mode
   mex_embed_mode = isempty(Spec_out);
   % Spec vs Mex only mode: embedded output omitted, compare Spec against Mex.
   spec_mex_mode = isempty(EMBED_out) && ~isempty(Spec_out);

   if comparison_type_flag == 1
      if spec_mex_mode
         % Two-way: Spec vs Mex (embedded skipped). Reuse the 2-way engine
         % with the Spec output supplied in place of the embedded output.
         [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_mex_embed( ...
                                                                       Mex_out, Spec_out, path_to_report_directory, radar_name, ...
                                                                       test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                       testcase, CFAR_flag, testcase_runtime, comparison_type_flag, workbook, ...
                                                                       USC_version, BB_version, itr, true);
      elseif mex_embed_mode
         % Two-way: Mex vs Embed (CreateSubReport with mex_embed_mode=true)
         [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_mex_embed( ...
                                                                       EMBED_out, Mex_out, path_to_report_directory, radar_name, ...
                                                                       test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                       testcase, CFAR_flag, testcase_runtime, comparison_type_flag, workbook, ...
                                                                       USC_version, BB_version, itr, false);
      else
         % Three-way: Spec vs Mex vs Embed (uses CreateSubReport)
         [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_three_way( ...
                                                                       EMBED_out, Mex_out, Spec_out, path_to_report_directory, radar_name, ...
                                                                       test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                       testcase, CFAR_flag, embed_runtime, comparison_type_flag, workbook, ...
                                                                       USC_version, BB_version, itr);
      end
   else
      % Two-way legacy: Embed vs Spec/TV data
      if mex_embed_mode
         % When Spec_out is empty in else-branch, compare EMBED vs Mex directly
         report_fn = @(a, b, c, d, e, f, g, h, i, j) CreateSubReport(a, b, c, d, e, f, g, h, i, j, true);
      else
         report_fn = @CreateSubReport;
      end
      data_source = conditional_pick(mex_embed_mode, Mex_out, Spec_out);
      [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_two_way( ...
                                                                  EMBED_out, data_source, path_to_report_directory, radar_name, ...
                                                                  test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                  testcase, CFAR_flag, embed_runtime, comparison_type_flag, workbook, ...
                                                                  USC_version, BB_version, itr, report_fn);
   end
end

%% ========================================================================
%  THREE-WAY COMPARISON: Spec vs Mex vs Embed
%  ========================================================================
function [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_three_way( ...
                                                                       EMBED_out, Mex_out, Spec_out, path_to_report_directory, radar_name, ...
                                                                       test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                       testcase, CFAR_flag, embed_runtime, comparison_type_flag, workbook, ...
                                                                       USC_version, BB_version, itr)

   [tot_pass_cnt, tot_fail_cnt, tc_pass_cnt, tc_fail_cnt, ~, ~, ...
    HTML_sum_1, incr, test_case_num, namesize, name_incr, ExecTime] = init_counters();
   Pass_cnt = 0;
   Fail_cnt = 0;

   setup_report_directory(path_to_report_directory);

   EMBED_out_c = struct2cell(EMBED_out);
   Mex_data_out_c = struct2cell(Mex_out);
   Spec_data_out_c = struct2cell(Spec_out);
   [EMBED_out_c, Mex_data_out_c, Spec_data_out_c, m, n] = pad_cells_3way(EMBED_out_c, Mex_data_out_c, Spec_data_out_c);

   [total_num, ~] = size(var_data);
   name_size = 1;

   if isfield(testcase, 'Filename')
      test_name = testcase.Filename{name_size};
      name_size = name_size + 1;
   end

   [HTML_string, filename] = CreateSubReport(radar_name, test_case_num, test_case_cnt, test_name, path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, BB_version);
   fid = fopen(filename, 'w+');
   fprintf(fid, HTML_string);
   fclose(fid);
   fprintf('Created Test Case Report #%d.\n', itr);
   HTML_Insert(filename, Pass_cnt, Fail_cnt, testcase_runtime(test_case_num), 0, 'Execution_Time');
   HTML_Insert(filename, Pass_cnt, Fail_cnt, 0, embed_runtime(test_case_num), 'Embed_Time');
   HTML_sum = CreateTestCase(radar_name, test_case_cnt, testcase_runtime(min(test_case_cnt + 1, numel(testcase_runtime))), test_name_overall);

   fields_mex = fieldnames(Mex_out);
   fields_embed = fieldnames(EMBED_out);
   fields_spec = fieldnames(Spec_out);

   tic;
   for j = 1:m
      for i = 1:n
         loc_mex = find_field_index(fields_mex, fields_embed{j});
         loc_spec = find_field_index(fields_spec, fields_embed{j});
         if loc_mex ~= loc_spec
            error('Outputs of mex structure and spec structure are not identical');
         end

         embed_data = EMBED_out_c{j, i};
         mex_data = Mex_data_out_c{loc_mex, i};
         spec_data = Spec_data_out_c{loc_spec, i};

         if isreal(mex_data) && isreal(spec_data)
            [data_rows, data_cols] = get_common_size(embed_data, mex_data, spec_data);
            for row = 1:data_rows
               for col = 1:data_cols
                  if incr > total_num
                     [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                      HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                                       filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                                       HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                                       path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                                       BB_version, testcase_runtime, embed_runtime, itr, @CreateSubReport);
                  end

                  [name, incr, name_incr, namesize] = get_and_advance_var( ...
                                                                          var_data, incr, CFAR_flag, name_incr, namesize, test_case_cnt);

                  em_raw    = embed_data(row, col);
                  s         = double(spec_data(row, col));
                  mx        = double(mex_data(row, col));
                  range_lin = var_data{incr - 1, 5};
                  range_dB  = var_data{incr - 1, 6};

                  [delta_sm, dB_spec_mex]   = measure_error_calc(s,  mx,     1, name);
                  [delta_se, dB_spec_embed] = measure_error_calc(s,  em_raw, 1, name);
                  [delta_me, dB_mex_embed]  = measure_error_calc(mx, em_raw, 1, name);

                  % SPEC vs. MEX (row opener)
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_comparison_row( ...
                                                                                          filename, name, {s, mx, double(em_raw)}, delta_sm, dB_spec_mex, ...
                                                                                          range_lin, range_dB, '<tr bgcolor="#EEEEEE">\n', '', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  % SPEC vs. EMBED (continuation)
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                          filename, delta_se, dB_spec_embed, range_lin, range_dB, '', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  % MEX vs. EMBED (closes row)
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                          filename, delta_me, dB_mex_embed, range_lin, range_dB, '</tr>\n', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
               end
            end
         else
            [data_rows, data_cols] = get_common_size(embed_data, mex_data, spec_data);
            for row = 1:data_rows
               for col = 1:data_cols
                  if incr > total_num
                     [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                      HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                                       filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                                       HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                                       path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                                       BB_version, testcase_runtime, embed_runtime, itr, @CreateSubReport);
                  end

                  name_im = var_data{incr, 1};
                  name_re = var_data{incr + 1, 1};
                  range_im_lin = var_data{incr, 5};
                  range_re_lin = var_data{incr + 1, 5};
                  range_im_dB = var_data{incr, 6};
                  range_re_dB = var_data{incr + 1, 6};

                  em_raw = embed_data(row, col);
                  ei_raw = imag(em_raw);
                  er_raw = real(em_raw);
                  si = imag(spec_data(row, col));
                  mi = imag(mex_data(row, col));
                  sr = real(spec_data(row, col));
                  mr = real(mex_data(row, col));

                  [delta_si_mi, dB_si_mi] = measure_error_calc(si, mi,     1, name_im);
                  [delta_si_ei, dB_si_ei] = measure_error_calc(si, ei_raw, 1, name_im);
                  [delta_mi_ei, dB_mi_ei] = measure_error_calc(mi, ei_raw, 1, name_im);
                  [delta_sr_mr, dB_sr_mr] = measure_error_calc(sr, mr,     1, name_re);
                  [delta_sr_er, dB_sr_er] = measure_error_calc(sr, er_raw, 1, name_re);
                  [delta_mr_er, dB_mr_er] = measure_error_calc(mr, er_raw, 1, name_re);

                  % Imaginary: SPEC vs MEX / SPEC vs EMBED / MEX vs EMBED
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_comparison_row( ...
                                                                                          filename, name_im, {si, mi, double(ei_raw)}, delta_si_mi, dB_si_mi, ...
                                                                                          range_im_lin, range_im_dB, '<tr bgcolor="#EEEEEE">\n', '', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                          filename, delta_si_ei, dB_si_ei, range_im_lin, range_im_dB, '', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                          filename, delta_mi_ei, dB_mi_ei, range_im_lin, range_im_dB, '</tr>\n', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);

                  % Real: SPEC vs MEX / SPEC vs EMBED / MEX vs EMBED
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_comparison_row( ...
                                                                                          filename, name_re, {sr, mr, double(er_raw)}, delta_sr_mr, dB_sr_mr, ...
                                                                                          range_re_lin, range_re_dB, '<tr bgcolor="#EEEEEE">\n', '', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                          filename, delta_sr_er, dB_sr_er, range_re_lin, range_re_dB, '', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                          filename, delta_mr_er, dB_mr_er, range_re_lin, range_re_dB, '</tr>\n', ...
                                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);

                  incr = incr + 2;
               end
            end
         end
      end
   end

   [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = finalize_summary( ...
                                                                filename, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, tot_pass_cnt, tot_fail_cnt, ...
                                                                HTML_sum_1, HTML_sum, test_case_num, ExecTime, path_to_report_directory);
end

%% ========================================================================
%  TWO-WAY: Mex vs Embed (comparison_type_flag == 1, Spec_out empty)
%  ========================================================================
function [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_mex_embed( ...
                                                                       EMBED_out, Mex_out, path_to_report_directory, radar_name, ...
                                                                       test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                       testcase, CFAR_flag, embed_runtime, comparison_type_flag, workbook, ...
                                                                       USC_version, BB_version, itr, spec_mex_mode)

   if nargin < 18
      spec_mex_mode = false;  % Default: generic Mex vs Embed mode
   end

   [tot_pass_cnt, tot_fail_cnt, tc_pass_cnt, tc_fail_cnt, ~, ~, ...
    HTML_sum_1, incr, test_case_num, namesize, name_incr, ExecTime] = init_counters();
   Pass_cnt = 0;
   Fail_cnt = 0;

   setup_report_directory(path_to_report_directory);

   Mex_data_out_c = struct2cell(Mex_out);
   Embed_data_out_c = struct2cell(EMBED_out);
   [Mex_data_out_c, Embed_data_out_c, m, n] = pad_cells_2way(Mex_data_out_c, Embed_data_out_c);

   [total_num, ~] = size(var_data);
   name_size = 1;

   if isfield(testcase, 'Filename')
      test_name = testcase.Filename{name_size};
      name_size = name_size + 1;
   end

   [HTML_string, filename] = CreateSubReport(radar_name, test_case_num, test_case_cnt, test_name, path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, BB_version, true, spec_mex_mode);
   fid = fopen(filename, 'w+');
   fprintf(fid, HTML_string);
   fclose(fid);
   fprintf('Created Test Case Report #%d.\n', itr);
   HTML_Insert(filename, Pass_cnt, Fail_cnt, testcase_runtime(test_case_num), 0, 'Execution_Time');
   HTML_Insert(filename, Pass_cnt, Fail_cnt, 0, embed_runtime(test_case_num), 'Embed_Time');
   HTML_sum = CreateTestCase(radar_name, test_case_cnt, testcase_runtime(min(test_case_cnt + 1, numel(testcase_runtime))), test_name_overall);

   fields_mex = fieldnames(Mex_out);
   fields_embed = fieldnames(EMBED_out);

   tic;
   for j = 1:m
      for i = 1:n
         if numel(fields_mex) ~= numel(fields_embed)
            error('Outputs of mex structure and embed structure are not identical');
         end

         mex_data = cast(Mex_data_out_c{j, i}, 'double');
         embed_data = Embed_data_out_c{j, i};

         if isreal(mex_data) && isreal(embed_data)
            [data_rows, data_cols] = get_common_size(mex_data, embed_data);
            for row = 1:data_rows
               for col = 1:data_cols
                  if incr > total_num
                     [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                      HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                                       filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                                       HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                                       path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                                       BB_version, testcase_runtime, embed_runtime, itr, @(a, b, c, d, e, f, g, h, i, j) CreateSubReport(a, b, c, d, e, f, g, h, i, j, true, spec_mex_mode));
                  end

                  [name, incr, name_incr, namesize] = get_and_advance_var( ...
                                                                          var_data, incr, CFAR_flag, name_incr, namesize, test_case_cnt);

                  range_lin = var_data{incr - 1, 5};
                  range_dB = var_data{incr - 1, 6};
                  [Delta, dB_Delta] = measure_error_calc(double(mex_data(row, col)), embed_data(row, col), 1, name);

                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_mex_row( ...
                                                                                   filename, name, double(mex_data(row, col)), double(embed_data(row, col)), ...
                                                                                   Delta, dB_Delta, range_lin, range_dB, ...
                                                                                   Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
               end
            end
         else
            [data_rows, data_cols] = get_common_size(mex_data, embed_data);
            for row = 1:data_rows
               for col = 1:data_cols
                  em_raw = embed_data(row, col);
                  im_mex = imag(mex_data(row, col));
                  re_mex = real(mex_data(row, col));

                  if incr > total_num
                     [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                      HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                                       filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                                       HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                                       path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                                       BB_version, testcase_runtime, embed_runtime, itr, @(a, b, c, d, e, f, g, h, i, j) CreateSubReport(a, b, c, d, e, f, g, h, i, j, true, spec_mex_mode));
                  end

                  name_im = var_data{incr, 1};
                  name_re = var_data{incr + 1, 1};
                  range_im_lin = var_data{incr, 5};
                  range_re_lin = var_data{incr + 1, 5};
                  range_im_dB = var_data{incr, 6};
                  range_re_dB = var_data{incr + 1, 6};
                  [Delta_im, dB_Delta_im] = measure_error_calc(double(im_mex), imag(em_raw), 1, name_im);
                  [Delta_re, dB_Delta_re] = measure_error_calc(double(re_mex), real(em_raw), 1, name_re);

                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_mex_row( ...
                                                                                   filename, name_im, im_mex, double(imag(em_raw)), Delta_im, dB_Delta_im, ...
                                                                                   range_im_lin, range_im_dB, Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  incr = incr + 1;

                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_mex_row( ...
                                                                                   filename, name_re, re_mex, double(real(em_raw)), Delta_re, dB_Delta_re, ...
                                                                                   range_re_lin, range_re_dB, Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  incr = incr + 1;
               end
            end
         end
      end
   end

   [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = finalize_summary( ...
                                                                filename, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, tot_pass_cnt, tot_fail_cnt, ...
                                                                HTML_sum_1, HTML_sum, test_case_num, ExecTime, path_to_report_directory);
end

%% ========================================================================
%  TWO-WAY LEGACY: Embed vs Spec/TV data (comparison_type_flag ~= 1)
%  ========================================================================
function [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = compare_two_way( ...
                                                                     EMBED_out, data_out, path_to_report_directory, radar_name, ...
                                                                     test_name, test_name_overall, test_case_cnt, var_data, testcase_runtime, ...
                                                                     testcase, CFAR_flag, embed_runtime, comparison_type_flag, workbook, ...
                                                                     USC_version, BB_version, itr, report_fn)

   [tot_pass_cnt, tot_fail_cnt, tc_pass_cnt, tc_fail_cnt, ~, ~, ...
    HTML_sum_1, incr, test_case_num, namesize, name_incr, ExecTime] = init_counters();
   Pass_cnt = 0;
   Fail_cnt = 0;

   setup_report_directory(path_to_report_directory);

   EMBED_out_c = struct2cell(EMBED_out);
   data_out_c = struct2cell(data_out);
   [m, n] = size(EMBED_out_c);
   [total_num, ~] = size(var_data);

   name_size = 1;
   if isfield(testcase, 'Filename')
      test_name = testcase.Filename{name_size};
      name_size = name_size + 1;
   end

   [HTML_string, filename] = report_fn(radar_name, test_case_num, test_case_cnt, test_name, path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, BB_version);
   fid = fopen(filename, 'w+');
   fprintf(fid, HTML_string);
   fclose(fid);
   fprintf('Created Test Case Report #%d.\n', itr);
   HTML_Insert(filename, Pass_cnt, Fail_cnt, testcase_runtime(test_case_num), 0, 'Execution_Time');
   HTML_Insert(filename, Pass_cnt, Fail_cnt, 0, embed_runtime(test_case_num), 'Embed_Time');
   HTML_sum = CreateTestCase(radar_name, test_case_cnt, testcase_runtime(min(test_case_cnt + 1, numel(testcase_runtime))), test_name_overall);

   fields_alg = fieldnames(data_out);
   fields_embed = fieldnames(EMBED_out);

   tic;
   for i = 1:n
      for j = 1:m
         loc_fidx = find_field_index(fields_alg, fields_embed{j});
         embed_data = EMBED_out_c{j, i};
         tv_data = data_out_c{loc_fidx, i};

         if isreal(tv_data)
            [data_rows, data_cols] = size(embed_data);
            for row = 1:data_rows
               for col = 1:data_cols
                  if incr > total_num
                     [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                      HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                                       filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                                       HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                                       path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                                       BB_version, testcase_runtime, embed_runtime, itr, report_fn);
                  end

                  [name, incr, name_incr, namesize] = get_and_advance_var( ...
                                                                          var_data, incr, CFAR_flag, name_incr, namesize, test_case_cnt);

                  range_lin = var_data{incr - 1, 5};
                  range_rel = var_data{incr - 1, 6};
                  [Delta, ~] = measure_error_calc(double(tv_data(row, col)), embed_data(row, col), 1, name);
                  if isnan(range_lin)
                     rel_delta = (double(tv_data(row, col)) - double(embed_data(row, col))) / double(tv_data(row, col));
                  else
                     rel_delta = 0;
                  end

                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_2way_standalone_row( ...
                                                                                               filename, name, double(tv_data(row, col)), double(embed_data(row, col)), ...
                                                                                               Delta, rel_delta, range_lin, range_rel, range_rel, ...
                                                                                               Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
               end
            end
         else
            [data_rows, data_cols] = size(embed_data);
            for row = 1:data_rows
               for col = 1:data_cols
                  em_raw = embed_data(row, col);

                  if incr > total_num
                     [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                      HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                                       filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                                       HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                                       path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                                       BB_version, testcase_runtime, embed_runtime, itr, report_fn);
                  end

                  name_im = var_data{incr, 1};
                  name_re = var_data{incr + 1, 1};
                  range_im_lin = var_data{incr, 5};
                  range_re_lin = var_data{incr + 1, 5};
                  range_im_rel = var_data{incr, 6};
                  range_re_rel = var_data{incr + 1, 6};
                  [Delta_im, ~] = measure_error_calc(double(imag(tv_data(row, col))), imag(em_raw), 1, name_im);
                  [Delta_re, ~] = measure_error_calc(double(real(tv_data(row, col))), real(em_raw), 1, name_re);

                  tv_im = imag(tv_data(row, col));
                  em_im = double(imag(em_raw));
                  tv_re = real(tv_data(row, col));
                  em_re = double(real(em_raw));

                  % Imaginary
                  rel_im = conditional_pick(isnan(range_im_lin), (tv_im - em_im) / tv_im, 0);
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_2way_standalone_row( ...
                                                                                               filename, name_im, tv_im, em_im, Delta_im, rel_im, ...
                                                                                               range_im_lin, range_im_rel, range_im_rel * 100, ...
                                                                                               Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  incr = incr + 1;

                  % Real
                  rel_re = conditional_pick(isnan(range_re_lin), (tv_re - em_re) / tv_re, 0);
                  [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_2way_standalone_row( ...
                                                                                               filename, name_re, tv_re, em_re, Delta_re, rel_re, ...
                                                                                               range_re_lin, range_re_rel, range_re_rel * 100, ...
                                                                                               Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt);
                  incr = incr + 1;
               end
            end
         end
      end
   end

   [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = finalize_summary( ...
                                                                filename, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, tot_pass_cnt, tot_fail_cnt, ...
                                                                HTML_sum_1, HTML_sum, test_case_num, ExecTime, path_to_report_directory);
end

%% ========================================================================
%  LOCAL HELPER FUNCTIONS
%  ========================================================================

function result = conditional_pick(condition, val_true, val_false)
   if condition
      result = val_true;
   else
      result = val_false;
   end
end

function [tot_pass, tot_fail, tc_pass, tc_fail, Fail, Pass, sum1, incr, tc_num, ns, ni, et] = init_counters()
   tot_pass = 0;
   tot_fail = 0;
   tc_pass = 0;
   tc_fail = 0;
   Fail = 0;
   Pass = 0;
   sum1 = [];
   incr = 1;
   tc_num = 1;
   ns = 0;
   ni = 1;
   et = 0;
end

function idx = find_field_index(fields, target_name)
   idx = find(strcmp(fields, target_name), 1);
   if isempty(idx)
      idx = numel(fields);
   end
end

function [rows, cols] = get_common_size(varargin)
   rows = inf;
   cols = inf;
   for k = 1:nargin
      [r, c] = size(varargin{k});
      rows = min(rows, r);
      cols = min(cols, c);
   end
end

function [A, B, C, m, n] = pad_cells_3way(A, B, C)
   [ar, ac] = size(A);
   [br, bc] = size(B);
   [cr, cc] = size(C);
   m = min([ar br cr]);
   n = min([ac bc cc]);
   A = pad_cell(A, m, n);
   B = pad_cell(B, m, n);
   C = pad_cell(C, m, n);
end

function [A, B, m, n] = pad_cells_2way(A, B)
   [ar, ac] = size(A);
   [br, bc] = size(B);
   m = min([ar br]);
   n = min([ac bc]);
   A = pad_cell(A, m, n);
   B = pad_cell(B, m, n);
end

function C = pad_cell(C, m, n)
   [r, c] = size(C);
   for ri = r + 1:m
      for ci = 1:c
         C{ri, ci} = 0;
      end
   end
   for ri = 1:min(r, m)
      for ci = c + 1:n
         C{ri, ci} = 0;
      end
   end
end

function [name, incr, name_incr, namesize] = get_and_advance_var(var_data, incr, CFAR_flag, name_incr, namesize, test_case_cnt)
   if CFAR_flag
      if name_incr <= test_case_cnt
         name = var_data{name_incr + namesize, 1};
      else
         namesize = namesize + (var_data{name_incr - 1 + namesize, 2}(1) * var_data{name_incr + namesize, 2}(2));
         name_incr = 1;
         name = var_data{name_incr + namesize, 1};
      end
   else
      name = var_data{incr, 1};
   end
   incr = incr + 1;
   name_incr = name_incr + 1;
end

function [test_case_num, incr, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
         HTML_sum_1, filename, name_size, test_name] = rollover_test_case( ...
                                                                          filename, test_case_num, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, ...
                                                                          HTML_sum_1, ExecTime, testcase, name_size, radar_name, test_case_cnt, test_name, ...
                                                                          path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, ...
                                                                          BB_version, testcase_runtime, embed_runtime, itr, create_report_fn)

   incr = 1;
   test_case_num = test_case_num + 1;

   html_append(filename, '</tbody>\n</table>\n</td>\n</tr>\n</tbody>\n</table>');
   HTML_Insert(filename, Pass_cnt, Fail_cnt, ExecTime, 0, 'Pass_Fail');

   if (Pass_cnt / max(Pass_cnt + Fail_cnt, 1)) == 1
      pass_fail = 'PASS';
      tc_pass_cnt = tc_pass_cnt + 1;
      color = '#CCFFCC';
   else
      pass_fail = 'FAIL';
      tc_fail_cnt = tc_fail_cnt + 1;
      color = '#FF9292';
   end

   HTML_sum_1 = [HTML_sum_1, '<tr bgcolor="#EEEEEE">\n<td><a href="./Testcases/Testcase_', ...
                 num2str(test_case_num - 1), '.html">Testcase ', num2str(test_case_num - 1), ...
                 '</a></td>\n<td>', num2str(Pass_cnt), ' / ', num2str(Pass_cnt + Fail_cnt), ...
                 '</td><td bgcolor="', color, '">', pass_fail, '</td></tr>\n'];
   Pass_cnt = 0;
   Fail_cnt = 0;

   if isfield(testcase, 'Filename') && name_size <= numel(testcase.Filename)
      test_name = testcase.Filename{name_size};
      name_size = name_size + 1;
   end

   [HTML_string, filename] = create_report_fn(radar_name, test_case_num, test_case_cnt, ...
                                              test_name, path_to_report_directory, CFAR_flag, comparison_type_flag, workbook, USC_version, BB_version);
   fid = fopen(filename, 'w+');
   fprintf(fid, HTML_string);
   fclose(fid);
   fprintf('Created Test Case Report #%d.\n', itr);
   % Clamp indices so a scalar or under-sized runtime array never causes
   % an out-of-bounds error (e.g. embed_time_taken passed as a scalar).
   tc_idx = min(test_case_num, numel(testcase_runtime));
   em_idx = min(test_case_num, numel(embed_runtime));
   HTML_Insert(filename, Pass_cnt, Fail_cnt, testcase_runtime(tc_idx), 0, 'Execution_Time');
   HTML_Insert(filename, Pass_cnt, Fail_cnt, 0, embed_runtime(em_idx), 'Embed_Time');
end

function [tc_fail_cnt, tot_pass_cnt, tot_fail_cnt] = finalize_summary( ...
                                                                      filename, Pass_cnt, Fail_cnt, tc_pass_cnt, tc_fail_cnt, tot_pass_cnt, tot_fail_cnt, ...
                                                                      HTML_sum_1, HTML_sum, test_case_num, ExecTime, path_to_report_directory)

   html_append(filename, '</tbody>\n</table>\n</td>\n</tr>\n</tbody>\n</table>');
   HTML_Insert(filename, Pass_cnt, Fail_cnt, ExecTime, 0, 'Pass_Fail');

   if (Pass_cnt / max(Pass_cnt + Fail_cnt, 1)) >= 0.98
      pass_fail = 'PASS';
      tc_pass_cnt = tc_pass_cnt + 1;
      color = '#CCFFCC'; %#ok<NASGU>
   else
      pass_fail = 'FAIL';
      tc_fail_cnt = tc_fail_cnt + 1;
      color = '#FF9292';
   end

   HTML_sum_1 = [HTML_sum_1, '<tr bgcolor="#EEEEEE">\n<td><a href="./Testcases/Testcase_', ...
                 num2str(test_case_num), '.html">Testcase ', num2str(test_case_num), ...
                 '</a></td>\n<td>', num2str(Pass_cnt), ' / ', num2str(Pass_cnt + Fail_cnt), ...
                 '</td><td bgcolor="', color, '">', pass_fail, '</td></tr>\n'];
   HTML_sum_1 = [HTML_sum_1, '</tbody>\n</table>\n</td>\n</tr>\n</tbody>\n</table>'];

   filename_sum = fullfile(path_to_report_directory, 'Reports', 'Testcase_Summary.html');
   HTML_sumID = fopen(filename_sum, 'w+');
   fprintf(HTML_sumID, strcat(HTML_sum, HTML_sum_1));
   HTML_Insert(filename_sum, tot_pass_cnt, tot_fail_cnt, ExecTime, 0, 'Total_Pass_Fail');
   HTML_Insert(filename_sum, tc_pass_cnt, tc_fail_cnt, ExecTime, 0, 'Pass_Fail');
   fclose(HTML_sumID);
   fprintf('Created Test Case Summary.\nComplete.\n');
end

function [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_mex_row( ...
                                                                          filename, name, v1, v2, delta, dB_delta, range_lin, range_dB, ...
                                                                          Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt)
   % WRITE_MEX_ROW  Write a Mex-vs-Embed standalone pass/fail row (2 values).
   if ~isnan(range_lin)
      passed = abs(delta) <= range_lin;
      row_str = sprintf('<tr bgcolor="#EEEEEE">\n<td>%s&nbsp;&nbsp;&nbsp;</td>\n<td>%6g</td>\n<td>%6g</td>\n<td>%6g</td>\n<td>+&nbsp;/&nbsp;-&nbsp;&nbsp;%5g</td>\n', ...
                        name, v1, v2, range_lin, abs(delta));
   else
      % dB comparison: error_log is 20*log10(abs(error)), so negative = small error
      % Check if error magnitude (in dB) is below threshold
      passed = dB_delta <= range_dB;
      row_str = sprintf('<tr bgcolor="#EEEEEE">\n<td>%s&nbsp;&nbsp;&nbsp;</td>\n<td>%6g</td>\n\n<td>%6g</td><td>%6g</td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%5g&nbsp;dB </td>\n', ...
                        name, v1, v2, range_dB, dB_delta);
   end
   if passed
      html_append(filename, [row_str, '<td bgcolor="#CCFFCC">PASS</td>']);
      Pass_cnt = Pass_cnt + 1;
      tot_pass_cnt = tot_pass_cnt + 1;
   else
      html_append(filename, [row_str, '<td bgcolor="#FF9292">FAIL</td>']);
      Fail_cnt = Fail_cnt + 1;
      tot_fail_cnt = tot_fail_cnt + 1;
   end
end

function [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_2way_standalone_row( ...
                                                                                      filename, name, v1, v2, delta, rel_delta, range_lin, range_rel, display_range_rel, ...
                                                                                      Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt)
   % WRITE_2WAY_STANDALONE_ROW  Write a complete 2-value pass/fail table row (closes row).
   if ~isnan(range_lin)
      passed = abs(delta) <= range_lin;
      row_str = sprintf('<tr bgcolor="#EEEEEE">\n<td>%s&nbsp;&nbsp;&nbsp;</td>\n<td>%6g</td>\n<td>%6g</td>\n<td>+&nbsp;/&nbsp;-&nbsp;&nbsp;%5g</td>\n', name, v1, v2, range_lin);
   else
      passed = abs(rel_delta) <= range_rel;
      row_str = sprintf('<tr bgcolor="#EEEEEE">\n<td>%s&nbsp;&nbsp;&nbsp;</td>\n<td>%6g</td>\n<td>%6g</td>\n<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%5g&nbsp;dB </td>\n', name, v1, v2, display_range_rel);
   end
   if passed
      html_append(filename, [row_str, '<td bgcolor="#CCFFCC">PASS</td></tr>\n']);
      Pass_cnt = Pass_cnt + 1;
      tot_pass_cnt = tot_pass_cnt + 1;
   else
      html_append(filename, [row_str, '<td bgcolor="#FF9292">FAIL</td></tr>\n']);
      Fail_cnt = Fail_cnt + 1;
      tot_fail_cnt = tot_fail_cnt + 1;
   end
end
