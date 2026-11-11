%%% RunTest_Suite_IT.m
%   Runs the Integration Test Suite for a specified sensor type.
%   Creates individual and consolidated reports.
%
%   Features:
%   - GUI-based configuration via Suite_Dialog
%   - Robust error handling with hardware reset on retry
%   - Proper calibration loading for consolidated reports
%   - Clean global state management
%
% Usage:
%   RunTest_Suite_IT()           % Interactive mode with GUI
%   RunTest_Suite_IT(suiteConfig) % Programmatic mode with config struct

function RunTest_Suite_IT(varargin)

   %% This script auto-generates test profiles for FLR8 and SRR8P sensors so
   %% the Suite_Dialog test list is always populated. Calibration files (SMC/USC)
   %% are downloaded first if missing, since PopulateParams.(sensor).gen_test_profiles()
   %% requires them on disk before it can build CSVs for that sensor.
   AUTO_GENERATE_CSV = 1;

   if AUTO_GENERATE_CSV
      ensure_test_profiles_ready('SRR8P');
      ensure_test_profiles_ready('FLR8');
   end

   %% Parse input arguments
   show_dialog = true;
   if nargin >= 1 && isstruct(varargin{1})
      suiteConfig = varargin{1};
      show_dialog = false;
   else
      suiteConfig = get_default_suite_config();
   end

   %% Show Suite Dialog (if interactive mode)
   if show_dialog
      suiteConfig = Suite_Dialog(true, suiteConfig);
      if isempty(suiteConfig)
         fprintf('[Suite##Info] Test suite cancelled by user.\n');
         return
      end
   end

   %% Initialize global state for SITP reporting
   init_global_state(suiteConfig);

   %% Setup paths and calibrations
   [WorkbookPath, variant, variant_config] = setup_paths(suiteConfig.sensor_type);

   %% Download calibration files
   download_smc_usc(WorkbookPath, variant);

   %% Load calibration data (needed for consolidated report)
   [smc_cal, usc_cal] = load_calibrations(WorkbookPath);

   %% Generate test profiles if requested
   if suiteConfig.gen_test_profiles
      generate_test_profiles(suiteConfig.sensor_type);
   end

   %% Get test case list
   testcase_list = get_testcase_list(suiteConfig);
   num_tests = numel(testcase_list);

   if num_tests == 0
      warning('[Suite##Warn] No test cases found. Exiting.');
      return
   end

   fprintf('[Suite##Info] Starting test suite with %d test case(s).\n', num_tests);
   suite_start_time = tic;

   %% Initialize result tracking
   results = struct('name', {}, 'status', {}, 'error', {}, 'attempts', {});

   %% Execute each test case
   for test_idx = 1:num_tests
      testcase_name = testcase_list(test_idx).name;
      testcase_path = fullfile('.', 'File', 'CSV', suiteConfig.sensor_type, testcase_name);

      fprintf('\n[Suite##Info] ========================================\n');
      fprintf('[Suite##Info] Test %d/%d: %s\n', test_idx, num_tests, testcase_name);
      fprintf('[Suite##Info] ========================================\n');

      test_result = execute_test_with_retry( ...
                                            testcase_path, ...
                                            testcase_name, ...
                                            suiteConfig);

      results(test_idx) = test_result;
   end

   %% Generate suite summary
   suite_elapsed = toc(suite_start_time) / 60;
   print_suite_summary(results, suite_elapsed);

   %% Generate HTML report (always, even on errors)
   generate_html_report(results, suiteConfig, suite_elapsed, smc_cal, usc_cal);

   %% Generate consolidated report if requested
   if suiteConfig.need_consolidated_report
      generate_consolidated_report(smc_cal, usc_cal);
   end

   fprintf('[Suite##Info] Test suite completed in %.2f minutes.\n', suite_elapsed);

end

%% ========================================================================
%  HELPER FUNCTIONS
%% ========================================================================

function config = get_default_suite_config()
   % Returns default suite configuration
   config = struct( ...
                   'sensor_type', 'FLR8', ...
                   'run_all_tests', 0, ...
                   'gen_test_profiles', 0, ...
                   'need_consolidated_report', 1, ...
                   'max_retries', 2, ...
                   'selected_tests', {{}}, ...
                   'debug_mode', 0, ...
                   'offline_mode_inject', 2, ...
                   'build_flag', 0, ...
                   'clean_build', 0, ...
                   'sitp_run', 1);
