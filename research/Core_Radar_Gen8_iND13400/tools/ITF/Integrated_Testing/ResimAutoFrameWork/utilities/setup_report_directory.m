function setup_report_directory(path_to_report_directory)
   % SETUP_REPORT_DIRECTORY  Remove stale reports and create a fresh directory structure.
   report_dir = fullfile(path_to_report_directory, 'Reports');
   if exist(report_dir, 'dir') == 7
      system(sprintf('rmdir /S /Q "%s"', report_dir));
   end
   mkdir(report_dir);
   mkdir(fullfile(report_dir, 'Testcases'));
end
