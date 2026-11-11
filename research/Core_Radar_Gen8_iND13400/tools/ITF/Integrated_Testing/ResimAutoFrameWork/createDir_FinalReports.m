%%% createDir_FinalReports.m
%   This function creates the necessary directory structure for storing final reports of test cases.
% Inputs:
%   testcase_dir_name - Name of the test case directory.
% Outputs:
%   None
function createDir_FinalReports(testcase_dir_name)

   % Always ensure the root Reports directory exists first
   if ~exist('./Reports', 'dir')
      mkdir('./Reports');
   end

   % Creating directory used for the final reports
   if 7 == exist(['./Reports/' testcase_dir_name], 'dir')
      rmdir(['./Reports/' testcase_dir_name], 's');
   end
   mkdir(['./Reports/' testcase_dir_name]);
   mkdir(['./Reports/' testcase_dir_name '/Final_Outputs']);

end
