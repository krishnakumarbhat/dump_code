/**
 * @file BswM_Callout_Stubs_wrapper.c
 * @brief Wrapper for BswM_Callout_Stubs.c with testable functions
 */

#include "BswM_Callout_fakes.h"

const void *EcuM_Config_Ptr                            = (void *)0x1000;
static const void *mock_com_config                     = (void *)0x2000;
static EcuM_GlobalPCConfigType mock_global_config      = {&mock_com_config};
const EcuM_GlobalPCConfigType *EcuM_GlobalPCConfig_Ptr = &mock_global_config;

#line 1 "software/r52/autosar/config/Appl/Source/BswM_Callout_Stubs.c"
void BswM_AL_SetProgrammableInterrupts(void)
{
   // Empty stub
}

void BswM_ESH_OnEnterPostRun(void)
{
   // Empty stub
}

void BswM_ESH_OnEnterPrepShutdown(void)
{
   // Empty stub
}

void BswM_ESH_OnEnterRun(void)
{
   // Empty stub
}

void BswM_ESH_OnEnterShutdown(void)
{
   // Empty stub
}

void BswM_ESH_OnEnterWaitForNvm(void)
{
   // Empty stub
}

void BswM_ESH_OnEnterWakeup(void)
{
   // Empty stub
}

void BswM_INIT_NvMReadAll(void)
{
   NvM_RequestResultType ErrorStatus;
   NvM_ReadAll();
   do
   {
      NvM_MainFunction();
      Fee_30_FlexNor_MainFunction();
      Fls_MainFunction();
      NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &ErrorStatus);
   } while (ErrorStatus == NVM_REQ_PENDING);
}

void Eth_ComM_Init(void)
{
   ComM_RequestComMode(ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b, COMM_FULL_COMMUNICATION);
}

void User_CAN_ComPduGroupHandling(void)
{
   uint8_t ecu_position;

   ecu_position = Get_Radar_Position();

   switch (ecu_position)
   {
      case 1: /* ECU_POS_VARIANT_RDR01 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067, 1);
         break;
      }
      case 2: /* ECU_POS_VARIANT_RDR02 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Tx_9f750495, 1);
         break;
      }
      case 3: /* ECU_POS_VARIANT_RDR03 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Tx_311d9504, 1);
         break;
      }
      case 4: /* ECU_POS_VARIANT_RDR04 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Tx_cce46d71, 1);
         break;
      }
      case 5: /* ECU_POS_VARIANT_RDR05 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Tx_628cfce0, 1);
         break;
      }
      case 6: /* ECU_POS_VARIANT_RDR06 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Tx_4b444812, 1);
         break;
      }
      case 7: /* ECU_POS_VARIANT_RDR07 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Tx_e52cd983, 1);
         break;
      }
      case 8: /* ECU_POS_VARIANT_RDR08 */
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9, 1);
         break;
      }
      default:
      {
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1, 1);
         Com_IpduGroupStart(ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067, 1);
         break;
      }
   }
}

void User_Com_Init(void)
{
   Com_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Com_Init);
}
