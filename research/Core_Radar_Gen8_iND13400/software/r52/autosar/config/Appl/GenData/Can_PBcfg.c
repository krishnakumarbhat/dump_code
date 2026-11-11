/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/*===========================================================================*/
/**
 * @Can Post-build Cfg source
 *
 * @file 	 Can_PBcfg.c
 * @Date     Generation Time:   2026-09-17 15:29:19
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 * @section DESCRIPTION:
 *
 * @Can Post-build configuration source file
 *------------------------------------------------------------------------------
 *
 * @copyright 2022 indie Semiconductor.
 *
 * This item is considered confidential and shall not be used, modified, 
 * or distributed without prior written consent from Indie Semiconductor 
 *
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @CAN MCAL Post-build configuration source file
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Can_PBcfg.h"
/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
 
/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD
#include "Can_MemMap.h"
/**
  * @name CanGeneralDefinitions
  * @brief Definitions for CanGeneral included container
  */
/** @{ */

static Can_MainFunctionRWPeriodsType CanMainFunctionPeriod =
{
    .CanMainFunctionReadPeriod                                          = 10U,
    /**< Contains the parameter for configuring the period for cyclic call to Can_MainFunction_Read, Generated for reference as Milliseconds. */
    .CanMainFunctionWritePeriod                                         = 10U
    /**< Contains the parameter for configuring the period for cyclic call to Can_MainFunction_Write, Generated for reference as Milliseconds. */
};


static Can_MainFunctionRWPeriodsType *CanMainFunctionRWPeriodsList[] =
{
    &CanMainFunctionPeriod

};

static Can_GeneralType CanGeneralContainer =
{
    .CanIndex                                                       = 0U,
    /**< Specifies the InstanceId of this module instance. If only one instance is present it shall have the Id 0. */
    .CanMainFunctionBusoffPeriod                                    = 50U,
    /**< This parameter describes the period for cyclic call to Can_MainFunction_Busoff. Unit is Milliseconds. */
    .CanMainFunctionModePeriod                                      = 50U,
    /**< This parameter describes the period for cyclic call to Can_MainFunction_Mode. Unit is Milliseconds. */
    .CanMainFunctionWakeupPeriod                                    = 0U,
    /**< This parameter describes the period for cyclic call to Can_MainFunction_Wakeup. Unit is Milliseconds. */
    #if (STD_ON == CAN_PUBLIC_ICOM_SUPPORT)
    .CanIcomGeneral                                                 = NULL_PTR,
    /**< This subcontainer contains the general configuration parameters of the ICOM Configuration. */
    #endif
    .CanMainFunctionRWPeriods                                       = CanMainFunctionRWPeriodsList
    /**< These subcontainers contain the parameter for configuring the period for cyclic call to Can_MainFunction_Read or Can_MainFunction_Write depending on the referring item. */
}; /**< Multiplicity: 1 */

/** @} */

/**
  * @name CanConfigSetDefinitions
  * @brief Definitions for CanConfigSet included container
  */
/** @{ */

/**
  * @name CanControllerDefinitions
  * @brief Definitions for CanController included subcontainer
  */
/** @{ */

static Can_ControllerFdBaudrateConfigType CanControllerFdBaudrateConfigContainer1_0 =
{
    .CanControllerFdBaudRate                                        = 5000U,
    /**< Specifies the data segment baud rate of the controller in kbps. */
    .CanControllerPropSeg                                           = 1U,
    /**< Specifies propagation delay in time quantas. */
    .CanControllerSeg1                                              = 1U,
    /**< Specifies phase segment 1 in time quantas. */
    .CanControllerSeg2                                              = 1U,
    /**< Specifies phase segment 2 in time quantas. */
    .CanControllerSspOffset                                         = 2U,
    /**< Specifies the Transmitter Delay Compensation Offset in minimum time quanta. */
    .CanControllerSyncJumpWidth                                     = 1U,
    /**< Specifies the synchronization jump width for the controller in time quantas. */
    .CanControllerTxBitRateSwitch                                   = TRUE
    /**< Specifies if the bit rate switching shall be used for transmissions. */
}; /**< Multiplicity: 0..1 */

static Can_ControllerBaudrateConfigType CanControllerBaudrateConfig0_0 =
{
    .CanControllerBaudRate                                          = 500U,
    /**< Specifies the baudrate of the controller in kbps. */
    .CanControllerBaudRateConfigID                                  = 0U,
    /**< Uniquely identifies a specific baud rate configuration. This ID is used by SetBaudrate API. */
    .CanControllerPropSeg                                           = 8U,
    /**< Specifies propagation delay in time quantas. */
    .CanControllerSeg1                                              = 7U,
    /**< Specifies phase segment 1 in time quantas. */
    .CanControllerSeg2                                              = 4U,
    /**< Specifies phase segment 2 in time quantas. */
    .CanControllerSyncJumpWidth                                     = 2U,
    /**< Specifies the synchronization jump width for the controller in time quantas. */
    .CanControllerFdBaudrateConfig                                  = NULL_PTR
    /**< This optional subcontainer contains bit timing related configuration parameters of the CAN controller(s) for payload and CRC of a CAN FD frame. */
}; /**< Multiplicity: 1..* */

