%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Name: compare_smc_usc(Mexspec_smc_val, Mexspec_usc_val, Embed_smc_val, Embed_usc_val)
%   Application specific function to read smc and usc version from
%   executable spec software
%
% Inputs:
%  Mexspec_smc_val gives the smc value of the Mex executable spec
%  Mexspec_usc_val gives the usc value of the Mex executable spec
%  Embed_smc_val gives the smc value of the embedded software
%  Embed_usc_val gives the usc value of the embedded software
% Return Variables:
%  None
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [] = compare_smc_usc(Mexspec_smc_val, Mexspec_usc_val, Embed_smc_val, Embed_usc_val)

   if isequal(Mexspec_smc_val, Embed_smc_val)
      fprintf("\nEmbedded and Exec_spec SMC match: (%d.%d.%d.%d)\n", ...
              Embed_smc_val.sec_comp, Embed_smc_val.platform, Embed_smc_val.customer, Embed_smc_val.version);
   else
      error("\nEmbedded (%d.%d.%d.%d) andMex_spec (%d.%d.%d.%d) SMC doesnt match\n", ...
            Embed_smc_val.sec_comp, Embed_smc_val.platform, Embed_smc_val.customer, Embed_smc_val.version, ...
            Mexspec_smc_val.sec_comp, Mexspec_smc_val.platform, Mexspec_smc_val.customer, Mexspec_smc_val.version);
   end

   if isequal(Mexspec_usc_val, Embed_usc_val)
      fprintf("\nEmbedded and Exec_spec USC match: (%d.%d.%d.%d)\n", ...
              Embed_usc_val.sec_comp, Embed_usc_val.platform, Embed_usc_val.customer, Embed_usc_val.version);
   else
      error("\nEmbedded (%d.%d.%d.%d) and Exec_spec (%d.%d.%d.%d) USC doesnt match\n", ...
            Embed_usc_val.sec_comp, Embed_usc_val.platform, Embed_usc_val.customer, Embed_usc_val.version, ...
            Mexspec_usc_val.sec_comp, Mexspec_usc_val.platform, Mexspec_usc_val.customer, Mexspec_usc_val.version);
   end
end
