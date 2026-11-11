function compare_and_excel(input_txt_folder)
   % Ask the user where to save the Excel file.
   output_excel_folder = uigetdir(pwd, 'Select a folder to save the Excel file');
   % Handle case where user cancels the dialog.
   if isequal(output_excel_folder, 0)
      disp('Operation cancelled by user.');
      return
   end
   % Set the output Excel file name
   output_excel_file = fullfile(output_excel_folder, 'PSP_Comparison_Results.xlsx');
   % Define the file pairs and corresponding Excel sheet names
   file_pairs = {
                 {'da_out_sil.txt', 'da_out_emb.txt', 'DA_Comparison'}
                 {'rc_out_sil.txt', 'rc_out_emb.txt', 'RC_Comparison'}
                 {'id_out_sil.txt', 'id_out_emb.txt', 'ID_Comparison'}
                 {'sa_out_sil.txt', 'sa_out_emb.txt', 'SA_Comparison'}
                };
   % ---- LOOP THROUGH EACH FILE PAIR ----
   for i = 1:numel(file_pairs)
      sil_filename = file_pairs{i}{1};
      emb_filename = file_pairs{i}{2};
      sheet_name   = file_pairs{i}{3};
      % Construct the full paths using the input argument
      sil_file = fullfile(input_txt_folder, sil_filename);
      emb_file = fullfile(input_txt_folder, emb_filename);
      fprintf('Processing %s and %s...\n', sil_file, emb_file);
      if exist(sil_file, 'file') && exist(emb_file, 'file')
         comparison_table = parse_and_compare(sil_file, emb_file);
         writetable(comparison_table, output_excel_file, 'Sheet', sheet_name);
      else
         warning('One or both files not found: %s, %s', sil_file, emb_file);
      end
   end
   % --- APPLY CONDITIONAL FORMATTING ---
   e = actxserver('Excel.Application');
   wb = e.Workbooks.Open(output_excel_file);
   for i = 1:numel(file_pairs)
      sheet_name = file_pairs{i}{3};
      ws = wb.Sheets.Item(sheet_name);
      last_row = ws.Cells(ws.Rows.Count, 'A').End(-4162).Row;
      diff_range = ws.Range(sprintf('D2:D%d', last_row));
      fc_green = diff_range.FormatConditions.Add('xlCellValue', 'xlEqual', '0');
      fc_green.Interior.Color = 5296274;
      fc_red = diff_range.FormatConditions.Add('xlCellValue', 'xlNotEqual', '0');
      fc_red.Interior.Color = 255;
   end
   wb.Save();
   wb.Close(false);
   e.Quit();
   delete(e);
   fprintf('Comparison complete. Results saved to %s.\n', output_excel_file);
end

% --- Helper function to parse files and compare values ---
function T = parse_and_compare(fileA, fileB)
   % Read files and parse into a containers.Map
   mapA = parse_file_to_map(fileA);
   mapB = parse_file_to_map(fileB);
   % Get a union of all unique keys
   all_keys = unique([keys(mapA), keys(mapB)]);
   % Initialize arrays to hold values and differences
   valA = nan(numel(all_keys), 1);
   valB = nan(numel(all_keys), 1);
   diffs = nan(numel(all_keys), 1);
   % Populate the arrays by checking for each key
   for k = 1:numel(all_keys)
      key = all_keys{k};
      if isKey(mapA, key)
         valA(k) = mapA(key);
      end
      if isKey(mapB, key)
         valB(k) = mapB(key);
      end
      diffs(k) = valA(k) - valB(k);
   end
   % Create a MATLAB table from the results
   T = table(all_keys', valA, valB, diffs, ...
             'VariableNames', {'Parameter', 'SiL', 'Embedded', 'Difference'});
end

% --- Helper function to parse a single file ---
function m = parse_file_to_map(filename)
   m = containers.Map;
   lines = strtrim(splitlines(fileread(filename)));
   lines = lines(~cellfun('isempty', lines));
   for i = 1:numel(lines)
      parts = strsplit(lines{i}, ':');
      if numel(parts) == 2
         key = strtrim(parts{1});
         value = str2double(strtrim(parts{2}));
         % Only add to map if conversion to number is successful
         if ~isnan(value)
            m(key) = value;
         end
      end
   end
end
