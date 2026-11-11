%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: read_smc_usc_exec_spec(t32lib, timeout_in_secs)
%   Application specific function to read smc and usc information from
%   executable spec
%
% Inputs:
%   SMC provides the smc information from executable_spec
%   usc_cal provides the USC information from executable_spec
%
% Return Variables:
% Execspec_smc_val is going to return the smc of the executable_Spec
% Execspec_usc_Val is going to return the usc of the executable_spec
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Execspec_smc_val, Execspec_usc_Val] = read_smc_usc_execspec(SMC, USC)

   addpath('..\..\..\Sig_Proc\');

   Execspec_smc_val.sec_comp = SMC.Version.Workbook.major.VALUE;
   Execspec_smc_val.platform = SMC.Version.Workbook.radar_variant_id.VALUE;

   Execspec_smc_val.customer = SMC.Version.Workbook.customer_id.VALUE;
   Execspec_smc_val.version = SMC.Version.Workbook.minor.VALUE;

   Execspec_usc_Val.sec_comp = USC.USC.Header2_Info.Section_Compatibility.VALUE;
   Execspec_usc_Val.platform = USC.USC.Header2_Info.platform.VALUE;
   Execspec_usc_Val.customer = USC.USC.Header2_Info.Customer.VALUE;
   Execspec_usc_Val.version = USC.USC.Header2_Info.version.VALUE;

end
