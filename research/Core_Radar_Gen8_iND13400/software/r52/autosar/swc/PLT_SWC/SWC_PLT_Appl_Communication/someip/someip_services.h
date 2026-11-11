#ifndef SOMEIP_SERVICES_H
#define SOMEIP_SERVICES_H
/*===========================================================================*/
/**
 * @file SWC_RDR_Veh_Com_SOMEIP.h
 *
 * @todo Add a one line description of the header file here.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2020 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
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
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup template Provide API description and define/delete next line
 * @ingroup <parent_API> (OPTIONAL USE if part of another API, else delete)
 * @{
 */

#include "ipc_data.h"
/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
#include "Platform_Types.h"
#include "Rte_Type.h"
#include "can_tx_msgs.h"
typedef struct
{
   volatile uint8 RDR_DetectionList_SdEventHandlerState;
   volatile uint8 RDR_Status_SdEventHandlerState;
   volatile uint8 RDR_Tracker_SdEventHandlerState;
   volatile uint8 RDR_SW_info_SdEventHandlerState;
   volatile uint8 Veh_Status_ConsumedServiceState;
   volatile uint8 Veh_Status_ConsumedEventGroupState;
   volatile uint8 RDR_Slave_Detections_ConsumedServiceState;
   volatile uint8 RDR_Slave_Detections_ConsumedEventGroupState;
} SdEventHandlerState_T;
typedef struct
{
   float32_t veh_speed;
   float32_t veh_yaw;
   float32_t veh_pitch;
   float32_t veh_roll;
   float32_t veh_steering_angle;
   uint32_t sw_version_adas;
   uint8_t can_pcan_minor_adas;
   uint8_t can_pcan_major_adas;
   uint8_t veh_speed_qf;
   uint8_t veh_yaw_qf;
   uint8_t veh_pitch_qf;
   uint8_t veh_roll_qf;
   uint8_t veh_steering_sign_status;
   uint8_t drive_reverse;
   uint8_t drive_dir;
   uint8_t gear_position;
   uint8_t yaw_rate_bias;
   uint8_t veh_abs_time_day;
   uint8_t veh_abs_time_hr;
   uint8_t veh_abs_time_min;
   uint8_t veh_abs_time_mnth;
   uint8_t veh_abs_time_sec;
   uint8_t veh_pwr_mode_sts;
   uint8_t veh_ign_status;
   uint8_t veh_state;
   uint16_t veh_sys_vtg;
   uint16_t veh_abs_time_yr;
   uint32_t odometer_val;
   int8_t veh_spd_comp_factor;
} SomeIpRxSignals_t;
#ifdef UNIT_TEST
volatile M2D_Msg_T *Get_MSS_IPC_M2D_Msg_Buffer(void);
D2M_Msg_T *Get_IPC_D2M_Sp_Post_Proc_Buffer(void);
#endif
/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
void Process_Consumed_Services(void);
void Process_Provided_Services(void);
void Init_Consumed_Services(void);
void Init_Provided_Services(void);
SomeIpRxSignals_t *Get_SomeIp_Rx_Sig(void);
#endif /* SOMEIP_SERVICES_H */
