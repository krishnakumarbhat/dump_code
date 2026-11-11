%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% measure_error_calc
%
% Scales inputs by data type and measures the error between them to rule out scaling
% discrepancies. Automatically selects scaling strategy based on
% scale_by_type flag and data source (LookProc vs BB).
%
% Inputs:
%   x         - First operand (Spec/Mex/Embed data)
%   y         - Second operand (Spec/Mex/Embed data)
%   scale_by_type - Scale by data type control:
%               0 = Scaling disabled:
%                   LookProc: Simple max-based scaling (x/max(abs(x)))
%                   BB: Raw delta (double conversion only)
%               1 = Scaling enabled:
%                   Config-based type-aware scaling (x / 2^bitwidth from config)
%   field_name - (Optional) Field name for config-based scaling.
%                Required when scale_by_type=1.
%                Used to detect LookProc vs BB when scale_by_type=0.
%   config_struct - (Optional) Config struct to bypass persistent cache.
%                   Pass containers.Map directly for debugging.
%   is_lookproc - (Optional) Explicitly specify if data is from LookProc module.
%                 true = Apply simple scaling when scale_by_type=0
%                 false = Apply raw delta when scale_by_type=0
%                 If not provided, auto-detects from field_name.
%
% Scaling Behavior:
%   scale_by_type=1: Config-based scaling (double(x) / 2^bitwidth)
%   scale_by_type=0, LookProc: Simple scaling (x / max(abs(x)))
%   scale_by_type=0, BB: Raw delta (double(x))
%
% Outputs:
%   error     - Linear error (x - y) after scaling
%   error_log - Error in dB (20*log10(abs(error)))
%   max_x     - Maximum absolute value in scaled x
%   max_y     - Maximum absolute value in scaled y
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [error, error_log, max_x, max_y] = measure_error_calc(x, y, scale_by_type, field_name, config_struct)
   % Default parameters
   if ~exist("scale_by_type", 'var')
      scale_by_type = 0;
   end
   if ~exist("field_name", 'var')
      field_name = '';
   end
   if ~exist("config_struct", 'var')
      config_struct = [];
   end

   % Apply scaling based on scale_by_type flag and data source

   [max_x, max_y, norm_x, norm_y] = apply_config_scaling(x, y, field_name, config_struct);

   % Calculate error metric
   error     = double(norm_x - norm_y);

   % Dynamic log guard: scale with data magnitude, with minimum floor
   data_magnitude = max(abs([norm_x(:); norm_y(:)]));
   if data_magnitude > 0
      log_guard = max(eps('double'), 1e-10 * data_magnitude);
   else
      log_guard = eps('double');
   end

   % dB error calculation depends on data source
   if scale_by_type == 1
      % Absolute error - 20*log10(abs(a - b))
      error_log = 20 * log10(abs(error) + log_guard);
   end
end

%% ========================================================================
%  SCALING STRATEGIES
%  ========================================================================

