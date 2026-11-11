%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The goal of the function is to create final HTML based summary reports
% which holds all sub reports asa subset of final summary reports.
% Name: finalize_reports()
%
% inputs:
%  tot_BBs
%  BB_flag
%  tc_fail_cnt
%  tot_pass_cnt
%  tot_fail_cnt
%  tot_report_cnt
%  tot_report_string
%  test_string
%  testcase_dir_name
%  SMC_Version
%  sw_id
%  USC_Version
%  BB_version_Af
%  platform_id
%  time_taken
% outputs:
%  varargout

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function varargout = finalize_reports(tot_BBs, BB_flag, tc_fail_cnt, tot_pass_cnt, tot_fail_cnt, tot_report_cnt, tot_report_string, test_string, testcase_dir_name, SMC_Version, sw_id, USC_Version, BB_version_Af, platform_id, time_taken)

   global af_Testing
   global sensor_type
   global test_case

   global BB_name
   global Count_Look_Processing
   global Count_CFAR
   global Count_First_Pass
   global Count_Second_Pass
   global Count_Angle_Finding
   global look_string

   testcase_fail = 0;
   testcase_pass = 0;
   overall_pass = 0;
   overall_fail = 0;
   loop_cnt = 0;
   loop_cnt_BB = 0;
   count_BB = 0;

   if BB_flag == 1
      count_BB = eval(['Count_' BB_name]);
   end
   testcase_cnt = 0;

   Test_ID = testcase_dir_name;
   dt = datetime('now');
   date = char(dt, 'dd-MMM-yyyy');
   time = char(dt, 'HH:mm:ss');

   if af_Testing == 1
      for i = 1:1
         mkdir(['./Reports/' testcase_dir_name '/', test_string{i}]);
      end
   else
      for i = 1:tot_BBs
         mkdir(['./Reports/' testcase_dir_name '/', test_string{i}]);
      end
   end
   if count_BB == 1
      for i = 1:tot_BBs
         if BB_flag == 1
            if strcmp(BB_name, test_string{i})
               if 7 == exist(['./Reports/BB_' test_string{i}], 'dir')
                  rmdir(['./Reports/BB_' test_string{i}], 's');
               end
            end
         end
      end
   end

   for i = 1:tot_BBs
      if BB_flag == 1
         if strcmp(BB_name, test_string{i})
            mkdir(['./Reports/BB_' test_string{i} '/', testcase_dir_name]);
            if count_BB == 1
               summary_string_BB = ['<head><title>' test_string{i} '&nbspResult&nbspSummary</title></head><div align="left">', ...
                                    '<img src="https://www.underconsideration.com/brandnew/archives/aptiv_logo.png"alt="Aptiv Logo"', ...
                                    'style="width:342px;height:48px;"></div><h1>' test_string{i}  '&nbspResults </h1>\n'];
            end
         end
      end
   end

   % Create header for overall summary
   summary_string = ['<head><title>Testcase&nbsp;Summary</title></head>', ...
                     '<div align="middle"><img src="https://www.underconsideration.com/brandnew/archives/aptiv_logo.png"alt="Aptiv Logo" style="width:342px;height:48px;"></div>\n', ...
                     '<div align="left"><span style="font-family: Arial; font-size: 16pt; color: #000000;"><strong>Overall Testcase Results</strong></div>\n', ...
                     '<table border="0" width="100%%" cellpadding="2">\n', ...
                     '<tbody>\n', ...
                     '<tr bgcolor="#ce380a">\n', ...
                     '<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>Table&nbsp;Of&nbsp;Contents</strong></td>\n', ...
                     '</tr>\n', ...
                     '<tr>\n', ...
                     '<td>\n', ...
                     '<table border="0" width="100%%" cellpadding="2">\n', ...
                     '<tbody>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td>\n', ...
                     '<ul>\n', ...
                     '<li><a href="#section1">Configuration&nbsp;Data</a>\n', ...
                     '</li><li><a href="#section2">Overall&nbsp;Results</a></li>\n', ...
                     '<li><a href="#section3">Testcase&nbsp;Results</a></li>\n', ...
                     '</ul>\n', ...
                     '</td>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n', ...
                     '</td>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n'];

   % Test Management Report Section 1
   summary_string = [summary_string ...
                     '<tbody>\n', ...
                     '<tr>\n', ...
                     '<td>\n', ...
                     '<a name="section1"></a>&nbsp;</td>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n', ...
                     '<table border="0" width="100%%" cellpadding="2">\n', ...
                     '<tbody>\n', ...
                     '<tr bgcolor="#ce380a">\n', ...
                     '<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>Configuration&nbsp;Data</strong></td>\n', ...
                     '</tr>\n', ...
                     '<tr>\n', ...
                     '<td>\n', ...
                     '<table border="0" cellpadding="2">\n', ...
                     '<tbody>\n', ...
                     '<tr>\n', ...
                     '<td colspan="2"><strong>This&nbsp;report&nbsp;includes&nbsp;data&nbsp;for:</strong></td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Test&nbsp;Name:</strong></td>\n', ...
                     '<td align="center">', ' Integration Test', '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Variant:</strong></td>\n', ...
                     '<td align="center">', sensor_type, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Test&nbsp;ID:</strong></td>\n', ...
                     '<td align="center">', Test_ID, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Test&nbsp;case:</strong></td>\n', ...
                     '<td align="center">', test_case, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Platform ID:</strong></td>\n', ...
                     '<td align="center">', num2str(platform_id), '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>SMC&nbsp;Version:</strong></td>\n', ...
                     '<td align="center">', SMC_Version, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>USC&nbsp;Version:</strong></td>\n', ...
                     '<td align="center">', USC_Version, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Software&nbsp;ID:</strong></td>\n', ...
                     '<td align="center">', sw_id, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Date&nbsp;of&nbsp;Test:</strong></td>\n', ...
                     '<td align="center">', date, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Time&nbsp;of&nbsp;Test:</strong></td>\n', ...
                     '<td align="center">', time, '</td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Total&nbsp;time&nbsp;taken&nbsp;in&nbsp;min:</strong></td>\n', ...
                     '<td align="center">', num2str(time_taken), '</td>\n', ...
                     '</tr>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n', ...
                     '</td>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n'];

   % Test Management Report Section 2
   summary_string = [summary_string ...
                     '<table>\n', ...
                     '<tbody>\n', ...
                     '<tr>\n', ...
                     '<td><a name="section2"></a>&nbsp;</td>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n', ...
                     '<table style="font-family: Arial; font-size: 10pt; color: #ffffff;" border="0" width="100%%" cellpadding="2">\n', ...
                     '<tbody>\n', ...
                     '<tr bgcolor="#ce380a">\n', ...
                     '<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>Overall&nbsp;Results</strong></span></td>\n', ...
                     '</tr>\n', ...
                     '<tr>\n', ...
                     '<td align="left">\n', ...
                     '<table style="font-family: Times New Roman; font-size: 12pt; color: #000000;" border="0" cellpadding="2">\n', ...
                     '<tbody>\n', ...
                     '<tr bgcolor="#CCD8EE">\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Category</strong></td>\n', ...
                     '<td bgcolor="#CCD8EE"><strong>Results</strong></td>\n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td><strong>Overall Pass/Fail:</strong></td>\n', ...
                     'Total_Pass_Fail                                                           \n', ...
                     '</tr>\n', ...
                     '<tr bgcolor="#EEEEEE">\n', ...
                     '<td><strong>Testcase Pass/Fail:</strong></td>\n', ...
                     'Pass_Fail                                                                 \n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n', ...
                     '</td>\n', ...
                     '</tr>\n', ...
                     '</tbody>\n', ...
                     '</table>\n'];

   %  NaN_finder = isnan(single(tc_fail_cnt));
   % a(1)="AF_output";
   % a(2)="BW_thold_Output";
   % a(3)="CFAR_Output";
   % a(4)="First_Pass_Output";
   % a(5)="Look_Proc_Output";
   % a(6)="Second_Pass_Output";
   % look_string="LRLL";

   % for i=1:6
   % b=[pwd '/' a(1) '_' look_string ];
   % tot_report_string_a(i)=strjoin(b);
   % end
   for i = 1:(tot_report_cnt - 1)
      report_string_full = tot_report_string{i};
      report_string_full = strrep(report_string_full, '\', '/');
      report_string = strsplit(report_string_full, '/');
      report_string = report_string{numel(report_string)};
      % if (NaN_finder(i) ~= 1)
      if ~strcmp(test_string(i), 'Look_Processing')
         if BB_flag == 1
            if strcmp(BB_name, test_string{i})
               copyfile([report_string_full, '/Reports/Testcases/Testcase_1.html'], ['./Reports/BB_' test_string{i} '/' testcase_dir_name  '/' report_string '.html'], 'f');
            end
         end
         movefile([report_string_full, '/Reports/Testcases/Testcase_1.html'], ['./Reports/' testcase_dir_name '/' test_string{i} '/' report_string '.html'], 'f');
         rmdir(report_string_full, 's');
         fid = fopen(['./Reports/' testcase_dir_name '/' test_string{i} '/' report_string '.html'], 'r');
         f = fread(fid, '*char');
         f = strrep(f', ['T' 'e' 's' 't' 'c' 'a' 's' 'e' '&' 'n' 'b' 's' 'p' ';' '1'], strsplit(report_string, ''));
         f = strrep(f', '%', '%%');
         fclose(fid);

         fid = fopen(['./Reports/' testcase_dir_name '/' test_string{i} '/' report_string '.html'], 'w');
         fprintf(fid, f{1});
         fclose(fid);

         if BB_flag == 1
            if strcmp(BB_name, test_string{i})
               fid = fopen(['./Reports/BB_' test_string{i} '/', testcase_dir_name  '/' report_string '.html'], 'r');
               f = fread(fid, '*char');
               f = strrep(f', ['T' 'e' 's' 't' 'c' 'a' 's' 'e' '&' 'n' 'b' 's' 'p' ';' '1'], strsplit(report_string, ''));
               f = strrep(f', '%', '%%');
               fclose(fid);
               fid = fopen(['./Reports/BB_' test_string{i} '/', testcase_dir_name  '/' report_string '.html'], 'w');
               fprintf(fid, f{1});
               fclose(fid);
            end
         end

      else
         % Move folder containing .fig and .jpeg files

         if BB_flag == 1
            if strcmp(BB_name, test_string{i})
               copyfile(report_string_full, ['./Reports/BB_' test_string{i} '/' testcase_dir_name '/' report_string], 'f');
            end
         end
         movefile(report_string_full, ['./Reports/' testcase_dir_name '/' test_string{i} '/' report_string], 'f');

         % Create html for look processing outputs
         html_string = ['<head><title>' report_string '</title></head><div align="middle"><img src="https://www.underconsideration.com/brandnew/archives/aptiv_logo.png"alt="Aptiv Logo" style="width:342px;height:48px;"></div>\n'];
         html_string = strcat(html_string, '<table border="0" width="100%%" cellpadding="2">\n');
         html_string = strcat(html_string, '<tbody>\n');
         html_string = strcat(html_string, '<tr bgcolor="#ce380a">\n');
         html_string = strcat(html_string, ['<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>' report_string '</strong></td>\n']);
         html_string = strcat(html_string, '</tr>\n');
         html_string = strcat(html_string, '<tr bgcolor="#ffffff">\n');
         html_string = strcat(html_string, ['<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #000000;"><strong>BB Version: ' BB_version_Af '</strong></td>\n']);
         html_string = strcat(html_string, '</tr>\n');
         html_string = strcat(html_string, '<td>\n');
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/RFFT_Spec_vs_Mex.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/RFFT_Spec_vs_Embed.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/RFFT_Mex_vs_Embed.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/DFFT_Spec_vs_mex.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/DFFT_Spec_vs_Embed.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/DFFT_Mex_vs_Embed.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/NCI_Spec_vs_Mex.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/NCI_Spec_vs_Embed.jpg">\n']);
         html_string = strcat(html_string, ['<img style="border:2px solid black;", src="./' report_string '/NCI_Mex_vs_Embed.jpg">\n']);

         html_string = strcat(html_string, '</td>');
         html_string = strcat(html_string, '</tbody>');
         html_string = strcat(html_string, '</table>');
         fid = fopen(['./Reports/' testcase_dir_name '/' test_string{i} '/' report_string '.html'], 'w+');
         fprintf(fid, html_string);
         fclose(fid);
         % Plain text version for individual BB reports is not generated

         if BB_flag == 1
            if strcmp(BB_name, test_string{i})
               fid = fopen(['./Reports/BB_' test_string{i} '/', testcase_dir_name  '/' report_string '.html'], 'w+');
               fprintf(fid, html_string);
               fclose(fid);
               % Plain text version for BB-specific look processing is not generated
            end
         end
      end
      %% if (NaN_finder(i) ~= 1)
      if tc_fail_cnt(i) == 0
         color = '#CCFFCC';
         pass_fail = 'PASS';
         testcase_pass = testcase_pass + 1;
         overall_fail = overall_fail + tot_fail_cnt(i);
         overall_pass = overall_pass + tot_pass_cnt(i);
      else
         color = '#FF9292';
         pass_fail = 'FAIL';
         testcase_fail = testcase_fail + 1;
         overall_fail = overall_fail + tot_fail_cnt(i);
         overall_pass = overall_pass + tot_pass_cnt(i);
      end

      % Create pass fail table
      if loop_cnt == 0
         testcase_cnt = testcase_cnt + 1;
         if af_Testing == 1
            loop_cnt = 1;
         else
            loop_cnt = tot_BBs;
         end
         summary_string = [summary_string ...
                           '<table>\n', ...
                           '<tbody>\n', ...
                           '<tr>\n', ...
                           '<td><a name="section3"></a>&nbsp;</td>\n', ...
                           '</tr>\n', ...
                           '</tbody>\n', ...
                           '</table>\n', ...
                           '<table border="0" width="100%%" cellpadding="2">\n', ...
                           '<tbody>\n', ...
                           '<tr bgcolor="#ce380a">\n', ...
                           '<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>Cycle ' num2str(testcase_cnt) '</strong></td>\n', ...
                           '</tr>\n', ...
                           '<tr>\n', ...
                           '<td>\n', ...
                           '<table border="0" cellpadding="2">\n', ...
                           '<tbody>\n', ...
                           '<tr bgcolor="#CCD8EE"><td bgcolor="#CCD8EE"><strong>Testcase&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</strong></td>\n', ...
                           '<td bgcolor="#CCD8EE"><strong>Results&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</strong></td>\n', ...
                           '<td bgcolor="#CCD8EE"><strong>Pass/Fail</strong></td>\n', ...
                           '</tr>\n'];

      end
      if BB_flag == 1
         if strcmp(BB_name, test_string{i})
            if loop_cnt_BB == 0
               loop_cnt_BB = (tot_report_cnt - 1) / tot_BBs;
               if count_BB == 1
                  summary_string_BB = [summary_string_BB ...
                                       '<table border="0" width="100%%" cellpadding="2">\n', ...
                                       '<tbody>\n', ...
                                       '<tr bgcolor="#ce380a">\n', ...
                                       '<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>' testcase_dir_name '</strong></td>\n', ...
                                       '</tr>\n', ...
                                       '<tr>\n', ...
                                       '<td>\n', ...
                                       '<table border="0" cellpadding="2">\n', ...
                                       '<tbody>\n', ...
                                       '<tr bgcolor="#CCD8EE"><td bgcolor="#CCD8EE"><strong>Testcase&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</strong></td>\n', ...
                                       '<td bgcolor="#CCD8EE"><strong>Results&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</strong></td>\n', ...
                                       '<td bgcolor="#CCD8EE"><strong>Pass/Fail</strong></td>\n', ...
                                       '</tr>\n'];
               else
                  fid_BB = fopen(['./Reports/BB_' BB_name '/',  BB_name '_Summary.html'], 'r');
                  f1 = fread(fid_BB, '*char');
                  f1 = strrep(f1', '%', '%%');
                  fclose(fid_BB);
                  summary_string_BB = ['<table border="0" width="100%%" cellpadding="2">\n', ...
                                       '<tbody>\n', ...
                                       '<tr bgcolor="#ce380a">\n', ...
                                       '<td align="left"><span style="font-family: Arial; font-size: 14pt; color: #ffffff;"><strong>' testcase_dir_name '</strong></td>\n', ...
                                       '</tr>\n', ...
                                       '<tr>\n', ...
                                       '<td>\n', ...
                                       '<table border="0" cellpadding="2">\n', ...
                                       '<tbody>\n', ...
                                       '<tr bgcolor="#CCD8EE"><td bgcolor="#CCD8EE"><strong>Testcase&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</strong></td>\n', ...
                                       '<td bgcolor="#CCD8EE"><strong>Results&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</strong></td>\n', ...
                                       '<td bgcolor="#CCD8EE"><strong>Pass/Fail</strong></td>\n', ...
                                       '</tr>\n'];

               end
            end
         end
      end

      summary_string = [summary_string, '<tr bgcolor="#EEEEEE">\n<td><a href="./' test_string{i} '/' report_string '.html">' report_string '</a></td>\n<td>', num2str(tot_pass_cnt(i)), ' / ', num2str(tot_pass_cnt(i) + tot_fail_cnt(i)), '</td><td bgcolor="', color, '">', pass_fail, '</td></tr>\n'];

      if BB_flag == 1
         if strcmp(BB_name, test_string{i})
            summary_string_BB = [summary_string_BB, '<tr bgcolor="#EEEEEE">\n<td><a href="./' testcase_dir_name  '/' report_string '.html">' report_string '</a></td>\n<td>', num2str(tot_pass_cnt(i)), ' / ', ...
                                 num2str(tot_pass_cnt(i) + tot_fail_cnt(i)), '</td><td bgcolor="', color, '">', pass_fail, '</td></tr>\n'];
         end
      end
      loop_cnt = loop_cnt - 1;
      if BB_flag == 1
         if strcmp(BB_name, test_string{i})
            loop_cnt_BB = loop_cnt_BB - 1;
         end
      end
   end

   if BB_flag == 1
      fid_BB = fopen(['./Reports/BB_' BB_name '/',  BB_name '_Summary.html'], 'w+');
      if count_BB ~= 1
         fprintf(fid_BB, f1);
      end
      fprintf(fid_BB, summary_string_BB);
      fclose(fid_BB);
   end

   summary_string = [summary_string, '</tbody>\n</table>\n</td>\n</tr>\n</tbody>\n</table>'];
   summary_string = strcat(summary_string, '');
   fid = fopen(['./Reports/' testcase_dir_name '/Integration_Test_Summary.html'], 'w+');
   fprintf(fid, summary_string);
   fclose(fid);
   % Insert pass/fail counts into HTML
   HTML_Insert(['./Reports/' testcase_dir_name '/Integration_Test_Summary.html'], overall_pass, overall_fail, 0, 0, 'Total_Pass_Fail');
   HTML_Insert(['./Reports/' testcase_dir_name '/Integration_Test_Summary.html'], testcase_pass, testcase_fail, 0, 0, 'Pass_Fail');
   % Re-read modified HTML so text export includes injected counts
   fid = fopen(['./Reports/' testcase_dir_name '/Integration_Test_Summary.html'], 'r');
   updated_html = fread(fid, '*char')';
   fclose(fid);
   summary_plain = html_to_structured_text(updated_html);
   fid_txt = fopen(['./Reports/' testcase_dir_name '/Integration_Test_Summary.txt'], 'w+');
   fprintf(fid_txt, '%s', summary_plain);
   fclose(fid_txt);
   % Return results to RunTestIntegration
   varargout{1} = overall_pass;
   varargout{2} = overall_fail;
   varargout{3} = testcase_pass;
   varargout{4} = testcase_fail;
end

% Helper: structured tabular text export (filters TOC/nav and normalizes key:value pairs)
function plain = html_to_structured_text(html)
   if iscell(html)
      html = html{1};
   end
   src = html;
   % Extract headings and remove any Table of Contents entries
   headings = regexp(src, '<h[1-4][^>]*>(.*?)</h[1-4]>', 'tokens');
   heading_lines = cellfun(@(c) html_clean(c{1}), headings, 'UniformOutput', false);
   heading_lines = heading_lines(~cellfun(@(x) isempty(x) || contains(lower(x), 'table of contents'), heading_lines));
   % Parse table rows
   rowTokens = regexp(src, '<tr[^>]*>(.*?)</tr>', 'tokens');
   lines = {};
   for r = 1:numel(rowTokens)
      rowHtml = rowTokens{r}{1};
      % Skip navigation/TOC style rows with multiple links
      if length(regexp(rowHtml, 'href="', 'once')) > 1
         continue
      end
      cellTokens = regexp(rowHtml, '<td[^>]*>(.*?)</td>', 'tokens');
      if isempty(cellTokens)
         continue
      end
      cells = cellfun(@(c) html_clean(c{1}), cellTokens, 'UniformOutput', false);
      cells = cells(~cellfun(@(x) isempty(strtrim(x)), cells));
      if isempty(cells)
         continue
      end
      % Normalize into key: value pairs when possible
      formatted = {};
      i = 1;
      while i <= numel(cells)
         if i < numel(cells) && ~contains(cells{i + 1}, ':')
            key = strtrim(cells{i});
            val = strtrim(cells{i + 1});
            % Special case: suppress colon for "Category Results" and "Testcase Results"
            if (strcmpi(key, 'Category') || strcmpi(key, 'Testcase')) && strcmpi(val, 'Results')
               formatted{end + 1} = sprintf('%s %s', key, val); %#ok<AGROW>
            elseif endsWith(key, ':')
               % Avoid double colon if key already ends with ':'
               formatted{end + 1} = sprintf('%s %s', key, val); %#ok<AGROW>
            else
               formatted{end + 1} = sprintf('%s: %s', key, val); %#ok<AGROW>
            end
            i = i + 2;
         else
            formatted{end + 1} = strtrim(cells{i}); %#ok<AGROW>
            i = i + 1;
         end
      end
      lines{end + 1} = strjoin(formatted, '\t'); %#ok<AGROW>
   end
   if isempty(lines)
      plain = html_flat_clean(src);
      return
   end
   if ~isempty(heading_lines)
      lines = [heading_lines(:); lines(:)];
   end
   dedup = {};
   for k = 1:numel(lines)
      if k == 1 || ~strcmp(lines{k}, lines{k - 1})
         dedup{end + 1} = lines{k}; %#ok<AGROW>
      end
   end
   % Remove raw URLs
   dedup = cellfun(@(x) regexprep(x, 'https?://\S+', ''), dedup, 'UniformOutput', false);
   % Post-process to drop Table Of Contents related lines and enforce single header
   dropPatterns = { 'Table Of Contents', 'Configuration Data Overall Results Testcase Results'};
   keep = true(size(dedup));
   for p = 1:numel(dropPatterns)
      keep = keep & ~contains(dedup, dropPatterns{p});
   end
   % Keep 'Configuration Data' so we can position it explicitly
   % Drop any line starting with 'Testcase Summary'
   keep = keep & ~cellfun(@(x) startsWith(strtrim(x), 'Testcase Summary'), dedup);
   filtered = dedup(keep);
   % Remove any existing occurrence of header to avoid duplication
   filtered = filtered(~cellfun(@(x) strcmp(strtrim(x), 'Overall Testcase Results'), filtered));
   % Build output with required blank lines: one after header, one before 'Overall Results', one before each 'Cycle'
   outputLines = {};
   outputLines{end + 1} = 'Overall Testcase Results';
   outputLines{end + 1} = ''; % blank line after header
   insertedConfigHeader = false;
   for idx = 1:numel(filtered)
      ln = strtrim(filtered{idx});
      % Insert 'Configuration Data' immediately before the "This report includes data for:" line if not already present
      if ~insertedConfigHeader && strcmpi(ln, 'This report includes data for:')
         % Ensure preceding line isn't already the header
         if isempty(outputLines) || ~strcmp(strtrim(outputLines{end}), 'Configuration Data')
            outputLines{end + 1} = 'Configuration Data';
         end
         insertedConfigHeader = true;
      end
      if contains(ln, 'Overall Results')
         if ~isempty(outputLines) && ~isempty(outputLines{end})
            outputLines{end + 1} = ''; % gap before Overall Results section
         end
      elseif startsWith(ln, 'Cycle ')
         if ~isempty(outputLines) && ~isempty(outputLines{end})
            outputLines{end + 1} = ''; % gap before each cycle header
         end
      end
      outputLines{end + 1} = filtered{idx}; %#ok<AGROW>
   end
   % Final join
   plain = strjoin(outputLines, sprintf('\n'));
   % Post-replace any lingering colon patterns (defensive)
   plain = regexprep(plain, '(^|\n)Category: Results', '$1Category Results');
   plain = regexprep(plain, '(^|\n)Testcase: Results', '$1Testcase Results');
end

% Clean inner HTML fragment (remove tags/entities, normalize spaces)
function t = html_clean(fragment)
   t = regexprep(fragment, '<[^>]+>', '');
   t = strrep(t, '&nbsp;', ' ');
   t = strrep(t, '&amp;', '&');
   t = strrep(t, '&lt;', '<');
   t = strrep(t, '&gt;', '>');
   t = strrep(t, '&quot;', '"');
   t = strrep(t, '&#39;', '''');
   t = regexprep(t, '[ \t\n\r]+', ' ');
   t = strtrim(t);
end

% Flat clean fallback (single line)
function t = html_flat_clean(src)
   t = regexprep(src, '<[^>]+>', ' ');
   t = strrep(t, '&nbsp;', ' ');
   t = strrep(t, '&amp;', '&');
   t = strrep(t, '&lt;', '<');
   t = strrep(t, '&gt;', '>');
   t = strrep(t, '&quot;', '"');
   t = strrep(t, '&#39;', '''');
   t = regexprep(t, '[ \t\n\r]+', ' ');
   t = strtrim(t);
end
