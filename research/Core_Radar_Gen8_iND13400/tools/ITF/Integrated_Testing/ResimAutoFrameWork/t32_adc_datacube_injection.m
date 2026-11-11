%
% API for writing ADC data to the MIPI wrapper ping/pong buffer
%
% Samples must be written into a temporary buffer, then the BBE triggered
% to copy the samples to the MIPI wrapper over the OCP interface.
%
% The writes to the OCP interface must be 64 bit writes, so better to do in embedded.
%
%  Name: t32_adc_datacube_injection()
%  Inputs:
%    look_type
%    t32lib
%    smc_cal
%    post_mipi_adc_data  (required) ADC payload from SCRIPT_Range_Doppler_Processing
%  Outputs:
%   status
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status] = t32_adc_datacube_injection(look_type, t32lib, smc_cal, post_mipi_adc_data, mipiStats, download_data_set)

   num_rbins = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   max_doppler_size = smc_cal.Configuration.BB_Configuration.MAX_DOPPLER_FFT_SIZE.VALUE;
   num_chirps = smc_cal.Configuration.BB_Configuration.K_FRAME.VALUE(look_type);
   num_samples = smc_cal.Configuration.BB_Configuration.M_FRAME.VALUE(look_type);
   num_rx = smc_cal.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE;

   set_data_ready_str = 'Intercom R52 var.set Offline_Data_Injection_Ptr->data_ready = 0xAA55';

   % Validate payload argument (do not read from MAT file)
   if isempty(post_mipi_adc_data) && isempty(mipiStats) && ~download_data_set
      status = -1;
      warning('post_mipi_adc_data or mipiStatspayload is missing or empty.');
      return
   elseif download_data_set
      load("mex_output\current_state_dfft.mat");
   end

   status = wait_for_bbe_ready_for_chirp(t32lib);

   last_string_length = 0;

   % This will disable debug outputs that come from the t32_write_data function.
   % If there are other debug statements added - set this to 0,
   % print_update will overwrite the line, so the screen isn't overwhelmed with bin updates.
   disable_write_outputs = 1;

   if status == 0
      for i = 1:num_chirps
         chirp_data = squeeze(post_mipi_adc_data(:, i, :));
         adc_lk1_chrp1_postmipi = chirp_data;

         adc_in_l1chn1_chrp1_postmipi = adc_lk1_chrp1_postmipi(1, :);
         adc_in_l1chn2_chrp1_postmipi = adc_lk1_chrp1_postmipi(2, :);
         adc_in_l1chn3_chrp1_postmipi = adc_lk1_chrp1_postmipi(3, :);
         adc_in_l1chn4_chrp1_postmipi = adc_lk1_chrp1_postmipi(4, :);

         adc_in_4ch_chrp1_postmipi = [adc_in_l1chn1_chrp1_postmipi; adc_in_l1chn2_chrp1_postmipi; adc_in_l1chn3_chrp1_postmipi; adc_in_l1chn4_chrp1_postmipi]';

         adc_in_4ch_chrp1_postmipi = adc_in_4ch_chrp1_postmipi + mod(adc_in_4ch_chrp1_postmipi, 2);

         chirp_data = reshape(adc_in_4ch_chrp1_postmipi, 1, num_rx * num_samples);

         chirp_data = typecast(int16(chirp_data(:)), 'uint8');

         excision_count_chA = mipiStats(1, i, 1, 1);
         excision_count_chB = mipiStats(1, i, 2, 1);
         excision_count_chC = mipiStats(1, i, 3, 1);
         excision_count_chD = mipiStats(1, i, 4, 1);

         max_excision_count = uint16(max(max(excision_count_chA, excision_count_chB), max(excision_count_chC, excision_count_chD)));

         status = t32_write_var(t32lib, 'max_excision_count_injection', max_excision_count);

         if status ~= 0
            break
         end

         status = t32_write_data(t32lib, 'Offline_Data_Injection_Ptr->chirp_data', chirp_data, disable_write_outputs);

         if status ~= 0
            break
         end

         status = t32_cmd(t32lib, set_data_ready_str);

         if status ~= 0
            break
         end

         wait_for_bbe_ready_for_chirp(t32lib);

         if status ~= 0
            break
         end

         % If the t32_write_data is outputting debug data, this printout must be disabled, since it clears the output string.
         last_string_length = print_update('Injected chirp:', last_string_length, i, num_chirps);

         if disable_write_outputs == 0
            last_string_length = 0;
         end
      end
   end

   if 0 ~= status
      warning("Error Injecting ADC data.");
   else
      status = t32_cmd(t32lib, set_data_ready_str);
      if 0 ~= status
         warning("Failed to write the final data ready.");
      end
   end

end

function status = wait_for_bbe_ready_for_chirp(t32lib)
   data_ready_flag_str = 'Offline_Data_Injection_Ptr->data_ready';
   data_ready = 0;
   t32_tries = 0;
   t32_tries_max = 10;

   while data_ready ~= hex2dec('55aa') && t32_tries < t32_tries_max
      [status, data_ready] = t32_read_mem(t32lib, data_ready_flag_str, 1);

      if status ~= 0
         break
      else
         data_ready = typecast(data_ready, 'uint32');

         if data_ready == hex2dec('55aa')
            break
         else
            t32_tries = t32_tries + 1;
         end
      end
   end
end
