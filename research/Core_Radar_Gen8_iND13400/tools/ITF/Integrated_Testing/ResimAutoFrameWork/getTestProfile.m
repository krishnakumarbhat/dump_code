% %%% API for extracting test profile from CSV file
%  Name: getTestProfile()
%   This function extracts the test profile from the given CSV file
%  Inputs:
%   nargin - number of input arguments
%   varargin - variable input arguments (test vector file name and file path)
%   BB_flag - flag to indicate if building block name needs to be set
%  Outputs:
%   FileName - name of the test vector file
%   testVecFileName - full path of the test vector file
%   testVecData - data read from the test vector file
%   cycles - unique cycle indices from the test vector data
%   startCycle - starting cycle index
%   endCycle - ending cycle index
%   testcase_dir_name - name of the test case directory

function [FileName, testVecFileName, testVecData, cycles, startCycle, endCycle, testcase_dir_name] = getTestProfile(n_args, varargin, BB_flag)
   global sensor_type test_case_name BB_name Count_Look_Processing Count_CFAR Count_First_Pass Count_Second_Pass Count_Angle_Finding

   if n_args == 0
      PathName = ['.\File\CSV\', sensor_type, '\'];
      FileName = ['RCT_001_', sensor_type, '_RSC.csv']; % select file index number
      testVecFileName = [PathName FileName];
   else
      testVecFileName = varargin{1};
      FileName = varargin{2};
   end

   sprintf('Running Test Spec : %s \n', testVecFileName);
   testVecData = readmatrix(testVecFileName);
   [~, cycles] = unique(testVecData(:, 2)); % index location
   startCycle = 1;
   endCycle = length(cycles);

   % Create final report directory string
   testcase_dir_name = strsplit(testVecFileName, '/');
   testcase_dir_name = testcase_dir_name{numel(testcase_dir_name)};
   testcase_dir_name = strsplit(testcase_dir_name, '\');
   testcase_dir_name = testcase_dir_name{numel(testcase_dir_name)};
   testcase_dir_name = strsplit(testcase_dir_name, '.csv');
   testcase_dir_name = testcase_dir_name{1};
   test_case_name = testcase_dir_name;

   if BB_flag == 1
      % TODO Mention the file name to load
      %     if (strcmp(testcase_dir_name,['RCT_001_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_002_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_003_' sensor_type '_RSC']) ||...
      %         strcmp(testcase_dir_name,['RCT_004_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_005_' sensor_type '_RSC']))
      %         BB_name='Look_Processing';
      %         Count_Look_Processing=Count_Look_Processing + 1;
      %     elseif  (strcmp(testcase_dir_name,['RCT_006_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_007_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_008_' sensor_type '_RSC']))
      %         BB_name='CFAR';
      %         Count_CFAR=Count_CFAR + 1;
      %     elseif (strcmp(testcase_dir_name,['RCT_009_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_010_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_011_' sensor_type '_RSC']) ||...
      %         strcmp(testcase_dir_name,['RCT_012_' sensor_type '_RSC'])...
      %             || strcmp(testcase_dir_name,['RCT_028_' sensor_type '_RSC']))
      %         BB_name='First_Pass';
      %         Count_First_Pass= Count_First_Pass + 1;
      %     elseif (strcmp(testcase_dir_name,['RCT_013_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_014_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_015_' sensor_type '_RSC']) ||...
      %       strcmp(testcase_dir_name,['RCT_023_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_024_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_025_' sensor_type '_RSC'])...
      %             || strcmp(testcase_dir_name,['RCT_029_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_031_' sensor_type '_RSC']))
      %         BB_name='Second_Pass';
      %         Count_Second_Pass= Count_Second_Pass + 1;
      %     elseif (strcmp(testcase_dir_name,['RCT_016_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_017_' sensor_type '_RSC'])...
      %             || strcmp(testcase_dir_name,['RCT_032_' sensor_type '_RSC']) || strcmp(testcase_dir_name,['RCT_033_' sensor_type '_RSC']))
      %         BB_name='Angle_Finding';
      %         Count_Angle_Finding=Count_Angle_Finding + 1;
      %     end
   end

end
