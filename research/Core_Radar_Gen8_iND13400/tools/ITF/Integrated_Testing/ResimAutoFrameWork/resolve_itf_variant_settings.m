function variant_settings = resolve_itf_variant_settings(sensor_type, build_profile)

   if nargin < 2 || strlength(string(build_profile)) == 0
      build_profile = 'satellite_can';
   end

   sensor_key = lower(string(sensor_type));
   build_profile = lower(string(build_profile));

   switch sensor_key
      case "flr8"
         variant_settings = get_profile_settings('flr8', build_profile);
      case "srr8p"
         variant_settings = get_profile_settings('srr8p', build_profile);
      otherwise
         error('resolve_itf_variant_settings: Unsupported sensor_type "%s". Only FLR8 and SRR8P are allowed.', sensor_type);
   end

   variant_settings.sensor_type = upper(char(sensor_key));
   variant_settings.build_profile = char(build_profile);
end

function variant_settings = get_profile_settings(variant, build_profile)

   variant_settings = struct( ...
                             'variant', variant, ...
                             'variant_config', '', ...
                             'build_args', '', ...
                             'smc_repo_name', '', ...
                             'usc_repo_name', sprintf('usc_%s', variant));

   switch build_profile
      case "satellite_can"
         variant_settings.variant_config = sprintf('%s_satellite_can', variant);
         variant_settings.smc_repo_name = sprintf('smc_%s', variant);
      case "satellite_eth_high_det"
         variant_settings.variant_config = sprintf('%s_satellite_eth_high_det', variant);
         variant_settings.build_args = '--veh_com=someip';
         variant_settings.smc_repo_name = sprintf('smc_%s_high_det', variant);
      otherwise
         error('resolve_itf_variant_settings: Unsupported build_profile "%s".', build_profile);
   end
end
