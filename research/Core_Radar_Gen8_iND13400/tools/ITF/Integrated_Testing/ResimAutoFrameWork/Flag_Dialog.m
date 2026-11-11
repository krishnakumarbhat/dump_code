function runConfig = Flag_Dialog(show_dialog, runConfig)
   % Flag_Dialog Interactive startup dialog for RunTest_Integration.
   %   The dialog lets the user review the most important integration flags,
   %   edit them before launch, and continue automatically with defaults after
   %   a 30 second timeout.

   base_defaults = struct( ...
                          'run_single_look', 0, ...
                          'selected_look', 1, ...
                          'debug_mode', 0, ...
                          'offline_mode_inject', 2, ...
                          'MexEmbed_Mode', 0, ...
                          'Super_Lite_ITF', 0, ...
                          'Lite_ITF_Mode', 0, ...
                          'SpecMex_Only', 0, ...
                          'save_ADC_data', 1, ...
                          'build_flag', 0, ...
                          'clean_build', 0, ...
                          'testvec_file', '', ...
                          'sensor_type', 'FLR8', ...
                          'build_profile', 'satellite_can');

   if ~isfield(runConfig, 'build_profile')
      runConfig.build_profile = 'satellite_can';
   end
   if nargin < 2
      show_dialog = true;
      runConfig = load_saved_run_config(base_defaults);
   else
      runConfig = merge_run_config(base_defaults, runConfig);
   end

   if ~show_dialog
      return
   end

   defaults = runConfig;
   dialog_cancelled = false;

   sensor_choices = {'FLR8', 'SRR8P'};
   sensor_value = find(strcmp(sensor_choices, defaults.sensor_type), 1);
   if isempty(sensor_value)
      sensor_value = numel(sensor_choices);
   end

   build_profile_choices = {'satellite_can', 'satellite_eth_high_det'};
   build_profile_labels = {'Satellite CAN', 'Satellite ETH High Det'};
   build_profile_value = find(strcmp(build_profile_choices, defaults.build_profile), 1);
   if isempty(build_profile_value)
      build_profile_value = 1;
   end

   offline_labels_full = { ...
                          '0 - Normal MARS ADC injection', ...
                          '1 - RFFT data cube injection', ...
                          '2 - ADC data cube injection'};
   offline_values_full = [0, 1, 2];
   offline_value = find(offline_values_full == defaults.offline_mode_inject, 1);
   if isempty(offline_value)
      offline_value = numel(offline_values_full);
   end

   baseW = 760;
   baseH = 640;
   monitor_pos = get_best_monitor_position();
   monitorW = monitor_pos(3);
   monitorH = monitor_pos(4);
   figW = max(640, round(monitorW * 0.45));
   figH = max(520, round(monitorH * 0.45));
   ui_scale = min(figW / baseW, figH / baseH);
   scale = @(v) round(v * ui_scale);
   scaled_pos = @(x, y, w, h) [scale(x) scale(y) scale(w) scale(h)];
   figX = round(monitor_pos(1) + (monitorW - figW) / 2);
   figY = round(monitor_pos(2) + (monitorH - figH) / 2);
   dialog_handle = figure( ...
                          'Name', 'RunTest Integration Setup', ...
                          'NumberTitle', 'off', ...
                          'MenuBar', 'none', ...
                          'ToolBar', 'none', ...
                          'Resize', 'off', ...
                          'WindowStyle', 'modal', ...
                          'Color', [0.97 0.97 0.98], ...
                          'Position', [figX figY figW figH], ...
                          'CloseRequestFcn', @cancel_dialog);

   controls = struct();
   row_h = scale(26);
   label_x = scale(24);
   control_x = scale(320);
   label_w = scale(280);
   current_y = scale(596);

   uicontrol( ...
             'Parent', dialog_handle, ...
             'Style', 'text', ...
             'String', 'Integration setup', ...
             'FontSize', max(8, round(11 * ui_scale)), ...
             'FontWeight', 'bold', ...
             'HorizontalAlignment', 'left', ...
             'BackgroundColor', get(dialog_handle, 'Color'), ...
             'Position', scaled_pos(24, 612, 260, 20));

   uicontrol( ...
             'Parent', dialog_handle, ...
             'Style', 'text', ...
             'String', 'Review or adjust the flags before launch, then click Start now to run.', ...
             'HorizontalAlignment', 'left', ...
             'FontSize', max(8, round(9 * ui_scale)), ...
             'BackgroundColor', get(dialog_handle, 'Color'), ...
             'Position', scaled_pos(24, 592, 690, 18));

   uicontrol( ...
             'Parent', dialog_handle, ...
             'Style', 'text', ...
             'String', 'Tip: Use the defaults button to quickly restore the recommended startup configuration.', ...
             'HorizontalAlignment', 'left', ...
             'FontSize', max(7, round(8 * ui_scale)), ...
             'ForegroundColor', [0.35 0.35 0.35], ...
             'BackgroundColor', get(dialog_handle, 'Color'), ...
             'Position', scaled_pos(24, 576, 690, 16));

   current_y = add_section_header('Core execution', current_y);
   current_y = add_popup_row('Sensor type', 'sensor_type', sensor_choices, sensor_value, 'Select the vehicle variant to use for the run.', current_y);
   current_y = add_popup_row('Build profile', 'build_profile', build_profile_labels, build_profile_value, 'Select the build output and calibration flavor used by ITF.', current_y);
   current_y = add_bool_row('Debug mode', 'debug_mode', 'Keep debug mode on for easier troubleshooting.', current_y);
   current_y = add_bool_row('Run single look', 'run_single_look', 'Run only one look instead of the whole cycle.', current_y);
   current_y = add_edit_row('Selected look', 'selected_look', 'Look index to run when single-look mode is enabled.', current_y);

   current_y = current_y - 10;
   current_y = add_section_header('Test profile', current_y);
   current_y = add_popup_row('Test profile CSV', 'testvec_file', {'Loading...'}, 1, ...
                             'Select the CSV test profile that getTestProfile should run.', current_y);

   current_y = current_y - 8;
   current_y = add_section_header('Data and execution source', current_y);
   current_y = add_popup_row('Offline mode inject', 'offline_mode_inject', offline_labels_full, offline_value, 'Choose the offline injection mode: 0 = Normal MARS ADC, 1 = RFFT data cube, 2 = ADC injection.', current_y);
   current_y = add_bool_row('Lite ITF Mode', 'Lite_ITF_Mode', 'Force offline mode to 0 for Lite ITF runs.', current_y);
   current_y = add_bool_row('MexEmbed Mode', 'MexEmbed_Mode', 'Run the compact MexEmbed comparison flow.', current_y);
   current_y = add_bool_row('Super Lite ITF', 'Super_Lite_ITF', 'Enable Super Lite ITF mode before running.', current_y);
   current_y = add_bool_row('Spec vs Mex only', 'SpecMex_Only', 'Run Spec and Mex only and compare Spec vs Mex; skip the embedded/sensor path.', current_y);
   current_y = add_bool_row('Save ADC data', 'save_ADC_data', 'Store ADC data from the run.', current_y);

   current_y = current_y - 8;
   current_y = add_section_header('Build behavior', current_y);
   current_y = add_bool_row('Build flag', 'build_flag', 'Trigger a software build if required.', current_y);
   current_y = add_bool_row('Clean build', 'clean_build', 'Force a clean build before execution.', current_y);

   status_handle = uicontrol( ...
                             'Parent', dialog_handle, ...
                             'Style', 'text', ...
                             'String', 'Click Start now to run.', ...
                             'HorizontalAlignment', 'left', ...
                             'FontWeight', 'bold', ...
                             'BackgroundColor', get(dialog_handle, 'Color'), ...
                             'Position', scaled_pos(24, 24, 320, 18));

   uicontrol( ...
             'Parent', dialog_handle, ...
             'Style', 'pushbutton', ...
             'String', 'Start now', ...
             'FontWeight', 'bold', ...
             'Position', scaled_pos(555, 18, 82, 28), ...
             'Callback', @accept_dialog);

   uicontrol( ...
             'Parent', dialog_handle, ...
             'Style', 'pushbutton', ...
             'String', 'Restore defaults', ...
             'Position', scaled_pos(645, 18, 92, 28), ...
             'Callback', @restore_defaults);

   set(controls.sensor_type, 'Callback', @sync_sensor_type_state);
   set(controls.testvec_file, 'Callback', @sync_test_profile_selection_state);
   set(controls.MexEmbed_Mode, 'Callback', @sync_mex_embed_state);
   set(controls.Lite_ITF_Mode, 'Callback', @sync_lite_itf_state);
   set(controls.Super_Lite_ITF, 'Callback', @sync_super_lite_state);
   set(controls.SpecMex_Only, 'Callback', @sync_specmex_only_state);
   set(controls.clean_build, 'Callback', @sync_build_state);
   set(controls.run_single_look, 'Callback', @sync_single_look_state);
   sync_single_look_state();
   sync_sensor_type_state();
   sync_mex_embed_state();
   sync_lite_itf_state();
   sync_super_lite_state();
   sync_specmex_only_state();
   sync_build_state();
   sync_offline_mode_state();
   sync_lite_itf_lock_state();

   cleanup_obj = onCleanup(@cleanup_dialog);
   uiwait(dialog_handle);
   clear cleanup_obj;

   if isvalid(dialog_handle)
      delete(dialog_handle);
   end

   function y = add_section_header(title, y)
      uicontrol( ...
                'Parent', dialog_handle, ...
                'Style', 'text', ...
                'String', title, ...
                'HorizontalAlignment', 'left', ...
                'FontWeight', 'bold', ...
                'BackgroundColor', [0.90 0.92 0.96], ...
                'Position', scaled_pos(24, y, 700, 18));
      y = y - 22;
   end

   function y = add_bool_row(label, field_name, tooltip, y)
      uicontrol( ...
                'Parent', dialog_handle, ...
                'Style', 'text', ...
                'String', label, ...
                'HorizontalAlignment', 'left', ...
                'BackgroundColor', get(dialog_handle, 'Color'), ...
                'Position', scaled_pos(label_x, y, label_w, 20));
      controls.(field_name) = uicontrol( ...
                                        'Parent', dialog_handle, ...
                                        'Style', 'checkbox', ...
                                        'Value', logical(defaults.(field_name)), ...
                                        'TooltipString', tooltip, ...
                                        'Position', scaled_pos(control_x, y, 24, 22));
      y = y - row_h;
   end

   function y = add_dual_bool_row(label1, field_name1, tooltip1, label2, field_name2, tooltip2, y)
      half_label_w = floor(label_w * 0.48);
      first_x = label_x;
      second_x = label_x + half_label_w + scale(18);
      first_control_x = first_x + half_label_w;
      second_control_x = second_x + half_label_w;

      uicontrol( ...
                'Parent', dialog_handle, ...
                'Style', 'text', ...
                'String', label1, ...
                'HorizontalAlignment', 'left', ...
                'BackgroundColor', get(dialog_handle, 'Color'), ...
                'Position', scaled_pos(first_x, y, half_label_w, 20));
      controls.(field_name1) = uicontrol( ...
                                         'Parent', dialog_handle, ...
                                         'Style', 'checkbox', ...
                                         'Value', logical(defaults.(field_name1)), ...
                                         'TooltipString', tooltip1, ...
                                         'Position', scaled_pos(first_control_x, y, 24, 22));

      uicontrol( ...
                'Parent', dialog_handle, ...
                'Style', 'text', ...
                'String', label2, ...
                'HorizontalAlignment', 'left', ...
                'BackgroundColor', get(dialog_handle, 'Color'), ...
                'Position', scaled_pos(second_x, y, half_label_w, 20));
      controls.(field_name2) = uicontrol( ...
                                         'Parent', dialog_handle, ...
                                         'Style', 'checkbox', ...
                                         'Value', logical(defaults.(field_name2)), ...
                                         'TooltipString', tooltip2, ...
                                         'Position', scaled_pos(second_control_x, y, 24, 22));

      y = y - row_h;
   end

   function y = add_edit_row(label, field_name, tooltip, y)
      uicontrol( ...
                'Parent', dialog_handle, ...
                'Style', 'text', ...
                'String', label, ...
                'HorizontalAlignment', 'left', ...
                'BackgroundColor', get(dialog_handle, 'Color'), ...
                'Position', scaled_pos(label_x, y, label_w, 20));
      controls.(field_name) = uicontrol( ...
                                        'Parent', dialog_handle, ...
                                        'Style', 'edit', ...
                                        'String', num2str(defaults.(field_name)), ...
                                        'BackgroundColor', 'white', ...
                                        'TooltipString', tooltip, ...
                                        'HorizontalAlignment', 'left', ...
                                        'Position', scaled_pos(control_x, y, 120, 24));
      y = y - row_h;
   end

   function y = add_popup_row(label, field_name, items, value_index, tooltip, y)
      uicontrol( ...
                'Parent', dialog_handle, ...
                'Style', 'text', ...
                'String', label, ...
                'HorizontalAlignment', 'left', ...
                'BackgroundColor', get(dialog_handle, 'Color'), ...
                'Position', scaled_pos(label_x, y, label_w, 20));
      controls.(field_name) = uicontrol( ...
                                        'Parent', dialog_handle, ...
                                        'Style', 'popupmenu', ...
                                        'String', items, ...
                                        'Value', value_index, ...
                                        'TooltipString', tooltip, ...
                                        'BackgroundColor', 'white', ...
                                        'Position', scaled_pos(control_x, y, 250, 24));
      y = y - row_h;
   end

   function sync_single_look_state(~, ~)
      if logical(get(controls.run_single_look, 'Value'))
         set(controls.selected_look, 'Enable', 'on');
      else
         set(controls.selected_look, 'Enable', 'off');
      end
   end

   function sync_sensor_type_state(~, ~)
      sensor_name = sensor_choices{get(controls.sensor_type, 'Value')};
      [test_profile_labels, test_profile_paths] = list_test_profiles(sensor_name);
      if isempty(test_profile_labels)
         test_profile_labels = {'No CSV files found'};
         test_profile_paths = {''};
      end
      current_path = test_profile_paths{1};
      current_value = 1;
      desired_path = '';
      if isappdata(dialog_handle, 'selected_test_profile')
         desired_path = strtrim(getappdata(dialog_handle, 'selected_test_profile'));
      elseif isfield(defaults, 'testvec_file')
         desired_path = strtrim(defaults.testvec_file);
      end
      if ~isempty(desired_path)
         match_idx = find(strcmpi(test_profile_paths, desired_path), 1);
         if isempty(match_idx)
            [desired_folder, desired_name, desired_ext] = fileparts(desired_path);
            desired_label = [desired_name desired_ext];
            match_idx = find(strcmpi(test_profile_labels, desired_label), 1);
            if isempty(match_idx) && ~isempty(desired_folder)
               [~, desired_folder_name] = fileparts(desired_folder);
               match_idx = find(strcmpi(test_profile_labels, desired_folder_name), 1);
            end
         end
         if ~isempty(match_idx)
            current_value = match_idx;
            current_path = test_profile_paths{match_idx};
         end
      end
      if isfield(controls, 'testvec_file') && isgraphics(controls.testvec_file)
         set(controls.testvec_file, 'String', test_profile_labels, 'Value', current_value);
         setappdata(dialog_handle, 'test_profile_paths', test_profile_paths);
         setappdata(dialog_handle, 'selected_test_profile', current_path);
         sync_test_profile_selection_state();
         sync_mex_embed_state();
      end
   end

   function sync_test_profile_selection_state(~, ~)
      if ~isfield(controls, 'testvec_file') || ~isgraphics(controls.testvec_file)
         return
      end
      test_profile_paths = getappdata(dialog_handle, 'test_profile_paths');
      if isempty(test_profile_paths)
         return
      end
      selected_idx = get(controls.testvec_file, 'Value');
      if selected_idx < 1 || selected_idx > numel(test_profile_paths)
         selected_idx = 1;
      end
      setappdata(dialog_handle, 'selected_test_profile', test_profile_paths{selected_idx});
   end

   function sync_mex_embed_state(~, ~)
      sync_offline_mode_state();
      sync_test_profile_state();
      sync_save_adc_state();
   end

   function sync_super_lite_state(~, ~)
      if logical(get(controls.Super_Lite_ITF, 'Value'))
         set(controls.MexEmbed_Mode, 'Value', 1);
      else
         set(controls.MexEmbed_Mode, 'Value', 0);
      end
      sync_offline_mode_state();
      sync_test_profile_state();
      sync_save_adc_state();
   end

   function sync_specmex_only_state(~, ~)
      % When SpecMex_Only is enabled, disable conflicting modes and disable
      % sensor-related options. When disabled, restore normal state.
      if logical(get(controls.SpecMex_Only, 'Value'))
         % Force off conflicting execution modes
         set(controls.MexEmbed_Mode, 'Value', 0);
         set(controls.Super_Lite_ITF, 'Value', 0);
         set(controls.Lite_ITF_Mode, 'Value', 0);
         % Disable sensor-related controls
         set(controls.offline_mode_inject, 'Enable', 'off');
         set(controls.debug_mode, 'Enable', 'off');
         set(controls.build_flag, 'Enable', 'off');
         set(controls.clean_build, 'Enable', 'off');
      else
         % Re-enable sensor controls
         set(controls.offline_mode_inject, 'Enable', 'on');
         set(controls.debug_mode, 'Enable', 'on');
         set(controls.build_flag, 'Enable', 'on');
         set(controls.clean_build, 'Enable', 'on');
      end
      sync_offline_mode_state();
      sync_test_profile_state();
      sync_save_adc_state();
   end

   function sync_lite_itf_state(~, ~)
      if logical(get(controls.Lite_ITF_Mode, 'Value'))
         set(controls.offline_mode_inject, 'Enable', 'off');
         set(controls.debug_mode, 'Value', 1);
      else
         set(controls.offline_mode_inject, 'Enable', 'on');
         set(controls.debug_mode, 'Value', 0);
      end
      sync_offline_mode_state();
      sync_test_profile_state();
      sync_save_adc_state();
      sync_lite_itf_lock_state();
   end

   function sync_save_adc_state(~, ~)
      if logical(get(controls.Lite_ITF_Mode, 'Value')) || logical(get(controls.MexEmbed_Mode, 'Value')) || logical(get(controls.Super_Lite_ITF, 'Value'))
         setappdata(dialog_handle, 'save_adc_previous_value', get(controls.save_ADC_data, 'Value'));
         set(controls.save_ADC_data, 'Value', 0);
         set(controls.save_ADC_data, 'Enable', 'off');
      else
         set(controls.save_ADC_data, 'Enable', 'on');
         previous_value = getappdata(dialog_handle, 'save_adc_previous_value');
         if ~isempty(previous_value)
            set(controls.save_ADC_data, 'Value', logical(previous_value));
         end
      end
   end

   function sync_lite_itf_lock_state(~, ~)
      lite_mode = logical(get(controls.Lite_ITF_Mode, 'Value'));
      selectable_names = {'build_profile', 'debug_mode', 'run_single_look', 'selected_look', 'testvec_file', ...
                          'offline_mode_inject', 'MexEmbed_Mode', 'Super_Lite_ITF', ...
                          'save_ADC_data', 'build_flag', 'clean_build'};

      if lite_mode
         for idx = 1:numel(selectable_names)
            field_name = selectable_names{idx};
            if isfield(controls, field_name) && isgraphics(controls.(field_name))
               set(controls.(field_name), 'Enable', 'off');
            end
         end
         if isfield(controls, 'sensor_type') && isgraphics(controls.sensor_type)
            set(controls.sensor_type, 'Enable', 'on');
         end
         if isfield(controls, 'Lite_ITF_Mode') && isgraphics(controls.Lite_ITF_Mode)
            set(controls.Lite_ITF_Mode, 'Enable', 'on');
         end
      else
         for idx = 1:numel(selectable_names)
            field_name = selectable_names{idx};
            if isfield(controls, field_name) && isgraphics(controls.(field_name))
               set(controls.(field_name), 'Enable', 'on');
            end
         end
         if isfield(controls, 'Lite_ITF_Mode') && isgraphics(controls.Lite_ITF_Mode)
            set(controls.Lite_ITF_Mode, 'Enable', 'on');
         end
         sync_test_profile_state();
         sync_offline_mode_state();
         sync_save_adc_state();
         sync_build_state();
         sync_single_look_state();
      end
   end

   function sync_build_state(~, ~)
      if logical(get(controls.clean_build, 'Value'))
         set(controls.build_flag, 'Value', 1);
      else
         set(controls.build_flag, 'Value', 0);
      end
   end

   function sync_offline_mode_state(~, ~)
      if logical(get(controls.Lite_ITF_Mode, 'Value'))
         labels = offline_labels_full(1);
         values = offline_values_full(1);
      elseif logical(get(controls.MexEmbed_Mode, 'Value')) || logical(get(controls.Super_Lite_ITF, 'Value'))
         labels = offline_labels_full(2:3);
         values = offline_values_full(2:3);
      else
         labels = offline_labels_full;
         values = offline_values_full;
      end

      current_value = get(controls.offline_mode_inject, 'Value');
      if isempty(values)
         values = offline_values_full;
         labels = offline_labels_full;
      end

      if ~ismember(current_value, values)
         current_value = values(end);
      end

      set(controls.offline_mode_inject, 'String', labels);
      set(controls.offline_mode_inject, 'Value', find(values == current_value, 1));
      setappdata(dialog_handle, 'offline_mode_values', values);
   end

   function sync_test_profile_state(~, ~)
      if logical(get(controls.MexEmbed_Mode, 'Value')) || logical(get(controls.Lite_ITF_Mode, 'Value'))
         set(controls.testvec_file, 'Enable', 'off');
      else
         set(controls.testvec_file, 'Enable', 'on');
      end
   end

   function restore_defaults(~, ~)
      defaults = base_defaults;
      set(controls.run_single_look, 'Value', logical(base_defaults.run_single_look));
      set(controls.selected_look, 'String', num2str(base_defaults.selected_look));
      set(controls.debug_mode, 'Value', logical(base_defaults.debug_mode));
      set(controls.offline_mode_inject, 'Value', base_defaults.offline_mode_inject + 1);
      set(controls.MexEmbed_Mode, 'Value', logical(base_defaults.MexEmbed_Mode));
      set(controls.Super_Lite_ITF, 'Value', logical(base_defaults.Super_Lite_ITF));
      set(controls.Lite_ITF_Mode, 'Value', logical(base_defaults.Lite_ITF_Mode));
      set(controls.SpecMex_Only, 'Value', logical(base_defaults.SpecMex_Only));
      set(controls.save_ADC_data, 'Value', logical(base_defaults.save_ADC_data));
      set(controls.build_flag, 'Value', logical(base_defaults.build_flag));
      set(controls.clean_build, 'Value', logical(base_defaults.clean_build));
      set(controls.sensor_type, 'Value', sensor_value);
      set(controls.build_profile, 'Value', build_profile_value);
      sync_sensor_type_state();
      sync_mex_embed_state();
      sync_lite_itf_state();
      sync_super_lite_state();
      sync_specmex_only_state();
      sync_save_adc_state();
      sync_build_state();
      sync_offline_mode_state();
      sync_single_look_state();
      sync_lite_itf_lock_state();
      setappdata(dialog_handle, 'save_adc_previous_value', base_defaults.save_ADC_data);
      set(controls.save_ADC_data, 'Enable', 'on');
      set(controls.save_ADC_data, 'Value', logical(base_defaults.save_ADC_data));
      save_run_config(base_defaults);
   end

   function accept_dialog(~, ~)
      if isvalid(dialog_handle)
         runConfig = read_controls();
         save_run_config(runConfig);
         uiresume(dialog_handle);
      end
   end

   function cancel_dialog(~, ~)
      dialog_cancelled = true;
      if isvalid(dialog_handle)
         uiresume(dialog_handle);
      end
   end

   function updated = read_controls()
      updated = defaults;
      updated.run_single_look = logical(get(controls.run_single_look, 'Value'));
      selected_look_value = str2double(strtrim(get(controls.selected_look, 'String')));
      if isnan(selected_look_value) || selected_look_value < 1
         selected_look_value = defaults.selected_look;
      end
      updated.selected_look = round(selected_look_value);
      updated.debug_mode = logical(get(controls.debug_mode, 'Value'));
      updated.Lite_ITF_Mode = logical(get(controls.Lite_ITF_Mode, 'Value'));
      if updated.Lite_ITF_Mode
         updated.offline_mode_inject = 0;
      else
         offline_values = getappdata(dialog_handle, 'offline_mode_values');
         if isempty(offline_values)
            offline_values = offline_values_full;
         end
         updated.offline_mode_inject = offline_values(get(controls.offline_mode_inject, 'Value'));
      end
      updated.MexEmbed_Mode = logical(get(controls.MexEmbed_Mode, 'Value'));
      updated.Super_Lite_ITF = logical(get(controls.Super_Lite_ITF, 'Value'));
      updated.SpecMex_Only = logical(get(controls.SpecMex_Only, 'Value'));
      updated.save_ADC_data = logical(get(controls.save_ADC_data, 'Value'));
      if logical(get(controls.Lite_ITF_Mode, 'Value')) || logical(get(controls.MexEmbed_Mode, 'Value')) || logical(get(controls.Super_Lite_ITF, 'Value'))
         updated.save_ADC_data = 0;
      end
      updated.build_flag = logical(get(controls.build_flag, 'Value'));
      updated.clean_build = logical(get(controls.clean_build, 'Value'));
      if logical(get(controls.MexEmbed_Mode, 'Value')) || logical(get(controls.Lite_ITF_Mode, 'Value'))
         updated.testvec_file = '';
      else
         test_profile_paths = getappdata(dialog_handle, 'test_profile_paths');
         if isempty(test_profile_paths)
            updated.testvec_file = '';
         else
            updated.testvec_file = test_profile_paths{get(controls.testvec_file, 'Value')};
         end
      end
      updated.sensor_type = sensor_choices{get(controls.sensor_type, 'Value')};
      updated.build_profile = build_profile_choices{get(controls.build_profile, 'Value')};
   end

   function cleanup_dialog()
      if isvalid(dialog_handle)
         delete(dialog_handle);
      end
   end

   if dialog_cancelled
      runConfig = [];
   end

   function monitor_pos = get_best_monitor_position()
      monitor_positions = get(groot, 'MonitorPositions');
      if isempty(monitor_positions)
         monitor_pos = [100 100 1280 720];
         return
      end
      if size(monitor_positions, 1) == 1
         monitor_pos = monitor_positions(1, :);
         return
      end
      areas = monitor_positions(:, 3) .* monitor_positions(:, 4);
      [~, idx] = max(areas);
      monitor_pos = monitor_positions(idx, :);
   end

   function [labels, paths] = list_test_profiles(sensor_name)
      folder_path = fullfile('.', 'File', 'CSV', sensor_name);
      csv_files = dir(fullfile(folder_path, '*.csv'));
      if isempty(csv_files)
         labels = {};
         paths = {};
         return
      end
      [~, sort_idx] = sort({csv_files.name});
      csv_files = csv_files(sort_idx);
      labels = {csv_files.name};
      paths = cell(1, numel(csv_files));
      for idx = 1:numel(csv_files)
         paths{idx} = fullfile(folder_path, csv_files(idx).name);
      end
   end

   function merged = merge_run_config(base_config, override_config)
      merged = base_config;
      if isempty(override_config)
         return
      end
      override_fields = fieldnames(override_config);
      for idx = 1:numel(override_fields)
         merged.(override_fields{idx}) = override_config.(override_fields{idx});
      end
   end

   function saved_config = load_saved_run_config(base_config)
      saved_config = base_config;
      pref_group = 'RunTest_Integration';
      pref_name = 'Flag_Dialog_runConfig';
      if ispref(pref_group, pref_name)
         try
            saved_config = getpref(pref_group, pref_name);
         catch
            saved_config = base_config;
         end
      end
      saved_config = merge_run_config(base_config, saved_config);
   end

   function save_run_config(config_to_save)
      pref_group = 'RunTest_Integration';
      pref_name = 'Flag_Dialog_runConfig';
      try
         setpref(pref_group, pref_name, config_to_save);
      catch
      end
   end

end
