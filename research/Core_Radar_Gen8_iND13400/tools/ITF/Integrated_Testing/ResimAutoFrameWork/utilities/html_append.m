function html_append(filename, html_str)
   % HTML_APPEND  Append an HTML string to a report file.
   %   Replaces the repetitive fopen/fprintf/fclose pattern used throughout
   %   the ITF reporting code.
   fid = fopen(filename, 'a');
   fprintf(fid, html_str);
   fclose(fid);
end
