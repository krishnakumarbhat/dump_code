% This function checks for build outputs existence, if doesn't, builds for
% the corresponding variant type selected.
% Inputs - build_flag, clean_build, variant_settings
% Output - status
function Check_Build_Status(build_flag, clean_build, variant_settings)

   outputRoot = fullfile('..', '..', '..', '..', 'bazel-bin', 'outputs', 'PHY_1Gb');
   variantOutputPath = fullfile(outputRoot, variant_settings.variant_config);

   ApplicationPath = fullfile(variantOutputPath, 'app.s19');
   R52_ELF_Path = fullfile(variantOutputPath, 'r52App.elf');
   BBE32_ELF_Path = fullfile(variantOutputPath, 'bbe32App.elf');

   if isfile(ApplicationPath) && isfile(R52_ELF_Path) && isfile(BBE32_ELF_Path)
      fprintf("Build outputs exist for %s (%s) \n", variant_settings.variant, variant_settings.variant_config);
   else
      fprintf("Build outputs doesn't exist for %s (%s) \n", variant_settings.variant, variant_settings.variant_config);
      build_flag = 1;
   end

   % Perform build if requested
   if build_flag
      fprintf('Please wait, building %s binaries for %s\n', lower(variant_settings.variant), variant_settings.variant_config);
      bazel_path = '..\\..\\..\\..\\bazelisk.exe';

      if clean_build
         bazel_clean_cmd = sprintf('%s clean', bazel_path);
         system(bazel_clean_cmd, '-echo');
      end

      cmdString = sprintf('%s build //:gen8 --config=%s %s --disable_int_wdg --//:static_register_safety_enabled=false --enable_debug', ...
                          bazel_path, ...
                          lower(variant_settings.variant), ...
                          variant_settings.build_args);
      status = system(cmdString, '-echo');
      if status ~= 0
         error('%s build failed for %s! - exiting', lower(variant_settings.variant), variant_settings.variant_config);
      else
         fprintf('Finished building successfully! \n');
      end
   end
end
