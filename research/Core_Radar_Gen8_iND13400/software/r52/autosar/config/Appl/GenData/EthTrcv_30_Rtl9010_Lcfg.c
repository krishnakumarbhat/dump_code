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
 *            Module: EthTrcv_30_Rtl9010
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Rtl9010_Lcfg.c
 *   Generation Time: 2026-09-02 19:03:38
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] ETHIF01416 - Hardware module SNV configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] DefinitionRef: /[ANY]/EthTrcv/EthTrcvGeneral/EthTrcvIndexs must be configured to a value in range from 0 to 2 without gaps. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvGeneral[0:EthTrcvIndex](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvGeneral/EthTrcvIndex)
 * /ActiveEcuC/EthTrcv_NXP/EthTrcvGeneral[0:EthTrcvIndex](value=0) (DefRef: /MICROSAR/EthTrcv_30_Tja1103/EthTrcv/EthTrcvGeneral/EthTrcvIndex)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * 
 * [Warning] ETHTRCV01001 - MII index validation error 
 * - [Reduced Severity due to User-Defined Parameter] Multiple DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig use /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb with the same MII address. DefinitionRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfigs connected to a /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb have to use a unique MII address.
 * Erroneous configuration elements:
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 * /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb/EthTrcvMgmtInterface/EthTrcvMiiInterface[0:EthTrcvMiiIdx](value=0) (DefRef: /MICROSAR/EthTrcv_30_Rtl9010/EthTrcv/EthTrcvConfigSet/EthTrcvConfig/EthTrcvMgmtInterface/EthTrcvMiiInterface/EthTrcvMiiIdx)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#define ETHTRCV_30_RTL9010_LCFG_SOURCE
/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "EthTrcv_30_Rtl9010_Lcfg.h"

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
  EthTrcv_30_Rtl9010_AccessEntityFcts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_AccessEntityFcts
  \brief  Functions of the accesses entities to read/write transceiver registers.
  \details
  Element         Description
  ReadTrcvReg     Function to call when a read register shall be performed
  WriteTrcvReg    Function to call when a write register shall be performed
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_AccessEntityFctsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_AccessEntityFcts[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ReadTrcvReg              WriteTrcvReg                    Referable Keys */
  { /*     0 */ &Eth_30_Wrapper_ReadMii, &Eth_30_Wrapper_WriteMii }   /* [/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_EthTrcv
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_EthTrcv
  \brief  Ethernet transceivers managed by the driver.
  \details
  Element                   Description
  AccessEntitySnv           Entity providing access to the transceiver hardware
  BasicCtrlRegVal           Initialization value of basic control register
  AutoNegEnabled            Auto negotiation configuration
  HwAccessMonitorEnabled    Enable HW access monitor for the defined Transceiver
  MacSecEnabled             Indicates if MACsec is enabled for this transceiver
  SoftResetOnInitEnabled    Soft reset on initialization configuration
  AccessEntityFctsIdx       the index of the 1:1 relation pointing to EthTrcv_30_Rtl9010_AccessEntityFcts
  AddressingIdx             Addressing index in context of the access entity to address the transceiver hardware
  ConnectionNeg             Connection negotiation configuration
  DemEAccessEventId         ETHTRCV_E_ACCESS DEM event
  MiiMode                   Mii interface
  PhySignalQualityMean      Mean value of phyisical signal quality
  SoCBaseRegAddr            Base register address within memory space of SoC in case PHY is integrated as module into SoC.
  SoftResetWaitCycles       Soft reset wait cycles
  Speed                     Transceiver speed
  WakeupIdx                 the index of the 0:1 relation pointing to EthTrcv_30_Rtl9010_Wakeup
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_EthTrcvType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcv[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AccessEntitySnv                                        BasicCtrlRegVal  AutoNegEnabled  HwAccessMonitorEnabled  MacSecEnabled  SoftResetOnInitEnabled  AccessEntityFctsIdx                                                                              AddressingIdx  ConnectionNeg                                             DemEAccessEventId  MiiMode                                        PhySignalQualityMean  SoCBaseRegAddr  SoftResetWaitCycles  Speed                                              WakeupIdx                                                                                                            */
  { /*     0 */ EthConf_EthCtrlConfig_RDR_1_Eth_Controller_1_6addc1bb,         0x0140u,          FALSE,                  FALSE,         FALSE,                   TRUE,                  0u  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      ,            0u, ETHTRCV_30_RTL9010_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV,                0u, ETHTRCV_30_RTL9010_DONT_CARE_MIIMODEOFETHTRCV,                 100u,          0x00u,                100u, ETHTRCV_30_RTL9010_TRCV_SPEED_1000_SPEEDOFETHTRCV, ETHTRCV_30_RTL9010_NO_WAKEUPIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */       },
  { /*     1 */ EthConf_EthCtrlConfig_RDR_1_Eth_Controller_1_6addc1bb,         0x2100u,          FALSE,                  FALSE,         FALSE,                   TRUE,                  0u  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */,            0u, ETHTRCV_30_RTL9010_CONN_NEG_SLAVE_CONNECTIONNEGOFETHTRCV,                0u, ETHTRCV_30_RTL9010_DONT_CARE_MIIMODEOFETHTRCV,                 100u,          0x00u,                100u,  ETHTRCV_30_RTL9010_TRCV_SPEED_100_SPEEDOFETHTRCV, ETHTRCV_30_RTL9010_NO_WAKEUPIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */ }
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_EthTrcvRtl9010
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_EthTrcvRtl9010
  \brief  Rtl9010 specific configuration data.
  \details
  Element                Description
  Derivative             Rtl9010AA-Vx derivative
  DrivingStrength        RGMII Driving Strength
  IOPower                RGMII I/O Power Level
  RxcDelayEnable         RGMII delay for Rxc
  RxcDelayValue          RxcDelay level selection
  SoftResetWaitCycles    Soft reset wait cycles
  TxcDelayEnable         RGMII delay for Txc
  TxcDelayValue          TxcDelay level selection
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_EthTrcvRtl9010Type, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvRtl9010[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Derivative                                                    DrivingStrength                                                                   IOPower                                                            RxcDelayEnable                                                        RxcDelayValue                                                                  SoftResetWaitCycles  TxcDelayEnable                                                        TxcDelayValue                                                                 */
  { /*     0 */ ETHTRCV_30_RTL9010_TRCV_RTL9010BX_DERIVATIVEOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_DRIVING_STRENGTH_INVALID_DRIVINGSTRENGTHOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_I_O_LEVEL_INVALID_IOPOWEROFETHTRCVRTL9010, ETHTRCV_30_RTL9010_RXC_DELAY_DISABLED_RXCDELAYENABLEOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_INVALID_RXCDELAYVALUEOFETHTRCVRTL9010,                100u, ETHTRCV_30_RTL9010_TXC_DELAY_DISABLED_TXCDELAYENABLEOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_INVALID_TXCDELAYVALUEOFETHTRCVRTL9010 },
  { /*     1 */ ETHTRCV_30_RTL9010_TRCV_RTL9010BX_DERIVATIVEOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_DRIVING_STRENGTH_INVALID_DRIVINGSTRENGTHOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_I_O_LEVEL_INVALID_IOPOWEROFETHTRCVRTL9010, ETHTRCV_30_RTL9010_RXC_DELAY_DISABLED_RXCDELAYENABLEOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_RXC_DELAY_LEVEL_INVALID_RXCDELAYVALUEOFETHTRCVRTL9010,                100u, ETHTRCV_30_RTL9010_TXC_DELAY_DISABLED_TXCDELAYENABLEOFETHTRCVRTL9010, ETHTRCV_30_RTL9010_TRCV_TXC_DELAY_LEVEL_INVALID_TXCDELAYVALUEOFETHTRCVRTL9010 }
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
  \brief  Rtl9010Ax specific configuration data related to Erratum handling.
  \details
  Element           Description
  Erratum1Active    Indicates if Erratum #1 is active.
  Erratum2Active    Indicates if Erratum #2 is active.
  Erratum3Active    Indicates if Erratum #3 is active.
  Erratum4Active    Indicates if Erratum #4 is active.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlrType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Erratum1Active  Erratum2Active  Erratum3Active  Erratum4Active */
  { /*     0 */          FALSE,          FALSE,          FALSE,          FALSE },
  { /*     1 */          FALSE,          FALSE,          FALSE,          FALSE }
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
  \brief  Hardware access monitor failure callouts to application.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_UserHwAccessMonitorFailureCalloutFctPtrType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     HwAccessMonitorFailureCallout      Referable Keys */
  /*     0 */ NULL_PTR                      ,  /* [/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */ NULL_PTR                         /* [/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_UserAccessCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_UserAccessCallouts
  \brief  pretransceiver read/write access callouts to application.
  \details
  Element                      Description
  PreTrcvReadAccessCallout     Pre-Transceiver Read Access callout
  PreTrcvWriteAccessCallout    Pre-Transceiver Write Access callout
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_UserAccessCalloutsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_UserAccessCallouts[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PreTrcvReadAccessCallout  PreTrcvWriteAccessCallout */
  { /*     0 */ NULL_PTR                , NULL_PTR                  }
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_UserInitCallouts
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_UserInitCallouts
  \brief  Pre-/Post-Transceiver-Initialization callouts to application.
  \details
  Element                Description
  PostInitUserCallout    Post-Transceiver-Initialization callout
  PreInitUserCallout     Pre-Transceiver-Initialization callout
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_UserInitCalloutsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_UserInitCallouts[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PostInitUserCallout  PreInitUserCallout */
  { /*     0 */ &RTL_PHY_Post_Init , &RTL_PHY_Pre_Init  }
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_CableDiagnosticState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_CableDiagnosticState
  \brief  State of cable diagnostic.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Rtl9010_CableDiagnosticStateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_CableDiagnosticState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter
  \brief  The Wakeup reason cycle Counter
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounterType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error reaction
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounterType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter
  \brief  Performs debouncing for the Hw access feature before triggering the error recovery
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounterType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_HwAccessState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_HwAccessState
  \brief  State of the hardware access state for Transceiver initialization
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Rtl9010_HwAccessStateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_HwAccessState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvHwAccessibility
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvHwAccessibility
  \brief  Transceiver hardware accessibility
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_30_Rtl9010_HardwareAccessibilityType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvHwAccessibility[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvLinkState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvLinkState
  \brief  Transceiver link state.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_StateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvLinkState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvMode
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvMode
  \brief  Transceiver operating mode.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_ModeType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvMode[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_TrcvState
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_TrcvState
  \brief  Transceiver initialization state.
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthTrcv_StateType, ETHTRCV_30_RTL9010_VAR_NOINIT) EthTrcv_30_Rtl9010_TrcvState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_PCConfig
  \details
  Element                                   Description
  AccessEntityFcts                          the pointer to EthTrcv_30_Rtl9010_AccessEntityFcts
  CableDiagnosticState                      the pointer to EthTrcv_30_Rtl9010_CableDiagnosticState
  EthTrcv                                   the pointer to EthTrcv_30_Rtl9010_EthTrcv
  EthTrcvRtl9010                            the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010
  EthTrcvRtl9010AxErrataHdlr                the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
  HwAccessMonitorCycleCounter               the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter
  HwAccessMonitorFailureCallout             the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
  HwAccessMonitorFailureDebounceCounter     the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter
  HwAccessMonitorRecoveryDebounceCounter    the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter
  HwAccessState                             the pointer to EthTrcv_30_Rtl9010_HwAccessState
  TrcvHwAccessibility                       the pointer to EthTrcv_30_Rtl9010_TrcvHwAccessibility
  TrcvLinkState                             the pointer to EthTrcv_30_Rtl9010_TrcvLinkState
  TrcvMode                                  the pointer to EthTrcv_30_Rtl9010_TrcvMode
  TrcvState                                 the pointer to EthTrcv_30_Rtl9010_TrcvState
  UserAccessCallouts                        the pointer to EthTrcv_30_Rtl9010_UserAccessCallouts
  UserInitCallouts                          the pointer to EthTrcv_30_Rtl9010_UserInitCallouts
  Wakeup                                    the pointer to EthTrcv_30_Rtl9010_Wakeup
  WakeupCallout                             the pointer to EthTrcv_30_Rtl9010_WakeupCallout
  WakeupMap                                 the pointer to EthTrcv_30_Rtl9010_WakeupMap
  WakeupMode                                the pointer to EthTrcv_30_Rtl9010_WakeupMode
  WakeupReasonFlags                         the pointer to EthTrcv_30_Rtl9010_WakeupReasonFlags
  WakeupVerificationCallout                 the pointer to EthTrcv_30_Rtl9010_WakeupVerificationCallout
  CableDiagLoopCycles                       Maximum tries the driver performs to get results during cable diagnostics.
  HwAccessLoopCount                         Maximum tries the driver performs to access the hardware.
  HwAccessMonitorFailureDebounceLimiter     The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  HwAccessMonitorLoopLimiter                The loop limiter value to realize the period of the hardware access check in relation to the main function period
  HwAccessMonitorRecoveryDebounceLimiter    The debounce limiter number. The debouncing is completed when the debounce counter reaches that value
  MaxPhySignalQualityMean                   Maximum physical signal quality mean configured for the Ethernet transceivers
  SizeOfAccessEntityFcts                    the number of accomplishable value elements in EthTrcv_30_Rtl9010_AccessEntityFcts
  SizeOfEthTrcv                             the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcv
  SizeOfEthTrcvRtl9010                      the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010
  SizeOfEthTrcvRtl9010AxErrataHdlr          the number of accomplishable value elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr
  SizeOfHwAccessMonitorFailureCallout       the number of accomplishable value elements in EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout
  SizeOfUserAccessCallouts                  the number of accomplishable value elements in EthTrcv_30_Rtl9010_UserAccessCallouts
  SizeOfUserInitCallouts                    the number of accomplishable value elements in EthTrcv_30_Rtl9010_UserInitCallouts
  SizeOfWakeup                              the number of accomplishable value elements in EthTrcv_30_Rtl9010_Wakeup
  SizeOfWakeupCallout                       the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupCallout
  SizeOfWakeupMap                           the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupMap
  SizeOfWakeupVerificationCallout           the number of accomplishable value elements in EthTrcv_30_Rtl9010_WakeupVerificationCallout
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthTrcv_30_Rtl9010_PCConfigsType, ETHTRCV_30_RTL9010_CONST) EthTrcv_30_Rtl9010_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      EthTrcv_30_Rtl9010_AccessEntityFcts                        /**< the pointer to EthTrcv_30_Rtl9010_AccessEntityFcts */
    , EthTrcv_30_Rtl9010_CableDiagnosticState                    /**< the pointer to EthTrcv_30_Rtl9010_CableDiagnosticState */
    , EthTrcv_30_Rtl9010_EthTrcv                                 /**< the pointer to EthTrcv_30_Rtl9010_EthTrcv */
    , EthTrcv_30_Rtl9010_EthTrcvRtl9010                          /**< the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
    , EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr              /**< the pointer to EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
    , (&(EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter))        /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorCycleCounter */
    , EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout           /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout */
    , EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter   /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorFailureDebounceCounter */
    , EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter  /**< the pointer to EthTrcv_30_Rtl9010_HwAccessMonitorRecoveryDebounceCounter */
    , EthTrcv_30_Rtl9010_HwAccessState                           /**< the pointer to EthTrcv_30_Rtl9010_HwAccessState */
    , EthTrcv_30_Rtl9010_TrcvHwAccessibility                     /**< the pointer to EthTrcv_30_Rtl9010_TrcvHwAccessibility */
    , EthTrcv_30_Rtl9010_TrcvLinkState                           /**< the pointer to EthTrcv_30_Rtl9010_TrcvLinkState */
    , EthTrcv_30_Rtl9010_TrcvMode                                /**< the pointer to EthTrcv_30_Rtl9010_TrcvMode */
    , EthTrcv_30_Rtl9010_TrcvState                               /**< the pointer to EthTrcv_30_Rtl9010_TrcvState */
    , EthTrcv_30_Rtl9010_UserAccessCallouts                      /**< the pointer to EthTrcv_30_Rtl9010_UserAccessCallouts */
    , EthTrcv_30_Rtl9010_UserInitCallouts                        /**< the pointer to EthTrcv_30_Rtl9010_UserInitCallouts */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Rtl9010_Wakeup */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Rtl9010_WakeupCallout */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Rtl9010_WakeupMap */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Rtl9010_WakeupMode */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Rtl9010_WakeupReasonFlags */
    , NULL_PTR                                                   /**< the pointer to EthTrcv_30_Rtl9010_WakeupVerificationCallout */
    , 10000u
    , 100u
    , 255u
    , 1u
    , 255u
    , 100u
    , 1u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_AccessEntityFcts */
    , 2u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_EthTrcv */
    , 2u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010 */
    , 2u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_EthTrcvRtl9010AxErrataHdlr */
    , 2u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_HwAccessMonitorFailureCallout */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_UserAccessCallouts */
    , 1u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_UserInitCallouts */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_Wakeup */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_WakeupCallout */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_WakeupMap */
    , 0u                                                         /**< the number of elements in EthTrcv_30_Rtl9010_WakeupVerificationCallout */
  }
};
#define ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTrcv_30_Rtl9010_ConfigDataPtr
**********************************************************************************************************************/
/** 
  \var    EthTrcv_30_Rtl9010_ConfigDataPtr
  \brief  Points to the currently active configuration for EthTrcv_30_Rtl9010
*/ 
#define ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
P2CONST(EthTrcv_30_Rtl9010_ConfigType, ETHTRCV_30_RTL9010_VAR_NOINIT, ETHTRCV_30_RTL9010_INIT_DATA) EthTrcv_30_Rtl9010_ConfigDataPtr;
#define ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Rtl9010_Lcfg.c
 *********************************************************************************************************************/

