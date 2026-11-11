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
 *             File:  Rte_SWC_PLT_Radar_Alignment_Handler_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PLT_Radar_Alignment_Handler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_TYPE_H
# define RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef AH_AA_ROOTCAUSE_INVALID_INPUT
#   define AH_AA_ROOTCAUSE_INVALID_INPUT (0U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_SENSOR_FACING_UPWARDS
#   define AH_AA_ROOTCAUSE_SENSOR_FACING_UPWARDS (1U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_SENSOR_FACING_DOWNWARDS
#   define AH_AA_ROOTCAUSE_SENSOR_FACING_DOWNWARDS (2U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_SENSOR_FACING_RIGHT
#   define AH_AA_ROOTCAUSE_SENSOR_FACING_RIGHT (3U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_SENSOR_FACING_LEFT
#   define AH_AA_ROOTCAUSE_SENSOR_FACING_LEFT (4U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_VELOCITY_TOO_LOW
#   define AH_AA_ROOTCAUSE_VELOCITY_TOO_LOW (5U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_YAW_RATE_TOO_HIGH
#   define AH_AA_ROOTCAUSE_YAW_RATE_TOO_HIGH (6U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_VEHICLE_IN_REVERSE
#   define AH_AA_ROOTCAUSE_VEHICLE_IN_REVERSE (7U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_INVALID_VEHICLE_SIGNAL
#   define AH_AA_ROOTCAUSE_INVALID_VEHICLE_SIGNAL (8U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_TARGETS_TOO_LOW
#   define AH_AA_ROOTCAUSE_TARGETS_TOO_LOW (9U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_QUALITY_TOO_LOW
#   define AH_AA_ROOTCAUSE_QUALITY_TOO_LOW (10U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_BLOCKAGE
#   define AH_AA_ROOTCAUSE_BLOCKAGE (11U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_OPERATION_MODE_FAULTY
#   define AH_AA_ROOTCAUSE_OPERATION_MODE_FAULTY (12U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_DATA_QUALIFIER_INVALID
#   define AH_AA_ROOTCAUSE_DATA_QUALIFIER_INVALID (13U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_SUDDEN_JUMP_DETECTION
#   define AH_AA_ROOTCAUSE_SUDDEN_JUMP_DETECTION (14U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_CRITICAL_MISALIGNMENT
#   define AH_AA_ROOTCAUSE_CRITICAL_MISALIGNMENT (15U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_CORRUPTED_NVM
#   define AH_AA_ROOTCAUSE_CORRUPTED_NVM (16U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_INACCURATE_MISALIGNMENT_VALUE
#   define AH_AA_ROOTCAUSE_INACCURATE_MISALIGNMENT_VALUE (17U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_INITIAL_ALIGNMENT_NOT_DONE
#   define AH_AA_ROOTCAUSE_INITIAL_ALIGNMENT_NOT_DONE (18U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_ALIGNMENT_QF_NOT_OK
#   define AH_AA_ROOTCAUSE_ALIGNMENT_QF_NOT_OK (19U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_TRAILER_CONNECTED
#   define AH_AA_ROOTCAUSE_TRAILER_CONNECTED (20U)
#  endif

#  ifndef AH_AA_ROOTCAUSE_NONE
#   define AH_AA_ROOTCAUSE_NONE (255U)
#  endif
#  ifndef AH_ALIGNERR_NO_ERROR
#   define AH_ALIGNERR_NO_ERROR (0U)
#  endif

#  ifndef AH_ALIGNERR_SENSOR_FACING_UPWARDS
#   define AH_ALIGNERR_SENSOR_FACING_UPWARDS (1U)
#  endif

#  ifndef AH_ALIGNERR_SENSOR_FACING_DOWNWARDS
#   define AH_ALIGNERR_SENSOR_FACING_DOWNWARDS (2U)
#  endif

#  ifndef AH_ALIGNERR_SENSOR_FACING_RIGHT
#   define AH_ALIGNERR_SENSOR_FACING_RIGHT (3U)
#  endif

#  ifndef AH_ALIGNERR_SENSOR_FACING_LEFT
#   define AH_ALIGNERR_SENSOR_FACING_LEFT (4U)
#  endif

#  ifndef AH_ALIGNERR_NUMBER_OF_TARGETS_TOO_LOW_SERVICE
#   define AH_ALIGNERR_NUMBER_OF_TARGETS_TOO_LOW_SERVICE (5U)
#  endif

