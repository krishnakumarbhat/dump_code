function [smc, usc] = Update_smc_usc_params(smc, usc, lookNum)

   % Add in new SMC parameters in const_params
   smc.const_params.NUM_RX_CHANNELS = smc.Configuration.BB_Configuration.NUM_RX_CHANNELS.VALUE;
   smc.const_params.NUM_TX_CHANNELS = smc.Configuration.BB_Configuration.NUM_TX_CHANNELS.VALUE;
   smc.const_params.NUM_RX_ANTENNAS = smc.Configuration.BB_Configuration.NUM_RX_ANTENNAS.VALUE;
end
