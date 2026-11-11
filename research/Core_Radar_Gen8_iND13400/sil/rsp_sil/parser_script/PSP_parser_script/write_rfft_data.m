function write_rfft_data(rdd_data, frame_idx, rfft_bin_file_path)

   if ~isempty(rfft_bin_file_path)
      file_name = fullfile(rfft_bin_file_path, "rfft_input.bin");
   else
      error("Path is empty!!");
   end
   fileID = fopen(file_name, 'w');

   % for k = frame_idx:frame_idx

   %   fwrite(fileID, rdd_data.rfft_data.interfered_samples_per_chirp(k, :), 'uint16');
   % end

   fclose(fileID);

end
