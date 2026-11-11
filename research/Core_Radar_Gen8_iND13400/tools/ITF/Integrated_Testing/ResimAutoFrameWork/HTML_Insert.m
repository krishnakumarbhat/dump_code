function HTML_Insert(filename, Pass_cnt, Fail_cnt, ExecTime, EmbedTime, control)

   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Name: HTML_Insert
   %   This function replaces the control keyword found in filename with either
   %   the amount of passes / (amount of passes + amount of fails) or with the
   %   amount of execution time.
   %
   % Return Variables:
   %   None
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

   fid = fopen(filename, 'r+');

   if fid == -1
      error(['FOPEN cannot open ', filename, '.\n']);
   end

   fseek(fid, 0, 'bof');
   tline = fgetl(fid);

   if strcmp(control, 'Pass_Fail') || strcmp(control, 'Total_Pass_Fail') || strcmp(control, 'Execution_Time') || strcmp(control, 'Embed_Time')
      while ~feof(fid) && ~strcmp(tline, control)
         tline = fgetl(fid);
         strLength = length(tline);
         tline = strtrim(tline);
         if strcmp(tline, control)
            cursorPos = ftell(fid) - (strLength + 1);
            fseek(fid, cursorPos, 'bof');
            if (Pass_cnt / (Pass_cnt + Fail_cnt)) == 1
               color = '#CCFFCC';
            else
               color = '#FF9292';
            end
            if strcmp(control, 'Execution_Time')
               fprintf(fid, '<td align="center">%.6f min</td>', ExecTime);
            elseif strcmp(control, 'Embed_Time')
               fprintf(fid, '<td align="center">%.6f min</td>', EmbedTime);
            else
               fprintf(fid, '<td align="center" bgcolor="%s">%8d&nbsp;/%8d</td>', color, Pass_cnt, Pass_cnt + Fail_cnt);
            end
         end
      end
   else
      fclose(fid);
      error('ErrorTests:convertTest', ...
            'Invaild Parameter String!\n "control" in HTML_Insert() is limited to [Pass_Fail, Total_Pass_Fail, Execution_Time]');
   end
   fclose(fid);
