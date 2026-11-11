% ***parse_pcap_data - does the same as parse_mudp_data with a new name
%
% parse_mudp_data - Parses raw UDP data according to a stream definition file
%
% USAGE:  data = parse_mudp_data(streamdef_file, X, big_endian, size_unknowns)
%
%         Examples:
%         data = parse_mudp_data('C:\stream_definitions\strdef_src010_str005_ver001.txt', payload, 0, 4);
%         data = parse_mudp_data('C:\stream_definitions\strdef_src010_str005_ver001.txt', payload, 1);
%         data = parse_mudp_data('C:\stream_definitions\strdef_src010_str005_ver001.txt', payload);
%
% REQUIRED INPUTS:
%     streamdef_file - full path to a stream definition text file
%                      e.g. 'D:\project_dir\stream_definitions\strdef_srcXXX_strYYY_verZZZ.txt'
%     X - 2-dimensional uint8 matrix containing the raw UDP stream payload bytes,
%         column-wise. The number of rows should equal the length of the payload
%         data and the number of columns should equal the number of data records.
%         i.e. Column 1 contains record 1, column N contains record N.
%
% OPTIONAL INPUTS:
%     big_endian - 1/true if stream data is in big-endian order
%                  0/false if stream data is in little-endian order
%                  If not specified, this defaults to 0/false.
%     size_unknowns - the size, in bytes, to assume for any unidentified
%                     (non-base) variable types
%                     If not specified, this defaults to 4.
%
% OUTPUTS:
%     data - a struct containing all of the signals from the stream definition
%            file populated by the payload bytes.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% APTIV PROPRIETARY
%   Copyright (C) 2013 Aptiv, All Rights Reserved
%
% THIS SOFTWARE IS APTIV PROPRIETARY.  IT MAY BE DISTRIBUTED, BY APTIV OR APTIV
% CUSTOMERS,  TO THIRD PARTIES WHO NEED THIS INFORMATION TO PURSUE APTIV-RELATED
% ACTIVITIES DIRECTED BY APTIV OR APTIV CUSTOMERS.  THIRD PARTIES SHALL NOT
% DISTRIBUTE THIS INFORMATION TO OTHER PARTIES OR USE THE INFORMATION FOR OTHER
% PURPOSES.
%
% THIS SOFTWARE INCLUDES NO WARRANTIES, EXPRESS OR IMPLIED, WHETHER ORAL, OR
% WRITTEN WITH RESPECT TO THE SOFTWARE OR OTHER MATERIAL, INCLUDING BUT NOT
% LIMITED TO ANY IMPLIED WARRANTIES OF MERCHANTABILITY, OR FITNESS FOR A
% PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF PERFORMANCE OR DEALING, OR
% FROM USAGE OR TRADE, OR OF NON-INFRINGEMENT OF ANY PATENTS OF THIRD PARTIES.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% History:
% 20131115  1.0  CH  Initial version.
% 20140127  1.1  CH  Bugfix to account for size of fixed point variables.
% 20171003  2.0  DP  Added support for big endian data.
% 20180419  2.1  DP  Very minor modifications to unknown type default size.
% 20190817  2.2  PC  Added Bitfield as a data type.
% 20191220  2.3  RKG Added Bitfield parsing support.
% 20220224  x.x  NS  Repurposed and renamed for pcap to mat conversion. No
%                    edits to this file other than the file and function
%                    names.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function data = parse_pcap_data(streamdef_file, X, big_endian, size_unknowns)

   % Validate input arguments.
   if (nargin < 3) || isempty(big_endian) || ~(islogical(big_endian) || isnumeric(big_endian))
      big_endian = false;
   end
   if (nargin < 4) || isempty(size_unknowns) || ~isnumeric(size_unknowns) || (size_unknowns < 1) || (mod(size_unknowns, 1) ~= 0)
      size_unknowns = 4; % enum/unknown type size defaulted to 4 bytes
   end

   if big_endian
      % Message bytes are in rows (i.e. column 1 has message 1, etc.).
      X = flipud(X);
   end

   MAX_LEVELS = 6;

   special_defs = {'REPEAT', 'END_REPEAT', 'PADDING'};

   % Initialize defaults.
   num_defs = 0;
   defs = cell(num_defs, 1);
   types = cell(num_defs, 1);
   scale = zeros(num_defs, 1);
   valid = zeros(num_defs, 1);
   repeat_count = zeros(num_defs, 1);
   repeat_count_all = zeros(num_defs, MAX_LEVELS);
   repeat_skip = zeros(num_defs, MAX_LEVELS);
   repeat_first = zeros(num_defs, 1);
   repeat_level = zeros(num_defs, 1);
   current_repeat_start = zeros(1, MAX_LEVELS);
   current_repeat_counter = zeros(1, MAX_LEVELS);
   current_repeat_count = zeros(1, MAX_LEVELS);
   current_repeat_skip = zeros(1, MAX_LEVELS);
   current_level = 0;
   current_start = 0;
   line_count = 1;
   m = 0;

   parse_data = zeros(num_defs, 1);
   bitfield_sz = zeros(num_defs, 1);
   bitfield_start = 0;
   bitfield_count = 0;
   bitfield_expected_count = 0;

   fid = fopen(streamdef_file, 'r');
   expected_recordsize = str2double(fgetl(fid));
   while ~feof(fid)
      % Read the next line in the file.
      temp = strtrim(fgetl(fid));
      line_count = line_count + 1;
      if isempty(temp)
         continue
      end
      m = m + 1;

      % Determine if the line contains a special operator (REPEAT, END_REPEAT, PADDING).
      special = false;
      for n = 1:length(special_defs)
         if strncmp(temp, special_defs{n}, length(special_defs{n}))
            special = true;
            break
         end
      end
      if special
         defs{m} = temp;
      else
         temp = my_strsplit(temp);
         if length(temp) < 2
            error('parse_mudp_data:syntaxError', 'Error on line %d of header file %s\n', line_count - 1, streamdef_file);
         end
         types{m} = my_strjoin(temp(1:end - 1));
         def_temp = my_strsplit(temp{end}, ':');
         defs{m} = def_temp{1};

         % Check for bitfield
         if length(def_temp) > 1
            bitfield_sz(m) = str2double(def_temp{2});
         else
            bitfield_sz(m) = 0; % Bitfield size 0 indicates that its Not a bitfield variable
         end
      end

      % Process the line contents.
      if strncmp(defs{m}, 'REPEAT', 6)
         valid(m) = 0;
         current_level = current_level + 1;
         current_repeat_start(current_level) = m;
         current_repeat_counter(current_level) = 0;
         current_repeat_skip(current_level) = 0;
         current_repeat_count(current_level) = str2double(defs{m}(7:end));
      elseif strncmp(defs{m}, 'END_REPEAT', 10)
         valid(m) = 0;
         repeat_skip(current_repeat_start(current_level) + 1:m - 1, current_level) = current_repeat_skip(current_level);
         current_start = current_start + current_repeat_skip(current_level) * (current_repeat_count(current_level) - 1);
         if current_level > 1
            current_repeat_skip(current_level - 1) = current_repeat_skip(current_level - 1) + current_repeat_count(current_level) * current_repeat_counter(current_level);
            current_repeat_counter(current_level - 1) = current_repeat_counter(current_level - 1) + current_repeat_count(current_level) * current_repeat_counter(current_level);
         end
         current_level = current_level - 1;
      else
         if strncmp(defs{m}, 'PADDING', 7)
            valid(m) = 0;
            bitfield_sz(m) = 0;
            sz = str2double(defs{m}(8:end));
         else
            valid(m) = 1;
            scale(m) = 1;
            switch lower(types{m})
               case {'double', 'float64', 'float64_t', 'real64_t'}
                  sz = 8;
                  types{m} = 'double';
               case {'single', 'float', 'float32', 'float32_t', 'real32_t'}
                  sz = 4;
                  types{m} = 'single';
               case {'uint8', 'uint8_t', 'unsigned char', 'bool', 'boolean', 'boolean_t', 'unsigned8_t', 'bitfield8_t'}
                  sz = 1;
                  types{m} = 'uint8';
               case {'int8', 'sint8', 'int8_t', 'sint8_t', 'signed char', 'char', 'signed8_t'}
                  sz = 1;
                  types{m} = 'int8';
               case {'uint16', 'uint16_t', 'unsigned short', 'unsigned16_t', 'bitfield16_t'}
                  sz = 2;
                  types{m} = 'uint16';
               case {'int16', 'sint16', 'int16_t', 'sint16_t', 'signed short', 'short', 'signed16_t'}
                  sz = 2;
                  types{m} = 'int16';
               case {'uint32', 'uint32_t', 'unsigned int', 'unsigned32_t', 'bitfield32_t'}
                  sz = 4;
                  types{m} = 'uint32';
               case {'int32', 'sint32', 'int32_t', 'sint32_t', 'signed int', 'int', 'signed32_t'}
                  sz = 4;
                  types{m} = 'int32';
               case {'uint64', 'uint64_t', 'unsigned64_t'}
                  sz = 8;
                  types{m} = 'uint64';
               case {'int64', 'sint64', 'int64_t', 'sint64_t', 'signed64_t'}
                  sz = 8;
                  types{m} = 'int64';
               otherwise
                  % identify fixed point types
                  match = false;
                  tokens = regexp(lower(types{m}), 's(\d+)p(\d+)_t', 'tokens');
                  if length(tokens) == 1
                     values = str2double(tokens{1});
                     bytes = (1 + sum(values)) / 8;
                     if bytes == round(bytes)
                        switch bytes
                           case 1
                              types{m} = 'int8';
                              scale(m) = 2^-values(2);
                              sz = bytes;
                              match = true;
                           case 2
                              types{m} = 'int16';
                              scale(m) = 2^-values(2);
                              sz = bytes;
                              match = true;
                           case 4
                              types{m} = 'int32';
                              scale(m) = 2^-values(2);
                              sz = bytes;
                              match = true;
                           case 8
                              types{m} = 'int64';
                              scale(m) = 2^-values(2);
                              sz = bytes;
                              match = true;
                        end
                     end
                  end
                  if ~match
                     tokens = regexp(lower(types{m}), 'u(\d+)p(\d+)_t', 'tokens');
                     if length(tokens) == 1
                        values = str2double(tokens{1});
                        bytes = sum(values) / 8;
                        if bytes == round(bytes)
                           switch bytes
                              case 1
                                 types{m} = 'uint8';
                                 scale(m) = 2^-values(2);
                                 sz = bytes;
                                 match = true;
                              case 2
                                 types{m} = 'uint16';
                                 scale(m) = 2^-values(2);
                                 sz = bytes;
                                 match = true;
                              case 4
                                 types{m} = 'uint32';
                                 scale(m) = 2^-values(2);
                                 sz = bytes;
                                 match = true;
                              case 8
                                 types{m} = 'uint64';
                                 scale(m) = 2^-values(2);
                                 sz = bytes;
                                 match = true;
                           end
                        end
                     end
                  end
                  if ~match
                     switch size_unknowns
                        case 1
                           types{m} = 'int8';
                           sz = size_unknowns;
                        case 2
                           types{m} = 'int16';
                           sz = size_unknowns;
                        case 4
                           types{m} = 'int32';
                           sz = size_unknowns;
                        case 8
                           types{m} = 'int64';
                           sz = size_unknowns;
                        otherwise
                           types{m} = 'int32';
                           sz = 4;
                     end
                  end
            end
         end
         current_level = current_level + 1;
         current_repeat_start(current_level) = m;
         current_repeat_counter(current_level) = 0;
         current_repeat_skip(current_level) = 0;

         if bitfield_count == bitfield_expected_count
            bitfield_start = 0;
            bitfield_count = 0;
            bitfield_expected_count = 0;
         elseif bitfield_count > bitfield_expected_count
            error('parse_mudp_data:bitfieldSizeError', 'Calculated bitfield size %d exceeds the number of bits for bitfield type %s.', bitfield_count, types{m});
         end

         if bitfield_sz(m) > 0
            if bitfield_start == 0
               bitfield_start = 1;
               bitfield_count = bitfield_sz(m);
               bitfield_expected_count = sz * 8;
               current_repeat_count(current_level) = sz;
               parse_data(m) = 1;
            else
               bitfield_count = bitfield_count + bitfield_sz(m);
               current_repeat_count(current_level) = 0;
               parse_data(m) = 0;
            end
         else
            bitfield_start = 0;
            bitfield_count = 0;
            bitfield_expected_count = 0;
            current_repeat_count(current_level) = sz;
            parse_data(m) = 1;
         end

         current_start = current_start + 1;
         if current_level == 0
            repeat_count(m) = 1;
         else
            repeat_count(m) = prod(current_repeat_count(1:current_level));
            repeat_count_all(m, 1:current_level) = current_repeat_count(1:current_level);
            current_repeat_counter(current_level) = current_repeat_counter(current_level) + 1;
            current_repeat_skip(current_level) = current_repeat_skip(current_level) + 1;
         end
         repeat_first(m) = current_start;
         repeat_level(m) = current_level;

         repeat_skip(m, current_level) = current_repeat_skip(current_level);
         current_start = current_start + current_repeat_skip(current_level) * (current_repeat_count(current_level) - 1);
         if current_level > 1
            current_repeat_skip(current_level - 1) = current_repeat_skip(current_level - 1) + current_repeat_count(current_level) * current_repeat_counter(current_level);
            current_repeat_counter(current_level - 1) = current_repeat_counter(current_level - 1) + current_repeat_count(current_level) * current_repeat_counter(current_level);
         end
         current_level = current_level - 1;
      end
   end
   fclose(fid);

   % Parse the values into a structure.
   recordsize = sum(repeat_count);
   if recordsize ~= expected_recordsize
      error('parse_mudp_data:recordSizeError', 'Calculated record size %d does not match expected record size %d.', recordsize, expected_recordsize);
   end
   nrecs = size(X, 2);

   data = [];
   num_defs = length(defs);
   for m = 1:num_defs
      if valid(m)
         if parse_data(m)
            temp_ind = repeat_first(m);
            for n = repeat_level(m):-1:1
               temp_ind = temp_ind' * ones(1, repeat_count_all(m, n)) + ones(length(temp_ind), 1) * (repeat_skip(m, n) * (0:repeat_count_all(m, n) - 1));
               temp_ind = reshape(temp_ind', 1, []);
            end
            temp_data = X(temp_ind, :)';
            if repeat_level(m) > 0
               temp_data = reshape(temp_data, [nrecs repeat_count_all(m, 1:repeat_level(m))]);
            end
            if ~strcmp(types{m}, 'uint8') && ~strcmp(types{m}, 'int8')
               temp_data = permute(temp_data, [ndims(temp_data) 1:ndims(temp_data) - 1]);
            end
            if ~strcmp(types{m}, 'uint8')
               temp_data = typecast(temp_data(:), types{m});
            end
            temp_data = double(temp_data) * scale(m);
            if repeat_level(m) > 1
               temp_data = reshape(temp_data(:), [nrecs repeat_count_all(m, 1:repeat_level(m) - 1)]);
            end

            % If data is big endian and the value is an array, reverse the array.
            if big_endian && (size(temp_data, 2) > 1)
               temp_data = fliplr(temp_data);
            end

            if bitfield_sz(m) > 0
               temp_data_bitfield = cast(temp_data, types{m});
            end
         end

         if bitfield_sz(m) > 0
            temp_data = bitand(temp_data_bitfield, (2^bitfield_sz(m)) - 1, types{m});
            temp_data_bitfield = bitshift(temp_data_bitfield, -bitfield_sz(m), types{m});
         end

         S = [];
         field_tree = my_strsplit(defs{m}, '\.');
         [S(1:length(field_tree)).type] = deal('.');
         [S.subs] = field_tree{:};
         data = subsasgn(data, S, temp_data);
      end
   end
end

%%
function output = my_strsplit(str, delim)

   if isempty(str)
      output = {};
      return
   end

   if nargin < 2
      delim = '\s+';
   end

   % find delimiter matches
   [start_ind, end_ind] = regexp(str, delim, 'start', 'end');

   % add start and end matches if needed
   if isempty(start_ind) || (start_ind(1) > 1)
      start_ind = [0 start_ind];
      end_ind = [0 end_ind];
   end
   if isempty(end_ind) || (end_ind(end) < length(str))
      start_ind = [start_ind (length(str) + 1)];
      end_ind = [end_ind (length(str) + 1)];
   end

   % split string into output
   output = cell(1, length(start_ind) - 1);
   for m = 1:length(start_ind) - 1
      output{m} = str((end_ind(m) + 1):(start_ind(m + 1) - 1));
   end
end

%%
function str = my_strjoin(strcell, delim)
   if nargin < 2
      delim = ' ';
   end
   if isempty(strcell)
      str = '';
   else
      str = strcell{1};
      for m = 2:length(strcell)
         str = [str delim strcell{m}]; %#ok<AGROW>
      end
   end
end