static Can_ControllerBaudrateConfigType CanControllerBaudrateConfig1_0 =
{
    .CanControllerBaudRate                                          = 500U,
    /**< Specifies the baudrate of the controller in kbps. */
    .CanControllerBaudRateConfigID                                  = 0U,
    /**< Uniquely identifies a specific baud rate configuration. This ID is used by SetBaudrate API. */
    .CanControllerPropSeg                                           = 16U,
    /**< Specifies propagation delay in time quantas. */
    .CanControllerSeg1                                              = 13U,
    /**< Specifies phase segment 1 in time quantas. */
    .CanControllerSeg2                                              = 10U,
    /**< Specifies phase segment 2 in time quantas. */
    .CanControllerSyncJumpWidth                                     = 5U,
    /**< Specifies the synchronization jump width for the controller in time quantas. */
    .CanControllerFdBaudrateConfig                                  = &CanControllerFdBaudrateConfigContainer1_0
    /**< This optional subcontainer contains bit timing related configuration parameters of the CAN controller(s) for payload and CRC of a CAN FD frame. */
}; /**< Multiplicity: 1..* */

static Can_ControllerBaudrateConfigType *CanControllerBaudrateConfigList0[] =
{
    &CanControllerBaudrateConfig0_0
}; /**< Multiplicity: 1..* */

static Can_ControllerBaudrateConfigType *CanControllerBaudrateConfigList1[] =
{
    &CanControllerBaudrateConfig1_0
}; /**< Multiplicity: 1..* */

static Can_ControllerType CanController0 =
{
    .CanControllerActivation                                        = TRUE,
    /**< Defines if a CAN controller is used in the configuration. */
    .CanControllerBaseAddress                                       = 0x00000000u,
    /**< Specifies the CAN controller base address. */
    .CanControllerId                                                = 0U,
    /**< This parameter provides the controller ID which is unique in a given CAN Driver. */
    .CanWakeupSupport                                               = FALSE,
    /**< CAN driver support for wakeup over CAN Bus. */
    .CanControllerDefaultBaudrate                                   = &CanControllerBaudrateConfig0_0,
    /**< Reference to baudrate configuration container configured for the Can Controller. */
    .CanControllerBaudrateConfig                                    = CanControllerBaudrateConfigList0,
    /**< These subcontainers contain bit timing related configuration parameters of the CAN controller(s). */
    .CanNumberOfBaudrateConfigs                                     = 1U
    /**< The number of Baud Rate configurations available for this controller.*/
};

static Can_ControllerType CanController1 =
{
    .CanControllerActivation                                        = TRUE,
    /**< Defines if a CAN controller is used in the configuration. */
    .CanControllerBaseAddress                                       = 0x00000000u,
    /**< Specifies the CAN controller base address. */
    .CanControllerId                                                = 1U,
    /**< This parameter provides the controller ID which is unique in a given CAN Driver. */
    .CanWakeupSupport                                               = FALSE,
    /**< CAN driver support for wakeup over CAN Bus. */
    .CanControllerDefaultBaudrate                                   = &CanControllerBaudrateConfig1_0,
    /**< Reference to baudrate configuration container configured for the Can Controller. */
    .CanControllerBaudrateConfig                                    = CanControllerBaudrateConfigList1,
    /**< These subcontainers contain bit timing related configuration parameters of the CAN controller(s). */
    .CanNumberOfBaudrateConfigs                                     = 1U
    /**< The number of Baud Rate configurations available for this controller.*/
};

static Can_ControllerType *CanControllerList[] =
{
	&CanController0, 
	&CanController1 
}; /**< Multiplicity: 1..* */

/** @} */

/**
  * @name CanHardwareObjectDefinitions
  * @brief Definitions for CanHardwareObject included subcontainer
  */
/** @{ */

