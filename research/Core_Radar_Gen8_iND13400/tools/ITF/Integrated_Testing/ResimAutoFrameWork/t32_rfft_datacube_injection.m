% [status, emb_data_cube] = t32_rfft_datacube_injection(look_type, t32lib, smc_cal)
% This function loads the current_state_rfft from spec and injects it to
% the radar data cube in system memory. Does the writes to memory so that the data
% can be read out by the embedded doppler processing in the RA using the "view" concept
% of Gen8.
%
%  Inputs:
%   look_type
%   t32lib - obtained by running t32_config()
%   smc_cal
%  Outputs:
%   status - non-zero indicates an error occurred.
%   emb_data_cube - the embedded data cube written to the system memory
%
function [status, emb_data_cube_uint8] = t32_rfft_datacube_injection(look_type, t32lib, smc_cal, download_data_set)

   num_rbins = smc_cal.Configuration.BB_Configuration.RANGE_BINS_USED.VALUE(look_type);
   num_rbins_low = smc_cal.Configuration.BB_Configuration.VARIABLE_COMPRESSION_RANGE_BIN.VALUE;
   num_rbins_high = num_rbins - num_rbins_low;
   max_doppler_size = smc_cal.Configuration.BB_Configuration.MAX_DOPPLER_FFT_SIZE.VALUE;
   num_chirps = smc_cal.Configuration.BB_Configuration.K_FRAME.VALUE(look_type);

   if exist('current_state_rfft.mat', 'file') && ~download_data_set
      S = load('current_state_rfft.mat');
      if isfield(S, 'rfftResult_comp') && isfield(S, 'range_end_min_shift')
         rfftResult_comp = S.rfftResult_comp;
         range_end_min_shift = S.range_end_min_shift;
      else
         status = -1;
         emb_data_cube = [];
         warning('current_state_rfft.mat missing rfftResult_comp or range_end_min_shift');
         return
      end
   elseif download_data_set
      load("mex_output\current_state_dfft.mat");
   else
      status = -1;
      emb_data_cube = [];
      warning('current_state_rfft.mat not found. Cannot inject RFFT datacube.');
      return
   end
   rfft_comp_op_copy = rfftResult_comp;

   value_to_write = 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.min_chirp_scaling';
   t32_write_var(t32lib, value_to_write, uint8(range_end_min_shift));
   [status, min_chirp_scaling_ipc] = t32_read_mem(t32lib, value_to_write, 1);
   if status ~= 0
      fprintf('Error Writing min_chirp_scaling in IPC \n');
   end

   % Now validate that the range_end_min_shift was written correctly.
   min_chirp_scaling_ipc = typecast(min_chirp_scaling_ipc, 'uint8');
   if min_chirp_scaling_ipc  ~= uint8(range_end_min_shift)
      fprintf('Correct min_chirp_scaling not successfully written in IPC.\n');
   end

   emb_data_cube_low = uint64(zeros(num_rbins_low, max_doppler_size));
   emb_data_cube_high = uint32(zeros(num_rbins_high, max_doppler_size));

   for j = 1:num_rbins_low
      chirp_idx = (j - 1) * num_chirps;
      for i = 1:num_chirps
         rfft_64bit = typecast(rfft_comp_op_copy(j, 1:4, i), 'uint64');

         % fito address calculation
         byte_index = chirp_idx * 8;
         start_addr = byte_index;
         addr = byte_index;
         b43 = bitand(addr, hex2dec('00000018'));
         b5 = bitand(addr, hex2dec('00000020'));
         addr = bitand(addr, hex2dec('FFFFFFC0'));
         addr = addr + b43 * 2 + b5 / 4;

         % Iterating with chirp_idx as chirp continuos data,
         % destination array is RangeProc_OutputDataCube[K_MAX][MAX_RANGE_BINS]
         y_idx = uint32(floor((addr / 8) / num_rbins_low));
         x_idx = mod(addr / 8, num_rbins_low);

         emb_data_cube_low(x_idx + 1, y_idx + 1) = (rfft_64bit);

         chirp_idx = chirp_idx + 1;
      end
   end

   for j = 1:num_rbins_high
      chirp_idx = (j - 1) * num_chirps;
      for i = 1:num_chirps
         rfft_32bit = typecast(rfft_comp_op_copy(num_rbins_low + j, 1:2, i), 'uint32');

         % fito address calculation
         byte_index = chirp_idx * 4;
         start_addr = byte_index;
         addr = byte_index;
         b32 = bitand(addr, hex2dec('0000000C'));
         b54 = bitand(addr, hex2dec('00000030'));
         addr = bitand(addr, hex2dec('FFFFFFC3'));
         addr = addr + b32 * 4 + b54 / 4; % addr = addr + (b3  <<2) + (b54 >>1);

         % Iterating with chirp_idx as chirp continuos data,
         % destination array is RangeProc_OutputDataCube[K_MAX][MAX_RANGE_BINS]
         y_idx = uint32(floor((addr / 4) / num_rbins_high));
         x_idx = mod(addr / 4, num_rbins_high);

         emb_data_cube_high(x_idx + 1, y_idx + 1) = (rfft_32bit);

         chirp_idx = chirp_idx + 1;
      end
   end

   emb_data_cube_low_uint8 = typecast(reshape(emb_data_cube_low(:, 1:num_chirps), [], 1), 'uint8');
   emb_data_cube_high_uint8 = typecast(reshape(emb_data_cube_high(:, 1:num_chirps), [], 1), 'uint8');
   emb_data_cube_uint8 = [emb_data_cube_low_uint8; emb_data_cube_high_uint8];

   status = t32_write_data(t32lib, 'RangeProc_OutputDataCube', emb_data_cube_uint8);

   if 0 ~= status
      warning("Error Injecting RFFT Datacube.");
   end

end
