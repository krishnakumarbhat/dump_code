% status = wait_for_application_start(t32lib)
%   Wait for the application to start, as indicated by reading the IPC_D2M_Buffer[0].header.counter.
%
%   Waits for the header counter to increment by 50, indicating that the application is running. Will wait for this up to 60 seconds.
%
%  Inputs:
%   t32lib - obtained by running t32_config()
%  Outputs:
%   status - non-zero indicates an error occurred.
function [status] = wait_for_application_start(t32lib)

   frames_to_wait = uint32(50);

   t32_tries_max = 60; % Wait up to a minute for the application to start running.

   t32_tries = 1;
   doppler_count_final_value = 2^32;

   % This will disable debug outputs.
   % If there are other debug statements added - set this to 0,
   % print_update will overwrite the line, so the screen isn't overwhelmed with bin updates.
   disable_write_outputs = 1;

   last_update = 0;

   while t32_tries < t32_tries_max
      % Use the doppler complete count as indication that the application is running in a valid state.
      % If doppler complete count isn't incrementing, the software isn't running.
      [status_1, doppler_complete_count] = t32_read_mem(t32lib, 'IPC_D2M_Buffer[0].header.counter', disable_write_outputs);

      if status_1 ~= 0
         fprintf('T32 connection not established \n');
         status = 1;
         t32_tries = t32_tries_max + 1;
      else
         % Now validate that the test mode got enabled correctly.
         doppler_complete_count = typecast(doppler_complete_count, 'uint32');

         if 2^32 == double(doppler_count_final_value)  % this is out of range of doppler_complete_count values, so will only be true the first time doppler_complete_count is read.
            doppler_count_final_value = doppler_complete_count + frames_to_wait;
            fprintf('Waiting for application to start running.\n');
            pause(1);
            t32_tries = t32_tries + 1;
            status = 3;
         elseif doppler_complete_count < doppler_count_final_value % wait frames_to_wait frames before starting any ITF checks.
            last_update = print_update('Waiting for software to start - Frames processed', last_update, doppler_count_final_value - doppler_complete_count, frames_to_wait);
            pause(1);
            t32_tries = t32_tries + 1;
            status = 2;
         else
            last_update = print_update('Waiting for software to start - Frames processed', last_update, frames_to_wait, frames_to_wait);
            status = 0;
            t32_tries = t32_tries_max + 1;
         end

      end
   end
end
