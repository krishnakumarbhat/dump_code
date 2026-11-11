#ifndef RTE_SWC_PLT_APPL_NVMHANDLER_H
#define RTE_SWC_PLT_APPL_NVMHANDLER_H

#include "NvM.h"
#include "Rte_Type.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef AUTOMATIC
   #define AUTOMATIC
#endif

#ifndef RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR
   #define RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR
#endif

#ifndef RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA
   #define RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA
#endif

#ifndef P2VAR
   #define P2VAR(type, memclass, ptrclass) type *
#endif

#ifndef P2CONST
   #define P2CONST(type, memclass, ptrclass) const type *
#endif

   typedef uint8 Std_ReturnType;

   typedef const void *dtRef_const_VOID;
   typedef void *dtRef_VOID;

   typedef struct
   {
      float32 AACurrentAzimuth;
      float32 AACurrentElevation;
      float32 AACurrentRoll;
      float32 InitialAlignmentResultAzimuth;
      float32 InitialAlignmentResultElevation;
      float32 InitialAlignmentResultRoll;
      float32 InitialLastSuccessfulAlignmentMode;
      float32 ElevationUpdates;
      float32 AzimuthUpdates;
      float32 RollUpdates;
      float32 InitialAlignmentResultElevationUpdates;
      float32 InitialAlignmentResultHostSpeedCompensationFactor;
      float32 HostSpeedCompensationFactor;
      float32 InitialAlignmentResultAzimuthUpdates;
      float32 InitialAlignmentResultRollUpdates;
      uint8 AlignmentModeOut;
   } Dt_Write_Alignment_NvM_Data_T;

   typedef struct
   {
      uint8 reset_reason[5];
      uint8 reset_counter;
      uint8 last_cycle_reset;
      uint8 reset_reason_crnt_indx;
      uint8 repetitive_reset_counter;
      uint8 RFE_Repetitive_Reset_Counter;
      uint8 mem_exception_reason[24];
      uint16 wdg_failed_SE_info[5];
      uint16 FCCU_Faults[10];
      uint8 StaticRegCheckFailureInfo[35];
   } Dt_FailSafe_ResetReason_T;

   typedef struct
   {
      uint8 MMIC_Rfe_R1R2_Fault[12];
      uint8 MMIC_Rfe_ApiError_Code[2];
      uint8 MMIC_RfeReserve_Error[20];
   } Dt_Rfe_R1R2_Fault;

   typedef Dt_Rfe_R1R2_Fault Dt_Rfe_REC_NREC_Fault;

   typedef struct
   {
      uint8 aa_mem_sec;
      uint8 artie_mem_sec;
      uint8 csi2_sec;
      uint8 dsp_opif_sec;
      uint8 dsp_idma_sec;
      uint8 dsp_iram_sec_axis;
      uint8 dsp_dcache_sec;
      uint8 dsp_dram_sec;
      uint8 dsp_icache_sec;
      uint8 dsp_iram_sec;
      uint8 ra_cqmem_sec;
      uint8 ra_dpmem_sec;
      uint8 ra_estmem_sec;
      uint8 ra_idxmem_sec;
      uint8 ra_phmem_sec;
      uint8 ra_wcmem_sec;
      uint8 sp_axi_m_corr;
      uint8 sp_axi_s_corr;
      uint8 sysmem0_sec;
      uint8 sysmem1_sec;
      uint8 not_recorded;
   } Dt_ECC_Correctable_Error_Counters;

   typedef struct
   {
      uint8 SensorPos_Value;
      uint8 SensorPos_Lock_Status;
   } Dt_SensorPosition_Status_T;

   typedef struct
   {
      Dt_SensorPosition_Status_T SensorPosition_Data;
      uint32 SensorPos_CRC;
   } Dt_SensorPosition_Data_T;

   typedef unsigned char Dt_Align_Mode_T;

   typedef struct
   {
      Dt_Align_Mode_T AlignmentModeIn;
      Dt_Align_Mode_T InitialLastSuccessfulAlignmentMode;
      sint32 IntialMisalignmentAngleAzimuth;
      sint32 IntialMisalignmentAngleElevation;
   } Dt_Manual_Alignment_Execution_Data;

   typedef struct
   {
      Dt_Manual_Alignment_Execution_Data Manual_Alignment_Execution_Data;
      uint32 Data_CRC;
   } Dt_Manual_Alignment_Execution_Data_CRC;

   typedef struct
   {
      sint16 AlignmentStatic_TargetAzimuth;
      sint16 AlignmentStatic_TargetElevation;
      uint16 AlignmentStatic_TargetDistance;
   } Dt_Static_Alignment_Engineering_Write_Configuration_Parameters;

   typedef struct
   {
      Dt_Static_Alignment_Engineering_Write_Configuration_Parameters Static_alignment_write_Params;
      uint32 Data_CRC;
   } Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC;

   typedef struct
   {
      sint32 nvm_last_rem_swa_bias_deg;
      sint32 nvm_last_rem_speed_comp;
      sint32 nvm_last_rem_stop_yaw_bias_primary_radps;
      sint32 nvm_last_rem_stop_yaw_bias_secondary_radps;
      uint8 nvm_f_last_rem_swa_bias;
   } Dt_VSE_NVM_Params;

   typedef uint8 Dt_Nv_Caller_ID;

