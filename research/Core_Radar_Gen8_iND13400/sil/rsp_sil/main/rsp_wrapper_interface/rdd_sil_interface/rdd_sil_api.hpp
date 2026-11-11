#ifndef RDD_SIL_API_HPP
#define RDD_SIL_API_HPP
/**
 * @file rdd_sil_api.hpp
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024-2025 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file is the header file for rdd_sil_api.
 *
 */
/*==========================================================================*/
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "rdd_stream.h"
#include "spbb_include.h"
#include "spbb_typedefs.h"
#include "status_stream.h"
#include "vse_stream.h"
/*===========================================================================*

 * Exported Preprocessor #define Constants
 *===========================================================================*/
/*===========================================================================*

 * Exported Preprocessor #define MACROS
 *===========================================================================*/
/*===========================================================================*

 * Exported Type Declarations
 *===========================================================================*/
bool RDD_to_Detection_Configuration(Radar_Look_T look_id, Rdd_Stream_T *p_rdd_data_in, Rdd_Stream_T *p_rdd_data_out,
                                    Detection_Stream_T *p_af_det_stream_data, Detection_Debug_Stream_T *p_af_det_debug_stream_data,
                                    Down_selection_Stream_T *p_af_downselection_stream_data, Vse_Stream_T *p_vse_stream_data,
                                    uint8_t *p_radar_position_data, Status_Stream_T *p_status_stream);
#endif
