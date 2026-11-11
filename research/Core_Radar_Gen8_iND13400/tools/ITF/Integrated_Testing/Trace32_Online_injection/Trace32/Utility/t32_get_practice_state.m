% T32EXTERN int T32_GetPracticeState(int *pPracticeState);
% class PracticeInterpreterState(enum.IntEnum):    UNKNOWN = -1    NOT_RUNNING = 0    RUNNING = 1    DIALOG_OPEN = 2
function [state] = t32_get_practice_state(t32lib, disable_print, disable_error)

   if ~exist('disable_print', 'var')
      disable_print = 0;
   end
   if ~exist('disable_error', 'var')
      disable_error = 1;
   end
   % T32EXTERN int T32_GetState ( int *pstate );

   pstate = libpointer('int32Ptr', int32(-1));

   status = calllib(t32lib, 'T32_GetPracticeState', pstate);
   errorCheck(t32lib, 'T32_GetPracticeState', status, disable_error);

   state = typecast(pstate.Value, 'int32');
   state = state(1);

   if disable_print == 0
      if state == 0
         fprintf('Practice Script Not Running!\n');
      elseif state == 1
         fprintf('Practice Script Running!\n');
      elseif state == 2
         fprintf('Practice Script Dialog Open!\n');
      else
         fprintf('Practice Script State Unknown!\n');
      end
   end

end