#  ifndef AH_ALIGNERR_QUALITY_OF_TARGET_TOO_LOW_SERVICE
#   define AH_ALIGNERR_QUALITY_OF_TARGET_TOO_LOW_SERVICE (6U)
#  endif

#  ifndef AH_ALIGNERR_TARGET_SIGNAL_TOO_WEAK
#   define AH_ALIGNERR_TARGET_SIGNAL_TOO_WEAK (7U)
#  endif

#  ifndef AH_ALIGNERR_TARGET_SIGNAL_TOO_STRONG
#   define AH_ALIGNERR_TARGET_SIGNAL_TOO_STRONG (8U)
#  endif

#  ifndef AH_ALIGNERR_TARGET_NOT_STATIC
#   define AH_ALIGNERR_TARGET_NOT_STATIC (9U)
#  endif

#  ifndef AH_ALIGNERR_TARGET_DISTANCE_TOO_HIGH_STATIC
#   define AH_ALIGNERR_TARGET_DISTANCE_TOO_HIGH_STATIC (10U)
#  endif

#  ifndef AH_ALIGNERR_TARGET_DISTANCE_TOO_LOW_STATIC
#   define AH_ALIGNERR_TARGET_DISTANCE_TOO_LOW_STATIC (11U)
#  endif

#  ifndef AH_ALIGNERR_TARGET_NOT_FOUND_STATIC
#   define AH_ALIGNERR_TARGET_NOT_FOUND_STATIC (12U)
#  endif

#  ifndef AH_ALIGNERR_INTERFERENCE_STATIC
#   define AH_ALIGNERR_INTERFERENCE_STATIC (13U)
#  endif

#  ifndef AH_ALIGNERR_INVALID_INPUT
#   define AH_ALIGNERR_INVALID_INPUT (14U)
#  endif

#  ifndef AH_ALIGNERR_INVALID_VEHICLE_SIGNAL
#   define AH_ALIGNERR_INVALID_VEHICLE_SIGNAL (15U)
#  endif

#  ifndef AH_ALIGNERR_BLOCKAGE
#   define AH_ALIGNERR_BLOCKAGE (16U)
#  endif

#  ifndef AH_ALIGNERR_MAX_DISTANCE_CROSSED_SERVICE
#   define AH_ALIGNERR_MAX_DISTANCE_CROSSED_SERVICE (17U)
#  endif

#  ifndef AH_ALIGNERR_MAX_DURATION_CROSSED_SERVICE
#   define AH_ALIGNERR_MAX_DURATION_CROSSED_SERVICE (18U)
#  endif

#  ifndef AH_ALIGNERR_OPERATION_MODE_FAULTY
#   define AH_ALIGNERR_OPERATION_MODE_FAULTY (19U)
#  endif

#  ifndef AH_ALIGNERR_DATA_QUALIFIER_INVALID
#   define AH_ALIGNERR_DATA_QUALIFIER_INVALID (20U)
#  endif

#  ifndef AH_ALIGNERR_AUTO_ALIGNMENT_ANGLE_CHG
#   define AH_ALIGNERR_AUTO_ALIGNMENT_ANGLE_CHG (21U)
#  endif

#  ifndef AH_ALIGNERR_INVALID
#   define AH_ALIGNERR_INVALID (255U)
#  endif
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
#  ifndef ALIGNMENT_OFF
#   define ALIGNMENT_OFF (0U)
#  endif

#  ifndef ALIGNMENT_RUNNING
#   define ALIGNMENT_RUNNING (1U)
#  endif

#  ifndef ALIGNMENT_PAUSED
#   define ALIGNMENT_PAUSED (2U)
#  endif

#  ifndef ALIGNMENT_FAILED
#   define ALIGNMENT_FAILED (3U)
#  endif

#  ifndef ALIGNMENT_SUCCESSFUL
#   define ALIGNMENT_SUCCESSFUL (4U)
#  endif
#  ifndef ALIGN_VEH_VEL_LOW
#   define ALIGN_VEH_VEL_LOW (0U)
#  endif

#  ifndef ALIGN_VEH_VEL_HIGH
#   define ALIGN_VEH_VEL_HIGH (1U)
#  endif

#  ifndef ALIGN_VEH_YAW_HIGH
#   define ALIGN_VEH_YAW_HIGH (2U)
#  endif

#  ifndef ALIGN_VEH_VEL_QF_INSUFFICIENT
#   define ALIGN_VEH_VEL_QF_INSUFFICIENT (3U)
#  endif

#  ifndef ALIGN_VEH_YAW_QF_INSUFFICIENT
#   define ALIGN_VEH_YAW_QF_INSUFFICIENT (4U)
#  endif

