% download_mex_output function basically downloads a file (current_state_af.mat)from JFrog link and saves it in a
% temp directory. and copy that .mat file from temp directory to mex_output folder.
% rough skeleton how folder structure looks like in jfrog
% -- SMC_v8_82_0_1
%  -- Look_A
%     -- TestCase1
%     -- TestCase2
%     -- TestCase3
%     -- TestCase4
%  -- Look_B
%     -- TestCase1
%     -- TestCase2
%     -- TestCase3
%     -- TestCase4
%  -- Look_C
%     -- TestCase1
%     -- TestCase2
%     -- TestCase3
%     -- TestCase4
%  -- Look_D
%     -- TestCase1
%     -- TestCase2
%     -- TestCase3
%     -- TestCase4
% Inputs:
%   - smc_cal
%   - usc_cal
%   - look_string
%   - TestCase

function download_mex_output(smc_cal, usc_cal, look_string, TestCase)

   %% Add path for mex_output download
   mex_output_path = ["mex_output"];
   addpath(mex_output_path);

   % mex_output download
   % If the mex_output folder with required mex_spec_output exist, add it to the path.
   % Else, mkdir and dowload mex_output
   current_state_af_file = strcat(mex_output_path, "\current_state_af.mat");
   if exist(current_state_af_file, 'file')
      load(current_state_af_file, 'smc', 'usc', 'lookNum');

      Mexspec_smc_val.sec_comp = smc.Version.Workbook.major.VALUE;
      Mexspec_smc_val.platform = smc.Version.Workbook.radar_variant_id.VALUE;
      Mexspec_smc_val.customer = smc.Version.Workbook.customer_id.VALUE;
      Mexspec_smc_val.version  = smc.Version.Workbook.minor.VALUE;
      [input_smc_val, input_usc_val] = read_smc_usc_mexspec(smc_cal, usc_cal);

      try
         compare_smc_usc(Mexspec_smc_val, input_usc_val, input_smc_val, input_usc_val);

         if (lookNum == 1 && strcmp(look_string, 'Look_A')) || ...
            (lookNum == 2 && strcmp(look_string, 'Look_B')) || ...
            (lookNum == 3 && strcmp(look_string, 'Look_C')) || ...
            (lookNum == 4 && strcmp(look_string, 'Look_D'))
            disp("Downloaded mex file matches expected look.");
         else
            error("Invalid mex file for current look.");
         end

      catch
         delete(current_state_af_file);
         rmdir(mex_output_path);
      end
   end

   if exist(current_state_af_file, 'file')
      addpath(genpath(mex_output_path));
      download_mex_output = 0;
   else
      mkdir(mex_output_path);
      download_mex_output = 1;
   end

   if download_mex_output

      %% Read SMC version and download corresponding output of the Mex Spec
      [Mexspec_smc_val] = read_smc_usc_mexspec(smc_cal, usc_cal);
      fprintf("Mexspec smc value = %d_%d_%d_%d\n", Mexspec_smc_val.sec_comp, Mexspec_smc_val.platform, Mexspec_smc_val.customer, Mexspec_smc_val.version);
      smc_version = sprintf("%d_%d_%d_%d", Mexspec_smc_val.sec_comp, Mexspec_smc_val.platform, Mexspec_smc_val.customer, Mexspec_smc_val.version);
      smc_version = strcat("SMC_v", smc_version);

      mex_outputr_url = strcat("https://jfrog.asux.aptiv.com/artifactory/core_radar-aptiv-00000000-gen8_ind13400-local/ITF_Exec_Mex_Outputs/CI_Disable/", smc_version, "/", string(look_string), "/", TestCase, "/current_state_af.mat");
      mex_out_DownloadPath = downloadFileFromJfrog(mex_outputr_url);

      addpath(genpath(mex_out_DownloadPath));

      copyfile(char(mex_out_DownloadPath), mex_output_path);
   end

end
