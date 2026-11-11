function det_csv_compare(varargin)
   % det_csv_compare(csvfile, matfile) - read AF det data from csvfile and compare to a tv_anglefinding matfile

   %% parse args
   argc = length(varargin);
   if argc > 0
      csvfile = varargin{1};
   else
      csvfile = "af_det.csv";
   end
   if argc > 1
      matfile = varargin{2};
   else
      matfile = "tv_anglefinding.mat";
   end

   %% read inputs
   % load csv file
   csvdata = read_csv_file(csvfile);
   % load matfile and look for tv_anglefinding.AF_det
   load(matfile);
   matdata = tv_anglefinding.AF_det;
   % convert rdd_idx to 0-based system
   matdata.rdd_idx = matdata.rdd_idx - 1;
   matdata.rdd_idx(matdata.rdd_idx < 0) = 0;
   % compute target_selected_post_stage_n
   matdata.pass_sen_thld_idx = find(matdata.below_af_sen_thld == 0);
   matdata.target_selected_post_stage_1 = sum(matdata.tgt_sel_sen_thld_pass_post_stage(matdata.pass_sen_thld_idx) == 1);
   matdata.target_selected_post_stage_2 = sum(matdata.tgt_sel_sen_thld_pass_post_stage(matdata.pass_sen_thld_idx) == 2);
   matdata.target_selected_post_stage_3 = sum(matdata.tgt_sel_sen_thld_pass_post_stage(matdata.pass_sen_thld_idx) == 3);
   matdata.target_selected_post_stage_4 = sum(matdata.tgt_sel_sen_thld_pass_post_stage(matdata.pass_sen_thld_idx) == 4);
   matdata.target_selected_post_stage_5 = sum(matdata.tgt_sel_sen_thld_pass_post_stage(matdata.pass_sen_thld_idx) == 5);

   %% perform comparison and output summary
   fprintf("Summary:\n");
   fprintf("         CSV\tMAT\n");
   fprintf("num det: %3d\t%3d\n", csvdata.num_AF_det(1), matdata.num_AF_det(1));
   fprintf("num s1 : %3d\t%3d\n", csvdata.target_selected_post_stage_1(1), matdata.target_selected_post_stage_1(1));
   fprintf("num s2 : %3d\t%3d\n", csvdata.target_selected_post_stage_2(1), matdata.target_selected_post_stage_2(1));
   fprintf("num s3 : %3d\t%3d\n", csvdata.target_selected_post_stage_3(1), matdata.target_selected_post_stage_3(1));
   fprintf("num s4 : %3d\t%3d\n", csvdata.target_selected_post_stage_4(1), matdata.target_selected_post_stage_4(1));
   fprintf("num s4 : %3d\t%3d\n", csvdata.target_selected_post_stage_5(1), matdata.target_selected_post_stage_5(1));
   fprintf("\n");
   fprintf("Matching:\n");
   fprintf("                   Match\t First  \t  Worst  \t   Worst\n");
   fprintf("                   Count\tMismatch\tMatch Idx\tMatch Delta\n");
   fprintf("rdd_idx          : ");
   print_match_stats(csvdata.rdd_idx, matdata.rdd_idx, .1);
   fprintf("ran              : ");
   print_match_stats(csvdata.ran, matdata.ran, 1e-5);
   fprintf("vel              : ");
   print_match_stats(csvdata.vel, matdata.vel, 1e-5);
   fprintf("pow              : ");
   print_match_stats(csvdata.pow, matdata.pow, 1e-5);
   fprintf("snr              : ");
   print_match_stats(csvdata.snr, matdata.snr, 1e-5);
   fprintf("theta            : ");
   print_match_stats(csvdata.theta, matdata.theta, 1e-5);
   fprintf("phi              : ");
   print_match_stats(csvdata.phi, matdata.phi, 1e-4);
   fprintf("spec_res         : ");
   print_match_stats(csvdata.spec_res, matdata.spec_res, 1e-4);
   fprintf("az_conf          : ");
   print_match_stats(csvdata.az_conf, matdata.az_conf, .1);
   fprintf("el_conf          : ");
   print_match_stats(csvdata.el_conf, matdata.el_conf, .1);
   if isfield(matdata, "Az_AF_type")
      fprintf("az_af_type       : ");
      print_match_stats(csvdata.Az_AF_type, matdata.Az_AF_type, .1);
   end
   if isfield(matdata, "El_AF_type")
      fprintf("el_af_type       : ");
      print_match_stats(csvdata.El_AF_type, matdata.El_AF_type, .1);
   end
   fprintf("f_single_target  : ");
   print_match_stats(csvdata.f_single_target, matdata.f_single_target, .1);
   if isfield(matdata, "f_superres_target")
      fprintf("f_superres_target: ");
      print_match_stats(csvdata.f_superres_target, matdata.f_superres_target, .1);
   end
   fprintf("f_bistatic       : ");
   print_match_stats(csvdata.f_bistatic, matdata.f_bistatic, .1);

end % end function

function print_match_stats(a, b, tol)
   % print_match_stats(a, b, tol) - compare arrays a and b and print the match
   % count and first mismatch index (using tol as the tolerance for
   % comparison)

   la = length(a);
   lb = length(b);
   sz = max(la, lb);
   a = reshape(a, [], 1);
   a = [a; zeros(sz - la, 1)];
   b = reshape(b, [], 1);
   b = [b; zeros(sz - lb, 1)];
   delta = (abs(a - b));
   [max_delta, max_index] = max(delta);
   fail_tol = (abs(a - b) < tol);
   fprintf("%5d", sum(fail_tol));
   fail_index = find(fail_tol == 0);
   if fail_index
      fprintf("\t %5d", fail_index(1));
   else
      fprintf("\t     ");
   end
   fprintf("   \t  %5d", max_index);
   fprintf("  \t%g\n", max_delta);

end % end function
