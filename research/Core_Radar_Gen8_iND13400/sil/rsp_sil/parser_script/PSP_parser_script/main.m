clear all;
pcap = struct();

root = pwd;
fprintf('\n========================================\n');
fprintf('   Gen8 iND13400 Complete SIL Pipeline\n');
fprintf('========================================\n\n');

% Repo root path
wkspace = "C:\Core_Radar_Gen8_iND13400"; % Update this based on local repo
wkspace = "C:\Core_Radar_Gen8_iND13400"; % Update this based on local repo

% SIL executable path
sil_exe_path = fullfile(wkspace, "bazel-bin\sil\rsp_sil\main\rsp_wrapper_interface\rdd_sil_interface\test\rdd_sil_Test.exe");
fprintf('=== STEP 1 : Select Variant ===\n');
variants = {'srr8p', 'flr8'};
[indx, tf] = listdlg('PromptString', {'Select a variant'}, ...
                     'SelectionMode', 'single', 'ListString', variants);
selected_variant = variants{indx};

% SIL bin file directory
sil_bin_file_path  = fullfile(wkspace, "sil", "rsp_sil", "data_bin", selected_variant, "rdd_data");
vse_bin_file_path  = fullfile(wkspace, "sil", "rsp_sil", "data_bin", selected_variant, "vse_data");
psp_bin_file_path  = fullfile(wkspace, "sil", "rsp_sil", "data_bin", selected_variant, "psp_data");
rfft_bin_file_path = fullfile(wkspace, "sil", "rsp_sil", "data_bin", selected_variant, "rfft_data");

% CMD for building AF SIL
cmd = strcat('bazelisk build', {' '}, ...
             '//sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface/test:rdd_sil_Test', {' '}, ...
             '--variant=', selected_variant, {' '}, ...
             '--@afbb//module/_common:sil_config_enable=True', {' '}, ...
             '--@rm//:use_bbe_cstub_simulator=False', {' '}, ...
             '--//sil/rsp_sil/main/sil_wrapper_interface:enable_logging=True', {' '}, ...
             '--psp_sil_config=True --copt="-g" --copt="-O0" -c dbg');
% , {' '}, ... '--subcommands --verbose_failures'); Can Add for visibility
% like debugging

cmd = string(cmd(1));

fprintf('=== STEP 2 : Select PCAP file ===\n');
% Select pcap file and stream definitions
uiwait(msgbox("select_pcap_file"));
[file, path] = uigetfile('*.pcap', 'Select a PCAP File');
if isequal(file, 0)
   f = msgbox("Operation Canceled");
   return
else
   disp(['User selected ', fullfile(path, file)]);
   pcapFilePath = fullfile(path, file);
end

fprintf('=== STEP 3 : Select streamdef folder ===\n');
uiwait(msgbox("Please_select_stream_defination_file"));
Streamdefinition_Files = uigetdir;
pcap = read_pcap_data(pcapFilePath, Streamdefinition_Files);

%% 1. Setup Session and Field Names
f_name1 = fieldnames(pcap);
session = pcap.(f_name1{1});
f_names = fieldnames(session);
% Helper Function: Finds the index of a stream by its ID (e.g., 'Stream_4_')
find_idx = @(id) find(contains(f_names, ['Stream_' num2str(id) '_']), 1);
%% 2. Primary Data Extraction (Using Stream IDs)
% Stream 4: RDD
idx4 = find_idx(4);
if ~isempty(idx4)
   rdd_stream = session.(f_names{idx4});
   look_data = rdd_stream.look_data;
   stream4_header_data = rdd_stream.stream_hdr;
end
% Stream 5: VSE
idx5 = find_idx(5);
if ~isempty(idx5)
   vse_data = session.(f_names{idx5}).veh_raw_data;
   stream5_header_data = session.(f_names{idx5}).stream_hdr;
end
% Stream 1: Detection
idx1 = find_idx(1);
if ~isempty(idx1)
   af_data = session.(f_names{idx1});
end
% Stream 2: Header/Alignment
idx2 = find_idx(2);
if ~isempty(idx2)
   header_struct = session.(f_names{idx2});
   staticalign_data = header_struct.alignment_data.static_alignment_data;
   dynalign_data = header_struct.alignment_data.dynamic_alignment_data;
end
% Stream 20: Radar Capability
idx20 = find_idx(20);
if ~isempty(idx20)
   rc_data = session.(f_names{idx20});
end
% Stream 45: DRA
idx45 = find_idx(45);
if ~isempty(idx45)
   dracore_data = session.(f_names{idx45}).dra_core_data;
end
% Stream 9: Alignment
idx9 = find_idx(9);
if ~isempty(idx9)
   sa_stream_data = session.(f_names{idx9});
end

% Stream 15: Detection Debug
idx15 = find_idx(15);
if ~isempty(idx15)
   detection_stream_data = session.(f_names{idx15});
end

% Stream 36: ID
idx36 = find_idx(36);
if ~isempty(idx36)
   ID_data = session.(f_names{idx36});
