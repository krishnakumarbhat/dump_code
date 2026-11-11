#ifndef INPUT_DATA_H
#define INPUT_DATA_H
/*===========================================================================*
 * FILE: Radar_SIL_Input_Data.h
 *===========================================================================
 * Copyright 2024 APTIV Technologies, Inc., All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Input Data Structures for Radar Software In Loop(SIL) Simulation.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
 *===========================================================================*/
#define INPUT_DATA_STRUCTURE_VERSION (6)
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

#pragma pack(push, 2)
extern "C"
{
#include "RR_ADAS_SYMBOL_Data.h"
#include "RR_ADAS_SYMBOL_Enum.h"
#include "fixmac.h"
}

/*===========================================================================*
 * Typedef's or Structure Declarations
 *===========================================================================*/
/* Header for the Input Data Structure */
typedef struct Input_Data_Hdr
{
   uint32_t Sec_Size;
   uint16_t Sec_Compatibility;
   uint16_t Sec_Checksum;
   uint16_t Sensor_id;
} Input_Data_Hdr_T;
/* Input Data Structure with UDP Log data */
typedef struct SIL_RADAR_Input_Data_Tag
{
   Input_Data_Hdr_T Input_Data_Header;
   UDP_CUST_FRAME_HEADER_SIL_T cust_frame_header;
   // unsigned long Scan_Index_Buff[MAX_LOGGING_SOURCE];
   void *Radar_Stream[MAX_RADAR_LOGGING_SOURCE];
   /* MUDP Record */
   RR_ADAS_SYMBOL_Data_T Symbol_Record;
} SIL_RADAR_Input_Data_T;

#pragma pack(pop)

#endif
