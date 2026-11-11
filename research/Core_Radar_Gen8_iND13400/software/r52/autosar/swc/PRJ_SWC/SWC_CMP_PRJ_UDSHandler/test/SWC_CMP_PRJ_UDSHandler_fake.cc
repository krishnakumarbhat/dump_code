/*===========================================================================*/
/**
 * @file SWC_CMP_PRJ_UDSHandler_fake.cc
 *
 * Fake/Mock implementation file for SWC_CMP_PRJ_UDSHandler unit testing
 */
/*===========================================================================*/

#include "SWC_CMP_PRJ_UDSHandler_fake.h"

#include <cstdint>
#include <cstring>

DEFINE_FFF_GLOBALS;

VAR(Dt_VIN_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_VIN                               = {0};
VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 0U;

DEFINE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Dem_RequestNvSynchronization);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_GetErrorStatus, NvM_BlockIdType, NvM_RequestResultType *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_WriteBlock, NvM_BlockIdType, dtRef_const_VOID);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData, Dt_AdcData_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType,
                       Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info,
                       const Idt_SW_Version_Info_T *);
DEFINE_FAKE_VOID_FUNC(CS_ReadNvM_Value_Operation, Dt_SensorPosition_Status_T *);
DEFINE_FAKE_VOID_FUNC(CS_GetError_Status_Operation, NvM_RequestResultType *);
DEFINE_FAKE_VOID_FUNC(CS_Control_DTC_Service_Operation, uint8);
DEFINE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, Dt_Nv_Caller_ID);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Dcm_GetSesCtrlType, Dcm_SesCtrlType *);
DEFINE_FAKE_VALUE_FUNC(uint8, Platform_Get_Fault_Status, uint16);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status,
                       const Dt_SensorPosition_Data_T *);
static uint8_t g_customer_radar_position = 0x05U;

DEFINE_FAKE_VOID_FUNC(Clear_Platform_Fault_Arrays);
DEFINE_FAKE_VOID_FUNC(Clear_Cust_Fault_Arrays);
DEFINE_FAKE_VALUE_FUNC(
   Std_ReturnType,
   Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC,
   Dt_Manual_Alignment_Execution_Data_CRC *);
DEFINE_FAKE_VALUE_FUNC(
   Std_ReturnType,
   Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC,
   const Dt_Manual_Alignment_Execution_Data_CRC *);
DEFINE_FAKE_VALUE_FUNC(
   Std_ReturnType,
   Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC,
   const Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *);
extern "C" uint8_t Get_Customer_Radar_Position(void)
{
   return g_customer_radar_position;
}

extern "C" void Set_Customer_Radar_Position(uint8_t position)
{
   g_customer_radar_position = position;
}

extern "C"
{
   void CRC32_Init(void)
   {
   }

   uint32_t CRC32_GetRunTimeCRC32(uint8_t *pBuf, uint16_t length)
   {
      (void)pBuf;
      (void)length;
      return 0U;
   }

   uint32_t crc32_sw(const uint32_t initialVal, const uint8_t *const data, const uint32_t size)
   {
      (void)initialVal;
      (void)data;
      (void)size;
      return 0U;
   }
}
