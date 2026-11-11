/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @PWM configuration header file
 *
 * @file 	 Pwm_Cfg.h
 * @Date     Generation Time:   2026-08-26 22:51:47
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 * @section DESCRIPTION:
 *
 * @PWM configuration header file
 *------------------------------------------------------------------------------
 *
 * Copyright (c) indie Semiconductor 2025. All rights reserved.
 *
 * Information within this file is indie Semiconductor confidential and proprietary. 
 * 
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @PWM PWM configuration header file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of PWM Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of PWM Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 * @section Maybe Changed By the User: NO
 */
/*===========================================================================*/
#ifndef PWM_CFG_H_
#define PWM_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/
/**< PWM Driver Post-build Configuration Version Info */
#define PWM_CFG_MAJOR_VERSION         (9U) /**< PWM  Configuration Major Version */
#define PWM_CFG_MINOR_VERSION         (1U) /**< PWM  Configuration Minor Version */

/**< PWM Configuration Number of channels  */
#define PWM_NUMBER_CONF_CHANNEL          (4U)  /**Number of configured pwm channels (AR + DDS)*/

#define PWM_NUMBER_CONF_AR_CHANNELS       (2U)  /**Number of configured AR channels*/

#define PWM_NUMBER_CONF_DDS_CHANNELS      (2U)  /**Number of configured DDS channels*/

#define PWM_NUMBER_MAX_CHANNELS		(4U)  /**Number of channels allowed by hardware*/

#define PWM_EOC_UNMASKED_ALLOWS_EXT_TRIGGER	(0U)

#define PWM_EOC_MASKED_BLOCKS_EXT_TRIGGER	(1U)

#define PWM_EOF_UNMASKED_ALLOWS_EXT_TRIGGER	(uint8)(0U)

#define PWM_EOF_MASKED_BLOCKS_EXT_TRIGGER	(uint8)(1U)

#define PWM_EOC_SOURCE_MIPI	(uint8)(0U)

#define PWM_EOC_SOURCE_SYS_TMR_ALARM_0 (uint8)(1U)

#define PWM_EOF_SOURCE_MIPI (uint8)(0U)

#define PWM_EOF_SOURCE_SYS_TMR_ALARM_1 (uint8)(1U) 


#define PWM_ACCESSIBLE_APPS_NUM             (0U) /** Specifies the number of authorized OS applications */

/**< Configuration of option API services */

/**< DeInit Service */
#define PWM_DE_INIT_API                     STD_ON

/**< Set Duty Cycle Service */
#define PWM_SET_DUTY_CYCLE_API              STD_ON

/**< Set Period and Duty Service*/
#define PWM_SET_PERIOD_AND_DUTY_API        	STD_ON

/**< Set Output To Idle service*/
#define PWM_SET_OUTPUT_TO_IDLE_API          STD_ON

/**< Get Output State Service */
#define PWM_GET_OUTPUT_STATE_API            STD_ON

/**< Development Error Detect */
#define PWM_DEV_ERROR_DETECT             	STD_ON


/**< Pwm Safety Features */
#define PWM_SAFETY_ENABLE					STD_OFF


/**< Set Version Info API */
#define PWM_VERSION_INFO_API				STD_ON


/**
 * @def             PWM_OS_ISR_CATEGORY_1
 * @brief           OS Category 1 ISR selector.
 */
#define PWM_OS_ISR_CATEGORY_1                  (1U)

/**
 * @def             PWM_OS_ISR_CATEGORY_2
 * @brief           OS Category 2 ISR selector.
 */
#define PWM_OS_ISR_CATEGORY_2                  (2U)

/**
 * @def             PWM_OS_ISR_CATEGORY
 * @brief           Configured OS ISR category for the PWM FuSa interrupt.
 */
#define PWM_OS_ISR_CATEGORY                    (PWM_OS_ISR_CATEGORY_2)

/**
 * @def             PWM_OS_ISR_SPECIAL_FUNCTION_NAME
 * @brief           OS ISR special function name configured for the PWM FuSa interrupt.
 */
#define PWM_OS_ISR_SPECIAL_FUNCTION_NAME       PWM0123_CTRL_ERR_FUSA_Handler
/* Symbolic names: index into PwmChannelConfig[] (0 .. PWM_NUMBER_CONF_CHANNELS-1) */

/* DDS channels are placed first in PwmChannelConfig[] */
#define PwmConf_PwmChannel_PwmDDSChannel   (0U)
#define PwmConf_PwmChannel_PwmDDSChannel_001   (1U)

/* AR channels follow DDS channels */
#define PwmConf_PwmChannel_PwmChannel_002   (2U)
#define PwmConf_PwmChannel_PwmChannel_003   (3U)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* PWM_CFG_H_*/