% Extract base field name from T32 embedded path
% Handles both full paths and simple names
% Examples:
%   'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.cfar_nf_est[0][0]' -> 'CFAR_NF_est'
%   'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.cfar_nf_est[0][0].re' -> 'CFAR_NF_est'
%   'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.rdd1_rbinest[*]' -> 'rbinest'
%   'range_fft_decomp' -> 'range_fft_decomp'
function base_name = extract_base_field_name(field_path)
   if isempty(field_path)
      base_name = '';
      return
   end

   % Define T32 embedded path to config name mapping
   % Format: T32 suffix -> Config key
   persistent mapping
   persistent mapping_lower  % Case-insensitive lookup
   if isempty(mapping)
      mapping = containers.Map('KeyType', 'char', 'ValueType', 'char');
      mapping_lower = containers.Map('KeyType', 'char', 'ValueType', 'char');

      % CFAR
      mapping('cfar_nf_est') = 'CFAR_NF_est';
      mapping_lower('cfar_nf_est') = 'CFAR_NF_est';
      mapping('cfar_thold') = 'CFAR_thold';
      mapping_lower('cfar_thold') = 'CFAR_thold';
      mapping('cfar_thold_xcp') = 'cfar_thold_xcp';
      mapping_lower('cfar_thold_xcp') = 'cfar_thold_xcp';

      % First Pass
      mapping('rdd1_num_detect') = 'numDetected';
      mapping_lower('rdd1_num_detect') = 'numDetected';
      mapping('rdd1_rindx') = 'rindx';
      mapping_lower('rdd1_rindx') = 'rindx';
      mapping('rdd1_dindx') = 'dindx';
      mapping_lower('rdd1_dindx') = 'dindx';
      mapping('rdd1_aindx') = 'aindx';
      mapping_lower('rdd1_aindx') = 'aindx';
      mapping('rdd1_rdop_amp') = 'rdop_amp';
      mapping_lower('rdd1_rdop_amp') = 'rdop_amp';
      mapping('rdd1_rbinest') = 'rbinest';
      mapping_lower('rdd1_rbinest') = 'rbinest';
      mapping('rdd1_dbinest') = 'dbinest';
      mapping_lower('rdd1_dbinest') = 'dbinest';
      mapping('rdd1_abinest') = 'abinest';
      mapping_lower('rdd1_abinest') = 'abinest';
      mapping('rdd1_max_per_range_bin') = 'max_per_range_bin';
      mapping_lower('rdd1_max_per_range_bin') = 'max_per_range_bin';
      mapping('rdd1_signal_thold_first_pass') = 'sig_thold_1st_pass';
      mapping_lower('rdd1_signal_thold_first_pass') = 'sig_thold_1st_pass';
      mapping('rdd1_first_pass_thold') = 'first_pass_thold';
      mapping_lower('rdd1_first_pass_thold') = 'first_pass_thold';
      mapping('rdd1_bv') = 'bv';
      mapping_lower('rdd1_bv') = 'bv';
      mapping('nci_bexp') = 'nci_bexp';
      mapping_lower('nci_bexp') = 'nci_bexp';

      % Second Pass
      mapping('rdd2_num_detect') = 'numDetected';
      mapping_lower('rdd2_num_detect') = 'numDetected';
      mapping('rdd2_range') = 'range';
      mapping_lower('rdd2_range') = 'range';
      mapping('rdd2_range_rate') = 'range_rate';
      mapping_lower('rdd2_range_rate') = 'range_rate';
      mapping('rdd2_snr') = 'snr';
      mapping_lower('rdd2_snr') = 'snr';
      mapping('rdd2_second_pass_fail_flag') = 'sp_fail_flag';
      mapping_lower('rdd2_second_pass_fail_flag') = 'sp_fail_flag';
      mapping('below_sp_thold') = 'below_sp_thold';
      mapping_lower('below_sp_thold') = 'below_sp_thold';
      mapping('rdd2_thold_2nd_pass') = 'thold_2nd_pass';
      mapping_lower('rdd2_thold_2nd_pass') = 'thold_2nd_pass';

      % BW Dependent Thresholds (SweepBW)
      mapping('bwdep_cr_resp') = 'CR_Response';
      mapping_lower('bwdep_cr_resp') = 'CR_Response';
      mapping('bwdep_sensitivity_thold') = 'Sensitivity_Threshold';
      mapping_lower('bwdep_sensitivity_thold') = 'Sensitivity_Threshold';
      mapping('bwdep_hvc_thold') = 'HVC_Threshold';
      mapping_lower('bwdep_hvc_thold') = 'HVC_Threshold';
      mapping('bwdep_mb_thold') = 'MB_Threshold';
      mapping_lower('bwdep_mb_thold') = 'MB_Threshold';

      % Look Processing - usually direct field names, not paths
      mapping('range_fft') = 'range_fft';
      mapping_lower('range_fft') = 'range_fft';
      mapping('range_fft_decomp') = 'range_fft_decomp';
      mapping_lower('range_fft_decomp') = 'range_fft_decomp';
      mapping('min_chirp_scale') = 'min_chirp_scale';
      mapping_lower('min_chirp_scale') = 'min_chirp_scale';
      mapping('dopp_fft_decomp') = 'dopp_fft_decomp';
      mapping_lower('dopp_fft_decomp') = 'dopp_fft_decomp';
      mapping('scaled_nci') = 'scaled_nci';
      mapping_lower('scaled_nci') = 'scaled_nci';
      mapping('rdop_avg_NCI') = 'rdop_avg_NCI';
      mapping_lower('rdop_avg_nci') = 'rdop_avg_NCI';
   end

   % Remove .re or .im suffix for complex numbers
   field_path = regexprep(field_path, '\.(re|im)$', '');

   % Extract the last component after the last dot, removing array indices
   % e.g., 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.cfar_nf_est[0][0]' -> 'cfar_nf_est'
   tokens = regexp(field_path, '\.([^.\[]+)', 'tokens');
   if ~isempty(tokens)
      t32_suffix = tokens{end}{1};
   else
      % No dots, might be simple field name or has array indices
      t32_suffix = regexprep(field_path, '\[.*?\]', '');
   end

   % Map T32 suffix to config key (case-insensitive)
   t32_suffix_lower = lower(t32_suffix);
   if mapping_lower.isKey(t32_suffix_lower)
      base_name = mapping_lower(t32_suffix_lower);
   elseif mapping.isKey(t32_suffix)
      base_name = mapping(t32_suffix);
   else
      % Return as-is (for LookProc fields or unmapped names)
      base_name = t32_suffix;
   end
