#ifndef FAILSAFE_CALLOUT_H
#define FAILSAFE_CALLOUT_H

/**************************************************************************
 * Copyright 2019 Aptiv Technologies, Inc., All Rights Reserved.
 * Aptiv Confidential
 *
 * \b Application:        FailSafe \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:fjvnnx  %derived_by: fjvnnx % \n
 * \b Classification:     CONFIDENTIAL \n
 * %date_modified: 10/10/2019 %
 *
 *
 *
 ***************************************************************************
 *
 *  Module Name:  FailSafe_Callout.h
 *
 *  Description:
 *    Header file for FailSafe_Callout.h
 *
 *
 **************************************************************************/
/*=====================================================================================================================*
 * PREPROCESSOR DIRECTIVES
 *=====================================================================================================================*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS ------------------------------------------------------------------------------*/
#include "reuse.h"
/*====================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*====================================================================================================================*/
void Fail_Safe_Store_Reset_Reason_Callout(void);
void Fail_Safe_Check_NVM_Status_Callout(void);
void Fail_Safe_Read_Reset_Reason_Callout(void);
void Fail_Safe_Clear_Last_Cycle_Callout(void);
uint8_t FailSafe_Verify_ResetReason(uint8_t *FaultChannel);
void FailSafe_Repetative_ResetReason(uint8_t *ResetReason);
void FailSafe_Check_RepetitiveResetCount(void);
#if (TRUE == XCP_FAULT_INJECTION)
void FailSafe_Reset_PLT_Reset_Reason(void);
#endif
/* Function Prototypes------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************\
 * #define constants
\**********************************************************************************************************************/
#define REPETITIVE_RESET_CNTR             1U
#define REPETITIVE_RESET_CNTR_THRSHLD     2U
#define RFE_REPETITIVE_RESET_CNTR_THRSHLD 2U

/*
 * Note: This define for ZERO is not desireable
 * This is a workaround since the define is used internally within
 * external/FailSafe/Source/FailSafe.c
 * Once it is removed from there, this define can be removed.
 */
#define ZERO (0U)

/************************************************************************************************************************************
*  Revision History
*
*   Date        SCR			Name             Description
*   ----        ----		-----------      ---------------------------------------------------------------------------------------
*	01/03/2023	EEG-1179    Chirag Chauhan added declaration for FailSafe_Repetative_ResetReason
*   08-May-2023   EEG-1956    Arvind pandi   adding OS PROTECTION ERROR TO NVM

*************************************************************************************************************************************************/
#endif /* End FAILSAFE_CALLOUT_H */
