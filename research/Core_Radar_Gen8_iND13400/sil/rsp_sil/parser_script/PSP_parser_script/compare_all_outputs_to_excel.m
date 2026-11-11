function compare_all_outputs_to_excel(exe_dir, root)
   cd(exe_dir);
   % ---- FILE GROUPS ----
   fileGroups = { ...
                 {'da_out_sil.txt', 'da_out_emb.txt', 'DA_Comparison'}, ...
                 {'rc_out_sil.txt', 'rc_out_emb.txt', 'RC_Comparison'}, ...
                 {'id_out_sil.txt', 'id_out_emb.txt', 'ID_Comparison'}, ...
                 {'sa_out_sil.txt', 'sa_out_emb.txt', 'SA_Comparison'}};
   % ---- Prompt user to choose folder ----
   folderPath = uigetdir(pwd, 'Select folder to save Excel file');
   if folderPath == 0
      fprintf('User canceled. Exiting function.\n');
      return
   end
   % ---- Generate Excel file path automatically ----
   outExcel = fullfile(folderPath, 'PSP_emb_sil_comparison.xlsx');
   % ---- LOOP THROUGH ALL PAIRS ----
   for k = 1:numel(fileGroups)
      silFile  = fileGroups{k}{1};
      embFile  = fileGroups{k}{2};
      sheet    = fileGroups{k}{3};
      % Build comparison table
      T = compareTwoFiles(silFile, embFile);
      writetable(T, outExcel, 'Sheet', sheet);
   end
   % ---- APPLY CONDITIONAL FORMATTING ----
   % Use ActiveX to open Excel and add formatting
   e = actxserver('Excel.Application');
   wb = e.Workbooks.Open(outExcel);
   for k = 1:numel(fileGroups)
      sheetName = fileGroups{k}{3};
      ws = wb.Sheets.Item(sheetName);
      % Find last row
      lastRow = ws.Cells(ws.Rows.Count, 1).End(-4162).Row; % -4162 = xlUp
      % Difference column is column D
      range = ws.Range(sprintf('D2:D%d', lastRow));
      % Green if diff=0 (within tolerance), Red otherwise
      fc1 = range.FormatConditions.Add( ...
                                       'xlCellValue', 'xlEqual', '0'); % exactly zero
      fc1.Interior.Color = 5296274;      % green color
      fc2 = range.FormatConditions.Add( ...
                                       'xlCellValue', 'xlNotEqual', '0');
      fc2.Interior.Color = 255;          % red color
   end
   wb.Save;
   wb.Close(false);
   e.Quit;
   delete(e);
   fprintf('All comparisons written to %s with conditional formatting applied.\n', outExcel);
   cd(root);
end

function T = compareTwoFiles(fileA, fileB)
   % Read and clean
   linesA = strtrim(splitlines(fileread(fileA)));
   linesB = strtrim(splitlines(fileread(fileB)));
   linesA = linesA(~cellfun('isempty', linesA));
   linesB = linesB(~cellfun('isempty', linesB));
   % Parse into maps
   mapA = parseKeyValues(linesA);
   mapB = parseKeyValues(linesB);
   % Keys union
   allKeys = unique([keys(mapA), keys(mapB)]);
   valA = nan(numel(allKeys), 1);
   valB = nan(numel(allKeys), 1);
   diffVals = nan(numel(allKeys), 1);
   % Fill values and differences
   for i = 1:numel(allKeys)
      key = allKeys{i};
      if isKey(mapA, key)
         valA(i) = mapA(key);
      end
      if isKey(mapB, key)
         valB(i) = mapB(key);
      end
      diffVals(i) = valA(i) - valB(i);
   end
   % Table output
   T = table(allKeys', valA, valB, diffVals, ...
             'VariableNames', {'Parameter', 'SiL', 'Embedded', 'Difference'});
end

function m = parseKeyValues(lines)
   m = containers.Map;
   for i = 1:numel(lines)
      parts = strsplit(lines{i}, ':');
      if numel(parts) == 2
         key = strtrim(parts{1});
         val = str2double(strtrim(parts{2}));
         if ~isnan(val)
            m(key) = val;
         else
            m(key) = NaN; % treat non-numeric as NaN
         end
      end
   end
end
