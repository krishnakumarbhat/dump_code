#include "plp_iface.h"

void PLP_OpenVigemFile(void)
{
   // Get output control from the emblib
   Emb_Lib_Output_Control_T control = get_output_control();
   reset_output_dvl_payload();

   set_can_channel_mapping(control.CUSTOMER_NAME);

   // Check if PLP sync is enabled
   if ((control.plp_algorithms == RADAR_PLP_SYNC_ENABLE))
   {
      // Call the driver to synchronize radar data
      Radar_plp_Synchronizer();
   }
}

void PLP_ProcessOutput(Can_FD_ID_Struct_T *can_fd_data)
{
   // Process the synchronized data and prepare output
   Emb_Lib_Output_Control_T control = get_output_control();
   if ((control.plp_algorithms == RADAR_PLP_SYNC_ENABLE))
      PLP_output_logger(can_fd_data);
}

// void PLP_OpenVigemEthFile(void)
// {
//    Emb_Lib_Output_Control_T control = get_output_control();
//    reset_output_someip_payload();

//    if ((control.plp_algorithms == RADAR_PLP_SYNC_ENABLE))
//    {
//       SOMEIP_Radar_plp_Synchronizer();
//    }
// }

// void PLP_ProcessSOMEIPOutput(SOMEIP_ID_Struct_T *someip_data)
// {
//    Emb_Lib_Output_Control_T control = get_output_control();
//    if ((control.plp_algorithms == RADAR_PLP_SYNC_ENABLE))
//       PLP_SOMEIP_output_logger(someip_data);
// }
