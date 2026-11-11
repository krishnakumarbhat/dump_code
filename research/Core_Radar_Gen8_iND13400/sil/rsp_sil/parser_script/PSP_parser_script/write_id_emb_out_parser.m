function write_id_emb_out_parser(id_stream_data, frame_idx, exe_dir)

   % creates a file named "rc_out_emb.txt" in the same path as this .mat
   % file

   if ~isempty(exe_dir)
      file_name = fullfile(exe_dir, "id_out_emb.txt");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   for k = frame_idx:frame_idx
      % read  dra_core_data
      fprintf(fileID, "version major: %f\n", id_stream_data.id_version_major(k));
      fprintf(fileID, "version minor: %f\n", id_stream_data.id_version_minor(k));
      fprintf(fileID, "nf_min_db_value: %f\n", id_stream_data.nf_min_db_value(k));
      fprintf(fileID, "nf_max_db_value: %f\n", id_stream_data.nf_max_db_value(k));
      fprintf(fileID, "nf_mean_db_value: %f\n", id_stream_data.nf_mean_db_value(k));
      fprintf(fileID, "normalised_nf: %f\n", id_stream_data.normalised_nf(k));
      fprintf(fileID, "interference_health: %f\n", id_stream_data.interference_health(k));
      fprintf(fileID, "interference_level: %f\n", id_stream_data.interference_level(k));
      fprintf(fileID, "interference_detected: %f\n", id_stream_data.interference_detected(k));
      fprintf(fileID, "interference_data_discard: %f\n", id_stream_data.interference_data_discard(k));

   end % end of for loop used for index count

   fclose(fileID);
