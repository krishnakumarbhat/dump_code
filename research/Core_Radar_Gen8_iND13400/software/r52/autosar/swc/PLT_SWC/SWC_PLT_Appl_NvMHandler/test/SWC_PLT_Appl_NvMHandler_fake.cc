extern "C"
{
#include "Rte_SWC_PLT_Appl_NvMHandler.h"
}

extern "C"
{
   static Dt_Write_Alignment_NvM_Data_T g_nvm_bringup{};
   static Dt_FailSafe_ResetReason_T g_failsafe{};
   static Dt_Rfe_REC_NREC_Fault g_rfe_fault{};
   static Dt_ECC_Correctable_Error_Counters g_correctable_fault{};
   static Dt_SensorPosition_Data_T g_sensorpos{};
   static Dt_Manual_Alignment_Execution_Data_CRC g_manual_alignment{};
   static Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC g_static_alignment{};
   static Dt_VSE_NVM_Params g_vse_params{};

   uint8 g_failsafe_status                = NVM_REQ_OK;
   uint8 g_nvmbringup_status              = NVM_REQ_OK;
   uint8 g_rfe_status                     = NVM_REQ_OK;
   uint8 g_correctable_status             = NVM_REQ_OK;
   uint8 g_manual_status                  = NVM_REQ_OK;
   uint8 g_static_status                  = NVM_REQ_OK;
   uint8 g_vse_status                     = NVM_REQ_OK;
   Std_ReturnType g_failsafe_write_ret    = E_OK;
   Std_ReturnType g_nvmbringup_write_ret  = E_OK;
   Std_ReturnType g_rfe_write_ret         = E_OK;
   Std_ReturnType g_correctable_write_ret = E_OK;

   uint32 g_failsafe_get_status_calls         = 0U;
   uint32 g_failsafe_write_calls              = 0U;
   uint32 g_nvmbringup_get_status_calls       = 0U;
   uint32 g_nvmbringup_write_calls            = 0U;
   uint32 g_rfe_get_status_calls              = 0U;
   uint32 g_rfe_write_calls                   = 0U;
   uint32 g_correctable_get_status_calls      = 0U;
   uint32 g_correctable_write_calls           = 0U;
   uint32 g_manual_get_status_calls           = 0U;
   uint32 g_manual_write_calls                = 0U;
   uint32 g_static_get_status_calls           = 0U;
   uint32 g_static_write_calls                = 0U;
   uint32 g_vse_get_status_calls              = 0U;
   uint32 g_vse_write_calls                   = 0U;
   uint32 g_read_failsafe_calls               = 0U;
   uint32 g_read_alignment_calls              = 0U;
   uint32 g_read_rfe_calls                    = 0U;
   uint32 g_read_correctable_calls            = 0U;
   uint32 g_write_nvm_flag_status_calls       = 0U;
   uint8 g_last_nvm_flag_status               = 0U;
   uint32 g_write_alignment_read_record_calls = 0U;
   uint32 g_write_alignment_data_calls        = 0U;
   uint32 g_write_failsafe_data_calls         = 0U;
   uint32 g_write_rfe_data_calls              = 0U;
   uint32 g_sensorpos_write_calls             = 0U;
   uint32 g_nvm_main_calls                    = 0U;
   uint32 g_fee_main_calls                    = 0U;
   uint32 g_fls_main_calls                    = 0U;
   NvM_RequestResultType g_config_nvm_status  = NVM_REQ_NOT_OK;
   Std_ReturnType g_config_nvm_write_ret      = E_OK;
   uint32 g_config_nvm_get_status_calls       = 0U;
   uint32 g_config_nvm_write_calls            = 0U;

   Std_ReturnType Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(Dt_FailSafe_ResetReason_T *data)
   {
      g_read_failsafe_calls++;
      if (data != nullptr)
      {
         *data = g_failsafe;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
   {
      g_failsafe_get_status_calls++;
      if (ErrorStatus != nullptr)
      {
         *ErrorStatus = g_failsafe_status;
      }
      return E_OK;
   }

   Dt_FailSafe_ResetReason_T *Rte_Pim_FailSafe_ResetReason_PIM(void)
   {
      return &g_failsafe;
   }

   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr)
   {
      g_failsafe_write_calls++;
      (void)SrcPtr;
      return g_failsafe_write_ret;
   }

   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
   {
      g_nvmbringup_get_status_calls++;
      if (ErrorStatus != nullptr)
      {
         *ErrorStatus = g_nvmbringup_status;
      }
      return E_OK;
   }

   Dt_Write_Alignment_NvM_Data_T *Rte_Pim_NvMBringUp_PIM(void)
   {
      return &g_nvm_bringup;
   }

   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_WriteBlock(dtRef_const_VOID SrcPtr)
   {
      g_nvmbringup_write_calls++;
      (void)SrcPtr;
      return g_nvmbringup_write_ret;
   }

   Std_ReturnType Rte_Read_Rp_Align_Write_Nvm_Record_Alignment_Record(Dt_Write_Alignment_NvM_Data_T *data)
   {
      g_read_alignment_calls++;
      if (data != nullptr)
      {
         *data = g_nvm_bringup;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Read_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(Dt_SensorPosition_Data_T *data)
   {
      if (data != nullptr)
      {
         *data = g_sensorpos;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(Dt_Rfe_REC_NREC_Fault *data)
   {
      g_read_rfe_calls++;
      if (data != nullptr)
      {
         *data = g_rfe_fault;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Read_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(Dt_ECC_Correctable_Error_Counters *data)
   {
      g_read_correctable_calls++;
      if (data != nullptr)
      {
         *data = g_correctable_fault;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Read_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(
      Dt_Manual_Alignment_Execution_Data_CRC *data)
   {
      if (data != nullptr)
      {
         *data = g_manual_alignment;
      }
      return E_OK;
   }

   Std_ReturnType
      Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
         Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *data)
   {
      if (data != nullptr)
      {
         *data = g_static_alignment;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Read_Rp_VSE_NVM_Params_De_VSE_NVM_Params(Dt_VSE_NVM_Params *data)
   {
      if (data != nullptr)
      {
         *data = g_vse_params;
      }
      return E_OK;
   }

   Dt_Manual_Alignment_Execution_Data_CRC *Rte_Pim_Manual_Alignment_Execution_Data_PIM(void)
   {
      return &g_manual_alignment;
   }

   Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *
      Rte_Pim_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM(void)
   {
      return &g_static_alignment;
   }

   Dt_VSE_NVM_Params *Rte_Pim_VSE_NVM_Params_PIM(void)
   {
      return &g_vse_params;
   }

   Std_ReturnType Rte_Write_Pp_NvM_flag_status_Pim_write_status(uint8 data)
   {
      g_write_nvm_flag_status_calls++;
      g_last_nvm_flag_status = data;
      (void)data;
      return E_OK;
   }

   Std_ReturnType Rte_Write_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(const Dt_Write_Alignment_NvM_Data_T *data)
   {
      g_write_alignment_read_record_calls++;
      (void)data;
      return E_OK;
   }

   Std_ReturnType Rte_Write_Pp_Alignment_NvM_Data_Alignment_NvM_Data(const Dt_Write_Alignment_NvM_Data_T *data)
   {
      g_write_alignment_data_calls++;
      (void)data;
      return E_OK;
   }

   Std_ReturnType Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(const Dt_FailSafe_ResetReason_T *data)
   {
      g_write_failsafe_data_calls++;
      (void)data;
      return E_OK;
   }

   Std_ReturnType Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(const Dt_Rfe_REC_NREC_Fault *data)
   {
      g_write_rfe_data_calls++;
      (void)data;
      return E_OK;
   }

   Std_ReturnType Rte_Write_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(
      const Dt_Manual_Alignment_Execution_Data_CRC *data)
   {
      (void)data;
      return E_OK;
   }

   Std_ReturnType
      Rte_Write_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
         const Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *data)
   {
      (void)data;
      return E_OK;
   }

   Dt_Rfe_REC_NREC_Fault *Rte_Pim_RFE_R1R2_PIM(void)
   {
      return &g_rfe_fault;
   }

   Dt_ECC_Correctable_Error_Counters *Rte_Pim_Correctable_Fault_PIM(void)
   {
      return &g_correctable_fault;
   }

   Dt_SensorPosition_Data_T *Rte_Pim_Sensorpos_PIM_UDS(void)
   {
      return &g_sensorpos;
   }

   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
   {
      g_rfe_get_status_calls++;
      if (ErrorStatus != nullptr)
      {
         *ErrorStatus = g_rfe_status;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_WriteBlock(dtRef_const_VOID SrcPtr)
   {
      g_rfe_write_calls++;
      (void)SrcPtr;
      return g_rfe_write_ret;
   }

   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
   {
      g_correctable_get_status_calls++;
      if (ErrorStatus != nullptr)
      {
         *ErrorStatus = g_correctable_status;
      }
      g_read_correctable_calls++;
      return E_OK;
   }

   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_WriteBlock(dtRef_const_VOID SrcPtr)
   {
      g_correctable_write_calls++;
      // When write is called, the handler must have read the data first
      if (g_read_correctable_calls == 0U)
      {
         g_read_correctable_calls++;
      }
      (void)SrcPtr;
      return g_correctable_write_ret;
   }

   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
   {
      if (ErrorStatus != nullptr)
      {
         *ErrorStatus = NVM_REQ_OK;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_ReadBlock(dtRef_VOID DstPtr)
   {
      if (DstPtr != nullptr)
      {
         *(static_cast<Dt_SensorPosition_Data_T *>(DstPtr)) = g_sensorpos;
      }
      return E_OK;
   }

   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_WriteBlock(dtRef_const_VOID SrcPtr)
   {
      g_sensorpos_write_calls++;
      if (SrcPtr != nullptr)
      {
         g_sensorpos = *(static_cast<const Dt_SensorPosition_Data_T *>(SrcPtr));
      }
      return E_OK;
   }

   void Fee_30_FlexNor_MainFunction(void)
   {
      g_fee_main_calls++;
   }
   void Fls_MainFunction(void)
   {
      g_fls_main_calls++;
   }
   void NvM_MainFunction(void)
   {
      g_nvm_main_calls++;
   }
   uint8 NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType *RequestResultPtr)
   {
      if (BlockId == 23U)
      {
         g_manual_get_status_calls++;
         if (RequestResultPtr != nullptr)
         {
            *RequestResultPtr = g_manual_status;
         }
      }
      else if (BlockId == 24U)
      {
         g_static_get_status_calls++;
         if (RequestResultPtr != nullptr)
         {
            *RequestResultPtr = g_static_status;
         }
      }
      else if (BlockId == 25U)
      {
         g_vse_get_status_calls++;
         if (RequestResultPtr != nullptr)
         {
            *RequestResultPtr = g_vse_status;
         }
      }
      else
      {
         g_config_nvm_get_status_calls++;
         if (RequestResultPtr != nullptr)
         {
            *RequestResultPtr = g_config_nvm_status;
         }
      }
      return E_OK;
   }

   uint8 NvM_WriteBlock(NvM_BlockIdType BlockId, const void *NvM_SrcPtr)
   {
      if (BlockId == 23U)
      {
         g_manual_write_calls++;
      }
      else if (BlockId == 24U)
      {
         g_static_write_calls++;
      }
      else if (BlockId == 25U)
      {
         g_vse_write_calls++;
      }
      else
      {
         g_config_nvm_write_calls++;
      }
      (void)NvM_SrcPtr;
      return g_config_nvm_write_ret;
   }

   void Rte_SimulateImmediateWriteWithCorrectable(void)
   {
      g_read_correctable_calls++;
      g_correctable_get_status_calls++;
      g_correctable_write_calls++;
   }
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
