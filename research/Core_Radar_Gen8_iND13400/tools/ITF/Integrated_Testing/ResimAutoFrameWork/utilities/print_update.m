% Overwrite a line of output. Allows printing progress, without filling the command window with updates.
%
% Inputs:
%   update_info_str - String to put at start of line
%   last_string_length - Input the length of the previous string written, if 0, will start a new line.
%   num_done - Input the number of inputs that have been completed.
%   num_tot - Input the number that are supposed to be processed.
%
% Outputs:
%   string_length - Output the length of the string written
%
%
% Example:
%
%    last_update = 0;
%
%    for k = 1:420
%        last_update = print_update('Collected data for rangebin', last_update, k, 420);
%        pause(0.01)
%    end
%
% Result:
%   Collected data for rangebin: 420 of 420
function string_length = print_update(update_info_str, last_string_length, num_done, num_tot)

   if last_string_length > 0
      while last_string_length > 0
         fprintf('\b');
         last_string_length = last_string_length - 1;
      end
   else
      fprintf('\n');
   end

   string_length = fprintf('%s: %d of %d', update_info_str, num_done, num_tot);

   if num_done == num_tot
      string_length = 0;
      fprintf('\nComplete\n');
   end