#  ifndef ALIGN_VEH_VEL_REVERSE
#   define ALIGN_VEH_VEL_REVERSE (5U)
#  endif

#  ifndef ALIGN_VEH_NO_ISSSUE
#   define ALIGN_VEH_NO_ISSSUE (6U)
#  endif
#  ifndef OFF
#   define OFF (0U)
#  endif

#  ifndef AUTOALIGNMENT
#   define AUTOALIGNMENT (1U)
#  endif

#  ifndef SHORT_TRACK_ALIGNMENT
#   define SHORT_TRACK_ALIGNMENT (2U)
#  endif

#  ifndef SERVICE_ALIGNMEMT
#   define SERVICE_ALIGNMEMT (3U)
#  endif

#  ifndef STATIC_ALIGNMENT
#   define STATIC_ALIGNMENT (4U)
#  endif
#  ifndef ACCEPTED
#   define ACCEPTED (0U)
#  endif

#  ifndef PENDING
#   define PENDING (1U)
#  endif

#  ifndef REJECTED
#   define REJECTED (2U)
#  endif
#  ifndef DRA_DET_COORD_SYS_UNDEFINED_ALIGN
#   define DRA_DET_COORD_SYS_UNDEFINED_ALIGN (0U)
#  endif

#  ifndef DRA_DET_COORD_SYS_SAE_ALIGN
#   define DRA_DET_COORD_SYS_SAE_ALIGN (1U)
#  endif

#  ifndef DRA_DET_COORD_SYS_ISO_ALIGN
#   define DRA_DET_COORD_SYS_ISO_ALIGN (2U)
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
#  ifndef INIT_MCU
#   define INIT_MCU (1U)
#  endif

#  ifndef RADAR_NOT_CONFIGURED
#   define RADAR_NOT_CONFIGURED (2U)
#  endif

#  ifndef OPERATIONAL
#   define OPERATIONAL (3U)
#  endif

#  ifndef FAULTY
#   define FAULTY (4U)
#  endif

#  ifndef SHUTDOWN_INITIATED
#   define SHUTDOWN_INITIATED (5U)
#  endif

#  ifndef SHUTDOWN_COMPLETED
#   define SHUTDOWN_COMPLETED (6U)
#  endif
#  ifndef ECUM_STATE_SLEEP
#   define ECUM_STATE_SLEEP (80U)
#  endif

#  ifndef ECUM_STATE_OFF
#   define ECUM_STATE_OFF (128U)
#  endif

#  ifndef ECUM_STATE_RESET
#   define ECUM_STATE_RESET (144U)
#  endif
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
#  ifndef OFF
#   define OFF (0U)
#  endif

#  ifndef ACTIVE
#   define ACTIVE (1U)
#  endif

#  ifndef PAUSED
#   define PAUSED (2U)
#  endif

#  ifndef FAILED
#   define FAILED (3U)
#  endif
#  ifndef INVALID_INPUT
#   define INVALID_INPUT (0U)
#  endif

#  ifndef SENSOR_FACING_UPWARDS
#   define SENSOR_FACING_UPWARDS (1U)
#  endif

#  ifndef SENSOR_FACING_DOWNWARDS
#   define SENSOR_FACING_DOWNWARDS (2U)
#  endif

#  ifndef SENSOR_FACING_RIGHT
#   define SENSOR_FACING_RIGHT (3U)
#  endif

#  ifndef SENSOR_FACING_LEFT
#   define SENSOR_FACING_LEFT (4U)
#  endif

#  ifndef VELOCITY_TOO_LOW
#   define VELOCITY_TOO_LOW (5U)
#  endif

#  ifndef YAW_RATE_TOO_HIGH
#   define YAW_RATE_TOO_HIGH (6U)
#  endif

#  ifndef VEHICLE_IN_RESERVE
#   define VEHICLE_IN_RESERVE (7U)
#  endif

#  ifndef INVALID_VEHICLE_SIGNAL
#   define INVALID_VEHICLE_SIGNAL (8U)
#  endif

#  ifndef TARGETS_TOO_LOW
#   define TARGETS_TOO_LOW (9U)
#  endif

#  ifndef QUALITY_TOO_LOW
#   define QUALITY_TOO_LOW (10U)
#  endif

#  ifndef ALIGNMENT_BLOCKAGE
#   define ALIGNMENT_BLOCKAGE (11U)
#  endif

#  ifndef NONE
#   define NONE (255U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_TYPE_H */
