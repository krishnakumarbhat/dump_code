%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: read_smc_usc_mex_spec(t32lib)
%   Application specific function to read smc and usc information from
%   Mex_Spec Framework
%
% Inputs:
%   SMC provides the smc information from executable_spec
%   usc_cal provides the USC information from executable_spec
%
% Return Variables:
% Mexspec_smc_val is going to return the smc of the Mex_Spec
% Mexspec_usc_Val is going to return the usc of the Mex_Spec
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Mexspec_smc_val, Mexspec_usc_val] = read_smc_usc_mexspec(smc, usc)

   Mexspec_smc_val.sec_comp = smc.Version.Workbook.major.VALUE;
   Mexspec_smc_val.platform = smc.Version.Workbook.radar_variant_id.VALUE;
   Mexspec_smc_val.customer = smc.Version.Workbook.customer_id.VALUE;
   Mexspec_smc_val.version  = smc.Version.Workbook.minor.VALUE;

   Mexspec_usc_val.sec_comp =  usc.USC.Header2_Info.Section_Compatibility.VALUE;
   Mexspec_usc_val.platform =  usc.USC.Header2_Info.platform.VALUE;
   Mexspec_usc_val.customer =  usc.USC.Header2_Info.Customer.VALUE;
   Mexspec_usc_val.version  =  usc.USC.Header2_Info.version.VALUE;
end
