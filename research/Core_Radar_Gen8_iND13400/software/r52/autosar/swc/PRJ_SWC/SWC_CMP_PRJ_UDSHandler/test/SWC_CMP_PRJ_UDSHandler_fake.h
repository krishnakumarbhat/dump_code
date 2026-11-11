#ifndef SWC_CMP_PRJ_UDSHANDLER_FAKE_H
#define SWC_CMP_PRJ_UDSHANDLER_FAKE_H

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "Rte_SWC_CMP_PRJ_UDSHandler.h"
#include "mcu_reset_wrapper.h"

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Dem_RequestNvSynchronization);
   DECLARE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_GetErrorStatus, NvM_BlockIdType, NvM_RequestResultType *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_WriteBlock, NvM_BlockIdType, dtRef_const_VOID);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData, Dt_AdcData_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable,
                           uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info,
                           const Idt_SW_Version_Info_T *);
   DECLARE_FAKE_VOID_FUNC(CS_ReadNvM_Value_Operation, Dt_SensorPosition_Status_T *);
   DECLARE_FAKE_VOID_FUNC(CS_GetError_Status_Operation, NvM_RequestResultType *);
   DECLARE_FAKE_VOID_FUNC(CS_Control_DTC_Service_Operation, uint8);
   DECLARE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, Dt_Nv_Caller_ID);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Dcm_GetSesCtrlType, Dcm_SesCtrlType *);
   DECLARE_FAKE_VALUE_FUNC(uint8, Platform_Get_Fault_Status, uint16);

   extern uint8_t Get_Customer_Radar_Position(void);
   extern void Set_Customer_Radar_Position(uint8_t position);

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status,
                           const Dt_SensorPosition_Data_T *);
   DECLARE_FAKE_VOID_FUNC(Clear_Platform_Fault_Arrays);
   DECLARE_FAKE_VOID_FUNC(Clear_Cust_Fault_Arrays);
   DECLARE_FAKE_VALUE_FUNC(
      Std_ReturnType,
      Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC,
      Dt_Manual_Alignment_Execution_Data_CRC *);
   DECLARE_FAKE_VALUE_FUNC(
      Std_ReturnType,
      Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC,
      const Dt_Manual_Alignment_Execution_Data_CRC *);
   DECLARE_FAKE_VALUE_FUNC(
      Std_ReturnType,
      Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC,
      const Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *);

#ifdef __cplusplus
}
#endif

#endif /* SWC_CMP_PRJ_UDSHANDLER_FAKE_H */
