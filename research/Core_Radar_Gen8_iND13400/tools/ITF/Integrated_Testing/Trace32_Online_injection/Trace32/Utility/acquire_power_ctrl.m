%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Python module acquisition — R2025b compatible (Python 3.9–3.13)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ok, PowerCtrl] = acquire_power_ctrl()
   ok = false;
   PowerCtrl = [];
   last_err = "";

   % Prefer shared utility if available
   if exist('acquire_power_module', 'file') == 2
      try
         [ok, PowerCtrl] = acquire_power_module();
         if ok
            return
         end
      catch
      end
   end

   % Try already-loaded interpreter first
   pe = pyenv;
   if pe.Status == "Loaded"
      [ok, PowerCtrl, err_text] = try_import_power_ctrl();
      if ok
         return
      end
      last_err = string(err_text);
      fprintf('Active Python interpreter missing module/dependency; scanning candidates...\n');
      try
         terminate(pyenv);
      catch e
         warning(['Unable to switch Python interpreter in this MATLAB session: %s. ' ...
                  'Restart MATLAB after fixing Python packages. Last import error: %s'], ...
                 e.message, err_text);
         dependency_hint(pe, err_text);
         return
      end
   end

   % Walk candidate paths (newest-first; R2025b supports 3.9–3.13)
   base = fullfile(getenv('USERPROFILE'), 'AppData', 'Local', 'Programs', 'Python');
   candidates = [
                 {'C:\Python313\python.exe', 'C:\Python312\python.exe', ...
                  'C:\Python311\python.exe', 'C:\Python310\python.exe', 'C:\Python39\python.exe'}, ...
                 cellfun(@(v) fullfile(base, v, 'python.exe'), ...
                         {'Python313', 'Python312', 'Python311', 'Python310', 'Python39'}, ...
                         'UniformOutput', false) ...
                ];
   for i = 1:numel(candidates)
      if isfile(candidates{i})
         try
            pyenv('Version', candidates{i}, 'ExecutionMode', 'OutOfProcess');
            [ok, PowerCtrl, err_text] = try_import_power_ctrl();
            if ok
               return
            end
            last_err = string(err_text);
         catch e
            last_err = string(e.message);
         end
      end
   end

   % Last resort: module on PATH with current interpreter
   [ok, PowerCtrl, err_text] = try_import_power_ctrl();
   if ~ok
      if strlength(string(err_text)) == 0
         err_text = char(last_err);
      end
      warning('power_supply_control module not found: %s', err_text);
      dependency_hint(pyenv, err_text);
   end
end

function [ok, PowerCtrl, err_text] = try_import_power_ctrl()
   ok = false;
   PowerCtrl = [];
   err_text = '';
   try
      PowerCtrl = py.importlib.import_module('power_supply_control');
      py.importlib.reload(PowerCtrl);
      ok = true;
   catch e
      err_text = e.message;
   end
end

function dependency_hint(pe, err_text)
   txt = lower(string(err_text));
   if contains(txt, "no module named 'serial'")
      exe = "<unknown python executable>";
      try
         exe = string(pe.Executable);
      catch
      end
      fprintf(['Detected missing dependency: pyserial.\n' ...
               'Install with: "%s" -m pip install pyserial\n'], exe);
   end
end
