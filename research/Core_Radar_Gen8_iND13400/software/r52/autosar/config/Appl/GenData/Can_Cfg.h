/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/*===========================================================================*/
/**
 * @Can Cfg header
 *
 * @file 	 Can_Cfg.h
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
 * @CAN MCAL configuration header file
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
#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/
/**
 * Can Driver Configuration Version Info 
 */
/** @{ */
/**
 * @def             CAN_CFG_MAJOR_VERSION
 * @brief           Can Driver Configuration Major Version
 */
#define CAN_CFG_MAJOR_VERSION               (0x09U)

/**
 * @def             CAN_CFG_MINOR_VERSION
 * @brief           Can Driver Configuration Minor Version
 */
#define CAN_CFG_MINOR_VERSION               (0x02U)

/**
 * @def             CAN_OS_ISR_CATEGORY_1
 * @requirements    None
 * @brief           OS Category 1 ISR selector.
 */
#define CAN_OS_ISR_CATEGORY_1                  (1U)

/**
 * @def             CAN_OS_ISR_CATEGORY_2
 * @requirements    None
 * @brief           OS Category 2 ISR selector.
 */
#define CAN_OS_ISR_CATEGORY_2                  (2U)

/**
 * @def             CAN0_OS_ISR_CATEGORY
 * @requirements    None
 * @brief           Configured OS ISR category for the CAN interrupt.
 */
#define CAN0_OS_ISR_CATEGORY                    (CAN_OS_ISR_CATEGORY_2)

/**
 * @def             CAN0_OS_ISR_SPECIAL_FUNCTION_NAME
 * @requirements    None
 * @brief           OS ISR special function name configured for the CAN interrupt.
 */
#define CAN0_OS_ISR_SPECIAL_FUNCTION_NAME       CANFD0_Handler

/**
 * @def             CAN1_OS_ISR_CATEGORY
 * @requirements    None
 * @brief           Configured OS ISR category for the CAN interrupt.
 */
#define CAN1_OS_ISR_CATEGORY                    (CAN_OS_ISR_CATEGORY_2)

/**
 * @def             CAN1_OS_ISR_SPECIAL_FUNCTION_NAME
 * @requirements    None
 * @brief           OS ISR special function name configured for the CAN interrupt.
 */
#define CAN1_OS_ISR_SPECIAL_FUNCTION_NAME       CANFD1_Handler

/**
 * @def             CAN_DEV_ERROR_DETECT
 * @requirements    ECUC_Can_00064
 * @brief           Switches the development error detection and notification on or off.
 *                  Parent container: CanGeneral.
 */
#define CAN_DEV_ERROR_DETECT                (STD_OFF)
 
/**
 *@def              CAN_MULTIPLEXED_TRANSMISSION
 *@requirements     ECUC_Can_00095, SWS_Can_00277
 *@brief            Specifies if multiplexed transmission shall be supported.
 *                  Parent container: CanGeneral. 
 */
#define CAN_MULTIPLEXED_TRANSMISSION        (STD_OFF)

/**
 * @def             CAN_PUBLIC_ICOM_SUPPORT
 * @requirements    ECUC_Can_00483
 * @brief           Selects support of Pretended Network features in Can driver.
 *                  Parent container: CanGeneral.
 */
#define CAN_PUBLIC_ICOM_SUPPORT             (STD_OFF)

/**
 * @def             CAN_SET_BAUDRATE_API
 * @requirements    ECUC_Can_00482
 * @brief           If this parameter is set to TRUE the Can_SetBaudrate API shall be supported.
 *                  Parent container: CanGeneral.
 */
#define CAN_SET_BAUDRATE_API                (STD_OFF)

/**
 * @def             CAN_TIMEOUT_DURATION
 * @requirements    ECUC_Can_00113
 * @brief           Specifies the maximum time for blocking function until a timeout is detected. Unit is seconds.
 *                  Parent container: CanGeneral.
 */
#define CAN_TIMEOUT_DURATION                (0U)

/**
 * @def             CAN_VERSION_INFO_API
 * @requirements    ECUC_Can_00106
 * @brief           Switches the Can_GetVersionInfo API ON or OFF.
 *                  Parent container: CanGeneral.
 */
#define CAN_VERSION_INFO_API                (STD_OFF)

