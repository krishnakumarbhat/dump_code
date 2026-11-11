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
 *            Module: Eth_30_Wrapper
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Eth_30_Wrapper_Lcfg.c
 *   Generation Time: 2026-08-27 14:12:18
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

#define ETH_30_WRAPPER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Eth_30_Wrapper_Lcfg.h"

/*********************************************************************************************************
 * Dynamic includes depending on configuration
 *********************************************************************************************************/
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
  Eth_30_Wrapper_EthCtrl
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_EthCtrl
  \brief  Eth controller table
  \details
  Element                                     Description
  BufferIndexOffsetEnabled                
  CtrlIdx                                     EthWrapper Controller Index
  EthCtrlConfigIngressQueuesPolledEndIdx      the end index of the 0:n relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  EthCtrlConfigIngressQueuesPolledStartIdx    the start index of the 0:n relation pointing to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  EthDrvApiInd                                the enum value of the according target of the 0:1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11
  EthDrvApiIndIdx                             the index of the 0:1 relation pointing to Eth_30_Wrapper_EthDrvApis_AR_4_1_3,Eth_30_Wrapper_EthDrvApis_AR_4_3_0,Eth_30_Wrapper_EthDrvApis_AR_4_3_1,Eth_30_Wrapper_EthDrvApis_AR_4_4_0,Eth_30_Wrapper_EthDrvApis_AR_19_11,Eth_30_Wrapper_EthDrvApis_AR_20_11,Eth_30_Wrapper_EthDrvApis_AR_21_11,Eth_30_Wrapper_EthDrvApis_AR_22_11,Eth_30_Wrapper_EthDrvApis_AR_23_11,Eth_30_Wrapper_EthDrvApis_AR_24_11
  SubCtrlIdx                                  Third-Party Controller Index
*/ 
#define ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Eth_30_Wrapper_EthCtrlType, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthCtrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BufferIndexOffsetEnabled  CtrlIdx  EthCtrlConfigIngressQueuesPolledEndIdx                             EthCtrlConfigIngressQueuesPolledStartIdx                             EthDrvApiInd                                              EthDrvApiIndIdx  SubCtrlIdx        Referable Keys */
  { /*     0 */                    FALSE,      0u, ETH_30_WRAPPER_NO_ETHCTRLCONFIGINGRESSQUEUESPOLLEDENDIDXOFETHCTRL, ETH_30_WRAPPER_NO_ETHCTRLCONFIGINGRESSQUEUESPOLLEDSTARTIDXOFETHCTRL, ETH_30_WRAPPER_ETHDRVAPIS_AR_4_4_0_ETHDRVAPIINDOFETHCTRL,              0u,         0u }   /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */
};
#define ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Eth_30_Wrapper_EthDrvApis_AR_4_4_0
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_EthDrvApis_AR_4_4_0
  \brief  Eth driver APIs for AR_4_4_0
  \details
  Element                    Description
  ControllerInit             Eth_ControllerInit() of Eth driver
  EnableEgressTimeStamp      Eth_EnableEgressTimeStamp() of Eth driver.
  GetControllerMode          Eth_GetControllerMode() of Eth driver
  GetCounterState            Eth_GetCounterState() of Eth driver
  GetCounterValues           Eth_GetCounterValues() of Eth driver
  GetCurrentTime             Eth_GetCurrentTime() of Eth driver.
  GetEgressTimeStamp         Eth_GetEgressTimeStamp() of Eth driver.
  GetIngressTimeStamp        Eth_GetIngressTimeStamp() of Eth driver.
  GetPhysAddr                Eth_GetPhysAddr() of Eth driver
  GetRxStats                 Eth_GetRxStats() of Eth driver
  GetTxErrorCounterValues    Eth_GetTxErrorCounterValues() of Eth driver
  GetTxStats                 Eth_GetTxStats() of Eth driver
  ProvideTxBuffer            Eth_ProvideTxBuffer() of Eth driver
  ReadMii                    Eth_ReadMii() of Eth driver
  Receive                    Eth_Receive() of Eth driver
  SetControllerMode          Eth_SetControllerMode() of Eth driver
  SetPhysAddr                Eth_SetPhysAddr() of Eth driver
  Transmit                   Eth_Transmit() of Eth driver
  TxConfirmation             Eth_TxConfirmation() of Eth driver
  UpdatePhysAddrFilter       Eth_UpdatePhysAddrFilter() of Eth driver
  WriteMii                   Eth_WriteMii() of Eth driver
