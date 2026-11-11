%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This routine will decompress the XCP "lightly compressed" range output.
%
% The lightly compressed data is compressed with level 1 compression, and
% is the data collected across all chirps for a single range bin of data.
%
% The script allows for inputting a single or multiple input of data, provided
% the multiple inputs all have the same number of chirps of collected data.
%
% Inputs:
%   lightly_compressed - The compressed data input. Data should be of a datatype
%      related to bit widths, as it will be typecasted to int16 for processing.
%      For 2-D inputs, the data is expected to be formatted as 8 rows of uint16
%      data, or 16  rows of uint8 data.
%      For 1-D inputs, the data should be in linear order as collected from memory
%   num_chirps - Number of chirps to process
%
% Optional Inputs:
% max_chirps - The max number of chirps allowed, defaults to 1024
%              Embedded data requires this to be max number of chirps from SMC
%              Exec spec data requires this to be number of chirps per range bin
% plot_true - Set to 1 to plot the magnitude of the decompressed data, defaults to off
%
%
% Outputs:
% outRangeBin - The decompressed complex output for the range bin across all chirps
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [outRangeBin] = decomp_lightly_compressed_range_bin(lightly_compressed, num_chirps, max_chirps, plot_true)

   if ~exist('max_chirps', 'var')
      max_chirps = 1024; % By default, the max number of chirps will be 1024
   end

   if ~exist('plot_true', 'var')
      plot_true = 0;
   end

   cmp_lvl = 1; % Lightly compressed data compression level is 1.

   if ~isa(lightly_compressed, 'uint16') && ~isa(lightly_compressed, 'int16')
      lightly_compressed_u16 = typecast(lightly_compressed(:), 'int16');
   else
      lightly_compressed_u16 = lightly_compressed(:);
   end

   lightly_compressed_length = length(lightly_compressed_u16);

   % A single captured range bin of data will be 16 bytes * max_chirps
   % Each compressed word is 8 uint16 values
   % A range bin of data is composed of max_chirps compressed words
   words_per_sample = 8;
   range_bin_u16_words = words_per_sample * max_chirps;

   % Get the number of range bins to be decompressed
   num_range_bins = lightly_compressed_length / range_bin_u16_words;

   outRangeBin = zeros(num_range_bins, 4, num_chirps); % 4 received data points per compressed word

   for j = 1:num_range_bins
      idata_chirp          = reshape(lightly_compressed_u16((1:range_bin_u16_words) + (j - 1) * range_bin_u16_words), words_per_sample, []);
      [data_r, data_i, shft] = dcmp_unpack(idata_chirp, int16(1), int16(cmp_lvl));
      [outRangeBin(j, :, :), ~, ~] = decompression (2^-15 * complex(double(data_r), double(data_i)), double(shft), 0, 0, cmp_lvl, 0, 0, 0);
   end

   if plot_true
      % Plot the data only for the first collection of range bin data.
      plotData = squeeze(outRangeBin(1, :, :));
      for  adc_idx = 1:4
         figure(adc_idx);
         plot(db(abs(plotData(adc_idx, :))));
         xlabel('Chirp Index');
         ylabel('Magnitude (dB)');
      end
   end

end