end

% Config-based scaling: Load type from config and apply bit-width scaling
function [max_x, max_y, norm_x, norm_y] = apply_config_scaling(x, y, field_name, config_struct)
   % Load config - use provided struct or persistent cache
   if ~isempty(config_struct)
      config_cache = config_struct;
   else
      persistent config_cache_persistent
      if isempty(config_cache_persistent)
         config_cache_persistent = embed_data_types_config();
      end
      config_cache = config_cache_persistent;
   end

   % Validate field_name is provided
   if isempty(field_name)
      error('measure_error_calc:MissingFieldName', ...
            'field_name required when scale_by_type=1.');
   end

   % Extract base field name from T32 embedded path
   % e.g., 'IPC_D2M_Buffer[0].payload.rdd_stream_data.rdd_data.cfar_nf_est[0][0]' -> 'CFAR_NF_est'
   base_field_name = extract_base_field_name(field_name);

   % Fetch field configuration
   if config_cache.isKey(base_field_name)
      field_config = config_cache(base_field_name);
   elseif config_cache.isKey('_default_')
      field_config = config_cache('_default_');
   else
      error('measure_error_calc:ConfigNotFound', ...
            'Field "%s" (base: "%s") not in config and no _default_ exists.', field_name, base_field_name);
   end

   % Apply scaling if configured
   if field_config.scale_by_type
      data_type = field_config.data_type;

      % Handle 'auto' data type by introspecting actual data
      if strcmp(data_type, 'auto')
         data_type = class(x);
      end

      norm_x = scale_to_float(x, data_type);
      norm_y = scale_to_float(y, data_type);

      % Calculate max values
      max_x     = max(abs(norm_x(:)));
      max_y     = max(abs(norm_y(:)));

      % Validate scaling output
      if any(isnan(norm_x(:))) || any(isinf(norm_x(:)))
         error('measure_error_calc:InvalidScaling', ...
               'Scaling of x produced NaN/Inf values for field "%s"', base_field_name);
      end
      if any(isnan(norm_y(:))) || any(isinf(norm_y(:)))
         error('measure_error_calc:InvalidScaling', ...
               'Scaling of y produced NaN/Inf values for field "%s"', base_field_name);
      end
   else
      norm_x = double(x);
      norm_y = double(y);
      max_x     = max(abs(norm_x(:)));
      max_y     = max(abs(norm_y(:)));
   end
end

% Scale an operand to floating-point range based on config-provided type.
% Integer types are divided by 2^bitwidth, float/double inputs pass through unchanged.
% data_type comes from embed_data_types_config (e.g., 'int16', 'uint32', 'double')
function out = scale_to_float(data, data_type)
   bw = get_int_bit_width(data_type);
   if bw > 0
      out = double(data) ./ 2^bw;
   else
      out = data;
   end
end

% Return the integer bit width from config-provided type string.
% Returns 0 for float types (single, double, float) so they are not scaled.
% type_name: String from embed_data_types_config (e.g., 'int16', 'uint32', 'double')
function bw = get_int_bit_width(type_name)
   switch type_name
      case {'uint8',  'int8'}
         bw = 8;
      case {'uint16', 'int16'}
         bw = 16;
      case {'uint32', 'int32'}
         bw = 32;
      case {'uint64', 'int64'}
         bw = 64;
      otherwise
         bw = 0;  % Includes 'single', 'double', 'float', etc.
   end
end
