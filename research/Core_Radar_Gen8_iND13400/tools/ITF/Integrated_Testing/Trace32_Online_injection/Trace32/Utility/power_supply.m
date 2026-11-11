%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: power_supply(action)
%   Unified power supply control. Requires Python 3.11 (recommended for
%   MATLAB R2025b; supports 3.9–3.13). Install: python.org/downloads
%
%   action : 'on'/'start' | 'off'/'shutdown'
%   Returns: success (logical)
%
%   Falls back to interactive manual prompt if automation unavailable.
%   Backward-compatible wrappers: power_supply_on() / power_supply_off()
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function success = power_supply(action)
   if nargin == 0 || ~ischar(action)
      error('power_supply:InvalidArgument', 'Provide action: ''on'' or ''off''');
   end
   act = lower(strtrim(action));
   if ~ismember(act, {'on', 'start', 'off', 'shutdown'})
      error('power_supply:InvalidAction', 'Unsupported action: %s', act);
   end
   success = false;

   [ok, PowerCtrl] = acquire_power_ctrl();
   if ~ok
      manual_prompt(act);
      return
   end

   try
      power = PowerCtrl.PowerCtrl();
   catch e
      warning('Controller instantiation failed: %s');
      manual_prompt(act);
      return
   end

   % R2025b-safe COM port check (avoids string-comparison edge cases)
   if strlength(string(power.com_port)) == 0
      fprintf('No COM port detected.\n');
      manual_prompt(act);
      return
   end

   fprintf('Power supply on port: %s\n', string(power.com_port));
   success = do_switch(power, act);
end

% Backward-compatible wrappers
function success = power_supply_on()
   success = power_supply('on');
end

function success = power_supply_off()
   success = power_supply('off');
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Switch ON or OFF, read back state
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function success = do_switch(power, act)
   success = false;
   label = upper(act(1:2));  % 'ON' or 'OF'
   if contains(act, {'on', 'start'})
      label = 'ON';
   else
      label = 'OFF';
   end
   fprintf(' Switching %s...\n', label);
   try
      if strcmp(label, 'ON')
         try
            power.set_output_voltage(12.0);
            power.set_output_current(2.5);
            pause(0.2);
         catch
         end
         power.switch_on();
      else
         power.switch_off();
      end
   catch e
      warning('Switch %s failed: %s', label, e.message);
      manual_prompt(lower(label));
      return
   end
   pause(4);

   try
      status = power.get_status();
      if strcmp(label, 'ON') && ~strcmp(string(status.output_status), "Output ON")
         fprintf(' Output state did not latch ON, retrying once...\n');
         power.switch_on();
         pause(2);
         status = power.get_status();
      elseif strcmp(label, 'OFF') && ~strcmp(string(status.output_status), "Output OFF")
         fprintf(' Output state did not latch OFF, retrying once...\n');
         power.switch_off();
         pause(2);
         status = power.get_status();
      end

      fprintf(' Status: %s\n', string(status.output_status));
      if strcmp(label, 'ON') && ~strcmp(string(status.output_status), "Output ON")
         warning('Switch ON command completed but output still reports OFF.');
         return
      elseif strcmp(label, 'OFF') && ~strcmp(string(status.output_status), "Output OFF")
         warning('Switch OFF command completed but output still reports ON.');
         return
      end
   catch
   end

   try
      fprintf(' %s — Voltage: %.2fV  Current: %.2fA\n', label, ...
              double(power.get_output_voltage()), double(power.get_output_current()));
   catch
   end
   success = true;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Interactive manual fallback — 20 s auto-continue (2022a–2025b compatible)
% Uses uiwait+dialog so the timer can actually fire (input() blocks timers).
% Falls back to a console countdown if running headless.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function manual_prompt(act)
   timeout = 20;
   fprintf('\n*** MANUAL ACTION REQUIRED: Switch power supply %s ***\n', upper(act));
   try
      hDlg = dialog('Name', 'Power Supply — Manual Action', 'Position', [500 400 400 120]);
      uicontrol(hDlg, 'Style', 'text', 'FontSize', 11, 'HorizontalAlignment', 'center', ...
                'Position', [20 65 360 45], ...
                'String', sprintf('Switch power supply %s.\nAuto-continues in %ds.', upper(act), timeout));
      uicontrol(hDlg, 'Style', 'pushbutton', 'String', 'Confirmed', 'FontSize', 11, ...
                'Position', [150 15 100 35], 'Callback', @(~, ~) uiresume(hDlg));
      tmr = timer('StartDelay', timeout, 'TimerFcn', @(~, ~) safe_resume(hDlg));
      start(tmr);
      uiwait(hDlg);                             % yields to event loop — timer CAN fire
      stop(tmr);
      if isvalid(tmr)
         delete(tmr);
      end
      if ishandle(hDlg)
         delete(hDlg);
      end
   catch
      % Headless fallback: pure countdown, no blocking input()
      for i = timeout:-1:1
         fprintf('\r  Auto-continuing in %2ds... ', i);
         pause(1);
      end
      fprintf('\n');
   end
   fprintf('  Continuing.\n');
end

function safe_resume(hDlg)
   fprintf('\n  Timeout — continuing.\n');
   if ishandle(hDlg)
      uiresume(hDlg);
   end
end
