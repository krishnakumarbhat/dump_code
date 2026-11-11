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
 *             File:  Rte_SWC_PLT_Appl_NvMHandler_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PLT_Appl_NvMHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_NVMHANDLER_TYPE_H
# define RTE_SWC_PLT_APPL_NVMHANDLER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef ALIGN_MODE_OFF
#   define ALIGN_MODE_OFF (0U)
#  endif

#  ifndef ALIGN_MODE_AUTO
#   define ALIGN_MODE_AUTO (1U)
#  endif

#  ifndef ALIGN_MODE_SHORT_TRACK
#   define ALIGN_MODE_SHORT_TRACK (2U)
#  endif

#  ifndef ALIGN_MODE_SERVICE
#   define ALIGN_MODE_SERVICE (3U)
#  endif

#  ifndef ALIGN_MODE_STATIC
#   define ALIGN_MODE_STATIC (4U)
#  endif

#  ifndef ALIGN_MODE_MANUAL
#   define ALIGN_MODE_MANUAL (5U)
#  endif
#  ifndef INVALID
#   define INVALID (0U)
#  endif

#  ifndef CDD_FAIL_SAFE
#   define CDD_FAIL_SAFE (1U)
#  endif

#  ifndef CDD_ESM
#   define CDD_ESM (2U)
#  endif

#  ifndef APPL_DIAG
#   define APPL_DIAG (3U)
#  endif

#  ifndef CDD_ALIGNMENT
#   define CDD_ALIGNMENT (4U)
#  endif

#  ifndef DYNAMIC_ALIGNMENT
#   define DYNAMIC_ALIGNMENT (5U)
#  endif

#  ifndef RFE_R1R2_FAULT
#   define RFE_R1R2_FAULT (6U)
#  endif

#  ifndef CDD_FAILSAFE_ECC
#   define CDD_FAILSAFE_ECC (7U)
#  endif

#  ifndef CDD_SENSORPOS
#   define CDD_SENSORPOS (8U)
#  endif

#  ifndef UDS_MANUAL_ALIGNMENT
#   define UDS_MANUAL_ALIGNMENT (9U)
#  endif

#  ifndef UDS_STATIC_ALIGNMENT
#   define UDS_STATIC_ALIGNMENT (10U)
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
#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_NVMHANDLER_TYPE_H */
