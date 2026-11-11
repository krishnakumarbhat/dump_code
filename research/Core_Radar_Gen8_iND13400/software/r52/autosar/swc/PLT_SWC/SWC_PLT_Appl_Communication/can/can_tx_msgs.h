#ifndef CAN_TX_MSGS_H
#define CAN_TX_MSGS_H
/*===========================================================================*/
/**
 * @file can_tx_msgs.h
 *
 * CAN transmission message definitions and function prototypes for Radar platform.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This module provides function prototypes for transmitting CAN messages related to Radar
 * status, detection data, alignment status, and Tracker information on the CAN bus.
 *
 * @section ABBR ABBREVIATIONS:
 *   - CAN: Controller Area Network
 *   - TX: Transmission
 *   - RX: Reception
 *   - VCAN: Virtual CAN
 *   - DBC: Database File format
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - DND-3402: TX CAN Messages DBCv2.0 Gen8 Radar Platform
 *
 *   - Requirements Document(s):
 *     - Gen8 Radar Platform CAN Communication Requirements
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - AUTOSAR C++ Coding Guidelines
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup template Provide API description and define/delete next line
 * @ingroup <parent_API> (OPTIONAL USE if part of another API, else delete)
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
//#include "reuse.h"

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Rte_Type.h"
#include "can_signals.h"
#include "reuse.h"

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define DET_DBC_BASE_VERSION_MAJOR               (2)
#define DET_DBC_BASE_VERSION_MINOR               (3)
#define STS_BRR_STATUS_LINK_UP_SERVICES_ENABLED  (2U)
#define STS_BRR_STATUS_LINK_UP_SERVICES_DISABLED (1U)

#define Cx0_OUT_OF_SYNC                 (0U)
#define Cx1_SYNCED_AT_LEAST_ONCE        (1U)
#define Cx2_SYNC_MSG_TIMEOUT_OR_CRC_ERR (2U)
#define SENSOR_POS_FC                   (5U)
#define SENSOR_POS_L2                   (4U)
/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef enum Vehicle_Supply_Vtg_Tag
{
   NORM_V,
   LOW_V_TEMP,
   LOW_V_TEMP_TO_NORM,
   LOW_V1,
   LOW_V2,
   LOW_V1_TO_NORM,
   LOW_V2_TO_NORM,
   HIGH_V_TEMP,
   HIGH_V_TEMP_TO_NORM,
   HIGH_V1,
   HIGH_V2,
   HIGH_V1_TO_NORM,
   HIGH_V2_TO_NORM,
} Vehicle_Supply_Vtg_T;

/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/
void modify_status(uint32_t *status);
void Send_Radar_Header_Messages(void);
void Send_Radar_Header_Messages_2nd_VCAN(void);
void Send_Radar_Status_001_Messages(void);
void Send_Radar_Status_001_Messages_2nd_VCAN(void);
void Send_Radar_Status_002_Messages(void);
void Send_Alignment_Status_001_Messages(void);
void Send_Alignment_Status_002_Messages(void);
void Send_Radar_Capability_Messages(void);
void Send_Radar_Detection_Messages(void);
void Send_Tracker_Header_Messages(void);
void Send_Tracker_Status_Messages(void);
void Send_Tracker_Objects_On_CAN(void);

/*===========================================================================
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *    Date      userid  (Description on following lines: SCR #, etc.)
 * -----------  ------  ------------------------------------------------
 * 03-Mar-2025  xj0l28  DND-3402 Update for TX can msgs dbcv2.0 Gen8 RdrPlatform
 * 01-Mar-2025  xj0l28  DND-3402: New file checkin
 * ============================================================================ */
#endif /* CAN_TX_MSGS_H */
