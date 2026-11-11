#ifndef CDC_FRAME_INTERFACE_H
#define CDC_FRAME_INTERFACE_H
/*===========================================================================*/
/**
 * @file cdc_frame_interface.h
 *
 *  Interface file between R52-BBE for cdc packets
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @section ABBR ABBREVIATIONS:
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
/*===========================================================================*\
 * Header Files
\*===========================================================================*/
#include "reuse.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/
typedef struct Cdc_Frame_Interface_Tag
{
   uint32_t cdc_enet_buffer_addr;                 /* Holds the cdc enet buffer base address */
   uint32_t cdc_frame_interface_index;            /* Frame interface index incremented at each new radar look/cycle boundary */
   uint16_t cdc_enet_packet_tx_cnt;               /* Holds the cdc enet packet ready count */
   uint16_t cdc_enet_packet_index;                /* Holds the cdc enet buffer index ready for tx */
   uint16_t cdc_enet_frame_end_index;             /* Holds the cdc enet buffer index for the last packet */
   uint16_t cdc_enet_buffer_max_depth;            /* Holds the cdc enet buffer max depth */
   uint16_t cdc_last_avail_cycle_total_frame_cnt; /* Holds the total cdc-tdc enet frames on last available cycle.
                                                   * Value never resets to 0 */
   uint16_t cdc_prev_cycle_total_frame_cnt;       /* Holds the total cdc-tdc enet frames on previous radar cycle */
   bool cdc_radar_frame_reset;                    /* Flag to indicate last rbin process completion */
} Cdc_Frame_Interface_T;

/*===========================================================================*\
 * External Object Definitions
\*===========================================================================*/
#endif /* CDC_FRAME_INTERFACE_H */
