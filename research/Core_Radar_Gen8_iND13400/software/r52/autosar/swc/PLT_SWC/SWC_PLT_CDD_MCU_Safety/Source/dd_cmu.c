/*===========================================================================*\
 * FILE: dd_cmu.c
 *===========================================================================
 * Copyright (C) 2021 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the clock monitoring unit related functions.
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
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "dd_cmu.h"
#include "reuse.h"
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/
/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/*****************************************************************************
 *. Name: CMU_Init
 *. This function initialize the Clock Monitoring Unit
 *.
 *.
 *. Parameters: Cmu_Config
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void CMU_Init(void)
{
   /* Enable the clock failure detectors for reference clock, system clock, DSP clock, RA clock, MIPI clock and SERDES clock */
   ADDR_CLK_REF_FAIL_DETECTOR |= CTL_CKDET_ENA_MASK;
   ADDR_CTL_ADD_FAIL_DETECTOR |= CTL_CKSYS_DET_ENA_MASK | CTL_CKDSP_DET_ENA_MASK | CTL_CKRA_DET_ENA_MASK | CTL_CKMIPI_DET_ENA_MASK;
   ADDR_CLKGEN_CTRL0 |= CTL_CKSER_DET_ENA_MASK;
}
/*===========================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*===========================================================================
*
* Date        userid    (Description on following lines: SCR #, etc.)
* ----------- --------  ----------------------------------------------------
* 09-03-2026  Sathvika(vj1jjy)   EEG-EEG-6901:Implemented Clock Monitoring Unit (CMU).
\*===========================================================================*/
