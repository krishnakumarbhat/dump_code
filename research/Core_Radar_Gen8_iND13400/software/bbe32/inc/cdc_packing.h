#ifndef CDC_PACKING_H
#define CDC_PACKING_H

/*===========================================================================*/
/**
 * @file cdc_packing.h
 *
 * This module packs the CDC Beam vectors into CDC Records
 * and copies onto ENET buffer.
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
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "cdc_frame_interface.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "sh_module_cfg.h"
#include "spbb_cfg.h"
#include "spbb_include.h"
#include "spbb_math.h"
/*===========================================================================*\
* Exported Preprocessor #define Constants
\*===========================================================================*/
/* Depth of ENET RAM Buffers */
/* + 1 is kept for buffer if any overflow happens*/
/* For 500 dbins:25 + 1*/
#define CDC_LAST_CHUNK_INDICATOR          (1U)
#define CDC_NUM_ENET_TX_BUFFERS           ((26U) + CDC_LAST_CHUNK_INDICATOR)
#define CDC_NUM_BYTES_PER_CDC_DATA_RECORD ((uint16_t)sizeof(CDC_Record_T))
#define CDC_NUM_RECORDS_PER_FRAME         ((uint16_t)((sizeof(CDC_Stream_T) - sizeof(Dyn_Hdr_T)) / CDC_NUM_BYTES_PER_CDC_DATA_RECORD))
/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/
extern volatile Cdc_Frame_Interface_T Cdc_Frame_Interface;
/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void __attribute__((noinline)) __attribute__((section(".sram0.text")))
Cdc_Packing(Look_Data_T *p_look_data, uint16_t range_idx, uint16_t cdc_dbin_count,
            BV_Comp_Type_T (*dfft_bv_buffer)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE]);

#endif /* CDC_PACKING_H */
