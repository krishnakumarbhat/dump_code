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
 *             File:  Rte_SWC_Appl_Project_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_Appl_Project>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_APPL_PROJECT_TYPE_H
# define RTE_SWC_APPL_PROJECT_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Idt_XCP_LED_STATE_AUTO
#   define Idt_XCP_LED_STATE_AUTO (1U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_OFF
#   define Idt_XCP_LED_STATE_FORCED_OFF (16U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_ON
#   define Idt_XCP_LED_STATE_FORCED_ON (17U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_5_PWM
#   define Idt_XCP_LED_STATE_FORCED_5_PWM (160U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_50_PWM
#   define Idt_XCP_LED_STATE_FORCED_50_PWM (161U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_95_PWM
#   define Idt_XCP_LED_STATE_FORCED_95_PWM (162U)
#  endif
#  ifndef Idt_XCP_LED_SELECT_SOURCE_PULL
#   define Idt_XCP_LED_SELECT_SOURCE_PULL (1U)
#  endif

#  ifndef Idt_XCP_LED_SELECT_SOURCE_EN
#   define Idt_XCP_LED_SELECT_SOURCE_EN (2U)
#  endif
#  ifndef TIMEOUT__FALSE
#   define TIMEOUT__FALSE (0U)
#  endif

#  ifndef TIMEOUT_BflMask
#   define TIMEOUT_BflMask 1U
#  endif

#  ifndef TIMEOUT_BflPn
#   define TIMEOUT_BflPn 0U
#  endif

#  ifndef TIMEOUT_BflLn
#   define TIMEOUT_BflLn 1U
#  endif

#  ifndef TIMEOUT
#   define TIMEOUT (1U)
#  endif

#  ifndef SYNC_TO_GATEWAY__FALSE
#   define SYNC_TO_GATEWAY__FALSE (0U)
#  endif

#  ifndef SYNC_TO_GATEWAY_BflMask
#   define SYNC_TO_GATEWAY_BflMask 4U
#  endif

#  ifndef SYNC_TO_GATEWAY_BflPn
#   define SYNC_TO_GATEWAY_BflPn 2U
#  endif

#  ifndef SYNC_TO_GATEWAY_BflLn
#   define SYNC_TO_GATEWAY_BflLn 1U
#  endif

#  ifndef SYNC_TO_GATEWAY
#   define SYNC_TO_GATEWAY (4U)
#  endif

#  ifndef GLOBAL_TIME_BASE__FALSE
#   define GLOBAL_TIME_BASE__FALSE (0U)
#  endif

#  ifndef GLOBAL_TIME_BASE_BflMask
#   define GLOBAL_TIME_BASE_BflMask 8U
#  endif

#  ifndef GLOBAL_TIME_BASE_BflPn
#   define GLOBAL_TIME_BASE_BflPn 3U
#  endif

#  ifndef GLOBAL_TIME_BASE_BflLn
#   define GLOBAL_TIME_BASE_BflLn 1U
#  endif

#  ifndef GLOBAL_TIME_BASE
#   define GLOBAL_TIME_BASE (8U)
#  endif

#  ifndef TIMELEAP_FUTURE__FALSE
#   define TIMELEAP_FUTURE__FALSE (0U)
#  endif

#  ifndef TIMELEAP_FUTURE_BflMask
#   define TIMELEAP_FUTURE_BflMask 16U
#  endif

#  ifndef TIMELEAP_FUTURE_BflPn
#   define TIMELEAP_FUTURE_BflPn 4U
#  endif

#  ifndef TIMELEAP_FUTURE_BflLn
#   define TIMELEAP_FUTURE_BflLn 1U
#  endif

#  ifndef TIMELEAP_FUTURE
#   define TIMELEAP_FUTURE (16U)
#  endif

#  ifndef TIMELEAP_PAST__FALSE
#   define TIMELEAP_PAST__FALSE (0U)
#  endif

#  ifndef TIMELEAP_PAST_BflMask
#   define TIMELEAP_PAST_BflMask 32U
#  endif

#  ifndef TIMELEAP_PAST_BflPn
#   define TIMELEAP_PAST_BflPn 5U
#  endif

#  ifndef TIMELEAP_PAST_BflLn
#   define TIMELEAP_PAST_BflLn 1U
#  endif

#  ifndef TIMELEAP_PAST
#   define TIMELEAP_PAST (32U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_APPL_PROJECT_TYPE_H */
