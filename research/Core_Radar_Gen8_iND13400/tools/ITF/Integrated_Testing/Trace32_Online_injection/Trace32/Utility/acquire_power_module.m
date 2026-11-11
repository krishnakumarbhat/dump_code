%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: acquire_power_module()
%   Shared utility to obtain the Python power_supply_control module with
%   resilient interpreter fallback. Returns ok=false if import fails.
%   Call signature is uniform across ON/OFF/CYCLE scripts to simplify
%   maintenance. Extend by passing extra interpreter paths as varargs.
%
% Return:
%   [ok, PowerCtrl]
%       ok        - logical indicating successful import
%       PowerCtrl  - imported Python module object (empty if not ok)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ok, PowerCtrl] = acquire_power_module(varargin)
   ok = false;
   PowerCtrl = [];

   % Allow optional extra candidate interpreter paths from caller
   extra = {};
   if ~isempty(varargin)
      extra = varargin; %#ok<NASGU>
   end

   candidates = [{
                  'C:\\Python311\\python.exe', ...
                  'C:\\Python310\\python.exe', ...
                  'C:\\Python39\\python.exe', ...
                  'C:\\Python38\\python.exe', ...
                  fullfile(getenv('USERPROFILE'), 'AppData', 'Local', 'Programs', 'Python', 'Python311', 'python.exe'), ...
                  fullfile(getenv('USERPROFILE'), 'AppData', 'Local', 'Programs', 'Python', 'Python310', 'python.exe'), ...
                  fullfile(getenv('USERPROFILE'), 'AppData', 'Local', 'Programs', 'Python', 'Python39', 'python.exe'), ...
                  fullfile(getenv('USERPROFILE'), 'AppData', 'Local', 'Programs', 'Python', 'Python38', 'python.exe')
                 }, extra];

   % Filter candidates to MATLAB-supported versions (whitelist); keep order preference
   try
      supported = select_supported_python(candidates);
   catch
      supported = candidates; % fallback if selector fails
   end

   pe = pyenv;
   if pe.Status == "Loaded"
      try
         fprintf('Using loaded Python %s. Attempting module import...\n', pe.Version);
         PowerCtrl = py.importlib.import_module('power_supply_control');
         py.importlib.reload(PowerCtrl);
         ok = true;
         return
      catch
         fprintf('Loaded Python failed to import power_supply_control. Trying fallbacks...\n');
      end
   end

   if pe.Status ~= "Loaded"
      for i = 1:numel(supported)
         pth = supported{i};
         if ~isempty(pth) && ischar(pth) && isfile(pth)
            try
               pyenv('Version', pth);
               fprintf('Loaded supported Python interpreter: %s\n', pth);
               PowerCtrl = py.importlib.import_module('power_supply_control');
               py.importlib.reload(PowerCtrl);
               ok = true;
               return
            catch e
               % Skip unsupported / failing versions silently except when informative
               if contains(e.message, 'supported version', 'IgnoreCase', true) || contains(e.message, 'Unsupported', 'IgnoreCase', true)
                  fprintf('Interpreter %s not supported by this MATLAB. Trying next...\n', pth);
               end
            end
         end
      end
   end

   if ~ok
      try
         % Final attempt with already loaded (even if partially unsupported) environment.
         PowerCtrl = py.importlib.import_module('power_supply_control');
         py.importlib.reload(PowerCtrl);
         ok = true;
         return
      catch e
         warning('Failed to establish Python environment for power supply control: %s', e.message);
         fprintf('No supported Python interpreter found.(power operations fallback).\n');
      end
   end
end
