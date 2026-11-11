#ifndef DD_CMU_H /* { */
#define DD_CMU_H
/*===========================================================================*\
 * FILE: dd_cmu.h
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

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
* Exported Preprocessor #define MACROS
\*===========================================================================*/

#define ADDR_CLK_REF_FAIL_DETECTOR (*(volatile uint32_t *)0x89002004UL)
#define ADDR_CTL_ADD_FAIL_DETECTOR (*(volatile uint32_t *)0x89002038UL)
#define ADDR_CLKGEN_CTRL0          (*(volatile uint32_t *)0x8900306CUL)

#define CTL_CKDET_ENA_MASK      (0x00000001U)
#define CTL_CKSYS_DET_ENA_MASK  (0x00000001U)
#define CTL_CKDSP_DET_ENA_MASK  (0x00000010U)
#define CTL_CKRA_DET_ENA_MASK   (0x00000100U)
#define CTL_CKMIPI_DET_ENA_MASK (0x00001000U)
#define CTL_CKSER_DET_ENA_MASK  (0x00040000U)

#define ADDR_CLK_TOP_CTRL (*(volatile uint32_t *)0x89002000UL)

#define CTL_CG_DSP_CKEN_MASK    (0x00000200U)
#define CTL_CG_RA_CKEN_MASK     (0x00000100U)
#define CTL_CG_MIPI_CKEN_MASK   (0x00000400U)
#define CTL_CG_SERIAL_CKEN_MASK (0x00001000U)
/*===========================================================================*\
* Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void CMU_Init(void);
/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*===========================================================================
*
* Date        userid    (Description on following lines: SCR #, etc.)
* ----------- --------  ----------------------------------------------------
* 09-03-2026  Sathvika(vj1jjy)   EEG-EEG-6901:Implemented Clock Monitoring Unit (CMU).
\*===========================================================================*/
#endif /* DD_CMU_H */
