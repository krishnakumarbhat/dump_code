#ifndef RA_FAULT_INJECTION_H
#define RA_FAULT_INJECTION_H
/*===========================================================================*\
 * FILE: Ra_fault_injection.h
 *===========================================================================
 * Copyright 2024 APTIV Technologies Inc. All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Functional Safety Configuration.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     SW REF 264.15D "APTIV C Coding Standards" [12-Mar-2006]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "reuse.h"

/*===========================================================================*\
* Other Header Files
\*===========================================================================*/

/*===========================================================================*\
* Exported Preprocessor #define Constants
\*===========================================================================*/

typedef enum
{
   SM_064_RA_AXI_M_IN_PARITY = 64,
   SM_065_RA_AXI_M_OUT_PARITY,
   SM_066_RA_AXI_STREAM_MON,
   SM_067_RA_CMD_MON,
   SM_068_RA_CQ_OVF_MON,
   SM_069_RA_CQMEM_ECC,
   SM_070_RA_DATAPATH_MON,
   SM_071_RA_DPMEM_ECC,
   SM_072_RA_EST_MUX_MON,
   SM_073_RA_ESTMEM_ECC,
   SM_074_RA_FSM_MONITOR,
   SM_075_RA_IDXMEM_ECC,
   SM_076_RA_MEM_ACCESS_MON,
   SM_077_RA_OUT_ADDR_MONITOR,
   SM_078_RA_PER_BIST,
   SM_079_RA_PHMEM_ECC,
   SM_080_RA_SLV_ERR_MON,
   SM_081_RA_WCMEM_ECC,
   SM_082_RA_WWDG_IS,
   SM_083_RA_WWDG_OS,
   SM_084_RA_WWDG_PS,
   SM_MAX
} ra_sm_test_t;

typedef enum
{
   RA_ECC_TEST_SEC = 0,
   RA_ECC_TEST_DED,
   RA_ECC_TEST_MAX
} ra_ecc_test_t;

typedef void (*ra_fault_handler_t)(void);

extern volatile ra_sm_test_t ra_sm_enable;
extern volatile ra_ecc_test_t ra_ecc_test_enable;
extern volatile uint8_t RA_Inj_Type;

void Set_RA_SEC_Threshold(void);
void RA_Fault_Injection_Execute(void);

#if defined(ENABLE_SQT_TEST_STUBS)
void SM_064_RA_AXI_M_IN_PARITY_Inject(void);
void SM_065_RA_AXI_M_OUT_PARITY_Inject(void);
void SM_067_RA_CMD_MON_Inject(void);
void SM_068_RA_CQ_OVF_MON_Inject(void);
void SM_069_RA_CQMEM_ECC_Inject(void);
void SM_069_RA_CQMEM_ECC_SEC_Inject(void);
void SM_069_RA_CQMEM_ECC_DED_Inject(void);
void SM_073_RA_ESTMEM_ECC_Inject(void);
void SM_073_RA_ESTMEM_ECC_SEC_Inject(void);
void SM_073_RA_ESTMEM_ECC_DED_Inject(void);
void SM_070_RA_DATAPATH_MON_Inject(void);
void SM_072_RA_EST_MUX_MON_Inject(void);
void SM_075_RA_IDXMEM_ECC_Inject(void);
void SM_075_RA_IDXMEM_ECC_SEC_Inject(void);
void SM_075_RA_IDXMEM_ECC_DED_Inject(void);
void SM_076_RA_MEM_ACCESS_MON_Inject(void);
void SM_077_RA_OUT_ADDR_MONITOR_Inject(void);
void SM_079_RA_PHMEM_ECC_Inject(void);
void SM_079_RA_PHMEM_ECC_SEC_Inject(void);
void SM_079_RA_PHMEM_ECC_DED_Inject(void);
void SM_080_RA_SLV_ERR_MON_Inject(void);
void SM_081_RA_WCMEM_ECC_Inject(void);
void SM_081_RA_WCMEM_ECC_SEC_Inject(void);
void SM_081_RA_WCMEM_ECC_DED_Inject(void);
void SM_082_RA_WWDG_IS_Inject(void);
void SM_083_RA_WWDG_OS_Inject(void);
void SM_084_RA_WWDG_PS_Inject(void);

   #ifndef UNIT_TEST
static const ra_fault_handler_t ra_fault_handlers[SM_MAX] = {
   [SM_064_RA_AXI_M_IN_PARITY]  = SM_064_RA_AXI_M_IN_PARITY_Inject,
   [SM_065_RA_AXI_M_OUT_PARITY] = SM_065_RA_AXI_M_OUT_PARITY_Inject,
   [SM_067_RA_CMD_MON]          = SM_067_RA_CMD_MON_Inject,
   [SM_068_RA_CQ_OVF_MON]       = SM_068_RA_CQ_OVF_MON_Inject,
   [SM_069_RA_CQMEM_ECC]        = SM_069_RA_CQMEM_ECC_Inject,
   [SM_070_RA_DATAPATH_MON]     = SM_070_RA_DATAPATH_MON_Inject,
   [SM_072_RA_EST_MUX_MON]      = SM_072_RA_EST_MUX_MON_Inject,
   [SM_073_RA_ESTMEM_ECC]       = SM_073_RA_ESTMEM_ECC_Inject,
   [SM_075_RA_IDXMEM_ECC]       = SM_075_RA_IDXMEM_ECC_Inject,
   [SM_076_RA_MEM_ACCESS_MON]   = SM_076_RA_MEM_ACCESS_MON_Inject,
   [SM_077_RA_OUT_ADDR_MONITOR] = SM_077_RA_OUT_ADDR_MONITOR_Inject,
   [SM_079_RA_PHMEM_ECC]        = SM_079_RA_PHMEM_ECC_Inject,
   [SM_080_RA_SLV_ERR_MON]      = SM_080_RA_SLV_ERR_MON_Inject,
   [SM_081_RA_WCMEM_ECC]        = SM_081_RA_WCMEM_ECC_Inject,
   [SM_082_RA_WWDG_IS]          = SM_082_RA_WWDG_IS_Inject,
   [SM_083_RA_WWDG_OS]          = SM_083_RA_WWDG_OS_Inject,
   [SM_084_RA_WWDG_PS]          = SM_084_RA_WWDG_PS_Inject,
};
   #endif /* UNIT_TEST */

#endif

#endif /* RA_FAULT_INJECTION_H */
