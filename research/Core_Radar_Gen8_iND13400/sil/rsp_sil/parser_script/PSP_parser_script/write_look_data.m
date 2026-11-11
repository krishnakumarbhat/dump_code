function write_look_data(look_data, frame_idx, sil_bin_file_path)

   if ~isempty(sil_bin_file_path)
      file_name = fullfile(sil_bin_file_path, "look_data_input.bin");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   for k = frame_idx:frame_idx
      % fixed_rbin_res = look_data.rbin_res(k, :) .* 2^16;
      % fwrite(fileID, fixed_rbin_res, 'uint32');
      % fixed_dbin_res = look_data.dbin_res(k, :) .* 2^21;
      % fwrite(fileID, fixed_dbin_res, 'int32');
      % fixed_vua = look_data.vua(k, :) .* 2^21;
      % fwrite(fileID, fixed_vua, 'int32');
      fwrite(fileID, look_data.start_dwell_nanosec(k, :), 'uint32');
      fwrite(fileID, look_data.start_dwell_sec(k, :), 'uint32');
      fwrite(fileID, look_data.end_dwell_nanosec(k, :), 'uint32');
      fwrite(fileID, look_data.end_dwell_sec(k, :), 'uint32');
      fwrite(fileID, look_data.mid_dwell_nanosec(k, :), 'uint32');
      fwrite(fileID, look_data.mid_dwell_sec(k, :), 'uint32');
      fwrite(fileID, look_data.look_id(k, :), 'uint16');
      fwrite(fileID, look_data.scan_type(k, :), 'uint16');
      % fwrite(fileID, look_data.dwell_type(k, :), 'uint16');
      % fwrite(fileID, 0, 'uint16');
      % fixed_range_coverage = look_data.range_coverage(k, :) .* 2^7;
      % fwrite(fileID, fixed_range_coverage, 'uint16');
      % fixed_doppler_coverage = look_data.doppler_coverage(k, :) .* 2^8;
      % fwrite(fileID, fixed_doppler_coverage, 'int16');
      fwrite(fileID, look_data.look_index(k, :), 'uint16');
      fwrite(fileID, look_data.scan_index(k, :), 'uint16');
      % fwrite(fileID, look_data.rest_count(k, :), 'uint16');
      % fwrite(fileID, 0, 'uint16');
      % fwrite(fileID, look_data.start_dwell_status(k, :), 'uint8');
      fwrite(fileID, look_data.end_dwell_status(k, :), 'uint8');
      fwrite(fileID, look_data.mid_dwell_status(k, :), 'uint8');
      fwrite(fileID, 0, 'uint8');
   end

   fclose(fileID);

end
