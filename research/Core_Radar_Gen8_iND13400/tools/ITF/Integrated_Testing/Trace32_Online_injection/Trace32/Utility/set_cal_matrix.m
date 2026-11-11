%% This function sets the calibration matrix for the USC calibration data in the T32 environment.
% It takes in the T32 library and an enable flag. If the enable flag is set to 'true', it will set the calibration matrix values to 0 and then set specific values to 1 to create an identity matrix.
% Parameters:
%   t32lib: The T32 library object used to send commands to the T32
%   enable: A string flag that determines whether to set the calibration matrix (should be 'true' to enable)
% Returns:
%   status: The status returned from the last T32 command executed

function status = set_cal_matrix(t32lib, enable)

   if ~strcmp(enable, 'true')
      status = 0;  % No action taken, return status 0
      return
   end

   status = -1;

   status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[0][0..7] = 0', 1);
   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[1][0..7] = 0', 1);
   end
   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[2][0..7] = 0', 1);
   end
   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[3][0..7] = 0', 1);
   end

   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[0][0] = 1', 1);
   end
   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[1][2] = 1', 1);
   end
   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[2][4] = 1', 1);
   end
   if status == 0
      status = t32_cmd(t32lib, 'Var.Set USC_Cal_Data.USC_AF_Cal.k_calmat1_ctx[3][6] = 1', 1);
   end
end
