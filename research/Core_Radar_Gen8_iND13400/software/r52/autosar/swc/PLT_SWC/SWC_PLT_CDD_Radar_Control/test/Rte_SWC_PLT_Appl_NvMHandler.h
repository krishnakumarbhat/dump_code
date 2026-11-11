/*===========================================================================*/
/**
 * @file Rte_SWC_PLT_Appl_NvMHandler.h
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Stub header file for unit testing SWC_PLT_CDD_Radar_Control
 * Provides minimal RTE interface definitions required by the source code
 *
 *------------------------------------------------------------------------------
 */
/*===========================================================================*/

#ifndef RTE_SWC_PLT_APPL_NVMHANDLER_H
#define RTE_SWC_PLT_APPL_NVMHANDLER_H

#ifdef __cplusplus
extern "C"
{
#endif

   /*===========================================================================*
    * RTE Read/Write Interfaces - Fake functions for testing
    *===========================================================================*/

   /* These are now fake functions instead of macros to allow error injection */
   Std_ReturnType Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(void *data);
   Std_ReturnType Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(const void *data);
   Std_ReturnType Rte_Call_CS_Radar_Control_Rfe_R1R2_NvM_Write_NvHandler_Trigger_Write_To_NVM(uint8_t arg1, uint8_t arg2);
   Std_ReturnType Rte_Read_Rp_XCP_CW_Mode_De_XCP_CW_Mode(uint8_t *data);
   Std_ReturnType Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final(uint8_t *data);
   Std_ReturnType Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream(void);
   Std_ReturnType Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream(void);
   Std_ReturnType Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream(void);
   Std_ReturnType Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream(void);
   Std_ReturnType Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream(void);
   Std_ReturnType Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx(void);

#ifdef __cplusplus
}
#endif

#endif /* RTE_SWC_PLT_APPL_NVMHANDLER_H */
