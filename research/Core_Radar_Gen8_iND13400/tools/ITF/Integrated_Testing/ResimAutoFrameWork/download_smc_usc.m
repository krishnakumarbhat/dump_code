function download_smc_usc(WorkbookPath, variant_settings)

   if ~isstruct(variant_settings)
      variant_settings = resolve_itf_variant_settings(variant_settings, 'satellite_can');
   end

   % WORKSPACE path where SMC,USC links are maintained
   workspace_file_path = '../../../../bb.MODULE.bazel';
   % Use regex to extract URLs robustly, independent of exact line offsets in the Bazel file
   fileContent = fileread(workspace_file_path);

   smc_token = regexp(fileContent, ['"', variant_settings.smc_repo_name, '"[\s\S]*?urls\s*=\s*\[\s*"(https://[^"]+)"'], 'tokens', 'once', 'ignorecase');
   if isempty(smc_token)
      error('download_smc_usc: Could not find SMC URL for repo "%s" in %s', variant_settings.smc_repo_name, workspace_file_path);
   end
   smc_url = string(smc_token{1});

   usc_token = regexp(fileContent, ['"', variant_settings.usc_repo_name, '"[\s\S]*?urls\s*=\s*\[\s*"(https://[^"]+)"'], 'tokens', 'once', 'ignorecase');
   if isempty(usc_token)
      error('download_smc_usc: Could not find USC URL for repo "%s" in %s', variant_settings.usc_repo_name, workspace_file_path);
   end
   usc_url = string(usc_token{1});
   usc_itf_prefix = string(extract_itf_usc_prefix(char(usc_url)));

   %% delete already existing smc or usc if any
   delete(fullfile(pwd, WorkbookPath, '*'));
   delete(fullfile(pwd, '*.ptp')); % delete already existing smc or usc ptp's if any
   %% COPY SMC
   smcDownloadPath = downloadFileFromJfrog(smc_url, 'temp/');
   smc_mat_path = char(smcDownloadPath + "/matlab_files/");
   smc_ptp_path = char(smcDownloadPath + "/ptp/");
   copyfile([char(smc_mat_path) '\smc_cal*.mat'], WorkbookPath);
   copyfile([char(smc_ptp_path) '\smc_cal*.ptp'], pwd);

   %% COPY USC (ITF package only; resolve latest artifact by stable prefix)
   try
      usc_itf_url = string(resolve_latest_itf_artifact_url(char(usc_url), char(usc_itf_prefix)));
      uscDownloadPath = downloadFileFromJfrog(usc_itf_url, 'temp/');
      fprintf('Using ITF USC package: %s\n', usc_itf_url);
   catch e
      error('download_smc_usc: ITF USC package download failed: %s', e.message);
   end
   usc_mat_path = char(uscDownloadPath + "/matlab_files/");
   usc_ptp_path = char(uscDownloadPath + "/ptp/");
   copyfile([char(usc_mat_path) '\usc_cal*.mat'], WorkbookPath);
   copyfile([char(usc_ptp_path) '\usc_cal*.ptp'], pwd);

end

function prefix_out = extract_itf_usc_prefix(base_usc_url)
   [~, base_name, ~] = fileparts(base_usc_url);
   base_name = safe_urldecode(base_name);
   if contains(base_name, '_ITF_')
      itf_name = base_name;
   elseif contains(base_name, '_EDU_')
      itf_name = regexprep(base_name, '_EDU_', '_ITF_EDU_', 'once');
   else
      error('download_smc_usc: Cannot derive ITF USC name from %s', base_name);
   end

   tok = regexp(itf_name, '^(.*)_USC_', 'tokens', 'once');
   if isempty(tok)
      error('download_smc_usc: Cannot extract USC prefix from %s', itf_name);
   end
   prefix_out = tok{1};
end

