function [frame_value] = get_user_frame_index(max)

   while 1
      % Prompt the user for input with range check
      prompt = {'Select the frame number'};
      dlgtitle = 'Frame selection';
      defaultanswer = {num2str('1')}; % Default value, optional

      % Create the input dialog box
      answer = inputdlg(prompt, dlgtitle, [1 40], defaultanswer);

      % Check if the user clicked 'Cancel'
      if isempty(answer)
         disp('User canceled the input.');
         break
      else
         % Perform range check
         specific_frame_index = str2num(answer{1, 1}); % Convert the input to a number

         if ~isnan(specific_frame_index) && specific_frame_index >= 1 && specific_frame_index <= max
            disp(['Valid frame no: ' num2str(specific_frame_index)]);
            frame_value = specific_frame_index;
            break
         else
            h = msgbox(strcat('Invalid frame no. Please enter a number between 1 and', ' ', num2str(max)), 'Error');
            uiwait(h);
         end
      end
   end

end
