%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% RunTest_Integration is the main function to run "Radar Core SW Integration Test Automation (RCITA)"
% starting Look-Processing until Angle Finding
%
% DESCRIPTION
% Following modules will run sequentially:-
% [1]TestVector_Parser() --> Cycle [N]
%                         [2]Radar Simulator() --> [3]ExecSpec() --> [4]MEX-ExecSpec() -->
%                                                            [5] Trace32_Remote()<-->Radar ECU()
%                                          -->[6] WaitforECU_Output()-->
%                                          -->[7]ComparisonReportGen(Real,Required)
%                     --> Repeat Cycle [N] , N = 1.. TestVector::Size()
%
%        X =  RunTest_Integration('TestProfile.csv')
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function varargout = RunTest_Integration(varargin)
   %% GLOBAL DECLARATIONS
   global sensor_type cals_path itr integTesting af_Testing test_case_name look_string BB_name ...
      Count_Look_Processing Count_CFAR Count_First_Pass Count_Second_Pass Count_Angle_Finding InjectRoadData sitp_run ...
      sw_id WorkbookPath LookName debug_mode wfStr
   % Suite mode globals - set by RunTest_Suite_IT
   global suite_mode_active suite_config

   %% Determine execution mode: standalone vs suite
   is_suite_mode = ~isempty(suite_mode_active) && suite_mode_active;
   called_with_args = nargin > 0;

   % Clean paths only for fresh standalone runs
   if called_with_args && ~is_suite_mode
      rmpath(genpath(pwd));
      clc;
   end

   %% INITIALIZATIONS
   % Waveform type configuration
   % wfStr = '4DDM_2CDM_8_VaryingBPM';
   wfStr = '4DDM_2QDDM_16';
   % wfStr = '4DDM_2CDM_8';

   %% Build default runConfig
   runConfig = struct( ...
                      'run_single_look', 0, ...
                      'selected_look', 1, ...
                      'debug_mode', 0, ...
                      'offline_mode_inject', 2, ...
                      'MexEmbed_Mode', 0, ...
                      'Super_Lite_ITF', 0, ...
                      'Lite_ITF_Mode', 0, ...
                      'SpecMex_Only', 0, ...
                      'save_ADC_data', 1, ...
                      'build_flag', 0, ...
                      'clean_build', 0, ...
                      'testvec_file', '', ...
                      'sensor_type', 'FLR8', ...
                      'build_profile', 'satellite_can');

   %% Configure based on execution mode
   if is_suite_mode
      % Suite mode: use config from suite, skip dialog
      runConfig = apply_suite_config(runConfig, suite_config);
      fprintf('[Integration##Info] Running in Suite mode (dialog disabled).\n');
   elseif called_with_args
      % Called with arguments but not from suite: use global sensor_type if set
      if ~isempty(sensor_type)
         runConfig.sensor_type = sensor_type;
      end
      % Dialog disabled when called with arguments
   else
      % Standalone interactive mode: show dialog
      runConfig = Flag_Dialog(true, runConfig);
      if isempty(runConfig)
         fprintf('RadarCore_Itg_AutoInfo, Integration setup cancelled by user.\n');
         return
      end
   end

   %% Extract configuration values
   run_single_look = runConfig.run_single_look;
   selected_look = runConfig.selected_look;
   debug_mode = runConfig.debug_mode;
   offline_mode_inject = runConfig.offline_mode_inject;
   MexEmbed_Mode = runConfig.MexEmbed_Mode;
   Super_Lite_ITF = runConfig.Super_Lite_ITF;
   save_ADC_data = runConfig.save_ADC_data;
   build_flag = runConfig.build_flag;
   clean_build = runConfig.clean_build;
   Lite_ITF_Mode = runConfig.Lite_ITF_Mode;
   SpecMex_Only = runConfig.SpecMex_Only;
   sensor_type = runConfig.sensor_type;
   selected_testvec_file = strtrim(runConfig.testvec_file);

   % Spec vs Mex only mode compares Spec and Mex outputs and skips the
   % embedded/sensor path entirely. Ensure it is not combined with other
   % mutually exclusive execution modes.
   if SpecMex_Only
      MexEmbed_Mode = 0;
      Super_Lite_ITF = 0;
      Lite_ITF_Mode = 0;
   end

   variant_settings = resolve_itf_variant_settings(sensor_type, runConfig.build_profile);
   variant = variant_settings.variant;
   variant_config = variant_settings.variant_config;

   if Lite_ITF_Mode
      offline_mode_inject = 0;
   end

   if sitp_run == 1
      global test_case_result sitp_color str_label
      test_case_result = {};
      str_label = {};
      sitp_color = {};
   end

   % offline_mode_inject used to enable injection mode selection OR data collection of normal ADC input
   %     0 - enable ITF data collection of normal ADC input from MARS
   %     1 - enable radar datacube injection
   %     2 - enable ADC injection

   % This must be in sync with the available ITF configurations in ipc_command.h
   if offline_mode_inject == 0
      offline_mode_flag = hex2dec('33333333');
   elseif offline_mode_inject == 1
      offline_mode_flag = hex2dec('22222222');
   elseif offline_mode_inject == 2
      offline_mode_flag = hex2dec('11111111');
   else
      error('Invalid offline mode selected.');
   end

   %% Initialize test counters (unified for both modes)
   if ~called_with_args || ~is_suite_mode
      % Reset counters only for standalone or first suite call
      integTesting = 1;
      Count_Look_Processing = 0;
      Count_CFAR = 0;
      Count_First_Pass = 0;
      Count_Second_Pass = 0;
      Count_Angle_Finding = 0;
   end
   InjectRoadData = 0;
   cals_path = '../../../software/common/calibrations';

   %% Setup workbook path
   WorkbookPath = fullfile('.', 'workbook', sensor_type);
   addpath(WorkbookPath);

   %% Check build and download calibrations (skip if suite already did this)
   if ~is_suite_mode
      if ~debug_mode && ~SpecMex_Only
         Check_Build_Status(build_flag, clean_build, variant_settings);
      end
      download_smc_usc(WorkbookPath, variant_settings);
   end
   t1 = tic;

   %% PATHS
   currentDIR = pwd;
   addpath([currentDIR, '\..\..\Integrated_Testing\Trace32_Online_injection\Trace32\Utility']);
   addpath([currentDIR, '\..\..\Integrated_Testing\Trace32_Online_injection\Trace32']);
   addpath([currentDIR, '\..\..\Integrated_Testing\ResimAutoFrameWork\utilities']);
   addpath('C:\T32\demo\api\capi\src');
   addpath('C:\T32\demo\api\capi\dll');
   SpecsPath = '../../ExecutableSpecs/ADVRADAR_Gen7_Exec_Spec';
   LookName = {'Look_A', 'Look_B', 'Look_C', 'Look_D'};

   WorkbookPath = ['./workbook/' sensor_type];
   addpath(WorkbookPath);
   smc_info = dir(fullfile([WorkbookPath, '\smc_cal*.mat']));
   load(smc_info.name);
   SMC_Version = smc_info.name;
   SMC_Version = erase(SMC_Version, 'smc_cal_');
   SMC_Version = erase(SMC_Version, '.mat');
   platform_id = smc_cal.Configuration.BB_Configuration.K_PLATFORM_VARIANT.VALUE;
   usc_info = dir(fullfile([WorkbookPath, '\usc_cal*.mat']));
   load(usc_info.name);
   USC_Version = usc_info.name;
   USC_Version = erase(USC_Version, 'usc_cal_');
   USC_Version = erase(USC_Version, '.mat');
   af_Testing = 0; % set to 1 to just run AF
   BB_flag = 0; % set to 1 for running specific building block test cases
   af_comparison = 0; % to compare AF outputs, set to 1. Else, set to 0.
   enable_matching = ~MexEmbed_Mode && ~Super_Lite_ITF && ~SpecMex_Only;
   %% Step-1, Extract the TestProfile for possible look cyles available in the input %%
   if Lite_ITF_Mode
      startCycle = 1;
      endCycle = 1;
      testcase_dir_name = 'LiteITF_Mode';
      test_case_name = 'LiteITF_Mode';
      createDir_FinalReports(testcase_dir_name); % Creating directory for the final reports
      debug_mode = 1;
      status = addpaths(integTesting);
   elseif InjectRoadData % note that this portion of code will work only with exec spec package
      [ADC_data_folder, IQ_data_file, startCycle, endCycle, SMC, USC, z4, brr_flag] = getRoadDataInfo(SMC, USC);
   elseif MexEmbed_Mode
      startCycle = 1;
      endCycle = 4;
      testcase_dir_name = 'MexEmbed_Mode';
      test_case_name = 'MexEmbed_Mode';
      createDir_FinalReports(testcase_dir_name); % Creating directory for the final reports
   else
      if ~isempty(selected_testvec_file)
         [selected_folder, selected_name, selected_ext] = fileparts(selected_testvec_file);
         FileName = [selected_name selected_ext];
         [FileName, testVecFileName, testVecData, cycles, startCycle, endCycle, testcase_dir_name] = getTestProfile(2, {selected_testvec_file, FileName}, BB_flag);
      else
         [FileName, testVecFileName, testVecData, cycles, startCycle, endCycle, testcase_dir_name] = getTestProfile(nargin, varargin, BB_flag);
      end
      createDir_FinalReports(testcase_dir_name); % Creating directory for the final reports
   end
   if sitp_run == 1
      test_case_result = {test_case_name, '', '', '', ''};
      sitp_color = {'', '', '', '', ''};
      str_label = {'', '', '', ''};
   end
   if af_comparison
      tot_BBs =  6; % Look_Processing, RDD_FP, RDD_SP, CFAR, BW_Depd_tholds and Angle Finding
   else
      tot_BBs = 5; % Look_Processing, RDD_FP, RDD_SP, CFAR, BW_Depd_tholds
   end
   if run_single_look
      num_BBs_all_cycles = tot_BBs; % only single look
   else
      num_BBs_all_cycles = tot_BBs * (endCycle - startCycle + 1);
   end
   tc_fail_cnt = zeros(1, num_BBs_all_cycles);
   tot_report_string = cell(1, num_BBs_all_cycles);
   test_string =  cell(1, num_BBs_all_cycles);
   tot_fail_cnt = zeros(1, num_BBs_all_cycles);
   tot_pass_cnt = zeros(1, num_BBs_all_cycles);
   tot_report_cnt = 1; %  Initializing a total report counter

   %% Replace USC PTP in flash output with USC PTP from current ITF run with unitary calmat.
   if ~Lite_ITF_Mode && ~SpecMex_Only && ~Super_Lite_ITF && ~debug_mode
      flash_output_dir = fullfile('..', '..', '..', '..', 'bazel-bin', 'outputs', 'PHY_1Gb', variant_config);
      itf_usc_ptp = dir(fullfile(pwd, 'usc_cal*.ptp'));
      if isempty(itf_usc_ptp)
         warning('No ITF USC PTP found in %s. Existing flash USC PTP will be used.', pwd);
      else
         [~, usc_idx] = max([itf_usc_ptp.datenum]);
         src_usc_ptp = fullfile(itf_usc_ptp(usc_idx).folder, itf_usc_ptp(usc_idx).name);
         dst_usc_ptp = fullfile(flash_output_dir, 'usc_cal.ptp');
         copyfile(src_usc_ptp, dst_usc_ptp, 'f');
         fprintf('Updated flash USC PTP: %s -> %s\n', src_usc_ptp, dst_usc_ptp);
      end
   end

   %% Power on sensor once before processing all looks
   if ~debug_mode && ~SpecMex_Only
      try
         status = power_supply('on');
      catch
         warning("Automated power on failed, power on manually");
      end
   end

   %% Initialize t32lib handle (will be set on first iteration)
   t32lib = [];

   %% Processing
   for itr = startCycle:endCycle
      if ~run_single_look || (run_single_look && selected_look == itr)
         close all;
         if ~Lite_ITF_Mode && ~MexEmbed_Mode
            %%% Construct Timeslice%%%%%%
            TarLookIdx = eq(testVecData(:, 2), itr);
            TimeSlice{1}.ntarg_sim = sum(TarLookIdx);
            TimeSlice{1}.x_targ = testVecData(TarLookIdx, 5);
            TimeSlice{1}.y_targ = testVecData(TarLookIdx, 6);
            TimeSlice{1}.z_targ = testVecData(TarLookIdx, 7);

            TimeSlice{1}.force_x_velocity = testVecData(TarLookIdx, 8);
            TimeSlice{1}.force_y_velocity = testVecData(TarLookIdx, 9);
            TimeSlice{1}.rcs = testVecData(TarLookIdx, 10);
            if length(testVecData) == 12
               TimeSlice{1}.snr = testVecData(TarLookIdx, 11);
               TimeSlice{1}.noise_fact = testVecData(TarLookIdx, 12);
            else
               TimeSlice{1}.snr = repelem(0, sum(TarLookIdx));
               TimeSlice{1}.noise_fact = 1;
            end
            TimeSlice{1}.phi_targ = 2 * pi * rand(1, TimeSlice{1}.ntarg_sim);
            TestID = extractBetween(test_case_name, 'RCT_0', '_');
            TestID = cell2mat(TestID);
            TestID = str2num(TestID);
            TimeSlice{1}.TestID = TestID;
            if InjectRoadData
               testcase_dir_name = IQ_data_file(startCycle).name;
               testcase_dir_name(end - 3:end) = [];
               createDir_FinalReports(testcase_dir_name); % Creating directory for the final reports

               % Extract ADC data of a look/scan
               iq_file_name = IQ_data_file(itr).name;
               [ADC_data_cube, look_type, bin_res, scan_index] = Load_IQ_DataCubeOnline(ADC_data_folder, iq_file_name, WorkbookPath);
               temperature = get_temperature(brr_flag, scan_index, z4, SMC);
            else

               %% Step-2, Invoke RadarSimulator to get the ADC buffer
               if itr == endCycle
                  testVecblock = cycles(itr):size(testVecData, 1);
               else
                  testVecblock = cycles(itr):cycles(itr + 1) - 1;
               end
               data_file_in = testVecData(testVecblock, 2:end);
               look_type = data_file_in(1, 1);

               if save_ADC_data == 1
                  addpath('..\..\ExecutableSpecs\ADVRADAR_Gen7_Exec_Spec\GUI');
                  addpath('..\..\ExecutableSpecs\ADVRADAR_Gen7_Exec_Spec\Sig_Proc\');
                  IF_final = Simulator_standalone(sensor_type, cals_path, itr, WorkbookPath, SpecsPath, TimeSlice, test_case_name, save_ADC_data);
                  I_counts1 = IF_final.(LookName{look_type}).Data;
                  % I_counts1 = IF_final.IQdata;
                  ADC_data_cube = I_counts1;
                  test_case_name = FileName;
                  test_case_name(end - 3:end) = [];
                  data_folder = ['.\BB_Test_Cases\', sensor_type, '\', test_case_name];
                  if ~exist(data_folder, 'dir')
                     mkdir(data_folder);
                  end
                  save([data_folder, '\IQ_data_', LookName{look_type}, '.mat'], '-struct', 'IF_final');

               else
                  data_folder = ['.\BB_Test_Cases\', sensor_type, '\', test_case_name];
                  IF_final = load([data_folder, '\IQ_data_', LookName{look_type}, '.mat']);
                  I_counts1 = IF_final.(LookName{look_type}).Data;
                  ADC_data_cube = I_counts1;
               end
               temperature = 50;
            end
         else
            look_type = itr;
         end

         look_string = LookName{look_type};

         %% Start sensor: flash on first look, power cycle only on subsequent looks
         if ~SpecMex_Only
            if itr == startCycle || run_single_look
               % First look: initialize T32 and flash the sensor
               [t32lib, status] = start_gen8_sensor(sensor_type, look_type, debug_mode, 0, [], Lite_ITF_Mode);
               if 0 ~= status
                  error('Sensor initialization failed. Cannot proceed with test.');
               end
               % Read SMC and USC version of the Embedded software
               [status, Embed_smc_val, Embed_usc_val] = read_smc_usc_embed(t32lib);

               if 0 ~= status
                  error('SMC USC Read failed. Cannot proceed with test.');
               end

               fprintf("Embed smc value  = %d_%d_%d_%d \n", Embed_smc_val.sec_comp, Embed_smc_val.platform, Embed_smc_val.customer, Embed_smc_val.version);
               fprintf("Embed usc value  = %d_%d_%d_%d \n", Embed_usc_val.sec_comp, Embed_usc_val.platform, Embed_usc_val.customer, Embed_usc_val.version);
            else
               % Subsequent looks: power cycle only, reuse t32lib
               [t32lib, status] = start_gen8_sensor(sensor_type, look_type, debug_mode, 0, t32lib, Lite_ITF_Mode);
               if 0 ~= status
                  error('Power cycle failed for look %d. Skipping this look.', itr);
               end
            end
         end

         if Super_Lite_ITF
            set_cal_matrix(t32lib, 'true'); % Only in super lite mode, set cal matrix - with standalone mex run data only.
         end

         t2 = tic;

         if ~Lite_ITF_Mode && ~MexEmbed_Mode

            %% Step-4, Invoke Executive Spec and pass the ADC buffer
            fprintf('Spec executing..\n');
            current_bv = [];
            prev_bv_multi_look = [];
            addpath(genpath(SpecsPath));
            IntegTestParams.looktype = look_type;
            IntegTestParams.sensorType = sensor_type;
            IntegTestParams.fHWAAgnostic = 0;
            IntegTestParams.fHWAAgnostic_3DFFT = 1;
            IntegTestParams.HWAVersion = 0;
            Signal_Processing_hdls(WorkbookPath, data_folder, IntegTestParams);
            copyfile([pwd '\Executable_Specs\Data\SigProc_Data\' test_case_name '\IntegrationTesting'], [pwd '\Executable_Specs\Data']);
            rmdir([pwd '\Executable_Specs\Data\SigProc_Data'], 's');

            if (itr == startCycle || run_single_look) && ~SpecMex_Only
               % Read SMC and USC version of the Exec Spec
               [Execspec_smc_val, Execspec_usc_Val] = read_smc_usc_execspec(smc_cal, usc_cal);
               fprintf("Execspec SMC value = %d_%d_%d_%d\n", Execspec_smc_val.sec_comp, Execspec_smc_val.platform, Execspec_smc_val.customer, Execspec_smc_val.version);
               fprintf("Execspec USC value = %d_%d_%d_%d\n", Execspec_usc_Val.sec_comp, Execspec_usc_Val.platform, Execspec_usc_Val.customer, Execspec_usc_Val.version);

               % Compare SMC and USC version of the Embedded software and Exec Spec
               compare_smc_usc(Execspec_smc_val, Execspec_usc_Val, Embed_smc_val, Embed_usc_val);
            end

            %%% Create SPBB structures from Spec & Save the outputs
            [LookProc_spec_out] = spec_lookprocdata_collect(look_string);
            [BW_spec_out] = spec_BWdata_collect(look_string);
            [CFAR_spec_out] = spec_cfardata_collect(look_string);
            [FP_spec_out] = spec_Firstpassdata_collect(look_string);
            [SP_spec_out, Secondpass_spec_debug_signal] = spec_Secondpassdata_collect(look_string, FP_spec_out);
            spec_time_taken = toc(t2) / 60;
            fprintf("Time taken for spec execution is %.2f minutes.\n", spec_time_taken);
         else
            fprintf('Skipping Spec execution for look %d due to Mex-Embed comparison mode.\n', look_type);
            LookProc_spec_out = [];
            BW_spec_out = [];
            CFAR_spec_out = [];
            FP_spec_out = [];
            SP_spec_out = [];
            Secondpass_spec_debug_signal = [];
         end

         if ~Lite_ITF_Mode
            t3 = tic;
            %% Step-5, Invoke MEX Executable spec asynchronously and pass ADC buffer
            fprintf('Mex executing..\n');
            addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec');
            status = addpaths(integTesting);
            mkdir('Mex_Executable_Specs\Data');
            % Clear any stale variables from previous runs to prevent contamination
            evalin('base', 'clear RunTest_post_mipi_payload RunTest_rfft_ready RunTest_mipi_stats');
            % DataQueues for early payload publication
            postMipiQueue   = parallel.pool.DataQueue;   % post_mipi_adc_data
            MipiStatsQueue   = parallel.pool.DataQueue;   % mipi stats
            rfftReadyQueue  = parallel.pool.DataQueue;   % simple ready flag
            afterEach(postMipiQueue,  @(p) assignin('base', 'RunTest_post_mipi_payload', p));
            afterEach(MipiStatsQueue,  @(p) assignin('base', 'RunTest_mipi_stats', p));
            afterEach(rfftReadyQueue, @(p) assignin('base', 'RunTest_rfft_ready', p));
            % Launch MEX in background with queues
            if ~MexEmbed_Mode
               mexFuture = parfeval(@SCRIPT_Range_Doppler_Processing_B0, 0, look_type, 0, 0, ADC_data_cube, integTesting, smc_cal, usc_cal, postMipiQueue, rfftReadyQueue, MipiStatsQueue);
               fprintf('[Async##Info] MEX future started for look %d.\n', look_type);
            elseif MexEmbed_Mode && ~Super_Lite_ITF
               mexFuture = parfeval(@SCRIPT_Range_Doppler_Processing_B0, 0, look_type, 0, 0, [], 1, [], [], postMipiQueue, rfftReadyQueue, MipiStatsQueue);
               fprintf('[Async##Info] MEX future started for look %d.\n', look_type);
            elseif Super_Lite_ITF
               %% Do not execute MEX but just download the corresponding data set from the Jfrog for mex-embed comparison mode
               % download_mex_output(smc_cal, usc_cal, look_string, 'MexEmbed_Mode');
            else
               error('Invalid MexEmbed_Mode value');
            end
         end

         % Local state for gating
         postMipiPayload   = [];
         rfftMatReady      = false;
         MipiStatsQueue    = [];

         if ~Lite_ITF_Mode && MexEmbed_Mode

            %% Read SMC and USC version of the Mex Spec
            [Mexspec_smc_val, Mexspec_usc_val] = read_smc_usc_mexspec(smc_cal, usc_cal);
            fprintf("Mexspec smc value = %d_%d_%d_%d\n", Mexspec_smc_val.sec_comp, Mexspec_smc_val.platform, Mexspec_smc_val.customer, Mexspec_smc_val.version);
            fprintf("Mexspec usc value = %d_%d_%d_%d\n", Mexspec_usc_val.sec_comp, Mexspec_usc_val.platform, Mexspec_usc_val.customer, Mexspec_usc_val.version);

            %% Compare SMC and USC version of the Embedded software and Mex Spec
            compare_smc_usc(Mexspec_smc_val, Mexspec_usc_val, Embed_smc_val, Embed_usc_val);

         end
         if ~SpecMex_Only
            t4 = tic;

            %% Enable offline mode and set breakpoints
            [status, sw_id] = offline_mode_enable(t32lib, look_type, offline_mode_flag);

            if 0 ~= status
               error('Failed to enable offline mode. Cannot proceed with test.');
            end

            status = set_functional_breakpoints(t32lib, offline_mode_inject);

            if 0 ~= status
               error('Failed to set functional breakpoints. Cannot proceed with test.');
            end
            % Optimized injection handling: switch-case by mode, branch on dataset option
            switch offline_mode_inject
               case 1
                  if ~Super_Lite_ITF
                     % Wait for RFFT MAT ready flag and inject from MAT
                     fprintf('[Async##Info] Waiting for RFFT MAT ready..\n');
                     rfftTimeoutSec = 600; % 10 minutes
                     rfftMatReady = wait_for_mex_payload('RunTest_rfft_ready', rfftTimeoutSec);
                     if rfftMatReady
                        [status, compRfftWritten] = t32_rfft_datacube_injection(look_type, t32lib, smc_cal, Super_Lite_ITF);
                        if 0 ~= status
                           error('Rfft Data Cube injection failed.\n');
                        else
                           fprintf('[Async##Info] RFFT datacube injection complete.\n');
                        end
                     end
                  else
                     [status, compRfftWritten] = t32_rfft_datacube_injection(look_type, t32lib, smc_cal, Super_Lite_ITF);
                     if 0 ~= status
                        error('Rfft Data Cube injection failed.\n');
                     else
                        fprintf('RFFT datacube injection complete.\n');
                     end
                  end
               case 2
                  if ~Super_Lite_ITF
                     % Wait for post MIPI ADC payload from MEX before injection
                     fprintf('[Async##Info] Waiting for post MIPI ADC payload..\n');
                     injectionTimeoutSec = 300; % 5 minutes
                     postMipiPayload = wait_for_mex_payload('RunTest_post_mipi_payload', injectionTimeoutSec);
                     MipiStatsQueue = wait_for_mex_payload('RunTest_mipi_stats', injectionTimeoutSec);
                     if ~isempty(postMipiPayload) && ~isempty(MipiStatsQueue)
                        [status] = t32_adc_datacube_injection(look_type, t32lib, smc_cal, postMipiPayload, MipiStatsQueue, Super_Lite_ITF);
                        if 0 ~= status
                           error('ADC injection failed.\n');
                        else
                           fprintf('[Async##Info] ADC datacube injection complete.\n');
                        end
                     end
                  else
                     [status] = t32_adc_datacube_injection(look_type, t32lib, smc_cal, postMipiPayload, MipiStatsQueue, Super_Lite_ITF);
                     if 0 ~= status
                        error('ADC injection failed.\n');
                     else
                        fprintf('ADC datacube injection complete.\n');
                     end
                  end
               otherwise
                  % No injection for other modes
            end

            % Collect trace32 embed data for Range
            [LookProc_embed_out, LookProc_embed_debug_signal] = t32_LP_Range_data_collect(look_type, t32lib, smc_cal);

            % Collect trace32 embed Doppler, NCI and CI
            [status, LookProc_embed_out, LookProc_embed_debug_signal] = t32_LP_Doppler_data_collect(LookProc_embed_out, LookProc_embed_debug_signal, look_type, t32lib, smc_cal);

            % We should be at signal processing done state - so can do AF validation.
            if 0 ~= status
               error('Aborting data collection, BBE did not hit final breakpoint.\n');
            end
            % collect RDD data  - CFAR, BW-thresholds, First_pass & Second_Pass
            % Collect CFAR data
            [status, CFAR_embed_out, CFAR_embed_debug_signal] = t32_cfardata_collect(look_type, t32lib, smc_cal);

            % Collect BW Dependent thresholds Data
            [status, BW_embed_out] = t32_BWdata_collect(look_type, t32lib, smc_cal);

            % Collect FP Dependent thresholds Data
            [status, FP_embed_out, Firstpass_embed_debug_signal] = t32_FPdata_collect(look_type, t32lib, smc_cal, LookProc_embed_out, LookProc_embed_debug_signal);

            % Collect SP Dependent thresholds Data
            [status, SP_embed_out, Secondpass_embed_debug_signal] = t32_SPdata_collect(look_type, t32lib, smc_cal, FP_embed_out);

            if af_comparison
               % Collect trace32 embed data for AF modules
               [status, AF_embed_out] = t32_AFdata_collect(look_type, t32lib);
            end

            embed_time_taken = toc(t4) / 60;
            fprintf("Time taken for embedded execution is %.2f minutes.\n", embed_time_taken);
         else
            % SpecMex_Only: embedded/sensor path skipped, compare Spec vs Mex only.
            status = 0;
            LookProc_embed_out = [];
            LookProc_embed_debug_signal = [];
            CFAR_embed_out = [];
            CFAR_embed_debug_signal = [];
            BW_embed_out = [];
            FP_embed_out = [];
            Firstpass_embed_debug_signal = [];
            SP_embed_out = [];
            Secondpass_embed_debug_signal = [];
            AF_embed_out = [];
            if isempty(sw_id)
               sw_id = 0;
            end
            embed_time_taken = 0;
         end
         if ~Super_Lite_ITF && ~Lite_ITF_Mode
            % Ensure MEX is complete before collecting MEX outputs
            fprintf('[Async##Info] Waiting for MEX future completion before collecting outputs..\n');
            wait(mexFuture);
            copyfile([pwd '\current_state_dfft.mat'], [pwd '\Mex_Executable_Specs\Data']);
            delete('current_state_rfft.mat', 'current_state_dfft.mat');
         end
         %%% Updating var data structures
         addpath('.\..\Trace32_online_injection\Files\Variables_In_ITF_Reports');
         if ~Lite_ITF_Mode
            %%% Create SPBB structures from MEX & saved
            [LookProc_mex_out] = mex_lookprocdata_collect(look_string, Super_Lite_ITF);
            [CFAR_mex_out] = mex_cfardata_collect(look_string, Super_Lite_ITF);
            [BW_mex_out] = mex_BWdata_collect(look_string, Super_Lite_ITF);
            [FP_mex_out, Firstpass_mex_debug_signal] = mex_Firstpassdata_collect(look_string, Super_Lite_ITF);
            [SP_mex_out, Secondpass_mex_debug_signal] = mex_Secondpassdata_collect(look_string, FP_mex_out, Super_Lite_ITF);
            if af_comparison
               [AF_mex_out] = mex_AngleFindingdata_collect(look_string, Super_Lite_ITF);
            end
            mex_time_taken = toc(t3) / 60;
            fprintf("Time taken for Mex execution is %.2f minutes.\n", mex_time_taken);

            %%% Apply scaling for spec and mex output
            [BW_mex_out, CFAR_mex_out, FP_mex_out, SP_mex_out, LookProc_mex_out, ...
                LookProc_embed_out, CFAR_embed_out, BW_embed_out, FP_embed_out, SP_embed_out] = Scaling(BW_mex_out, CFAR_mex_out, FP_mex_out, SP_mex_out, LookProc_mex_out, ...
                                                                                                        LookProc_embed_out, CFAR_embed_out, BW_embed_out, FP_embed_out, SP_embed_out, ...
                                                                                                        Firstpass_mex_debug_signal, SpecMex_Only);

            %% Data Comparison
            % LookProcessing Comparison
            % Save figures of look processing Mex and Embedded output%%%%%
            [fail_count, pass_count] = LookProcOutput_compare(LookProc_spec_out, LookProc_mex_out, LookProc_embed_out, look_string, smc_cal);
            if fail_count == 0
               tc_fail_cnt(tot_report_cnt) = 0;
            else
               tc_fail_cnt(tot_report_cnt) = 1;
            end
            BB_version_Look_Proc = 'N/A';   % Label{1,4}; %Look proc BB repo label
            tot_fail_cnt(tot_report_cnt) = fail_count;
            tot_pass_cnt(tot_report_cnt) = pass_count;
            tot_report_string{tot_report_cnt} = [pwd, '/Look_Proc_Output_' look_string];
            test_string{tot_report_cnt} = 'Look_Processing';
            tot_report_cnt = tot_report_cnt + 1;

            %% BW threshold Comparison
            % Add measurement variable for sweep bw
            [BW_fields, BWThold_var_data] = AddMeasurementVariables_v1(BW_mex_out, 1, 1, 'BW_Thold.csv', 0, 0);

            writeTime = mex_time_taken;
            CFAR_flag = 0;
            path_to_report_directory = [pwd, '/BW_Output_' look_string];
            path_to_USC_data = [sensor_type, look_string];
            test_case_cnt = 1;
            testcase_runtime = mex_time_taken;
            test_name = 'Integration Test';
            testcase = 1;
            workbook = smc_cal.Version.Workbook.major.VALUE;
            BB_version_BW = 'N/A';

            [tc_fail_cnt(tot_report_cnt), ...
                tot_pass_cnt(tot_report_cnt), ...
                tot_fail_cnt(tot_report_cnt)] = DataCompare(BW_embed_out, ...
                                                            BW_mex_out, BW_spec_out, ...
                                                            path_to_report_directory, ...
                                                            path_to_USC_data, ...
                                                            test_case_cnt, ...
                                                            BWThold_var_data, ...
                                                            testcase_runtime, ...
                                                            test_name, ...
                                                            testcase, ...
                                                            CFAR_flag, ...
                                                            embed_time_taken, ...
                                                            1, ...
                                                            workbook, ...
                                                            USC_Version, ...
                                                            BB_version_BW);
            tot_report_string{tot_report_cnt} = path_to_report_directory;
            test_string{tot_report_cnt} = 'BW_thold';
            tot_report_cnt = tot_report_cnt + 1;
            %% CFAR Comparison
            % Add measurement variable for cfar
            [CFAR_fields, CFAR_var_data] = AddMeasurementVariables_v1(CFAR_mex_out, 1, 1, 'CFAR.csv', 0, 0);

            writeTime = mex_time_taken;
            CFAR_flag = 0;
            path_to_report_directory = [pwd, '/CFAR_Output_' look_string];
            path_to_USC_data = [sensor_type, look_string];
            test_case_cnt = 1;
            testcase_runtime = mex_time_taken;
            test_name = 'Integration Test';
            testcase = 1;
            workbook = smc_cal.Version.Workbook.major.VALUE;
            BB_version_cfar = 'N/A';

            [tc_fail_cnt(tot_report_cnt), ...
                tot_pass_cnt(tot_report_cnt), ...
                tot_fail_cnt(tot_report_cnt)] = DataCompare(CFAR_embed_out, ...
                                                            CFAR_mex_out, CFAR_spec_out, ...
                                                            path_to_report_directory, ...
                                                            path_to_USC_data, ...
                                                            test_case_cnt, ...
                                                            CFAR_var_data, ...
                                                            testcase_runtime, ...
                                                            test_name, ...
                                                            testcase, ...
                                                            CFAR_flag, ...
                                                            embed_time_taken, ...
                                                            1, ...
                                                            workbook, ...
                                                            USC_Version, ...
                                                            BB_version_cfar);
            tot_report_string{tot_report_cnt} = path_to_report_directory;
            test_string{tot_report_cnt} = 'CFAR';
            tot_report_cnt = tot_report_cnt + 1;

            %% Firstpass comparison
            % This will bring the common structure elements
            [FP_spec_out, FP_mex_out] = match_detect(FP_spec_out, FP_mex_out, 'First_Pass', enable_matching);
            [FP_spec_out, FP_embed_out] = match_detect(FP_spec_out, FP_embed_out, 'First_Pass', enable_matching);
            [FP_mex_out, FP_embed_out] = match_detect(FP_mex_out, FP_embed_out, 'First_Pass', enable_matching);

            % Add measurement variable for first pass
            [Firstpass_fields, Firstpass_var_data] = AddMeasurementVariables_v1(FP_mex_out, 1, 1, 'First_Pass.csv', 0, 0);

            writeTime = mex_time_taken;
            CFAR_flag = 0;
            path_to_report_directory = [pwd, '/FP_Output_' look_string];
            path_to_USC_data = [sensor_type, look_string];
            test_case_cnt = 1;
            testcase_runtime = mex_time_taken;
            test_name = 'Integration Test';
            testcase = 1;
            workbook = smc_cal.Version.Workbook.major.VALUE;
            BB_version_Firstpass = 'N/A';

            [tc_fail_cnt(tot_report_cnt), ...
                tot_pass_cnt(tot_report_cnt), ...
                tot_fail_cnt(tot_report_cnt)] = DataCompare(FP_embed_out, ...
                                                            FP_mex_out, FP_spec_out, ...
                                                            path_to_report_directory, ...
                                                            path_to_USC_data, ...
                                                            test_case_cnt, ...
                                                            Firstpass_var_data, ...
                                                            testcase_runtime, ...
                                                            test_name, ...
                                                            testcase, ...
                                                            CFAR_flag, ...
                                                            embed_time_taken, ...
                                                            1, ...
                                                            workbook, ...
                                                            USC_Version, ...
                                                            BB_version_Firstpass);
            tot_report_string{tot_report_cnt} = path_to_report_directory;
            test_string{tot_report_cnt} = 'First_pass';
            tot_report_cnt = tot_report_cnt + 1;

            %% Secondpass comparison
            % This will bring the common structure elements
            [SP_spec_out, SP_mex_out, Secondpass_spec_debug_signal, Secondpass_mex_debug_signal] = match_detect(SP_spec_out, SP_mex_out, 'Second_Pass', enable_matching, Secondpass_spec_debug_signal, Secondpass_mex_debug_signal);
            [SP_spec_out, SP_embed_out, Secondpass_spec_debug_signal, Secondpass_embed_debug_signal] = match_detect(SP_spec_out, SP_embed_out, 'Second_Pass', enable_matching, Secondpass_spec_debug_signal, Secondpass_embed_debug_signal);
            [SP_mex_out, SP_embed_out, Secondpass_mex_debug_signal, Secondpass_embed_debug_signal] = match_detect(SP_mex_out, SP_embed_out, 'Second_Pass', enable_matching, Secondpass_mex_debug_signal, Secondpass_embed_debug_signal);

            % Add measurement variable for second pass
            [Secondpass_fields, Secondpass_var_data] = AddMeasurementVariables_v1(SP_mex_out, 1, 1, 'Second_Pass.csv', 0, 0);

            % Second pass comparison
            writeTime = mex_time_taken;
            CFAR_flag = 0;
            path_to_report_directory = [pwd, '/Secondpass_Output_' look_string];
            path_to_USC_data = [sensor_type, look_string];
            test_case_cnt = 1;
            testcase_runtime = mex_time_taken;
            test_name = 'Integration Test';
            testcase = 1;
            workbook = smc_cal.Version.Workbook.major.VALUE;
            BB_version_Secondpass = 'N/A';
            [tc_fail_cnt(tot_report_cnt), ...
                tot_pass_cnt(tot_report_cnt), ...
                tot_fail_cnt(tot_report_cnt)] = DataCompare(SP_embed_out, ...
                                                            SP_mex_out, SP_spec_out, ...
                                                            path_to_report_directory, ...
                                                            path_to_USC_data, ...
                                                            test_case_cnt, ...
                                                            Secondpass_var_data, ...
                                                            testcase_runtime, ...
                                                            test_name, ...
                                                            testcase, ...
                                                            CFAR_flag, ...
                                                            embed_time_taken, ...
                                                            1, ...
                                                            workbook, ...
                                                            USC_Version, ...
                                                            BB_version_Secondpass);
            tot_report_string{tot_report_cnt} = path_to_report_directory;
            test_string{tot_report_cnt} = 'Secondpass';
            tot_report_cnt = tot_report_cnt + 1;

            %% AngleFinding comparison
            if af_comparison
               % Add measurement variable for Angle Finding
               [Anglefinding_fields, Anglefinding_var_data] = AddMeasurementVariables_v1(AF_mex_out, 1, 1, 'Angle_Finding.csv', 0, 0);

               % Angle Finding comparison
               writeTime = mex_time_taken;
               CFAR_flag = 0;
               path_to_report_directory = [pwd, '/Anglefinding_Output_' look_string];
               path_to_USC_data = [sensor_type, look_string];
               test_case_cnt = 1;
               testcase_runtime = mex_time_taken;
               test_name = 'Integration Test';
               testcase = 1;
               workbook = smc_cal.Version.Workbook.major.VALUE;
               BB_version_Anglefinding = 'N/A';
               [tc_fail_cnt(tot_report_cnt), ...
                  tot_pass_cnt(tot_report_cnt), ...
                  tot_fail_cnt(tot_report_cnt)] = DataCompare(AF_embed_out, ...
                                                              AF_mex_out, AF_spec_out, ...
                                                              path_to_report_directory, ...
                                                              path_to_USC_data, ...
                                                              test_case_cnt, ...
                                                              Anglefinding_var_data, ...
                                                              testcase_runtime, ...
                                                              test_name, ...
                                                              testcase, ...
                                                              CFAR_flag, ...
                                                              embed_time_taken, ...
                                                              1, ...
                                                              workbook, ...
                                                              USC_Version, ...
                                                              BB_version_Anglefinding);
               tot_report_string{tot_report_cnt} = path_to_report_directory;
               test_string{tot_report_cnt} = 'Anglefinding';
               tot_report_cnt = tot_report_cnt + 1;
            end
         end
         %% Step-8, Invoke Save Result from Embedded
         % Save final outputs grouped by execution mode flag
         mkdir(['./Reports/' testcase_dir_name '/Final_Outputs/Final_Outputs_' look_string]);
         output_dir = ['./Reports/' testcase_dir_name '/Final_Outputs/Final_Outputs_' look_string];

         if SpecMex_Only
            % Spec vs Mex only mode: save Spec and Mex outputs
            save([output_dir '/lookproc_outputs.mat'], 'LookProc_spec_out', 'LookProc_mex_out');
            save([output_dir '/cfar_outputs.mat'], 'CFAR_spec_out', 'CFAR_mex_out');
            save([output_dir '/bwthold_outputs.mat'], 'BW_spec_out', 'BW_mex_out');
            save([output_dir '/firstpass_outputs.mat'], 'FP_spec_out', 'FP_mex_out', 'Firstpass_mex_debug_signal');
            save([output_dir '/secondpass_outputs.mat'], 'SP_spec_out', 'SP_mex_out', 'Secondpass_mex_debug_signal');
            if af_comparison
               save([output_dir '/anglefinding_outputs.mat'], 'AF_spec_out', 'AF_mex_out');
            end

         elseif ~isempty(LookProc_spec_out)
            % Three-way mode: save Spec, Mex, and Embed outputs
            save([output_dir '/lookproc_outputs.mat'], 'LookProc_embed_out', 'LookProc_spec_out', 'LookProc_mex_out', 'LookProc_embed_debug_signal');
            save([output_dir '/cfar_outputs.mat'], 'CFAR_embed_out', 'CFAR_spec_out', 'CFAR_mex_out', 'CFAR_embed_debug_signal');
            save([output_dir '/bwthold_outputs.mat'], 'BW_embed_out', 'BW_spec_out', 'BW_mex_out');
            save([output_dir '/firstpass_outputs.mat'], 'FP_embed_out', 'FP_spec_out', 'FP_mex_out', 'Firstpass_embed_debug_signal', 'Firstpass_mex_debug_signal');
            save([output_dir '/secondpass_outputs.mat'], 'SP_embed_out', 'SP_spec_out', 'SP_mex_out', 'Secondpass_spec_debug_signal', 'Secondpass_mex_debug_signal', 'Secondpass_embed_debug_signal');
            if af_comparison
               save([output_dir '/anglefinding_outputs.mat'], 'AF_embed_out', 'AF_mex_out', 'AF_spec_out');
            end

         elseif MexEmbed_Mode || Super_Lite_ITF
            % Mex-Embed mode: save Mex and Embed outputs
            save([output_dir '/lookproc_outputs.mat'], 'LookProc_embed_out', 'LookProc_mex_out', 'LookProc_embed_debug_signal');
            save([output_dir '/cfar_outputs.mat'], 'CFAR_embed_out', 'CFAR_mex_out', 'CFAR_embed_debug_signal');
            save([output_dir '/bwthold_outputs.mat'], 'BW_embed_out', 'BW_mex_out');
            save([output_dir '/firstpass_outputs.mat'], 'FP_embed_out', 'FP_mex_out', 'Firstpass_embed_debug_signal', 'Firstpass_mex_debug_signal');
            save([output_dir '/secondpass_outputs.mat'], 'SP_embed_out', 'SP_mex_out', 'Secondpass_mex_debug_signal', 'Secondpass_embed_debug_signal');
            if af_comparison
               save([output_dir '/anglefinding_outputs.mat'], 'AF_embed_out', 'AF_mex_out');
            end

         else
            % Standalone mode: save Embed outputs only
            save([output_dir '/lookproc_outputs.mat'], 'LookProc_embed_out', 'LookProc_embed_debug_signal');
            save([output_dir '/cfar_outputs.mat'], 'CFAR_embed_out', 'CFAR_embed_debug_signal');
            save([output_dir '/bwthold_outputs.mat'], 'BW_embed_out');
            save([output_dir '/firstpass_outputs.mat'], 'FP_embed_out', 'Firstpass_embed_debug_signal');
            save([output_dir '/secondpass_outputs.mat'], 'SP_embed_out', 'Secondpass_embed_debug_signal');
            if af_comparison
               save([output_dir '/anglefinding_outputs.mat'], 'AF_embed_out');
            end
         end
         if 0
            % Plot results for final outputs
            plot_results(look_string, sensor_type, testcase_dir_name);
         end
      else
         continue
      end
      if sitp_run == 1
         sitp_rep(tc_fail_cnt, tot_report_cnt, testcase_dir_name, smc_cal, sw_id, usc_cal, itr);
      end
   end
   time_taken = toc(t1) / 60;
   fprintf("Total time taken to complete the test is %.2f minutes.\n", time_taken);

   %% Create final reports directory and remove all temporary ones
   BB_version_Af = 'N/A';

   [overall_pass, ...
       overall_fail, ...
       testcase_pass, ...
       testcase_fail] = finalize_reports(tot_BBs, BB_flag, ...
                                         tc_fail_cnt, ...
                                         tot_pass_cnt, ...
                                         tot_fail_cnt, ...
                                         tot_report_cnt, ...
                                         tot_report_string, ...
                                         test_string, ...
                                         testcase_dir_name, ...
                                         SMC_Version, ...
                                         sw_id, ...
                                         USC_Version, ...
                                         BB_version_Af, platform_id, time_taken);
   fprintf('[RadarCore_Itg_Auto##Info], Successfully completed!!!\n');

   %% Cleanup: close T32 and power off (unless debug mode or suite will handle it)
   cleanup_test_resources(t32lib, debug_mode, is_suite_mode, SpecMex_Only);
end

%% ========================================================================
%  LOCAL HELPER FUNCTIONS
%% ========================================================================

function config = apply_suite_config(config, suite_config)
   % Apply suite configuration to run config
   if isempty(suite_config)
      return
   end

   % Map suite config fields to run config
   if isfield(suite_config, 'sensor_type')
      config.sensor_type = suite_config.sensor_type;
   end
   if isfield(suite_config, 'debug_mode')
      config.debug_mode = suite_config.debug_mode;
   end
   if isfield(suite_config, 'offline_mode_inject')
      config.offline_mode_inject = suite_config.offline_mode_inject;
   end
   if isfield(suite_config, 'build_flag')
      config.build_flag = suite_config.build_flag;
   end
   if isfield(suite_config, 'clean_build')
      config.clean_build = suite_config.clean_build;
   end
   if isfield(suite_config, 'SpecMex_Only')
      config.SpecMex_Only = suite_config.SpecMex_Only;
   end
end

function cleanup_test_resources(t32lib, debug_mode, is_suite_mode, SpecMex_Only)
   % Cleanup function to ensure resources are released
   % In suite mode, let the suite handle final cleanup
   if nargin < 4 || isempty(SpecMex_Only)
      SpecMex_Only = false;
   end

   if SpecMex_Only
      fprintf('[Integration##Info] Spec vs Mex only mode: no sensor/T32 cleanup required.\n');
      return
   end

   if debug_mode
      fprintf('[Integration##Info] Debug mode: keeping T32 and power on for inspection.\n');
      return
   end

   if is_suite_mode
      fprintf('[Integration##Info] Suite mode: deferring cleanup to suite orchestrator.\n');
      return
   end

   % Standalone mode: perform full cleanup
   try
      power_supply('off');
   catch
      warning('[Integration##Warn] Automated power off failed, power off manually.');
   end

   if ~isempty(t32lib)
      try
         t32_exit(t32lib, 0);
      catch
         warning('[Integration##Warn] T32 exit failed.');
      end
   end
end