function matched_url = resolve_latest_itf_artifact_url(base_usc_url, itf_prefix)
   % Base URL points to one artifact; derive parent folder and list artifacts.
   last_slash_idx = find(base_usc_url == '/', 1, 'last');
   if isempty(last_slash_idx)
      error('download_smc_usc: Invalid USC URL: %s', base_usc_url);
   end
   parent_url = base_usc_url(1:last_slash_idx - 1);

   % Convert artifact URL into Artifactory storage API URL.
   artifactory_tag = '/artifactory/';
   artifactory_idx = strfind(parent_url, artifactory_tag);
   if isempty(artifactory_idx)
      error('download_smc_usc: Unsupported JFrog URL format: %s', parent_url);
   end
   split_idx = artifactory_idx(1) + length(artifactory_tag) - 1;
   server_root = parent_url(1:split_idx);
   repo_path = parent_url(split_idx + 1:end);

   list_url = [server_root 'api/storage/' repo_path '?list&deep=0&listFolders=0'];
   options = get_jfrog_weboptions();

   try
      list_resp = webread(list_url, options);
   catch e
      error('download_smc_usc: Failed to list USC artifacts from JFrog: %s', e.message);
   end

   if ~isfield(list_resp, 'files') || isempty(list_resp.files)
      error('download_smc_usc: No USC artifacts found under %s', parent_url);
   end

   best_name = '';
   best_time = '';
   for i = 1:numel(list_resp.files)
      entry = list_resp.files(i);
      if ~isfield(entry, 'uri')
         continue
      end
      fname = string(entry.uri);
      if startsWith(fname, '/')
         fname = extractAfter(fname, 1);
      end

      fname_decoded = string(safe_urldecode(char(fname)));
      if (startsWith(fname, itf_prefix) || startsWith(fname_decoded, itf_prefix)) && endsWith(fname, '.zip')
         entry_time = "";
         if isfield(entry, 'lastModified')
            entry_time = string(entry.lastModified);
         end
         if strlength(best_name) == 0 || entry_time > best_time
            best_name = fname;
            best_time = entry_time;
         end
      end
   end

   if strlength(best_name) == 0
      error('download_smc_usc: No ITF USC artifact matches prefix "%s" under %s', itf_prefix, parent_url);
   end

   matched_url = [parent_url '/' char(best_name)];
end

function options = get_jfrog_weboptions()
   netrcFile = char(java.lang.System.getProperty('user.home')) + "/.netrc";

   persistent allInfoFound
   persistent jfrogUsername
   persistent jfrogPassword
   if isempty(allInfoFound)
      allInfoFound = false;
      jfrogUsername = '';
      jfrogPassword = '';
   end

   if ~allInfoFound
      if isfile(netrcFile)
         netrc = readtable(netrcFile, 'FileType', 'delimitedtext', 'ReadRowNames', false, 'ReadVariableNames', false);
         for row = 1:size(netrc, 1)
            if contains(netrc{row, 1}, 'machine')
               machine = netrc{row, 2};
               if strcmpi(machine, 'jfrog.asux.aptiv.com')
                  rowLoopIdx = 0;
                  while ~allInfoFound
                     for column = 1:width(netrc)
                        if contains(netrc{row + rowLoopIdx, column}, 'login')
                           jfrogUsername = string(netrc{row + rowLoopIdx, column + 1});
                        elseif contains(netrc{row + rowLoopIdx, column}, 'password')
                           jfrogPassword = string(netrc{row + rowLoopIdx, column + 1});
                        end
                        if (~(isempty(jfrogUsername))) && (~(isempty(jfrogPassword)))
                           allInfoFound = true;
                           break
                        end
                     end
                     rowLoopIdx = rowLoopIdx + 1;
                     if ((row + rowLoopIdx) > height(netrc)) || contains(netrc{row + rowLoopIdx, 1}, 'machine')
                        break
                     end
                  end
               end
            end
            if allInfoFound
               break
            end
         end
      end
   end

   while ~allInfoFound
      prompt = ["netID:" "JFrog API Key:"];
      title = "Credentials needed for JFrog";
      answer = inputdlg(prompt, title, [1, 60], {jfrogUsername, jfrogPassword});

      if ~isempty(answer)
         jfrogUsername = answer{1};
         jfrogPassword = answer{2};
      else
         error('JFrog credentials required.');
      end

      if (~(jfrogUsername == "")) && (~(jfrogPassword == ""))
         allInfoFound = true;
         break
      end
   end

   options = weboptions('Username', jfrogUsername, 'Password', jfrogPassword);
end

function out = safe_urldecode(in)
   try
      out = urldecode(in);
   catch
      out = in;
   end
end