end

function init_global_state(suiteConfig)
   % Initialize global variables for SITP reporting and test tracking
   global GUI_Enable sensor_type sitp_run need_consolidated_report
   global integTesting Count_Look_Processing Count_CFAR
   global Count_First_Pass Count_Second_Pass Count_Angle_Finding
   global suite_mode_active suite_config

   % Suite mode flag - disables Flag_Dialog in RunTest_Integration
   suite_mode_active = true;
   suite_config = suiteConfig;

   GUI_Enable = 0;
   sensor_type = suiteConfig.sensor_type;
   sitp_run = suiteConfig.sitp_run;
   need_consolidated_report = suiteConfig.need_consolidated_report;
   integTesting = 1;

   % Reset counters
   Count_Look_Processing = 0;
   Count_CFAR = 0;
   Count_First_Pass = 0;
   Count_Second_Pass = 0;
   Count_Angle_Finding = 0;

   % Initialize SITP reporting globals if needed
   if sitp_run
      global dir_size call_count
      global sitp_color str_label test_case_result
      global sitp_error

      dir_size = 0;
      call_count = 0;
      sitp_error = 0;
      test_case_result = {};
      str_label = {};
      sitp_color = {};
   end
end

function [WorkbookPath, variant, variant_config] = setup_paths(sensor_type)
   % Setup paths and validate sensor type
   valid_sensors = {'FLR8', 'SRR8P'};
   if ~ismember(sensor_type, valid_sensors)
      error('Unsupported sensor_type: %s. Only FLR8 and SRR8P are allowed.', sensor_type);
   end

   WorkbookPath = fullfile('.', 'workbook', sensor_type);
   addpath(WorkbookPath);

   % Map sensor type to variant names
   variant_map = struct('FLR8', 'flr8', 'SRR8P', 'srr8p');
   config_map = struct('FLR8', 'flr8_satellite_can', 'SRR8P', 'srr8p_satellite_can');

   variant = variant_map.(sensor_type);
   variant_config = config_map.(sensor_type);
end

function [smc_cal, usc_cal] = load_calibrations(WorkbookPath)
   % Load SMC and USC calibration files
   smc_cal = [];
   usc_cal = [];

   smc_files = dir(fullfile(WorkbookPath, 'smc_cal*.mat'));
   if ~isempty(smc_files)
      smc_data = load(fullfile(WorkbookPath, smc_files(1).name));
      if isfield(smc_data, 'smc_cal')
         smc_cal = smc_data.smc_cal;
      end
   else
      warning('[Suite##Warn] No SMC calibration file found in %s', WorkbookPath);
   end

   usc_files = dir(fullfile(WorkbookPath, 'usc_cal*.mat'));
   if ~isempty(usc_files)
      usc_data = load(fullfile(WorkbookPath, usc_files(1).name));
      if isfield(usc_data, 'usc_cal')
         usc_cal = usc_data.usc_cal;
      end
   else
      warning('[Suite##Warn] No USC calibration file found in %s', WorkbookPath);
   end
end

function ensure_test_profiles_ready(sensor_variant)
   % Pre-flight helper: makes sure SMC/USC calibration files exist for
   % sensor_variant (downloading them if missing) before attempting to
   % generate its test profile CSVs. Without calibration files on disk,
   % PopulateParams.(sensor).gen_test_profiles() always fails on a fresh
   % checkout, which previously showed up as an unexplained warning on
   % the very first run.
   [WorkbookPath, variant, ~] = setup_paths(sensor_variant);

   if ~calibration_files_exist(WorkbookPath)
      fprintf('[Suite##Info] Calibration files missing for %s. Downloading...\n', sensor_variant);
      try
         download_smc_usc(WorkbookPath, variant);
      catch ME
         warning('[Suite##Warn] Failed to download calibration for %s: %s', sensor_variant, ME.message);
         return
      end
   end

   generate_test_profiles(sensor_variant);
end

