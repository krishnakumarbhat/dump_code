% This script will flash the files and run the Gen8 sensor.
% Inputs - sensor type, look type, debug mode flag, and optional skip_flash flag.
%   debug_mode: 0 = normal mode (flash + powercycle), 1 = debug mode (powercycle only, no flash)
%   skip_flash: 0 = perform flash (default), 1 = skip flashing but still powercycle
%   t32lib_in:  existing t32lib handle when skip_flash=1 (optional)
% Returns status of execution and t32lib handle

function [t32lib, status] = start_gen8_sensor(sensor_type, look_type, debug_mode, skip_flash, t32lib_in, Lite_ITF_Mode)
   parentDirectory = fileparts(pwd);

   powercycle_timeout = 20;

   if ~exist('debug_mode', 'var')
      debug_mode = 0;
   end
   if ~exist('skip_flash', 'var')
      skip_flash = 0;
   end
   if ~exist('t32lib_in', 'var')
      t32lib_in = [];
   end

   % Normal ITF mode - Start T32, flash software, wait for powercycle
   if debug_mode == 0
      if skip_flash == 0
         % First look: initialize T32 and flash
         parentDirectory = fileparts(pwd);
         fprintf(strcat("Starting ", sensor_type, " board\n"));
         t32lib = initialize_trace32(parentDirectory);
         status = flash_and_start(t32lib, parentDirectory, sensor_type);

         if status == 0
            power_cycle();
         else
            error('Flashing unsuccessful, please check the output files');
         end
      else
         % Subsequent looks: reuse t32lib, only powercycle
         fprintf(strcat("Power cycling ", sensor_type, " board for next look\n"));
         t32lib = t32lib_in;
         power_cycle();
         status = 0;
      end

   else
      % Debug mode - Only wait for powercycle
      if ~Lite_ITF_Mode
         power_cycle();
      end
      t32lib = t32_config();
      t32_init(t32lib);
      status = 0;
      debug_mode = 1;
   end
   if status == 0
      status = clear_breakpoints_and_attach(t32lib);
   end
end
