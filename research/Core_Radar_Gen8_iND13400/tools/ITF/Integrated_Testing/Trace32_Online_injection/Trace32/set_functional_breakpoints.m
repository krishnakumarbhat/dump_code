% set_functional_breakpoints(t32lib, offline_mode_inject)
%   This function accepts the t32lib as an argument and sets breakpoints
%   for allowing data capture through RDD and AF.
%
% INPUTS:
%   t32lib - t32 instance obtained from t32_config()
%   offline_mode_inject - select injection mode
%       0 - enable ITF data collection of ADC input from MARS
%       1 - enable radar datacube injection
%       2 - enable ADC injection
% OUTPUTS:
%   status - non-zero indicates error occurred.
function status = set_functional_breakpoints(t32lib, offline_mode_inject)

   status = t32_cmd(t32lib, 'Intercom BBE32 Break.delete');
   if 0 ~= status
      warning("Error deleting  breakpoints");
   end

   if 0 == status
      % If there were breakpoints set, then the BBE will be halted.
      % Send the GO command to release it from the breakpoint.
      status = t32_cmd(t32lib, 'Intercom BBE32 Go');
      if 0 ~= status
         warning("Could not run the BBE");
      end
   end

   if 0 == status
      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set Appl_Doppler_Rdd_Processing');
      if 0 ~= status
         warning("Could not set breakpoint for Appl_Doppler_Rdd_Processing");
      end
   end

   % For data cube injection, have to wait for breakpoint to be hit here before
   % setting the other breakpoints, so the BBE is halted and ready to process the datacube.
   % Otherwise, the other breakpoints might get hit before this breakpoint and the datacube
   % injection would be done at the wrong point, and the expected flow for ITF would be incorrect.
   % In ADC injection mode, the R52 will halt when the offline mode is updated to the BBE,
   % and the BBE will be in the ADC injection handler, blocked waiting for the
   % input ADC samples to be written to the MIPI. So, these breakpoints will not be
   % hit until the ADC injection runs and the range processing completes.
   if offline_mode_inject ~= 2
      if 0 == status
         status = t32_wait_for_bbe_breakpoint(t32lib, 120);
         if 0 ~= status
            warning("Appl_Doppler_Rdd_Processing breakpoint not hit within time frame");
         end
      end
   end

   % Set a breakpoint for the R52 to halt so the DSP doesn't get reset
   % while collecting data.
   t32_cmd(t32lib, 'Intercom R52 Var.Break.Set DSP_Skipped_Frame; /Write');

   if 0 == status
      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set SP_Post_Proc_Complete_Handler');
      if 0 ~= status
         warning("Could not set breakpoint for SP_Post_Proc_Complete_Handler");
      end
   end

   if 0 == status
      status = t32_cmd(t32lib, 'Intercom BBE32 Break.set Circular_Buffer_Update');
      if 0 ~= status
         warning("Could not set breakpoint for Circular_Buffer_Update");
      end
   end
end
