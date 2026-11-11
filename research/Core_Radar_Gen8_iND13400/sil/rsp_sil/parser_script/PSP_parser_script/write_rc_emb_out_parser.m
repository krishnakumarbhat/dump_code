function write_rc_emb_out_parser(rc_data, exe_dir)

   % creates a file named "rc_out_emb.txt" in the same path as this .mat
   % file

   if ~isempty(exe_dir)
      file_name = fullfile(exe_dir, "rc_out_emb.txt");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   % read version
   fprintf(fileID, "Radar Capability log Outputs");
   fprintf(fileID, "\n\n");
   fprintf(fileID, "RC_Version_Output_Stream:\n");
   fprintf(fileID, "rc_ver_major: %d\n", rc_data.version.rc_ver_major(1));
   fprintf(fileID, "rc_ver_minor: %d\n", rc_data.version.rc_ver_minor(1));
   fprintf(fileID, "rc_ver_patch: %d\n\n", rc_data.version.rc_ver_patch(1));

   % read  fault_table
   fprintf(fileID, "fault_table:\n");
   fprintf(fileID, "Blockage_Algo_Error: %d\n", rc_data.fault_table.Blockage_Algo_Error(1));
   fprintf(fileID, "Damping_Algo_Error: %d\n", rc_data.fault_table.Damping_Algo_Error(1));
   fprintf(fileID, "Range_Algo_Error: %d\n", rc_data.fault_table.Range_Algo_Error(1));
   fprintf(fileID, "PBD_Monitor_Algo_Error: %d\n\n", rc_data.fault_table.PBD_Monitor_Algo_Error(1));

   % read  fault_injection
   fprintf(fileID, "fault_injection:\n");
   fprintf(fileID, "fault_type: %d\n", rc_data.fault_injection.fault_type(1));
   fprintf(fileID, "run_counter: %d\n", rc_data.fault_injection.run_counter(1));
   fprintf(fileID, "f_fault_injected: %d\n", rc_data.fault_injection.f_fault_injected(1));
   fprintf(fileID, "f_active: %d\n\n", rc_data.fault_injection.f_active(1));

   % read  diag
   fprintf(fileID, "diag:\n");
   fprintf(fileID, "elapsed_time_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.elapsed_time_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.elapsed_time_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.elapsed_time_input_fault.f_status_ok(1));
   fprintf(fileID, "det_look_index_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.det_look_index_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.det_look_index_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.det_look_index_input_fault.f_status_ok(1));
   fprintf(fileID, "rdd_look_index_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.rdd_look_index_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.rdd_look_index_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.rdd_look_index_input_fault.f_status_ok(1));
   fprintf(fileID, "veh_index_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.veh_index_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.veh_index_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.veh_index_input_fault.f_status_ok(1));
   fprintf(fileID, "id_look_index_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.id_look_index_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.id_look_index_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.id_look_index_input_fault.f_status_ok(1));
   fprintf(fileID, "smc_data_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.smc_data_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.smc_data_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.smc_data_input_fault.f_status_ok(1));
   fprintf(fileID, "usc_data_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.usc_data_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.usc_data_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.usc_data_input_fault.f_status_ok(1));
   fprintf(fileID, "mmic_temperature_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.mmic_temperature_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.mmic_temperature_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.mmic_temperature_input_fault.f_status_ok(1));
   fprintf(fileID, "dyn_align_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.dyn_align_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.dyn_align_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.dyn_align_input_fault.f_status_ok(1));
   fprintf(fileID, "rf_health_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.rf_health_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.rf_health_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.rf_health_input_fault.f_status_ok(1));
   fprintf(fileID, "det_rdd_matching_index_input_fault: \n");
   fprintf(fileID, "total_fault_cnt: %d\n", rc_data.diag.det_rdd_matching_index_input_fault.total_fault_cnt(1));
   fprintf(fileID, "cur_fault_cnt: %d\n", rc_data.diag.det_rdd_matching_index_input_fault.cur_fault_cnt(1));
   fprintf(fileID, "f_status_ok: %d\n", rc_data.diag.det_rdd_matching_index_input_fault.f_status_ok(1));

   % read  diag
   fprintf(fileID, "\nBlockage: \n");
   for i = 1:3
      fprintf(fileID, "partial blockage[%d]: \npercentage:  %d\nProbability:  %d\nValue:  %d\n", i - 1, rc_data.blockage.partial_blockage.percentage(1, i), rc_data.blockage.partial_blockage.probability(1, i), rc_data.blockage.partial_blockage.value(1, i));
   end
   fprintf(fileID, "blockage: \n");
   fprintf(fileID, "percentage:  %d\n", rc_data.blockage.blockage.percentage(1));
   fprintf(fileID, "Probability:  %d\n", rc_data.blockage.blockage.probability(1));
   fprintf(fileID, "Value:  %d\n", rc_data.blockage.blockage.value(1));
   fprintf(fileID, "blockage_th: ");
   for i = 1:4
      fprintf(fileID, "%d", rc_data.blockage.blockage_th(1, i));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nblockage_status: %d\n", rc_data.blockage.blockage_active(1));
   fprintf(fileID, "blockage_active: %d\n\n", rc_data.blockage.blockage_status(1));

   % read  dm
   fprintf(fileID, "dm:\n");
   for i = 1:3
      fprintf(fileID, "partial_Damping[%d]:\ncurrent_dB: %d\nstd_dB:%d\n", i - 1, int32(rc_data.dm.partial_damping.current_dB(1, i)), int32(rc_data.dm.partial_damping.std_dB(1, i)));
   end
   fprintf(fileID, "damping: \n");
   fprintf(fileID, "current_dB: %d\n", rc_data.dm.damping.current_dB(1));
   fprintf(fileID, "std_dB: %d\n", int32(rc_data.dm.damping.std_dB(1)));
   fprintf(fileID, "damping_dB_meas: %d\n", int32(rc_data.dm.damping_dB_meas(1)));
   fprintf(fileID, "dm_status: %d\n", rc_data.dm.dm_status(1));
   fprintf(fileID, "dm_active: %d\n", rc_data.dm.dm_active(1));

   % read  fsc
   fprintf(fileID, "\nfsc: \n");
   fprintf(fileID, "det_range_hist: ");
   for i = 1:3
      fprintf(fileID, "%d", rc_data.fsc.det_range_hist(1, i));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\ntraveled_time_ms: %d\n", rc_data.fsc.traveled_time_ms(1));
   fprintf(fileID, "traveled_dist_m: %d\n", rc_data.fsc.traveled_dist_m(1));
   fprintf(fileID, "run_status: %d\n", rc_data.fsc.run_status(1));
   fprintf(fileID, "fault_status: %d\n\n", rc_data.fsc.fault_status(1));

   % read  re
   fprintf(fileID, "re: \n");
   fprintf(fileID, "max_det_range_car: ");
   for i = 1:3
      fprintf(fileID, "%d", int32(rc_data.re.max_det_range_car(1, i)));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nmax_det_range_motorbike: ");
   for i = 1:3
      fprintf(fileID, "%d", int32(rc_data.re.max_det_range_motorbike(1, i)));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nmax_det_range_pedestrian: ");
   for i = 1:3
      fprintf(fileID, "%d", int32(rc_data.re.max_det_range_pedestrian(1, i)));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nre_status: %d\n", rc_data.re.re_status(1));
   fprintf(fileID, "re_active: %d\n\n", rc_data.re.re_active(1));

   % read  se
   fprintf(fileID, "se: \n");
   fprintf(fileID, "f_interference_present: %f\n", rc_data.se.f_interference_present(1));
   fprintf(fileID, "f_amp_spike_present: %f\n", rc_data.se.f_amp_spike_present(1));
   fprintf(fileID, "f_amp_drop_present: %f\n", rc_data.se.f_amp_drop_present(1));
   fprintf(fileID, "f_num_rdd1_dets_spike: %f\n", rc_data.se.f_num_rdd1_dets_spike(1));
   fprintf(fileID, "f_problematic_data: %f\n", rc_data.se.f_problematic_data(1));
   fprintf(fileID, "f_many_dets_high_MCS: %f\n", rc_data.se.f_many_dets_high_MCS(1));
   fprintf(fileID, "f_close_target_issue: %f\n", rc_data.se.f_close_target_issue(1));
   fprintf(fileID, "f_close_target_high_MNR: %f\n", rc_data.se.f_close_target_high_MNR(1));
   fprintf(fileID, "f_very_close_target_issue: %f\n", rc_data.se.f_very_close_target_issue(1));
   fprintf(fileID, "f_very_close_target_strongest: %f\n", rc_data.se.f_very_close_target_strongest(1));
   fprintf(fileID, "f_very_close_target_high_MNR: %f\n", rc_data.se.f_very_close_target_high_MNR(1));
   fprintf(fileID, "f_very_low_MNR_all: %f\n", rc_data.se.f_very_low_MNR_all(1));
   fprintf(fileID, "f_very_high_MNR_all: %f\n", rc_data.se.f_very_high_MNR_all(1));
   fprintf(fileID, "filt_min_chirp_scaling: %f\n", rc_data.se.filt_min_chirp_scaling(1));
   fprintf(fileID, "mean_mnr: ");
   for i = 1:3
      fprintf(fileID, "%f", rc_data.se.mean_mnr_region(1, i));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nmax_mnr_region: ");
   for i = 1:3
      fprintf(fileID, "%f", rc_data.se.max_mnr_region(1, i));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nmax_mnr: %f\n", rc_data.se.max_mnr_all(1));
   fprintf(fileID, "max_range_m: %f\n", rc_data.se.max_range_m(1));
   fprintf(fileID, "num_valid_rbins: ");
   for i = 1:3
      fprintf(fileID, "%d", int32(rc_data.se.num_valid_rbins(1, i)));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nmin_rbin_used: ");
   for i = 1:3
      fprintf(fileID, "%d", int32(rc_data.se.min_rbin_used(1, i)));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nmax_rbin_used: ");
   for i = 1:3
      fprintf(fileID, "%d", int32(rc_data.se.max_rbin_used(1, i)));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\nnum_st_dets: %d\n", rc_data.se.num_st_dets(1));
   fprintf(fileID, "invalid_input_cnt: %d\n", rc_data.se.invalid_input_cnt(1));
   fprintf(fileID, "se_status: %d\n", rc_data.se.se_status(1));
   fprintf(fileID, "se_active: %d\n", rc_data.se.se_active(1));
   fprintf(fileID, "f_low_MCS: %d\n", rc_data.se.f_low_MCS(1));
   fprintf(fileID, "f_high_MCS: %d\n", rc_data.se.f_high_MCS(1));
   fprintf(fileID, "f_many_dets: %d\n", rc_data.se.f_many_dets(1));
   fprintf(fileID, "f_few_dets: %d\n", rc_data.se.f_few_dets(1));
   fprintf(fileID, "f_low_MNR_all: %d\n", rc_data.se.f_low_MNR_all(1));
   fprintf(fileID, "f_high_MNR_all: %d\n", rc_data.se.f_high_MNR_all(1));
   fprintf(fileID, "f_low_damping: %d\n", rc_data.se.f_low_damping(1));
   fprintf(fileID, "f_high_damping: %d\n\n", rc_data.se.f_high_damping(1));

   % read  pbd
   fprintf(fileID, "pbd: ");
   for i = 1:3
      fprintf(fileID, "\naz_sector[%d]: \n", i - 1);
      fprintf(fileID, "filt_residue_hist_norm: ");
      for j = 1:6
         fprintf(fileID, "%f", rc_data.pbd.az_sector.filt_residue_hist_norm(1, i, j));
         fprintf(fileID, " ");

      end
      fprintf(fileID, "\nresidue_hist: ");
      for j = 1:6
         fprintf(fileID, "%d", int32(rc_data.pbd.az_sector.residue_hist(1, i, j)));
         fprintf(fileID, " ");

      end
      fprintf(fileID, "\nnum_dets: %d", rc_data.pbd.az_sector.num_dets(1, i));
      fprintf(fileID, "\nside_lobe_level: %d", rc_data.pbd.az_sector.side_lobe_level(1, i));

   end
   fprintf(fileID, "\npbd_status: %d", rc_data.pbd.status(1));
   fprintf(fileID, "\npbd_active: %d\n\n", rc_data.pbd.pbd_active(1));

   fprintf(fileID, "az_fov_begin_rad: ");
   for i = 1:3
      fprintf(fileID, "%f", rc_data.az_fov_begin_rad(1, i));
      fprintf(fileID, " ");
   end

   fprintf(fileID, "\n\naz_fov_end_rad: ");
   for i = 1:3
      fprintf(fileID, "%f", rc_data.az_fov_end_rad(1, i));
      fprintf(fileID, " ");
   end
   fprintf(fileID, "\n\nhost_speed_m_s: %f", rc_data.host_speed_m_s(1));
   fprintf(fileID, "\n\nhost_yawrate_rad_s: %f", rc_data.host_yawrate_rad_s(1));
   fprintf(fileID, "\n\nnormalized_nf_dB: %f", rc_data.normalized_nf_dB(1));
   fprintf(fileID, "\n\nrange_coverage_m: %d", rc_data.range_coverage_m(1));
   fprintf(fileID, "\n\ndamping_adjustment_dB: %d", rc_data.damping_adjustment_dB(1));
   fprintf(fileID, "\n\ntimestamp_ms: %d", rc_data.timestamp_ms(1));
   fprintf(fileID, "\n\nrc_index: %d", rc_data.rc_index(1));
   fprintf(fileID, "\n\nlook_index: %d", rc_data.look_index(1));
   fprintf(fileID, "\n\navg_mmic_onchip_temp: %d", rc_data.avg_mmic_onchip_temp(1));
   fprintf(fileID, "\n\nlook_type: %d", rc_data.look_type(1));
   fprintf(fileID, "\n\nsensitivity_level: %d", rc_data.sensitivity_level(1));
   fprintf(fileID, "\n\nRFHealthPercentage: %d", rc_data.RFHealthPercentage(1));
   fprintf(fileID, "\n\nRFMalFunctionFlag: %d", rc_data.RFMalFunctionFlag(1));
   fprintf(fileID, "\n\nRFHealth_EnableStatusFlag: %d", rc_data.RFHealth_EnableStatusFlag(1));
   fprintf(fileID, "\n\ninterference_data_discard: %d", rc_data.interference_data_discard(1));
   fprintf(fileID, "\n\nf_ignore_fsc_status: %d", rc_data.f_ignore_fsc_status(1));
   fprintf(fileID, "\n\nrc_active: %d", rc_data.rc_active(1));

   fclose(fileID);

   % =========================================================================
   % FILE REVISION HISTORY - To be filled by the project team
   % -------------------------------------------------------------------------
   %
   % REVISION         AID               SUMMARY OF CHANGES
   % -------------------------------------------------------------------------
   %      1        AthulNath RS      First version
   %
   % -------------------------------------------------------------------------
   % =========================================================================

   % END OF FILE ------------------------------------------------------------%