*/ 
#define ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Eth_30_Wrapper_EthDrvApis_AR_4_4_0Type, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_EthDrvApis_AR_4_4_0[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ControllerInit  EnableEgressTimeStamp       GetControllerMode       GetCounterState  GetCounterValues  GetCurrentTime       GetEgressTimeStamp       GetIngressTimeStamp       GetPhysAddr       GetRxStats  GetTxErrorCounterValues  GetTxStats  ProvideTxBuffer       ReadMii       Receive       SetControllerMode       SetPhysAddr       Transmit       TxConfirmation       UpdatePhysAddrFilter       WriteMii             Referable Keys */
  { /*     0 */ NULL_PTR      , &Eth_EnableEgressTimeStamp, &Eth_GetControllerMode, NULL_PTR       , NULL_PTR        , &Eth_GetCurrentTime, &Eth_GetEgressTimeStamp, &Eth_GetIngressTimeStamp, &Eth_GetPhysAddr, NULL_PTR  , NULL_PTR               , NULL_PTR  , &Eth_ProvideTxBuffer, &Eth_ReadMii, &Eth_Receive, &Eth_SetControllerMode, &Eth_SetPhysAddr, &Eth_Transmit, &Eth_TxConfirmation, &Eth_UpdatePhysAddrFilter, &Eth_WriteMii }   /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */
};
#define ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Eth_30_Wrapper_ApiAccessMutex
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_ApiAccessMutex
  \brief  Api access mutex for dedicated APIs that are defined by AUTOSAR as non-reentrant but are reentrant by the EthWrapper.
  \details
  Element                         Description
  GetCurrentTimeApiLocked         Indicates if the Eth_GetCurrentTime is locked by an ISR/TASK
  GetCurrentTimeTupleApiLocked    Indicates if the Eth_GetCurrentTimeTuple is locked by an ISR/TASK
  ReadMiiApiLocked                Indicates if the Eth_ReadMii is locked by an ISR/TASK
*/ 
#define ETH_30_WRAPPER_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Eth_30_Wrapper_ApiAccessMutexUType, ETH_30_WRAPPER_VAR_NO_INIT) Eth_30_Wrapper_ApiAccessMutex;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */

#define ETH_30_WRAPPER_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Eth_30_Wrapper_PCConfig
**********************************************************************************************************************/
/** 
  \var    Eth_30_Wrapper_PCConfig
  \details
  Element                                   Description
  ApiAccessMutex                            the pointer to Eth_30_Wrapper_ApiAccessMutex
  EthCtrl                                   the pointer to Eth_30_Wrapper_EthCtrl
  EthCtrlConfigIngressQueuesPolled          the pointer to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  EthDrvApis_AR_19_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_19_11
  EthDrvApis_AR_20_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_20_11
  EthDrvApis_AR_21_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_21_11
  EthDrvApis_AR_22_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_22_11
  EthDrvApis_AR_23_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_23_11
  EthDrvApis_AR_24_11                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_24_11
  EthDrvApis_AR_4_1_3                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_1_3
  EthDrvApis_AR_4_3_0                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_0
  EthDrvApis_AR_4_3_1                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_1
  EthDrvApis_AR_4_4_0                       the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_4_0
  SizeOfEthCtrl                             the number of accomplishable value elements in Eth_30_Wrapper_EthCtrl
  SizeOfEthCtrlConfigIngressQueuesPolled    the number of accomplishable value elements in Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled
  SizeOfEthDrvApis_AR_19_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_19_11
  SizeOfEthDrvApis_AR_20_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_20_11
  SizeOfEthDrvApis_AR_21_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_21_11
  SizeOfEthDrvApis_AR_22_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_22_11
  SizeOfEthDrvApis_AR_23_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_23_11
  SizeOfEthDrvApis_AR_24_11                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_24_11
  SizeOfEthDrvApis_AR_4_1_3                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_1_3
  SizeOfEthDrvApis_AR_4_3_0                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_0
  SizeOfEthDrvApis_AR_4_3_1                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_1
  SizeOfEthDrvApis_AR_4_4_0                 the number of accomplishable value elements in Eth_30_Wrapper_EthDrvApis_AR_4_4_0
*/ 
#define ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Eth_30_Wrapper_PCConfigsType, ETH_30_WRAPPER_CONST) Eth_30_Wrapper_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      Eth_30_Wrapper_ApiAccessMutex.raw       /**< the pointer to Eth_30_Wrapper_ApiAccessMutex */
    , Eth_30_Wrapper_EthCtrl                  /**< the pointer to Eth_30_Wrapper_EthCtrl */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_19_11 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_20_11 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_21_11 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_22_11 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_23_11 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_24_11 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
    , NULL_PTR                                /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
    , Eth_30_Wrapper_EthDrvApis_AR_4_4_0      /**< the pointer to Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
    , 1u                                      /**< the number of elements in Eth_30_Wrapper_EthCtrl */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthCtrlConfigIngressQueuesPolled */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_19_11 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_20_11 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_21_11 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_22_11 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_23_11 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_24_11 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_4_1_3 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_0 */
    , 0u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_4_3_1 */
    , 1u                                      /**< the number of elements in Eth_30_Wrapper_EthDrvApis_AR_4_4_0 */
  }
};
#define ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  Eth_30_Wrapper_ConfigDataPtr
**********************************************************************************************************************/
/**
  \var    Eth_30_Wrapper_ConfigDataPtr
  \brief  Points to the currently active configuration for EthWrapper
*/
#define ETH_30_WRAPPER_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
P2CONST(Eth_30_Wrapper_ConfigType, ETH_30_WRAPPER_VAR_NO_INIT, ETH_30_WRAPPER_INIT_DATA) Eth_30_Wrapper_ConfigDataPtr;
#define ETH_30_WRAPPER_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_30_Wrapper_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Wrapper_Cfg.c
 *********************************************************************************************************************/

