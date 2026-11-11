function write_vse_data(vse_data, frame_idx, sil_bin_file_path)

   if ~isempty(sil_bin_file_path)
      file_name = fullfile(sil_bin_file_path, "vse_stream_input.bin");
   else
      error("Path is empty!!");
   end

   fileID = fopen(file_name, 'w');

   for k = frame_idx:frame_idx
      % Veh_Raw_Data_T layout (matches updated Vse_Stream_T)
      fwrite(fileID, vse_data.system_time_secs(k, :), 'uint32');
      fwrite(fileID, vse_data.system_time_nanosecs(k, :), 'uint32');
      fwrite(fileID, vse_data.ego_vehicle_speed(k, :), 'float');
      fwrite(fileID, vse_data.ego_yaw_rate(k, :), 'float');
      fwrite(fileID, vse_data.steering_whl_angle(k, :), 'float');
      fwrite(fileID, vse_data.steering_whl_speed_deg_per_s(k, :), 'float');
      fwrite(fileID, vse_data.ego_lateral_accel(k, :), 'float');
      fwrite(fileID, vse_data.ego_longitudinal_accel(k, :), 'float');
      fwrite(fileID, vse_data.vehspeedcompfac_ka(k, :), 'float');
      fwrite(fileID, vse_data.K_Unused16_1(k, :), 'uint16');
      fwrite(fileID, vse_data.ego_vehicle_speed_qf(k, :), 'uint8');
      fwrite(fileID, vse_data.ego_yaw_rate_qf(k, :), 'uint8');
      fwrite(fileID, vse_data.vehicle_standstill(k, :), 'uint8');
      fwrite(fileID, vse_data.steering_whl_angle_qf(k, :), 'uint8');
      fwrite(fileID, vse_data.ego_lateral_accel_qf(k, :), 'uint8');
      fwrite(fileID, vse_data.ego_longitudinal_accel_qf(k, :), 'uint8');
      fwrite(fileID, vse_data.gear_pos(k, :), 'uint8');
      fwrite(fileID, vse_data.vehspeedcompfac_ka_qf(k, :), 'uint8');
      fwrite(fileID, vse_data.turn_signal(k, :), 'uint8');
      fwrite(fileID, vse_data.K_Unused8_1(k, :), 'uint8');
   end

   fclose(fileID);

end
