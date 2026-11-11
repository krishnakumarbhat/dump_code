/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PRJ_Appl_FaultMgr_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PRJ_Appl_FaultMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_FAULTMGR_TYPE_H
# define RTE_SWC_PRJ_APPL_FAULTMGR_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DEM_EVENT_STATUS_PASSED
#   define DEM_EVENT_STATUS_PASSED (0U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED
#   define DEM_EVENT_STATUS_FAILED (1U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED
#   define DEM_EVENT_STATUS_PREPASSED (2U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED
#   define DEM_EVENT_STATUS_PREFAILED (3U)
#  endif

#  ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
#   define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
#  endif

#  ifndef DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
#  endif
#  ifndef PowerON
#   define PowerON (0U)
#  endif

#  ifndef NORMV
#   define NORMV (1U)
#  endif

#  ifndef LO_V1
#   define LO_V1 (2U)
#  endif

#  ifndef HI_V1
#   define HI_V1 (3U)
#  endif

#  ifndef LO_V2
#   define LO_V2 (4U)
#  endif

#  ifndef HI_V2
#   define HI_V2 (5U)
#  endif

#  ifndef LO_Vtemp
#   define LO_Vtemp (6U)
#  endif

#  ifndef LO_VTEMP_TONORM
#   define LO_VTEMP_TONORM (7U)
#  endif

#  ifndef LO_V1_TONORM
#   define LO_V1_TONORM (8U)
#  endif

#  ifndef LO_V2_TONORM
#   define LO_V2_TONORM (9U)
#  endif

#  ifndef HI_VTEMP_TONORM
#   define HI_VTEMP_TONORM (10U)
#  endif

#  ifndef HI_V1_TONORM
#   define HI_V1_TONORM (11U)
#  endif

#  ifndef HI_V2_TONORM
#   define HI_V2_TONORM (12U)
#  endif

#  ifndef HI_Vtemp
#   define HI_Vtemp (13U)
#  endif
#  ifndef FAULT_OVERRIDE_AUTO_MODE
#   define FAULT_OVERRIDE_AUTO_MODE (1U)
#  endif

#  ifndef FAULT_OVERRIDE_SET_FAULT_MODE
#   define FAULT_OVERRIDE_SET_FAULT_MODE (2U)
#  endif

#  ifndef FAULT_OVERRIDE_CLEAR_FAULT_MODE
#   define FAULT_OVERRIDE_CLEAR_FAULT_MODE (3U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_FAULTMGR_TYPE_H */