end

%% 3. Dynamic TOI Check (Stream 41)
idx41 = find_idx(41);

% Check if the index was actually found before using it
if ~isempty(idx41)
   % Only runs if Stream 41 exists
   current_stream = session.(f_names{idx41});

   if isfield(current_stream, 'toi_data')
      toi_data = current_stream.toi_data;
      disp(['Success: TOI data loaded from ', f_names{idx41}]);
      disp(['Success: TOI data loaded from ', f_names{idx41}]);
   else
      % Fallback if the field name inside Stream 40 is different
      toi_data = current_stream;
      warning('Stream 41 found, but "toi_data" subfield missing.');
      warning('Stream 41 found, but "toi_data" subfield missing.');
   end
else
   % Runs if Stream 40 is completely missing from the pcap
   toi_data = [];
   fprintf('Notice: Stream 41 (TOI) was not found in this pcap file.\n');
   fprintf('Notice: Stream 41 (TOI) was not found in this pcap file.\n');
end
disp('Data extraction complete.');
rdd_scan_index_data = stream4_header_data.scan_index;
vse_scan_index_data = stream5_header_data.scan_index;

% Setup directories
scriptDir = pwd;
repoRoot = fileparts(fileparts(fileparts(fileparts(scriptDir)))); % Go up to repo root

%% STEP 3: Create binary output directories
fprintf('\n=== STEP 4: Creating Binary Output Directories ===\n');
data_bin_base = fullfile(repoRoot, 'sil', 'rsp_sil', 'data_bin', selected_variant);
rdd_bin_path = fullfile(data_bin_base, 'rdd_data');
vse_bin_path = fullfile(data_bin_base, 'vse_data');
psp_bin_path = fullfile(data_bin_base, 'psp_data');
rfft_bin_path = fullfile(data_bin_base, 'rfft_data');

for path_cell = {rdd_bin_path, vse_bin_path, psp_bin_path, rfft_bin_path}
   path = path_cell{1};
   if ~isfolder(path)
      mkdir(path);
      fprintf('  Created: %s\n', path);
   end
end

max_frame_value = length(rdd_scan_index_data);

fprintf('=== STEP 5 : Select Frame Number ===\n');
% get the specific frame index from user
specific_frame_index = get_user_frame_index(max_frame_value);
rdd_scan_index = rdd_scan_index_data(specific_frame_index);

% get specific frame for vse stream data
vse_frame_index = find(rdd_scan_index == vse_scan_index_data);

% af_scan_index_data = stream1_header_data.scan_index;
% = find(af_scan_index_data == rdd_scan_index);

% write the rdd_data into bin file
write_rdd_data(rdd_stream, specific_frame_index, sil_bin_file_path);

% write the look_data into bin file
write_look_data(look_data, specific_frame_index, sil_bin_file_path);

% write the look_data into bin file
write_vse_data(vse_data, vse_frame_index, vse_bin_file_path);

% write the psp_data into bin file
write_psp_data(rc_data, dynalign_data, staticalign_data, dracore_data, toi_data, af_data, psp_bin_file_path);

% write the stream_hdr into bin file
write_stream_hdr_data(rdd_stream, specific_frame_index, sil_bin_file_path);

% write the stream_hdr into bin file
write_rfft_data(rdd_stream, specific_frame_index, rfft_bin_file_path);

% write the operation mode and data qualifier into bin file
% write_opmode_data_qualifier_data(toi_data, op_data, sil_bin_file_path);
% build the SIL wrapper lib
cd(wkspace);
fprintf('--- Starting Bazel Build ---\n');
system(cmd);

% run SIL executable
exe_dir = fileparts(sil_exe_path);

% Define where you want the .emb files to be stored
relative_output = fullfile('sil', 'rsp_sil', 'parser_script', 'PSP_parser_script', 'emb_output', selected_variant);
output_dir = fullfile(wkspace, relative_output);

% Create the folder if it doesnt already exist
if ~exist(output_dir, 'dir')
   mkdir(output_dir);
end

% Create the Alignment embedded out into  file
write_alignment_emb_out_parser(dracore_data, sa_stream_data, specific_frame_index, output_dir);

% Create the RC embedded out into  file
write_rc_emb_out_parser(rc_data, output_dir);

% Create the ID embedded out into  file
write_id_emb_out_parser(ID_data, specific_frame_index, output_dir);

% 3. RUN THE EXE FROM THE ROOT (Crucial Step)
% Do NOT cd(exe_dir). Bazel binaries need to see the 'WORKSPACE' file.
disp('Running SIL Executable from Workspace Root...');
run_cmd = sprintf('cd /d "%s" && "%s"', output_dir, sil_exe_path);
system(run_cmd);

% 5. Finalize
cd(root);
fprintf('\n========================================\n');
fprintf('   Pipeline Finished Successfully\n');
fprintf('   Results in: %s\n', output_dir);
fprintf('========================================\n');

cd(root);

% compare_and_excel(exe_dir);