#define INVALID              ((Dt_Nv_Caller_ID)0U)
#define CDD_FAIL_SAFE        ((Dt_Nv_Caller_ID)1U)
#define CDD_ESM              ((Dt_Nv_Caller_ID)2U)
#define APPL_DIAG            ((Dt_Nv_Caller_ID)3U)
#define CDD_ALIGNMENT        ((Dt_Nv_Caller_ID)4U)
#define DYNAMIC_ALIGNMENT    ((Dt_Nv_Caller_ID)5U)
#define RFE_R1R2_FAULT       ((Dt_Nv_Caller_ID)6U)
#define CDD_FAILSAFE_ECC     ((Dt_Nv_Caller_ID)7U)
#define CDD_SENSORPOS        ((Dt_Nv_Caller_ID)8U)
#define UDS_MANUAL_ALIGNMENT ((Dt_Nv_Caller_ID)9U)
#define UDS_STATIC_ALIGNMENT ((Dt_Nv_Caller_ID)10U)

#define E_OK     ((Std_ReturnType)0U)
#define E_NOT_OK ((Std_ReturnType)1U)

#ifndef NULL_PTR
   #define NULL_PTR NULL
#endif

#define SWC_PLT_Appl_NvMHandler_CODE
#define FUNC(rettype, memclass) rettype

   Std_ReturnType Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(Dt_FailSafe_ResetReason_T *data);
   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
   Dt_FailSafe_ResetReason_T *Rte_Pim_FailSafe_ResetReason_PIM(void);
   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr);
   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
   Dt_Write_Alignment_NvM_Data_T *Rte_Pim_NvMBringUp_PIM(void);
   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_WriteBlock(dtRef_const_VOID SrcPtr);
   Std_ReturnType Rte_Read_Rp_Align_Write_Nvm_Record_Alignment_Record(Dt_Write_Alignment_NvM_Data_T *data);
   Std_ReturnType Rte_Read_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(Dt_SensorPosition_Data_T *data);
   Std_ReturnType Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(Dt_Rfe_REC_NREC_Fault *data);
   Std_ReturnType Rte_Read_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(Dt_ECC_Correctable_Error_Counters *data);
   Std_ReturnType Rte_Write_Pp_NvM_flag_status_Pim_write_status(uint8 data);
   Std_ReturnType Rte_Write_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(const Dt_Write_Alignment_NvM_Data_T *data);
   Std_ReturnType Rte_Write_Pp_Alignment_NvM_Data_Alignment_NvM_Data(const Dt_Write_Alignment_NvM_Data_T *data);
   Std_ReturnType Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(const Dt_FailSafe_ResetReason_T *data);
   Std_ReturnType Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(const Dt_Rfe_REC_NREC_Fault *data);
   Dt_Rfe_REC_NREC_Fault *Rte_Pim_RFE_R1R2_PIM(void);
   Dt_ECC_Correctable_Error_Counters *Rte_Pim_Correctable_Fault_PIM(void);
   Dt_SensorPosition_Data_T *Rte_Pim_Sensorpos_PIM_UDS(void);
   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_WriteBlock(dtRef_const_VOID SrcPtr);
   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_WriteBlock(dtRef_const_VOID SrcPtr);
   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_ReadBlock(dtRef_VOID DstPtr);
   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_WriteBlock(dtRef_const_VOID SrcPtr);
   Std_ReturnType Rte_Read_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(
      Dt_Manual_Alignment_Execution_Data_CRC *data);
   Std_ReturnType
      Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
         Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *data);
   Std_ReturnType Rte_Read_Rp_VSE_NVM_Params_De_VSE_NVM_Params(Dt_VSE_NVM_Params *data);
   Std_ReturnType Rte_Write_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(
      const Dt_Manual_Alignment_Execution_Data_CRC *data);
   Std_ReturnType
      Rte_Write_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
         const Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *data);
   Dt_Manual_Alignment_Execution_Data_CRC *Rte_Pim_Manual_Alignment_Execution_Data_PIM(void);
   Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *
      Rte_Pim_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM(void);
   Dt_VSE_NVM_Params *Rte_Pim_VSE_NVM_Params_PIM(void);

#define Rte_Call_CS_NvMService_ManualAlignment_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)23, arg1))
#define Rte_Call_CS_NvMService_ManualAlignment_WriteBlock(arg1)     (NvM_WriteBlock((NvM_BlockIdType)23, arg1))
#define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_GetErrorStatus(arg1)                   \
   (NvM_GetErrorStatus((NvM_BlockIdType)24, arg1))
#define Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_WriteBlock(arg1)                       \
   (NvM_WriteBlock((NvM_BlockIdType)24, arg1))
#define Rte_Call_CS_NvMService_VSE_Parameters_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)25, arg1))
#define Rte_Call_CS_NvMService_VSE_Parameters_WriteBlock(arg1)     (NvM_WriteBlock((NvM_BlockIdType)25, arg1))

#ifdef __cplusplus
}
#endif

#endif