function tf = calibration_files_exist(WorkbookPath)
   % Returns true only if BOTH SMC and USC calibration mat files are present.
   smc_files = dir(fullfile(WorkbookPath, 'smc_cal*.mat'));
   usc_files = dir(fullfile(WorkbookPath, 'usc_cal*.mat'));
   tf = ~isempty(smc_files) && ~isempty(usc_files);
end

function generate_test_profiles(sensor_variant)
   % Generate test profile CSVs for sensor_variant using PopulateParams.
   %
   % IMPORTANT: PopulateParams.(sensor).gen_test_profiles() internally reads
   % the GLOBAL 'sensor_type' variable (not its own input argument, which is
   % actually a Suite_IT flag) to resolve the workbook/CSV paths. That global
   % MUST be set to sensor_variant before invoking, or it silently uses a
   % stale/empty value and fails. (The argument here is named sensor_variant,
   % not sensor_type, specifically so 'global sensor_type' can be declared in
   % this function without a name-collision error.)
   global sensor_type
   prev_sensor_type = sensor_type;
   sensor_type = sensor_variant;

   addpath(fullfile('..', '..', 'ExecutableSpecs', 'ADVRADAR_Gen7_Exec_Spec', 'GUI'));
   try
      PopulateParams.(sensor_variant).gen_test_profiles(1);
      fprintf('[Suite##Info] Test profiles generated successfully for %s.\n', sensor_variant);
   catch ME
      warning('[Suite##Warn] Failed to generate test profiles for %s: %s', sensor_variant, ME.message);
   end

   sensor_type = prev_sensor_type;
end

function testcase_list = get_testcase_list(suiteConfig)
   % Get list of test cases to run
   sensor_type = suiteConfig.sensor_type;

   if suiteConfig.run_all_tests
      % Get all CSV files from the sensor folder
      testcase_dir = fullfile('.', 'File', 'CSV', sensor_type);
      testcase_list = dir(fullfile(testcase_dir, '*.csv'));
   elseif ~isempty(suiteConfig.selected_tests)
      % Use selected tests from config
      testcase_dir = fullfile('.', 'File', 'CSV', sensor_type);
      testcase_list = struct('name', {}, 'folder', {});
      for i = 1:numel(suiteConfig.selected_tests)
         test_name = suiteConfig.selected_tests{i};
         test_file = fullfile(testcase_dir, test_name);
         if exist(test_file, 'file')
            testcase_list(end + 1).name = test_name;
            testcase_list(end).folder = testcase_dir;
         else
            warning('[Suite##Warn] Test case not found: %s', test_name);
         end
      end
   else
      % Use testcases.ini configuration
      [~, testcase_list] = testcases_config(sensor_type);
   end

   % Update global dir_size for SITP reporting
   global dir_size
   dir_size = numel(testcase_list);
end

function result = execute_test_with_retry(testcase_path, testcase_name, suiteConfig)
   % Execute a single test with retry logic
   result = struct( ...
                   'name', testcase_name, ...
                   'status', 'FAILED', ...
                   'error', '', ...
                   'attempts', 0);

   for attempt = 1:suiteConfig.max_retries
      result.attempts = attempt;

      try
         fprintf('[Suite##Info] Attempt %d/%d for %s\n', ...
                 attempt, suiteConfig.max_retries, testcase_name);

         % Call RunTest_Integration with suite mode parameters
         RunTest_Integration(testcase_path, testcase_name);

         % If we reach here, test passed
         result.status = 'PASSED';
         result.error = '';
         fprintf('[Suite##Info] Test PASSED: %s\n', testcase_name);
         return

      catch ME
         result.error = ME.message;
         fprintf('[Suite##Error] Attempt %d failed: %s\n', attempt, ME.message);

         if attempt < suiteConfig.max_retries
            % Brief pause before retry
            pause(2);
         end
      end
   end

   % All retries exhausted
   fprintf('[Suite##Error] Test FAILED after %d attempts: %s\n', ...
           suiteConfig.max_retries, testcase_name);

   % Save error information
   save_error_report(testcase_name, result.error);

   % Update SITP error count
   global sitp_run sitp_error
   if sitp_run
      sitp_error = sitp_error + 1;
   end
end

