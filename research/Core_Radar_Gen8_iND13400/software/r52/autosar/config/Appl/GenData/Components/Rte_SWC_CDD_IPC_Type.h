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
 *             File:  Rte_SWC_CDD_IPC_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_CDD_IPC>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_CDD_IPC_TYPE_H
# define RTE_SWC_CDD_IPC_TYPE_H

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
#  ifndef INT_WDG
#   define INT_WDG (0U)
#  endif

#  ifndef EXT_WDG
#   define EXT_WDG (1U)
#  endif

#  ifndef INT_EXT_WDG
#   define INT_EXT_WDG (2U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_CDD_IPC_TYPE_H */
