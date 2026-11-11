#ifndef SH_MEMMAP_H
#define SH_MEMMAP_H
/*===========================================================================*\
 * FILE: sh_memmap.h
*===========================================================================
* Copyright (C) 2020 Aptiv Advanced Safety and User Experience. All rights
* reserved.
* Confidential Restricted Aptiv information. Do not disclose.
*
* DESCRIPTION:
*   Provides the memory mapping info of SH BB.
*
* ABBREVIATIONS:
*   List of abbreviations used, or reference(s) to external document(s)
*
* TRACEABILITY INFO:
*   Design Document(s):
*
*   Requirements Document(s):
*
*   Applicable Standards (in order of precedence: highest first):
*     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
*
* DEVIATIONS FROM STANDARDS:
*   None.
*
\*===========================================================================*/

#ifdef SH_SECTION_START
   #define SWC_PLT_CDD_Logging_START_SEC_VAR_INIT_UNSPECIFIED
   #include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
   #undef SH_SECTION_START
#endif

#ifdef SH_SECTION_STOP
   #define SWC_PLT_CDD_Logging_STOP_SEC_VAR_INIT_UNSPECIFIED
   #include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
   #undef SH_SECTION_STOP
#endif

#ifdef SH_SECTION_CODE_START
   #define SWC_PLT_CDD_Logging_START_SEC_CODE
   #include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
   #undef SH_SECTION_CODE_START
#endif

#ifdef SH_SECTION_CODE_STOP
   #define SWC_PLT_CDD_Logging_STOP_SEC_CODE
   #include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
   #undef SH_SECTION_CODE_STOP
#endif

#endif /* SH_MEMMAP_H */
