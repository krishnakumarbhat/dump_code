%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% API Adds the Measurement variables for Building block modules Inputs the variables from the .csv
% Name: AddMeasurementVariables_v1()
%
% Inputs:
%   data_op_TV_out
%   ModuleHandle
%   EventIndex
%   path_to_Variable_Name_Range
%   hardware_flag
%   IPC_index
%  Outputs:
%   used_fields
%   var_data
% Return Variables description:
%   used_fields: cell that holds all of the fields in the structure
%   var_data: cell that holds the names of all Measurement variables added
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [used_fields, var_data] = AddMeasurementVariables_v1(data_op_TV_out, ModuleHandle, EventIndex, path_to_Variable_Name_Range, hardware_flag, IPC_index)

   all = readcell(path_to_Variable_Name_Range);
   mask = cellfun(@(x) any(isa(x, 'missing')), all);
   all(mask) = {NaN};

   fields = fieldnames(data_op_TV_out);    % Get all field names of structure
   cell = struct2cell(data_op_TV_out);     % Convert  structure to a cell

   % Get the amount of fields in the structure
   [num_vars, ~] = size(all);
   [num_fields, ~] = size(cell);

   found = 0;

   % Pattern for regular expression check of range and percent
   pattern = '[0-9]*.?[0-9]+';
   chk = 1;
   % create a cell to store all measurement names
   name_idx = 1;
   field_idx = 1;
   for ii = 2:num_vars
      alg_name = all{ii, 1};
      embed_name = all{ii, 2};
      embed_name = strrep(embed_name, 'IPC_c1_c2[1]', ['IPC_c1_c2[', num2str(IPC_index), ']']);
      embed_name = strrep(embed_name, 'IPC_c1_c2[0]', ['IPC_c1_c2[', num2str(IPC_index), ']']);
      range = all{ii, 3};
      percent = all{ii, 4};
      complex = all{ii, 5};
      scaling = all{ii, 6};
      scaling = strsplit(scaling, 'p');
      scaling = scaling{numel(scaling)};
      scaling = (2^str2double(scaling));
      small_dev = all{ii, 7};
      small_dev_db = all{ii, 8};
      if ischar(complex)
         complex = strsplit(complex, ',');
      end
      for jj = 1:num_fields
         if strcmp(alg_name, fields{jj})
            loc = jj;
            found = 1;
            break
         else
            found = 0;
         end
      end

      try
         [m, n] = size(cell{loc, 1});
      catch
         m = 0;
         n = 0;
      end
      num = m * n;
      if found == 0
         % do nothing
      elseif num == 1
         if ~isreal(cell{loc, 1, 1})
            s = strrep(embed_name, '[*]', '[0]');
            s = deblank(s);
            s = sprintf('%s', s);
            im_name = complex{1};
            re_name = complex{2};
            im = sprintf('%s.%s', s, im_name);
            re = sprintf('%s.%s', s, re_name);
            var_data{name_idx, 1} = im;
            var_data{name_idx + 1, 1} = re;
            var_data{name_idx, 5} = range;
            var_data{name_idx + 1, 5} = range;
            var_data{name_idx, 6} = percent;
            var_data{name_idx + 1, 6} = percent;
            var_data{name_idx, 7} = scaling;
            var_data{name_idx + 1, 7} = scaling;
            var_data{name_idx, 8} = small_dev;
            var_data{name_idx + 1, 8} = small_dev;
            var_data{name_idx, 9} = small_dev_db;
            var_data{name_idx + 1, 9} = small_dev_db;
            get_range_percent = check_tolerance(range, pattern, percent);
            if chk ~= 1
               fprintf('Measurement module %s not added.\n', im);
            else
               fprintf('Measurement module %s added for event #%d.\n', im, EventIndex - 1);
               var_data{name_idx, 2} = [m, n];
               var_data{name_idx, 3} = class(cell{loc, 1, 1});
               var_data{name_idx, 4} = 'complex';
               var_data{name_idx + 1, 2} = [m, n];
               var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
               var_data{name_idx + 1, 4} = 'complex';
               used_fields{ii - 1, 1} = alg_name;
               used_fields{field_idx, 2} = var_data{name_idx, 2};
               used_fields{field_idx, 3} = var_data{name_idx, 3};
               used_fields{field_idx, 4} = var_data{name_idx, 4};
            end

            if chk ~= 1
               fprintf('Measurement module %s not added.\n', im);
            else
               fprintf('Measurement module %s added for event #%d.\n', im, EventIndex - 1);
               var_data{name_idx, 2} = [m, n];
               var_data{name_idx, 3} = class(cell{loc, 1, 1});
               var_data{name_idx, 4} = 'complex';
               var_data{name_idx + 1, 2} = [m, n];
               var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
               var_data{name_idx + 1, 4} = 'complex';
               used_fields{ii - 1, 1} = alg_name;
               used_fields{field_idx, 2} = var_data{name_idx, 2};
               used_fields{field_idx, 3} = var_data{name_idx, 3};
               used_fields{field_idx, 4} = var_data{name_idx, 4};
            end
            name_idx = name_idx + 1;
            name_idx = name_idx + 1;
         else
            s = strrep(embed_name, '[*]', '[0]');
            s = deblank(s);
            s = sprintf('%s', s);
            var_data{name_idx, 1} = s;
            var_data{name_idx, 5} = range;
            var_data{name_idx, 6} = percent;
            var_data{name_idx, 7} = scaling;
            var_data{name_idx, 8} = small_dev;
            var_data{name_idx, 9} = small_dev_db;
            get_range_percent = check_tolerance(range, pattern, percent);

            if chk ~= 1
               fprintf('Measurement module %s not added.\n', s);
            else
               fprintf('Measurement module %s added for event #%d.\n', s, EventIndex - 1);
               var_data{name_idx, 2} = [m, n];
               var_data{name_idx, 3} = class(cell{loc, 1, 1});
               var_data{name_idx, 4} = 'real';
               used_fields{ii - 1, 1} = alg_name;
               used_fields{field_idx, 2} = var_data{name_idx, 2};
               used_fields{field_idx, 3} = var_data{name_idx, 3};
               used_fields{field_idx, 4} = var_data{name_idx, 4};
            end
            name_idx = name_idx + 1;
         end

      elseif (n == 1 && m ~= 1) || (n ~= 1 && m == 1)
         for k = 1:num
            if ~isreal(cell{loc, 1, 1})
               s = strrep(embed_name, '[*]', ['[' num2str(k - 1) ']']);
               s = deblank(s);
               s = sprintf('%s', s);
               re_name = complex{2};
               im_name = complex{1};
               im = sprintf('%s.%s', s, im_name);
               re = sprintf('%s.%s', s, re_name);
               var_data{name_idx, 1} = im;
               var_data{name_idx + 1, 1} = re;
               var_data{name_idx, 5} = range;
               var_data{name_idx + 1, 5} = range;
               var_data{name_idx, 6} = percent;
               var_data{name_idx + 1, 6} = percent;
               var_data{name_idx, 7} = scaling;
               var_data{name_idx + 1, 7} = scaling;
               var_data{name_idx, 8} = small_dev;
               var_data{name_idx + 1, 8} = small_dev;
               var_data{name_idx, 9} = small_dev_db;
               var_data{name_idx + 1, 9} = small_dev_db;
               get_range_percent = check_tolerance(range, pattern, percent);

               if chk ~= 1
                  im = sprintf('%s._%d_.im', embed_name, k - 1);
                  if hardware_flag == 1
                     chk = ml_CANapeAddMeasurementModule(ModuleHandle, im, EventIndex, 0);
                  else
                     chk = 1;
                     try
                        t32_get_symbol(ModuleHandle, im);
                     catch
                        chk = 0;
                        t32lib = t32_config();
                        t32_init(t32lib);
                     end
                  end
                  if chk ~= 1
                     fprintf('Measurement module %s not added.\n', im);
                  else
                     fprintf('Measurement module %s added for event #%d.\n', im, EventIndex - 1);
                     var_data{name_idx, 2} = [m, n];
                     var_data{name_idx, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx, 4} = 'complex';
                     var_data{name_idx + 1, 2} = [m, n];
                     var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx + 1, 4} = 'complex';
                     used_fields{ii - 1, 1} = alg_name;
                     used_fields{field_idx, 2} = var_data{name_idx, 2};
                     used_fields{field_idx, 3} = var_data{name_idx, 3};
                     used_fields{field_idx, 4} = var_data{name_idx, 4};
                  end
               else
                  fprintf('Measurement module %s added for event #%d.\n', im, EventIndex - 1);
                  var_data{name_idx, 2} = [m, n];
                  var_data{name_idx, 3} = class(cell{loc, 1, 1});
                  var_data{name_idx, 4} = 'complex';
                  var_data{name_idx + 1, 2} = [m, n];
                  var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
                  var_data{name_idx + 1, 4} = 'complex';
                  used_fields{ii - 1, 1} = alg_name;
                  used_fields{field_idx, 2} = var_data{name_idx, 2};
                  used_fields{field_idx, 3} = var_data{name_idx, 3};
                  used_fields{field_idx, 4} = var_data{name_idx, 4};
               end

               if chk ~= 1
                  re = sprintf('%s._%d_.re', embed_name, k - 1);

                  if chk ~= 1
                     fprintf('Measurement module %s not added.\n', re);
                  else
                     fprintf('Measurement module %s added for event #%d.\n', re, EventIndex - 1);
                     var_data{name_idx, 2} = [m, n];
                     var_data{name_idx, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx, 4} = 'complex';
                     var_data{name_idx + 1, 2} = [m, n];
                     var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx + 1, 4} = 'complex';
                     used_fields{ii - 1, 1} = alg_name;
                     used_fields{field_idx, 2} = var_data{name_idx, 2};
                     used_fields{field_idx, 3} = var_data{name_idx, 3};
                     used_fields{field_idx, 4} = var_data{name_idx, 4};
                  end
               else
                  fprintf('Measurement module %s added for event #%d.\n', re, EventIndex - 1);
                  var_data{name_idx, 2} = [m, n];
                  var_data{name_idx, 3} = class(cell{loc, 1, 1});
                  var_data{name_idx, 4} = 'complex';
                  var_data{name_idx + 1, 2} = [m, n];
                  var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
                  var_data{name_idx + 1, 4} = 'complex';
                  used_fields{ii - 1, 1} = alg_name;
                  used_fields{field_idx, 2} = var_data{name_idx, 2};
                  used_fields{field_idx, 3} = var_data{name_idx, 3};
                  used_fields{field_idx, 4} = var_data{name_idx, 4};
               end
               name_idx = name_idx + 1;
               name_idx = name_idx + 1;
            else
               s = strrep(embed_name, '[*]', ['[' num2str(k - 1) ']']);
               s = deblank(s);
               s = sprintf('%s', s);
               var_data{name_idx, 1} = s;
               var_data{name_idx, 5} = range;
               var_data{name_idx, 6} = percent;
               var_data{name_idx, 7} = scaling;
               var_data{name_idx, 8} = small_dev;
               var_data{name_idx, 9} = small_dev_db;
               get_range_percent = check_tolerance(range, pattern, percent);

               if chk ~= 1
                  s = sprintf('%s._%d_', embed_name, k - 1);
                  if chk ~= 1
                     fprintf('Measurement module %s not added.\n', s);
                  else
                     fprintf('Measurement module %s added for event #%d.\n', s, EventIndex - 1);
                     var_data{name_idx, 2} = [m, n];
                     var_data{name_idx, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx, 4} = 'real';
                     used_fields{ii - 1, 1} = alg_name;
                     used_fields{field_idx, 2} = var_data{name_idx, 2};
                     used_fields{field_idx, 3} = var_data{name_idx, 3};
                     used_fields{field_idx, 4} = var_data{name_idx, 4};
                  end
               else
                  fprintf('Measurement module %s added for event #%d.\n', s, EventIndex - 1);
                  var_data{name_idx, 2} = [m, n];
                  var_data{name_idx, 3} = class(cell{loc, 1, 1});
                  var_data{name_idx, 4} = 'real';
                  used_fields{ii - 1, 1} = alg_name;
                  used_fields{field_idx, 2} = var_data{name_idx, 2};
                  used_fields{field_idx, 3} = var_data{name_idx, 3};
                  used_fields{field_idx, 4} = var_data{name_idx, 4};
               end
               name_idx = name_idx + 1;
            end
         end
      else
         for k = 1:m
            for l = 1:n
               if ~isreal(cell{loc, 1, 1})
                  s = strrep(embed_name, '[*][*]', ['[' num2str(k - 1) ']' '[' num2str(l - 1) ']']);
                  % s = strrep(embed_name, '[*]', '[0]');
                  s = deblank(s);
                  s = sprintf('%s', s);
                  im_name = complex{1};
                  re_name = complex{2};
                  im = sprintf('%s.%s', s, im_name);
                  re = sprintf('%s.%s', s, re_name);
                  var_data{name_idx, 1} = im;
                  var_data{name_idx + 1, 1} = re;
                  var_data{name_idx, 5} = range;
                  var_data{name_idx + 1, 5} = range;
                  var_data{name_idx, 6} = percent;
                  var_data{name_idx + 1, 6} = percent;
                  var_data{name_idx, 7} = scaling;
                  var_data{name_idx + 1, 7} = scaling;
                  var_data{name_idx, 8} = small_dev;
                  var_data{name_idx + 1, 8} = small_dev;
                  var_data{name_idx, 9} = small_dev_db;
                  var_data{name_idx + 1, 9} = small_dev_db;
                  get_range_percent = check_tolerance(range, pattern, percent);
                  if chk ~= 1
                     fprintf('Measurement module %s not added.\n', im);
                  else
                     fprintf('Measurement module %s added for event #%d.\n', im, EventIndex - 1);
                     var_data{name_idx, 2} = [m, n];
                     var_data{name_idx, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx, 4} = 'complex';
                     var_data{name_idx + 1, 2} = [m, n];
                     var_data{name_idx + 1, 3} = class(cell{loc, 1, 1});
                     var_data{name_idx + 1, 4} = 'complex';
                     used_fields{ii - 1, 1} = alg_name;
                     used_fields{field_idx, 2} = var_data{name_idx, 2};
                     used_fields{field_idx, 3} = var_data{name_idx, 3};
                     used_fields{field_idx, 4} = var_data{name_idx, 4};
                  end
                  name_idx = name_idx + 1;
                  name_idx = name_idx + 1;
               else
                  s = strrep(embed_name, '[*][*]', ['[' num2str(k - 1) ']' '[' num2str(l - 1) ']']);
                  s = deblank(s);
                  s = sprintf('%s', s);
                  var_data{name_idx, 1} = s;
                  var_data{name_idx, 5} = range;
                  var_data{name_idx, 6} = percent;
                  var_data{name_idx, 7} = scaling;
                  var_data{name_idx, 8} = small_dev;
                  var_data{name_idx, 9} = small_dev_db;
                  fprintf('Measurement module %s added for event #%d.\n', s, EventIndex - 1);
                  get_range_percent = check_tolerance(range, pattern, percent);
                  var_data{name_idx, 2} = [m, n];
                  var_data{name_idx, 3} = class(cell{loc, 1, 1});
                  var_data{name_idx, 4} = 'real';
                  used_fields{ii - 1, 1} = alg_name;
                  used_fields{field_idx, 2} = var_data{name_idx, 2};
                  used_fields{field_idx, 3} = var_data{name_idx, 3};
                  used_fields{field_idx, 4} = var_data{name_idx, 4};
                  name_idx = name_idx + 1;
               end
            end
         end
      end
      field_idx = field_idx + 1;
   end

   try
      [m, ~] = size(used_fields);
   catch
      error('No Measurement modules were added.');
   end

   row = 1;
   while row <= m
      [m, ~] = size(used_fields);
      if isempty(used_fields{row, 1})
         used_fields(row, :) = [];
      else
         row = row + 1;
      end
   end

   [m, ~] = size(var_data);
   row = 1;
   while row <= m
      if isempty(var_data{row, 2})
         var_data(row, :) = [];
      else
         row = row + 1;
      end
      [m, ~] = size(var_data);
   end

end

%%%%%%%%%%%%%%%%%%%%%%%%%%% Local Functions%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [range, percent] = check_tolerance(range, pattern, percent)

   match = regexp(num2str(range), pattern, 'match');
   if isempty(match) && ~strcmp(num2str(range), 'NaN')
      error(['Range (', num2str(range), ') must be an number.']);
   end

   match = regexp(num2str(percent), pattern, 'match');
   if isempty(match) && ~strcmp(num2str(percent), 'NaN')
      error(['dB Range (', num2str(percent), ') must be an number.']);
   end

   if strcmp(num2str(percent), 'NaN') && strcmp(num2str(range), 'NaN')
      error('dB Range and Range columns are both blank.');
   end
end
