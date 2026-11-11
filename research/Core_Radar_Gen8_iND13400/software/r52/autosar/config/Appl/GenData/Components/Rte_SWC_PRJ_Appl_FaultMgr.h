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
 *             File:  Rte_SWC_PRJ_Appl_FaultMgr.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PRJ_Appl_FaultMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_FAULTMGR_H
# define RTE_SWC_PRJ_APPL_FAULTMGR_H

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

# include "Rte_SWC_PRJ_Appl_FaultMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status;
extern VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault;

#  define RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
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

#  define Rte_InitValue_Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Rp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Rp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Rp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Rp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Rp_FaultMngr_Vbatt_State_De_Vbatt_State (0U)
#  define Rte_InitValue_Rp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Rp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Rp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault (170U)
#  define Rte_InitValue_Rp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status (0U)
#  define Rte_InitValue_Rp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Rp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Rp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status (170U)
#  define Rte_InitValue_Rp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Rp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault (170U)
#  define Rte_InitValue_Rp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault (170U)
#  define Rte_InitValue_Rp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
#  define Rte_InitValue_Rp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status (170U)
#  define Rte_InitValue_Rp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status (170U)
#  define Rte_InitValue_Rp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status (170U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultTable_De_ActiveFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultTable_De_ActiveFaultTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_FaultTestCompleteTable_De_FaultTestCompleteTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_FaultTestCompleteTable_De_FaultTestCompleteTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable(P2CONST(Dt_Fault_T, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_ActiveFaultLatchTable_De_ActiveFaultLatchTable Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultLatchTable_De_ActiveFaultLatchTable
#  define Rte_Read_Rp_ActiveFaultTable_De_ActiveFaultTable Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultTable_De_ActiveFaultTable
#  define Rte_Read_Rp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_FaultMngr_Vbatt_State_De_Vbatt_State Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_FaultMngr_Vbatt_State_De_Vbatt_State
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_FaultMngr_Vbatt_State_De_Vbatt_State(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_FaultTestCompleteTable_De_FaultTestCompleteTable Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_FaultTestCompleteTable_De_FaultTestCompleteTable
#  define Rte_Read_Rp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_HistoryFaultTable_De_HistoryFaultTable
#  define Rte_Read_Rp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status(data) (*(data) = Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault(data) (*(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault(data) (*(data) = Rte_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status(data) (*(data) = Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(data) (*(data) = Rte_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_Fault_Override_De_XCP_Fault_Override Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_XCP_Fault_Override_De_XCP_Fault_Override
#  define Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_XCP_Fault_Override_De_XCP_Fault_Override(data) (*(data) = Rte_C_XCP_Fault_Override_Idt_XCP_Fault_Override_T, ((Std_ReturnType)RTE_E_UNCONNECTED))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable
#  define Rte_Write_Pp_ActiveFaultTable_De_ActiveFaultTable Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable
#  define Rte_Write_Pp_FaultEnableTable_De_FaultEnableTable Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultEnableTable_De_FaultEnableTable
#  define Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultEnableTable_De_FaultEnableTable(data) (RTE_E_OK)
#  define Rte_Write_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable
#  define Rte_Write_Pp_HistoryFaultTable_De_HistoryFaultTable Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define DemSatellite_Invalid_OsApplication_START_SEC_CODE
#  include "DemSatellite_Invalid_OsApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, DemSatellite_Invalid_OsApplication_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define DemSatellite_Invalid_OsApplication_STOP_SEC_CODE
#  include "DemSatellite_Invalid_OsApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AT_or_AMT_ECU_ETC2_03_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)3, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Application_Interface_Lookup_Performance_OR_incorrect_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)6, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Application_Radar_MMIC_Component_Internal_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)39, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Algorithm_Signal_Calculation_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)35, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Misalignment_Performance_or_Incorrect_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)36, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_AutoAlignment_Range_Alignment_or_Adjustment_Incorrect_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)37, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Battery_Voltage_System_Voltage_High_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)50, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Battery_Voltage_System_Voltage_Low_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)51, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Calibration_or_Parameter_Memory_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)52, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_ADAS_FN_STS_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)10, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_CLS_Tx_16_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)14, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_CLS_Tx_4_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)12, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_OEL_message_Missing_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)16, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Cluster_ECU_TD_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)18, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_CCVS1_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)21, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_ETC2_00_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)22, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_EMS_ECU_VD_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)25, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_ESC_ECU_VDC2_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)27, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Front_Left_Side_Radar_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)29, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Front_Left_Side_Radar_Value_of_Signal_Protection_Calculation_Incorrect_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)30, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Initial_Alignment_Missing_Calibration_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)38, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_MMIC_RFBIST_Component_or_System_Internal_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)40, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_General_Memory_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)41, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_Over_Temperature_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)42, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_System_Internal_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)43, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Module_Watchdog_or_Safety_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)44, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Mounting_Orientation_Incorrect_Assembly_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)45, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_NVM_Corruption_Program_Memory_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)19, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_PCAN_Communication_Bus_off_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)33, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Performance_Capability_Algorithm_Based_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)46, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Platform_Time_Sync_error_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)48, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Radar_Pin_Position_Wrong_Mounting_Position_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)47, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_SAS_ECU_SAS_message_Missing_Message_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)53, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_SMC_General_Checksum_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)49, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Security_Access_0x27_Attempt_Threshold_Authentication_Failure_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)28, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Time_Synchronization_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)34, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_VCAN_Communication_Bus_off_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)56, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Vehicle_DatasetNot_Configured_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)60, arg1))
#  define Rte_Call_FaultMgr_DiagnosticMonitor_RADAR_Vehicle_Dataset_Value_of_Signal_Protection_Calculation_Incorrect_Fault_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)61, arg1))

# endif /* !defined(RTE_CORE) */


# define SWC_PRJ_Appl_FaultMgr_START_SEC_CODE
# include "SWC_PRJ_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Control_DTC_Service_Operation CS_Control_DTC_Service_Operation
#  define RTE_RUNNABLE_RE_PCAN_Timeout_Faults_Event RE_PCAN_Timeout_Faults_Event
#  define RTE_RUNNABLE_RE_PRJ_FaultMgr_50ms RE_PRJ_FaultMgr_50ms
#  define RTE_RUNNABLE_RE_PRJ_FaultMgr_DEM_50ms RE_PRJ_FaultMgr_DEM_50ms
#  define RTE_RUNNABLE_RE_PRJ_FaultMgr_Init RE_PRJ_FaultMgr_Init
#  define RTE_RUNNABLE_RE_VCAN_Timeout_Faults_100ms_1000ms_Event RE_VCAN_Timeout_Faults_100ms_1000ms_Event
#  define RTE_RUNNABLE_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event
# endif

FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) CS_Control_DTC_Service_Operation(uint8 Control); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PCAN_Timeout_Faults_Event(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PRJ_FaultMgr_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PRJ_FaultMgr_DEM_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_PRJ_FaultMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_VCAN_Timeout_Faults_100ms_1000ms_Event(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_FaultMgr_CODE) RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PRJ_Appl_FaultMgr_STOP_SEC_CODE
# include "SWC_PRJ_Appl_FaultMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_FAULTMGR_H */

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
