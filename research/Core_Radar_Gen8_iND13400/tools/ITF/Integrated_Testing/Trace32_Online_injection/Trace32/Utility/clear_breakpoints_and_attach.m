%% %%%%%%%%%%%%%%%% API for Remote control Lauterbach %%%%%%%%%%%%%%%%%%%%
% Name: clear_breakpoints_and_attach(t32lib)
%   This function accepts the t32lib as an argument clears all
%   breakpoints and then attaches the R52 and BBE instances.
%
% INPUTS:
%   t32 lib
% OUTPUTS:
%   None

function status = clear_breakpoints_and_attach(t32lib)
   % Delete all the breakpoints in the R52
   status = t32_cmd(t32lib, 'Intercom R52 Break.delete');
   if 0 ~= status
      warning("Error deleting R52 breakpoints");
   end

   % Delete all the breakpoints in the BBE then send the "GO" command.
   status = t32_cmd(t32lib, 'Intercom BBE32 Break.delete');
   if 0 ~= status
      warning("Error deleting BBE breakpoints");
   end

   if 0 == status
      status = t32_cmd(t32lib, 'Intercom R52 System.Attach');
      if 0 ~= status
         warning("Could not attach the R52 instance");
      end
   end

   if 0 == status
      status = t32_cmd(t32lib, 'Intercom BBE32 System.Attach');
      if 0 ~= status
         warning("Could not attach the BBE32 instance");
      end
   end

   if 0 == status
      status = wait_for_application_start(t32lib);
      if 0 ~= status
         warning("Application did not start.");
      end
   end
end
