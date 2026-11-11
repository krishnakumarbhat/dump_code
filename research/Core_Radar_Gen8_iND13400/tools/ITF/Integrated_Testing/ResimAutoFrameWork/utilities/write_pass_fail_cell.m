function [Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt] = write_pass_fail_cell( ...
                                                                                 filename, delta, dB_delta, range_lin, range_dB, row_suffix, ...
                                                                                 Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt)
   % WRITE_PASS_FAIL_CELL  Write a continuation pass/fail cell (no row opener, no name column).
   %   Used for SPEC-vs-EMBED and MEX-vs-EMBED cells that continue an already-opened row.
   %
   %   Inputs:
   %     filename   - HTML report file
   %     delta      - absolute difference
   %     dB_delta   - dB difference
   %     range_lin  - linear tolerance (NaN triggers dB mode)
   %     range_dB   - dB tolerance
   %     row_suffix - '' to keep row open, '</tr>\n' to close it
   %     Pass_cnt, Fail_cnt, tot_pass_cnt, tot_fail_cnt - running counters

   [passed, display_val, ~] = evaluate_pass_fail(delta, dB_delta, range_lin, range_dB);

   if passed
      html_str = sprintf('<td>%s</td><td bgcolor="#CCFFCC">PASS</td>%s', display_val, row_suffix);
      Pass_cnt = Pass_cnt + 1;
      tot_pass_cnt = tot_pass_cnt + 1;
   else
      html_str = sprintf('<td>%s</td><td bgcolor="#FF9292">FAIL</td>%s', display_val, row_suffix);
      Fail_cnt = Fail_cnt + 1;
      tot_fail_cnt = tot_fail_cnt + 1;
   end

   html_append(filename, html_str);
end
