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
 *             File:  Rte_SWC_PRJ_Appl_Power_Manager_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PRJ_Appl_Power_Manager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_POWER_MANAGER_TYPE_H
# define RTE_SWC_PRJ_APPL_POWER_MANAGER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef RELEASED
#   define RELEASED (0U)
#  endif

#  ifndef REQUESTED
#   define REQUESTED (1U)
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
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_POWER_MANAGER_TYPE_H */