function save_error_report(testcase_name, error_message)
   % Save error information to file
   report_name = strrep(testcase_name, '.csv', '');
   report_dir = fullfile('.', 'Reports', report_name);

   if ~exist(report_dir, 'dir')
      mkdir(report_dir);
   end

   ERR = struct('message', error_message, 'timestamp', datestr(now));
   save(fullfile(report_dir, 'error.mat'), 'ERR');
end

function print_suite_summary(results, elapsed_minutes)
   % Print summary of test results
   num_passed = sum(strcmp({results.status}, 'PASSED'));
   num_failed = sum(strcmp({results.status}, 'FAILED'));
   total = numel(results);

   fprintf('\n');
   fprintf('========================================\n');
   fprintf('         TEST SUITE SUMMARY\n');
   fprintf('========================================\n');
   fprintf('Total Tests:  %d\n', total);
   fprintf('Passed:       %d (%.1f%%)\n', num_passed, 100 * num_passed / max(1, total));
   fprintf('Failed:       %d (%.1f%%)\n', num_failed, 100 * num_failed / max(1, total));
   fprintf('Duration:     %.2f minutes\n', elapsed_minutes);
   fprintf('========================================\n');

   if num_failed > 0
      fprintf('\nFailed Tests:\n');
      for i = 1:numel(results)
         if strcmp(results(i).status, 'FAILED')
            fprintf('  - %s (after %d attempts)\n', results(i).name, results(i).attempts);
            if ~isempty(results(i).error)
               fprintf('    Error: %s\n', results(i).error);
            end
         end
      end
   end
   fprintf('\n');
end

