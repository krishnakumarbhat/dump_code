/**
 * @file SWC_PRJ_Appl_FaultMgr_fake.h
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
#ifndef SWC_PRJ_Appl_FaultMgr_FAKE_H_
#define SWC_PRJ_Appl_FaultMgr_FAKE_H_
#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "Fault_Lib_Plt.h"
#include "Fault_Lib_Prj.h"
#include "NvM.h"
#include "Rte_Type.h"

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Dem_SetEventStatus, Dem_EventIdType, Dem_EventStatusType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable,
                           const uint8 *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable, const uint8 *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable,
                           const uint8 *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable,
                           const uint8 *);
   DECLARE_FAKE_VOID_FUNC(Diag_No_Filter_Test, uint8, uint16);
   DECLARE_FAKE_VOID_FUNC(Diagnostics_Filter_Test, uint8, uint16, uint16, uint16, uint16 *, uint16 *);
   /* Fakes for functions referenced by SWC_PRJ_Appl_FaultMgr.c that are
    * normally provided by Fault_Lib_Prj.c (not linked in the unit test)
    * and by board_revision.c (transitively linked via psc_module). */
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_Board_Rev_Cnt);
#ifdef __cplusplus
}
#endif

DECLARE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Fault_Test_Completed_Table);
DECLARE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Fault_Enable_Table);
DECLARE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Active_Fault_Table);
DECLARE_FAKE_VALUE_FUNC(Platform_fault_T *, Get_Platform_Active_Fault_Latch_Table);
DECLARE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_Active_Fault_Table);
DECLARE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_Active_Fault_Latched_Table);
DECLARE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_Fault_Test_Completed_Table);
DECLARE_FAKE_VALUE_FUNC(Customer_fault_Latch_Enable_T *, Get_Customer_Fault_Enable_Table);
DECLARE_FAKE_VALUE_FUNC(Customer_fault_T *, Get_Customer_History_Fault_Table);
DECLARE_FAKE_VOID_FUNC(Platform_memory_Copy, void *, void *, uint8);
DECLARE_FAKE_VALUE_FUNC(uint8, Platform_Get_Fault_Status, uint16);
DECLARE_FAKE_VALUE_FUNC(uint8, Customer_Get_Fault_Status, uint16);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_GetErrorStatus, NvM_BlockIdType, NvM_RequestResultType *);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, NvM_WriteBlock, NvM_BlockIdType, const void *);

#endif
