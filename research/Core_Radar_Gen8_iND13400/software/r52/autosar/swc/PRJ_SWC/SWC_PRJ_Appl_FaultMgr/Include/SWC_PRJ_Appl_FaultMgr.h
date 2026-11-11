#ifndef SWC_PRJ_Appl_FaultMgr_H
#define SWC_PRJ_Appl_FaultMgr_H

/*===================================================================================================================*/
/*****************************************************************************
 * @file SWC_PRJ_Appl_FaultMgr.h
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *
 *
 * @section ABBR ABBREVIATIONS:
 *   - List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*===================================================================================================================*/

/*===================================================================================================================*\
 * Standard Header Files
\*===================================================================================================================*/
/*===================================================================================================================*\
 * Other Header Files
\*===================================================================================================================*/

/*===================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*===================================================================================================================*/
Std_ReturnType App_DemCbkEventStatus_PCAN_BusOffFault(uint8_t EventStatusOld, uint8_t EventStatusNew);

Std_ReturnType App_DemCbkEventStatus_VCAN_BusOffFault(uint8_t EventStatusOld, uint8_t EventStatusNew);

/* Project battery fault handlers (declared so callers before definitions compile under C99+) */
void Prj_Battery_Low_Fault(Dt_VBattState_T Project_vbatt_state);
void Prj_Battery_High_Fault(Dt_VBattState_T Project_vbatt_state);
/* Project-level periodic battery fault tests */
void Proj_Battery_Fault_Tests_50ms(void);
/*===================================================================================================================*\
 * Exported Preprocessor #define Constants
\*===================================================================================================================*/

typedef enum
{
   FAULT_NONE                           = 0,
   FAULT_BUSOFF                         = 1, // Highest priority
   FAULT_MESSAGE_TIMEOUT                = 2,
   FAULT_E2E                            = 3,
   FAULT_ERRATIC_COMMUNICATION_ABNORMAL = 4,
   FAULT_SIGNAL_ERROR_INVALID_DATA      = 5 // Lowest priority
} FaultType;
/*===================================================================================================================*\
 * Exported Preprocessor #define MACROS
\*===================================================================================================================*/

/* OTHER TYPEDEFS ----------------------------------------------------------------------------------------------------*/

#ifndef ENABLE_SAMPLE_FAULT
   #define ENABLE_SAMPLE_FAULT FALSE
#endif

#ifndef ENABLE_SAMPLE_FAULT_FILTER_TYPE
   #define ENABLE_SAMPLE_FAULT_FILTER_TYPE NO_FILTER
#endif

#ifndef ENABLE_PCAN_BUSOFF_FAULT
   #define ENABLE_PCAN_BUSOFF_FAULT TRUE
#endif

#ifndef ENABLE_PCAN_BUSOFF_FAULT_FILTER_TYPE
   #define ENABLE_PCAN_BUSOFF_FAULT_FILTER_TYPE NO_FILTER
#endif

#ifndef ENABLE_VCAN_BUSOFF_FAULT
   #define ENABLE_VCAN_BUSOFF_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_BUSOFF_FAULT_FILTER_TYPE
   #define ENABLE_VCAN_BUSOFF_FAULT_FILTER_TYPE NO_FILTER
#endif
#ifndef ENABLE_PCAN_RX_TIMEOUT_FAULT
   #define ENABLE_PCAN_RX_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_PCAN_RX_TIMEOUT_FILTER_TYPE
   #define ENABLE_PCAN_RX_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_CCVS1_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_VDC2_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_ETC2_MT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_ETC2_AT_AMT_Variant_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_CLS_TX_16_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_CLS_TX_4_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_OEL_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_TD_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_VD_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FAULT
   #define ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FAULT TRUE
#endif

#ifndef ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FILTER_TYPE
   #define ENABLE_VCAN_SAS_MESSAGE_TIMEOUT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_PRJ_BATTERY_HIGH_FAULT
   #define ENABLE_PRJ_BATTERY_HIGH_FAULT TRUE
#endif

#ifndef ENABLE_PRJ_BATTERY_HIGH_FAULT_FILTER_TYPE
   #define ENABLE_PRJ_BATTERY_HIGH_FAULT_FILTER_TYPE DIAG_FILTER
#endif

#ifndef ENABLE_PRJ_BATTERY_LOW_FAULT
   #define ENABLE_PRJ_BATTERY_LOW_FAULT TRUE
#endif

#ifndef ENABLE_PRJ_BATTERY_LOW_FAULT_FILTER_TYPE
   #define ENABLE_PRJ_BATTERY_LOW_FAULT_FILTER_TYPE DIAG_FILTER
#endif
#ifndef ENABLE_TIME_SYNCHRONIZATION_FAULT
   #define ENABLE_TIME_SYNCHRONIZATION_FAULT TRUE
#endif

#ifndef ENABLE_TIME_SYNCHRONIZATION_FAULT_FILTER_TYPE
   #define ENABLE_TIME_SYNCHRONIZATION_FAULT_FILTER_TYPE NO_FILTER
#endif

/*  PIN_POSITION_MISMATCH_FAULT  */

#ifndef ENABLE_PIN_POSITION_MISMATCH_FAULT
   #define ENABLE_PIN_POSITION_MISMATCH_FAULT TRUE
#endif

#ifndef ENABLE_PIN_POSITION_MISMATCH_FAULT_FILTER_TYPE
   #define ENABLE_PIN_POSITION_MISMATCH_FAULT_FILTER_TYPE NO_FILTER
#endif

/*  NVM_CORRUPTION_FAULT  */

#ifndef ENABLE_NVM_CORRUPTION_FAULT
   #define ENABLE_NVM_CORRUPTION_FAULT TRUE
#endif

#ifndef ENABLE_NVM_CORRUPTION_FAULT_FILTER_TYPE
   #define ENABLE_NVM_CORRUPTION_FAULT_FILTER_TYPE NO_FILTER
#endif

#define CONTROL_DTC_ON_FAULTMGR  (0x01)
#define CONTROL_DTC_OFF_FAULTMGR (0x02)
/*====================================================================================================================*\
 * EXPORTED OBJECT DECLARATIONS
\*====================================================================================================================*/

#endif /* SWC_PRJ_Appl_FaultMgr_H */
