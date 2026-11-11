
/*===========================================================================*/
/**
 * @file af_sil_api.hpp
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024-2025 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 * @section DESC DESCRIPTION:
 *
 * This file contains the API declaration of Angle Finding Process.
 *
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "rdd_stream.h"
#include "status_stream.h"
#include "vse_stream.h"

/*
 * NOTE: function headers can be found alongside the function definitions in
 * af_sil_api.cpp
 */
bool AF_Configure_And_Execute(Rdd_Stream_T *p_rdd_stream_data, Status_Stream_T *p_status_stream,
                              Detection_Stream_T *p_af_det_stream_data, Detection_Debug_Stream_T *p_af_det_debug_stream_data,
                              Down_selection_Stream_T *p_af_downselection_stream_data, Vse_Stream_T *p_vse_stream_data,
                              uint8_t *p_radar_position_data);
