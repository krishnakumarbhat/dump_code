%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: power_cycle()
%   Automated power cycle (OFF → 3 s → ON). Delegates to power_supply()
%   for Python module acquisition and manual fallback handling.
%   Requires Python 3.11 recommended (MATLAB R2025b supports 3.9–3.13).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function power_cycle()
   fprintf('Power cycle: OFF -> wait -> ON\n');

   if ~power_supply('off')
      fprintf('Power cycle aborted: OFF action failed.\n');
      manual_cycle_prompt();
      return
   end

   pause(4);

   if ~power_supply('on')
      fprintf('Power cycle aborted: ON action failed.\n');
      manual_cycle_prompt();
      return
   end

   pause(4);
   fprintf('Power cycle completed.\n');
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Manual power cycle prompt — 20 s auto-continue (mirrors power_supply.m)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function manual_cycle_prompt()
   timeout = 20;
   fprintf('\n*** MANUAL ACTION REQUIRED: Power cycle the device ***\n');
   try
      hDlg = dialog('Name', 'Power Cycle — Manual Action', 'Position', [500 400 400 120]);
      uicontrol(hDlg, 'Style', 'text', 'FontSize', 11, 'HorizontalAlignment', 'center', ...
                'Position', [20 65 360 45], ...
                'String', sprintf('Power cycle the device (OFF then ON).\nAuto-continues in %ds.', timeout));
      uicontrol(hDlg, 'Style', 'pushbutton', 'String', 'Confirmed', 'FontSize', 11, ...
                'Position', [150 15 100 35], 'Callback', @(~, ~) uiresume(hDlg));
      tmr = timer('StartDelay', timeout, 'TimerFcn', @(~, ~) safe_resume(hDlg));
      start(tmr);
      uiwait(hDlg);
      stop(tmr);
      if isvalid(tmr)
         delete(tmr);
      end
      if ishandle(hDlg)
         delete(hDlg);
      end
   catch
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
