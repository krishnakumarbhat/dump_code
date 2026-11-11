function downloadPath = downloadFileFromJfrog(downloadUrl, destFolder)
   % downloadFileFromJfrogFunc  Downloads a file from JFrog and saves it in a
   %   temp directory. If the file is a zip file, it will unzip the file.
   %
   % Inputs:
   %   - downloadUrl: the JFrog URL to download a file from
   %   - destFolder:  the folder to put the downloaded file - if a zip file, file will be unzipped here, as well.
   %
   % Outputs:
   %   - downloadPath: the relative path to the downloaded file. If the
   %       downloaded file was a zip file, this points to the  unziped directory

   if ~isfolder(destFolder)
      mkdir(destFolder);
   end

   [~, downloadBasename, downloadExt] = fileparts(downloadUrl);
   downloadFilename = strcat(downloadBasename, downloadExt);
   downloadSavePath = strcat(destFolder, downloadFilename);

   % Get the location of the .netrc based on the system architecture
   netrcFile = char(java.lang.System.getProperty('user.home')) + "/.netrc";

   % Use some persistent storage, so that if the .netrc file is not provided,
   % we only have to ask for credentials once
   persistent allInfoFound
   persistent jfrogUsername
   persistent jfrogPassword
   if isempty(allInfoFound)
      allInfoFound = false;
      jfrogUsername = '';
      jfrogPassword = '';
   end

   if ~allInfoFound
      % If the .netrc file exists, try to read it to find a JFrog entry
      if isfile(netrcFile)
         netrc = readtable(netrcFile, 'FileType', 'delimitedtext', 'ReadRowNames', false, 'ReadVariableNames', false);
         for row = 1:size(netrc, 1)
            % machine in a .netrc file contains the element for the
            % particualar website.
            if contains(netrc{row, 1}, 'machine')
               machine = netrc{row, 2};
               if strcmpi(machine, 'jfrog.asux.aptiv.com')
                  rowLoopIdx = 0;
                  while ~allInfoFound
                     % Iterate over the columns and rows to find the
                     % username and API key
                     for column = 1:width(netrc)
                        if contains(netrc{row + rowLoopIdx, column}, 'login')
                           jfrogUsername = string(netrc{row + rowLoopIdx, column + 1});
                        elseif contains(netrc{row + rowLoopIdx, column}, 'password')
                           jfrogPassword = string(netrc{row + rowLoopIdx, column + 1});
                        end
                        % Once all info is found, break out of the loop
                        if (~(isempty(jfrogUsername))) && (~(isempty(jfrogPassword)))
                           allInfoFound = true;
                           break
                        end
                     end
                     % Keep iterating over rows until we reach the end
                     % of the file or another "machine" element is found
                     rowLoopIdx = rowLoopIdx + 1;
                     if ((row + rowLoopIdx) > height(netrc)) || contains(netrc{row + rowLoopIdx, 1}, 'machine')
                        break
                     end
                  end
               end
            end
            % Break out of the line by line read of the .netrc file if all
            % info is found, else keep looking for credentials
            if allInfoFound
               break
            end
         end
      end
   end

   % If no .netrc file is provided, or it does not include JFrog credentials,
   % prompt the user to input them manually via a GUI
   while ~allInfoFound
      prompt = ["netID:" "JFrog API Key:"];
      title = "Credentials needed for JFrog";
      answer = inputdlg(prompt, title, [1, 60], {jfrogUsername, jfrogPassword});

      % If something is provided, parse it into the username and password
      if ~isempty(answer)
         jfrogUsername = answer{1};
         jfrogPassword = answer{2};
      else
         % Else raise an error because we won't be able to download
         error("JFrog Credentials required. Please run script again.");
      end

      % Make sure that both username and API key are provided, otherwise
      % reopen the GUI via looping around
      if (~(jfrogUsername == "")) && (~(jfrogPassword == ""))
         allInfoFound = true;
         break
      end
   end

   % Set the weboptions to be passed into the websave call.
   options = weboptions('Username', jfrogUsername, 'Password', jfrogPassword);

   try
      % Try downloading from JFrog
      downloadPath = websave(downloadSavePath, downloadUrl, options);
   catch e
      % Catch the error if we're not able to for some reason.
      % Clear the persistent variables, incase they were the issues.
      % Then re-raise the original error so the user knows what happened.
      fprintf('Could not download %s\n', downloadUrl);
      clear allInfoFound;
      clear jfrogUsername;
      clear jfrogPassword;

      rethrow(e);
   end

   % If the extension is .zip, unzip the file into a directory with the name
   % of the zipfile.
   [~, ~, ext] = fileparts(downloadPath);
   if strcmp(ext, ".zip")
      downloadUnzipPath = fullfile(destFolder, downloadBasename);
      % If the directory already exists, remove it so we don't have a tainted
      % directory.
      if isfolder(downloadUnzipPath)
         rmdir(downloadUnzipPath, 's');
      end
      unzip(downloadPath, downloadUnzipPath);

      downloadPath = downloadUnzipPath;
   end
