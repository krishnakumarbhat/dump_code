/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EthTrcv_30_Tja1103
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Tja1103_Lcfg.c
 *   Generation Time: 2026-09-03 22:28:17
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#define ETHTRCV_30_TJA1103_LCFG_SOURCE
/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "EthTrcv_30_Tja1103_Lcfg.h"

#include "Eth_30_Wrapper.h"

#include "PHY_User_Cbk.h"


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Tja1103_AccessEntityFcts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_AccessEntityFcts
  \brief  Functions of the accesses entities to read/write transceiver registers.
  \details
  Element         Description
  ReadTrcvReg     Function to call when a read register shall be performed
  WriteTrcvReg    Function to call when a write register shall be performed
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_AccessEntityFctsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_AccessEntityFcts[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ReadTrcvReg              WriteTrcvReg                    Referable Keys */
  { /*     0 */ &Eth_30_Wrapper_ReadMii, &Eth_30_Wrapper_WriteMii }   /* [/ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_EthTrcv
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_EthTrcv
  \brief  Ethernet transceivers managed by the driver.
  \details
  Element                   Description
  AccessEntitySnv           Entity providing access to the transceiver hardware
  BasicCtrlRegVal           Initialization value of basic control register
  AutoNegEnabled            Auto negotiation configuration
  HwAccessMonitorEnabled    Enable HW access monitor for the defined Transceiver
  MacSecEnabled             Indicates if MACsec is enabled for this transceiver
  SoftResetOnInitEnabled    Soft reset on initialization configuration
  AccessEntityFctsIdx       the index of the 1:1 relation pointing to EthTrcv_30_Tja1103_AccessEntityFcts
  AddressingIdx             Addressing index in context of the access entity to address the transceiver hardware
  ConnectionNeg             Connection negotiation configuration
  DemEAccessEventId         ETHTRCV_E_ACCESS DEM event
  MiiMode                   Mii interface
  PhySignalQualityMean      Mean value of phyisical signal quality
  SoCBaseRegAddr            Base register address within memory space of SoC in case PHY is integrated as module into SoC.
  SoftResetWaitCycles       Soft reset wait cycles
  Speed                     Transceiver speed
  WakeupIdx                 the index of the 0:1 relation pointing to EthTrcv_30_Tja1103_Wakeup
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_EthTrcvType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_EthTrcv[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AccessEntitySnv                                        BasicCtrlRegVal  AutoNegEnabled  HwAccessMonitorEnabled  MacSecEnabled  SoftResetOnInitEnabled  AccessEntityFctsIdx                                                                         AddressingIdx  ConnectionNeg                                             DemEAccessEventId  MiiMode                                        PhySignalQualityMean  SoCBaseRegAddr  SoftResetWaitCycles  Speed                                             WakeupIdx                                                                                                       */
  { /*     0 */ EthConf_EthCtrlConfig_RDR_1_Eth_Controller_1_6addc1bb,         0x8000u,          FALSE,                  FALSE,         FALSE,                   TRUE,                  0u  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */,           27u, ETHTRCV_30_TJA1103_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV,                0u, ETHTRCV_30_TJA1103_DONT_CARE_MIIMODEOFETHTRCV,                 100u,          0x00u,                100u, ETHTRCV_30_TJA1103_TRCV_SPEED_100_SPEEDOFETHTRCV, ETHTRCV_30_TJA1103_NO_WAKEUPIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */ }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_EthTrcvTja1103
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_EthTrcvTja1103
  \brief  Tja1103 specific configuration data.
  \details
  Element       Description
  Derivative    Tja1103x derivative.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_EthTrcvTja1103Type, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_EthTrcvTja1103[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Derivative                                             */
  { /*     0 */ ETHTRCV_30_TJA1103_TJA1103B_DERIVATIVEOFETHTRCVTJA1103 }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
  \brief  Hardware access monitor failure callouts to application.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_UserHwAccessMonitorFailureCalloutFctPtrType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     HwAccessMonitorFailureCallout      Referable Keys */
  /*     0 */ NULL_PTR                         /* [/ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_PolSwapConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_PolSwapConfig
  \brief  Polarity swap configuration.
  \details
  Element         Description
  PolaritySwap    Polarity swap correction and detection.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_PolSwapConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_PolSwapConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PolaritySwap                                                     */
  { /*     0 */ ETHTRCV_30_TJA1103_POL_NO_CORRECTION_POLARITYSWAPOFPOLSWAPCONFIG }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_SmiConfiguration
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_SmiConfiguration
  \brief  SMI configuration.
  \details
  Element                    Description
  SmiIdlePreChargeEnabled    SMI Idle Pre-Charge Configuration.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_SmiConfigurationType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_SmiConfiguration[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SmiIdlePreChargeEnabled */
  { /*     0 */                    TRUE }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvRgmiiConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvRgmiiConfig
  \brief  RGMII specific configuration data.
  \details
  Element             Description
  RxClkSignalShift    RGMII Rx clock signal shift
  TxClkSignalShift    RGMII Tx clock signal shift
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_TrcvRgmiiConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_TrcvRgmiiConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxClkSignalShift                                                    TxClkSignalShift                                                   */
  { /*     0 */ ETHTRCV_30_TJA1103_SHIFT_INVALID_RXCLKSIGNALSHIFTOFTRCVRGMIICONFIG, ETHTRCV_30_TJA1103_SHIFT_INVALID_TXCLKSIGNALSHIFTOFTRCVRGMIICONFIG }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_UserAccessCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_UserAccessCallouts
  \brief  pretransceiver read/write access callouts to application.
  \details
  Element                      Description
  PreTrcvReadAccessCallout     Pre-Transceiver Read Access callout
  PreTrcvWriteAccessCallout    Pre-Transceiver Write Access callout
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_UserAccessCalloutsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_UserAccessCallouts[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PreTrcvReadAccessCallout  PreTrcvWriteAccessCallout */
  { /*     0 */ NULL_PTR                , NULL_PTR                  }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_UserInitCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_UserInitCallouts
  \brief  Pre-/Post-Transceiver-Initialization callouts to application.
  \details
  Element                Description
  PostInitUserCallout    Post-Transceiver-Initialization callout
  PreInitUserCallout     Pre-Transceiver-Initialization callout
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_UserInitCalloutsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_UserInitCallouts[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PostInitUserCallout     PreInitUserCallout    */
  { /*     0 */ &TJA1103_PHY_Post_Init, &TJA1103_PHY_Pre_Init }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_XmiiClkIoConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_XmiiClkIoConfig
  \brief  xMii clock I/O configuration.
  \details
  Element            Description
  DrivingStrength    xMII clock I/O Driving Strength.
  SlewRate           xMII clock I/O Slew Rate.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_XmiiClkIoConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_XmiiClkIoConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DrivingStrength                                                           SlewRate                                                           */
  { /*     0 */ ETHTRCV_30_TJA1103_CLK_STRENGTH_INVALID_DRIVINGSTRENGTHOFXMIICLKIOCONFIG, ETHTRCV_30_TJA1103_CLK_SLEW_RATE_INVALID_SLEWRATEOFXMIICLKIOCONFIG }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_XmiiDataIoConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_XmiiDataIoConfig
  \brief  xMii data I/O configuration.
  \details
  Element            Description
  DrivingStrength    xMII data I/O Driving Strength.
  SlewRate           xMII data I/O Slew Rate.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_XmiiDataIoConfigType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_XmiiDataIoConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DrivingStrength                                                             SlewRate                                                             */
  { /*     0 */ ETHTRCV_30_TJA1103_DATA_STRENGTH_INVALID_DRIVINGSTRENGTHOFXMIIDATAIOCONFIG, ETHTRCV_30_TJA1103_DATA_SLEW_RATE_INVALID_SLEWRATEOFXMIIDATAIOCONFIG }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_CableDiagnosticState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_CableDiagnosticState
  \brief  State of cable diagnostic.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Tja1103_CableDiagnosticStateType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_CableDiagnosticState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter
  \brief  The Wakeup reason cycle Counter
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Tja1103_HwAccessMonitorCycleCounterType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error reaction
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounterType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error recovery
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounterType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvHwAccessibility
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvHwAccessibility
  \brief  Transceiver hardware accessibility
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Tja1103_HardwareAccessibilityType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvHwAccessibility[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvLinkState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvLinkState
  \brief  Transceiver link state.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_StateType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvLinkState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvMode
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvMode
  \brief  Transceiver operating mode.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_ModeType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvMode[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_TrcvState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_TrcvState
  \brief  Transceiver initialization state.
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_StateType, ETHTRCV_30_TJA1103_VAR_NOINIT) EthTrcv_30_Tja1103_TrcvState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Tja1103_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_PCConfig
  \details
  Element                                   Description
  AccessEntityFcts                          the pointer to EthTrcv_30_Tja1103_AccessEntityFcts
  CableDiagnosticState                      the pointer to EthTrcv_30_Tja1103_CableDiagnosticState
  EthTrcv                                   the pointer to EthTrcv_30_Tja1103_EthTrcv
  EthTrcvTja1103                            the pointer to EthTrcv_30_Tja1103_EthTrcvTja1103
  HwAccessMonitorCycleCounter               the pointer to EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter
  HwAccessMonitorFailureCallout             the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
  HwAccessMonitorFailureDebounceCounter     the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter
  HwAccessMonitorRecoveryDebounceCounter    the pointer to EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter
  PolSwapConfig                             the pointer to EthTrcv_30_Tja1103_PolSwapConfig
  SmiConfiguration                          the pointer to EthTrcv_30_Tja1103_SmiConfiguration
  TrcvHwAccessibility                       the pointer to EthTrcv_30_Tja1103_TrcvHwAccessibility
  TrcvLinkState                             the pointer to EthTrcv_30_Tja1103_TrcvLinkState
  TrcvMode                                  the pointer to EthTrcv_30_Tja1103_TrcvMode
  TrcvRgmiiConfig                           the pointer to EthTrcv_30_Tja1103_TrcvRgmiiConfig
  TrcvState                                 the pointer to EthTrcv_30_Tja1103_TrcvState
  UserAccessCallouts                        the pointer to EthTrcv_30_Tja1103_UserAccessCallouts
  UserInitCallouts                          the pointer to EthTrcv_30_Tja1103_UserInitCallouts
  Wakeup                                    the pointer to EthTrcv_30_Tja1103_Wakeup
  WakeupCallout                             the pointer to EthTrcv_30_Tja1103_WakeupCallout
  WakeupMap                                 the pointer to EthTrcv_30_Tja1103_WakeupMap
  WakeupMode                                the pointer to EthTrcv_30_Tja1103_WakeupMode
  WakeupReasonFlags                         the pointer to EthTrcv_30_Tja1103_WakeupReasonFlags
  WakeupVerificationCallout                 the pointer to EthTrcv_30_Tja1103_WakeupVerificationCallout
  XmiiClkIoConfig                           the pointer to EthTrcv_30_Tja1103_XmiiClkIoConfig
  XmiiDataIoConfig                          the pointer to EthTrcv_30_Tja1103_XmiiDataIoConfig
  CableDiagLoopCycles                       Maximum tries the driver performs to get results during cable diagnostics.
  HwAccessLoopCount                         Maximum tries the driver performs to access the hardware.
  HwAccessMonitorFailureDebounceLimiter     The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  HwAccessMonitorLoopLimiter                The loop limiter value to realize the period of the hardware access check in relation to the main function period
  HwAccessMonitorRecoveryDebounceLimiter    The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  MaxPhySignalQualityMean                   Maximum physical signal quality mean configured for the Ethernet transceivers
  SizeOfAccessEntityFcts                    the number of accomplishable value elements in EthTrcv_30_Tja1103_AccessEntityFcts
  SizeOfEthTrcv                             the number of accomplishable value elements in EthTrcv_30_Tja1103_EthTrcv
  SizeOfEthTrcvTja1103                      the number of accomplishable value elements in EthTrcv_30_Tja1103_EthTrcvTja1103
  SizeOfHwAccessMonitorFailureCallout       the number of accomplishable value elements in EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout
  SizeOfPolSwapConfig                       the number of accomplishable value elements in EthTrcv_30_Tja1103_PolSwapConfig
  SizeOfSmiConfiguration                    the number of accomplishable value elements in EthTrcv_30_Tja1103_SmiConfiguration
  SizeOfTrcvRgmiiConfig                     the number of accomplishable value elements in EthTrcv_30_Tja1103_TrcvRgmiiConfig
  SizeOfUserAccessCallouts                  the number of accomplishable value elements in EthTrcv_30_Tja1103_UserAccessCallouts
  SizeOfUserInitCallouts                    the number of accomplishable value elements in EthTrcv_30_Tja1103_UserInitCallouts
  SizeOfWakeup                              the number of accomplishable value elements in EthTrcv_30_Tja1103_Wakeup
  SizeOfWakeupCallout                       the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupCallout
  SizeOfWakeupMap                           the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupMap
  SizeOfWakeupVerificationCallout           the number of accomplishable value elements in EthTrcv_30_Tja1103_WakeupVerificationCallout
  SizeOfXmiiClkIoConfig                     the number of accomplishable value elements in EthTrcv_30_Tja1103_XmiiClkIoConfig
  SizeOfXmiiDataIoConfig                    the number of accomplishable value elements in EthTrcv_30_Tja1103_XmiiDataIoConfig
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Tja1103_PCConfigsType, ETHTRCV_30_TJA1103_CONST) EthTrcv_30_Tja1103_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      EthTrcv_30_Tja1103_AccessEntityFcts                        /**< the pointer to EthTrcv_30_Tja1103_AccessEntityFcts */
    , EthTrcv_30_Tja1103_CableDiagnosticState                    /**< the pointer to EthTrcv_30_Tja1103_CableDiagnosticState */
    , EthTrcv_30_Tja1103_EthTrcv                                 /**< the pointer to EthTrcv_30_Tja1103_EthTrcv */
    , EthTrcv_30_Tja1103_EthTrcvTja1103                          /**< the pointer to EthTrcv_30_Tja1103_EthTrcvTja1103 */
    , (&(EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter))        /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorCycleCounter */
    , EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout           /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout */
    , EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter   /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorFailureDebounceCounter */
    , EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter  /**< the pointer to EthTrcv_30_Tja1103_HwAccessMonitorRecoveryDebounceCounter */
    , EthTrcv_30_Tja1103_PolSwapConfig                           /**< the pointer to EthTrcv_30_Tja1103_PolSwapConfig */
    , EthTrcv_30_Tja1103_SmiConfiguration                        /**< the pointer to EthTrcv_30_Tja1103_SmiConfiguration */
    , EthTrcv_30_Tja1103_TrcvHwAccessibility                     /**< the pointer to EthTrcv_30_Tja1103_TrcvHwAccessibility */
    , EthTrcv_30_Tja1103_TrcvLinkState                           /**< the pointer to EthTrcv_30_Tja1103_TrcvLinkState */
    , EthTrcv_30_Tja1103_TrcvMode                                /**< the pointer to EthTrcv_30_Tja1103_TrcvMode */
    , EthTrcv_30_Tja1103_TrcvRgmiiConfig                         /**< the pointer to EthTrcv_30_Tja1103_TrcvRgmiiConfig */
    , EthTrcv_30_Tja1103_TrcvState                               /**< the pointer to EthTrcv_30_Tja1103_TrcvState */
    , EthTrcv_30_Tja1103_UserAccessCallouts                      /**< the pointer to EthTrcv_30_Tja1103_UserAccessCallouts */
    , EthTrcv_30_Tja1103_UserInitCallouts                        /**< the pointer to EthTrcv_30_Tja1103_UserInitCallouts */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Tja1103_Wakeup */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Tja1103_WakeupCallout */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Tja1103_WakeupMap */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Tja1103_WakeupMode */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Tja1103_WakeupReasonFlags */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Tja1103_WakeupVerificationCallout */
    , EthTrcv_30_Tja1103_XmiiClkIoConfig                         /**< the pointer to EthTrcv_30_Tja1103_XmiiClkIoConfig */
    , EthTrcv_30_Tja1103_XmiiDataIoConfig                        /**< the pointer to EthTrcv_30_Tja1103_XmiiDataIoConfig */
    , 10000u
    , 100u
    , 255u
    , 1u
    , 255u
    , 100u
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_AccessEntityFcts */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_EthTrcv */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_EthTrcvTja1103 */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_HwAccessMonitorFailureCallout */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_PolSwapConfig */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_SmiConfiguration */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_TrcvRgmiiConfig */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_UserAccessCallouts */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_UserInitCallouts */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Tja1103_Wakeup */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Tja1103_WakeupCallout */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Tja1103_WakeupMap */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Tja1103_WakeupVerificationCallout */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_XmiiClkIoConfig */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Tja1103_XmiiDataIoConfig */
  }
};
#define ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Tja1103_ConfigDataPtr
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Tja1103_ConfigDataPtr
  \brief  Points to the currently active configuration for EthTrcv_30_Tja1103
*/ 
#define ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
P2CONST(EthTrcv_30_Tja1103_ConfigType, ETHTRCV_30_TJA1103_VAR_NOINIT, ETHTRCV_30_TJA1103_INIT_DATA) EthTrcv_30_Tja1103_ConfigDataPtr;
#define ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1103_Lcfg.c
 *********************************************************************************************************************/

