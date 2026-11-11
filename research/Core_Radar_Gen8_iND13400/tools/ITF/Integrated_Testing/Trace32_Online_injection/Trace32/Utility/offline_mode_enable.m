%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: offline_mode_enable()
%   this function is responsible for enabling the xcp variables and offline
%   mode flag
%   Return Variables:
%   status -> provides the status of the function
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [status, sw_id] = offline_mode_enable(t32lib, look_type, injection_mode)

   look_type_zero_based = look_type - 1;

   sw_id_name_data = 'Application_Version';
   [status, sw_id] = t32_read_mem(t32lib, sw_id_name_data, 1);
   sw_id = ['Version ' num2str(sw_id(9)), '.', num2str(sw_id(10)), '.', num2str(sw_id(11))];

   fprintf("Waiting for ADC offline mode to start.\n");
   t32_tries_max = 60; % Wait up to a minute for the adc offline mode to be started, once the connection to T32 is established.

   % To prevent the R52 from resetting the MIPI (and maybe later the chip), create a
   % breakpoint when the Offline_Data_Mode_Enabled_Counter is incremented.
   % NOTE - this breakpoint should not be encountered in data cube injection or ITF data collection modes.
   status = t32_cmd(t32lib, 'Intercom R52 Var.Break.Set Offline_Data_Mode_Enabled_Counter; /Write');
   if 0 ~= status
      warning("Could not set breakpoint for the R52 Offline_Data_Mode_Enabled_Counter write");
   end

   % First, force the single look type of the current test.
   t32_tries = 1;

   while t32_tries < t32_tries_max

      % Must update the look type first, otherwise the logic subtracts 1 from 0 and results in an invalid look selection.
      t32_cmd(t32lib, ['Intercom R52 var.set  XCP_Single_Look_Type = ' num2str(look_type_zero_based)]);
      t32_cmd(t32lib, 'Intercom R52 var.set XCP_Single_Look_Type_Enable = 0x55aa');

      [status_1, xcp_single_look_type_enable] = t32_read_mem(t32lib, 'XCP_Single_Look_Type_Enable', 1);
      [status_2, xcp_single_look_type] = t32_read_mem(t32lib, 'XCP_Single_Look_Type', 1);
      [status_3, current_look] = t32_read_mem(t32lib, 'Radar_Ctl_Data.this_look', 1);

      if status_1 ~= 0 || status_2 ~= 0 || status_3 ~= 0
         fprintf('T32 connection not established \n');
         status = 1;
         t32_tries = t32_tries_max + 1;
      else

         % Now validate that the test mode got enabled correctly.
         xcp_single_look_type_enable = typecast(xcp_single_look_type_enable, 'uint16');
         xcp_single_look_type = typecast(xcp_single_look_type, 'uint8');

         if (xcp_single_look_type_enable(1) ~= hex2dec('55aa')) || ...
               (xcp_single_look_type(1) ~= look_type_zero_based) || ...
               (current_look(1) ~= look_type_zero_based)
            fprintf('Force look type did not take effect - trying again.\n');
            pause(1);
            t32_tries = t32_tries + 1;
            status = 2;
         else
            status = 0;
            t32_tries = t32_tries_max + 1;
         end
      end
   end

   % Set the offline mode flag, and then check that the DSP version of the flag is set,
   % indicating that the DSP received the IPC message to enable offline mode.
   if status == 0
      t32_tries = 1;
      set_offline_mode_str = sprintf('Intercom R52 var.set Offline_Mode_Flag = %d', injection_mode);
      max_DSP_reset_timeout_str = sprintf('Intercom R52 var.set DSP_Reset_Timeout_Check = %d', 255);

      while t32_tries < t32_tries_max

         t32_cmd(t32lib, max_DSP_reset_timeout_str);
         t32_cmd(t32lib, set_offline_mode_str);
         [status, offline_mode_flag] = t32_read_mem(t32lib, 'Offline_Mode_Flag_DSP', 1);

         if status ~= 0
            fprintf('T32 connection not established \n');
            status = 1;
            t32_tries = t32_tries_max + 1;
         else
            % Now validate that the test mode got enabled correctly.
            offline_mode_flag = typecast(offline_mode_flag, 'uint32');
            if offline_mode_flag  ~= injection_mode
               t32_cmd(t32lib, 'Intercom R52 Go');

               fprintf('Offline injection mode was not successfully enabled - trying again.\n');
               pause(1);
               t32_tries = t32_tries + 1;
               status = 3;
            else
               status = 0;
               t32_tries = t32_tries_max + 1;
            end
         end
      end
   end
end
