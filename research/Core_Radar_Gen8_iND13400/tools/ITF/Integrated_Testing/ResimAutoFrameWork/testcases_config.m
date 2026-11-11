%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: testcases_config()
%   This function configs the selected testcases
%
% Return Variables:
%   dir_size
%   temp_dir
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [dir_size, temp_dir] = testcases_config(sensor_type)

   config = ini2struct('testcases.ini');

   % Extract test list
   tests = config.SelectedTests.tests;

   % Split test names
   if ischar(tests) || isstring(tests)
      selected_tests = strtrim(split(string(tests), ','));
   else
      error('Unexpected format for test case list.');
   end

   source_dir = fullfile(pwd, 'File', 'CSV', sensor_type);
   temp_dir = fullfile(pwd, 'TempTests', sensor_type);

   if exist(temp_dir, 'dir')
      delete(fullfile(temp_dir, '*.csv'));  % Delete all CSV files
   else
      mkdir(temp_dir);
   end
   % Copy selected test cases
   for i = 1:length(selected_tests)
      test_name = char(selected_tests{i});
      test_file = fullfile(source_dir, [test_name, '.csv']);

      if exist(test_file, 'file')
         copyfile(test_file, temp_dir);
         fprintf('Copied: %s\n', test_name);
      else
         warning('Test case %s not found.', test_name);
      end
   end
   temp_dir = dir(['./TempTests/' sensor_type '/*.csv']);
   dir_size = size(temp_dir, 1);

end
