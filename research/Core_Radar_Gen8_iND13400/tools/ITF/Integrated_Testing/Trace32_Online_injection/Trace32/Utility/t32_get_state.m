function [state] = t32_get_state(t32lib)

   % T32EXTERN int T32_GetState ( int *pstate );

   pstate = libpointer('int32Ptr', int32(-1));

   status = calllib(t32lib, 'T32_GetState', pstate);
   errorCheck(t32lib, 'T32_GetState', status);

   state = typecast(pstate.Value, 'int32');
   state = state(1);

   if state == 0
      fprintf('\nDebug system is down!\n');
   elseif state == 1
      fprintf('\nSystem is halted!\n');
   elseif state == 2
      fprintf('\nSystem is stopped!\n');
   elseif state == 3
      fprintf('\nSystem is running!\n');
   else
      fprintf('\nSystem has Error!\n');
   end

end
