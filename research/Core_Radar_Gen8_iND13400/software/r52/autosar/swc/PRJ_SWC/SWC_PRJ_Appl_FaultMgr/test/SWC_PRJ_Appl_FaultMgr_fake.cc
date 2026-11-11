/**
 * @file SWC_PRJ_Appl_FaultMgr_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in SWC_PRJ_Appl_FaultMgr.c file.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */

#include "SWC_PRJ_Appl_FaultMgr_fake.h"
#include "NvM.h"
#include "psc_cal.h"

DEFINE_FFF_GLOBALS;

Platform_fault_T *SWC_PLT_Appl_Active_Fault_Table;

DEFINE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Fault_Test_Completed_Table);
DEFINE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Fault_Enable_Table);
DEFINE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Active_Fault_Table);
DEFINE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Active_Fault_Latch_Table);
DEFINE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_Active_Fault_Table);
DEFINE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_Active_Fault_Latched_Table);
DEFINE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_Fault_Test_Completed_Table);
DEFINE_FAKE_VALUE_FUNC(Customer_fault_Latch_Enable_T *, Get_Customer_Fault_Enable_Table);
DEFINE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_History_Fault_Table);
DEFINE_FAKE_VOID_FUNC(Platform_memory_Copy, void *, void *, uint8);

DEFINE_FAKE_VALUE_FUNC(uint8, Platform_Get_Fault_Status, uint16);
DEFINE_FAKE_VALUE_FUNC(uint8, Customer_Get_Fault_Status, uint16);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_GetErrorStatus, NvM_BlockIdType, NvM_RequestResultType *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_WriteBlock, NvM_BlockIdType, const void *);

extern "C"
{
   DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable,
                          const uint8 *);
   DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable, const uint8 *);
   DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable,
                          const uint8 *);
   DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable,
                          const uint8 *);
   DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Dem_SetEventStatus, Dem_EventIdType, Dem_EventStatusType);
   DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_Board_Rev_Cnt);
   DEFINE_FAKE_VOID_FUNC(Diag_No_Filter_Test, uint8, uint16);
   DEFINE_FAKE_VOID_FUNC(Diagnostics_Filter_Test, uint8, uint16, uint16, uint16, uint16 *, uint16 *);
}
/* Stubs/definitions to satisfy unit-test linking for symbols referenced by
   SWC_PRJ_Appl_FaultMgr_unit_test.cc. Match the project's declarations
   (C++ linkage and types from headers). */

void Clear_Fault_If_Enabled_and_Not_Latched(uint16 fault_name)
{
   (void)fault_name;
}

/* Define globals matching their real declarations */
Customer_fault_T Customer_Active_Fault_Table = {0};

unsigned char Rte_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status =
   0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status =
   0u;
unsigned char
   Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 0u;
unsigned char
   Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 0u;
unsigned char
   Rte_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status =
      0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status =
   0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status   = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status  = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status               = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status         = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status           = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status           = 0u;
unsigned char Rte_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status       = 0u;
unsigned char Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status = 0u;

/* Added to satisfy unit-test linking */
unsigned char Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State                                      = 0u;
uint8 Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = DIAG_TEST_PASS;

uint16 Pass_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT] = {0};
uint16 Fail_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT] = {0};
PSC_Cal_T PSC_Cal_Data                                       = {0};
PSC_Cal_T *PSC_Cal_Data_Ptr                                  = &PSC_Cal_Data;
uint8 Plt_Fault_Table_Freeze                                 = 0u;
