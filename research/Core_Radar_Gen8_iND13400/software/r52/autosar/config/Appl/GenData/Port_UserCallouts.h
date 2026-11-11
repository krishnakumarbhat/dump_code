/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/*===========================================================================*/
/**
 * @Port Port User Callouts
 *
 * @file 	 Port_UserCallouts.h
 * @Date     Generation Time:   2026-09-11 16:06:48
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
 * @PORT  Include declaration of user callout functions triggered by Port safety events
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of PORT Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Specification of PORT Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @AUTOSAR 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef PORT_USER_CALLOUTS_H_
#define PORT_USER_CALLOUTS_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor
*===========================================================================*/
/**
 * @defgroup PORT_SafetyEvents PORT Safety Event Identifiers
 * @brief Safety event identifiers used in User Safety Callouts.
 *
 * These values represent distinct safety-related conditions detected
 * by the PORT module. Each bit corresponds to a specific event type
 * that may be reported through user-defined safety callbacks.
 * @{
 */

/** Storage violation detected in PORT. */
#define PORT_SAFETY_ERROR_STORAGE        (0x01u)

/** Unauthorized or invalid access detected. */
#define PORT_SAFETY_ERROR_ACCESS         (0x02u)

/** Software interface (SWIF) fault detected. */
#define PORT_SAFETY_ERROR_SWIF           (0x04u)

/** Hardware interface (HWIF) fault detected. */
#define PORT_SAFETY_ERROR_HWIF           (0x08u)

/** Control logic fault detected. */
#define PORT_SAFETY_ERROR_CTRL           (0x10u)

/**
 * @typedef Port_SafetyEventIdentifier
 * @brief Type used to hold PORT safety event identifiers.
 *
 * This type represents the bit-mask values defined above.
 * Multiple safety events may be combined in a single value.
 */
typedef uint32 Port_SafetyEventIdentifier;

/** @} */ /* end of PORT_SafetyEvents group */


/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* PORT_USER_CALLOUTS_H_*/

