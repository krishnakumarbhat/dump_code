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
 *             File:  Rte_SWC_PLT_Appl_Communication.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_Communication>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_COMMUNICATION_H
# define RTE_SWC_PLT_APPL_COMMUNICATION_H

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

# include "Rte_SWC_PLT_Appl_Communication_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault;
extern VAR(BswM_SDC_SdClientServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode;
extern VAR(BswM_SDC_SdConsumedEventGroupRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode;
extern VAR(BswM_SDC_SdServerServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode;
extern VAR(BswM_SDC_SdServerServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode;
extern VAR(BswM_SDC_SdServerServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode;
extern VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;
extern VAR(Dt_STS_No_TSyn_Error, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error;
extern VAR(Dt_Time_Stamp_Delta, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta;
extern VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault (170U)
#  define Rte_InitValue_Pp_RDR_NM_CAN_NM_State_Vdp_RDR_NM_CAN_NM_State (0U)
#  define Rte_InitValue_Pp_RDR_NM_CBV_ActWakeBit_4_Vdp_RDR_NM_CBV_ActWakeBit_4 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_NMCoordBit_3_Vdp_RDR_NM_CBV_NMCoordBit_3 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_PNIBit_6_Vdp_RDR_NM_CBV_PNIBit_6 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_ReptMsgBit0_Vdp_RDR_NM_CBV_ReptMsgBit0 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_ResdBit_1_Vdp_RDR_NM_CBV_ResdBit_1 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_ResdBit_2_Vdp_RDR_NM_CBV_ResdBit_2 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_ResdBit_5_Vdp_RDR_NM_CBV_ResdBit_5 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_CBV_ResdBit_7_Vdp_RDR_NM_CBV_ResdBit_7 (FALSE)
#  define Rte_InitValue_Pp_RDR_NM_PNC_Reserved1_Vdp_RDR_NM_PNC_Reserved1 (0U)
#  define Rte_InitValue_Pp_RDR_NM_PNC_Reserved2_Vdp_RDR_NM_PNC_Reserved2 (0U)
#  define Rte_InitValue_Pp_RDR_NM_PNC_Reserved3_Vdp_RDR_NM_PNC_Reserved3 (0U)
#  define Rte_InitValue_Pp_RDR_NM_PN_User_Data_Vdp_RDR_NM_PN_User_Data (0U)
#  define Rte_InitValue_Pp_RDR_NM_Wakeup_And_Reason_Vdp_RDR_NM_Wakeup_And_Reason (0U)
#  define Rte_InitValue_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Pp_WarningRelevantObjectDetected_AL_Vdp_WarningRelevantObjectDetected_AL (0U)
#  define Rte_InitValue_Rp_OperationMode_System_De_OperationMode_System (0U)
#  define Rte_InitValue_Rp_TSYNC_CRC_Vdp_TSYNC_CRC (0U)
#  define Rte_InitValue_Rp_TSYN_OVS_Vdp_TSYN_OVS (0U)
#  define Rte_InitValue_Rp_TSYN_PDU_Vdp_TSYN_PDU (40U)
#  define Rte_InitValue_Rp_TSYN_RESERVED_Vdp_TSYN_RESERVED (0U)
#  define Rte_InitValue_Rp_TSYN_SEQUENCE_COUNTER_Vdp_TSYN_SEQUENCE_COUNTER (0U)
#  define Rte_InitValue_Rp_TSYN_SGW_Vdp_TSYN_SGW (FALSE)
#  define Rte_InitValue_Rp_TSYN_SYNCTIME_NANOSEC_Vdp_TSYN_SYNCTIME_NANOSEC (0U)
#  define Rte_InitValue_Rp_TSYN_SYNCTIME_SEC_Vdp_TSYN_SYNCTIME_SEC (0U)
#  define Rte_InitValue_Rp_TSYN_TIMEDOMAIN_Vdp_TSYN_TIMEDOMAIN (0U)
#  define Rte_InitValue_Rp_TSYN_USERBYTE_Vdp_TSYN_USERBYTE (0U)
#  define Rte_InitValue_Rp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error (0U)
#  define Rte_InitValue_Rp_Time_Stamp_Delta_De_Time_Stamp_Delta (0)
#  define Rte_InitValue_Rp_Vbatt_State_De_Vbatt_State (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_RP_RDR_Vehicle_Status_Vehicle_Status(P2VAR(SR_VEHICLE_STATUS_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ADAS_FN_Enable_disable_sts_ALVCAN_Vdp_SG_ADAS_FN_Enable_disable_sts_ALVCAN(P2VAR(I_SG_ADAS_FN_Enable_disable_sts_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CCVS1_ALVCAN_Vdp_SG_CCVS1_ALVCAN(P2VAR(I_SG_CCVS1_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_16_ALVCAN_Vdp_SG_CLS_Tx_16_ALVCAN(P2VAR(I_SG_CLS_Tx_16_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_4_ALVCAN_Vdp_SG_CLS_Tx_4_ALVCAN(P2VAR(I_SG_CLS_Tx_4_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_00_ALVCAN_Vdp_SG_ETC2_00_ALVCAN(P2VAR(I_SG_ETC2_00_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_03_ALVCAN_Vdp_SG_ETC2_03_ALVCAN(P2VAR(I_SG_ETC2_03_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN(P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN(P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_001_004_AL_Vdp_SG_Fusion_Detections_001_004_AL(P2VAR(I_SG_Fusion_Detections_001_004_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_005_008_AL_Vdp_SG_Fusion_Detections_005_008_AL(P2VAR(I_SG_Fusion_Detections_005_008_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_009_012_AL_Vdp_SG_Fusion_Detections_009_012_AL(P2VAR(I_SG_Fusion_Detections_009_012_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_013_016_AL_Vdp_SG_Fusion_Detections_013_016_AL(P2VAR(I_SG_Fusion_Detections_013_016_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_017_020_AL_Vdp_SG_Fusion_Detections_017_020_AL(P2VAR(I_SG_Fusion_Detections_017_020_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_021_024_AL_Vdp_SG_Fusion_Detections_021_024_AL(P2VAR(I_SG_Fusion_Detections_021_024_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_025_028_AL_Vdp_SG_Fusion_Detections_025_028_AL(P2VAR(I_SG_Fusion_Detections_025_028_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_029_032_AL_Vdp_SG_Fusion_Detections_029_032_AL(P2VAR(I_SG_Fusion_Detections_029_032_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_033_036_AL_Vdp_SG_Fusion_Detections_033_036_AL(P2VAR(I_SG_Fusion_Detections_033_036_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_037_040_AL_Vdp_SG_Fusion_Detections_037_040_AL(P2VAR(I_SG_Fusion_Detections_037_040_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_041_044_AL_Vdp_SG_Fusion_Detections_041_044_AL(P2VAR(I_SG_Fusion_Detections_041_044_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_045_048_AL_Vdp_SG_Fusion_Detections_045_048_AL(P2VAR(I_SG_Fusion_Detections_045_048_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_049_052_AL_Vdp_SG_Fusion_Detections_049_052_AL(P2VAR(I_SG_Fusion_Detections_049_052_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_053_056_AL_Vdp_SG_Fusion_Detections_053_056_AL(P2VAR(I_SG_Fusion_Detections_053_056_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_057_060_AL_Vdp_SG_Fusion_Detections_057_060_AL(P2VAR(I_SG_Fusion_Detections_057_060_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_061_064_AL_Vdp_SG_Fusion_Detections_061_064_AL(P2VAR(I_SG_Fusion_Detections_061_064_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_065_068_AL_Vdp_SG_Fusion_Detections_065_068_AL(P2VAR(I_SG_Fusion_Detections_065_068_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_069_072_AL_Vdp_SG_Fusion_Detections_069_072_AL(P2VAR(I_SG_Fusion_Detections_069_072_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_073_076_AL_Vdp_SG_Fusion_Detections_073_076_AL(P2VAR(I_SG_Fusion_Detections_073_076_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_077_080_AL_Vdp_SG_Fusion_Detections_077_080_AL(P2VAR(I_SG_Fusion_Detections_077_080_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_081_084_AL_Vdp_SG_Fusion_Detections_081_084_AL(P2VAR(I_SG_Fusion_Detections_081_084_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_085_088_AL_Vdp_SG_Fusion_Detections_085_088_AL(P2VAR(I_SG_Fusion_Detections_085_088_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_089_092_AL_Vdp_SG_Fusion_Detections_089_092_AL(P2VAR(I_SG_Fusion_Detections_089_092_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_093_096_AL_Vdp_SG_Fusion_Detections_093_096_AL(P2VAR(I_SG_Fusion_Detections_093_096_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_097_100_AL_Vdp_SG_Fusion_Detections_097_100_AL(P2VAR(I_SG_Fusion_Detections_097_100_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_101_104_AL_Vdp_SG_Fusion_Detections_101_104_AL(P2VAR(I_SG_Fusion_Detections_101_104_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_105_108_AL_Vdp_SG_Fusion_Detections_105_108_AL(P2VAR(I_SG_Fusion_Detections_105_108_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_109_112_AL_Vdp_SG_Fusion_Detections_109_112_AL(P2VAR(I_SG_Fusion_Detections_109_112_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_113_116_AL_Vdp_SG_Fusion_Detections_113_116_AL(P2VAR(I_SG_Fusion_Detections_113_116_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_117_120_AL_Vdp_SG_Fusion_Detections_117_120_AL(P2VAR(I_SG_Fusion_Detections_117_120_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_121_124_AL_Vdp_SG_Fusion_Detections_121_124_AL(P2VAR(I_SG_Fusion_Detections_121_124_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_125_128_AL_Vdp_SG_Fusion_Detections_125_128_AL(P2VAR(I_SG_Fusion_Detections_125_128_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN(P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN(P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN(P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN(P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN_Vdp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN(P2VAR(I_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CCVS1_ALPCAN_Vdp_SG_GW_CCVS1_ALPCAN(P2VAR(I_SG_GW_CCVS1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_16_ALPCAN_Vdp_SG_GW_CLS_Tx_16_ALPCAN(P2VAR(I_SG_GW_CLS_Tx_16_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_4_ALPCAN_Vdp_SG_GW_CLS_Tx_4_ALPCAN(P2VAR(I_SG_GW_CLS_Tx_4_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_03_ALPCAN_Vdp_SG_GW_ETC2_03_ALPCAN(P2VAR(I_SG_GW_ETC2_03_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_ALPCAN_Vdp_SG_GW_ETC2_ALPCAN(P2VAR(I_SG_GW_ETC2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_OEL_ALPCAN_Vdp_SG_GW_OEL_ALPCAN(P2VAR(I_SG_GW_OEL_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_SAS_ALPCAN_Vdp_SG_GW_SAS_ALPCAN(P2VAR(I_SG_GW_SAS_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_TD_ALPCAN_Vdp_SG_GW_TD_ALPCAN(P2VAR(I_SG_GW_TD_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VDC2_ALPCAN_Vdp_SG_GW_VDC2_ALPCAN(P2VAR(I_SG_GW_VDC2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VD_ALPCAN_Vdp_SG_GW_VD_ALPCAN(P2VAR(I_SG_GW_VD_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VI_ALPCAN_Vdp_SG_GW_VI_ALPCAN(P2VAR(I_SG_GW_VI_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_OEL_ALVCAN_Vdp_SG_OEL_ALVCAN(P2VAR(I_SG_OEL_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_SAS_ALVCAN_Vdp_SG_SAS_ALVCAN(P2VAR(I_SG_SAS_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_TD_ALVCAN_Vdp_SG_TD_ALVCAN(P2VAR(I_SG_TD_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VDC2_ALVCAN_Vdp_SG_VDC2_ALVCAN(P2VAR(I_SG_VDC2_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VD_ALVCAN_Vdp_SG_VD_ALVCAN(P2VAR(I_SG_VD_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VI_ALVCAN_Vdp_SG_VI_ALVCAN(P2VAR(I_SG_VI_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL(P2VAR(I_SG_VehicleStatus_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event(P2CONST(SR_DETECTIONS_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info(P2CONST(SR_RADAR_SW_INFO_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status(P2CONST(SR_RADAR_STATUS_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL(P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL(P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL(P2CONST(I_SG_Detections_001_004_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL(P2CONST(I_SG_Detections_005_008_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL(P2CONST(I_SG_Detections_009_012_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL(P2CONST(I_SG_Detections_013_016_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL(P2CONST(I_SG_Detections_017_020_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL(P2CONST(I_SG_Detections_021_024_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL(P2CONST(I_SG_Detections_025_028_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL(P2CONST(I_SG_Detections_029_032_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL(P2CONST(I_SG_Detections_033_036_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL(P2CONST(I_SG_Detections_037_040_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL(P2CONST(I_SG_Detections_041_044_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL(P2CONST(I_SG_Detections_045_048_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL(P2CONST(I_SG_Detections_049_052_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL(P2CONST(I_SG_Detections_053_056_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL(P2CONST(I_SG_Detections_057_060_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL(P2CONST(I_SG_Detections_061_064_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL(P2CONST(I_SG_Detections_065_068_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL(P2CONST(I_SG_Detections_069_072_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL(P2CONST(I_SG_Detections_073_076_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL(P2CONST(I_SG_Detections_077_080_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL(P2CONST(I_SG_Detections_081_084_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL(P2CONST(I_SG_Detections_085_088_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL(P2CONST(I_SG_Detections_089_092_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL(P2CONST(I_SG_Detections_093_096_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL(P2CONST(I_SG_Detections_097_100_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL(P2CONST(I_SG_Detections_101_104_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL(P2CONST(I_SG_Detections_105_108_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL(P2CONST(I_SG_Detections_109_112_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL(P2CONST(I_SG_Detections_113_116_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL(P2CONST(I_SG_Detections_117_120_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL(P2CONST(I_SG_Detections_121_124_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL(P2CONST(I_SG_Detections_125_128_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_129_132_AL_Vdp_SG_Detections_129_132_AL(P2CONST(I_SG_Detections_129_132_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_133_136_AL_Vdp_SG_Detections_133_136_AL(P2CONST(I_SG_Detections_133_136_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_137_140_AL_Vdp_SG_Detections_137_140_AL(P2CONST(I_SG_Detections_137_140_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_141_144_AL_Vdp_SG_Detections_141_144_AL(P2CONST(I_SG_Detections_141_144_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_145_148_AL_Vdp_SG_Detections_145_148_AL(P2CONST(I_SG_Detections_145_148_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_149_152_AL_Vdp_SG_Detections_149_152_AL(P2CONST(I_SG_Detections_149_152_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_153_156_AL_Vdp_SG_Detections_153_156_AL(P2CONST(I_SG_Detections_153_156_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_157_160_AL_Vdp_SG_Detections_157_160_AL(P2CONST(I_SG_Detections_157_160_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_161_164_AL_Vdp_SG_Detections_161_164_AL(P2CONST(I_SG_Detections_161_164_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_165_168_AL_Vdp_SG_Detections_165_168_AL(P2CONST(I_SG_Detections_165_168_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_169_172_AL_Vdp_SG_Detections_169_172_AL(P2CONST(I_SG_Detections_169_172_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_173_176_AL_Vdp_SG_Detections_173_176_AL(P2CONST(I_SG_Detections_173_176_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_177_180_AL_Vdp_SG_Detections_177_180_AL(P2CONST(I_SG_Detections_177_180_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_181_184_AL_Vdp_SG_Detections_181_184_AL(P2CONST(I_SG_Detections_181_184_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_185_188_AL_Vdp_SG_Detections_185_188_AL(P2CONST(I_SG_Detections_185_188_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_189_192_AL_Vdp_SG_Detections_189_192_AL(P2CONST(I_SG_Detections_189_192_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_193_196_AL_Vdp_SG_Detections_193_196_AL(P2CONST(I_SG_Detections_193_196_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_197_200_AL_Vdp_SG_Detections_197_200_AL(P2CONST(I_SG_Detections_197_200_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_201_204_AL_Vdp_SG_Detections_201_204_AL(P2CONST(I_SG_Detections_201_204_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_205_208_AL_Vdp_SG_Detections_205_208_AL(P2CONST(I_SG_Detections_205_208_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_209_212_AL_Vdp_SG_Detections_209_212_AL(P2CONST(I_SG_Detections_209_212_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_213_216_AL_Vdp_SG_Detections_213_216_AL(P2CONST(I_SG_Detections_213_216_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_217_220_AL_Vdp_SG_Detections_217_220_AL(P2CONST(I_SG_Detections_217_220_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_221_224_AL_Vdp_SG_Detections_221_224_AL(P2CONST(I_SG_Detections_221_224_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_225_228_AL_Vdp_SG_Detections_225_228_AL(P2CONST(I_SG_Detections_225_228_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_229_232_AL_Vdp_SG_Detections_229_232_AL(P2CONST(I_SG_Detections_229_232_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_233_236_AL_Vdp_SG_Detections_233_236_AL(P2CONST(I_SG_Detections_233_236_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_237_240_AL_Vdp_SG_Detections_237_240_AL(P2CONST(I_SG_Detections_237_240_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_241_244_AL_Vdp_SG_Detections_241_244_AL(P2CONST(I_SG_Detections_241_244_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_245_248_AL_Vdp_SG_Detections_245_248_AL(P2CONST(I_SG_Detections_245_248_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_249_252_AL_Vdp_SG_Detections_249_252_AL(P2CONST(I_SG_Detections_249_252_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_253_256_AL_Vdp_SG_Detections_253_256_AL(P2CONST(I_SG_Detections_253_256_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_257_260_AL_Vdp_SG_Detections_257_260_AL(P2CONST(I_SG_Detections_257_260_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_261_264_AL_Vdp_SG_Detections_261_264_AL(P2CONST(I_SG_Detections_261_264_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_265_268_AL_Vdp_SG_Detections_265_268_AL(P2CONST(I_SG_Detections_265_268_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_269_272_AL_Vdp_SG_Detections_269_272_AL(P2CONST(I_SG_Detections_269_272_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_273_276_AL_Vdp_SG_Detections_273_276_AL(P2CONST(I_SG_Detections_273_276_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_277_280_AL_Vdp_SG_Detections_277_280_AL(P2CONST(I_SG_Detections_277_280_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_281_284_AL_Vdp_SG_Detections_281_284_AL(P2CONST(I_SG_Detections_281_284_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_285_288_AL_Vdp_SG_Detections_285_288_AL(P2CONST(I_SG_Detections_285_288_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_289_292_AL_Vdp_SG_Detections_289_292_AL(P2CONST(I_SG_Detections_289_292_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_293_296_AL_Vdp_SG_Detections_293_296_AL(P2CONST(I_SG_Detections_293_296_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_297_300_AL_Vdp_SG_Detections_297_300_AL(P2CONST(I_SG_Detections_297_300_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_301_304_AL_Vdp_SG_Detections_301_304_AL(P2CONST(I_SG_Detections_301_304_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_305_308_AL_Vdp_SG_Detections_305_308_AL(P2CONST(I_SG_Detections_305_308_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_309_312_AL_Vdp_SG_Detections_309_312_AL(P2CONST(I_SG_Detections_309_312_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_313_316_AL_Vdp_SG_Detections_313_316_AL(P2CONST(I_SG_Detections_313_316_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_317_320_AL_Vdp_SG_Detections_317_320_AL(P2CONST(I_SG_Detections_317_320_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_321_324_AL_Vdp_SG_Detections_321_324_AL(P2CONST(I_SG_Detections_321_324_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_325_328_AL_Vdp_SG_Detections_325_328_AL(P2CONST(I_SG_Detections_325_328_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_329_332_AL_Vdp_SG_Detections_329_332_AL(P2CONST(I_SG_Detections_329_332_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_333_336_AL_Vdp_SG_Detections_333_336_AL(P2CONST(I_SG_Detections_333_336_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_337_340_AL_Vdp_SG_Detections_337_340_AL(P2CONST(I_SG_Detections_337_340_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_341_344_AL_Vdp_SG_Detections_341_344_AL(P2CONST(I_SG_Detections_341_344_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_345_348_AL_Vdp_SG_Detections_345_348_AL(P2CONST(I_SG_Detections_345_348_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_349_352_AL_Vdp_SG_Detections_349_352_AL(P2CONST(I_SG_Detections_349_352_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_353_356_AL_Vdp_SG_Detections_353_356_AL(P2CONST(I_SG_Detections_353_356_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_357_360_AL_Vdp_SG_Detections_357_360_AL(P2CONST(I_SG_Detections_357_360_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_361_364_AL_Vdp_SG_Detections_361_364_AL(P2CONST(I_SG_Detections_361_364_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_365_368_AL_Vdp_SG_Detections_365_368_AL(P2CONST(I_SG_Detections_365_368_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_369_372_AL_Vdp_SG_Detections_369_372_AL(P2CONST(I_SG_Detections_369_372_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_373_376_AL_Vdp_SG_Detections_373_376_AL(P2CONST(I_SG_Detections_373_376_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_377_380_AL_Vdp_SG_Detections_377_380_AL(P2CONST(I_SG_Detections_377_380_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_381_384_AL_Vdp_SG_Detections_381_384_AL(P2CONST(I_SG_Detections_381_384_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_385_388_AL_Vdp_SG_Detections_385_388_AL(P2CONST(I_SG_Detections_385_388_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_389_392_AL_Vdp_SG_Detections_389_392_AL(P2CONST(I_SG_Detections_389_392_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_393_396_AL_Vdp_SG_Detections_393_396_AL(P2CONST(I_SG_Detections_393_396_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_397_400_AL_Vdp_SG_Detections_397_400_AL(P2CONST(I_SG_Detections_397_400_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_GW_prop_ADAS_BSIS_info_ALPCAN_Vdp_SG_GW_prop_ADAS_BSIS_info_ALPCAN(P2CONST(I_SG_GW_prop_ADAS_BSIS_info_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_MOIS_ALVCAN_Vdp_SG_MOIS_ALVCAN(P2CONST(I_SG_MOIS_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RDR_BSD1_Tx_ALPCAN_Vdp_SG_RDR_BSD1_Tx_ALPCAN(P2CONST(I_SG_RDR_BSD1_Tx_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL(P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN(P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN(P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL(P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader(P2CONST(SG_TrackerHeader_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject002_Vdp_SG_TrackerObject002(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject003_Vdp_SG_TrackerObject003(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject004_Vdp_SG_TrackerObject004(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject005_Vdp_SG_TrackerObject005(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject006_Vdp_SG_TrackerObject006(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject007_Vdp_SG_TrackerObject007(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject008_Vdp_SG_TrackerObject008(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject009_Vdp_SG_TrackerObject009(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject010_Vdp_SG_TrackerObject010(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject011_Vdp_SG_TrackerObject011(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject012_Vdp_SG_TrackerObject012(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject013_Vdp_SG_TrackerObject013(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject014_Vdp_SG_TrackerObject014(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject015_Vdp_SG_TrackerObject015(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject016_Vdp_SG_TrackerObject016(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject017_Vdp_SG_TrackerObject017(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject018_Vdp_SG_TrackerObject018(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject019_Vdp_SG_TrackerObject019(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject020_Vdp_SG_TrackerObject020(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject021_Vdp_SG_TrackerObject021(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject022_Vdp_SG_TrackerObject022(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject023_Vdp_SG_TrackerObject023(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject024_Vdp_SG_TrackerObject024(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject025_Vdp_SG_TrackerObject025(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject026_Vdp_SG_TrackerObject026(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject027_Vdp_SG_TrackerObject027(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject028_Vdp_SG_TrackerObject028(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject029_Vdp_SG_TrackerObject029(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject030_Vdp_SG_TrackerObject030(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject031_Vdp_SG_TrackerObject031(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject032_Vdp_SG_TrackerObject032(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject033_Vdp_SG_TrackerObject033(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject034_Vdp_SG_TrackerObject034(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject035_Vdp_SG_TrackerObject035(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject036_Vdp_SG_TrackerObject036(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject037_Vdp_SG_TrackerObject037(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject038_Vdp_SG_TrackerObject038(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject039_Vdp_SG_TrackerObject039(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject040_Vdp_SG_TrackerObject040(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject041_Vdp_SG_TrackerObject041(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject042_Vdp_SG_TrackerObject042(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject043_Vdp_SG_TrackerObject043(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject044_Vdp_SG_TrackerObject044(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject045_Vdp_SG_TrackerObject045(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject046_Vdp_SG_TrackerObject046(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject047_Vdp_SG_TrackerObject047(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject048_Vdp_SG_TrackerObject048(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject049_Vdp_SG_TrackerObject049(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject050_Vdp_SG_TrackerObject050(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject051_Vdp_SG_TrackerObject051(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject052_Vdp_SG_TrackerObject052(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject053_Vdp_SG_TrackerObject053(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject054_Vdp_SG_TrackerObject054(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject055_Vdp_SG_TrackerObject055(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject056_Vdp_SG_TrackerObject056(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject057_Vdp_SG_TrackerObject057(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject058_Vdp_SG_TrackerObject058(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject059_Vdp_SG_TrackerObject059(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject060_Vdp_SG_TrackerObject060(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject061_Vdp_SG_TrackerObject061(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject062_Vdp_SG_TrackerObject062(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject063_Vdp_SG_TrackerObject063(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject064_Vdp_SG_TrackerObject064(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus(P2CONST(SG_TrackerStatus_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL(P2CONST(I_SG_VehicleStatus_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_prop_ADAS_MOIS_info_ALVCAN_Vdp_SG_prop_ADAS_MOIS_info_ALVCAN(P2CONST(I_SG_prop_ADAS_MOIS_info_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState(void);
FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState(void);
FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState(void);
FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState(void);
FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState(void);

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RP_RDR_Vehicle_Status_Vehicle_Status Rte_Read_SWC_PLT_Appl_Communication_RP_RDR_Vehicle_Status_Vehicle_Status
#  define Rte_Read_Rp_OperationMode_System_De_OperationMode_System Rte_Read_SWC_PLT_Appl_Communication_Rp_OperationMode_System_De_OperationMode_System
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_OperationMode_System_De_OperationMode_System(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_SG_ADAS_FN_Enable_disable_sts_ALVCAN_Vdp_SG_ADAS_FN_Enable_disable_sts_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ADAS_FN_Enable_disable_sts_ALVCAN_Vdp_SG_ADAS_FN_Enable_disable_sts_ALVCAN
#  define Rte_Read_Rp_SG_CCVS1_ALVCAN_Vdp_SG_CCVS1_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CCVS1_ALVCAN_Vdp_SG_CCVS1_ALVCAN
#  define Rte_Read_Rp_SG_CLS_Tx_16_ALVCAN_Vdp_SG_CLS_Tx_16_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_16_ALVCAN_Vdp_SG_CLS_Tx_16_ALVCAN
#  define Rte_Read_Rp_SG_CLS_Tx_4_ALVCAN_Vdp_SG_CLS_Tx_4_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_4_ALVCAN_Vdp_SG_CLS_Tx_4_ALVCAN
#  define Rte_Read_Rp_SG_ETC2_00_ALVCAN_Vdp_SG_ETC2_00_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_00_ALVCAN_Vdp_SG_ETC2_00_ALVCAN
#  define Rte_Read_Rp_SG_ETC2_03_ALVCAN_Vdp_SG_ETC2_03_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_03_ALVCAN_Vdp_SG_ETC2_03_ALVCAN
#  define Rte_Read_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN
#  define Rte_Read_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN
#  define Rte_Read_Rp_SG_Fusion_Detections_001_004_AL_Vdp_SG_Fusion_Detections_001_004_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_001_004_AL_Vdp_SG_Fusion_Detections_001_004_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_005_008_AL_Vdp_SG_Fusion_Detections_005_008_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_005_008_AL_Vdp_SG_Fusion_Detections_005_008_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_009_012_AL_Vdp_SG_Fusion_Detections_009_012_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_009_012_AL_Vdp_SG_Fusion_Detections_009_012_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_013_016_AL_Vdp_SG_Fusion_Detections_013_016_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_013_016_AL_Vdp_SG_Fusion_Detections_013_016_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_017_020_AL_Vdp_SG_Fusion_Detections_017_020_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_017_020_AL_Vdp_SG_Fusion_Detections_017_020_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_021_024_AL_Vdp_SG_Fusion_Detections_021_024_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_021_024_AL_Vdp_SG_Fusion_Detections_021_024_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_025_028_AL_Vdp_SG_Fusion_Detections_025_028_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_025_028_AL_Vdp_SG_Fusion_Detections_025_028_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_029_032_AL_Vdp_SG_Fusion_Detections_029_032_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_029_032_AL_Vdp_SG_Fusion_Detections_029_032_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_033_036_AL_Vdp_SG_Fusion_Detections_033_036_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_033_036_AL_Vdp_SG_Fusion_Detections_033_036_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_037_040_AL_Vdp_SG_Fusion_Detections_037_040_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_037_040_AL_Vdp_SG_Fusion_Detections_037_040_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_041_044_AL_Vdp_SG_Fusion_Detections_041_044_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_041_044_AL_Vdp_SG_Fusion_Detections_041_044_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_045_048_AL_Vdp_SG_Fusion_Detections_045_048_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_045_048_AL_Vdp_SG_Fusion_Detections_045_048_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_049_052_AL_Vdp_SG_Fusion_Detections_049_052_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_049_052_AL_Vdp_SG_Fusion_Detections_049_052_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_053_056_AL_Vdp_SG_Fusion_Detections_053_056_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_053_056_AL_Vdp_SG_Fusion_Detections_053_056_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_057_060_AL_Vdp_SG_Fusion_Detections_057_060_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_057_060_AL_Vdp_SG_Fusion_Detections_057_060_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_061_064_AL_Vdp_SG_Fusion_Detections_061_064_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_061_064_AL_Vdp_SG_Fusion_Detections_061_064_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_065_068_AL_Vdp_SG_Fusion_Detections_065_068_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_065_068_AL_Vdp_SG_Fusion_Detections_065_068_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_069_072_AL_Vdp_SG_Fusion_Detections_069_072_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_069_072_AL_Vdp_SG_Fusion_Detections_069_072_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_073_076_AL_Vdp_SG_Fusion_Detections_073_076_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_073_076_AL_Vdp_SG_Fusion_Detections_073_076_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_077_080_AL_Vdp_SG_Fusion_Detections_077_080_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_077_080_AL_Vdp_SG_Fusion_Detections_077_080_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_081_084_AL_Vdp_SG_Fusion_Detections_081_084_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_081_084_AL_Vdp_SG_Fusion_Detections_081_084_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_085_088_AL_Vdp_SG_Fusion_Detections_085_088_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_085_088_AL_Vdp_SG_Fusion_Detections_085_088_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_089_092_AL_Vdp_SG_Fusion_Detections_089_092_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_089_092_AL_Vdp_SG_Fusion_Detections_089_092_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_093_096_AL_Vdp_SG_Fusion_Detections_093_096_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_093_096_AL_Vdp_SG_Fusion_Detections_093_096_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_097_100_AL_Vdp_SG_Fusion_Detections_097_100_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_097_100_AL_Vdp_SG_Fusion_Detections_097_100_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_101_104_AL_Vdp_SG_Fusion_Detections_101_104_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_101_104_AL_Vdp_SG_Fusion_Detections_101_104_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_105_108_AL_Vdp_SG_Fusion_Detections_105_108_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_105_108_AL_Vdp_SG_Fusion_Detections_105_108_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_109_112_AL_Vdp_SG_Fusion_Detections_109_112_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_109_112_AL_Vdp_SG_Fusion_Detections_109_112_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_113_116_AL_Vdp_SG_Fusion_Detections_113_116_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_113_116_AL_Vdp_SG_Fusion_Detections_113_116_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_117_120_AL_Vdp_SG_Fusion_Detections_117_120_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_117_120_AL_Vdp_SG_Fusion_Detections_117_120_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_121_124_AL_Vdp_SG_Fusion_Detections_121_124_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_121_124_AL_Vdp_SG_Fusion_Detections_121_124_AL
#  define Rte_Read_Rp_SG_Fusion_Detections_125_128_AL_Vdp_SG_Fusion_Detections_125_128_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_125_128_AL_Vdp_SG_Fusion_Detections_125_128_AL
#  define Rte_Read_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN
#  define Rte_Read_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN
#  define Rte_Read_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN
#  define Rte_Read_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN
#  define Rte_Read_Rp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN_Vdp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN_Vdp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN
#  define Rte_Read_Rp_SG_GW_CCVS1_ALPCAN_Vdp_SG_GW_CCVS1_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CCVS1_ALPCAN_Vdp_SG_GW_CCVS1_ALPCAN
#  define Rte_Read_Rp_SG_GW_CLS_Tx_16_ALPCAN_Vdp_SG_GW_CLS_Tx_16_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_16_ALPCAN_Vdp_SG_GW_CLS_Tx_16_ALPCAN
#  define Rte_Read_Rp_SG_GW_CLS_Tx_4_ALPCAN_Vdp_SG_GW_CLS_Tx_4_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_4_ALPCAN_Vdp_SG_GW_CLS_Tx_4_ALPCAN
#  define Rte_Read_Rp_SG_GW_ETC2_03_ALPCAN_Vdp_SG_GW_ETC2_03_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_03_ALPCAN_Vdp_SG_GW_ETC2_03_ALPCAN
#  define Rte_Read_Rp_SG_GW_ETC2_ALPCAN_Vdp_SG_GW_ETC2_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_ALPCAN_Vdp_SG_GW_ETC2_ALPCAN
#  define Rte_Read_Rp_SG_GW_OEL_ALPCAN_Vdp_SG_GW_OEL_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_OEL_ALPCAN_Vdp_SG_GW_OEL_ALPCAN
#  define Rte_Read_Rp_SG_GW_SAS_ALPCAN_Vdp_SG_GW_SAS_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_SAS_ALPCAN_Vdp_SG_GW_SAS_ALPCAN
#  define Rte_Read_Rp_SG_GW_TD_ALPCAN_Vdp_SG_GW_TD_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_TD_ALPCAN_Vdp_SG_GW_TD_ALPCAN
#  define Rte_Read_Rp_SG_GW_VDC2_ALPCAN_Vdp_SG_GW_VDC2_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VDC2_ALPCAN_Vdp_SG_GW_VDC2_ALPCAN
#  define Rte_Read_Rp_SG_GW_VD_ALPCAN_Vdp_SG_GW_VD_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VD_ALPCAN_Vdp_SG_GW_VD_ALPCAN
#  define Rte_Read_Rp_SG_GW_VI_ALPCAN_Vdp_SG_GW_VI_ALPCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VI_ALPCAN_Vdp_SG_GW_VI_ALPCAN
#  define Rte_Read_Rp_SG_OEL_ALVCAN_Vdp_SG_OEL_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_OEL_ALVCAN_Vdp_SG_OEL_ALVCAN
#  define Rte_Read_Rp_SG_SAS_ALVCAN_Vdp_SG_SAS_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_SAS_ALVCAN_Vdp_SG_SAS_ALVCAN
#  define Rte_Read_Rp_SG_TD_ALVCAN_Vdp_SG_TD_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_TD_ALVCAN_Vdp_SG_TD_ALVCAN
#  define Rte_Read_Rp_SG_VDC2_ALVCAN_Vdp_SG_VDC2_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VDC2_ALVCAN_Vdp_SG_VDC2_ALVCAN
#  define Rte_Read_Rp_SG_VD_ALVCAN_Vdp_SG_VD_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VD_ALVCAN_Vdp_SG_VD_ALVCAN
#  define Rte_Read_Rp_SG_VI_ALVCAN_Vdp_SG_VI_ALVCAN Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VI_ALVCAN_Vdp_SG_VI_ALVCAN
#  define Rte_Read_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL
#  define Rte_Read_Rp_SG_XcpCTOReq_AL_Vdp_SG_XcpCTOReq_AL Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_XcpCTOReq_AL_Vdp_SG_XcpCTOReq_AL
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_XcpCTOReq_AL_Vdp_SG_XcpCTOReq_AL(data) (*(data) = Rte_C_I_SG_XcpCTOReq_AL_ECF484F46C5C5F5D7AF0B5DBE1414436, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYNC_CRC_Vdp_TSYNC_CRC Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYNC_CRC_Vdp_TSYNC_CRC
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYNC_CRC_Vdp_TSYNC_CRC(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_OVS_Vdp_TSYN_OVS Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_OVS_Vdp_TSYN_OVS
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_OVS_Vdp_TSYN_OVS(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_PDU_Vdp_TSYN_PDU Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_PDU_Vdp_TSYN_PDU
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_PDU_Vdp_TSYN_PDU(data) (*(data) = 40U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_RESERVED_Vdp_TSYN_RESERVED Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_RESERVED_Vdp_TSYN_RESERVED
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_RESERVED_Vdp_TSYN_RESERVED(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_SEQUENCE_COUNTER_Vdp_TSYN_SEQUENCE_COUNTER Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SEQUENCE_COUNTER_Vdp_TSYN_SEQUENCE_COUNTER
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SEQUENCE_COUNTER_Vdp_TSYN_SEQUENCE_COUNTER(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_SGW_Vdp_TSYN_SGW Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SGW_Vdp_TSYN_SGW
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SGW_Vdp_TSYN_SGW(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_SYNCTIME_NANOSEC_Vdp_TSYN_SYNCTIME_NANOSEC Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SYNCTIME_NANOSEC_Vdp_TSYN_SYNCTIME_NANOSEC
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SYNCTIME_NANOSEC_Vdp_TSYN_SYNCTIME_NANOSEC(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_SYNCTIME_SEC_Vdp_TSYN_SYNCTIME_SEC Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SYNCTIME_SEC_Vdp_TSYN_SYNCTIME_SEC
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_SYNCTIME_SEC_Vdp_TSYN_SYNCTIME_SEC(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_TIMEDOMAIN_Vdp_TSYN_TIMEDOMAIN Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_TIMEDOMAIN_Vdp_TSYN_TIMEDOMAIN
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_TIMEDOMAIN_Vdp_TSYN_TIMEDOMAIN(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TSYN_USERBYTE_Vdp_TSYN_USERBYTE Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_USERBYTE_Vdp_TSYN_USERBYTE
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TSYN_USERBYTE_Vdp_TSYN_USERBYTE(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error Rte_Read_SWC_PLT_Appl_Communication_Rp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error(data) (*(data) = Rte_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Time_Stamp_Delta_De_Time_Stamp_Delta Rte_Read_SWC_PLT_Appl_Communication_Rp_Time_Stamp_Delta_De_Time_Stamp_Delta
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_Time_Stamp_Delta_De_Time_Stamp_Delta(data) (*(data) = Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Vbatt_State_De_Vbatt_State Rte_Read_SWC_PLT_Appl_Communication_Rp_Vbatt_State_De_Vbatt_State
#  define Rte_Read_SWC_PLT_Appl_Communication_Rp_Vbatt_State_De_Vbatt_State(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Write_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Write_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Write_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Write_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Write_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault Rte_Write_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault(data) (Rte_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_RDR_DetectionList_Event_DetectionList_Event Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event
#  define Rte_Write_Pp_RDR_NM_CAN_NM_State_Vdp_RDR_NM_CAN_NM_State Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CAN_NM_State_Vdp_RDR_NM_CAN_NM_State
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CAN_NM_State_Vdp_RDR_NM_CAN_NM_State(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_ActWakeBit_4_Vdp_RDR_NM_CBV_ActWakeBit_4 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ActWakeBit_4_Vdp_RDR_NM_CBV_ActWakeBit_4
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ActWakeBit_4_Vdp_RDR_NM_CBV_ActWakeBit_4(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_NMCoordBit_3_Vdp_RDR_NM_CBV_NMCoordBit_3 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_NMCoordBit_3_Vdp_RDR_NM_CBV_NMCoordBit_3
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_NMCoordBit_3_Vdp_RDR_NM_CBV_NMCoordBit_3(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_PNIBit_6_Vdp_RDR_NM_CBV_PNIBit_6 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_PNIBit_6_Vdp_RDR_NM_CBV_PNIBit_6
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_PNIBit_6_Vdp_RDR_NM_CBV_PNIBit_6(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_ReptMsgBit0_Vdp_RDR_NM_CBV_ReptMsgBit0 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ReptMsgBit0_Vdp_RDR_NM_CBV_ReptMsgBit0
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ReptMsgBit0_Vdp_RDR_NM_CBV_ReptMsgBit0(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_ResdBit_1_Vdp_RDR_NM_CBV_ResdBit_1 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_1_Vdp_RDR_NM_CBV_ResdBit_1
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_1_Vdp_RDR_NM_CBV_ResdBit_1(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_ResdBit_2_Vdp_RDR_NM_CBV_ResdBit_2 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_2_Vdp_RDR_NM_CBV_ResdBit_2
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_2_Vdp_RDR_NM_CBV_ResdBit_2(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_ResdBit_5_Vdp_RDR_NM_CBV_ResdBit_5 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_5_Vdp_RDR_NM_CBV_ResdBit_5
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_5_Vdp_RDR_NM_CBV_ResdBit_5(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_CBV_ResdBit_7_Vdp_RDR_NM_CBV_ResdBit_7 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_7_Vdp_RDR_NM_CBV_ResdBit_7
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_CBV_ResdBit_7_Vdp_RDR_NM_CBV_ResdBit_7(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_PNC_Reserved1_Vdp_RDR_NM_PNC_Reserved1 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PNC_Reserved1_Vdp_RDR_NM_PNC_Reserved1
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PNC_Reserved1_Vdp_RDR_NM_PNC_Reserved1(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_PNC_Reserved2_Vdp_RDR_NM_PNC_Reserved2 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PNC_Reserved2_Vdp_RDR_NM_PNC_Reserved2
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PNC_Reserved2_Vdp_RDR_NM_PNC_Reserved2(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_PNC_Reserved3_Vdp_RDR_NM_PNC_Reserved3 Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PNC_Reserved3_Vdp_RDR_NM_PNC_Reserved3
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PNC_Reserved3_Vdp_RDR_NM_PNC_Reserved3(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_PN_User_Data_Vdp_RDR_NM_PN_User_Data Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PN_User_Data_Vdp_RDR_NM_PN_User_Data
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_PN_User_Data_Vdp_RDR_NM_PN_User_Data(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_NM_Wakeup_And_Reason_Vdp_RDR_NM_Wakeup_And_Reason Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_Wakeup_And_Reason_Vdp_RDR_NM_Wakeup_And_Reason
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_NM_Wakeup_And_Reason_Vdp_RDR_NM_Wakeup_And_Reason(data) (RTE_E_OK)
#  define Rte_Write_Pp_RDR_Radar_SW_Info_RDR_SW_Info Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info
#  define Rte_Write_Pp_RDR_Radar_Status_RDR_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status
#  define Rte_Write_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Write_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Write_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Write_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL
#  define Rte_Write_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL
#  define Rte_Write_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL
#  define Rte_Write_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL
#  define Rte_Write_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL
#  define Rte_Write_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL
#  define Rte_Write_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL
#  define Rte_Write_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL
#  define Rte_Write_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL
#  define Rte_Write_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL
#  define Rte_Write_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL
#  define Rte_Write_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL
#  define Rte_Write_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL
#  define Rte_Write_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL
#  define Rte_Write_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL
#  define Rte_Write_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL
#  define Rte_Write_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL
#  define Rte_Write_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL
#  define Rte_Write_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL
#  define Rte_Write_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL
#  define Rte_Write_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL
#  define Rte_Write_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL
#  define Rte_Write_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL
#  define Rte_Write_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL
#  define Rte_Write_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL
#  define Rte_Write_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL
#  define Rte_Write_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL
#  define Rte_Write_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL
#  define Rte_Write_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL
#  define Rte_Write_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL
#  define Rte_Write_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL
#  define Rte_Write_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL
#  define Rte_Write_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL
#  define Rte_Write_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL
#  define Rte_Write_Pp_SG_Detections_129_132_AL_Vdp_SG_Detections_129_132_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_129_132_AL_Vdp_SG_Detections_129_132_AL
#  define Rte_Write_Pp_SG_Detections_133_136_AL_Vdp_SG_Detections_133_136_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_133_136_AL_Vdp_SG_Detections_133_136_AL
#  define Rte_Write_Pp_SG_Detections_137_140_AL_Vdp_SG_Detections_137_140_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_137_140_AL_Vdp_SG_Detections_137_140_AL
#  define Rte_Write_Pp_SG_Detections_141_144_AL_Vdp_SG_Detections_141_144_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_141_144_AL_Vdp_SG_Detections_141_144_AL
#  define Rte_Write_Pp_SG_Detections_145_148_AL_Vdp_SG_Detections_145_148_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_145_148_AL_Vdp_SG_Detections_145_148_AL
#  define Rte_Write_Pp_SG_Detections_149_152_AL_Vdp_SG_Detections_149_152_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_149_152_AL_Vdp_SG_Detections_149_152_AL
#  define Rte_Write_Pp_SG_Detections_153_156_AL_Vdp_SG_Detections_153_156_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_153_156_AL_Vdp_SG_Detections_153_156_AL
#  define Rte_Write_Pp_SG_Detections_157_160_AL_Vdp_SG_Detections_157_160_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_157_160_AL_Vdp_SG_Detections_157_160_AL
#  define Rte_Write_Pp_SG_Detections_161_164_AL_Vdp_SG_Detections_161_164_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_161_164_AL_Vdp_SG_Detections_161_164_AL
#  define Rte_Write_Pp_SG_Detections_165_168_AL_Vdp_SG_Detections_165_168_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_165_168_AL_Vdp_SG_Detections_165_168_AL
#  define Rte_Write_Pp_SG_Detections_169_172_AL_Vdp_SG_Detections_169_172_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_169_172_AL_Vdp_SG_Detections_169_172_AL
#  define Rte_Write_Pp_SG_Detections_173_176_AL_Vdp_SG_Detections_173_176_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_173_176_AL_Vdp_SG_Detections_173_176_AL
#  define Rte_Write_Pp_SG_Detections_177_180_AL_Vdp_SG_Detections_177_180_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_177_180_AL_Vdp_SG_Detections_177_180_AL
#  define Rte_Write_Pp_SG_Detections_181_184_AL_Vdp_SG_Detections_181_184_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_181_184_AL_Vdp_SG_Detections_181_184_AL
#  define Rte_Write_Pp_SG_Detections_185_188_AL_Vdp_SG_Detections_185_188_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_185_188_AL_Vdp_SG_Detections_185_188_AL
#  define Rte_Write_Pp_SG_Detections_189_192_AL_Vdp_SG_Detections_189_192_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_189_192_AL_Vdp_SG_Detections_189_192_AL
#  define Rte_Write_Pp_SG_Detections_193_196_AL_Vdp_SG_Detections_193_196_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_193_196_AL_Vdp_SG_Detections_193_196_AL
#  define Rte_Write_Pp_SG_Detections_197_200_AL_Vdp_SG_Detections_197_200_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_197_200_AL_Vdp_SG_Detections_197_200_AL
#  define Rte_Write_Pp_SG_Detections_201_204_AL_Vdp_SG_Detections_201_204_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_201_204_AL_Vdp_SG_Detections_201_204_AL
#  define Rte_Write_Pp_SG_Detections_205_208_AL_Vdp_SG_Detections_205_208_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_205_208_AL_Vdp_SG_Detections_205_208_AL
#  define Rte_Write_Pp_SG_Detections_209_212_AL_Vdp_SG_Detections_209_212_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_209_212_AL_Vdp_SG_Detections_209_212_AL
#  define Rte_Write_Pp_SG_Detections_213_216_AL_Vdp_SG_Detections_213_216_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_213_216_AL_Vdp_SG_Detections_213_216_AL
#  define Rte_Write_Pp_SG_Detections_217_220_AL_Vdp_SG_Detections_217_220_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_217_220_AL_Vdp_SG_Detections_217_220_AL
#  define Rte_Write_Pp_SG_Detections_221_224_AL_Vdp_SG_Detections_221_224_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_221_224_AL_Vdp_SG_Detections_221_224_AL
#  define Rte_Write_Pp_SG_Detections_225_228_AL_Vdp_SG_Detections_225_228_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_225_228_AL_Vdp_SG_Detections_225_228_AL
#  define Rte_Write_Pp_SG_Detections_229_232_AL_Vdp_SG_Detections_229_232_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_229_232_AL_Vdp_SG_Detections_229_232_AL
#  define Rte_Write_Pp_SG_Detections_233_236_AL_Vdp_SG_Detections_233_236_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_233_236_AL_Vdp_SG_Detections_233_236_AL
#  define Rte_Write_Pp_SG_Detections_237_240_AL_Vdp_SG_Detections_237_240_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_237_240_AL_Vdp_SG_Detections_237_240_AL
#  define Rte_Write_Pp_SG_Detections_241_244_AL_Vdp_SG_Detections_241_244_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_241_244_AL_Vdp_SG_Detections_241_244_AL
#  define Rte_Write_Pp_SG_Detections_245_248_AL_Vdp_SG_Detections_245_248_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_245_248_AL_Vdp_SG_Detections_245_248_AL
#  define Rte_Write_Pp_SG_Detections_249_252_AL_Vdp_SG_Detections_249_252_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_249_252_AL_Vdp_SG_Detections_249_252_AL
#  define Rte_Write_Pp_SG_Detections_253_256_AL_Vdp_SG_Detections_253_256_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_253_256_AL_Vdp_SG_Detections_253_256_AL
#  define Rte_Write_Pp_SG_Detections_257_260_AL_Vdp_SG_Detections_257_260_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_257_260_AL_Vdp_SG_Detections_257_260_AL
#  define Rte_Write_Pp_SG_Detections_261_264_AL_Vdp_SG_Detections_261_264_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_261_264_AL_Vdp_SG_Detections_261_264_AL
#  define Rte_Write_Pp_SG_Detections_265_268_AL_Vdp_SG_Detections_265_268_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_265_268_AL_Vdp_SG_Detections_265_268_AL
#  define Rte_Write_Pp_SG_Detections_269_272_AL_Vdp_SG_Detections_269_272_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_269_272_AL_Vdp_SG_Detections_269_272_AL
#  define Rte_Write_Pp_SG_Detections_273_276_AL_Vdp_SG_Detections_273_276_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_273_276_AL_Vdp_SG_Detections_273_276_AL
#  define Rte_Write_Pp_SG_Detections_277_280_AL_Vdp_SG_Detections_277_280_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_277_280_AL_Vdp_SG_Detections_277_280_AL
#  define Rte_Write_Pp_SG_Detections_281_284_AL_Vdp_SG_Detections_281_284_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_281_284_AL_Vdp_SG_Detections_281_284_AL
#  define Rte_Write_Pp_SG_Detections_285_288_AL_Vdp_SG_Detections_285_288_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_285_288_AL_Vdp_SG_Detections_285_288_AL
#  define Rte_Write_Pp_SG_Detections_289_292_AL_Vdp_SG_Detections_289_292_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_289_292_AL_Vdp_SG_Detections_289_292_AL
#  define Rte_Write_Pp_SG_Detections_293_296_AL_Vdp_SG_Detections_293_296_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_293_296_AL_Vdp_SG_Detections_293_296_AL
#  define Rte_Write_Pp_SG_Detections_297_300_AL_Vdp_SG_Detections_297_300_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_297_300_AL_Vdp_SG_Detections_297_300_AL
#  define Rte_Write_Pp_SG_Detections_301_304_AL_Vdp_SG_Detections_301_304_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_301_304_AL_Vdp_SG_Detections_301_304_AL
#  define Rte_Write_Pp_SG_Detections_305_308_AL_Vdp_SG_Detections_305_308_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_305_308_AL_Vdp_SG_Detections_305_308_AL
#  define Rte_Write_Pp_SG_Detections_309_312_AL_Vdp_SG_Detections_309_312_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_309_312_AL_Vdp_SG_Detections_309_312_AL
#  define Rte_Write_Pp_SG_Detections_313_316_AL_Vdp_SG_Detections_313_316_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_313_316_AL_Vdp_SG_Detections_313_316_AL
#  define Rte_Write_Pp_SG_Detections_317_320_AL_Vdp_SG_Detections_317_320_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_317_320_AL_Vdp_SG_Detections_317_320_AL
#  define Rte_Write_Pp_SG_Detections_321_324_AL_Vdp_SG_Detections_321_324_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_321_324_AL_Vdp_SG_Detections_321_324_AL
#  define Rte_Write_Pp_SG_Detections_325_328_AL_Vdp_SG_Detections_325_328_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_325_328_AL_Vdp_SG_Detections_325_328_AL
#  define Rte_Write_Pp_SG_Detections_329_332_AL_Vdp_SG_Detections_329_332_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_329_332_AL_Vdp_SG_Detections_329_332_AL
#  define Rte_Write_Pp_SG_Detections_333_336_AL_Vdp_SG_Detections_333_336_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_333_336_AL_Vdp_SG_Detections_333_336_AL
#  define Rte_Write_Pp_SG_Detections_337_340_AL_Vdp_SG_Detections_337_340_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_337_340_AL_Vdp_SG_Detections_337_340_AL
#  define Rte_Write_Pp_SG_Detections_341_344_AL_Vdp_SG_Detections_341_344_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_341_344_AL_Vdp_SG_Detections_341_344_AL
#  define Rte_Write_Pp_SG_Detections_345_348_AL_Vdp_SG_Detections_345_348_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_345_348_AL_Vdp_SG_Detections_345_348_AL
#  define Rte_Write_Pp_SG_Detections_349_352_AL_Vdp_SG_Detections_349_352_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_349_352_AL_Vdp_SG_Detections_349_352_AL
#  define Rte_Write_Pp_SG_Detections_353_356_AL_Vdp_SG_Detections_353_356_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_353_356_AL_Vdp_SG_Detections_353_356_AL
#  define Rte_Write_Pp_SG_Detections_357_360_AL_Vdp_SG_Detections_357_360_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_357_360_AL_Vdp_SG_Detections_357_360_AL
#  define Rte_Write_Pp_SG_Detections_361_364_AL_Vdp_SG_Detections_361_364_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_361_364_AL_Vdp_SG_Detections_361_364_AL
#  define Rte_Write_Pp_SG_Detections_365_368_AL_Vdp_SG_Detections_365_368_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_365_368_AL_Vdp_SG_Detections_365_368_AL
#  define Rte_Write_Pp_SG_Detections_369_372_AL_Vdp_SG_Detections_369_372_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_369_372_AL_Vdp_SG_Detections_369_372_AL
#  define Rte_Write_Pp_SG_Detections_373_376_AL_Vdp_SG_Detections_373_376_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_373_376_AL_Vdp_SG_Detections_373_376_AL
#  define Rte_Write_Pp_SG_Detections_377_380_AL_Vdp_SG_Detections_377_380_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_377_380_AL_Vdp_SG_Detections_377_380_AL
#  define Rte_Write_Pp_SG_Detections_381_384_AL_Vdp_SG_Detections_381_384_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_381_384_AL_Vdp_SG_Detections_381_384_AL
#  define Rte_Write_Pp_SG_Detections_385_388_AL_Vdp_SG_Detections_385_388_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_385_388_AL_Vdp_SG_Detections_385_388_AL
#  define Rte_Write_Pp_SG_Detections_389_392_AL_Vdp_SG_Detections_389_392_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_389_392_AL_Vdp_SG_Detections_389_392_AL
#  define Rte_Write_Pp_SG_Detections_393_396_AL_Vdp_SG_Detections_393_396_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_393_396_AL_Vdp_SG_Detections_393_396_AL
#  define Rte_Write_Pp_SG_Detections_397_400_AL_Vdp_SG_Detections_397_400_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_397_400_AL_Vdp_SG_Detections_397_400_AL
#  define Rte_Write_Pp_SG_GW_prop_ADAS_BSIS_info_ALPCAN_Vdp_SG_GW_prop_ADAS_BSIS_info_ALPCAN Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_GW_prop_ADAS_BSIS_info_ALPCAN_Vdp_SG_GW_prop_ADAS_BSIS_info_ALPCAN
#  define Rte_Write_Pp_SG_MOIS_ALVCAN_Vdp_SG_MOIS_ALVCAN Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_MOIS_ALVCAN_Vdp_SG_MOIS_ALVCAN
#  define Rte_Write_Pp_SG_RDR_BSD1_Tx_ALPCAN_Vdp_SG_RDR_BSD1_Tx_ALPCAN Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RDR_BSD1_Tx_ALPCAN_Vdp_SG_RDR_BSD1_Tx_ALPCAN
#  define Rte_Write_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL
#  define Rte_Write_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN
#  define Rte_Write_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN
#  define Rte_Write_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL
#  define Rte_Write_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader
#  define Rte_Write_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001
#  define Rte_Write_Pp_SG_TrackerObject002_Vdp_SG_TrackerObject002 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject002_Vdp_SG_TrackerObject002
#  define Rte_Write_Pp_SG_TrackerObject003_Vdp_SG_TrackerObject003 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject003_Vdp_SG_TrackerObject003
#  define Rte_Write_Pp_SG_TrackerObject004_Vdp_SG_TrackerObject004 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject004_Vdp_SG_TrackerObject004
#  define Rte_Write_Pp_SG_TrackerObject005_Vdp_SG_TrackerObject005 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject005_Vdp_SG_TrackerObject005
#  define Rte_Write_Pp_SG_TrackerObject006_Vdp_SG_TrackerObject006 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject006_Vdp_SG_TrackerObject006
#  define Rte_Write_Pp_SG_TrackerObject007_Vdp_SG_TrackerObject007 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject007_Vdp_SG_TrackerObject007
#  define Rte_Write_Pp_SG_TrackerObject008_Vdp_SG_TrackerObject008 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject008_Vdp_SG_TrackerObject008
#  define Rte_Write_Pp_SG_TrackerObject009_Vdp_SG_TrackerObject009 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject009_Vdp_SG_TrackerObject009
#  define Rte_Write_Pp_SG_TrackerObject010_Vdp_SG_TrackerObject010 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject010_Vdp_SG_TrackerObject010
#  define Rte_Write_Pp_SG_TrackerObject011_Vdp_SG_TrackerObject011 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject011_Vdp_SG_TrackerObject011
#  define Rte_Write_Pp_SG_TrackerObject012_Vdp_SG_TrackerObject012 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject012_Vdp_SG_TrackerObject012
#  define Rte_Write_Pp_SG_TrackerObject013_Vdp_SG_TrackerObject013 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject013_Vdp_SG_TrackerObject013
#  define Rte_Write_Pp_SG_TrackerObject014_Vdp_SG_TrackerObject014 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject014_Vdp_SG_TrackerObject014
#  define Rte_Write_Pp_SG_TrackerObject015_Vdp_SG_TrackerObject015 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject015_Vdp_SG_TrackerObject015
#  define Rte_Write_Pp_SG_TrackerObject016_Vdp_SG_TrackerObject016 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject016_Vdp_SG_TrackerObject016
#  define Rte_Write_Pp_SG_TrackerObject017_Vdp_SG_TrackerObject017 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject017_Vdp_SG_TrackerObject017
#  define Rte_Write_Pp_SG_TrackerObject018_Vdp_SG_TrackerObject018 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject018_Vdp_SG_TrackerObject018
#  define Rte_Write_Pp_SG_TrackerObject019_Vdp_SG_TrackerObject019 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject019_Vdp_SG_TrackerObject019
#  define Rte_Write_Pp_SG_TrackerObject020_Vdp_SG_TrackerObject020 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject020_Vdp_SG_TrackerObject020
#  define Rte_Write_Pp_SG_TrackerObject021_Vdp_SG_TrackerObject021 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject021_Vdp_SG_TrackerObject021
#  define Rte_Write_Pp_SG_TrackerObject022_Vdp_SG_TrackerObject022 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject022_Vdp_SG_TrackerObject022
#  define Rte_Write_Pp_SG_TrackerObject023_Vdp_SG_TrackerObject023 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject023_Vdp_SG_TrackerObject023
#  define Rte_Write_Pp_SG_TrackerObject024_Vdp_SG_TrackerObject024 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject024_Vdp_SG_TrackerObject024
#  define Rte_Write_Pp_SG_TrackerObject025_Vdp_SG_TrackerObject025 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject025_Vdp_SG_TrackerObject025
#  define Rte_Write_Pp_SG_TrackerObject026_Vdp_SG_TrackerObject026 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject026_Vdp_SG_TrackerObject026
#  define Rte_Write_Pp_SG_TrackerObject027_Vdp_SG_TrackerObject027 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject027_Vdp_SG_TrackerObject027
#  define Rte_Write_Pp_SG_TrackerObject028_Vdp_SG_TrackerObject028 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject028_Vdp_SG_TrackerObject028
#  define Rte_Write_Pp_SG_TrackerObject029_Vdp_SG_TrackerObject029 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject029_Vdp_SG_TrackerObject029
#  define Rte_Write_Pp_SG_TrackerObject030_Vdp_SG_TrackerObject030 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject030_Vdp_SG_TrackerObject030
#  define Rte_Write_Pp_SG_TrackerObject031_Vdp_SG_TrackerObject031 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject031_Vdp_SG_TrackerObject031
#  define Rte_Write_Pp_SG_TrackerObject032_Vdp_SG_TrackerObject032 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject032_Vdp_SG_TrackerObject032
#  define Rte_Write_Pp_SG_TrackerObject033_Vdp_SG_TrackerObject033 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject033_Vdp_SG_TrackerObject033
#  define Rte_Write_Pp_SG_TrackerObject034_Vdp_SG_TrackerObject034 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject034_Vdp_SG_TrackerObject034
#  define Rte_Write_Pp_SG_TrackerObject035_Vdp_SG_TrackerObject035 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject035_Vdp_SG_TrackerObject035
#  define Rte_Write_Pp_SG_TrackerObject036_Vdp_SG_TrackerObject036 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject036_Vdp_SG_TrackerObject036
#  define Rte_Write_Pp_SG_TrackerObject037_Vdp_SG_TrackerObject037 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject037_Vdp_SG_TrackerObject037
#  define Rte_Write_Pp_SG_TrackerObject038_Vdp_SG_TrackerObject038 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject038_Vdp_SG_TrackerObject038
#  define Rte_Write_Pp_SG_TrackerObject039_Vdp_SG_TrackerObject039 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject039_Vdp_SG_TrackerObject039
#  define Rte_Write_Pp_SG_TrackerObject040_Vdp_SG_TrackerObject040 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject040_Vdp_SG_TrackerObject040
#  define Rte_Write_Pp_SG_TrackerObject041_Vdp_SG_TrackerObject041 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject041_Vdp_SG_TrackerObject041
#  define Rte_Write_Pp_SG_TrackerObject042_Vdp_SG_TrackerObject042 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject042_Vdp_SG_TrackerObject042
#  define Rte_Write_Pp_SG_TrackerObject043_Vdp_SG_TrackerObject043 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject043_Vdp_SG_TrackerObject043
#  define Rte_Write_Pp_SG_TrackerObject044_Vdp_SG_TrackerObject044 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject044_Vdp_SG_TrackerObject044
#  define Rte_Write_Pp_SG_TrackerObject045_Vdp_SG_TrackerObject045 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject045_Vdp_SG_TrackerObject045
#  define Rte_Write_Pp_SG_TrackerObject046_Vdp_SG_TrackerObject046 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject046_Vdp_SG_TrackerObject046
#  define Rte_Write_Pp_SG_TrackerObject047_Vdp_SG_TrackerObject047 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject047_Vdp_SG_TrackerObject047
#  define Rte_Write_Pp_SG_TrackerObject048_Vdp_SG_TrackerObject048 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject048_Vdp_SG_TrackerObject048
#  define Rte_Write_Pp_SG_TrackerObject049_Vdp_SG_TrackerObject049 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject049_Vdp_SG_TrackerObject049
#  define Rte_Write_Pp_SG_TrackerObject050_Vdp_SG_TrackerObject050 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject050_Vdp_SG_TrackerObject050
#  define Rte_Write_Pp_SG_TrackerObject051_Vdp_SG_TrackerObject051 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject051_Vdp_SG_TrackerObject051
#  define Rte_Write_Pp_SG_TrackerObject052_Vdp_SG_TrackerObject052 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject052_Vdp_SG_TrackerObject052
#  define Rte_Write_Pp_SG_TrackerObject053_Vdp_SG_TrackerObject053 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject053_Vdp_SG_TrackerObject053
#  define Rte_Write_Pp_SG_TrackerObject054_Vdp_SG_TrackerObject054 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject054_Vdp_SG_TrackerObject054
#  define Rte_Write_Pp_SG_TrackerObject055_Vdp_SG_TrackerObject055 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject055_Vdp_SG_TrackerObject055
#  define Rte_Write_Pp_SG_TrackerObject056_Vdp_SG_TrackerObject056 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject056_Vdp_SG_TrackerObject056
#  define Rte_Write_Pp_SG_TrackerObject057_Vdp_SG_TrackerObject057 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject057_Vdp_SG_TrackerObject057
#  define Rte_Write_Pp_SG_TrackerObject058_Vdp_SG_TrackerObject058 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject058_Vdp_SG_TrackerObject058
#  define Rte_Write_Pp_SG_TrackerObject059_Vdp_SG_TrackerObject059 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject059_Vdp_SG_TrackerObject059
#  define Rte_Write_Pp_SG_TrackerObject060_Vdp_SG_TrackerObject060 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject060_Vdp_SG_TrackerObject060
#  define Rte_Write_Pp_SG_TrackerObject061_Vdp_SG_TrackerObject061 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject061_Vdp_SG_TrackerObject061
#  define Rte_Write_Pp_SG_TrackerObject062_Vdp_SG_TrackerObject062 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject062_Vdp_SG_TrackerObject062
#  define Rte_Write_Pp_SG_TrackerObject063_Vdp_SG_TrackerObject063 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject063_Vdp_SG_TrackerObject063
#  define Rte_Write_Pp_SG_TrackerObject064_Vdp_SG_TrackerObject064 Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject064_Vdp_SG_TrackerObject064
#  define Rte_Write_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus
#  define Rte_Write_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL
#  define Rte_Write_Pp_SG_XcpCTOResp_AL_Vdp_SG_XcpCTOResp_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_XcpCTOResp_AL_Vdp_SG_XcpCTOResp_AL
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_XcpCTOResp_AL_Vdp_SG_XcpCTOResp_AL(data) (RTE_E_OK)
#  define Rte_Write_Pp_SG_XcpDAQResp_AL_Vdp_SG_XcpDAQResp_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_XcpDAQResp_AL_Vdp_SG_XcpDAQResp_AL
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_XcpDAQResp_AL_Vdp_SG_XcpDAQResp_AL(data) (RTE_E_OK)
#  define Rte_Write_Pp_SG_prop_ADAS_MOIS_info_ALVCAN_Vdp_SG_prop_ADAS_MOIS_info_ALVCAN Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_prop_ADAS_MOIS_info_ALVCAN_Vdp_SG_prop_ADAS_MOIS_info_ALVCAN
#  define Rte_Write_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Write_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Write_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Write_Pp_VSE_NVM_Params_De_VSE_NVM_Params Rte_Write_SWC_PLT_Appl_Communication_Pp_VSE_NVM_Params_De_VSE_NVM_Params
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_VSE_NVM_Params_De_VSE_NVM_Params(data) (RTE_E_OK)
#  define Rte_Write_Pp_WarningRelevantObjectDetected_AL_Vdp_WarningRelevantObjectDetected_AL Rte_Write_SWC_PLT_Appl_Communication_Pp_WarningRelevantObjectDetected_AL_Vdp_WarningRelevantObjectDetected_AL
#  define Rte_Write_SWC_PLT_Appl_Communication_Pp_WarningRelevantObjectDetected_AL_Vdp_WarningRelevantObjectDetected_AL(data) (RTE_E_OK)
#  define Rte_Write_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode
#  define Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode(data) (Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode
#  define Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode(data) (Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode
#  define Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode(data) (Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode
#  define Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode(data) (Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode
#  define Rte_Write_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode(data) (Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState
#  define Rte_Mode_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState
#  define Rte_Mode_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState
#  define Rte_Mode_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState
#  define Rte_Mode_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_Communication_START_SEC_CODE
# include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_PostRadarProcessing_CAN_Tx_RE_Communication_Tx PostRadarProcessing_CAN_Tx_RE_Communication_Tx
#  define RTE_RUNNABLE_Pp_PCAN_Srv_DisableAppTx_Operation Pp_PCAN_Srv_DisableAppTx_Operation
#  define RTE_RUNNABLE_Pp_PCAN_Srv_EnableAppTx_Operation Pp_PCAN_Srv_EnableAppTx_Operation
#  define RTE_RUNNABLE_Pp_VCAN_Srv_DisableAppTx_Operation Pp_VCAN_Srv_DisableAppTx_Operation
#  define RTE_RUNNABLE_Pp_VCAN_Srv_EnableAppTx_Operation Pp_VCAN_Srv_EnableAppTx_Operation
#  define RTE_RUNNABLE_RE_Communication_10ms RE_Communication_10ms
#  define RTE_RUNNABLE_RE_Communication_Init RE_Communication_Init
#  define RTE_RUNNABLE_RE_Communication_Rx RE_Communication_Rx
#  define RTE_RUNNABLE_RE_Communication_Tx_50ms RE_Communication_Tx_50ms
# endif

FUNC(Std_ReturnType, SWC_PLT_Appl_Communication_CODE) PostRadarProcessing_CAN_Tx_RE_Communication_Tx(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_PCAN_Srv_DisableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_PCAN_Srv_EnableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_VCAN_Srv_DisableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) Pp_VCAN_Srv_EnableAppTx_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) RE_Communication_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) RE_Communication_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) RE_Communication_Rx(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_Communication_CODE) RE_Communication_Tx_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_Communication_STOP_SEC_CODE
# include "SWC_PLT_Appl_Communication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_PostRadarProcessing_CAN_Tx_E_NOT_OK (1U)

#  define RTE_E_PostRadarProcessing_CAN_Tx_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_COMMUNICATION_H */

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
