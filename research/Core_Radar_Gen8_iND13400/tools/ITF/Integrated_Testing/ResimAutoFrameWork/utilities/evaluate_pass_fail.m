function [passed, display_val, display_range] = evaluate_pass_fail(delta, dB_delta, range_lin, range_dB)
   % EVALUATE_PASS_FAIL  Decide pass/fail and format display values.
   %   Inputs:
   %     delta      - absolute difference
   %     dB_delta   - dB difference (used when range_lin is NaN)
   %     range_lin  - linear threshold (NaN means use dB)
   %     range_dB   - dB threshold (used when range_lin is NaN)
   %   Outputs:
   %     passed        - true if within range
   %     display_val   - formatted value string for HTML
   %     display_range - formatted range string for HTML
   if ~isnan(range_lin)
      passed = abs(delta) <= range_lin;
      display_val   = sprintf('%6g', abs(delta));
      display_range = sprintf('+&nbsp;/&nbsp;-&nbsp;&nbsp;%5g', range_lin);
   else
      display_range = sprintf('&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%5g&nbsp;dB', range_dB);
      if dB_delta == -Inf
         % log10(0) = -Inf means the error is exactly zero — perfect match.
         passed      = true;
         display_val = sprintf('%6g&nbsp;dB', 0);
      elseif ~isfinite(dB_delta)
         % +Inf or NaN: indeterminate result, conservatively mark as FAIL.
         passed      = false;
         display_val = 'N/A&nbsp;dB';
      else
         passed      = dB_delta <= range_dB;
         display_val = sprintf('%6g&nbsp;dB', dB_delta);
      end
   end
end
