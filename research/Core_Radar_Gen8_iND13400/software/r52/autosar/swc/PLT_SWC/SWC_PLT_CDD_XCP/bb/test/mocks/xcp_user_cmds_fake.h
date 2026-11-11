/**
 * @file p_l_xcp_user_cmds_fake.h
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
#ifndef P_L_XCP_USER_CMDS_FAKE_H_
#define P_L_XCP_USER_CMDS_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "xcp_bb_types.h"
#include "xcp_user_cmds.h"

   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Target_Info_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_ADC_Info_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_ADC_info_Periodic_Task, XCP_BB_Input_Params_Tag *, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_Target_Info_Periodic_Task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_Filtered_ADC_Info_Periodic_Task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(XCP_Inject_Fault_T *, Get_XCP_Inject_Fault_Data);

/* Reset fake functions */
#define FFF_FAKES_P_L_XCP_USER_CMDS_FUNCTION(FAKE)                                                                                \
   FAKE(Get_Target_Info_Cmnd_Status)                                                                                              \
   FAKE(Get_ADC_Info_Cmnd_Status)                                                                                                 \
   FAKE(XCP_ADC_info_Periodic_Task)                                                                                               \
   FAKE(XCP_Target_Info_Periodic_Task)                                                                                            \
   FAKE(XCP_Filtered_ADC_Info_Periodic_Task)                                                                                      \
   FAKE(Get_XCP_Inject_Fault_Data)

#ifdef __cplusplus
}
#endif

#endif /* P_L_XCP_USER_CMDS_FAKE_H_ */

#if 0

   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Chksum_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Debug_Info_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_DID_Periodic_Task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_DID_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_JTAG_PWD_Periodic_Task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_jtag_Info_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_LC_Updation_Periodic_Task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_LifeCycle_Info_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Jtag_Pwd_Raed_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_JTAG_PWD_Read_Periodic_Task, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_PCAN_Enable_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_VCAN_Enable_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Ethernet_Enable_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, XCP_Chksum_Updation_Periodic_Task, uint8_t *, uint8_t *);


FAKE(Get_MMIC_Debug_Info_Cmnd_Status)                                                                                          \
FAKE(XCP_DID_Periodic_Task)                                                                                                    \
FAKE(Get_DID_Cmnd_Status)                                                                                                      \
FAKE(XCP_JTAG_PWD_Periodic_Task)                                                                                               \
FAKE(Get_jtag_Info_Cmnd_Status)                                                                                                \
FAKE(XCP_LC_Updation_Periodic_Task)                                                                                            \
FAKE(Get_LifeCycle_Info_Cmnd_Status)                                                                                           \
FAKE(Get_Jtag_Pwd_Raed_Cmnd_Status)                                                                                            \
FAKE(XCP_Chksum_Updation_Periodic_Task)                                                                                        \
FAKE(XCP_JTAG_PWD_Read_Periodic_Task)
FAKE(Get_XCP_Inject_Fault_Data)
FAKE(Get_XCP_PCAN_Enable_Ptr)
FAKE(Get_XCP_VCAN_Enable_Ptr)
FAKE(Get_XCP_Ethernet_Enable_Ptr)

#endif
