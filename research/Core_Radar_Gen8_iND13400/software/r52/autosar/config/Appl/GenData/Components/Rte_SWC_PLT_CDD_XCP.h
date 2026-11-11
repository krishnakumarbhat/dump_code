/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PLT_CDD_XCP.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_XCP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_XCP_H
# define RTE_SWC_PLT_CDD_XCP_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_PLT_CDD_XCP_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req;
extern VAR(Dt_AlignmentModeIn_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis;
extern VAR(Dt_ForceRadiate, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate;
extern VAR(Idt_XCP_Op_Mode_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_Lib_START_SEC_CODE_ASIL_B
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_Lib_STOP_SEC_CODE_ASIL_B
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_ADC_XCP_Req_De_ADC_XCP_Req (0U)
#  define Rte_InitValue_Pp_Alignment_Type_Alignment_Type (0U)
#  define Rte_InitValue_Pp_DSP_Read_Sensitivity_Factor_De_DSP_Read_Sensitivity_Factor (0U)
#  define Rte_InitValue_Pp_DSP_Wr_Sensitivity_Factor_De_DSP_Wr_Read_Sensitivity_Factor (0U)
#  define Rte_InitValue_Pp_Hil_Activation_De_Hil_Activation (0U)
#  define Rte_InitValue_Pp_MPU_lock_request_De_MPU_lock_sts (0U)
#  define Rte_InitValue_Pp_UDP_Logging_Enabled_Flag_De_UDP_Logging_Enabled_Flag (TRUE)
#  define Rte_InitValue_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override (1U)
#  define Rte_InitValue_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag (85U)
#  define Rte_InitValue_Pp_XCP_CW_Mode_De_XCP_CW_Mode (85U)
#  define Rte_InitValue_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis (0U)
#  define Rte_InitValue_Pp_XCP_ForceRadiate_De_XCPForceRadiate (2U)
#  define Rte_InitValue_Pp_XCP_HIL_Mode_De_XCP_HIL_Mode (85U)
#  define Rte_InitValue_Pp_XCP_Itv_IPC_Event_State_De_ITV_EVENT (0U)
#  define Rte_InitValue_Pp_XCP_Itv_IPC_State_De_XCP_SIM_MODE (0U)
#  define Rte_InitValue_Pp_XCP_Itv_IPC_Value_State_De_ITV_VALUE (0U)
#  define Rte_InitValue_Pp_XCP_NvM_Control_De_XCP_NvM_Control (0U)
#  define Rte_InitValue_Pp_XCP_Op_Mode_De_XCP_Op_Mode (0U)
#  define Rte_InitValue_Pp_XCP_PCAN_En_Dis_De_XCP_PCAN_En_Dis (0U)
#  define Rte_InitValue_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration (FALSE)
#  define Rte_InitValue_Pp_XCP_Program_Mode_De_XCP_Program_Mode (FALSE)
#  define Rte_InitValue_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger (85U)
#  define Rte_InitValue_Pp_XCP_VCAN_En_Dis_De_XCP_VCAN_En_Dis (0U)
#  define Rte_InitValue_Rp_Analog_Channel_Count_De_Analog_Channel_Count (0U)
#  define Rte_InitValue_Rp_Application_Checksum_De_Application_Checksum (0U)
#  define Rte_InitValue_Rp_BoardRevision_Xcp_De_BoardRevision_Xcp (0U)
#  define Rte_InitValue_Rp_Keep_Alive_Checksum_De_Keep_Alive_Checksum (0U)
#  define Rte_InitValue_Rp_MCU_Sensor_Count_De_MCU_Sensor_Count (0U)
#  define Rte_InitValue_Rp_MMIC_Count_De_MMIC_Count (0U)
#  define Rte_InitValue_Rp_MPU_lock_sts_De_MPU_lock_sts (0U)
#  define Rte_InitValue_Rp_NvM_flag_status_Pim_write_status (0U)
#  define Rte_InitValue_Rp_Primary_Bootloader_Checksum_De_Primary_Bootloader_Checksum (0U)
#  define Rte_InitValue_Rp_Radar_CMD_Radiate_De_Radar_CMD_Radiate (0U)
#  define Rte_InitValue_Rp_Radar_Init_Status_De_Radar_Init_Status (0U)
#  define Rte_InitValue_Rp_SMC_Checksum_De_SMC_Checksum (0U)
#  define Rte_InitValue_Rp_USC_Checksum_De_USC_Checksum (0U)
#  define Rte_InitValue_Rp_XCP_Data_Flash_Process_De_Data_Flash_Process (0U)
#  define Rte_InitValue_s_aptiv_xcp_can_chn_sel_EN_DIS (FALSE)
#  define Rte_InitValue_s_aptiv_xcp_en_EN_DIS (TRUE)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Table_De_ActiveFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Table_De_ActiveFaultTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Auto_Alignment_Data_Auto_Alignment_Data(P2VAR(Dt_Auto_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Calibration_Version_Info_De_Calibration_Version_Info(P2VAR(Idt_Cal_Version_Info_Type, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Customer_SW_Version_Info_De_Customer_SW_Version_Info(P2VAR(Dt_Customer_SW_Version, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_ID_data_De_ID_data(P2VAR(Dt_ID_data, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Initial_Alignment_Result_Initial_Alignment_Result(P2VAR(Dt_Initial_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_MMIC_Temperature_De_MMIC_Temperature(P2VAR(Idt_Type_MMIC_Temperature, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_PhysicalAdcData_De_PhysicalAdcData(P2VAR(Dt_AdcData_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_RawAdc_Data_Filtered_De_RawAdcData(P2VAR(Dt_RawAdcDataFilt_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(P2VAR(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_SW_Version_Info_De_SW_Version_Info(P2VAR(Idt_SW_Version_Info_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_initial_Alignment_Perform_Result_initial_Alignment_Perform(P2VAR(Dt_Initial_Alignment_Performance_Result_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override(P2CONST(Idt_XCP_Fault_Override_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output(P2CONST(Dt_XCP_Set_Output, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(P2CONST(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Pp_DSP_Read_Sensitivity_Factor_De_DSP_Read_Sensitivity_Factor Rte_Read_SWC_PLT_CDD_XCP_Pp_DSP_Read_Sensitivity_Factor_De_DSP_Read_Sensitivity_Factor
#  define Rte_Read_SWC_PLT_CDD_XCP_Pp_DSP_Read_Sensitivity_Factor_De_DSP_Read_Sensitivity_Factor(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable
#  define Rte_Read_Rp_Active_Fault_Table_De_ActiveFaultTable Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Table_De_ActiveFaultTable
#  define Rte_Read_Rp_Alignment_NvM_Data_Alignment_NvM_Data Rte_Read_SWC_PLT_CDD_XCP_Rp_Alignment_NvM_Data_Alignment_NvM_Data
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Alignment_NvM_Data_Alignment_NvM_Data(data) (*(data) = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data Rte_Read_SWC_PLT_CDD_XCP_Rp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data
#  define Rte_Read_Rp_Analog_Channel_Count_De_Analog_Channel_Count Rte_Read_SWC_PLT_CDD_XCP_Rp_Analog_Channel_Count_De_Analog_Channel_Count
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Analog_Channel_Count_De_Analog_Channel_Count(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Application_Checksum_De_Application_Checksum Rte_Read_SWC_PLT_CDD_XCP_Rp_Application_Checksum_De_Application_Checksum
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Application_Checksum_De_Application_Checksum(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Auto_Alignment_Data_Auto_Alignment_Data Rte_Read_SWC_PLT_CDD_XCP_Rp_Auto_Alignment_Data_Auto_Alignment_Data
#  define Rte_Read_Rp_BoardRevision_Xcp_De_BoardRevision_Xcp Rte_Read_SWC_PLT_CDD_XCP_Rp_BoardRevision_Xcp_De_BoardRevision_Xcp
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_BoardRevision_Xcp_De_BoardRevision_Xcp(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Calibration_Version_Info_De_Calibration_Version_Info Rte_Read_SWC_PLT_CDD_XCP_Rp_Calibration_Version_Info_De_Calibration_Version_Info
#  define Rte_Read_Rp_Customer_SW_Version_Info_De_Customer_SW_Version_Info Rte_Read_SWC_PLT_CDD_XCP_Rp_Customer_SW_Version_Info_De_Customer_SW_Version_Info
#  define Rte_Read_Rp_Fault_Enable_Table_De_FaultEnableTable Rte_Read_SWC_PLT_CDD_XCP_Rp_Fault_Enable_Table_De_FaultEnableTable
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Fault_Enable_Table_De_FaultEnableTable(data) ( \
          Rte_MemCpy32(data, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)) \
          ,((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable Rte_Read_SWC_PLT_CDD_XCP_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable
#  define Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable Rte_Read_SWC_PLT_CDD_XCP_Rp_HistoryFaultTable_De_HistoryFaultTable
#  define Rte_Read_Rp_ID_data_De_ID_data Rte_Read_SWC_PLT_CDD_XCP_Rp_ID_data_De_ID_data
#  define Rte_Read_Rp_Initial_Alignment_Result_Initial_Alignment_Result Rte_Read_SWC_PLT_CDD_XCP_Rp_Initial_Alignment_Result_Initial_Alignment_Result
#  define Rte_Read_Rp_Keep_Alive_Checksum_De_Keep_Alive_Checksum Rte_Read_SWC_PLT_CDD_XCP_Rp_Keep_Alive_Checksum_De_Keep_Alive_Checksum
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Keep_Alive_Checksum_De_Keep_Alive_Checksum(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_MCU_Sensor_Count_De_MCU_Sensor_Count Rte_Read_SWC_PLT_CDD_XCP_Rp_MCU_Sensor_Count_De_MCU_Sensor_Count
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_MCU_Sensor_Count_De_MCU_Sensor_Count(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_MMIC_Count_De_MMIC_Count Rte_Read_SWC_PLT_CDD_XCP_Rp_MMIC_Count_De_MMIC_Count
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_MMIC_Count_De_MMIC_Count(data) (*(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_MMIC_Temperature_De_MMIC_Temperature Rte_Read_SWC_PLT_CDD_XCP_Rp_MMIC_Temperature_De_MMIC_Temperature
#  define Rte_Read_Rp_MPU_lock_sts_De_MPU_lock_sts Rte_Read_SWC_PLT_CDD_XCP_Rp_MPU_lock_sts_De_MPU_lock_sts
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_MPU_lock_sts_De_MPU_lock_sts(data) (*(data) = Rte_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_NvM_flag_status_Pim_write_status Rte_Read_SWC_PLT_CDD_XCP_Rp_NvM_flag_status_Pim_write_status
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_NvM_flag_status_Pim_write_status(data) (*(data) = Rte_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData Rte_Read_SWC_PLT_CDD_XCP_Rp_PhysicalAdcData_De_PhysicalAdcData
#  define Rte_Read_Rp_Primary_Bootloader_Checksum_De_Primary_Bootloader_Checksum Rte_Read_SWC_PLT_CDD_XCP_Rp_Primary_Bootloader_Checksum_De_Primary_Bootloader_Checksum
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Primary_Bootloader_Checksum_De_Primary_Bootloader_Checksum(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Radar_CMD_Radiate_De_Radar_CMD_Radiate Rte_Read_SWC_PLT_CDD_XCP_Rp_Radar_CMD_Radiate_De_Radar_CMD_Radiate
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Radar_CMD_Radiate_De_Radar_CMD_Radiate(data) (*(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Radar_Init_Status_De_Radar_Init_Status Rte_Read_SWC_PLT_CDD_XCP_Rp_Radar_Init_Status_De_Radar_Init_Status
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Radar_Init_Status_De_Radar_Init_Status(data) (*(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Radar_RFBIST_Calib_Status_De_Radar_RFBIST_Calib_Status Rte_Read_SWC_PLT_CDD_XCP_Rp_Radar_RFBIST_Calib_Status_De_Radar_RFBIST_Calib_Status
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_Radar_RFBIST_Calib_Status_De_Radar_RFBIST_Calib_Status(data) (*(data) = Rte_C_Idt_XCP_RFBIST_Status_T_15E3F9BF21B19D5CA8FB804F198F59EC, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_RawAdc_Data_Filtered_De_RawAdcData Rte_Read_SWC_PLT_CDD_XCP_Rp_RawAdc_Data_Filtered_De_RawAdcData
#  define Rte_Read_Rp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered Rte_Read_SWC_PLT_CDD_XCP_Rp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered
#  define Rte_Read_Rp_SMC_Checksum_De_SMC_Checksum Rte_Read_SWC_PLT_CDD_XCP_Rp_SMC_Checksum_De_SMC_Checksum
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_SMC_Checksum_De_SMC_Checksum(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_SW_Version_Info_De_SW_Version_Info Rte_Read_SWC_PLT_CDD_XCP_Rp_SW_Version_Info_De_SW_Version_Info
#  define Rte_Read_Rp_USC_Checksum_De_USC_Checksum Rte_Read_SWC_PLT_CDD_XCP_Rp_USC_Checksum_De_USC_Checksum
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_USC_Checksum_De_USC_Checksum(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_XCP_DID_RESP_De_XCP_DID_RESP Rte_Read_SWC_PLT_CDD_XCP_Rp_XCP_DID_RESP_De_XCP_DID_RESP
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_XCP_DID_RESP_De_XCP_DID_RESP(data) (*(data) = Rte_C_Dt_Xcp_Read_Write_Did_T_42D1DCC3F8BF6F5DC60D9C88450ACD3F, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_XCP_Data_Flash_Process_De_Data_Flash_Process Rte_Read_SWC_PLT_CDD_XCP_Rp_XCP_Data_Flash_Process_De_Data_Flash_Process
#  define Rte_Read_SWC_PLT_CDD_XCP_Rp_XCP_Data_Flash_Process_De_Data_Flash_Process(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_initial_Alignment_Perform_Result_initial_Alignment_Perform Rte_Read_SWC_PLT_CDD_XCP_Rp_initial_Alignment_Perform_Result_initial_Alignment_Perform
#  define Rte_Read_s_aptiv_xcp_can_chn_sel_EN_DIS Rte_Read_SWC_PLT_CDD_XCP_s_aptiv_xcp_can_chn_sel_EN_DIS
#  define Rte_Read_SWC_PLT_CDD_XCP_s_aptiv_xcp_can_chn_sel_EN_DIS(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_s_aptiv_xcp_en_EN_DIS Rte_Read_SWC_PLT_CDD_XCP_s_aptiv_xcp_en_EN_DIS
#  define Rte_Read_SWC_PLT_CDD_XCP_s_aptiv_xcp_en_EN_DIS(data) (*(data) = TRUE, ((Std_ReturnType)RTE_E_UNCONNECTED))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_ADC_XCP_Req_De_ADC_XCP_Req Rte_Write_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req(data) (Rte_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Alignment_Type_Alignment_Type Rte_Write_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type(data) (Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM Rte_Write_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM
#  define Rte_Write_Pp_DSP_Wr_Sensitivity_Factor_De_DSP_Wr_Read_Sensitivity_Factor Rte_Write_SWC_PLT_CDD_XCP_Pp_DSP_Wr_Sensitivity_Factor_De_DSP_Wr_Read_Sensitivity_Factor
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_DSP_Wr_Sensitivity_Factor_De_DSP_Wr_Read_Sensitivity_Factor(data) (RTE_E_OK)
#  define Rte_Write_Pp_DSP_XCP_Target_Select_De_DSP_XCP_Target_Select Rte_Write_SWC_PLT_CDD_XCP_Pp_DSP_XCP_Target_Select_De_DSP_XCP_Target_Select
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_DSP_XCP_Target_Select_De_DSP_XCP_Target_Select(data) (RTE_E_OK)
#  define Rte_Write_Pp_Hil_Activation_De_Hil_Activation Rte_Write_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation(data) (Rte_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MPU_lock_request_De_MPU_lock_sts Rte_Write_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts(data) (Rte_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_UDP_Logging_Enabled_Flag_De_UDP_Logging_Enabled_Flag Rte_Write_SWC_PLT_CDD_XCP_Pp_UDP_Logging_Enabled_Flag_De_UDP_Logging_Enabled_Flag
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_UDP_Logging_Enabled_Flag_De_UDP_Logging_Enabled_Flag(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_CW_Mode_De_XCP_CW_Mode Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_DID_CMD_De_XCP_DID_CMD Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_DID_CMD_De_XCP_DID_CMD
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_DID_CMD_De_XCP_DID_CMD(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_Fault_Injection_De_Xcp_Fault_Injection Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Injection_De_Xcp_Fault_Injection
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Injection_De_Xcp_Fault_Injection(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Fault_Override_De_XCP_Fault_Override Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override
#  define Rte_Write_Pp_XCP_ForceRadiate_De_XCPForceRadiate Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_HIL_Mode_De_XCP_HIL_Mode Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_HIL_Mode_De_XCP_HIL_Mode
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_HIL_Mode_De_XCP_HIL_Mode(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Hw_Interface_Cntrl_De_Hw_Interface_Cntrl Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Hw_Interface_Cntrl_De_Hw_Interface_Cntrl
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Hw_Interface_Cntrl_De_Hw_Interface_Cntrl(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Itv_IPC_Event_State_De_ITV_EVENT Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Itv_IPC_Event_State_De_ITV_EVENT
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Itv_IPC_Event_State_De_ITV_EVENT(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Itv_IPC_State_De_XCP_SIM_MODE Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Itv_IPC_State_De_XCP_SIM_MODE
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Itv_IPC_State_De_XCP_SIM_MODE(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Itv_IPC_Value_State_De_ITV_VALUE Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Itv_IPC_Value_State_De_ITV_VALUE
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Itv_IPC_Value_State_De_ITV_VALUE(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_LED_OP_Cntrl_De_XCP_LED_OP_Cntrl Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_LED_OP_Cntrl_De_XCP_LED_OP_Cntrl
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_LED_OP_Cntrl_De_XCP_LED_OP_Cntrl(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_NvM_Control_De_XCP_NvM_Control Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_NvM_Control_De_XCP_NvM_Control
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_NvM_Control_De_XCP_NvM_Control(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Op_Mode_De_XCP_Op_Mode Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_PCAN_En_Dis_De_XCP_PCAN_En_Dis Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_PCAN_En_Dis_De_XCP_PCAN_En_Dis
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_PCAN_En_Dis_De_XCP_PCAN_En_Dis(data) (RTE_E_OK)
#  define Rte_Write_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_Program_Mode_De_XCP_Program_Mode Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger(data) (Rte_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_XCP_Set_Output_State_De_XCP_Set_Output Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output
#  define Rte_Write_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable
#  define Rte_Write_Pp_XCP_VCAN_En_Dis_De_XCP_VCAN_En_Dis Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_VCAN_En_Dis_De_XCP_VCAN_En_Dis
#  define Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_VCAN_En_Dis_De_XCP_VCAN_En_Dis(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_Appl_Project_START_SEC_CODE
#  include "SWC_Appl_Project_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_Appl_Project_CODE) CS_Signal_Integrity_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_Appl_Project_STOP_SEC_CODE
#  include "SWC_Appl_Project_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_CDD_IPC_START_SEC_CODE
#  include "SWC_CDD_IPC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_CDD_IPC_CODE) CS_IPC_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_CDD_IPC_STOP_SEC_CODE
#  include "SWC_CDD_IPC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_Communication_START_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_PCAN_Srv_DisableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_Communication_STOP_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_Communication_START_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_PCAN_Srv_EnableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_Communication_STOP_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_Communication_START_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_VCAN_Srv_DisableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_Communication_STOP_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_Communication_START_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_VCAN_Srv_EnableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_Communication_STOP_SEC_CODE
#  include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_Diag_START_SEC_CODE
#  include "SWC_PLT_Appl_Diag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_Diag_CODE) CS_Diag_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_Diag_STOP_SEC_CODE
#  include "SWC_PLT_Appl_Diag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_IoHwAb_START_SEC_CODE
#  include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, SWC_PLT_Appl_IoHwAb_CODE) CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option, P2VAR(DT_Thermal_Monitor_Temperatures_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_VAR) reqValue); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_IoHwAb_STOP_SEC_CODE
#  include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_ModeManager_START_SEC_CODE
#  include "SWC_PLT_Appl_ModeManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_ModeManager_CODE) CS_Modemanager_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_ModeManager_STOP_SEC_CODE
#  include "SWC_PLT_Appl_ModeManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_Appl_PlatformTime_START_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) CS_PlatformTime_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_PlatformTime_STOP_SEC_CODE
#  include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_ExternalWdg_START_SEC_CODE
#  include "SWC_PLT_CDD_ExternalWdg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) CS_External_Watchdog_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_ExternalWdg_STOP_SEC_CODE
#  include "SWC_PLT_CDD_ExternalWdg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_FCRU_START_SEC_CODE
#  include "SWC_PLT_CDD_FCRU_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_FCRU_CODE) CS_FCRU_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_FCRU_STOP_SEC_CODE
#  include "SWC_PLT_CDD_FCRU_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_FailSafe_START_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) CS_FailSafe_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_FailSafe_STOP_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_MCU_Safety_START_SEC_CODE
#  include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) CS_MCU_Safety_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_MCU_Safety_STOP_SEC_CODE
#  include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_MCU_Safety_START_SEC_CODE
#  include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECU_Soft_Reset(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_MCU_Safety_STOP_SEC_CODE
#  include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_Radar_Control_START_SEC_CODE
#  include "SWC_PLT_CDD_Radar_Control_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) CS_Radar_control_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_Radar_Control_STOP_SEC_CODE
#  include "SWC_PLT_CDD_Radar_Control_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define SWC_PLT_CDD_WdgHandler_START_SEC_CODE
#  include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) CS_WdgHandler_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_WdgHandler_STOP_SEC_CODE
#  include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Alignment_Fault_Injection_read(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_Diag_Fault_Injection_Read(arg1, arg2) (CS_Diag_Fault_Injection_Read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_External_Watchdog_Fault_Injection_Read(arg1, arg2) (CS_External_Watchdog_Fault_Injection_Read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_FCCU_Fault_Injection_Read(arg1, arg2) (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_FCRU_Fault_Injection_Read(arg1, arg2) (CS_FCRU_Fault_Injection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_FailSafe_Fault_Injection_Read(arg1, arg2) (CS_FailSafe_Fault_Injection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_IPC_Fault_Injection_Read(arg1, arg2) (CS_IPC_Fault_Injection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_MCU_Safety_Fault_Injection_Read(arg1, arg2) (CS_MCU_Safety_Fault_Injection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Modemanager_Fault_Injection_Read(arg1, arg2) (CS_Modemanager_Fault_Injection_Read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_PlatformTime_Fault_Injection_Read(arg1, arg2) (CS_PlatformTime_Fault_Injection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Radar_control_Fault_Injection_Read(arg1, arg2) (CS_Radar_control_Fault_Injection_Read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_Rp_PCAN_stop_periodic_interface_control_stop_periodic_interface_control(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_Rp_VCAN_stop_periodic_interface_control_Operation() (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_Rp_ethernet_platform_stop_periodic_interface_control_ethernet_platform_stop_periodic_interface_control(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_Rp_ethernet_project_stop_periodic_interface_control_Operation() (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_Signal_Integrity_Fault_Injection_Read(arg1, arg2) (CS_Signal_Integrity_Fault_Injection_Read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_ThermMonTemp_Read CS_ThermMonTemp_Read
#  define Rte_Call_CS_Trigger_Clear_Faults_Operation_Operation() (RTE_E_UNCONNECTED)
#  define Rte_Call_CS_WdgHandler_Fault_Injection_Read(arg1, arg2) (CS_WdgHandler_Fault_Injection_Read(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_XCP_FCCU_FakeFault_Inject_Read(arg1, arg2, arg3) (RTE_E_UNCONNECTED)
#  define Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset() (ECU_Soft_Reset(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Rp_PCAN_Srv_DisableAppTx_Operation() (Pp_PCAN_Srv_DisableAppTx_Operation(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Rp_PCAN_Srv_EnableAppTx_Operation() (Pp_PCAN_Srv_EnableAppTx_Operation(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Rp_VCAN_Srv_DisableAppTx_Operation() (Pp_VCAN_Srv_DisableAppTx_Operation(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Rp_VCAN_Srv_EnableAppTx_Operation() (Pp_VCAN_Srv_EnableAppTx_Operation(), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_XCP_START_SEC_CODE
# include "SWC_PLT_CDD_XCP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Pp_XCP_Enable_Disable_Status CS_Pp_XCP_Enable_Disable_Status
#  define RTE_RUNNABLE_RE_XCP_10ms RE_XCP_10ms
#  define RTE_RUNNABLE_RE_XCP_50ms RE_XCP_50ms
#  define RTE_RUNNABLE_RE_XCP_Init RE_XCP_Init
#  define RTE_RUNNABLE_Trigger_Periodic_XCP_Event Trigger_Periodic_XCP_Event
# endif

FUNC(void, SWC_PLT_CDD_XCP_CODE) CS_Pp_XCP_Enable_Disable_Status(XCP_Status_T XCP_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, SWC_PLT_CDD_XCP_CODE) Trigger_Periodic_XCP_Event(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define SWC_PLT_CDD_XCP_STOP_SEC_CODE
# include "SWC_PLT_CDD_XCP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Pi_NCFFchannel_IC_E_NOT_OK (1U)

#  define RTE_E_Pi_ThermMonTemp_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_XCP_Event_Trigger_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_XCP_Event_Trigger_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_XCP_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