static Can_HwFilterType CanHwFilter1_0 =
{
    .CanHwFilterCode                                        = 0x00000098u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x000007F8u
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter1_1 =
{
    .CanHwFilterCode                                        = 0x80000000u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x80000000u
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter1_2 =
{
    .CanHwFilterCode                                        = 0x00000280u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x000007E0u
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter1_3 =
{
    .CanHwFilterCode                                        = 0x00000001u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x000007FFu
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter1_4 =
{
    .CanHwFilterCode                                        = 0x00000010u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x000007FFu
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter1_5 =
{
    .CanHwFilterCode                                        = 0x00000028u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x000007FFu
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter1_6 =
{
    .CanHwFilterCode                                        = 0x00000030u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x000007FFu
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType CanHwFilter3_0 =
{
    .CanHwFilterCode                                        = 0x00000000u,
    /**< Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */
    .CanHwFilterMask                                        = 0x80000000u
    /**< Describes a mask for hardware-based filtering of CAN identifiers. */
}; /**< Multiplicity: 0..* */

static Can_HwFilterType *CanHwFilterList1[] =
{
    &CanHwFilter1_0,
    &CanHwFilter1_1,
    &CanHwFilter1_2,
    &CanHwFilter1_3,
    &CanHwFilter1_4,
    &CanHwFilter1_5,
    &CanHwFilter1_6
}; /**< Multiplicity: 0..* */

static Can_HwFilterType *CanHwFilterList3[] =
{
    &CanHwFilter3_0
}; /**< Multiplicity: 0..* */

static Can_HardwareObjectType CanHardwareObject0 =
{
    .CanFdPaddingValue                                      = 0U,
    /**< Specifies the value which is used to pad unspecified data in CAN FD frames > 8 bytes for transmission. */
    .CanHandleType                                          = BASIC,
    /**< Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */
    .CanHardwareObjectUsesPolling                           = FALSE,
    /**< Enables polling of this hardware object. */
    .CanHwObjectCount                                       = 1U,
    /**< Number of hardware objects used to implement one HOH. */
    .CanIdType                                              = MIXED_MODE,
    /**< Specifies whether the IdValue is of type standard identifier, extended identifier, mixed mode. */
    .CanObjectId                                            = 0U,
    /**< Holds the handle ID of HRH or HTH. */
    .CanObjectType                                          = TRANSMIT,
    /**< Specifies if the HardwareObject is used as Transmit or as Receive object. */
    .CanTriggerTransmitEnable                               = FALSE,
    /**< This parameter defines if or if not Can supports the trigger-transmit API for this handle. */
    .CanControllerRef                                       = &CanController1,
    /**< Reference to CAN Controller to which the HOH is associated to. */
    .CanMainFunctionRWPeriodRef                             = NULL_PTR,
    /**< Reference to CanMainFunctionPeriod. */
    .CanHwFilter                                            = NULL_PTR,
    /**< These sucontainers are only valid for HRHs and contain the configuration (parameters) of one hardware filter. */
    .CanNumberOfFilters                                     = 0U
    /**< Number of filters. This is only valid for HRHs.*/
}; /**< Multiplicity: 1..* */

static Can_HardwareObjectType CanHardwareObject1 =
{
    .CanFdPaddingValue                                      = 0U,
    /**< Specifies the value which is used to pad unspecified data in CAN FD frames > 8 bytes for transmission. */
    .CanHandleType                                          = BASIC,
    /**< Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */
    .CanHardwareObjectUsesPolling                           = FALSE,
    /**< Enables polling of this hardware object. */
    .CanHwObjectCount                                       = 1U,
    /**< Number of hardware objects used to implement one HOH. */
    .CanIdType                                              = MIXED_MODE,
    /**< Specifies whether the IdValue is of type standard identifier, extended identifier, mixed mode. */
    .CanObjectId                                            = 1U,
    /**< Holds the handle ID of HRH or HTH. */
    .CanObjectType                                          = RECEIVE,
    /**< Specifies if the HardwareObject is used as Transmit or as Receive object. */
    .CanTriggerTransmitEnable                               = FALSE,
    /**< This parameter defines if or if not Can supports the trigger-transmit API for this handle. */
    .CanControllerRef                                       = &CanController1,
    /**< Reference to CAN Controller to which the HOH is associated to. */
    .CanMainFunctionRWPeriodRef                             = &CanMainFunctionPeriod,
    /**< Reference to CanMainFunctionPeriod. */
    .CanHwFilter                                            = CanHwFilterList1,
    /**< These sucontainers are only valid for HRHs and contain the configuration (parameters) of one hardware filter. */
    .CanNumberOfFilters                                     = 7U
    /**< Number of filters. This is only valid for HRHs.*/
}; /**< Multiplicity: 1..* */

static Can_HardwareObjectType CanHardwareObject2 =
{
    .CanFdPaddingValue                                      = 0U,
    /**< Specifies the value which is used to pad unspecified data in CAN FD frames > 8 bytes for transmission. */
    .CanHandleType                                          = BASIC,
    /**< Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */
    .CanHardwareObjectUsesPolling                           = FALSE,
    /**< Enables polling of this hardware object. */
    .CanHwObjectCount                                       = 1U,
    /**< Number of hardware objects used to implement one HOH. */
    .CanIdType                                              = EXTENDED,
    /**< Specifies whether the IdValue is of type standard identifier, extended identifier, mixed mode. */
    .CanObjectId                                            = 2U,
    /**< Holds the handle ID of HRH or HTH. */
    .CanObjectType                                          = TRANSMIT,
    /**< Specifies if the HardwareObject is used as Transmit or as Receive object. */
    .CanTriggerTransmitEnable                               = FALSE,
    /**< This parameter defines if or if not Can supports the trigger-transmit API for this handle. */
    .CanControllerRef                                       = &CanController0,
    /**< Reference to CAN Controller to which the HOH is associated to. */
    .CanMainFunctionRWPeriodRef                             = NULL_PTR,
    /**< Reference to CanMainFunctionPeriod. */
    .CanHwFilter                                            = NULL_PTR,
    /**< These sucontainers are only valid for HRHs and contain the configuration (parameters) of one hardware filter. */
    .CanNumberOfFilters                                     = 0U
    /**< Number of filters. This is only valid for HRHs.*/
}; /**< Multiplicity: 1..* */

static Can_HardwareObjectType CanHardwareObject3 =
{
    .CanFdPaddingValue                                      = 0U,
    /**< Specifies the value which is used to pad unspecified data in CAN FD frames > 8 bytes for transmission. */
    .CanHandleType                                          = BASIC,
    /**< Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */
    .CanHardwareObjectUsesPolling                           = FALSE,
    /**< Enables polling of this hardware object. */
    .CanHwObjectCount                                       = 1U,
    /**< Number of hardware objects used to implement one HOH. */
    .CanIdType                                              = EXTENDED,
    /**< Specifies whether the IdValue is of type standard identifier, extended identifier, mixed mode. */
    .CanObjectId                                            = 3U,
    /**< Holds the handle ID of HRH or HTH. */
    .CanObjectType                                          = RECEIVE,
    /**< Specifies if the HardwareObject is used as Transmit or as Receive object. */
    .CanTriggerTransmitEnable                               = FALSE,
    /**< This parameter defines if or if not Can supports the trigger-transmit API for this handle. */
    .CanControllerRef                                       = &CanController0,
    /**< Reference to CAN Controller to which the HOH is associated to. */
    .CanMainFunctionRWPeriodRef                             = NULL_PTR,
    /**< Reference to CanMainFunctionPeriod. */
    .CanHwFilter                                            = CanHwFilterList3,
    /**< These sucontainers are only valid for HRHs and contain the configuration (parameters) of one hardware filter. */
    .CanNumberOfFilters                                     = 1U
    /**< Number of filters. This is only valid for HRHs.*/
}; /**< Multiplicity: 1..* */

static Can_HardwareObjectType *CanHardwareObjectList[] =
{
    &CanHardwareObject0,
    &CanHardwareObject1,
    &CanHardwareObject2,
    &CanHardwareObject3
}; /**< Multiplicity: 1..* */

/** @} */




#if (STD_ON == CAN_PUBLIC_ICOM_SUPPORT)
/**
  * @name CanIcomDefinitions
  * @brief Definitions for CanIcom included subcontainer
  */
/** @{ */
        /** Add here the parameters for configuring pretended networking. */
/** @} */
#endif

static Can_ConfigSetType CanConfigSetContainer =
{
    .CanController = CanControllerList,
    /**< These subcontainers contain the configuration parameters of the CAN controller(s). */
    .CanHardwareObject = CanHardwareObjectList,
    /**< These subcontainers contain the configuration (parameters) of CAN Hardware Objects. */
    #if (STD_ON == CAN_PUBLIC_ICOM_SUPPORT)
    .CanIcom = NULL_PTR,
    /**< This subcontainer contains the parameters for configuring pretended networking. */
    .CanNumberIcomConfigs = 0U,
    /**< Number of ICOM configurations. */
    #endif
    .CanNumberOfControllers = 2U
    /**< Number of CAN controllers. */
}; /**< Multiplicity: 1 */

/** @} */

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
const Can_ConfigType Can_Config =
{
    .CanGeneral     = &CanGeneralContainer,
    .CanConfigSet   = &CanConfigSetContainer
};


#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Can_MemMap.h"     /* polyspace MISRA-C3:20.1 [Justified:Low] "AUTOSAR Memory Mapping" */ /* polyspace DEFECT:USELESS_INCLUDE [Not a defect:Low] "AUTOSAR Memory Mapping" */
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*===========================================================================*
 *  Local Function Definitions
 *===========================================================================*/