function generate_html_report(results, suiteConfig, elapsed_minutes, smc_cal, usc_cal)
   % Generate comprehensive HTML report with all test results and errors
   % This function ALWAYS generates a report, even if tests failed

   reports_dir = fullfile('.', 'Reports');
   if ~exist(reports_dir, 'dir')
      mkdir(reports_dir);
   end

   report_file = fullfile(reports_dir, 'Software_Integration_Test_Report.html');

   try
      fid = fopen(report_file, 'w');
      if fid == -1
         warning('[Suite##Warn] Cannot create report file: %s', report_file);
         return
      end

      % Calculate summary statistics
      num_tests = numel(results);
      if num_tests > 0
         num_passed = sum(strcmp({results.status}, 'PASSED'));
         num_failed = sum(strcmp({results.status}, 'FAILED'));
      else
         num_passed = 0;
         num_failed = 0;
      end

      % Get version info
      smc_version = 'N/A';
      usc_version = 'N/A';
      if ~isempty(smc_cal) && isfield(smc_cal, 'Version')
         try
            smc_version = sprintf('%d.%d.%d', ...
                                  smc_cal.Version.Workbook.major.VALUE, ...
                                  smc_cal.Version.Workbook.minor.VALUE, ...
                                  smc_cal.Version.Workbook.patch.VALUE);
         catch
         end
      end
      if ~isempty(usc_cal) && isfield(usc_cal, 'Version')
         try
            usc_version = sprintf('%d.%d.%d', ...
                                  usc_cal.Version.major.VALUE, ...
                                  usc_cal.Version.minor.VALUE, ...
                                  usc_cal.Version.patch.VALUE);
         catch
         end
      end

      % Determine overall status color
      if num_tests == 0
         status_color = '#FFA500';  % Orange - no tests
         status_text = 'NO TESTS EXECUTED';
      elseif num_failed == 0
         status_color = '#28a745';  % Green
         status_text = 'ALL TESTS PASSED';
      elseif num_passed == 0
         status_color = '#dc3545';  % Red
         status_text = 'ALL TESTS FAILED';
      else
         status_color = '#ffc107';  % Yellow
         status_text = 'PARTIAL PASS';
      end

      % Write HTML header
      fprintf(fid, '<!DOCTYPE html>\n');
      fprintf(fid, '<html lang="en">\n<head>\n');
      fprintf(fid, '<meta charset="UTF-8">\n');
      fprintf(fid, '<meta name="viewport" content="width=device-width, initial-scale=1.0">\n');
      fprintf(fid, '<title>Integration Test Suite Report</title>\n');
      fprintf(fid, '<style>\n');
      fprintf(fid, 'body { font-family: Arial, sans-serif; margin: 20px; background: #f5f5f5; }\n');
      fprintf(fid, '.container { max-width: 1200px; margin: 0 auto; background: white; padding: 20px; border-radius: 8px; box-shadow: 0 2px 4px rgba(0,0,0,0.1); }\n');
      fprintf(fid, 'h1 { color: #333; border-bottom: 2px solid #007bff; padding-bottom: 10px; }\n');
      fprintf(fid, 'h2 { color: #555; margin-top: 30px; }\n');
      fprintf(fid, '.summary-box { display: flex; gap: 20px; flex-wrap: wrap; margin: 20px 0; }\n');
      fprintf(fid, '.stat-card { padding: 15px 25px; border-radius: 8px; color: white; min-width: 150px; text-align: center; }\n');
      fprintf(fid, '.stat-card h3 { margin: 0; font-size: 2em; }\n');
      fprintf(fid, '.stat-card p { margin: 5px 0 0 0; opacity: 0.9; }\n');
      fprintf(fid, '.passed { background: #28a745; }\n');
      fprintf(fid, '.failed { background: #dc3545; }\n');
      fprintf(fid, '.total { background: #007bff; }\n');
      fprintf(fid, '.info { background: #17a2b8; }\n');
      fprintf(fid, 'table { width: 100%%; border-collapse: collapse; margin: 20px 0; }\n');
      fprintf(fid, 'th, td { padding: 12px; text-align: left; border-bottom: 1px solid #ddd; }\n');
      fprintf(fid, 'th { background: #f8f9fa; font-weight: bold; }\n');
      fprintf(fid, 'tr:hover { background: #f5f5f5; }\n');
      fprintf(fid, '.status-pass { color: #28a745; font-weight: bold; }\n');
      fprintf(fid, '.status-fail { color: #dc3545; font-weight: bold; }\n');
      fprintf(fid, '.error-box { background: #fff3cd; border: 1px solid #ffc107; border-radius: 4px; padding: 10px; margin: 5px 0; font-family: monospace; font-size: 0.9em; white-space: pre-wrap; word-wrap: break-word; }\n');
      fprintf(fid, '.config-table td:first-child { font-weight: bold; width: 200px; }\n');
      fprintf(fid, '.timestamp { color: #666; font-size: 0.9em; }\n');
      fprintf(fid, '.status-banner { padding: 15px; border-radius: 8px; color: white; text-align: center; font-size: 1.2em; font-weight: bold; margin: 20px 0; }\n');
      fprintf(fid, '</style>\n</head>\n<body>\n');

      % Container
      fprintf(fid, '<div class="container">\n');

      % Title and timestamp
      fprintf(fid, '<h1>Integration Test Suite Report</h1>\n');
      fprintf(fid, '<p class="timestamp">Generated: %s</p>\n', datestr(now, 'yyyy-mm-dd HH:MM:SS'));

      % Status banner
      fprintf(fid, '<div class="status-banner" style="background: %s;">%s</div>\n', status_color, status_text);

      % Summary cards
      fprintf(fid, '<div class="summary-box">\n');
      fprintf(fid, '<div class="stat-card total"><h3>%d</h3><p>Total Tests</p></div>\n', num_tests);
      fprintf(fid, '<div class="stat-card passed"><h3>%d</h3><p>Passed</p></div>\n', num_passed);
      fprintf(fid, '<div class="stat-card failed"><h3>%d</h3><p>Failed</p></div>\n', num_failed);
      fprintf(fid, '<div class="stat-card info"><h3>%.1f</h3><p>Minutes</p></div>\n', elapsed_minutes);
      fprintf(fid, '</div>\n');

      % Configuration section
      fprintf(fid, '<h2>Configuration</h2>\n');
      fprintf(fid, '<table class="config-table">\n');
      fprintf(fid, '<tr><td>Sensor Type</td><td>%s</td></tr>\n', suiteConfig.sensor_type);
      fprintf(fid, '<tr><td>SMC Version</td><td>%s</td></tr>\n', smc_version);
      fprintf(fid, '<tr><td>USC Version</td><td>%s</td></tr>\n', usc_version);
      fprintf(fid, '<tr><td>Offline Injection Mode</td><td>%d</td></tr>\n', suiteConfig.offline_mode_inject);
      fprintf(fid, '<tr><td>Max Retries</td><td>%d</td></tr>\n', suiteConfig.max_retries);
      fprintf(fid, '<tr><td>Debug Mode</td><td>%s</td></tr>\n', bool_to_str(suiteConfig.debug_mode));
      fprintf(fid, '</table>\n');

      % Test Results section
      fprintf(fid, '<h2>Test Results</h2>\n');

      if num_tests == 0
         fprintf(fid, '<p style="color: #666; font-style: italic;">No test cases were executed.</p>\n');
      else
         fprintf(fid, '<table>\n');
         fprintf(fid, '<tr><th>#</th><th>Test Case</th><th>Status</th><th>Attempts</th><th>Error Details</th></tr>\n');

         for i = 1:num_tests
            if strcmp(results(i).status, 'PASSED')
               status_class = 'status-pass';
               status_icon = '✓';
            else
               status_class = 'status-fail';
               status_icon = '✗';
            end

            % Error display
            if ~isempty(results(i).error)
               error_html = sprintf('<div class="error-box">%s</div>', escape_html(results(i).error));
            else
               error_html = '-';
            end

            fprintf(fid, '<tr>\n');
            fprintf(fid, '<td>%d</td>\n', i);
            fprintf(fid, '<td>%s</td>\n', escape_html(results(i).name));
            fprintf(fid, '<td class="%s">%s %s</td>\n', status_class, status_icon, results(i).status);
            fprintf(fid, '<td>%d / %d</td>\n', results(i).attempts, suiteConfig.max_retries);
            fprintf(fid, '<td>%s</td>\n', error_html);
            fprintf(fid, '</tr>\n');
         end

         fprintf(fid, '</table>\n');
      end

      % Failed tests summary (if any)
      if num_failed > 0
         fprintf(fid, '<h2>Failed Test Details</h2>\n');
         for i = 1:num_tests
            if strcmp(results(i).status, 'FAILED')
               fprintf(fid, '<h3 style="color: #dc3545;">%s</h3>\n', escape_html(results(i).name));
               fprintf(fid, '<p><strong>Attempts:</strong> %d</p>\n', results(i).attempts);
               if ~isempty(results(i).error)
                  fprintf(fid, '<div class="error-box">%s</div>\n', escape_html(results(i).error));
               end
            end
         end
      end

      % Footer
      fprintf(fid, '<hr style="margin-top: 40px;">\n');
      fprintf(fid, '<p class="timestamp">Report generated by RunTest_Suite_IT.m</p>\n');

      fprintf(fid, '</div>\n</body>\n</html>\n');
      fclose(fid);

      fprintf('[Suite##Info] HTML report generated: %s\n', report_file);

   catch ME
      warning('[Suite##Warn] Failed to generate HTML report: %s');
      if exist('fid', 'var') && fid ~= -1
         try
            fclose(fid);
         catch
         end
      end
   end
end

function str = bool_to_str(val)
   % Convert boolean to Yes/No string
   if val
      str = 'Yes';
   else
      str = 'No';
   end
end

function escaped = escape_html(str)
   % Escape HTML special characters
   if isempty(str)
      escaped = '';
      return
   end
   escaped = strrep(str, '&', '&amp;');
   escaped = strrep(escaped, '<', '&lt;');
   escaped = strrep(escaped, '>', '&gt;');
   escaped = strrep(escaped, '"', '&quot;');
   escaped = strrep(escaped, '''', '&#39;');
   % Convert newlines to <br>
   escaped = strrep(escaped, char(10), '<br>');
   escaped = strrep(escaped, char(13), '');
end

function generate_consolidated_report(smc_cal, usc_cal)
   % Generate consolidated report from all test results
   if isempty(smc_cal) || isempty(usc_cal)
      warning('[Suite##Warn] Cannot generate consolidated report: calibration data not loaded.');
      return
   end

   try
      SMC = smc_cal.SMC;
      USC = usc_cal;
      getConslReport(SMC, USC);
      fprintf('[Suite##Info] Consolidated report generated successfully.\n');
   catch ME
      warning('[Suite##Warn] Failed to generate consolidated report: %s');
   end
end
