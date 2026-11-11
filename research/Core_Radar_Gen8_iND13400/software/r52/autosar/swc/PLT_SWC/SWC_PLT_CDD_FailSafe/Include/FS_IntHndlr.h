#ifndef FS_IntHndlr_H
#define FS_IntHndlr_H

/**************************************************************************
 * Copyright 2025 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        FailSafe \n
 * \b File-Revision:      1.0 \n
 * \b Classification:     CONFIDENTIAL \n
 *
 ***************************************************************************
 *
 *  Module Name:  FS_IntHndlr.h
 *
 *  Description:
 *    Header file for FS_IntHndlr.c
 *    Contains declarations for interrupt handler functions for safety
 *    mechanisms
 *
 **************************************************************************/

/*=====================================================================================================================*
 * PREPROCESSOR DIRECTIVES
 *=====================================================================================================================*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS ------------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "ra_sfrs.h"
#include "reuse.h"

typedef struct
{
   RA_R52_ERR_IRQ_FLAG_1_t R52_ERR_IRQ_FLAG_1;
   RA_R52_ERR_IRQ_FLAG_2_t R52_ERR_IRQ_FLAG_2;
   RA_R52_FUSA_IRQ_FLAG_t R52_FUSA_IRQ_FLAG;
} RA_R52_IRQ_Backup_t;

void Monitor_Correctable_Errors(void);
void Monitor_AXI_S_Correctable_Errors(void);
void Monitor_AXI_M_Correctable_Errors(void);
void Initalize_CEE_Limit(void);

RA_R52_ERR_IRQ_FLAG_1_t Get_RA_R52_ERR_IRQ_FLAG_1(void);
RA_R52_ERR_IRQ_FLAG_2_t Get_RA_R52_ERR_IRQ_FLAG_2(void);
RA_R52_FUSA_IRQ_FLAG_t Get_RA_R52_FUSA_IRQ_FLAG(void);
void FS_RA_Process_Failure_Cnts(void);
uint8_t Get_RA_R52_ERROR_Failure_State(void);
uint8_t Get_RA_R52_FUSA_Failure_State(void);
void Set_RA_R52_ERROR_Failure_State(uint8_t value);
void Set_RA_R52_FUSA_Failure_State(uint8_t value);

/*====================================================================================================================*\
 * GLOBAL VARIABLES
\*====================================================================================================================*/

/*====================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*====================================================================================================================*/

#endif /* FS_IntHndlr_H */
