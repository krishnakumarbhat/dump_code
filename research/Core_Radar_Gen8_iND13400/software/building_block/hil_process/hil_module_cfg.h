#ifndef HIL_MODULE_CFG_H
#define HIL_MODULE_CFG_H
/*===========================================================================*/
/**
 * @file
 *
 * Configurations for the Module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright 2026 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *
 *
 * @section ABBR ABBREVIATIONS:
 *   - None
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards"
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - "None"
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*
 * Header Files
\*===========================================================================*/
#include "SoAd_Cfg.h"
#include "aptiv_record_header.h"
/*===========================================================================*
 * #define MACROS
\*===========================================================================*/
/* Ethernet frame in bytes */
#define HIL_RECORD_VERSIONINFO_L (RECORD_VERSIONINFO)
#define HIL_STREAM_SOURCE_L      (STREAM_SOURCE)
#define HIL_Resp_Tx_PDU_L        (SoAdConf_SoAdPduRoute_RDR_HIL_TX)
#define HIL_MAX_NUM_STRMS_SH_L   (MAX_NUM_STRMS)
#define HIL_Tx_E_OK_L            (E_OK)
#define HIL_ETH_DATA_PAYLOAD_L   (ETH_DATA_PAYLOAD)
#define HIL_REC_PAYLOAD_L        (REC_PAYLOAD)

/*===========================================================================*
 * #define Constants
\*===========================================================================*/

/*===========================================================================*
 * Custom Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid   (Description on following lines: SCR #, etc.)
 * --------    -----    ------------------------------------------------------
 *  29-Aug-2024   jjyb9k   DNP-4996: Initial Version of hil interface.

\*===========================================================================*/
#endif // HIL__MODULE_CFG_H
