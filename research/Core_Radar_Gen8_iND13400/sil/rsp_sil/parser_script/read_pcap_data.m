%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% read_pcap_data - reads in pcap data and calls the parse function
%
% USAGE: output = read_pcap_data(pcapFilePath, streamdefFolderPath)
%
% REQUIRED INPUTS:
%     pcapFilePath: path to a pcap file with Aptiv stream data
%     streamdefFolderPath: path to a directory with stream definition files
%
% OUTPUTS:
%     output: a struct with the Aptiv stream data found in the given pcap
%             file
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function output = read_pcap_data(pcapFilePath, streamdefFolderPath)

   % SPLIT PACKET WORKAROUND
   splitPacketBool = false;

   % Output a struct
   output = struct();

   % Constants
   PCAP_GLOBAL_HEADER_SIZE = 24; % 24 bytes Global PCAP header
   PCAP_RECORD_HEADER_SIZE = 16; % 16 bytes per PCAP record header
   ENDIAN_CHECK = "A1";
   TIME_CHECK = "4D";
   APTIV_SOURCE_IP_ADDR = "C0A801"; % First three parts of source IP address Aptiv packets come from
   CORRECT_IP_PROTOCOL = 17; % IP protocol number to further filter out unneeded packets
   APTIV_HEADER_BEGIN = 43; % Byte number in PCAP payload where Aptiv header begins
   TOTAL_EXPECTED_PACKET_SIZE = 1514; % Number of bytes in an Aptiv packet including headers

   % Dynamic streams list
   DYNAMIC_STREAMS = struct('streamNumber', {}, 'streamName', {}, 'chunkIndexOffset', {});
   DYNAMIC_STREAMS(1).streamNumber = 6;
   DYNAMIC_STREAMS(1).streamName = "cdc";
   DYNAMIC_STREAMS(1).chunkIndexOffset = 1;
   DYNAMIC_STREAMS(2).streamNumber = 11;
   DYNAMIC_STREAMS(2).streamName = "rfft";
   DYNAMIC_STREAMS(2).chunkIndexOffset = -4096;

   % Validate input arguments
   if nargin < 2
      error('read_pcap_data:missingInputs', 'USAGE: read_pcap_data(pcapFilePath, streamdefFolderPath)\n');
   end
   if ~isfile(pcapFilePath)
      error('read_pcap_data:inputError', 'Cannot find file: %s.\n', pcapFilePath);
   end
   if ~isfolder(streamdefFolderPath)
      error('read_pcap_data:inputError', 'Cannot find folder: %s.\n', streamdefFolderPath);
   end

   % Open PCAP file
   pcapFileID = fopen(pcapFilePath, 'rb');
   if pcapFileID < 3
      error('read_pcap_data:fileio', 'Cannot open file: %s.\n', pcapFilePath);
   end

   % Read the PCAP global header to determine endianness of machine that
   %     captured the data and pcap time format
   globalHeader = fread(pcapFileID, PCAP_GLOBAL_HEADER_SIZE, '*uint8');
   globalFirstByte = dec2hex(globalHeader(1));
   globalIsBigEndian = 0;
   if globalFirstByte == ENDIAN_CHECK
      globalIsBigEndian = 1;
   end
   globalFourthByte = dec2hex(globalHeader(4));
   inNanos = 0;
   if globalFirstByte == TIME_CHECK || globalFourthByte == TIME_CHECK
      inNanos = 1;
   end

   % Splitting packets issue -> skip some bytes
   if splitPacketBool
      fread(pcapFileID, 78);
   end

   % Structure for keeping track of all packets that need parsed
   numPackets = 0;
   allAptivPackets = struct( ...
                            'isBigEndian', {}, ...
                            'timestamp', {}, ...
                            'sourceID', {}, ...
                            'streamRefIndex', {}, ...
                            'streamDataLength', {}, ...
                            'streamTxCnt', {}, ...
                            'streamNumber', {}, ...
                            'streamVersion', {}, ...
                            'streamNumChunks', {}, ...
                            'streamChunkIndex', {}, ...
                            'sensorID', {}, ...
                            'payload', {});

   % Read until the end of the given PCAP
   %     keeping track of packets that need parsed and ignoring others
   while ~feof(pcapFileID)

      % Splitting packets issue -> skip some bytes
      if splitPacketBool
         fread(pcapFileID, 18);
      end

      % Read PCAP record header bytes and get length of its payload
      [pcapRecordHeader, bytesRead] = fread(pcapFileID, PCAP_RECORD_HEADER_SIZE, '*uint8');
      if bytesRead ~= PCAP_RECORD_HEADER_SIZE
         continue
      end

      % Read the PCAP record's payload and timestamp
      pcapRecordLengthBytes = pcapRecordHeader(9:12);
      pcapSecondsBytes = pcapRecordHeader(1:4);
      pcapMicrosBytes = pcapRecordHeader(5:8);
      if globalIsBigEndian
         pcapRecordLength = typecast(flip(pcapRecordLengthBytes), 'uint32');
         pcapSeconds = typecast(flip(pcapSecondsBytes), 'uint32');
         pcapMicroseconds = double(typecast(flip(pcapMicrosBytes), 'uint32')) / 1000000.0;
      else
         pcapRecordLength = typecast(pcapRecordLengthBytes, 'uint32');
         pcapSeconds = typecast(pcapSecondsBytes, 'uint32');
         pcapMicroseconds = double(typecast(pcapMicrosBytes, 'uint32')) / 1000000.0;
      end
      pcapRecordPayload = fread(pcapFileID, pcapRecordLength, '*uint8');
      pcapTimestamp = double(pcapSeconds);
      if inNanos
         pcapNanoSeconds = pcapMicroseconds / 1000;
         pcapTimestamp = pcapTimestamp + pcapNanoSeconds;
      else
         pcapTimestamp = pcapTimestamp + pcapMicroseconds;
      end

      % Continue if this packet is not Aptiv packet size
      %     Have to do this first before other checks
      if pcapRecordLength ~= TOTAL_EXPECTED_PACKET_SIZE
         continue
      end

      % Confirm that this is an Aptiv UDP packet
      %     by checking the source address bytes and protocol
      %     and skip to the next loop iteration if not an Aptiv UDP packet
      sourceAddress = convertCharsToStrings(dec2hex(pcapRecordPayload(27:29), 2)');
      ipProtocol = pcapRecordPayload(24);
      if sourceAddress ~= APTIV_SOURCE_IP_ADDR || ...
         ipProtocol ~= CORRECT_IP_PROTOCOL
         continue
      end

      % Read important info from Aptiv header
      aptivHeaderFirstTwoBytes = pcapRecordPayload(APTIV_HEADER_BEGIN:APTIV_HEADER_BEGIN + 1);
      aptivHeaderVersion = convertCharsToStrings(dec2hex(aptivHeaderFirstTwoBytes, 2)');

      % Get information specific to header version
      % Version 1, little endian header version
      if aptivHeaderVersion == "18A1"

         isBigEndian = 0;
         aptivHeaderSize = double(aptivHeaderFirstTwoBytes(1));
         aptivHeader = pcapRecordPayload(APTIV_HEADER_BEGIN:APTIV_HEADER_BEGIN + aptivHeaderSize - 1);
         sourceID = aptivHeader(9);
         streamRefIndex = double(typecast(aptivHeader(13:16), 'uint32'));
         streamDataLength = double(typecast(aptivHeader(17:18), 'uint16'));
         streamTxCnt = aptivHeader(19);
         streamNumber = aptivHeader(20);
         streamVersion = aptivHeader(21);
         streamNumChunks = aptivHeader(22);
         streamChunkIndex = aptivHeader(23);
         sensorID = aptivHeader(24);

         % Version 3, big endian header version
      elseif aptivHeaderVersion == "A318"

         isBigEndian = 1;
         aptivHeaderSize = double(aptivHeaderFirstTwoBytes(2));
         aptivHeader = pcapRecordPayload(APTIV_HEADER_BEGIN:APTIV_HEADER_BEGIN + aptivHeaderSize - 1);
         sourceID = aptivHeader(9);
         streamRefIndex = double(typecast(aptivHeader(16:-1:13), 'uint32'));
         streamDataLength = double(typecast(aptivHeader(18:-1:17), 'uint16'));
         streamTxCnt = aptivHeader(19);
         streamNumber = aptivHeader(20);
         streamVersion = aptivHeader(21);
         streamNumChunks = aptivHeader(22);
         streamChunkIndex = aptivHeader(23);
         sensorID = aptivHeader(10);

         % Version 5, little endian header version
      elseif aptivHeaderVersion == "1CA5"

         isBigEndian = 0;
         aptivHeaderSize = double(aptivHeaderFirstTwoBytes(1));
         aptivHeader = pcapRecordPayload(APTIV_HEADER_BEGIN:APTIV_HEADER_BEGIN + aptivHeaderSize - 1);
         sourceID = aptivHeader(9);
         streamRefIndex = double(typecast(aptivHeader(13:16), 'uint32'));
         streamDataLength = double(typecast(aptivHeader(17:18), 'uint16'));
         streamTxCnt = aptivHeader(19);
         streamNumber = aptivHeader(20);
         streamVersion = aptivHeader(21);
         streamNumChunks = double(typecast(aptivHeader(23:24), 'uint16'));
         streamChunkIndex = double(typecast(aptivHeader(25:26), 'uint16'));
         sensorID = aptivHeader(28);

         % Version 5, big endian header version
      elseif aptivHeaderVersion == "A51C"

         isBigEndian = 1;
         aptivHeaderSize = double(aptivHeaderFirstTwoBytes(2));
         aptivHeader = pcapRecordPayload(APTIV_HEADER_BEGIN:APTIV_HEADER_BEGIN + aptivHeaderSize - 1);
         sourceID = aptivHeader(9);
         streamRefIndex = double(typecast(aptivHeader(16:-1:13), 'uint32'));
         streamDataLength = double(typecast(aptivHeader(18:-1:17), 'uint16'));
         streamTxCnt = aptivHeader(19);
         streamNumber = aptivHeader(20);
         streamVersion = aptivHeader(21);
         streamNumChunks = double(typecast(aptivHeader(24:-1:23), 'uint16'));
         streamChunkIndex = double(typecast(aptivHeader(26:-1:25), 'uint16'));
         sensorID = aptivHeader(28);

         % Otherwise, skip to next packet, this one doesn't have a proper header
      else
         fprintf('Unreadable header with version info: %s\n', aptivHeaderVersion);
         continue
      end

      % Add to packets structure
      numPackets = numPackets + 1;
      allAptivPackets(numPackets).isBigEndian = isBigEndian;
      allAptivPackets(numPackets).timestamp = pcapTimestamp;
      allAptivPackets(numPackets).sourceID = sourceID;
      allAptivPackets(numPackets).streamRefIndex = streamRefIndex;
      allAptivPackets(numPackets).streamDataLength = streamDataLength;
      allAptivPackets(numPackets).streamTxCnt = streamTxCnt;
      allAptivPackets(numPackets).streamNumber = streamNumber;
      allAptivPackets(numPackets).streamVersion = streamVersion;
      allAptivPackets(numPackets).streamNumChunks = streamNumChunks;
      allAptivPackets(numPackets).streamChunkIndex = streamChunkIndex;
      allAptivPackets(numPackets).sensorID = sensorID;
      allAptivPackets(numPackets).payload = pcapRecordPayload(APTIV_HEADER_BEGIN + aptivHeaderSize:end);
   end

   % Close the PCAP
   fclose(pcapFileID);

   % Find each stream number/version/source/sensor combination that is present
   presentStreamCombos = unique([ ...
                                 allAptivPackets.sensorID; ...
                                 allAptivPackets.streamNumber; ...
                                 allAptivPackets.streamVersion; ...
                                 allAptivPackets.sourceID]', 'rows');

   % Loop for each combination present
   for j = 1:size(presentStreamCombos, 1)

      % Get this combination's packets
      currentSourceID = double(presentStreamCombos(j, 4));
      currentStreamNum = double(presentStreamCombos(j, 2));
      currentStreamVer = double(presentStreamCombos(j, 3));
      currentSensorID = double(presentStreamCombos(j, 1));
      currentPackets = allAptivPackets( ...
                                       [allAptivPackets.sourceID] == currentSourceID & ...
                                       [allAptivPackets.streamNumber] == currentStreamNum & ...
                                       [allAptivPackets.streamVersion] == currentStreamVer & ...
                                       [allAptivPackets.sensorID] == currentSensorID);

      % Print status statement for this stream combo
      fprintf("\nAttempting to parse source %d stream %d version %d for sensor %d...\n", currentSourceID, currentStreamNum, currentStreamVer, currentSensorID);

      % Prepare output structure of this stream combo
      sensorName = getSensorNameFromSourceID(currentSourceID);
      sensorFieldName = sprintf("Sensor_%d_%s", currentSensorID, sensorName);
      if isempty(find(fieldnames(output) == sensorFieldName, 1))
         output.(sensorFieldName) = struct();
      end

      % Construct this stream combo's streamdef (or strdef) filename
      streamdefFileName = sprintf('streamdef_src%03d_str%03d_ver%03d.txt', currentSourceID, currentStreamNum, currentStreamVer);
      streamdefFilePath = fullfile(streamdefFolderPath, streamdefFileName);
      strdefFileName = sprintf('strdef_src%03d_str%03d_ver%03d.txt', currentSourceID, currentStreamNum, currentStreamVer);
      strdefFilePath = fullfile(streamdefFolderPath, strdefFileName);

      % Skip if streamdef/strdef doesn't exist
      if ~isfile(streamdefFilePath)
         streamdefFilePath = strdefFilePath;
         if ~isfile(streamdefFilePath)
            warning('read_pcap_data:missing_streamdef', 'Missing strdef/streamdef file %s in folder %s\nSkipping this stream...', streamdefFilePath, streamdefFolderPath);
            errorText = sprintf('Missing strdef/streamdef file %s in folder %s', streamdefFilePath, streamdefFolderPath);
            output.(sensorFieldName).(sprintf("Stream_%d_Version_%d", currentStreamNum, currentStreamVer)) = errorText;
            continue
         end
      end

      % Prepare variables for finding chunks of incomplete streams
      packetsToRemove = [];
      oneStreamPackets = [];
      firstChunkIndex = 0;
      finalChunkIndex = double(currentPackets(1).streamNumChunks) - 1;
      numCompleteStreams = 0;

      % Dynamic stream adjustment
      dynamicStream = false;
      dynamicStreamNums = extractfield(DYNAMIC_STREAMS, 'streamNumber');
      if any(dynamicStreamNums == currentStreamNum)
         dynamicStream = true;
         dynamicStreamName = DYNAMIC_STREAMS(dynamicStreamNums == currentStreamNum).streamName;
         chunkIndexOffset = DYNAMIC_STREAMS(dynamicStreamNums == currentStreamNum).chunkIndexOffset;
         newChunkIndexes = num2cell(extractfield(currentPackets, 'streamChunkIndex') + chunkIndexOffset);
         [currentPackets.streamChunkIndex] = newChunkIndexes{:};
         firstChunkIndex = 1;
      end

      % Find chunks of incomplete streams
      streamChunkIndexes = extractfield(currentPackets, 'streamChunkIndex');
      streamChunkDiffs = diff(double(streamChunkIndexes));
      m = 1;
      while m <= length(streamChunkIndexes)
         while m <= length(streamChunkDiffs) && streamChunkDiffs(m) > 0
            oneStreamPackets = [oneStreamPackets m]; %#ok<AGROW>
            m = m + 1;
         end
         oneStreamPackets = [oneStreamPackets m]; %#ok<AGROW>
         m = m + 1;
         if any(streamChunkDiffs(oneStreamPackets(1:end - 1)) ~= 1) || ...
                 streamChunkIndexes(oneStreamPackets(1)) ~= firstChunkIndex || ...
                 (streamChunkIndexes(oneStreamPackets(end)) ~= finalChunkIndex && ...
                  firstChunkIndex == 0)
            packetsToRemove = [packetsToRemove oneStreamPackets]; %#ok<AGROW>

            % ALSO, count number of complete streams
         else
            numCompleteStreams = numCompleteStreams + 1;
         end
         oneStreamPackets = [];
      end

      % Trim incomplete streams and continue if no complete streams
      currentPackets(packetsToRemove) = [];
      if isempty(currentPackets)
         warning('read_pcap_data:no_complete_stream', 'Source %d stream %d version %d for sensor %d has no complete streams.\nSkipping this stream...', currentSourceID, currentStreamNum, currentStreamVer, currentSensorID);
         errorText = sprintf('Source %d stream %d version %d for sensor %d has no complete streams.', currentSourceID, currentStreamNum, currentStreamVer, currentSensorID);
         output.(sensorFieldName).(sprintf("Stream_%d_Version_%d", currentStreamNum, currentStreamVer)) = errorText;
         continue
      end

      % Get the expected number of bytes for this stream from streamdef
      fid = fopen(streamdefFilePath);
      requiredByteNumber = str2double(fgetl(fid));
      fclose(fid);

      % Preallocate variables to build this stream's data matrix
      maxNumChunks = double(currentPackets(1).streamNumChunks);
      maxChunkSize = length(currentPackets(1).payload); % Only the last chunk of a stream may not be full
      % Dynamic stream adjustment
      if dynamicStream
         maxNumChunks = max(double(streamChunkIndexes));
         maxChunkSize = maxChunkSize - mod(maxChunkSize, requiredByteNumber);
      end
      streamDataColumn = zeros(maxNumChunks * maxChunkSize, 1);
      streamDataMatrix = zeros(maxNumChunks * maxChunkSize, numCompleteStreams);
      recordNumber = 1;

      % Loop for each packet received from this stream
      for k = 1:length(currentPackets)

         % Get indices for data insertion in streamDataColumn
         chunkSize = length(currentPackets(k).payload);
         chunkIndex = double(currentPackets(k).streamChunkIndex);
         % Dynamic stream adjustment
         if dynamicStream
            chunkIndex = chunkIndex - 1;
            chunkSize = chunkSize - mod(chunkSize, requiredByteNumber);
         end
         insertBegin = chunkIndex * chunkSize + 1;
         insertEnd =  chunkIndex * chunkSize + chunkSize;

         % Add this packet's payload to streamDataColumn
         streamDataColumn(insertBegin:insertEnd) = currentPackets(k).payload(1:chunkSize);

         % If this is the last packet in the loop or a final chunk
         %     add streamDataColumn to streamDataMatrix
         %     (plus dynamic stream adjustment)
         if k == length(currentPackets) || currentPackets(k + 1).streamChunkIndex == 0 || ...
                 (dynamicStream && currentPackets(k + 1).streamChunkIndex == 1)
            streamDataMatrix(:, recordNumber) = streamDataColumn;
            recordNumber = recordNumber + 1;
         end
      end

      % Trim extra zeros from matrix (skip for dynamic streams)
      if ~dynamicStream
         streamDataMatrix(requiredByteNumber + 1:end, :) = [];
      end

      % Cast the data matrix to uint8
      streamData8Byte = cast(streamDataMatrix, 'uint8');

      % Get endianness of matrix
      isBigEndianMatrix = currentPackets(1).isBigEndian;

      % Other helping variables
      if ~dynamicStream
         firstChunks = find(extractfield(currentPackets, 'streamChunkIndex') == 0)';
      else
         firstChunks = find(extractfield(currentPackets, 'streamChunkIndex') == 1)';
      end
      streamRefIndexArray = extractfield(currentPackets(firstChunks), 'streamRefIndex')';

      % Call the parse function for this stream combo
      %     (plus dynamic stream adjustment)
      if ~dynamicStream
         streamStruct = parse_pcap_data(streamdefFilePath, streamData8Byte, isBigEndianMatrix);
      else
         % Setup dynamic stream output
         streamStruct = struct();
         streamStruct.(dynamicStreamName) = struct();

         % Loop for each frame of dynamic stream data
         chunksPerFrame = [diff(firstChunks); (length(currentPackets) - firstChunks(end) + 1)];
         for i = 1:size(streamData8Byte, 2)
            % Reshape the data and parse
            numChunksSingleFrame = chunksPerFrame(i);
            dynamicChunkSize = numChunksSingleFrame * maxChunkSize;
            singleFrameData = streamData8Byte(1:dynamicChunkSize, i);
            reshapedSingleFrameData = reshape(singleFrameData, requiredByteNumber, []);
            if isempty(fields(streamStruct.(dynamicStreamName)))
               streamStruct.(dynamicStreamName) = parse_pcap_data(streamdefFilePath, reshapedSingleFrameData, isBigEndianMatrix);
            else
               streamStruct.(dynamicStreamName)(i) = parse_pcap_data(streamdefFilePath, reshapedSingleFrameData, isBigEndianMatrix);
            end
         end
      end

      % Add header information to this struct
      streamStruct.header = struct();
      streamStruct.header.streamRefIndex = streamRefIndexArray;
      streamStruct.header.streamDataLength = extractfield(currentPackets, 'streamDataLength')';
      streamStruct.header.streamTxCnt = extractfield(currentPackets, 'streamTxCnt')';
      streamStruct.header.timestamp = extractfield(currentPackets, 'timestamp')';

      % Add this stream struct to the output
      output.(sensorFieldName).(sprintf("Stream_%d_Version_%d", currentStreamNum, currentStreamVer)) = streamStruct;
      fprintf('Success!\n');

   end
end

% Get the correct sensor name based on the read source ID
function sensorName = getSensorNameFromSourceID(sourceID)
   switch sourceID
      case 200
         sensorName = "FLR4";
      case 201
         sensorName = "SRR6";
      case 202
         sensorName = "SRR6P";
      case 203
         sensorName = "FLR4P";
      case 204
         sensorName = "SRR7P";
      case 073
         sensorName = "FLR7";
      otherwise
         sensorName = "Unknown_Sensor";
   end
end
