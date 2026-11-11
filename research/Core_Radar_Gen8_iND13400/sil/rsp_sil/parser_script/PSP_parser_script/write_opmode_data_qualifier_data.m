function write_opmode_data_qualifier_data(toi_data, op_data, sil_bin_file_path)

   if ~isempty(sil_bin_file_path)
      file_name = fullfile(sil_bin_file_path, "operation_mode_and_data_qualifier.bin");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   % operation_mode_and_data_qualifier.bin
   % uint8_t OperationMode_System;
   % uint8_t data_qualifier;
   % uint8_t data_qualifier_ds;

   % read operation mode from header stream
   fwrite(fileID, op_data.OperationMode_System(1), "uint8");

   % read data_qualifier from toi stream
   fwrite(fileID, toi_data.data_qualifier(1), "uint8");

   fclose(fileID);

end
