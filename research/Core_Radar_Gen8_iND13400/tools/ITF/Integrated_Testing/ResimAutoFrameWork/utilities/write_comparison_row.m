function [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_comparison_row( ...
                                                                                 filename, name, values, delta, dB_delta, range_lin, range_dB, ...
                                                                                 row_prefix, row_suffix, Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt)
   % WRITE_COMPARISON_ROW  Write a pass/fail HTML table row with name, value columns, and result.
   %   Used for 3-way comparison row openers (SPEC vs MEX) that display all three data values.
   %
   %   Inputs:
   %     filename    - path to the HTML report file
   %     name        - variable name label
   %     values      - cell array of numeric values to display in <td> columns
   %     delta       - absolute difference value
   %     dB_delta    - dB difference value (used when range_lin is NaN)
   %     range_lin   - linear tolerance (NaN triggers dB comparison)
   %     range_dB    - dB tolerance (used when range_lin is NaN)
   %     row_prefix  - HTML before the data (e.g. '<tr bgcolor="#EEEEEE">\n')
   %     row_suffix  - HTML after the PASS/FAIL cell (e.g. '</tr>\n' or '')
   %     Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt - running counters

   [passed, display_val, display_range] = evaluate_pass_fail(delta, dB_delta, range_lin, range_dB);

   % Build value columns
   val_cols = '';
   for k = 1:numel(values)
      val_cols = [val_cols, sprintf('<td>%6g</td>\n', values{k})]; %#ok<AGROW>
   end

   % Build name column
   name_col = sprintf('<td>%s&nbsp;&nbsp;&nbsp;</td>\n', name);

   % Build result cell
   if passed
      color_cell = sprintf('<td>%s</td><td bgcolor="#CCFFCC">PASS</td>', display_val);
      Pass_cnt = Pass_cnt + 1;
      tot_pass_cnt = tot_pass_cnt + 1;
   else
      color_cell = sprintf('<td>%s</td><td bgcolor="#FF9292">FAIL</td>', display_val);
      Fail_cnt = Fail_cnt + 1;
      tot_fail_cnt = tot_fail_cnt + 1;
   end

   html_str = [row_prefix, name_col, val_cols, '<td>', display_range, '</td>\n', color_cell, row_suffix];
   html_append(filename, html_str);
end
