function write_stream_hdr_data(stream_data, frame_idx, sil_bin_file_path)

   if ~isempty(sil_bin_file_path)
      file_name = fullfile(sil_bin_file_path, "stream_hdr.bin");
   else
      error("Path is empty!!");
   end
   fileID = fopen(file_name, 'w');

   for k = frame_idx:frame_idx

      fwrite(fileID, stream_data.stream_hdr.size(k), 'uint32');
      fwrite(fileID, stream_data.stream_hdr.version(k), 'uint16');
      fwrite(fileID, stream_data.stream_hdr.checksum(k), 'uint16');
      fwrite(fileID, stream_data.stream_hdr.scan_index(k), 'uint16');
      fwrite(fileID, stream_data.stream_hdr.error_info(k), 'uint16');
      fwrite(fileID, stream_data.stream_hdr.module_time_ms(k), 'uint32');
   end

   fclose(fileID);

end
