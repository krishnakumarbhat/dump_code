% Name: match_detect()
% match_detect() function processes two structures (struct1 and struct2),along with BB name and performs some kind of matching or comparison
% to ensure the data is aligned, removing any uncommon or misleading information before producing a report (like in HTML format).
%
% INPUTS:
%    struct1
%    struct2
%    BB name
%    enable flag
%    debug_signal_1 - only used in second pass
%    debug_signal_2 - only used in second pass
% OUTPUTS:
%    struct1
%    struct2
%    debug_signal_1 - only used in second pass
%    debug_signal_2 - only used in second pass

function [struct1, struct2, debug_signal_1, debug_signal_2] = match_detect(struct1, struct2, BB, enable, debug_signal_1, debug_signal_2)

   m = [];
   k = [];

   % Only run matching logic when enable flag is set (normal mode, not special modes)
   % Use debug signal indices if provided, otherwise use main output indices (fallback)
   if enable && ((strcmp(BB, 'First_Pass') || strcmp(BB, 'Second_Pass')) && ~isempty(struct1) && ~isempty(struct2))
      % Determine which indices to use for matching
      if nargin >= 5 && ~isempty(debug_signal_1) && ~isempty(debug_signal_2)
         % Use debug signal indices
         use_debug = true;
         if isfield(debug_signal_1, 'rindx') && isfield(debug_signal_2, 'rindx')
            if ~isempty(debug_signal_1.rindx) && ~isempty(debug_signal_2.rindx)
               rindx_1 = debug_signal_1.rindx;
               dindx_1 = debug_signal_1.dindx;
               rindx_2 = debug_signal_2.rindx;
               dindx_2 = debug_signal_2.dindx;
               has_aindx = isfield(debug_signal_1, 'aindx') && isfield(debug_signal_2, 'aindx') && ~isempty(debug_signal_1.aindx) && ~isempty(debug_signal_2.aindx);
               if has_aindx
                  aindx_1 = debug_signal_1.aindx;
                  aindx_2 = debug_signal_2.aindx;
               end
            else
               return
            end
         else
            struct1 = struct();
            struct2 = struct();
            return
         end
      else
         % Fallback: use main output indices (for backward compatibility)
         use_debug = false;
         if isfield(struct1, 'rindx') && isfield(struct2, 'rindx')
            if ~isempty(struct1.rindx) && ~isempty(struct2.rindx)
               rindx_1 = struct1.rindx;
               dindx_1 = struct1.dindx;
               rindx_2 = struct2.rindx;
               dindx_2 = struct2.dindx;
               has_aindx = isfield(struct1, 'aindx') && isfield(struct2, 'aindx') && ~isempty(struct1.aindx) && ~isempty(struct2.aindx);
               if has_aindx
                  aindx_1 = struct1.aindx;
                  aindx_2 = struct2.aindx;
               end
            else
               return
            end
         else
            struct1 = struct();
            struct2 = struct();
            return
         end
      end

      if ~isequal(rindx_1, rindx_2) || ~isequal(dindx_1, dindx_2) || (has_aindx && ~isequal(aindx_1, aindx_2))
         chk1 = length(rindx_1);
         chk2 = length(rindx_2);
         for cnt1 = 1:chk1
            m(cnt1) = 0;
            for cnt2 = 1:chk2
               if rindx_1(cnt1) == rindx_2(cnt2) && dindx_1(cnt1) == dindx_2(cnt2) && (~has_aindx || aindx_1(cnt1) == aindx_2(cnt2))
                  m(cnt1) = cnt2;
                  break
               end
            end
         end

         for cnt1 = 1:chk2
            k(cnt1) = 0;
            for cnt2 = 1:chk1
               if rindx_1(cnt2) == rindx_2(cnt1) && dindx_1(cnt2) == dindx_2(cnt1) && (~has_aindx || aindx_1(cnt2) == aindx_2(cnt1))
                  k(cnt1) = cnt2;
                  break
               end
            end
         end

         p = find(m == 0);
         if ~isempty(p)
            m(p) = [];
            if strcmp(BB, 'First_Pass')
               struct1.rindx(p) = [];
               struct1.dindx(p) = [];
               struct1.aindx(p) = [];
               struct1.rdop_amp(p) = [];
               struct1.rbinest(p) = [];
               struct1.dbinest(p) = [];
               struct1.abinest(p) = [];
            end
            if strcmp(BB, 'Second_Pass')
               struct1.range(p) = [];
               struct1.snr(p) = [];
               struct1.range_rate(p) = [];
               struct1.below_sp_thold(p) = [];
               struct1.sp_fail_flag(p) = [];
               if use_debug
                  debug_signal_1.rindx(p) = [];
                  debug_signal_1.dindx(p) = [];
                  if has_aindx
                     debug_signal_1.aindx(p) = [];
                  end
               end
            end
         end

         p = find(k == 0);
         if ~isempty(p)
            k(p) = [];
            if strcmp(BB, 'First_Pass')
               struct2.rindx(p) = [];
               struct2.dindx(p) = [];
               struct2.aindx(p) = [];
               struct2.rdop_amp(p) = [];
               struct2.rbinest(p) = [];
               struct2.dbinest(p) = [];
               struct2.abinest(p) = [];
            end
            if strcmp(BB, 'Second_Pass')
               struct2.range(p) = [];
               struct2.range_rate(p) = [];
               struct2.snr(p) = [];
               struct2.below_sp_thold(p) = [];
               struct2.sp_fail_flag(p) = [];
               if use_debug
                  debug_signal_2.rindx(p) = [];
                  debug_signal_2.dindx(p) = [];
                  if has_aindx
                     debug_signal_2.aindx(p) = [];
                  end
               end
            end
         end

         if strcmp(BB, 'First_Pass')
            if max(k) > length(struct2.rindx)
               k = 1:length(struct2.rindx);
            end
         end

         if strcmp(BB, 'Second_Pass')
            if max(k) > length(struct2.range)
               k = 1:length(struct2.range);
            end
         end

         if strcmp(BB, 'First_Pass')
            struct2.rindx = struct2.rindx(k);
            struct2.dindx = struct2.dindx(k);
            struct2.aindx = struct2.aindx(k);
            struct2.rdop_amp = struct2.rdop_amp(k);
            struct2.rbinest = struct2.rbinest(k);
            struct2.dbinest = struct2.dbinest(k);
            struct2.abinest = struct2.abinest(k);
         end

         if strcmp(BB, 'Second_Pass')
            struct2.range = struct2.range(k);
            struct2.range_rate = struct2.range_rate(k);
            struct2.snr = struct2.snr(k);
            struct2.below_sp_thold = struct2.below_sp_thold(k);
            struct2.sp_fail_flag = struct2.sp_fail_flag(k);
            if use_debug
               debug_signal_2.rindx = debug_signal_2.rindx(k);
               debug_signal_2.dindx = debug_signal_2.dindx(k);
               if has_aindx
                  debug_signal_2.aindx = debug_signal_2.aindx(k);
               end
            end
         end

      end
   end
   disp('match detection completed');
end