/**
 * @def             CAN_BUSOFF_PROCESSING
 * @requirements    ECUC_Can_00314
 * @brief           Enables / disables API Can_MainFunction_BusOff()
 *                  Parent container: CanController.
 */
#define CAN_BUSOFF_PROCESSING               (INTERRUPT)
 
/**
 * @def             CANTRCV_STANDBY_CONTROL
 * @brief           Enables or disables API control of the CAN transceiver standby mode.
 *                  Parent container: CanGeneral.
 */
#define CAN_TRCV_ENABLE_STANDBY_CONTROL       (STD_OFF)

/**
 * @def             CAN_RX_PROCESSING
 * @requirements    ECUC_Can_00317, SWS_Can_00108
 * @brief           Enables / disables API Can_MainFunction_Read()
 *                  Parent container: CanController.
 */
#define CAN_RX_PROCESSING                   (MIXED)

/**
 * @def             CAN_TX_PROCESSING
 * @requirements    ECUC_Can_00318, SWS_Can_00031
 * @brief           Enables / disables API Can_MainFunction_Write()
 *                  Parent container: CanController.
 */
#define CAN_TX_PROCESSING                   (INTERRUPT)

/**
 * @def             CAN_WAKEUP_PROCESSING
 * @requirements    ECUC_Can_00319
 * @brief           Enables / disables API Can_MainFunction_Wakeup()
 *                  Parent container: CanController.
 */
#define CAN_WAKEUP_PROCESSING               (INTERRUPT)

/**
 * @def             CAN_WAKEUP_FUNCTIONALITY_API
 * @requirements    ECUC_Can_00466, SWS_Can_00485
 * @brief           Adds / removes the service Can_CheckWakeup() from the code.
 *                  Parent container: CanController.
 */
#define CAN_WAKEUP_FUNCTIONALITY_API        (STD_OFF)

/**
 * @def             CAN_ICOM_WAKE_ON_BUSOFF
 * @requirements    ECUC_Can_00442
 * @brief           This parameter defines that the MCU shall wake if the bus off is detected or not.
 *                  Parent container: CanIcomConfig.
 */
#define CAN_ICOM_WAKE_ON_BUSOFF             (STD_OFF)

/**
 * @def             CAN_ICOM_PAYLOAD_LENGTH_ERROR
 * @requirements    ECUC_Can_00451
 * @brief           This parameter defines that the MCU shall wake if a payload error occurs
 *                  Parent container: CanIcomRxMessage
 */
#define CAN_ICOM_PAYLOAD_LENGTH_ERROR       (STD_OFF)

/**
 * @def             CAN_MAX_NUMBER_CONTROLLERS
 * @brief           This parameter defines the maximum number of controllers available in a Hardware unit.
 */
#define CAN_MAX_NUMBER_CONTROLLERS          ((uint8) 2U)

/**
 * @def             CAN_MAX_NUMBER_HOH
 * @brief           This parameter defines the maximum number of Hardware Object Handles available in a Hardware unit.
 */
#define CAN_MAX_NUMBER_HOH                  ((uint8) 4U)

/**
 * @def             CAN_ENABLE_ECC_PROTECTION
 * @brief           Enables or disables RAM ECC protection for CAN controller.
 */
#define CAN_ENABLE_ECC_PROTECTION           (STD_OFF)
/**
 * @def             CAN_ENABLE_SPATIAL_REDUDANCY
 * @brief           Enables or disables logic protection in the CAN driver using spatial redundancy mechanism.
 */
#define CAN_ENABLE_SPATIAL_REDUDANCY        (STD_OFF)



/**
 * @def             CAN_SAFETY_SIM_TESTS_ENABLE
 * @brief           Enables simulation tests to verify safety mechanisms prior to CAN driver operation.
 */
#define CAN_SAFETY_SIM_TESTS_ENABLE         (STD_OFF)

/**
 * @def             CAN_ACCESSIBLE_APPS_NUM
 * @brief           Specifies the number of authorized OS applications.
 */
#define CAN_ACCESSIBLE_APPS_NUM             (0U)
/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/

/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

/*===========================================================================*
* Exported Inline Function Definitions and #define Function-Like Macros
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* CAN_CFG_H_*/
