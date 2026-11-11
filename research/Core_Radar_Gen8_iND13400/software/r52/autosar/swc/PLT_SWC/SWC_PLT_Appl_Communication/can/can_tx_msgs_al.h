#ifndef CAN_TX_MSGS_AL_H
#define CAN_TX_MSGS_AL_H
/*===========================================================================*/
/**
 * @file can_tx_msgs_al.h
 *
 * CAN transmission message definitions and function prototypes for MOIS/BSIS signals.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This module provides function prototypes for transmitting CAN messages related to
 * MOIS (Moving Object Indication System) and BSIS (Blind Spot Information System)
 * functionality. Additional prototypes may be added here as the feature set expands.
 *
 * @section ABBR ABBREVIATIONS:
 *   - BSIS: Blind Spot Information System
 *   - BSD:  Blind Spot Detection
 *   - CAN:  Controller Area Network
 *   - IPC:  Inter-Processor Communication
 *   - MOIS: Moving Object Indication System
 *   - TX:   Transmission
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
 *     - AUTOSAR C Coding Standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Rte_Type.h"
#include "can_signals.h"
#include "reuse.h"

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef struct Self_Feature_Degradation_Params_Tag
{
   uint8_t self_time_sync_validity_flag;
   uint8_t self_op_mode;
   uint8_t self_align_init_calib_flag;
} Self_Feature_Degradation_Params_T;

typedef struct Self_BSIS_Feature_Degradation_Flags_Tag
{
   uint8_t bsis_self_time_sync_validity_degrade_flag;
   uint8_t bsis_self_op_mode_degrade_flag;
   uint8_t bsis_self_align_init_calib_degrade_flag;
} Self_BSIS_Feature_Degradation_Flags_T;

typedef struct Self_MOIS_Feature_Degradation_Flags_Tag
{
   uint8_t mois_self_time_sync_validity_degrade_flag;
   uint8_t mois_self_op_mode_degrade_flag;
   uint8_t mois_self_align_init_calib_degrade_flag;
} Self_MOIS_Feature_Degradation_Flags_T;
typedef enum
{
   DETECTION_STATE_NOT_READY          = 0U,  /* system is not ready */
   DETECTION_STATE_DRIVER_DEACTIVATED = 2U,  /* system deactivated by driver */
   DETECTION_STATE_READY_ACTIVATED    = 3U,  /* ready and activated */
   DETECTION_STATE_COLLISION_WARNING  = 5U,  /* collision warning active */
   DETECTION_STATE_ERROR              = 14U, /* error indication */
   DETECTION_STATE_NOT_AVAILABLE      = 15U  /* not available */
} DetectionState_t;

/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
void Send_MOIS_Messages(void);
void Send_BSIS_Messages(void);
uint8_t FC_MOIS_Feature_Degradation_Check(Self_Feature_Degradation_Params_T feature_degradation_params);
uint8_t L2_BSIS_Feature_Degradation_Check(Self_Feature_Degradation_Params_T feature_degradation_flags);
/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

/*===========================================================================
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *    Date      userid  (Description on following lines: SCR #, etc.)
 * -----------  ------  ------------------------------------------------
 * 03-Mar-2025  xj0l28  DND-3402 Update for TX can msgs dbcv2.0 Gen8 RdrPlatform
 * 01-Mar-2025  xj0l28  DND-3402: New file checkin
 * ============================================================================ */
#endif /* CAN_TX_MSGS_AL_H */
