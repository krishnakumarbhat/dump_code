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
 *             File:  Rte_SWC_PLT_Appl_ModeManager_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PLT_Appl_ModeManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_MODEMANAGER_TYPE_H
# define RTE_SWC_PLT_APPL_MODEMANAGER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef SMC_CHECKSUM_FAULT
#   define SMC_CHECKSUM_FAULT (0U)
#  endif

#  ifndef USC_VALIDATION_FAULT
#   define USC_VALIDATION_FAULT (1U)
#  endif

#  ifndef MMIC_B_ID_FAULT
#   define MMIC_B_ID_FAULT (2U)
#  endif

#  ifndef MMIC_TEMPERATURE_HIGH_FAULT
#   define MMIC_TEMPERATURE_HIGH_FAULT (3U)
#  endif

#  ifndef MMIC_TEMPERATURE_LOW_FAULT
#   define MMIC_TEMPERATURE_LOW_FAULT (4U)
#  endif

#  ifndef MMIC_A_SAFESTART
#   define MMIC_A_SAFESTART (5U)
#  endif

#  ifndef MMIC_B_SAFESTART
#   define MMIC_B_SAFESTART (6U)
#  endif

#  ifndef MMIC_A_SAFETY_INTEGRITY_RFBIST
#   define MMIC_A_SAFETY_INTEGRITY_RFBIST (7U)
#  endif

#  ifndef MMIC_A_SENSOR_FAULT
#   define MMIC_A_SENSOR_FAULT (8U)
#  endif

#  ifndef MMIC_TEMPERATURE_CONSISTANCY_FAILURE
#   define MMIC_TEMPERATURE_CONSISTANCY_FAILURE (9U)
#  endif

#  ifndef PLATFORM_TIME_FAULT
#   define PLATFORM_TIME_FAULT (10U)
#  endif

#  ifndef TX_BALL_BREAK_FAULT
#   define TX_BALL_BREAK_FAULT (11U)
#  endif

#  ifndef BLOCKAGE_ALGO_ERROR_FAULT
#   define BLOCKAGE_ALGO_ERROR_FAULT (12U)
#  endif

#  ifndef MCU_STARTUP_FAULT
#   define MCU_STARTUP_FAULT (13U)
#  endif

#  ifndef MCU_REPETATIVE_RESET_FAULT
#   define MCU_REPETATIVE_RESET_FAULT (14U)
#  endif

#  ifndef A53_TO_CM7_IPC_FAULT
#   define A53_TO_CM7_IPC_FAULT (15U)
#  endif

#  ifndef CM7_TO_DSP_IPC_FAULT
#   define CM7_TO_DSP_IPC_FAULT (16U)
#  endif

#  ifndef EDMA_FAULT_CALIBRATION
#   define EDMA_FAULT_CALIBRATION (17U)
#  endif

#  ifndef DSP_TO_A53_IPC_FAULT
#   define DSP_TO_A53_IPC_FAULT (18U)
#  endif

#  ifndef DSP_TO_CM7_IPC_FAULT
#   define DSP_TO_CM7_IPC_FAULT (19U)
#  endif

#  ifndef MAX_FAULT_NUMBER
#   define MAX_FAULT_NUMBER (20U)
#  endif
#  ifndef FORCE_OFF
#   define FORCE_OFF (0U)
#  endif

#  ifndef FORCE_ON
#   define FORCE_ON (1U)
#  endif

#  ifndef NO_FORCE
#   define NO_FORCE (2U)
#  endif
#  ifndef NOT_COMPLETED
#   define NOT_COMPLETED (0U)
#  endif

#  ifndef COMPLETED
#   define COMPLETED (1U)
#  endif

#  ifndef FAILED
#   define FAILED (2U)
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
#  ifndef RADAR_NOT_STARTED
#   define RADAR_NOT_STARTED (0U)
#  endif

#  ifndef BUSY_RadarInitStatus
#   define BUSY_RadarInitStatus (1U)
#  endif

#  ifndef RADAR_SUCCESS
#   define RADAR_SUCCESS (2U)
#  endif

#  ifndef RADAR_INITIALIZATION_FAIL
#   define RADAR_INITIALIZATION_FAIL (3U)
#  endif
#  ifndef OFF
#   define OFF (0U)
#  endif

#  ifndef RADAR_INIT
#   define RADAR_INIT (1U)
#  endif

#  ifndef ERROR_RECOVERY
#   define ERROR_RECOVERY (2U)
#  endif

#  ifndef FULLY_OPERATIONAL
#   define FULLY_OPERATIONAL (3U)
#  endif

#  ifndef FAULTY
#   define FAULTY (4U)
#  endif

#  ifndef ENVIRONMENTAL_DEGRADED
#   define ENVIRONMENTAL_DEGRADED (5U)
#  endif

#  ifndef TEMPERATURE_DEGRADED
#   define TEMPERATURE_DEGRADED (6U)
#  endif

#  ifndef MANUFACTURING_MODE
#   define MANUFACTURING_MODE (7U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_MODEMANAGER_TYPE_H */
