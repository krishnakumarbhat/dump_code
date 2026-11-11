/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PLT_Appl_NvMHandler.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_NvMHandler
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_NvMHandler>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_NvMHandler.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Fee_30_FlexNor.h"
#include "Fls.h"
#include "MemIf.h"
#include "NvM.h"
#include "crc32.h"
#include "fixmac.h"

/*Fail Safe Ram block*/
Dt_FailSafe_ResetReason_T SWC_PLT_CDD_FailSafe_Ramblock, SWC_PLT_CDD_FailSafe_read_Ramblock;
Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC StaticParam;
Dt_Manual_Alignment_Execution_Data_CRC ManualParam;
volatile static uint8 u8_nvblock_write_pending_failsafe    = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_alignment   = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_rfefault    = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_corrfault   = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_sensorpos   = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_staticalign = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_vseparams   = CODED_FALSE;
volatile static uint8 u8_nvblock_write_pending_manualalign = CODED_FALSE;
static Dt_Rfe_REC_NREC_Fault RFE_R1R2_Fault;
static Dt_ECC_Correctable_Error_Counters Correctable_Fault_Ramblock;
Dt_Write_Alignment_NvM_Data_T NvMBringUp_NvM_Read_Record, NvMBringUp_NvM_Write_Record;
NvM_RequestResultType nvblock_status_1;
static uint8 NvM_Write_Status = CODED_FALSE;
extern FUNC(void, FLS_CODE) Fls_MainFunction(void);
extern FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunction(void);
static void NVM_REQ_rfefaultHandler(void);
static void NVM_REQ_correctablefaultHandler(void);
static void NVM_REQ_manualalignHandler(void);
static void NVM_REQ_staticalignHandler(void);
static void NVM_REQ_vseparamsHandler(void);
static void NVM_Sensor_Position_faultHandler(void);
uint32_t stored_CRC_Unlock_SensorPosition_Request = FALSE;
uint32_t stored_CRC_lock_SensorPosition_Request   = FALSE;
Dt_SensorPosition_Data_T Sensor_POS;
void updateConfigId(void);
uint8_t ConfigID_NvM_Write_Status = CODED_FALSE;
uint16_t configIdWriteCounter     = 1000U;
Std_ReturnType nvmWrtStatus       = 0;
uint8 NVM_Config_Ram_Block;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_Align_Mode_T: Enumeration of integer in interval [0...255] with enumerators
 *   ALIGN_MODE_OFF (0U)
 *   ALIGN_MODE_AUTO (1U)
 *   ALIGN_MODE_SHORT_TRACK (2U)
 *   ALIGN_MODE_SERVICE (3U)
 *   ALIGN_MODE_STATIC (4U)
 *   ALIGN_MODE_MANUAL (5U)
 * Dt_Nv_Caller_ID: Enumeration of integer in interval [0...255] with enumerators
 *   INVALID (0U)
 *   CDD_FAIL_SAFE (1U)
 *   CDD_ESM (2U)
 *   APPL_DIAG (3U)
 *   CDD_ALIGNMENT (4U)
 *   DYNAMIC_ALIGNMENT (5U)
 *   RFE_R1R2_FAULT (6U)
 *   CDD_FAILSAFE_ECC (7U)
 *   CDD_SENSORPOS (8U)
 *   UDS_MANUAL_ALIGNMENT (9U)
 *   UDS_STATIC_ALIGNMENT (10U)
 * Dt_VBattState_T: Enumeration of integer in interval [0...255] with enumerators
 *   PowerON (0U)
 *   NORMV (1U)
 *   LO_V1 (2U)
 *   HI_V1 (3U)
 *   LO_V2 (4U)
 *   HI_V2 (5U)
 *   LO_Vtemp (6U)
 *   LO_VTEMP_TONORM (7U)
 *   LO_V1_TONORM (8U)
 *   LO_V2_TONORM (9U)
 *   HI_VTEMP_TONORM (10U)
 *   HI_V1_TONORM (11U)
 *   HI_V2_TONORM (12U)
 *   HI_Vtemp (13U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Rte_DT_Dt_FailSafe_ResetReason_T_0: Array with 5 element(s) of type uint8
 * Rte_DT_Dt_FailSafe_ResetReason_T_7: Array with 5 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_8: Array with 10 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_9: Array with 35 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Dt_ECC_Correctable_Error_Counters: Record with elements
 *   aa_mem_sec of type uint8
 *   artie_mem_sec of type uint8
 *   csi2_sec of type uint8
 *   dsp_opif_sec of type uint8
 *   dsp_idma_sec of type uint8
 *   dsp_iram_sec_axis of type uint8
 *   dsp_dcache_sec of type uint8
 *   dsp_dram_sec of type uint8
 *   dsp_icache_sec of type uint8
 *   dsp_iram_sec of type uint8
 *   ra_cqmem_sec of type uint8
 *   ra_dpmem_sec of type uint8
 *   ra_estmem_sec of type uint8
 *   ra_idxmem_sec of type uint8
 *   ra_phmem_sec of type uint8
 *   ra_wcmem_sec of type uint8
 *   sp_axi_m_corr of type uint16
 *   sp_axi_s_corr of type uint16
 *   sysmem0_sec of type uint8
 *   sysmem1_sec of type uint8
 *   not_recorded of type uint8
 * Dt_FailSafe_ResetReason_T: Record with elements
 *   reset_reason of type Rte_DT_Dt_FailSafe_ResetReason_T_0
 *   reset_counter of type uint8
 *   last_cycle_reset of type uint8
 *   reset_reason_crnt_indx of type uint8
 *   repetitive_reset_counter of type uint8
 *   RFE_Repetitive_Reset_Counter of type uint8
 *   mem_exception_reason of type Dt_Memory_Exception_Info_T
 *   wdg_failed_SE_info of type Rte_DT_Dt_FailSafe_ResetReason_T_7
 *   FCCU_Faults of type Rte_DT_Dt_FailSafe_ResetReason_T_8
 *   StaticRegCheckFailureInfo of type Rte_DT_Dt_FailSafe_ResetReason_T_9
 *   NOC_LatentIntFault_Info of type Dt_NOC_Fault_Info_T
 * Dt_Manual_Alignment_Execution_Data: Record with elements
 *   AlignmentModeIn of type Dt_Align_Mode_T
 *   InitialLastSuccessfulAlignmentMode of type Dt_Align_Mode_T
 *   IntialMisalignmentAngleAzimuth of type sint32
 *   IntialMisalignmentAngleElevation of type sint32
 * Dt_Manual_Alignment_Execution_Data_CRC: Record with elements
 *   Manual_Alignment_Execution_Data of type Dt_Manual_Alignment_Execution_Data
 *   Data_CRC of type uint32
 * Dt_Memory_Exception_Info_T: Record with elements
 *   ExceptionType of type uint32
 *   ExceptionCausingAddress of type uint32
 *   ExceptionStatusRegister of type uint32
 *   IsMemException_Occured of type boolean
 *   MemoryExceptionAddress of type uint32
 *   StackPointer of type uint32
 * Dt_NOC_Fault_Info_T: Record with elements
 *   LatentFault0 of type uint32
 *   LatentFault1 of type uint32
 *   LatentFault2 of type uint32
 *   LatentFault3 of type uint32
 *   Resnum of type uint16
 * Dt_Rfe_REC_NREC_Fault: Record with elements
 *   CORE_BANK_SFT_ERR_MON of type uint32
 *   CORE_BANK_SFT_ERR_STATUS of type uint32
 *   CORE_BANK_MCU_STS_MCU_MSSG of type uint32
 *   FUSA_IRQ0_FLAG_R of type uint32
 *   FUSA_IRQ1_FLAG_R of type uint32
 *   FUSA_IRQ2_FLAG_R of type uint32
 *   Api_ret_val of type uint32
 *   LOGEN_BANK_CHRP_GEN_ERROR of type uint32
 *   LOGEN_BANK_LOGEN_ERROR of type uint32
 *   CPU_SYS_MCU_ERR_0 of type uint32
 *   CPU_SYS_MCU_ERR_1 of type uint32
 *   CPU_SYS_MCU_ERR_2 of type uint32
 *   CPU_SYS_MCU_ERR_3 of type uint32
 *   ASYNC_BANK_ASYNC_ERR1 of type uint32
 *   PROF_BANK_PRF_ERR1 of type uint32
 *   PROF_BANK_PRF_ERR2 of type uint32
 *   RXADC_FUSAMON of type uint32
 *   maf_status of type uint8
 * Dt_SensorPosition_Data_T: Record with elements
 *   SensorPosition_Data of type Dt_SensorPosition_Status_T
 *   SensorPos_CRC of type uint32
 * Dt_SensorPosition_Status_T: Record with elements
 *   SensorPos_Value of type uint8
 *   SensorPos_Lock_Status of type uint8
 * Dt_Static_Alignment_Engineering_Write_Configuration_Parameters: Record with elements
 *   AlignmentStatic_TargetAzimuth of type sint16
 *   AlignmentStatic_TargetElevation of type sint16
 *   AlignmentStatic_TargetDistance of type uint16
 * Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC: Record with elements
 *   Static_alignment_write_Params of type Dt_Static_Alignment_Engineering_Write_Configuration_Parameters
 *   Data_CRC of type uint32
 * Dt_VSE_NVM_Params: Record with elements
 *   nvm_last_rem_swa_bias_deg of type sint32
 *   nvm_last_rem_speed_comp of type sint32
 *   nvm_last_rem_stop_yaw_bias_primary_radps of type sint32
 *   nvm_last_rem_stop_yaw_bias_secondary_radps of type sint32
 *   nvm_f_last_rem_swa_bias of type uint8
 * Dt_Write_Alignment_NvM_Data_T: Record with elements
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AACurrentRoll of type float32
 *   InitialAlignmentResultAzimuth of type float32
 *   InitialAlignmentResultElevation of type float32
 *   InitialAlignmentResultRoll of type float32
 *   InitialLastSuccessfulAlignmentMode of type float32
 *   ElevationUpdates of type float32
 *   AzimuthUpdates of type float32
 *   RollUpdates of type float32
 *   InitialAlignmentResultElevationUpdates of type float32
 *   InitialAlignmentResultHostSpeedCompensationFactor of type float32
 *   HostSpeedCompensationFactor of type float32
 *   InitialAlignmentResultAzimuthUpdates of type float32
 *   InitialAlignmentResultRollUpdates of type float32
 *   AlignmentModeOut of type uint8
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Dt_Write_Alignment_NvM_Data_T *Rte_Pim_NvMBringUp_PIM(void)
 *   Dt_Write_Alignment_NvM_Data_T *Rte_Pim_Appl_Alignment_PIM(void)
 *   Dt_ECC_Correctable_Error_Counters *Rte_Pim_Correctable_Fault_PIM(void)
 *   Dt_FailSafe_ResetReason_T *Rte_Pim_FailSafe_ResetReason_PIM(void)
 *   Dt_Manual_Alignment_Execution_Data_CRC *Rte_Pim_Manual_Alignment_Execution_Data_PIM(void)
 *   Dt_Rfe_REC_NREC_Fault *Rte_Pim_RFE_R1R2_PIM(void)
 *   Dt_SensorPosition_Data_T *Rte_Pim_Sensorpos_PIM_UDS(void)
 *   Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
 **Rte_Pim_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM(void) Dt_VSE_NVM_Params
 **Rte_Pim_VSE_NVM_Params_PIM(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Dt_Write_Alignment_NvM_Data_T *Rte_CData_Alignment_NvMBlock_DefaultValue(void)
 *   Dt_ECC_Correctable_Error_Counters *Rte_CData_Correctable_Fault_NvM_DefaultValue(void)
 *   Dt_Write_Alignment_NvM_Data_T *Rte_CData_NvMBringUp_DefaultValue(void)
 *   Dt_Rfe_REC_NREC_Fault *Rte_CData_RFE_R1R2_Fault_NvM_DefaultValue(void)
 *   Dt_Manual_Alignment_Execution_Data_CRC *Rte_CData_SWC_Manual_alignment_Execution_DefaultValue(void)
 *   Dt_FailSafe_ResetReason_T *Rte_CData_SWC_PLT_CDD_FailSafe_DefaultValue(void)
 *   Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
 **Rte_CData_SWC_Static_Alignment_Write_Parameters_DefaultValue(void) Dt_VSE_NVM_Params
 **Rte_CData_SWC_VSE_NVM_Params_DefaultValue(void) Dt_SensorPosition_Data_T *Rte_CData_SensorPos_NvM_DefaultValue(void)
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_GetError_Status_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_GetError_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_GetError_Status_Operation(NvM_RequestResultType *NvM_Error_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_GetError_Status_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE)
CS_GetError_Status_Operation(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR)
                                NvM_Error_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_GetError_Status_Operation
    *********************************************************************************************************************/

   (void)Rte_Call_Rp_CDD_SensorPos_UDS_GetErrorStatus(NvM_Error_Status);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_ReadNvM_Value_Operation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_ReadNvM_Value>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_ReadNvM_Value_Operation(Dt_SensorPosition_Status_T *Sensorpos_Read_Record)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_ReadNvM_Value_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE)
CS_ReadNvM_Value_Operation(P2VAR(Dt_SensorPosition_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR)
                              Sensorpos_Read_Record) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_ReadNvM_Value_Operation
    *********************************************************************************************************************/
   if (NULL_PTR != Sensorpos_Read_Record)
   {
      *Sensorpos_Read_Record = Rte_Pim_Sensorpos_PIM_UDS()->SensorPosition_Data;
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Appl_NvMHandler_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Align_Write_Nvm_Record_Alignment_Record(Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Read_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(Dt_ECC_Correctable_Error_Counters *data)
 *   Std_ReturnType
 *Rte_Read_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(Dt_Manual_Alignment_Execution_Data_CRC
 **data) Std_ReturnType Rte_Read_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(Dt_SensorPosition_Data_T *data)
 *   Std_ReturnType Rte_Read_Rp_R1_NCF_Count_R1_NCF_Count(uint16 *data)
 *   Std_ReturnType
 *Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
 **data) Std_ReturnType Rte_Read_Rp_VSE_NVM_Params_De_VSE_NVM_Params(Dt_VSE_NVM_Params *data) Std_ReturnType
 *Rte_Read_Rp_Vbatt_State_Volt_De_Vbatt_State(Dt_VBattState_T *data) Std_ReturnType
 *Rte_Read_Rp_XCP_Program_Mode_De_XCP_Program_Mode(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(const Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Write_Pp_NvM_flag_status_Pim_write_status(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(const Dt_Rfe_REC_NREC_Fault *data)
 *   Std_ReturnType Rte_Write_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault(uint8 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_ManualAlignment_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_GetErrorStatus(NvM_RequestResultType
 **ErrorStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType
 *Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_SetRamBlockStatus(boolean
 *RamBlockStatus) Synchronous Service Invocation. Timeout: None Returned Application Errors:
 *RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK Std_ReturnType
 *Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_NvMService_VSE_Parameters_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_CDD_SensorPos_UDS_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_NvMBringup_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_Xcp_Alignment_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_Xcp_Alignment_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_Xcp_Alignment_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_Xcp_Alignment_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_PS_Swc_Xcp_Alignment_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Appl_NvMHandler_50ms_doc
 *********************************************************************************************************************/

/**
 * @brief   Helper function to handle the FailSafe write process.
 *
 * This function is responsible for reading the FailSafe reset reason,
 * checking the error status and writing the FailSafe data block to NvM.
 *
 * @return  Std_ReturnType
 *          - E_OK if the write operation succeeds.
 *          - E_NOT_OK if the write operation fails.
 */
static Std_ReturnType Handle_FailSafeWrite(void)
{
   (void)Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(&SWC_PLT_CDD_FailSafe_Ramblock);
   (void)Rte_Read_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(&ManualParam);
   (void)
      Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
         &StaticParam);
   (void)Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(&nvblock_status_1);
   if (NVM_REQ_PENDING != nvblock_status_1)
   {
      /* Storing the data to pim */
      *Rte_Pim_FailSafe_ResetReason_PIM() = SWC_PLT_CDD_FailSafe_Ramblock;
      if ((Std_ReturnType)E_OK == Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(NULL_PTR))
      {
         return E_OK;
      }
      else
      {
         /* No action to perform */
      }
   }
   else
   {
      /* No action to perform */
   }
   return E_NOT_OK;
}

/**
 * @brief   Helper function to handle the RFE fault write process.
 *
 * This function is responsible for reading the RFE fault data,
 * checking the error status and writing the RFE fault block to NvM.
 *
 * @return  Std_ReturnType
 *          - E_OK if the write operation succeeds.
 *          - E_NOT_OK if the write operation fails.
 */
static Std_ReturnType Handle_Rfe_FaultWrite(void)
{
   (void)Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(&RFE_R1R2_Fault);
   (void)Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_GetErrorStatus(&nvblock_status_1);
   if (NVM_REQ_PENDING != nvblock_status_1)
   {
      *Rte_Pim_RFE_R1R2_PIM() = RFE_R1R2_Fault;
      if ((Std_ReturnType)E_OK == Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_WriteBlock(NULL_PTR))
      {
         return E_OK;
      }
      else
      {
         /* No action to perform */
      }
   }
   else
   {
      /* No action to perform */
   }
   return E_NOT_OK;
}

/**
 * @brief   Helper function to process main NvM and memory functions.
 *
 * This function triggers the main function calls for NvM, Fee, and Fls
 * to manage the memory operations in the system.
 */
static void Process_MainFunctions(void)
{
   NvM_MainFunction();
   Fee_30_FlexNor_MainFunction();
   Fls_MainFunction();
}
/**
 * @brief   Helper function to check the status of the NV (Non-Volatile) memory error.
 *
 * This function retrieves the error status of the FailSafe reset reason from NvM.
 *
 * @return  NvM_RequestResultType
 *          - The current status of the NvM request (e.g., NVM_REQ_OK, NVM_REQ_PENDING).
 */
static NvM_RequestResultType Check_NV_ErrorStatus(void)
{
   (void)Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(&nvblock_status_1);
   return nvblock_status_1;
}
/**********************************************************************************************************************
 * Function Name: Handle_Immediate_Write
 *
 * Handles immediate write requests for non-volatile memory blocks.
 * --------------------------------------------------------------------------------------------------------------------
 *
 * Description:
 * This function checks if an immediate write request is pending, processes the request by reading and writing the relevant data,
 * and continues to handle pending requests until all are processed.
 *
 *********************************************************************************************************************/
static void Handle_Immediate_Write(void)
{
   do
   {
      if ((CODED_TRUE == u8_nvblock_write_pending_rfefault) && (E_OK == Handle_Rfe_FaultWrite()))
      {
         u8_nvblock_write_pending_rfefault = CODED_FALSE;
      }
      else
      {
         /* No action to perform */
      }

      if ((CODED_TRUE == u8_nvblock_write_pending_failsafe) && (E_OK == Handle_FailSafeWrite()))
      {
         u8_nvblock_write_pending_failsafe = CODED_FALSE;
      }
      else
      {
         /* No action to perform */
      }
      Process_MainFunctions();
      nvblock_status_1 = Check_NV_ErrorStatus();
   } while ((NVM_REQ_PENDING == nvblock_status_1) || (CODED_TRUE == u8_nvblock_write_pending_failsafe) ||
            (CODED_TRUE == u8_nvblock_write_pending_rfefault));
}

/**********************************************************************************************************************
 * Function Name: NVM_REQ_alignmentHandler
 *
 * Handles alignment block write requests to non-volatile memory.
 * --------------------------------------------------------------------------------------------------------------------
 *
 * Description:
 * This function processes write requests for alignment data, checking NvM status,
 * updating PIM, and triggering the write operation.
 *
 *********************************************************************************************************************/
static void NVM_REQ_alignmentHandler(void)
{
   (void)Rte_Call_Rp_PS_Swc_NvMBringup_GetErrorStatus(&nvblock_status_1);
   if ((NVM_REQ_PENDING != nvblock_status_1))
   {
      *Rte_Pim_NvMBringUp_PIM() = NvMBringUp_NvM_Write_Record;
      (void)Rte_Call_Rp_PS_Swc_NvMBringup_WriteBlock(NULL_PTR);
      NvM_Write_Status                   = CODED_TRUE;
      u8_nvblock_write_pending_alignment = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}

/**********************************************************************************************************************
 * Function Name: Process_Nvmblock_CallerID
 *
 * Handles different cases based on the caller ID for non-volatile memory operations.
 * --------------------------------------------------------------------------------------------------------------------
 *
 * Description:
 * This function processes write requests based on the caller ID, handling various scenarios such as fail-safe operations,
 * alignment updates, and error status reporting.
 *
 *********************************************************************************************************************/

static void Process_Nvmblock_CallerID(Dt_Nv_Caller_ID dt_Nv_Caller_Id)
{
   switch (dt_Nv_Caller_Id)
   {
      case RFE_R1R2_FAULT:
         u8_nvblock_write_pending_rfefault = CODED_TRUE;
         (void)Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(&RFE_R1R2_Fault);
         break;
      case CDD_FAILSAFE_ECC:
         u8_nvblock_write_pending_corrfault = CODED_TRUE;
         (void)Rte_Read_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&Correctable_Fault_Ramblock);
         break;
      case CDD_FAIL_SAFE:
         u8_nvblock_write_pending_failsafe = CODED_TRUE;
         (void)Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(&SWC_PLT_CDD_FailSafe_Ramblock);
         break;
      case CDD_ALIGNMENT:
         u8_nvblock_write_pending_alignment = CODED_TRUE;
         (void)Rte_Read_Rp_Align_Write_Nvm_Record_Alignment_Record(&NvMBringUp_NvM_Write_Record);
         NVM_REQ_alignmentHandler();
         break;
      case CDD_SENSORPOS:
         u8_nvblock_write_pending_sensorpos = CODED_TRUE;
         break;
      case UDS_MANUAL_ALIGNMENT:
         u8_nvblock_write_pending_manualalign = CODED_TRUE;
         (void)Rte_Read_Rp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(&ManualParam);
         break;
      case UDS_STATIC_ALIGNMENT:
         u8_nvblock_write_pending_staticalign = CODED_TRUE;
         (void)
            Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
               &StaticParam);
         break;
      default:
         break;
   }
}

/**********************************************************************************************************************
 * Function Name: NVM_REQ_failsafeHandler
 *
 * Handles different cases based on the block status for non-volatile memory operations.
 * --------------------------------------------------------------------------------------------------------------------
 *
 * Description:
 * This function processes write requests based on the FailSafe_ResetReason status, handling various scenarios such as
 * write status reporting and failfalse ramblock
 *
 *********************************************************************************************************************/
static void NVM_REQ_failsafeHandler(void)
{
   (void)Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(&nvblock_status_1);
   if ((NVM_REQ_PENDING != nvblock_status_1))
   {
      *Rte_Pim_FailSafe_ResetReason_PIM() = SWC_PLT_CDD_FailSafe_Ramblock;
      (void)Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_failsafe = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) RE_PLT_Appl_NvMHandler_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Appl_NvMHandler_50ms
    *********************************************************************************************************************/

   static uint8 Align_NvM_Write_Clr_Cnt = 0;
   nvblock_status_1                     = NVM_REQ_NOT_OK;
   if (CODED_TRUE == u8_nvblock_write_pending_alignment)
   {
      NVM_REQ_alignmentHandler();
   }
   else
   {
      /*Temp Logic : To Ensure XCP write is received in Alignment module*/
      Align_NvM_Write_Clr_Cnt++;
      if (Align_NvM_Write_Clr_Cnt > 2)
      {
         Align_NvM_Write_Clr_Cnt = 0;
         NvM_Write_Status        = CODED_FALSE;
      }
   }
   (void)Rte_Write_Pp_NvM_flag_status_Pim_write_status(NvM_Write_Status);

   if (CODED_TRUE == u8_nvblock_write_pending_failsafe)
   {
      NVM_REQ_failsafeHandler();
   }
   else
   {
      /* No action to perform */
   }

   if (CODED_TRUE == u8_nvblock_write_pending_rfefault)
   {
      NVM_REQ_rfefaultHandler();
   }
   else
   {
      /* No action to perform */
   }

   if (CODED_TRUE == u8_nvblock_write_pending_corrfault)
   {
      NVM_REQ_correctablefaultHandler();
   }
   else
   {
      /* No action to perform */
   }
   if (CODED_TRUE == u8_nvblock_write_pending_sensorpos)
   {
      NVM_Sensor_Position_faultHandler();
   }
   else
   {
      /* No action to perform */
   }

   if (CODED_TRUE == u8_nvblock_write_pending_manualalign)
   {
      NVM_REQ_manualalignHandler();
   }
   else
   {
      /* No action to perform */
   }

   if (CODED_TRUE == u8_nvblock_write_pending_staticalign)
   {
      NVM_REQ_staticalignHandler();
   }
   else
   {
      /* No action to perform */
   }

   if (CODED_TRUE == u8_nvblock_write_pending_vseparams)
   {
      NVM_REQ_vseparamsHandler();
   }
   else
   {
      /* No action to perform */
   }
   if (ConfigID_NvM_Write_Status == CODED_FALSE)
   {
      updateConfigId();
   }

   NvMBringUp_NvM_Read_Record = *Rte_Pim_NvMBringUp_PIM();
   (void)Rte_Write_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(&NvMBringUp_NvM_Read_Record);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Appl_NvMHandler_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_Appl_NvMHandler_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) RE_PLT_Appl_NvMHandler_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Appl_NvMHandler_5ms
    *********************************************************************************************************************/
#if 0
   /*Disabling because of DET  FEE_30_FLEXNOR_E_REENTRANCY_VIOLATED */
   Process_MainFunctions();
#endif

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SWC_PLT_Appl_NvMHandler_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(Dt_FailSafe_ResetReason_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Alignment_NvM_Data_Alignment_NvM_Data(const Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(const Dt_FailSafe_ResetReason_T *data)
 *   Std_ReturnType Rte_Write_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(const
 *Dt_Manual_Alignment_Execution_Data_CRC *data) Std_ReturnType Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(const
 *Dt_Rfe_REC_NREC_Fault *data) Std_ReturnType
 *Rte_Write_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(const
 *Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SWC_PLT_Appl_NvMHandler_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) SWC_PLT_Appl_NvMHandler_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: SWC_PLT_Appl_NvMHandler_Init
    *********************************************************************************************************************/
   RFE_R1R2_Fault                     = *Rte_Pim_RFE_R1R2_PIM();
   Correctable_Fault_Ramblock         = *Rte_Pim_Correctable_Fault_PIM();
   NvMBringUp_NvM_Read_Record         = *Rte_Pim_NvMBringUp_PIM();
   SWC_PLT_CDD_FailSafe_read_Ramblock = *Rte_Pim_FailSafe_ResetReason_PIM();
   ManualParam                        = *Rte_Pim_Manual_Alignment_Execution_Data_PIM();
   StaticParam                        = *Rte_Pim_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM();

   /* Write to output ports */
   (void)Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(&RFE_R1R2_Fault);
   (void)Rte_Write_Pp_Alignment_NvM_Data_Alignment_NvM_Data(&NvMBringUp_NvM_Read_Record);
   (void)Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(&SWC_PLT_CDD_FailSafe_read_Ramblock);
   (void)Rte_Write_Pp_Manual_Alignment_Execution_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(&ManualParam);
   (void)
      Rte_Write_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(
         &StaticParam);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Trigger_Write_to_NVM
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NvHandler_Trigger_Write_To_NVM> of PortPrototype
 *<CS_Pp_Trigger_Write_to_NvM>
 *   - triggered by server invocation for OperationPrototype <NvHandler_Trigger_Write_To_NVM> of PortPrototype
 *<CS_Trigger_Write_to_NVM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(Dt_Rfe_REC_NREC_Fault *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Trigger_Write_to_NVM_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE)
Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite,
                     Dt_Nv_Caller_ID dt_Nv_Caller_Id) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: Trigger_Write_to_NVM
    *********************************************************************************************************************/

   if ((u8_ImmidieteWrite == CODED_TRUE) &&
       ((dt_Nv_Caller_Id == CDD_FAIL_SAFE) || (dt_Nv_Caller_Id == RFE_R1R2_FAULT) || (dt_Nv_Caller_Id == CDD_FAILSAFE_ECC)))
   {
      u8_nvblock_write_pending_corrfault = CODED_TRUE;
      u8_nvblock_write_pending_failsafe  = CODED_TRUE;
      u8_nvblock_write_pending_rfefault  = CODED_TRUE;
      Handle_Immediate_Write();
   }
   else
   {
      Process_Nvmblock_CallerID(dt_Nv_Caller_Id);
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: NVM_REQ_rfefaultHandler
 *
 * Handles different cases based on the block status for non-volatile memory operations.
 * --------------------------------------------------------------------------------------------------------------------
 *
 * Description:
 * This function processes write requests based on the R1R2 fault error status, handling various scenarios such as
 * write status reporting and rfe fault
 *
 *********************************************************************************************************************/
static void NVM_REQ_rfefaultHandler(void)
{
   (void)Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(&RFE_R1R2_Fault);
   (void)Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_GetErrorStatus(&nvblock_status_1);
   if ((NVM_REQ_PENDING != nvblock_status_1))
   {
      *Rte_Pim_RFE_R1R2_PIM() = RFE_R1R2_Fault;
      (void)Rte_Call_Rp_SWC_PLT_CDD_Rfe_R1R2_Fault_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_rfefault = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}

/**********************************************************************************************************************
 * Function Name: NVM_REQ_correctablefaultHandler
 *
 * Handles different cases based on the block status for non-volatile memory operations.
 * --------------------------------------------------------------------------------------------------------------------
 *
 * Description:
 * This function processes write requests based on the Correctable fault error status.
 *
 *********************************************************************************************************************/
static void NVM_REQ_correctablefaultHandler(void)
{
   (void)Rte_Read_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(&Correctable_Fault_Ramblock);
   (void)Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_GetErrorStatus(&nvblock_status_1);
   if ((NVM_REQ_PENDING != nvblock_status_1))
   {
      *Rte_Pim_Correctable_Fault_PIM() = Correctable_Fault_Ramblock;
      (void)Rte_Call_Rp_SWC_PLT_CDD_Correctable_Fault_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_corrfault = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}
void updateConfigId(void)
{
   uint8 ErrorStatus = NVM_REQ_NOT_OK;

   // Check the error status of the configuration block
   (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMConfigBlock, &ErrorStatus);

   if ((ErrorStatus != NVM_REQ_OK) && (ErrorStatus != NVM_REQ_PENDING) && (configIdWriteCounter != 0U))
   {
      configIdWriteCounter--;
      if (configIdWriteCounter == 0)
      {
         // Attempt to write the configuration ID block
         nvmWrtStatus = NvM_WriteBlock((NvM_BlockIdType)NvMConf_NvMBlockDescriptor_NvMConfigBlock, &NVM_Config_Ram_Block);
         if (nvmWrtStatus == E_OK)
         {
            configIdWriteCounter = 1000U; // Write initiated, now wait for completion
         }
         else
         {
            configIdWriteCounter = 5000U; // Retry after some time
         }
      }
   }
   else if (ErrorStatus == NVM_REQ_OK)
   {
      // Configuration ID has been successfully written
      ConfigID_NvM_Write_Status = CODED_TRUE;
      configIdWriteCounter      = 0xFFU;
   }
   else
   {
      // No action needed
   }
}

static void NVM_REQ_manualalignHandler(void)
{
   (void)Rte_Call_CS_NvMService_ManualAlignment_GetErrorStatus(&nvblock_status_1);
   if (NVM_REQ_PENDING != nvblock_status_1)
   {
      ManualParam.Data_CRC                           = crc32_sw(0U, (const uint8_t *)&ManualParam.Manual_Alignment_Execution_Data,
                                                                sizeof(ManualParam.Manual_Alignment_Execution_Data));
      *Rte_Pim_Manual_Alignment_Execution_Data_PIM() = ManualParam;
      (void)Rte_Call_CS_NvMService_ManualAlignment_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_manualalign = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}

static void NVM_REQ_staticalignHandler(void)
{
   (void)Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_GetErrorStatus(&nvblock_status_1);
   if (NVM_REQ_PENDING != nvblock_status_1)
   {
      StaticParam.Data_CRC = crc32_sw(0U, (const uint8_t *)&StaticParam.Static_alignment_write_Params,
                                      sizeof(StaticParam.Static_alignment_write_Params));
      *Rte_Pim_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM() = StaticParam;
      (void)Rte_Call_CS_NvMService_Static_Alignment_Engineering_Write_Configuration_Parameters_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_staticalign = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}

static void NVM_REQ_vseparamsHandler(void)
{
   Dt_VSE_NVM_Params VSE_Parameters_Ramblock;

   (void)Rte_Read_Rp_VSE_NVM_Params_De_VSE_NVM_Params(&VSE_Parameters_Ramblock);
   (void)Rte_Call_CS_NvMService_VSE_Parameters_GetErrorStatus(&nvblock_status_1);
   if (NVM_REQ_PENDING != nvblock_status_1)
   {
      *Rte_Pim_VSE_NVM_Params_PIM() = VSE_Parameters_Ramblock;
      (void)Rte_Call_CS_NvMService_VSE_Parameters_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_vseparams = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}

static void NVM_Sensor_Position_faultHandler(void)
{
   Dt_SensorPosition_Data_T Sensor_Position_Ramblock;

   (void)Rte_Read_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(&Sensor_Position_Ramblock);
   (void)Rte_Call_Rp_CDD_SensorPos_UDS_GetErrorStatus(&nvblock_status_1);
   if ((NVM_REQ_PENDING != nvblock_status_1))
   {
      /* Always calculate and store the CRC for the sensor-position ramblock prior to
       * writing to NvM, independent of NVM_CRC_DISABLE (which only gates whether the
       * CRC is validated on read, not whether it is produced on write). */
      {
         uint32 calculated_CRC =
            crc32_sw(0U, (const uint8_t *)&Sensor_Position_Ramblock.SensorPosition_Data, sizeof(Dt_SensorPosition_Status_T));
         Sensor_Position_Ramblock.SensorPos_CRC = calculated_CRC;
      }
      *Rte_Pim_Sensorpos_PIM_UDS() = Sensor_Position_Ramblock;
      (void)Rte_Call_Rp_CDD_SensorPos_UDS_WriteBlock(NULL_PTR);
      u8_nvblock_write_pending_sensorpos = CODED_FALSE;
   }
   else
   {
      /* No action to perform */
   }
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
