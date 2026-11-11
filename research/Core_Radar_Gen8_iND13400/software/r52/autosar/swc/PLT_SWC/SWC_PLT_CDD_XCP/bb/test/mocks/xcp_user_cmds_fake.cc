/**
 * @file p_l_xcp_user_cmds_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in p_l_xcp_user_cmds.c file.
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
#include "xcp_user_cmds_fake.h"

DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Target_Info_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_ADC_info_Periodic_Task, XCP_BB_Input_Params_Tag *, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_Target_Info_Periodic_Task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_Filtered_ADC_Info_Periodic_Task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(XCP_Inject_Fault_T *, Get_XCP_Inject_Fault_Data);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_ADC_Info_Cmnd_Status);

#if 0
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Chksum_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, xcp_set_override_periodic_task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Debug_Info_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_DID_Periodic_Task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_DID_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_JTAG_PWD_Periodic_Task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_jtag_Info_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_LC_Updation_Periodic_Task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_LifeCycle_Info_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Jtag_Pwd_Raed_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t, XCP_JTAG_PWD_Read_Periodic_Task, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_PCAN_Enable_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_VCAN_Enable_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Ethernet_Enable_Ptr);
DEFINE_FAKE_VALUE_FUNC(XCP_BB_Input_Params_T*, XCP_Chksum_Updation_Periodic_Task, uint8_t *, uint8_t *);

#endif
