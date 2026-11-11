/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/*===========================================================================*/
/**
 * @Can CAN User Callouts
 *
 * @file 	 Can_UserCallouts.h
 * @Date     Generation Time:   2026-08-27 00:57:15
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 *------------------------------------------------------------------------------
 *
 * @copyright 2025 indie Semiconductor.
 *
 * This item is considered confidential and shall not be used, modified, 
 * or distributed without prior written consent from Indie Semiconductor 
 *
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @CAN  Include declaration of user callout functions triggered by CAN safety events
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of CAN Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Specification of CAN Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @AUTOSAR 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef CAN_USER_CALLOUTS_H_
#define CAN_USER_CALLOUTS_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/
/**
 * @brief CAN safety event identifiers used in User Safety Callouts.
 */
typedef enum
{
    CAN_SAFETY_EVENT_ERROR_NONE               = 0U,     /*!< No Safety Error Detected */
    CAN_SAFETY_EVENT_RAM_ECC_ERROR            = 1U,     /*!< ECC error detected in CAN RAM (Memory Protection) */
    CAN_SAFETY_EVENT_SPATIAL_REDUNDANCY_ERROR = 2U,     /*!< Logical mismatch detected in Spatial Redundancy mechanism */
	CAN_SAFETY_EVENT_RAM_ECC_WARNING 		  = 3U, 	/*!< Correctable RAM ECC errors have reached the configured error threshold */
} Can_SafetyEventType;

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* CAN_USER_CALLOUTS_H_*/
