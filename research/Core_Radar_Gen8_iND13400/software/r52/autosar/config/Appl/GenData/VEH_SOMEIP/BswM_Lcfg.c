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
 *            Module: BswM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2026-09-21 13:31:56
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
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 * 
 * [Warning] BSWM01016 - Feature must be enabled! 
 * - [Reduced Severity due to User-Defined Parameter] Module 'J1939Nm' found so 'BswMJ1939NmEnabled' must be enabled!
 * Erroneous configuration elements:
 * /ActiveEcuC/BswM/BswMGeneral[0:BswMJ1939NmEnabled](value=false) (DefRef: /MICROSAR/BswM/BswMGeneral/BswMJ1939NmEnabled)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ MISRA JUSTIFICATION
 ----------------------------------------------------------------------------- */
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif



#define BSWM_START_SEC_CODE_ASIL_D
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes a rule.
 * \details     Arbitrates a rule and executes corresponding action list.
 * \param[in]   handleId       Id of the rule to execute.
 * \param[in]   partitionIdx   Current partition context.
 * \return      E_OK      No action list was executed or corresponding action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);


/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId        Id of the timer to update.
 * \param[in]   value          New value of the timer.
 * \param[in]   partitionIdx   Current partition context.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                         BswM_SizeOfTimerValueType timerId,
                                                         BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  Init
 *********************************************************************************************************************/
/*! \defgroup    Init
 * \{
 */
/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Initializes BswM.
 * \details     Part of the BswM_Init. Initializes all generated variables and executes action lists for initialization.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        May only be called by BswM_Init.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of group Init */

/**********************************************************************************************************************
 *  Common
 *********************************************************************************************************************/
/*! \defgroup    Common
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Switch Modes of RTE and writes RTE values.
 * \details     Forwards a BswM Switch Action to the RTE and writes value of RteRequestPorts to RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group Common */

/**********************************************************************************************************************
 *  SwcModeRequestUpdate
 *********************************************************************************************************************/
/*! \defgroup    SwcModeRequestUpdate
 * \{
 */
/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Reads port values from RTE.
 * \details     Gets the current value of SwcModeRequest Ports and SwcNotification Ports from RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group SwcModeRequestUpdate */

/**********************************************************************************************************************
 *  BswMActionFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionFunctions
 * \{
 */

/*!
 * \{
 * \brief       Executes an action.
 * \details     Generated function which executes the configured action.
 * \param[IN]   handleId      ID of the parameter set which shall be used for calling the action.
 * \param[IN]   partitionIdx  Current partition context
 * \return      E_OK      Action was successfully executed.
 * \return      E_NOT_OK  Execution of Action failed
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SoAd_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Com_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_PduR_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EthSM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_TcpIp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EnableInterrupts_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Rte_Start_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SoAd_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanIf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanSM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWakeup_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterRun_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterShutdown_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPostRun_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Xcp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EthTSyn_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMUserCallout_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Can_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_NvM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_NvMReadAll_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_User_CAN_ComPduGroupHandling_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Sd_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Sd_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Sd_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_LdCom_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanXcp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CryIf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Crypto_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Csm_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanSM_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_NvMWriteAll_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTp_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dcm_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_AckModeTransition_Execute_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_EcuSoftReset_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Det_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dem_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Init_Action_Dem_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_E2EXf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SetOperationCycle_UserCallOut_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Ipdu_Mode_PCAN_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_User_EthIf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionFunctions */
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_02 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_03 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_04 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_05 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_06 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_07 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_08 BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_02 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_03 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_04 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_05 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_06 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_07 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_SoAd_Init_RDR_08 BswM_Action_INIT_Action_SoAd_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_02 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_03 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_04 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_05 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_06 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_07 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_Com_Init_RDR_08 BswM_Action_INIT_Action_Com_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_02 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_03 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_04 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_05 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_06 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_07 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_PduR_Init_RDR_08 BswM_Action_INIT_Action_PduR_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_02 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_03 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_04 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_05 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_06 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_07 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_EthSM_Init_RDR_08 BswM_Action_INIT_Action_EthSM_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_02 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_03 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_04 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_05 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_06 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_07 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIp_Init_RDR_08 BswM_Action_INIT_Action_TcpIp_Init_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_02 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_03 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_04 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_05 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_06 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_07 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_EnableInterrupts_RDR_08 BswM_Action_INIT_Action_EnableInterrupts_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_02 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_03 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_04 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_05 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_06 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_07 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_Init_RDR_08 BswM_Action_INIT_Action_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_02 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_03 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_04 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_05 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_06 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_07 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_ComM_PostInit_RDR_08 BswM_Action_INIT_Action_ComM_PostInit_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_02 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_03 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_04 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_05 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_06 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_07 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_Rte_Start_RDR_08 BswM_Action_INIT_Action_Rte_Start_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_02 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_03 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_04 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_05 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_06 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_07 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_SoAd_PostInit_RDR_08 BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_02 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_03 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_04 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_05 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_06 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_07 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanIf_Init_RDR_08 BswM_Action_INIT_Action_CanIf_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_02 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_03 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_04 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_05 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_06 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_07 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_Init_RDR_08 BswM_Action_INIT_Action_CanSM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_02 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_03 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_04 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_05 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_06 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_07 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_INIT_Action_ETH_ComM_Init_RDR_08 BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_02 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_03 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_04 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_05 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_06 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_07 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_08 BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_02 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_03 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_04 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_05 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_06 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_07 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterWakeup_RDR_08 BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_02 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_03 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_04 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_05 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_06 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_07 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterRun_RDR_08 BswM_Action_ESH_Action_OnEnterRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_02 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_03 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_04 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_05 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_06 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_07 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterShutdown_RDR_08 BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_02 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_03 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_04 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_05 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_06 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_07 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_08 BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_02 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_03 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_04 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_05 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_06 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_07 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_ESH_Action_OnEnterPostRun_RDR_08 BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_02 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_03 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_04 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_05 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_06 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_07 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_08 BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_02 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_03 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_04 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_05 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_06 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_07 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_Xcp_Init_RDR_08 BswM_Action_INIT_Action_Xcp_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_02 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_03 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_04 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_05 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_06 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_07 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PreInit_RDR_08 BswM_Action_INIT_Action_StbM_PreInit_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_02 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_03 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_04 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_05 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_06 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_07 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_EthTSyn_Init_RDR_08 BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_02 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_03 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_04 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_05 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_06 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_07 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_Init_RDR_08 BswM_Action_INIT_Action_StbM_Init_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_02 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_03 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_04 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_05 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_06 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_07 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_INIT_Action_StbM_PostInit_RDR_08 BswM_Action_INIT_Action_StbM_PostInit_RDR_01
#define BswM_Action_BswMUserCallout_RDR_02 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_BswMUserCallout_RDR_03 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_BswMUserCallout_RDR_04 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_BswMUserCallout_RDR_05 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_BswMUserCallout_RDR_06 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_BswMUserCallout_RDR_07 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_BswMUserCallout_RDR_08 BswM_Action_BswMUserCallout_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_02 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_03 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_04 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_05 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_06 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_07 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Can_Init_RDR_08 BswM_Action_INIT_Action_Can_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_02 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_03 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_04 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_05 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_06 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_07 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_08 BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_02 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_03 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_04 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_05 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_06 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_07 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvM_Init_RDR_08 BswM_Action_INIT_Action_NvM_Init_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_02 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_03 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_04 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_05 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_06 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_07 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_INIT_Action_NvMReadAll_RDR_08 BswM_Action_INIT_Action_NvMReadAll_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_02 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_03 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_04 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_05 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_06 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_07 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_User_CAN_ComPduGroupHandling_RDR_08 BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_02 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_03 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_04 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_05 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_06 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_07 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_08 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_02 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_03 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_04 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_05 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_06 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_07 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_08 BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_02 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_03 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_04 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_05 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_06 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_07 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_08 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_02 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_03 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_04 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_05 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_06 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_07 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_08 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_02 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_03 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_04 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_05 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_06 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_07 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_08 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_02 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_03 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_04 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_05 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_06 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_07 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_08 BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_02 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_03 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_04 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_05 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_06 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_07 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_08 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_02 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_03 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_04 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_05 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_06 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_07 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_08 BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_02 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_03 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_04 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_05 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_06 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_07 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_08 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_02 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_03 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_04 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_05 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_06 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_07 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_08 BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_02 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_03 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_04 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_05 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_06 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_07 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PreInit_RDR_08 BswM_Action_INIT_Action_Sd_PreInit_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_02 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_03 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_04 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_05 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_06 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_07 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_Init_RDR_08 BswM_Action_INIT_Action_Sd_Init_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_02 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_03 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_04 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_05 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_06 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_07 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_Sd_PostInit_RDR_08 BswM_Action_INIT_Action_Sd_PostInit_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_02 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_03 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_04 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_05 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_06 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_07 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_LdCom_Init_RDR_08 BswM_Action_INIT_Action_LdCom_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_02 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_03 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_04 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_05 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_06 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_07 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_SomeIpTp_Init_RDR_08 BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_02 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_03 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_04 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_05 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_06 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_07 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanXcp_Init_RDR_08 BswM_Action_INIT_Action_CanXcp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_02 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_03 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_04 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_05 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_06 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_07 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_08 BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_02 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_03 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_04 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_05 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_06 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_07 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CanTSyn_Init_RDR_08 BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_02 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_03 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_04 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_05 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_06 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_07 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_CryIf_Init_RDR_08 BswM_Action_INIT_Action_CryIf_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_02 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_03 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_04 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_05 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_06 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_07 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Crypto_Init_RDR_08 BswM_Action_INIT_Action_Crypto_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_02 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_03 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_04 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_05 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_06 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_07 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_Csm_Init_RDR_08 BswM_Action_INIT_Action_Csm_Init_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_02 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_03 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_04 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_05 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_06 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_07 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanSM_PreInit_RDR_08 BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_02 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_03 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_04 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_05 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_06 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_07 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_NvMWriteAll_RDR_08 BswM_Action_ESH_Action_NvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_02 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_03 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_04 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_05 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_06 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_07 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_08 BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_02 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_03 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_04 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_05 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_06 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_07 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_PreInit_RDR_08 BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_02 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_03 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_04 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_05 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_06 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_07 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_CanTp_Init_RDR_08 BswM_Action_INIT_Action_CanTp_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_02 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_03 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_04 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_05 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_06 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_07 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_INIT_Action_Dcm_Init_RDR_08 BswM_Action_INIT_Action_Dcm_Init_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_02 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_03 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_04 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_05 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_06 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_07 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_AckModeTransition_Execute_RDR_08 BswM_Action_Action_AckModeTransition_Execute_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_02 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_03 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_04 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_05 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_06 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_07 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_Action_EcuSoftReset_RDR_08 BswM_Action_Action_EcuSoftReset_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_02 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_03 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_04 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_05 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_06 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_07 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Det_Init_RDR_08 BswM_Action_INIT_Action_Det_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_02 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_03 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_04 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_05 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_06 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_07 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_INIT_Action_Dem_Init_RDR_08 BswM_Action_INIT_Action_Dem_Init_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_02 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_03 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_04 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_05 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_06 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_07 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_Init_Action_Dem_PreInit_RDR_08 BswM_Action_Init_Action_Dem_PreInit_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_02 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_03 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_04 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_05 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_06 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_07 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_INIT_Action_E2EXf_Init_RDR_08 BswM_Action_INIT_Action_E2EXf_Init_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_02 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_03 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_04 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_05 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_06 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_07 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_SetOperationCycle_UserCallOut_RDR_08 BswM_Action_SetOperationCycle_UserCallOut_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_02 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_03 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_04 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_05 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_06 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_07 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Ipdu_Mode_PCAN_RDR_08 BswM_Action_Ipdu_Mode_PCAN_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_02 BswM_Action_Action_User_EthIf_Init_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_03 BswM_Action_Action_User_EthIf_Init_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_04 BswM_Action_Action_User_EthIf_Init_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_05 BswM_Action_Action_User_EthIf_Init_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_06 BswM_Action_Action_User_EthIf_Init_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_07 BswM_Action_Action_User_EthIf_Init_RDR_01
#define BswM_Action_Action_User_EthIf_Init_RDR_08 BswM_Action_Action_User_EthIf_Init_RDR_01
/*! \} */ /* End of group BswMActionFunctions */

/**********************************************************************************************************************
 *  BswMExpressionFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMExpressionFunctions
 * \{
 */

/*!
 * \{
 * \brief       Evaluates a logical expression.
 * \details     Generated function which evaluates the configured logical expression.
 * \return      1  If logical expression evaluates to true
 * \return      0  If logical expression evaluates to false
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReached_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReleased_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRun_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_LE_EcuSoftReset_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMExpressionFunctions */
#define BswM_ExpFct_ESH_LE_RunReached_RDR_02 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReached_RDR_03 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReached_RDR_04 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReached_RDR_05 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReached_RDR_06 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReached_RDR_07 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReached_RDR_08 BswM_ExpFct_ESH_LE_RunReached_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_02 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_03 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_04 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_05 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_06 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_07 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunReleased_RDR_08 BswM_ExpFct_ESH_LE_RunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_02 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_03 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_04 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_05 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_06 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_07 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_NoWakeup_RDR_08 BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_02 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_03 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_04 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_05 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_06 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_07 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_ValidWakeup_RDR_08 BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_02 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_03 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_04 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_05 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_06 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_07 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_InitToWakeup_RDR_08 BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_02 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_03 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_04 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_05 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_06 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_07 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_PostRunReleased_RDR_08 BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_02 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_03 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_04 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_05 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_06 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_07 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_RunRequested_RDR_08 BswM_ExpFct_ESH_LE_RunRequested_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_02 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_03 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_04 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_05 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_06 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_07 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PostRun_RDR_08 BswM_ExpFct_ESH_LE_PostRun_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_02 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_03 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_04 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_05 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_06 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_07 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_08 BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_02 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_03 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_04 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_05 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_06 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_07 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_08 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_02 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_03 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_04 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_05 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_06 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_07 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_08 BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_02 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_03 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_04 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_05 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_06 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_07 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_08 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_02 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_03 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_04 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_05 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_06 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_07 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_08 BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_02 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_03 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_04 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_05 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_06 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_07 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_08 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_02 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_03 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_04 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_05 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_06 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_07 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_08 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_02 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_03 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_04 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_05 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_06 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_07 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_08 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_02 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_03 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_04 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_05 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_06 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_07 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_08 BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_02 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_03 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_04 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_05 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_06 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_07 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_08 BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_02 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_03 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_04 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_05 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_06 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_07 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_08 BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_01 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_02 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_02 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_03 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_03 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_04 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_04 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_05 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_05 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_06 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_06 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_07 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_07 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_08 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_08 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_02 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_03 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_04 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_05 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_06 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_07 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_08 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_02 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_03 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_04 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_05 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_06 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_07 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_08 BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_02 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_03 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_04 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_05 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_06 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_07 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_08 BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_02 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_03 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_04 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_05 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_06 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_07 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_ESH_LE_CancelNotPending_RDR_08 BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_02 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_03 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_04 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_05 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_06 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_07 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_AckModeTransition_Execute_RDR_08 BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_02 BswM_ExpFct_LE_EcuSoftReset_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_03 BswM_ExpFct_LE_EcuSoftReset_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_04 BswM_ExpFct_LE_EcuSoftReset_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_05 BswM_ExpFct_LE_EcuSoftReset_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_06 BswM_ExpFct_LE_EcuSoftReset_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_07 BswM_ExpFct_LE_EcuSoftReset_RDR_01
#define BswM_ExpFct_LE_EcuSoftReset_RDR_08 BswM_ExpFct_LE_EcuSoftReset_RDR_01
/*! \} */ /* End of group BswMExpressionFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE_ASIL_D
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/


/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BSWM_0310 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionItemsRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ActionItemsRDR_01
  \details
  Element         Description
  ActionsIdx      the index of the 1:1 relation pointing to BswM_Actions
  Parameter       the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
  ParameterIdx    the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsRDR_01[117] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*     0 */        76u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_AL_AckModeTransition_Execute, BswM_Action_Action_AckModeTransition_Execute_RDR_01] */
  { /*     1 */        74u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_AL_EcuSoftReset, BswM_Action_Action_EcuSoftReset_RDR_01] */
  { /*     2 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM, BswM_Action_CC_DisableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1_RDR_01] */
  { /*     3 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM, BswM_Action_CC_EnableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1_RDR_01] */
  { /*     4 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable, BswM_Action_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1_RDR_01] */
  { /*     5 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable, BswM_Action_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Rx_e0e717e1_RDR_01] */
  { /*     6 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable, BswM_Action_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067_RDR_01] */
  { /*     7 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable, BswM_Action_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Tx_b6bdb067_RDR_01] */
  { /*     8 */        16u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable, BswM_Action_Ipdu_Mode_PCAN_RDR_01] */
  { /*     9 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM, BswM_Action_CC_DisableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec_RDR_01] */
  { /*    10 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM, BswM_Action_CC_EnableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec_RDR_01] */
  { /*    11 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable, BswM_Action_CC_DisablePDUGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec_RDR_01] */
  { /*    12 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable, BswM_Action_CC_EnablePDUGroup_NoReinit_RDR01_oVCAN_RADAR_Rx_BC_7567adec_RDR_01] */
  { /*    13 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                               10u },  /* [AL_ESH_AL_ESH_PostRunToPrepCheck, BswM_Action_ESH_PostRunToPrepNested_RDR_01] */
  { /*    14 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                9u },  /* [AL_ESH_AL_ExitPostRun, BswM_Action_ESH_PostRunNested_RDR_01] */
  { /*    15 */        59u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_InitToWakeup, BswM_Action_ESH_Action_OnEnterWakeup_RDR_01] */
  { /*    16 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_InitToWakeup, BswM_Action_ESH_Action_ESH_Wakeup_RDR_01] */
  { /*    17 */        63u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown, BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01] */
  { /*    18 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToPrepShutdown, BswM_Action_ESH_Action_ESH_PrepShutdown_RDR_01] */
  { /*    19 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1_RDR_01] */
  { /*    20 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b_RDR_01] */
  { /*    21 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_SelfRunRequestTimer_Start_RDR_01] */
  { /*    22 */        62u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_OnEnterRun_RDR_01] */
  { /*    23 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_ESH_Run_RDR_01] */
  { /*    24 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_WriteAllTimer_Start_RDR_01] */
  { /*    25 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_NvMWriteAll_RDR_01] */
  { /*    26 */        60u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01] */
  { /*    27 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_ESH_WaitForNvm_RDR_01] */
  { /*    28 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1_RDR_01] */
  { /*    29 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b_RDR_01] */
  { /*    30 */        66u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01] */
  { /*    31 */        64u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_OnEnterPostRun_RDR_01] */
  { /*    32 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_ESH_PostRun_RDR_01] */
  { /*    33 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_WriteAllTimer_Stop_RDR_01] */
  { /*    34 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_CancelWriteAllTimer_Start_RDR_01] */
  { /*    35 */        69u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01] */
  { /*    36 */        59u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_OnEnterWakeup_RDR_01] */
  { /*    37 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_ESH_Wakeup_RDR_01] */
  { /*    38 */        63u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToPrep, BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01] */
  { /*    39 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToPrep, BswM_Action_ESH_Action_ESH_PrepShutdown_RDR_01] */
  { /*    40 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_CancelWriteAllTimer_Stop_RDR_01] */
  { /*    41 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1_RDR_01] */
  { /*    42 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b_RDR_01] */
  { /*    43 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_SelfRunRequestTimer_Start_RDR_01] */
  { /*    44 */        62u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_OnEnterRun_RDR_01] */
  { /*    45 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_ESH_Run_RDR_01] */
  { /*    46 */        41u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Det_Init_RDR_01] */
  { /*    47 */        72u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_BswMUserCallout_RDR_01] */
  { /*    48 */        56u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanSM_PreInit_RDR_01] */
  { /*    49 */        52u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTp_PreInit_RDR_01] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*    50 */        54u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01] */
  { /*    51 */        27u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Sd_PreInit_RDR_01] */
  { /*    52 */        21u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_StbM_PreInit_RDR_01] */
  { /*    53 */        50u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Can_Init_RDR_01] */
  { /*    54 */        58u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanIf_Init_RDR_01] */
  { /*    55 */        45u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Crypto_Init_RDR_01] */
  { /*    56 */        46u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CryIf_Init_RDR_01] */
  { /*    57 */        44u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Csm_Init_RDR_01] */
  { /*    58 */        35u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01] */
  { /*    59 */        32u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_NvM_Init_RDR_01] */
  { /*    60 */        31u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_PduR_Init_RDR_01] */
  { /*    61 */        47u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Com_Init_RDR_01] */
  { /*    62 */        34u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_LdCom_Init_RDR_01] */
  { /*    63 */        57u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanSM_Init_RDR_01] */
  { /*    64 */        53u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTp_Init_RDR_01] */
  { /*    65 */        33u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_NvMReadAll_RDR_01] */
  { /*    66 */        43u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Dcm_Init_RDR_01] */
  { /*    67 */        73u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_User_EthIf_Init_RDR_01] */
  { /*    68 */        19u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_TcpIp_Init_RDR_01] */
  { /*    69 */        26u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_SoAd_Init_RDR_01] */
  { /*    70 */        24u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01] */
  { /*    71 */        20u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01] */
  { /*    72 */        51u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanXcp_Init_RDR_01] */
  { /*    73 */        18u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Xcp_Init_RDR_01] */
  { /*    74 */        37u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_EthSM_Init_RDR_01] */
  { /*    75 */        23u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_StbM_Init_RDR_01] */
  { /*    76 */        55u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTSyn_Init_RDR_01] */
  { /*    77 */        36u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_EthTSyn_Init_RDR_01] */
  { /*    78 */        29u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Sd_Init_RDR_01] */
  { /*    79 */        49u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_ComM_Init_RDR_01] */
  { /*    80 */        48u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_ComM_PostInit_RDR_01] */
  { /*    81 */        39u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01] */
  { /*    82 */        38u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_EnableInterrupts_RDR_01] */
  { /*    83 */        75u,      BSWM_COMMMODESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b_RDR_01] */
  { /*    84 */        75u,      BSWM_COMMMODESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076_RDR_01] */
  { /*    85 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1_RDR_01] */
  { /*    86 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f_RDR_01] */
  { /*    87 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_ALLOW_COM_RDR_EthConnector1_de653f65_RDR_01] */
  { /*    88 */         1u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_User_CAN_ComPduGroupHandling_RDR_01] */
  { /*    89 */        28u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Sd_PostInit_RDR_01] */
  { /*    90 */        25u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_SoAd_PostInit_RDR_01] */
  { /*    91 */        22u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_StbM_PostInit_RDR_01] */
  { /*    92 */        40u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_E2EXf_Init_RDR_01] */
  { /*    93 */        17u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_Init_Action_Dem_PreInit_RDR_01] */
  { /*    94 */        42u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Dem_Init_RDR_01] */
  { /*    95 */         2u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_SetOperationCycle_UserCallOut_RDR_01] */
  { /*    96 */        30u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Rte_Start_RDR_01] */
  { /*    97 */         4u,            BSWM_SDCLIENTPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, BswM_Action_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED_RDR_01] */
  { /*    98 */         5u,          BSWM_SDCONSUMEDPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, BswM_Action_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4_RDR_01] */
  { /*    99 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN_RDR_01] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*   100 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN_RDR_01] */
  { /*   101 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN_RDR_01] */
  { /*   102 */         4u,            BSWM_SDCLIENTPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, BswM_Action_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED_RDR_01] */
  { /*   103 */         5u,          BSWM_SDCONSUMEDPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, BswM_Action_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58_RDR_01] */
  { /*   104 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE_RDR_01] */
  { /*   105 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE_RDR_01] */
  { /*   106 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE_RDR_01] */
  { /*   107 */        13u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01] */
  { /*   108 */        15u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01] */
  { /*   109 */        14u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01] */
  { /*   110 */        12u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01] */
  { /*   111 */        11u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d, BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01] */
  { /*   112 */         9u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581, BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01] */
  { /*   113 */         7u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae, BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01] */
  { /*   114 */        10u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d, BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01] */
  { /*   115 */         8u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581, BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01] */
  { /*   116 */         6u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS }   /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae, BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionItemsRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ActionItemsRDR_05
  \details
  Element         Description
  ActionsIdx      the index of the 1:1 relation pointing to BswM_Actions
  Parameter       the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
  ParameterIdx    the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_DcmSetChannelReadyParameters,BswM_DoIPAllowNonTlsDoIPConnectionParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_EthIfSwitchPortGroupRequestModeParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939KaStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsRDR_05[117] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*     0 */        76u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_AL_AckModeTransition_Execute, BswM_Action_Action_AckModeTransition_Execute_RDR_05] */
  { /*     1 */        74u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_AL_EcuSoftReset, BswM_Action_Action_EcuSoftReset_RDR_05] */
  { /*     2 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM, BswM_Action_CC_DisableDM_RDR05_oPCAN_RADAR_Rx_34d65b66_RDR_05] */
  { /*     3 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM, BswM_Action_CC_EnableDM_RDR05_oPCAN_RADAR_Rx_34d65b66_RDR_05] */
  { /*     4 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable, BswM_Action_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Rx_34d65b66_RDR_05] */
  { /*     5 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable, BswM_Action_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Rx_34d65b66_RDR_05] */
  { /*     6 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable, BswM_Action_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Tx_628cfce0_RDR_05] */
  { /*     7 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable, BswM_Action_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Tx_628cfce0_RDR_05] */
  { /*     8 */        16u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable, BswM_Action_Ipdu_Mode_PCAN_RDR_05] */
  { /*     9 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM, BswM_Action_CC_DisableDM_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e_RDR_05] */
  { /*    10 */        71u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM, BswM_Action_CC_EnableDM_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e_RDR_05] */
  { /*    11 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable, BswM_Action_CC_DisablePDUGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e_RDR_05] */
  { /*    12 */        70u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable, BswM_Action_CC_EnablePDUGroup_NoReinit_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e_RDR_05] */
  { /*    13 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                               10u },  /* [AL_ESH_AL_ESH_PostRunToPrepCheck, BswM_Action_ESH_PostRunToPrepNested_RDR_05] */
  { /*    14 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                9u },  /* [AL_ESH_AL_ExitPostRun, BswM_Action_ESH_PostRunNested_RDR_05] */
  { /*    15 */        59u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_InitToWakeup, BswM_Action_ESH_Action_OnEnterWakeup_RDR_05] */
  { /*    16 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_InitToWakeup, BswM_Action_ESH_Action_ESH_Wakeup_RDR_05] */
  { /*    17 */        63u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown, BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_05] */
  { /*    18 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToPrepShutdown, BswM_Action_ESH_Action_ESH_PrepShutdown_RDR_05] */
  { /*    19 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1_RDR_05] */
  { /*    20 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b_RDR_05] */
  { /*    21 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_SelfRunRequestTimer_Start_RDR_05] */
  { /*    22 */        62u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_OnEnterRun_RDR_05] */
  { /*    23 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_PostRunToRun, BswM_Action_ESH_Action_ESH_Run_RDR_05] */
  { /*    24 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_WriteAllTimer_Start_RDR_05] */
  { /*    25 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_NvMWriteAll_RDR_05] */
  { /*    26 */        60u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_05] */
  { /*    27 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM, BswM_Action_ESH_Action_ESH_WaitForNvm_RDR_05] */
  { /*    28 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1_RDR_05] */
  { /*    29 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b_RDR_05] */
  { /*    30 */        66u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_05] */
  { /*    31 */        64u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_OnEnterPostRun_RDR_05] */
  { /*    32 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun, BswM_Action_ESH_Action_ESH_PostRun_RDR_05] */
  { /*    33 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_WriteAllTimer_Stop_RDR_05] */
  { /*    34 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_CancelWriteAllTimer_Start_RDR_05] */
  { /*    35 */        69u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_05] */
  { /*    36 */        59u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_OnEnterWakeup_RDR_05] */
  { /*    37 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WaitForNvMWakeup, BswM_Action_ESH_Action_ESH_Wakeup_RDR_05] */
  { /*    38 */        63u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToPrep, BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_05] */
  { /*    39 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToPrep, BswM_Action_ESH_Action_ESH_PrepShutdown_RDR_05] */
  { /*    40 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_CancelWriteAllTimer_Stop_RDR_05] */
  { /*    41 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1_RDR_05] */
  { /*    42 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b_RDR_05] */
  { /*    43 */        68u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_SelfRunRequestTimer_Start_RDR_05] */
  { /*    44 */        62u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_OnEnterRun_RDR_05] */
  { /*    45 */        67u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_WakeupToRun, BswM_Action_ESH_Action_ESH_Run_RDR_05] */
  { /*    46 */        41u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Det_Init_RDR_05] */
  { /*    47 */        72u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_BswMUserCallout_RDR_05] */
  { /*    48 */        56u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanSM_PreInit_RDR_05] */
  { /*    49 */        52u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTp_PreInit_RDR_05] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*    50 */        54u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_05] */
  { /*    51 */        27u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Sd_PreInit_RDR_05] */
  { /*    52 */        21u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_StbM_PreInit_RDR_05] */
  { /*    53 */        50u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Can_Init_RDR_05] */
  { /*    54 */        58u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanIf_Init_RDR_05] */
  { /*    55 */        45u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Crypto_Init_RDR_05] */
  { /*    56 */        46u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CryIf_Init_RDR_05] */
  { /*    57 */        44u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Csm_Init_RDR_05] */
  { /*    58 */        35u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_05] */
  { /*    59 */        32u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_NvM_Init_RDR_05] */
  { /*    60 */        31u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_PduR_Init_RDR_05] */
  { /*    61 */        47u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Com_Init_RDR_05] */
  { /*    62 */        34u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_LdCom_Init_RDR_05] */
  { /*    63 */        57u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanSM_Init_RDR_05] */
  { /*    64 */        53u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTp_Init_RDR_05] */
  { /*    65 */        33u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_NvMReadAll_RDR_05] */
  { /*    66 */        43u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Dcm_Init_RDR_05] */
  { /*    67 */        73u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_User_EthIf_Init_RDR_05] */
  { /*    68 */        19u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_TcpIp_Init_RDR_05] */
  { /*    69 */        26u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_SoAd_Init_RDR_05] */
  { /*    70 */        24u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_SomeIpTp_Init_RDR_05] */
  { /*    71 */        20u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_05] */
  { /*    72 */        51u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanXcp_Init_RDR_05] */
  { /*    73 */        18u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Xcp_Init_RDR_05] */
  { /*    74 */        37u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_EthSM_Init_RDR_05] */
  { /*    75 */        23u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_StbM_Init_RDR_05] */
  { /*    76 */        55u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_CanTSyn_Init_RDR_05] */
  { /*    77 */        36u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_EthTSyn_Init_RDR_05] */
  { /*    78 */        29u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Sd_Init_RDR_05] */
  { /*    79 */        49u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_ComM_Init_RDR_05] */
  { /*    80 */        48u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_ComM_PostInit_RDR_05] */
  { /*    81 */        39u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_ETH_ComM_Init_RDR_05] */
  { /*    82 */        38u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_EnableInterrupts_RDR_05] */
  { /*    83 */        75u,      BSWM_COMMMODESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b_RDR_05] */
  { /*    84 */        75u,      BSWM_COMMMODESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076_RDR_05] */
  { /*    85 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1_RDR_05] */
  { /*    86 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f_RDR_05] */
  { /*    87 */        77u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_INIT_AL_Initialize, BswM_Action_Action_ALLOW_COM_RDR_EthConnector1_de653f65_RDR_05] */
  { /*    88 */         1u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_User_CAN_ComPduGroupHandling_RDR_05] */
  { /*    89 */        28u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Sd_PostInit_RDR_05] */
  { /*    90 */        25u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_SoAd_PostInit_RDR_05] */
  { /*    91 */        22u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_StbM_PostInit_RDR_05] */
  { /*    92 */        40u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_E2EXf_Init_RDR_05] */
  { /*    93 */        17u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_Init_Action_Dem_PreInit_RDR_05] */
  { /*    94 */        42u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Dem_Init_RDR_05] */
  { /*    95 */         2u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_SetOperationCycle_UserCallOut_RDR_05] */
  { /*    96 */        30u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize, BswM_Action_INIT_Action_Rte_Start_RDR_05] */
  { /*    97 */         4u,            BSWM_SDCLIENTPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, BswM_Action_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED_RDR_05] */
  { /*    98 */         5u,          BSWM_SDCONSUMEDPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, BswM_Action_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4_RDR_05] */
  { /*    99 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN_RDR_05] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*   100 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN_RDR_05] */
  { /*   101 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN_RDR_05] */
  { /*   102 */         4u,            BSWM_SDCLIENTPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, BswM_Action_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED_RDR_05] */
  { /*   103 */         5u,          BSWM_SDCONSUMEDPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, BswM_Action_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58_RDR_05] */
  { /*   104 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE_RDR_05] */
  { /*   105 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE_RDR_05] */
  { /*   106 */         3u,            BSWM_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01, BswM_Action_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE_RDR_05] */
  { /*   107 */        13u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_05] */
  { /*   108 */        15u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_05] */
  { /*   109 */        14u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_05] */
  { /*   110 */        12u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN, BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_05] */
  { /*   111 */        11u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d, BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_05] */
  { /*   112 */         9u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581, BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_05] */
  { /*   113 */         7u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae, BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_05] */
  { /*   114 */        10u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d, BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_05] */
  { /*   115 */         8u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581, BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_05] */
  { /*   116 */         6u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS }   /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae, BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_05] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element                Description
  Conditional            If true, action list is executed on condition else on trigger.
  ActionItemsEndIdx      the end index of the 0:n relation pointing to BswM_ActionItems
  ActionItemsStartIdx    the start index of the 0:n relation pointing to BswM_ActionItems
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[43] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Conditional  ActionItemsEndIdx  ActionItemsStartIdx        Comment                   Referable Keys */
  { /*     0 */       FALSE,                1u,                  0u },  /* [Priority: 0] */  /* [AL_AL_AckModeTransition_Execute] */
  { /*     1 */       FALSE,                2u,                  1u },  /* [Priority: 0] */  /* [AL_AL_EcuSoftReset] */
  { /*     2 */       FALSE,                3u,                  2u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  { /*     3 */       FALSE,                4u,                  3u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  { /*     4 */       FALSE,                5u,                  4u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  { /*     5 */       FALSE,                6u,                  5u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  { /*     6 */       FALSE,                7u,                  6u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  { /*     7 */       FALSE,                9u,                  7u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  { /*     8 */       FALSE,               10u,                  9u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  { /*     9 */       FALSE,               11u,                 10u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  { /*    10 */       FALSE,               12u,                 11u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  { /*    11 */       FALSE,               13u,                 12u },  /* [Priority: 0] */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  { /*    12 */        TRUE,               14u,                 13u },  /* [Priority: 0] */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*    13 */        TRUE,               15u,                 14u },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitPostRun] */
  { /*    14 */        TRUE,               17u,                 15u },  /* [Priority: 0] */  /* [AL_ESH_AL_InitToWakeup] */
  { /*    15 */        TRUE,               19u,                 17u },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    16 */        TRUE,               24u,                 19u },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToRun] */
  { /*    17 */        TRUE,               28u,                 24u },  /* [Priority: 0] */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    18 */        TRUE,               33u,                 28u },  /* [Priority: 0] */  /* [AL_ESH_AL_RunToPostRun] */
  { /*    19 */        TRUE,               38u,                 33u },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    20 */        TRUE,               40u,                 38u },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    21 */        TRUE,               46u,                 40u },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToRun] */
  { /*    22 */        TRUE,               97u,                 46u },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    23 */       FALSE,               98u,                 97u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  { /*    24 */       FALSE,               99u,                 98u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  { /*    25 */       FALSE,              100u,                 99u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  { /*    26 */       FALSE,              101u,                100u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  { /*    27 */       FALSE,              102u,                101u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  { /*    28 */       FALSE,              103u,                102u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  { /*    29 */       FALSE,              104u,                103u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  { /*    30 */       FALSE,              105u,                104u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  { /*    31 */       FALSE,              106u,                105u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  { /*    32 */       FALSE,              107u,                106u },  /* [Priority: 0] */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  { /*    33 */       FALSE,              108u,                107u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  { /*    34 */       FALSE,              109u,                108u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  { /*    35 */       FALSE,              110u,                109u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  { /*    36 */       FALSE,              111u,                110u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  { /*    37 */       FALSE,              112u,                111u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  { /*    38 */       FALSE,              113u,                112u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  { /*    39 */       FALSE,              114u,                113u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  { /*    40 */       FALSE,              115u,                114u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  { /*    41 */       FALSE,              116u,                115u },  /* [Priority: 0] */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  { /*    42 */       FALSE,              117u,                116u }   /* [Priority: 0] */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_01
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_01[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_01                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_01                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_01                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_01                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_01                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_01                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_01                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_01                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_01                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_01                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_01                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_01                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_01                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_01                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_01                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_01                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_01                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_01                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_01                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_01                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_01                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_01                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_01                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_01                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_01                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_01                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_01                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_01                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_01                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_01                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_01                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1, A_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067, A_CC_DisablePDUGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec, A_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Rx_e0e717e1, A_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Tx_b6bdb067, A_CC_EnablePDUGroup_NoReinit_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1, A_CC_DisableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec, A_CC_EnableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1, A_CC_EnableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_01                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_01                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_01                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_01                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_02
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_02[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_02                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_02                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_02                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_02                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_02                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_02                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_02                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_02                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_02                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_02                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_02     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_02 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_02                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_02                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_02                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_02                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_02                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_02                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_02                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_02                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_02                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_02                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_02                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_02                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_02                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_02                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_02                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_02                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_02                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_02                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_02                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_02                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_02                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_02                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_02                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_02                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_02                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_02                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_02                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_02                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_02                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_02                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_02                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_02                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_02                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_02                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_02                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_02                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_02                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_02                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR02_oPCAN_RADAR_Rx_c92fa313, A_CC_DisablePDUGroup_RDR02_oPCAN_RADAR_Tx_9f750495, A_CC_DisablePDUGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45, A_CC_EnablePDUGroup_NoReinit_RDR02_oPCAN_RADAR_Rx_c92fa313, A_CC_EnablePDUGroup_NoReinit_RDR02_oPCAN_RADAR_Tx_9f750495, A_CC_EnablePDUGroup_NoReinit_RDR02_oVCAN_RADAR_Rx_BC_d6312b45] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR02_oPCAN_RADAR_Rx_c92fa313, A_CC_DisableDM_RDR02_oVCAN_RADAR_Rx_BC_d6312b45, A_CC_EnableDM_RDR02_oPCAN_RADAR_Rx_c92fa313, A_CC_EnableDM_RDR02_oVCAN_RADAR_Rx_BC_d6312b45] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_02                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_02                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_02                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_02                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_03
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_03[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_03                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_03                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_03                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_03                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_03                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_03                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_03                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_03                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_03                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_03                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_03     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_03 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_03                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_03                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_03                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_03                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_03                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_03                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_03                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_03                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_03                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_03                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_03                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_03                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_03                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_03                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_03                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_03                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_03                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_03                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_03                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_03                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_03                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_03                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_03                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_03                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_03                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_03                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_03                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_03                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_03                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_03                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_03                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_03                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_03                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_03                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_03                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_03                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_03                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_03                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR03_oPCAN_RADAR_Rx_67473282, A_CC_DisablePDUGroup_RDR03_oPCAN_RADAR_Tx_311d9504, A_CC_DisablePDUGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d, A_CC_EnablePDUGroup_NoReinit_RDR03_oPCAN_RADAR_Rx_67473282, A_CC_EnablePDUGroup_NoReinit_RDR03_oPCAN_RADAR_Tx_311d9504, A_CC_EnablePDUGroup_NoReinit_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR03_oPCAN_RADAR_Rx_67473282, A_CC_DisableDM_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d, A_CC_EnableDM_RDR03_oPCAN_RADAR_Rx_67473282, A_CC_EnableDM_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_03                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_03                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_03                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_03                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_04
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_04[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_04                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_04                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_04                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_04                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_04                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_04                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_04                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_04                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_04                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_04                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_04     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_04 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_04                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_04                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_04                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_04                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_04                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_04                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_04                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_04                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_04                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_04                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_04                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_04                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_04                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_04                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_04                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_04                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_04                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_04                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_04                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_04                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_04                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_04                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_04                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_04                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_04                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_04                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_04                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_04                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_04                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_04                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_04                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_04                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_04                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_04                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_04                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_04                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_04                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_04                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7, A_CC_DisablePDUGroup_RDR04_oPCAN_RADAR_Tx_cce46d71, A_CC_DisablePDUGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056, A_CC_EnablePDUGroup_NoReinit_RDR04_oPCAN_RADAR_Rx_9abecaf7, A_CC_EnablePDUGroup_NoReinit_RDR04_oPCAN_RADAR_Tx_cce46d71, A_CC_EnablePDUGroup_NoReinit_RDR04_oVCAN_RADAR_Rx_BC_4bed2056] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR04_oPCAN_RADAR_Rx_9abecaf7, A_CC_DisableDM_RDR04_oVCAN_RADAR_Rx_BC_4bed2056, A_CC_EnableDM_RDR04_oPCAN_RADAR_Rx_9abecaf7, A_CC_EnableDM_RDR04_oVCAN_RADAR_Rx_BC_4bed2056] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_04                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_04                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_04                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_04                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_05
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_05[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_05                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_05                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_05                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_05                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_05                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_05                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_05                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_05                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_05                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_05                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_05     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_05 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_05                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_05                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_05                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_05                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_05                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_05                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_05                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_05                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_05                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_05                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_05                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_05                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_05                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_05                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_05                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_05                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_05                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_05                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_05                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_05                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_05                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_05                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_05                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_05                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_05                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_05                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_05                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_05                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_05                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_05                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_05                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_05                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_05                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_05                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_05                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_05                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_05                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_05                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Rx_34d65b66, A_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Tx_628cfce0, A_CC_DisablePDUGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e, A_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Rx_34d65b66, A_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Tx_628cfce0, A_CC_EnablePDUGroup_NoReinit_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR05_oPCAN_RADAR_Rx_34d65b66, A_CC_DisableDM_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e, A_CC_EnableDM_RDR05_oPCAN_RADAR_Rx_34d65b66, A_CC_EnableDM_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_05                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_05                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_05                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_05                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_06
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_06[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_06                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_06                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_06                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_06                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_06                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_06                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_06                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_06                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_06                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_06                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_06     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_06 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_06                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_06                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_06                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_06                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_06                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_06                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_06                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_06                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_06                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_06                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_06                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_06                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_06                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_06                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_06                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_06                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_06                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_06                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_06                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_06                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_06                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_06                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_06                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_06                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_06                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_06                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_06                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_06                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_06                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_06                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_06                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_06                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_06                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_06                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_06                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_06                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_06                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_06                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94, A_CC_DisablePDUGroup_RDR06_oPCAN_RADAR_Tx_4b444812, A_CC_DisablePDUGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7, A_CC_EnablePDUGroup_NoReinit_RDR06_oPCAN_RADAR_Rx_1d1eef94, A_CC_EnablePDUGroup_NoReinit_RDR06_oPCAN_RADAR_Tx_4b444812, A_CC_EnablePDUGroup_NoReinit_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR06_oPCAN_RADAR_Rx_1d1eef94, A_CC_DisableDM_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7, A_CC_EnableDM_RDR06_oPCAN_RADAR_Rx_1d1eef94, A_CC_EnableDM_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_06                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_06                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_06                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_06                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_07
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_07[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_07                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_07                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_07                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_07                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_07                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_07                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_07                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_07                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_07                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_07                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_07     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_07 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_07                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_07                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_07                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_07                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_07                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_07                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_07                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_07                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_07                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_07                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_07                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_07                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_07                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_07                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_07                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_07                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_07                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_07                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_07                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_07                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_07                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_07                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_07                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_07                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_07                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_07                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_07                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_07                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_07                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_07                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_07                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_07                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_07                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_07                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_07                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_07                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_07                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_07                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR07_oPCAN_RADAR_Rx_b3767e05, A_CC_DisablePDUGroup_RDR07_oPCAN_RADAR_Tx_e52cd983, A_CC_DisablePDUGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff, A_CC_EnablePDUGroup_NoReinit_RDR07_oPCAN_RADAR_Rx_b3767e05, A_CC_EnablePDUGroup_NoReinit_RDR07_oPCAN_RADAR_Tx_e52cd983, A_CC_EnablePDUGroup_NoReinit_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR07_oPCAN_RADAR_Rx_b3767e05, A_CC_DisableDM_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff, A_CC_EnableDM_RDR07_oPCAN_RADAR_Rx_b3767e05, A_CC_EnableDM_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_07                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_07                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_07                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_07                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRDR_08
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRDR_08[78] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*     0 */ &BswM_Action_RuleHandler                                                                                                                             ,  /* [R_ESH_PostRunNested, R_ESH_PostRunToPrepNested] */
  /*     1 */ &BswM_Action_User_CAN_ComPduGroupHandling_RDR_08                                                                                                     ,  /* [A_User_CAN_ComPduGroupHandling] */
  /*     2 */ &BswM_Action_SetOperationCycle_UserCallOut_RDR_08                                                                                                    ,  /* [A_SetOperationCycle_UserCallOut] */
  /*     3 */ &BswM_Action_SdServer                                                                                                                                ,  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE, A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  /*     4 */ &BswM_Action_SdClient                                                                                                                                ,  /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED, A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  /*     5 */ &BswM_Action_SdConsumed                                                                                                                              ,  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4, A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
  /*     6 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_08                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED] */
  /*     7 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_08                                        ,  /* [A_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED] */
  /*     8 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_08                                      ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED] */
  /*     9 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_08                                       ,  /* [A_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED] */
  /*    10 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_08                                   ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED] */
  /*    11 */ &BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_08                                    ,  /* [A_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED] */
  /*    12 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_08                                                        ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN] */
  /*    13 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_08                                                   ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE] */
  /*    14 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_08     ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN] */
  /*    15 */ &BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_08 ,  /* [A_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9] */
  /*    16 */ &BswM_Action_Ipdu_Mode_PCAN_RDR_08                                                                                                                   ,  /* [A_Ipdu_Mode_PCAN] */
  /*    17 */ &BswM_Action_Init_Action_Dem_PreInit_RDR_08                                                                                                          ,  /* [A_Init_Action_Dem_PreInit] */
  /*    18 */ &BswM_Action_INIT_Action_Xcp_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Xcp_Init] */
  /*    19 */ &BswM_Action_INIT_Action_TcpIp_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_TcpIp_Init] */
  /*    20 */ &BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_08                                                                                                        ,  /* [A_INIT_Action_TcpIpXcp_Init] */
  /*    21 */ &BswM_Action_INIT_Action_StbM_PreInit_RDR_08                                                                                                         ,  /* [A_INIT_Action_StbM_PreInit] */
  /*    22 */ &BswM_Action_INIT_Action_StbM_PostInit_RDR_08                                                                                                        ,  /* [A_INIT_Action_StbM_PostInit] */
  /*    23 */ &BswM_Action_INIT_Action_StbM_Init_RDR_08                                                                                                            ,  /* [A_INIT_Action_StbM_Init] */
  /*    24 */ &BswM_Action_INIT_Action_SomeIpTp_Init_RDR_08                                                                                                        ,  /* [A_INIT_Action_SomeIpTp_Init] */
  /*    25 */ &BswM_Action_INIT_Action_SoAd_PostInit_RDR_08                                                                                                        ,  /* [A_INIT_Action_SoAd_PostInit] */
  /*    26 */ &BswM_Action_INIT_Action_SoAd_Init_RDR_08                                                                                                            ,  /* [A_INIT_Action_SoAd_Init] */
  /*    27 */ &BswM_Action_INIT_Action_Sd_PreInit_RDR_08                                                                                                           ,  /* [A_INIT_Action_Sd_PreInit] */
  /*    28 */ &BswM_Action_INIT_Action_Sd_PostInit_RDR_08                                                                                                          ,  /* [A_INIT_Action_Sd_PostInit] */
  /*    29 */ &BswM_Action_INIT_Action_Sd_Init_RDR_08                                                                                                              ,  /* [A_INIT_Action_Sd_Init] */
  /*    30 */ &BswM_Action_INIT_Action_Rte_Start_RDR_08                                                                                                            ,  /* [A_INIT_Action_Rte_Start] */
  /*    31 */ &BswM_Action_INIT_Action_PduR_Init_RDR_08                                                                                                            ,  /* [A_INIT_Action_PduR_Init] */
  /*    32 */ &BswM_Action_INIT_Action_NvM_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_NvM_Init] */
  /*    33 */ &BswM_Action_INIT_Action_NvMReadAll_RDR_08                                                                                                           ,  /* [A_INIT_Action_NvMReadAll] */
  /*    34 */ &BswM_Action_INIT_Action_LdCom_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_LdCom_Init] */
  /*    35 */ &BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_08                                                                                                  ,  /* [A_INIT_Action_Fee_30_FlexNor_Init] */
  /*    36 */ &BswM_Action_INIT_Action_EthTSyn_Init_RDR_08                                                                                                         ,  /* [A_INIT_Action_EthTSyn_Init] */
  /*    37 */ &BswM_Action_INIT_Action_EthSM_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_EthSM_Init] */
  /*    38 */ &BswM_Action_INIT_Action_EnableInterrupts_RDR_08                                                                                                     ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    39 */ &BswM_Action_INIT_Action_ETH_ComM_Init_RDR_08                                                                                                        ,  /* [A_INIT_Action_ETH_ComM_Init] */
  /*    40 */ &BswM_Action_INIT_Action_E2EXf_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_E2EXf_Init] */
  /*    41 */ &BswM_Action_INIT_Action_Det_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Det_Init] */
  /*    42 */ &BswM_Action_INIT_Action_Dem_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Dem_Init] */
  /*    43 */ &BswM_Action_INIT_Action_Dcm_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Dcm_Init] */
  /*    44 */ &BswM_Action_INIT_Action_Csm_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Csm_Init] */
  /*    45 */ &BswM_Action_INIT_Action_Crypto_Init_RDR_08                                                                                                          ,  /* [A_INIT_Action_Crypto_Init] */
  /*    46 */ &BswM_Action_INIT_Action_CryIf_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_CryIf_Init] */
  /*    47 */ &BswM_Action_INIT_Action_Com_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Com_Init] */
  /*    48 */ &BswM_Action_INIT_Action_ComM_PostInit_RDR_08                                                                                                        ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    49 */ &BswM_Action_INIT_Action_ComM_Init_RDR_08                                                                                                            ,  /* [A_INIT_Action_ComM_Init] */
  /* Index     Actions                                                                                                                                                   Referable Keys */
  /*    50 */ &BswM_Action_INIT_Action_Can_Init_RDR_08                                                                                                             ,  /* [A_INIT_Action_Can_Init] */
  /*    51 */ &BswM_Action_INIT_Action_CanXcp_Init_RDR_08                                                                                                          ,  /* [A_INIT_Action_CanXcp_Init] */
  /*    52 */ &BswM_Action_INIT_Action_CanTp_PreInit_RDR_08                                                                                                        ,  /* [A_INIT_Action_CanTp_PreInit] */
  /*    53 */ &BswM_Action_INIT_Action_CanTp_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_CanTp_Init] */
  /*    54 */ &BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_08                                                                                                      ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    55 */ &BswM_Action_INIT_Action_CanTSyn_Init_RDR_08                                                                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    56 */ &BswM_Action_INIT_Action_CanSM_PreInit_RDR_08                                                                                                        ,  /* [A_INIT_Action_CanSM_PreInit] */
  /*    57 */ &BswM_Action_INIT_Action_CanSM_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_CanSM_Init] */
  /*    58 */ &BswM_Action_INIT_Action_CanIf_Init_RDR_08                                                                                                           ,  /* [A_INIT_Action_CanIf_Init] */
  /*    59 */ &BswM_Action_ESH_Action_OnEnterWakeup_RDR_08                                                                                                         ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    60 */ &BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_08                                                                                                     ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    61 */ &BswM_Action_ESH_Action_OnEnterShutdown_RDR_08                                                                                                       ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    62 */ &BswM_Action_ESH_Action_OnEnterRun_RDR_08                                                                                                            ,  /* [A_ESH_Action_OnEnterRun] */
  /*    63 */ &BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_08                                                                                                   ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    64 */ &BswM_Action_ESH_Action_OnEnterPostRun_RDR_08                                                                                                        ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    65 */ &BswM_Action_ESH_Action_NvMWriteAll_RDR_08                                                                                                           ,  /* [A_ESH_Action_NvMWriteAll] */
  /*    66 */ &BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_08                                                                                        ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    67 */ &BswM_Action_GenericMode                                                                                                                             ,  /* [A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    68 */ &BswM_Action_TimerControl                                                                                                                            ,  /* [A_ESH_Action_CancelWriteAllTimer_Start, A_ESH_Action_CancelWriteAllTimer_Stop, A_ESH_Action_SelfRunRequestTimer_Start, A_ESH_Action_WriteAllTimer_Start, A_ESH_Action_WriteAllTimer_Stop] */
  /*    69 */ &BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_08                                                                                                     ,  /* [A_ESH_Action_CancelNvMWriteAll] */
  /*    70 */ &BswM_Action_ComPduGroupHandling                                                                                                                     ,  /* [A_CC_DisablePDUGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f, A_CC_DisablePDUGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9, A_CC_DisablePDUGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031, A_CC_EnablePDUGroup_NoReinit_RDR08_oPCAN_RADAR_Rx_3d9c193f, A_CC_EnablePDUGroup_NoReinit_RDR08_oPCAN_RADAR_Tx_6bc6beb9, A_CC_EnablePDUGroup_NoReinit_RDR08_oVCAN_RADAR_Rx_BC_ab243031] */
  /*    71 */ &BswM_Action_ComDMHandling                                                                                                                           ,  /* [A_CC_DisableDM_RDR08_oPCAN_RADAR_Rx_3d9c193f, A_CC_DisableDM_RDR08_oVCAN_RADAR_Rx_BC_ab243031, A_CC_EnableDM_RDR08_oPCAN_RADAR_Rx_3d9c193f, A_CC_EnableDM_RDR08_oVCAN_RADAR_Rx_BC_ab243031] */
  /*    72 */ &BswM_Action_BswMUserCallout_RDR_08                                                                                                                  ,  /* [A_BswMUserCallout] */
  /*    73 */ &BswM_Action_Action_User_EthIf_Init_RDR_08                                                                                                           ,  /* [A_Action_User_EthIf_Init] */
  /*    74 */ &BswM_Action_Action_EcuSoftReset_RDR_08                                                                                                              ,  /* [A_Action_EcuSoftReset] */
  /*    75 */ &BswM_Action_ComMModeSwitch                                                                                                                          ,  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076, A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  /*    76 */ &BswM_Action_Action_AckModeTransition_Execute_RDR_08                                                                                                 ,  /* [A_Action_AckModeTransition_Execute] */
  /*    77 */ &BswM_Action_ComMAllowCom                                                                                                                               /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f, A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b, A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMapping
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMCanSMIndication.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                   ImmediateUserEndIdx  ImmediateUserStartIdx        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1,                  1u,                    0u },  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  { /*     1 */ ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6,                  2u,                    1u }   /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_01[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1    },  /* [A_CC_DisableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     1 */ ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec }   /* [A_CC_DisableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_02[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313    },  /* [A_CC_DisableDM_RDR02_oPCAN_RADAR_Rx_c92fa313] */
  { /*     1 */ ComConf_ComIPduGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45 }   /* [A_CC_DisableDM_RDR02_oVCAN_RADAR_Rx_BC_d6312b45] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_03[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282    },  /* [A_CC_DisableDM_RDR03_oPCAN_RADAR_Rx_67473282] */
  { /*     1 */ ComConf_ComIPduGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d }   /* [A_CC_DisableDM_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_04[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7    },  /* [A_CC_DisableDM_RDR04_oPCAN_RADAR_Rx_9abecaf7] */
  { /*     1 */ ComConf_ComIPduGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056 }   /* [A_CC_DisableDM_RDR04_oVCAN_RADAR_Rx_BC_4bed2056] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_05[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66    },  /* [A_CC_DisableDM_RDR05_oPCAN_RADAR_Rx_34d65b66] */
  { /*     1 */ ComConf_ComIPduGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e }   /* [A_CC_DisableDM_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_06[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94    },  /* [A_CC_DisableDM_RDR06_oPCAN_RADAR_Rx_1d1eef94] */
  { /*     1 */ ComConf_ComIPduGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7 }   /* [A_CC_DisableDM_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_07[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05    },  /* [A_CC_DisableDM_RDR07_oPCAN_RADAR_Rx_b3767e05] */
  { /*     1 */ ComConf_ComIPduGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff }   /* [A_CC_DisableDM_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRDR_08[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f    },  /* [A_CC_DisableDM_RDR08_oPCAN_RADAR_Rx_3d9c193f] */
  { /*     1 */ ComConf_ComIPduGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031 }   /* [A_CC_DisableDM_RDR08_oVCAN_RADAR_Rx_BC_ab243031] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_01[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1    },  /* [A_CC_EnableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     1 */ ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec }   /* [A_CC_EnableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_02[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313    },  /* [A_CC_EnableDM_RDR02_oPCAN_RADAR_Rx_c92fa313] */
  { /*     1 */ ComConf_ComIPduGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45 }   /* [A_CC_EnableDM_RDR02_oVCAN_RADAR_Rx_BC_d6312b45] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_03[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282    },  /* [A_CC_EnableDM_RDR03_oPCAN_RADAR_Rx_67473282] */
  { /*     1 */ ComConf_ComIPduGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d }   /* [A_CC_EnableDM_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_04[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7    },  /* [A_CC_EnableDM_RDR04_oPCAN_RADAR_Rx_9abecaf7] */
  { /*     1 */ ComConf_ComIPduGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056 }   /* [A_CC_EnableDM_RDR04_oVCAN_RADAR_Rx_BC_4bed2056] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_05[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66    },  /* [A_CC_EnableDM_RDR05_oPCAN_RADAR_Rx_34d65b66] */
  { /*     1 */ ComConf_ComIPduGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e }   /* [A_CC_EnableDM_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_06[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94    },  /* [A_CC_EnableDM_RDR06_oPCAN_RADAR_Rx_1d1eef94] */
  { /*     1 */ ComConf_ComIPduGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7 }   /* [A_CC_EnableDM_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_07[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05    },  /* [A_CC_EnableDM_RDR07_oPCAN_RADAR_Rx_b3767e05] */
  { /*     1 */ ComConf_ComIPduGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff }   /* [A_CC_EnableDM_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRDR_08[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f    },  /* [A_CC_EnableDM_RDR08_oPCAN_RADAR_Rx_3d9c193f] */
  { /*     1 */ ComConf_ComIPduGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031 }   /* [A_CC_EnableDM_RDR08_oVCAN_RADAR_Rx_BC_ab243031] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingParameters
  \details
  Element                                   Description
  ActionItemsIdx                            the index of the 1:1 relation pointing to BswM_ActionItems
  ComDMHandlingDisableParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters
  ComDMHandlingDisableParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters
  ComDMHandlingEnableParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingParametersType, BSWM_CONST) BswM_ComDMHandlingParameters[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActionItemsIdx  ComDMHandlingDisableParametersEndIdx                                   ComDMHandlingDisableParametersStartIdx                                   ComDMHandlingEnableParametersEndIdx                                   ComDMHandlingEnableParametersStartIdx                                         Referable Keys */
  { /*     0 */             2u,                                                                    1u,                                                                      0u, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS },  /* [A_CC_DisableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     1 */             3u, BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS,                                                                   1u,                                                                     0u },  /* [A_CC_EnableDM_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     2 */             9u,                                                                    2u,                                                                      1u, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS },  /* [A_CC_DisableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
  { /*     3 */            10u, BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS,                                                                   2u,                                                                     1u }   /* [A_CC_EnableDM_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMAllowComParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComMAllowComParameters
  \details
  Element    Description
  Channel
  Allowed
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMAllowComParametersType, BSWM_CONST) BswM_ComMAllowComParameters[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel                                         Allowed        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b, FALSE   },  /* [A_ESH_Action_ComMDisallow_cnctr_RDR_RdrNet_5172a59b] */
  { /*     1 */ ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1   , FALSE   },  /* [A_ESH_Action_ComMDisallow_CN_PCAN_RADAR_458ff0f1] */
  { /*     2 */ ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b, TRUE    },  /* [A_Action_ALLOW_COM_RDR_EthConnector1_de653f65, A_ESH_Action_ComMAllow_cnctr_RDR_RdrNet_5172a59b] */
  { /*     3 */ ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6   , TRUE    },  /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_CAN2_b6e0049f] */
  { /*     4 */ ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1   , TRUE    }   /* [A_Action_ALLOW_COM_CN_PCAN_RADAR_458ff0f1, A_ESH_Action_ComMAllow_CN_PCAN_RADAR_458ff0f1] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMModeSwitchParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComMModeSwitchParameters
  \details
  Element    Description
  User   
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMModeSwitchParametersType, BSWM_CONST) BswM_ComMModeSwitchParameters[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    User                                            Referable Keys */
  { /*     0 */ ComMConf_ComMUser_CN_PCAN_RADAR_d6cf874b },  /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_d6cf874b] */
  { /*     1 */ ComMConf_ComMUser_CN_VCAN_RADAR_4b138c58 }   /* [A_Action_BSWM_FULL_COM_CN_PCAN_RADAR_CAN2_d7b79076] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingParametersRDR_01
  \details
  Element                                       Description
  ActionItemsIdx                                the index of the 1:1 relation pointing to BswM_ActionItems
  ComPduGroupHandlingStartParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStartParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
  ComPduGroupHandlingStopParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingParametersType, BSWM_CONST) BswM_ComPduGroupHandlingParametersRDR_01[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActionItemsIdx  ComPduGroupHandlingStartParametersEndIdx                                         ComPduGroupHandlingStartParametersStartIdx                                         ComPduGroupHandlingStopParametersEndIdx                                         ComPduGroupHandlingStopParametersStartIdx                                               Referable Keys */
  { /*     0 */             6u, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             1u,                                                                               0u },  /* [A_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067] */
  { /*     1 */             7u,                                                                              1u,                                                                                0u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Tx_b6bdb067] */
  { /*     2 */             4u, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             2u,                                                                               1u },  /* [A_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     3 */             5u,                                                                              2u,                                                                                1u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     4 */            11u, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             3u,                                                                               2u },  /* [A_CC_DisablePDUGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
  { /*     5 */            12u,                                                                              3u,                                                                                2u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS }   /* [A_CC_EnablePDUGroup_NoReinit_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingParametersRDR_05
  \details
  Element                                       Description
  ActionItemsIdx                                the index of the 1:1 relation pointing to BswM_ActionItems
  ComPduGroupHandlingStartParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStartParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
  ComPduGroupHandlingStopParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingParametersType, BSWM_CONST) BswM_ComPduGroupHandlingParametersRDR_05[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ActionItemsIdx  ComPduGroupHandlingStartParametersEndIdx                                         ComPduGroupHandlingStartParametersStartIdx                                         ComPduGroupHandlingStopParametersEndIdx                                         ComPduGroupHandlingStopParametersStartIdx                                               Referable Keys */
  { /*     0 */             4u, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             1u,                                                                               0u },  /* [A_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Rx_34d65b66] */
  { /*     1 */             5u,                                                                              1u,                                                                                0u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Rx_34d65b66] */
  { /*     2 */             6u, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             2u,                                                                               1u },  /* [A_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Tx_628cfce0] */
  { /*     3 */             7u,                                                                              2u,                                                                                1u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Tx_628cfce0] */
  { /*     4 */            11u, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             3u,                                                                               2u },  /* [A_CC_DisablePDUGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
  { /*     5 */            12u,                                                                              3u,                                                                                2u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS }   /* [A_CC_EnablePDUGroup_NoReinit_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_01[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Tx_b6bdb067] */
  { /*     1 */ ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     2 */ ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec }   /* [A_CC_EnablePDUGroup_NoReinit_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_02[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Tx_9f750495    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR02_oPCAN_RADAR_Tx_9f750495] */
  { /*     1 */ ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR02_oPCAN_RADAR_Rx_c92fa313] */
  { /*     2 */ ComConf_ComIPduGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45 }   /* [A_CC_EnablePDUGroup_NoReinit_RDR02_oVCAN_RADAR_Rx_BC_d6312b45] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_03[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Tx_311d9504    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR03_oPCAN_RADAR_Tx_311d9504] */
  { /*     1 */ ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR03_oPCAN_RADAR_Rx_67473282] */
  { /*     2 */ ComConf_ComIPduGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d }   /* [A_CC_EnablePDUGroup_NoReinit_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_04[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Tx_cce46d71    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR04_oPCAN_RADAR_Tx_cce46d71] */
  { /*     1 */ ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR04_oPCAN_RADAR_Rx_9abecaf7] */
  { /*     2 */ ComConf_ComIPduGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056 }   /* [A_CC_EnablePDUGroup_NoReinit_RDR04_oVCAN_RADAR_Rx_BC_4bed2056] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_05[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Rx_34d65b66] */
  { /*     1 */ ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Tx_628cfce0    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR05_oPCAN_RADAR_Tx_628cfce0] */
  { /*     2 */ ComConf_ComIPduGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e }   /* [A_CC_EnablePDUGroup_NoReinit_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_06[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Tx_4b444812    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR06_oPCAN_RADAR_Tx_4b444812] */
  { /*     1 */ ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR06_oPCAN_RADAR_Rx_1d1eef94] */
  { /*     2 */ ComConf_ComIPduGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7 }   /* [A_CC_EnablePDUGroup_NoReinit_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_07[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR07_oPCAN_RADAR_Rx_b3767e05] */
  { /*     1 */ ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Tx_e52cd983    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR07_oPCAN_RADAR_Tx_e52cd983] */
  { /*     2 */ ComConf_ComIPduGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff }   /* [A_CC_EnablePDUGroup_NoReinit_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRDR_08[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR08_oPCAN_RADAR_Rx_3d9c193f] */
  { /*     1 */ ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9    },  /* [A_CC_EnablePDUGroup_NoReinit_RDR08_oPCAN_RADAR_Tx_6bc6beb9] */
  { /*     2 */ ComConf_ComIPduGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031 }   /* [A_CC_EnablePDUGroup_NoReinit_RDR08_oVCAN_RADAR_Rx_BC_ab243031] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_01
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_01[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067    },  /* [A_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067] */
  { /*     1 */ ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1    },  /* [A_CC_DisablePDUGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1] */
  { /*     2 */ ComConf_ComIPduGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec }   /* [A_CC_DisablePDUGroup_RDR01_oVCAN_RADAR_Rx_BC_7567adec] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_02
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_02[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Tx_9f750495    },  /* [A_CC_DisablePDUGroup_RDR02_oPCAN_RADAR_Tx_9f750495] */
  { /*     1 */ ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313    },  /* [A_CC_DisablePDUGroup_RDR02_oPCAN_RADAR_Rx_c92fa313] */
  { /*     2 */ ComConf_ComIPduGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45 }   /* [A_CC_DisablePDUGroup_RDR02_oVCAN_RADAR_Rx_BC_d6312b45] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_03
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_03[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Tx_311d9504    },  /* [A_CC_DisablePDUGroup_RDR03_oPCAN_RADAR_Tx_311d9504] */
  { /*     1 */ ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282    },  /* [A_CC_DisablePDUGroup_RDR03_oPCAN_RADAR_Rx_67473282] */
  { /*     2 */ ComConf_ComIPduGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d }   /* [A_CC_DisablePDUGroup_RDR03_oVCAN_RADAR_Rx_BC_01d3ab1d] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_04
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_04[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Tx_cce46d71    },  /* [A_CC_DisablePDUGroup_RDR04_oPCAN_RADAR_Tx_cce46d71] */
  { /*     1 */ ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7    },  /* [A_CC_DisablePDUGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7] */
  { /*     2 */ ComConf_ComIPduGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056 }   /* [A_CC_DisablePDUGroup_RDR04_oVCAN_RADAR_Rx_BC_4bed2056] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_05
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_05[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66    },  /* [A_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Rx_34d65b66] */
  { /*     1 */ ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Tx_628cfce0    },  /* [A_CC_DisablePDUGroup_RDR05_oPCAN_RADAR_Tx_628cfce0] */
  { /*     2 */ ComConf_ComIPduGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e }   /* [A_CC_DisablePDUGroup_RDR05_oVCAN_RADAR_Rx_BC_9c0fa00e] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_06
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_06[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Tx_4b444812    },  /* [A_CC_DisablePDUGroup_RDR06_oPCAN_RADAR_Tx_4b444812] */
  { /*     1 */ ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94    },  /* [A_CC_DisablePDUGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94] */
  { /*     2 */ ComConf_ComIPduGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7 }   /* [A_CC_DisablePDUGroup_RDR06_oVCAN_RADAR_Rx_BC_3f5926a7] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_07
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_07[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05    },  /* [A_CC_DisablePDUGroup_RDR07_oPCAN_RADAR_Rx_b3767e05] */
  { /*     1 */ ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Tx_e52cd983    },  /* [A_CC_DisablePDUGroup_RDR07_oPCAN_RADAR_Tx_e52cd983] */
  { /*     2 */ ComConf_ComIPduGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff }   /* [A_CC_DisablePDUGroup_RDR07_oVCAN_RADAR_Rx_BC_e8bba6ff] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRDR_08
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRDR_08[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                  Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f    },  /* [A_CC_DisablePDUGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f] */
  { /*     1 */ ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9    },  /* [A_CC_DisablePDUGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9] */
  { /*     2 */ ComConf_ComIPduGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031 }   /* [A_CC_DisablePDUGroup_RDR08_oVCAN_RADAR_Rx_BC_ab243031] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[17] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       0u },  /* [R_BswMRule_AckModeTransition_Execute] */
  { /*     1 */       1u },  /* [R_BswMRule_EcuSoftReset] */
  { /*     2 */       8u },  /* [R_ESH_PostRun] */
  { /*     3 */      12u },  /* [R_ESH_RunToPostRun] */
  { /*     4 */      13u },  /* [R_ESH_WaitToWakeup] */
  { /*     5 */      14u },  /* [R_ESH_WakeupToPrep] */
  { /*     6 */      15u },  /* [R_ESH_WakeupToRun] */
  { /*     7 */      16u },  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  { /*     8 */      17u },  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  { /*     9 */      18u },  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  { /*    10 */      19u },  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  { /*    11 */      20u },  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  { /*    12 */      21u },  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  { /*    13 */      22u },  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  { /*    14 */      23u },  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  { /*    15 */      24u },  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  { /*    16 */      25u }   /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_01
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_01[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_01                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_01                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_01                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_01                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_01                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_01                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_01                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_01                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_01                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_01                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_01                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_01                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_01                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_01                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_01                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_01                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_01                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_02
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_02[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_02                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_02                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_02                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_02                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_02                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_02                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_02                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_02                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_02                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_02                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_02                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_02                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_02                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_02                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_02                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_02                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_02                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_02                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_02                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_02                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_02                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_02 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_02                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_02  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_02                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_02                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_02                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_02                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_02                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_02                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_02                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_02                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_02                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_02                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_02                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_02                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_02                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_03
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_03[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_03                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_03                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_03                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_03                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_03                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_03                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_03                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_03                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_03                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_03                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_03                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_03                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_03                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_03                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_03                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_03                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_03                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_03                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_03                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_03                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_03                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_03 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_03                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_03  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_03                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_03                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_03                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_03                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_03                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_03                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_03                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_03                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_03                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_03                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_03                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_03                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_03                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_04
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_04[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_04                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_04                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_04                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_04                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_04                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_04                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_04                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_04                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_04                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_04                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_04                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_04                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_04                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_04                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_04                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_04                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_04                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_04                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_04                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_04                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_04                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_04 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_04                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_04  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_04                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_04                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_04                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_04                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_04                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_04                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_04                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_04                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_04                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_04                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_04                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_04                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_04                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_05
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_05[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_05                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_05                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_05                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_05                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_05                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_05                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_05                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_05                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_05                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_05                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_05                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_05                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_05                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_05                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_05                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_05                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_05                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_05                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_05                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_05                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_05                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_05 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_05                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_05  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_05                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_05                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_05                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_05                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_05                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_05                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_05                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_05                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_05                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_05                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_05                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_05                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_05                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_06
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_06[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_06                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_06                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_06                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_06                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_06                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_06                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_06                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_06                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_06                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_06                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_06                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_06                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_06                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_06                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_06                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_06                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_06                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_06                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_06                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_06                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_06                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_06 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_06                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_06  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_06                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_06                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_06                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_06                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_06                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_06                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_06                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_06                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_06                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_06                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_06                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_06                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_06                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_07
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_07[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_07                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_07                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_07                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_07                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_07                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_07                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_07                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_07                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_07                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_07                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_07                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_07                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_07                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_07                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_07                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_07                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_07                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_07                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_07                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_07                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_07                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_07 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_07                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_07  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_07                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_07                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_07                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_07                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_07                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_07                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_07                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_07                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_07                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_07                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_07                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_07                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_07                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRDR_08
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRDR_08[37] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     Expressions                                                                                                                                        Referable Keys */
  /*     0 */ &BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_08                                                                                             ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ &BswM_ExpFct_ESH_LE_RunReached_RDR_08                                                                                                         ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ &BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_08                                                                                           ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ &BswM_ExpFct_ESH_LE_NoRunReasons_RDR_08                                                                                                       ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ &BswM_ExpFct_ESH_LE_RunReleased_RDR_08                                                                                                        ,  /* [LE_ESH_LE_RunReleased] */
  /*     5 */ &BswM_ExpFct_ESH_LE_NoWakeup_RDR_08                                                                                                           ,  /* [LE_ESH_LE_NoWakeup] */
  /*     6 */ &BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_08                                                                                               ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*     7 */ &BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_08                                                                                                 ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*     8 */ &BswM_ExpFct_ESH_LE_ValidWakeup_RDR_08                                                                                                        ,  /* [LE_ESH_LE_ValidWakeup] */
  /*     9 */ &BswM_ExpFct_ESH_LE_WakeupToRun_RDR_08                                                                                                        ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    10 */ &BswM_ExpFct_ESH_LE_InitToWakeup_RDR_08                                                                                                       ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    11 */ &BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_08                                                                                               ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    12 */ &BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_08                                                                                                      ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    13 */ &BswM_ExpFct_ESH_LE_PostRunReleased_RDR_08                                                                                                    ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    14 */ &BswM_ExpFct_ESH_LE_PostRunToRun_RDR_08                                                                                                       ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    15 */ &BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_08                                                                                                ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    16 */ &BswM_ExpFct_ESH_LE_RunRequested_RDR_08                                                                                                       ,  /* [LE_ESH_LE_RunRequested] */
  /*    17 */ &BswM_ExpFct_ESH_LE_PostRun_RDR_08                                                                                                            ,  /* [LE_ESH_LE_PostRun] */
  /*    18 */ &BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_08                                                                                           ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    19 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_08                                                                ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    20 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_08                                       ,  /* [LE_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested] */
  /*    21 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_08 ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    22 */ &BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_08                                                       ,  /* [LE_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    23 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_08  ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable] */
  /*    24 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_08                                                                   ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    25 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_08                                        ,  /* [LE_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested] */
  /*    26 */ &BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_08                                                                    ,  /* [LE_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    27 */ &BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_08                                    ,  /* [LE_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested] */
  /*    28 */ &BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_08                                                        ,  /* [LE_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable] */
  /*    29 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_08                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_TX] */
  /*    30 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_08                                                                                        ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*    31 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM_RDR_08                                                                                        ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*    32 */ &BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_08                                                                                           ,  /* [LE_CC_LE_CN_VCAN_RADAR_489180b6_RX] */
  /*    33 */ &BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_08                                                                                           ,  /* [LE_CC_LE_CN_PCAN_RADAR_458ff0f1_RX] */
  /*    34 */ &BswM_ExpFct_ESH_LE_CancelNotPending_RDR_08                                                                                                   ,  /* [LE_ESH_LE_CancelNotPending] */
  /*    35 */ &BswM_ExpFct_LE_AckModeTransition_Execute_RDR_08                                                                                              ,  /* [LE_LE_AckModeTransition_Execute] */
  /*    36 */ &BswM_ExpFct_LE_EcuSoftReset_RDR_08                                                                                                              /* [LE_LE_EcuSoftReset] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericModeParameters
**********************************************************************************************************************/
/** 
  \var    BswM_GenericModeParameters
  \details
  Element    Description
  Mode   
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_GenericModeParametersType, BSWM_CONST) BswM_GenericModeParameters[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Mode                                                 Referable Keys */
  { /*     0 */ BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN      },  /* [A_ESH_Action_ESH_PostRun] */
  { /*     1 */ BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN },  /* [A_ESH_Action_ESH_PrepShutdown] */
  { /*     2 */ BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP        },  /* [A_ESH_Action_ESH_Wakeup] */
  { /*     3 */ BSWM_GENERICVALUE_ESH_State_ESH_RUN           },  /* [A_ESH_Action_ESH_Run] */
  { /*     4 */ BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM  }   /* [A_ESH_Action_ESH_WaitForNvm] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  OnInit              Arbitrate depending rules on initialization.
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    OnInit  RulesIndEndIdx  RulesIndStartIdx        Comment                                                       Referable Keys */
  { /*     0 */  FALSE,             3u,               0u },  /* [Name: CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  { /*     1 */  FALSE,             5u,               3u },  /* [Name: CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  { /*     2 */   TRUE,            12u,               5u }   /* [Name: ESH_State]                                 */  /* [MRP_ESH_State, GENERIC_0] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitGenVarAndInitAL
**********************************************************************************************************************/
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitGenVarAndInitAL                             */
  /*     0 */ &BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeNotificationFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_ModeNotificationFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ModeNotificationFct                             */
  /*     0 */ &BswM_ModeNotificationFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    BswM_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ BSWM_SINGLEPARTITION,                   0u }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element                Description
  ActionListsFalseIdx    the index of the 0:1 relation pointing to BswM_ActionLists
  ActionListsTrueIdx     the index of the 0:1 relation pointing to BswM_ActionLists
  ExpressionsIdx         the index of the 1:1 relation pointing to BswM_Expressions
  Id                     External id of rule.
  RuleStatesIdx          the index of the 1:1 relation pointing to BswM_RuleStates
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[26] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActionListsFalseIdx                 ActionListsTrueIdx  ExpressionsIdx  Id   RuleStatesIdx        Referable Keys */
  { /*     0 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 0u,            35u,  0u,            0u },  /* [R_BswMRule_AckModeTransition_Execute, MRP_BswMModeRequestPort_DCMECUReset] */
  { /*     1 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 1u,            36u,  1u,            1u },  /* [R_BswMRule_EcuSoftReset, MRP_BswMModeRequestPort_DCMECUReset] */
  { /*     2 */                                 4u,                 5u,            33u,  2u,            2u },  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  { /*     3 */                                 2u,                 3u,            31u,  3u,            3u },  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  { /*     4 */                                 6u,                 7u,            29u,  4u,            4u },  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  { /*     5 */                                10u,                11u,            32u,  5u,            5u },  /* [R_CC_CN_VCAN_RADAR_489180b6_RX, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  { /*     6 */                                 8u,                 9u,            30u,  6u,            6u },  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  { /*     7 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                14u,            10u,  7u,            7u },  /* [R_ESH_InitToWakeup, MRP_ESH_State] */
  { /*     8 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                13u,            17u,  8u,            8u },  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_SelfRunRequestTimer] */
  { /*     9 */                                12u,                16u,            14u,  9u,            9u },  /* [R_ESH_PostRunNested] */
  { /*    10 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                15u,            11u, 10u,           10u },  /* [R_ESH_PostRunToPrepNested] */
  { /*    11 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                17u,            18u, 11u,           11u },  /* [R_ESH_PrepToWait, MRP_ESH_State] */
  { /*    12 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                18u,             0u, 12u,           12u },  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_SelfRunRequestTimer] */
  { /*    13 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                19u,             7u, 13u,           13u },  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*    14 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                20u,             6u, 14u,           14u },  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_NvMIndication, MRP_ESH_NvM_CancelWriteAllTimer, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ComMIndication_RDR_EthConnector1_de653f65, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*    15 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                21u,             9u, 15u,           15u },  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_NvMIndication, MRP_ESH_NvM_CancelWriteAllTimer] */
  { /*    16 */                                23u,                28u,            22u, 16u,           16u },  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, MRP_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  { /*    17 */                                24u,                29u,            21u, 17u,           17u },  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, MRP_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  { /*    18 */                                25u,                30u,            19u, 18u,           18u },  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f, MRP_SDC_S_provService_RDR_1_Detections_89f78c9f] */
  { /*    19 */                                26u,                31u,            24u, 19u,           19u },  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9, MRP_SDC_S_provService_RDR_1_SW_Info_c2745ec9] */
  { /*    20 */                                27u,                32u,            26u, 20u,           20u },  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01, MRP_SDC_S_provService_RDR_1_Status_d2069d01] */
  { /*    21 */                                36u,                33u,            28u, 21u,           21u },  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  { /*    22 */                                35u,                34u,            23u, 22u,           22u },  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  { /*    23 */                                37u,                40u,            27u, 23u,           23u },  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  { /*    24 */                                38u,                41u,            20u, 24u,           24u },  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  { /*    25 */                                39u,                42u,            25u, 25u,           25u }   /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RulesInd      Referable Keys */
  /*     0 */        2u,  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */        3u,  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     2 */        4u,  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     3 */        5u,  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /*     4 */        6u,  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /*     5 */        7u,  /* [MRP_ESH_State] */
  /*     6 */        8u,  /* [MRP_ESH_State] */
  /*     7 */       11u,  /* [MRP_ESH_State] */
  /*     8 */       12u,  /* [MRP_ESH_State] */
  /*     9 */       13u,  /* [MRP_ESH_State] */
  /*    10 */       14u,  /* [MRP_ESH_State] */
  /*    11 */       15u   /* [MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdClientParameters
**********************************************************************************************************************/
/** 
  \var    BswM_SdClientParameters
  \details
  Element    Description
  State  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_SdClientParametersType, BSWM_CONST) BswM_SdClientParameters[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    State                                   Referable Keys */
  { /*     0 */ BSWM_SD_CLIENT_SERVICE_RELEASED  },  /* [A_SDC_SdClientServiceModeRequetst_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RELEASED] */
  { /*     1 */ BSWM_SD_CLIENT_SERVICE_REQUESTED }   /* [A_SDC_SdClientServiceModeRequest_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BSWM_SD_CLIENT_SERVICE_REQUESTED] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdConsumedParameters
**********************************************************************************************************************/
/** 
  \var    BswM_SdConsumedParameters
  \details
  Element    Description
  State  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_SdConsumedParametersType, BSWM_CONST) BswM_SdConsumedParameters[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    State                                        Referable Keys */
  { /*     0 */ BSWM_SD_CONSUMED_EVENTGROUP_RELEASED  },  /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_84c0fea4] */
  { /*     1 */ BSWM_SD_CONSUMED_EVENTGROUP_REQUESTED }   /* [A_SDC_SdCEGModeRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79_862c6c58] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdEventHandlerMapping
**********************************************************************************************************************/
/** 
  \var    BswM_SdEventHandlerMapping
  \brief  Maps the external id of BswMSdEventHandlerCurrentState to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMSdEventHandlerCurrentState.
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_SdEventHandlerMappingType, BSWM_CONST) BswM_SdEventHandlerMapping[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                             Referable Keys */
  { /*     0 */ SdConf_SdEventHandler_EventGroup_RDR_1_653e2581 },  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  { /*     1 */ SdConf_SdEventHandler_EventGroup_RDR_1_ca62382d },  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  { /*     2 */ SdConf_SdEventHandler_EventGroup_RDR_1_f7c73cae }   /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdServerParameters
**********************************************************************************************************************/
/** 
  \var    BswM_SdServerParameters
  \details
  Element    Description
  State  
  Id     
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_SdServerParametersType, BSWM_CONST) BswM_SdServerParameters[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    State                             Id                                                                  Referable Keys */
  { /*     0 */ BSWM_SD_SERVER_SERVICE_DOWN     , SdConf_SdServerService_provService_RDR_1_Detections_89f78c9f },  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_DOWN] */
  { /*     1 */ BSWM_SD_SERVER_SERVICE_AVAILABLE, SdConf_SdServerService_provService_RDR_1_Detections_89f78c9f },  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Detections_89f78c9f_BSWM_SD_SERVER_SERVICE_AVAILABLE] */
  { /*     2 */ BSWM_SD_SERVER_SERVICE_DOWN     , SdConf_SdServerService_provService_RDR_1_SW_Info_c2745ec9    },  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_DOWN] */
  { /*     3 */ BSWM_SD_SERVER_SERVICE_AVAILABLE, SdConf_SdServerService_provService_RDR_1_SW_Info_c2745ec9    },  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_SW_Info_c2745ec9_BSWM_SD_SERVER_SERVICE_AVAILABLE] */
  { /*     4 */ BSWM_SD_SERVER_SERVICE_DOWN     , SdConf_SdServerService_provService_RDR_1_Status_d2069d01     },  /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_DOWN] */
  { /*     5 */ BSWM_SD_SERVER_SERVICE_AVAILABLE, SdConf_SdServerService_provService_RDR_1_Status_d2069d01     }   /* [A_SDC_SdServerServiceModeRequest_provService_RDR_1_Status_d2069d01_BSWM_SD_SERVER_SERVICE_AVAILABLE] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SwcModeRequestUpdateFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_SwcModeRequestUpdateFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SwcModeRequestUpdateFct                             */
  /*     0 */ &BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_01
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_01[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_01     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_01 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_01       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_01       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_01 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_02
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_02[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_02     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_02 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_02       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_02       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_02 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_03
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_03[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_03     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_03 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_03       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_03       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_03 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_04
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_04[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_04     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_04 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_04       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_04       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_04 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_05
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_05[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_05     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_05 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_05       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_05       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_05 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_06
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_06[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_06     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_06 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_06       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_06       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_06 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_07
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_07[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_07     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_07 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_07       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_07       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_07 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRDR_08
  \details
  Element    Description
  Value  
  Timer  
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRDR_08[5] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Value  Timer                                              Referable Keys */
  { /*     0 */ 10u  , BSWM_TMR_ESH_SelfRunRequestTimer_RDR_08     },  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  { /*     1 */ 0u   , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_08 },  /* [A_ESH_Action_CancelWriteAllTimer_Stop] */
  { /*     2 */ 200u , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_08       },  /* [A_ESH_Action_WriteAllTimer_Start] */
  { /*     3 */ 0u   , BSWM_TMR_ESH_NvM_WriteAllTimer_RDR_08       },  /* [A_ESH_Action_WriteAllTimer_Stop] */
  { /*     4 */ 200u , BSWM_TMR_ESH_NvM_CancelWriteAllTimer_RDR_08 }   /* [A_ESH_Action_CancelWriteAllTimer_Start] */
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ActionListQueueUType, BSWM_VAR_CLEARED) BswM_ActionListQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [AL_AL_AckModeTransition_Execute] */
  /*     1 */  /* [AL_AL_EcuSoftReset] */
  /*     2 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Disable_DM] */
  /*     3 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_Enable_DM] */
  /*     4 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Disable] */
  /*     5 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_RX_Enable] */
  /*     6 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Disable] */
  /*     7 */  /* [AL_CC_AL_CN_PCAN_RADAR_458ff0f1_TX_Enable] */
  /*     8 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Disable_DM] */
  /*     9 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_Enable_DM] */
  /*    10 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Disable] */
  /*    11 */  /* [AL_CC_AL_CN_VCAN_RADAR_489180b6_RX_Enable] */
  /*    12 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    15 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    16 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    17 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    18 */  /* [AL_ESH_AL_RunToPostRun] */
  /*    19 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*    20 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*    21 */  /* [AL_ESH_AL_WakeupToRun] */
  /*    22 */  /* [AL_INIT_AL_Initialize] */
  /*    23 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    24 */  /* [AL_SDC_AL_ApplRelease_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    25 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Detections_89f78c9f] */
  /*    26 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    27 */  /* [AL_SDC_AL_ApplRelease_S_provService_RDR_1_Status_d2069d01] */
  /*    28 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    29 */  /* [AL_SDC_AL_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    30 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    31 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    32 */  /* [AL_SDC_AL_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    33 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_AVAILABLE] */
  /*    34 */  /* [AL_SDC_AL_SdAvailable_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da_028f42eb] */
  /*    35 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_DOWN] */
  /*    36 */  /* [AL_SDC_AL_SdDown_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_DOWN] */
  /*    37 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    38 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    39 */  /* [AL_SDC_AL_SdRelease_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /*    40 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    41 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    42 */  /* [AL_SDC_AL_SdRequest_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store the current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_CLEARED) BswM_CanSMChannelState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelState
  \brief  Variable to store the current mode of BswMComMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ModeType, BSWM_VAR_CLEARED) BswM_ComMChannelState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ComMIndication_RDR_EthConnector1_de653f65] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_CLEARED) BswM_ForcedActionListPriority;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store the current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_CLEARED) BswM_GenericState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_CLEARED) BswM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_CLEARED) BswM_ModeRequestQueue[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_PCAN_RADAR_458ff0f1, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_VCAN_RADAR_489180b6, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_ESH_State, GENERIC_0] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NvMJobState
**********************************************************************************************************************/
/** 
  \var    BswM_NvMJobState
  \brief  Variable to store the current mode of BswMNvMJobModeIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(NvM_RequestResultType, BSWM_VAR_CLEARED) BswM_NvMJobState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueSemaphoreType, BSWM_VAR_CLEARED) BswM_QueueSemaphore;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueWrittenType, BSWM_VAR_CLEARED) BswM_QueueWritten;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_RuleStatesUType, BSWM_VAR_CLEARED) BswM_RuleStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [R_BswMRule_AckModeTransition_Execute] */
  /*     1 */  /* [R_BswMRule_EcuSoftReset] */
  /*     2 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX] */
  /*     3 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_RX_DM] */
  /*     4 */  /* [R_CC_CN_PCAN_RADAR_458ff0f1_TX] */
  /*     5 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX] */
  /*     6 */  /* [R_CC_CN_VCAN_RADAR_489180b6_RX_DM] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRun] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRunToPrepNested] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_ESH_RunToPostRun] */
  /*    13 */  /* [R_ESH_WaitToWakeup] */
  /*    14 */  /* [R_ESH_WakeupToPrep] */
  /*    15 */  /* [R_ESH_WakeupToRun] */
  /*    16 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    17 */  /* [R_SDC_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    18 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Detections_89f78c9f] */
  /*    19 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9] */
  /*    20 */  /* [R_SDC_ApplRequest_S_provService_RDR_1_Status_d2069d01] */
  /*    21 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /*    22 */  /* [R_SDC_SdStateChange_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /*    23 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*    24 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*    25 */  /* [R_SDC_SdStateChange_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdClientServiceState
**********************************************************************************************************************/
/** 
  \var    BswM_SdClientServiceState
  \brief  Variable to store the current mode of BswMSdClientServiceCurrentState mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_ClientServiceCurrentStateType, BSWM_VAR_CLEARED) BswM_SdClientServiceState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [SD_CLIENT_0, MRP_SDC_SdClientState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdConsumedEventState
**********************************************************************************************************************/
/** 
  \var    BswM_SdConsumedEventState
  \brief  Variable to store the current mode of BswMSdConsumedEventGroupCurrentState mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_ConsumedEventGroupCurrentStateType, BSWM_VAR_CLEARED) BswM_SdConsumedEventState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [SD_CONSUMED_0, MRP_SDC_SdCEGState_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SdEventHandlerState
**********************************************************************************************************************/
/** 
  \var    BswM_SdEventHandlerState
  \brief  Variable to store the current mode of BswMSdEventHandlerCurrentState mode request ports.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_EventHandlerCurrentStateType, BSWM_VAR_CLEARED) BswM_SdEventHandlerState[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [SD_EVENT_0, MRP_SDC_SdEHState_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [SD_EVENT_1, MRP_SDC_SdEHState_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d] */
  /*     2 */  /* [SD_EVENT_2, MRP_SDC_SdEHState_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerStateUType, BSWM_VAR_CLEARED) BswM_TimerState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerValueUType, BSWM_VAR_CLEARED) BswM_TimerValue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCConfig
**********************************************************************************************************************/
/** 
  \var    BswM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCConfigsType, BSWM_CONST) BswM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_01] */
      BswM_PCPartitionConfigRDR_01  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_01 */
  },
  { /* Index: 1 Keys: [Config_RDR_02] */
      BswM_PCPartitionConfigRDR_02  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_02 */
  },
  { /* Index: 2 Keys: [Config_RDR_03] */
      BswM_PCPartitionConfigRDR_03  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_03 */
  },
  { /* Index: 3 Keys: [Config_RDR_04] */
      BswM_PCPartitionConfigRDR_04  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_04 */
  },
  { /* Index: 4 Keys: [Config_RDR_05] */
      BswM_PCPartitionConfigRDR_05  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_05 */
  },
  { /* Index: 5 Keys: [Config_RDR_06] */
      BswM_PCPartitionConfigRDR_06  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_06 */
  },
  { /* Index: 6 Keys: [Config_RDR_07] */
      BswM_PCPartitionConfigRDR_07  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_07 */
  },
  { /* Index: 7 Keys: [Config_RDR_08] */
      BswM_PCPartitionConfigRDR_08  /**< the pointer to BswM_PCPartitionConfig in Config_RDR_08 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_01
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_01[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_01                         /**< the pointer to BswM_ActionItems in Config_RDR_01 */
    , BswM_ActionsRDR_01                             /**< the pointer to BswM_Actions in Config_RDR_01 */
    , BswM_ComDMHandlingDisableParametersRDR_01      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_01 */
    , BswM_ComDMHandlingEnableParametersRDR_01       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_01 */
    , BswM_ComPduGroupHandlingParametersRDR_01       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_01 */
    , BswM_ComPduGroupHandlingStartParametersRDR_01  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_01 */
    , BswM_ComPduGroupHandlingStopParametersRDR_01   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_01 */
    , BswM_ExpressionsRDR_01                         /**< the pointer to BswM_Expressions in Config_RDR_01 */
    , BswM_TimerControlParametersRDR_01              /**< the pointer to BswM_TimerControlParameters in Config_RDR_01 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_02
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_02[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_01                         /**< the pointer to BswM_ActionItems in Config_RDR_02 */
    , BswM_ActionsRDR_02                             /**< the pointer to BswM_Actions in Config_RDR_02 */
    , BswM_ComDMHandlingDisableParametersRDR_02      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_02 */
    , BswM_ComDMHandlingEnableParametersRDR_02       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_02 */
    , BswM_ComPduGroupHandlingParametersRDR_01       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_02 */
    , BswM_ComPduGroupHandlingStartParametersRDR_02  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_02 */
    , BswM_ComPduGroupHandlingStopParametersRDR_02   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_02 */
    , BswM_ExpressionsRDR_02                         /**< the pointer to BswM_Expressions in Config_RDR_02 */
    , BswM_TimerControlParametersRDR_02              /**< the pointer to BswM_TimerControlParameters in Config_RDR_02 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_03
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_03[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_01                         /**< the pointer to BswM_ActionItems in Config_RDR_03 */
    , BswM_ActionsRDR_03                             /**< the pointer to BswM_Actions in Config_RDR_03 */
    , BswM_ComDMHandlingDisableParametersRDR_03      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_03 */
    , BswM_ComDMHandlingEnableParametersRDR_03       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_03 */
    , BswM_ComPduGroupHandlingParametersRDR_01       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_03 */
    , BswM_ComPduGroupHandlingStartParametersRDR_03  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_03 */
    , BswM_ComPduGroupHandlingStopParametersRDR_03   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_03 */
    , BswM_ExpressionsRDR_03                         /**< the pointer to BswM_Expressions in Config_RDR_03 */
    , BswM_TimerControlParametersRDR_03              /**< the pointer to BswM_TimerControlParameters in Config_RDR_03 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_04
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_04[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_01                         /**< the pointer to BswM_ActionItems in Config_RDR_04 */
    , BswM_ActionsRDR_04                             /**< the pointer to BswM_Actions in Config_RDR_04 */
    , BswM_ComDMHandlingDisableParametersRDR_04      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_04 */
    , BswM_ComDMHandlingEnableParametersRDR_04       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_04 */
    , BswM_ComPduGroupHandlingParametersRDR_01       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_04 */
    , BswM_ComPduGroupHandlingStartParametersRDR_04  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_04 */
    , BswM_ComPduGroupHandlingStopParametersRDR_04   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_04 */
    , BswM_ExpressionsRDR_04                         /**< the pointer to BswM_Expressions in Config_RDR_04 */
    , BswM_TimerControlParametersRDR_04              /**< the pointer to BswM_TimerControlParameters in Config_RDR_04 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_05
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_05[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_05                         /**< the pointer to BswM_ActionItems in Config_RDR_05 */
    , BswM_ActionsRDR_05                             /**< the pointer to BswM_Actions in Config_RDR_05 */
    , BswM_ComDMHandlingDisableParametersRDR_05      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_05 */
    , BswM_ComDMHandlingEnableParametersRDR_05       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_05 */
    , BswM_ComPduGroupHandlingParametersRDR_05       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_05 */
    , BswM_ComPduGroupHandlingStartParametersRDR_05  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_05 */
    , BswM_ComPduGroupHandlingStopParametersRDR_05   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_05 */
    , BswM_ExpressionsRDR_05                         /**< the pointer to BswM_Expressions in Config_RDR_05 */
    , BswM_TimerControlParametersRDR_05              /**< the pointer to BswM_TimerControlParameters in Config_RDR_05 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_06
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_06[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_01                         /**< the pointer to BswM_ActionItems in Config_RDR_06 */
    , BswM_ActionsRDR_06                             /**< the pointer to BswM_Actions in Config_RDR_06 */
    , BswM_ComDMHandlingDisableParametersRDR_06      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_06 */
    , BswM_ComDMHandlingEnableParametersRDR_06       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_06 */
    , BswM_ComPduGroupHandlingParametersRDR_01       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_06 */
    , BswM_ComPduGroupHandlingStartParametersRDR_06  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_06 */
    , BswM_ComPduGroupHandlingStopParametersRDR_06   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_06 */
    , BswM_ExpressionsRDR_06                         /**< the pointer to BswM_Expressions in Config_RDR_06 */
    , BswM_TimerControlParametersRDR_06              /**< the pointer to BswM_TimerControlParameters in Config_RDR_06 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_07
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_07[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_05                         /**< the pointer to BswM_ActionItems in Config_RDR_07 */
    , BswM_ActionsRDR_07                             /**< the pointer to BswM_Actions in Config_RDR_07 */
    , BswM_ComDMHandlingDisableParametersRDR_07      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_07 */
    , BswM_ComDMHandlingEnableParametersRDR_07       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_07 */
    , BswM_ComPduGroupHandlingParametersRDR_05       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_07 */
    , BswM_ComPduGroupHandlingStartParametersRDR_07  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_07 */
    , BswM_ComPduGroupHandlingStopParametersRDR_07   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_07 */
    , BswM_ExpressionsRDR_07                         /**< the pointer to BswM_Expressions in Config_RDR_07 */
    , BswM_TimerControlParametersRDR_07              /**< the pointer to BswM_TimerControlParameters in Config_RDR_07 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRDR_08
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  Actions                               the pointer to BswM_Actions
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComPduGroupHandlingParameters         the pointer to BswM_ComPduGroupHandlingParameters
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  Expressions                           the pointer to BswM_Expressions
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRDR_08[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRDR_05                         /**< the pointer to BswM_ActionItems in Config_RDR_08 */
    , BswM_ActionsRDR_08                             /**< the pointer to BswM_Actions in Config_RDR_08 */
    , BswM_ComDMHandlingDisableParametersRDR_08      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_RDR_08 */
    , BswM_ComDMHandlingEnableParametersRDR_08       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_RDR_08 */
    , BswM_ComPduGroupHandlingParametersRDR_05       /**< the pointer to BswM_ComPduGroupHandlingParameters in Config_RDR_08 */
    , BswM_ComPduGroupHandlingStartParametersRDR_08  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_RDR_08 */
    , BswM_ComPduGroupHandlingStopParametersRDR_08   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_RDR_08 */
    , BswM_ExpressionsRDR_08                         /**< the pointer to BswM_Expressions in Config_RDR_08 */
    , BswM_TimerControlParametersRDR_08              /**< the pointer to BswM_TimerControlParameters in Config_RDR_08 */
  }
};
#define BSWM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */

#define BSWM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

VAR(Rte_ModeType_SDC_SdEventHandlerState, BSWM_VAR_CLEARED) BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState;

VAR(Rte_ModeType_SDC_SdConsumedEventGroupState, BSWM_VAR_CLEARED) BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState;

VAR(Rte_ModeType_SDC_SdEventHandlerState, BSWM_VAR_CLEARED) BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState;

VAR(Rte_ModeType_SDC_SdEventHandlerState, BSWM_VAR_CLEARED) BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState;

VAR(Rte_ModeType_SDC_SdClientServiceState, BSWM_VAR_CLEARED) BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState;


VAR(BswM_ESH_RunRequest, BSWM_VAR_CLEARED) Request_ESH_RunRequest_0_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_CLEARED) Request_ESH_RunRequest_1_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_CLEARED) Request_ESH_PostRunRequest_0_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_CLEARED) Request_ESH_PostRunRequest_1_requestedMode;
VAR(BswM_SDC_SdServerServiceRequest, BSWM_VAR_CLEARED) Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode;
VAR(BswM_SDC_SdConsumedEventGroupRequest, BSWM_VAR_CLEARED) Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode;
VAR(BswM_SDC_SdClientServiceRequest, BSWM_VAR_CLEARED) Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode;
VAR(BswM_SDC_SdServerServiceRequest, BSWM_VAR_CLEARED) Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode;
VAR(BswM_SDC_SdServerServiceRequest, BSWM_VAR_CLEARED) Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode;
VAR(Rte_ModeType_DcmEcuReset, BSWM_VAR_CLEARED) BswM_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset;




VAR(boolean, BSWM_VAR_CLEARED) BswM_PreInitialized;
#define BSWM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


#define BSWM_START_SEC_CODE_ASIL_D
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType actionListIndex;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if ( BSWM_DEV_ERROR_DETECT == STD_ON )
  if (handleId < BswM_GetSizeOfRules(partitionIdx))
#endif
  {
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    actionListIndex = BswM_ArbitrateRule(handleId, partitionIdx);
    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(actionListIndex < BswM_GetSizeOfActionLists(partitionIdx))
    {
      retVal = BswM_Action_ActionListHandler(actionListIndex, partitionIdx);
    }
    else
    {
      retVal = E_OK;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}


/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                              BswM_SizeOfTimerValueType timerId,
                                                              BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue(partitionIdx))
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value, partitionIdx); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED), partitionIdx); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
*/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  uint16 uIndex;

  BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = 0xFFu;
  BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = 0xFFu;
  BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = 0xFFu;
  BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = 0xFFu;
  BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = 0xFFu;
  Request_ESH_RunRequest_0_requestedMode = RELEASED;
  Request_ESH_RunRequest_1_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_0_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_1_requestedMode = RELEASED;
  Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode = SDC_SERVER_DOWN;
  Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode = SDC_CEG_RELEASED;
  Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode = SDC_CLIENT_RELEASED;
  Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode = SDC_SERVER_DOWN;
  Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode = SDC_SERVER_DOWN;
  BswM_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset = RTE_MODE_DcmEcuReset_NONE;

  for(uIndex = 0u; uIndex < BswM_GetSizeOfInitActionLists(partitionIdx); uIndex++) /* COV_BSWM_INITACTIONLISTS XF */ /* PRQA S 2877 */ /* MD_BSWM_2877 */ 
  {
    (void)BswM_Action_ActionListHandler((BswM_HandleType)BswM_GetInitActionLists(uIndex, partitionIdx), partitionIdx);
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/
/* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void)
{
  if(BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState != 0xFFu)
  {
    if(Rte_Switch_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState(BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState) == RTE_E_OK)
    {
      BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = 0xFFu;
    }
  }
  if(BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState != 0xFFu)
  {
    if(Rte_Switch_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState(BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState) == RTE_E_OK)
    {
      BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = 0xFFu;
    }
  }
  if(BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState != 0xFFu)
  {
    if(Rte_Switch_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState(BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState) == RTE_E_OK)
    {
      BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = 0xFFu;
    }
  }
  if(BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState != 0xFFu)
  {
    if(Rte_Switch_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState(BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState) == RTE_E_OK)
    {
      BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = 0xFFu;
    }
  }
  if(BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState != 0xFFu)
  {
    if(Rte_Switch_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState(BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState) == RTE_E_OK)
    {
      BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = 0xFFu;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
*/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset();
  if (mode != RTE_TRANSITION_DcmEcuReset)
  {
    BswM_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset = (Rte_ModeType_DcmEcuReset)mode;
  }
  (void)Rte_Read_Request_ESH_RunRequest_0_requestedMode(&Request_ESH_RunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_RunRequest_1_requestedMode(&Request_ESH_RunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(&Request_ESH_PostRunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(&Request_ESH_PostRunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode(&Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode(&Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode(&Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode(&Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode(&Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode); /* SBSW_BSWM_RTE_READ */
}

/**********************************************************************************************************************
 *  BswMActionFunctions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
*/

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_GenericMode
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_GenericMode(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BswM_RequestMode(BswM_GetUserOfGenericModeParameters(handleId, partitionIdx), BswM_GetModeOfGenericModeParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_TimerControl
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_TimerControl(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BswM_UpdateTimer(partitionIdx, BswM_GetTimerOfTimerControlParameters(handleId, partitionIdx), BswM_GetValueOfTimerControlParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_SoAd_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SoAd_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SoAd_Init(SoAd_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Com_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Com_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

/* Commented out via Post Gen script for (CAN/SomeIP)Variant specific changes*/
//  User_Com_Init();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_PduR_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_PduR_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  PduR_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_EthSM_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EthSM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EthSM_Init(EthSM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_TcpIp_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_TcpIp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  TcpIp_Init(TcpIp_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_EnableInterrupts_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EnableInterrupts_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_AL_SetProgrammableInterrupts();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_ComM_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_Init(ComM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_ComM_PostInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Rte_Start_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Rte_Start_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Rte_Start();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_SoAd_PostInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SoAd_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SoAd_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanIf_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanIf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
/* Commented out via Post Gen script for (CAN/SomeIP)Variant specific changes*/
//  CanIf_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanIf_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanSM_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanSM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
/* Commented out via Post Gen script for (CAN/SomeIP)Variant specific changes*/
//  CanSM_Init(CanSM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComMAllowCom
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComMAllowCom(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ComM_CommunicationAllowed(BswM_GetChannelOfComMAllowComParameters(handleId, partitionIdx), BswM_GetAllowedOfComMAllowComParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ETH_ComM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  Eth_ComM_Init();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPrepShutdown_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterPrepShutdown();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterWakeup_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWakeup_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterWakeup();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterRun_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterRun_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterRun();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterShutdown_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterShutdown_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterShutdown();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWaitForNvm_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterWaitForNvm();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterPostRun_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPostRun_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterPostRun();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_TcpIpXcp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  TcpIpXcp_Init(NULL_PTR);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Xcp_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Xcp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Xcp_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_StbM_PreInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  StbM_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_StbM_PreInit);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_EthTSyn_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EthTSyn_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EthTSyn_Init(EthTSyn_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_StbM_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  StbM_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_StbM_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_StbM_PostInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  StbM_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_BswMUserCallout_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMUserCallout_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PreInit(ComM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Can_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Can_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
/* Commented out via Post Gen script for (CAN/SomeIP)Variant specific changes*/
//  Can_Init(&Can_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComMModeSwitch
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComMModeSwitch(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return ComM_RequestComMode(BswM_GetUserOfComMModeSwitchParameters(handleId, partitionIdx), BswM_GetComModeOfComMModeSwitchParameters(handleId, partitionIdx));
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Fee_30_FlexNor_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Fee_30_FlexNor_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_NvM_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_NvM_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_NvMReadAll_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_NvMReadAll_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_INIT_NvMReadAll();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_User_CAN_ComPduGroupHandling_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_User_CAN_ComPduGroupHandling_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

/* Commented out via Post Gen script for (CAN/SomeIP)Variant specific changes*/
//  User_CAN_ComPduGroupHandling();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SdServer
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SdServer(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return Sd_ServerServiceSetState(BswM_GetIdOfSdServerParameters(handleId, partitionIdx), BswM_GetStateOfSdServerParameters(handleId, partitionIdx));
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_RELEASED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_SDC_SdEventHandlerState_SDC_EH_RELEASED;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_SDC_EH_REQUESTED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_SDC_SdEventHandlerState_SDC_EH_REQUESTED;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SdConsumed
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SdConsumed(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return Sd_ConsumedEventGroupSetState(BswM_GetIdOfSdConsumedParameters(handleId, partitionIdx), BswM_GetStateOfSdConsumedParameters(handleId, partitionIdx));
}

/**********************************************************************************************************************
 *  BswM_Action_SdClient
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SdClient(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return Sd_ClientServiceSetState(BswM_GetIdOfSdClientParameters(handleId, partitionIdx), BswM_GetStateOfSdClientParameters(handleId, partitionIdx));
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_DOWN_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = RTE_MODE_SDC_SdConsumedEventGroupState_SDC_CEG_DOWN;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_SDC_CEG_0469f0b9_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = RTE_MODE_SDC_SdConsumedEventGroupState_SDC_CEG_AVAILABLE;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_RELEASED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_SDC_SdEventHandlerState_SDC_EH_RELEASED;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_SDC_EH_REQUESTED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_SDC_SdEventHandlerState_SDC_EH_REQUESTED;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_RELEASED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_SDC_SdEventHandlerState_SDC_EH_RELEASED;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_SDC_EH_REQUESTED_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_SDC_SdEventHandlerState_SDC_EH_REQUESTED;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_DOWN_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = RTE_MODE_SDC_SdClientServiceState_SDC_CLIENT_DOWN;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_SDC_CLIENT_AVAILABLE_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = RTE_MODE_SDC_SdClientServiceState_SDC_CLIENT_AVAILABLE;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Sd_PreInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Sd_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Sd_PreInit(Sd_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Sd_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Sd_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Sd_Init(Sd_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Sd_PostInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Sd_PostInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Sd_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_LdCom_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_LdCom_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  LdCom_Init(LdCom_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SomeIpTp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SomeIpTp_Init(SomeIpTp_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanXcp_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanXcp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
/* Commented out via Post Gen script for (CAN/SomeIP)Variant specific changes*/
//  CanXcp_Init(NULL_PTR);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTSyn_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanTSyn_PreInit);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTSyn_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTSyn_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanTSyn_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CryIf_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CryIf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CryIf_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Crypto_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Crypto_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Crypto_182_iND13400_Init(NULL_PTR);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Csm_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Csm_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Csm_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComPduGroupHandling
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComPduGroupHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BswM_SizeOfComPduGroupHandlingStartParametersType idxStart;

  BswM_SizeOfComPduGroupHandlingStopParametersType idxStop;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  for(idxStart = BswM_GetComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStart < BswM_GetComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStart++) /* FETA_BSWM_CSL_USE_CASE */
  {
    (void)Com_IpduGroupStart(BswM_GetIpduGroupIdOfComPduGroupHandlingStartParameters(idxStart, partitionIdx), BswM_GetInitializeOfComPduGroupHandlingStartParameters(idxStart, partitionIdx));
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  for(idxStop = BswM_GetComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStop < BswM_GetComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStop++) /* FETA_BSWM_CSL_USE_CASE */
  {
    (void)Com_IpduGroupStop(BswM_GetIpduGroupIdOfComPduGroupHandlingStopParameters(idxStop, partitionIdx));
  }
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComDMHandling
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComDMHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BswM_SizeOfComDMHandlingEnableParametersType idxEnable;

  BswM_SizeOfComDMHandlingDisableParametersType idxDisable;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  for(idxEnable = BswM_GetComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(handleId, partitionIdx); idxEnable < BswM_GetComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters(handleId, partitionIdx); idxEnable++) /* FETA_BSWM_CSL_USE_CASE */
  {
    (void)Com_EnableReceptionDM(BswM_GetIpduGroupIdOfComDMHandlingEnableParameters(idxEnable, partitionIdx));
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  for(idxDisable = BswM_GetComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(handleId, partitionIdx); idxDisable < BswM_GetComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters(handleId, partitionIdx); idxDisable++) /* FETA_BSWM_CSL_USE_CASE */
  {
    (void)Com_DisableReceptionDM(BswM_GetIpduGroupIdOfComDMHandlingDisableParameters(idxDisable, partitionIdx));
  }
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanSM_PreInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanSM_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanSM_PreInit(CanSM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_NvMWriteAll_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_NvMWriteAll_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_WriteAll();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_CancelNvMWriteAll_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_CancelWriteAll();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTp_PreInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTp_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTp_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanTp_PreInit);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTp_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTp_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTp_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanTp_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Dcm_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dcm_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dcm_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Dcm_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Action_AckModeTransition_Execute_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_AckModeTransition_Execute_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  UserCalloutFunc_AckModeTransition_Execute();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Action_EcuSoftReset_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_EcuSoftReset_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  Ecu_PerformSoftReset();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Det_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Det_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  UserCallout_Det_Init();;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Dem_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dem_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Dem_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Init_Action_Dem_PreInit_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Init_Action_Dem_PreInit_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_Dem_PreInit);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_E2EXf_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_E2EXf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  E2EXf_Init(NULL_PTR);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_SetOperationCycle_UserCallOut_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_SetOperationCycle_UserCallOut_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_Power_On_Off , DEM_CYCLE_STATE_START);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Ipdu_Mode_PCAN_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Ipdu_Mode_PCAN_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  Ipdu_Mode();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Action_User_EthIf_Init_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_User_EthIf_Init_RDR_01(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  User_EthIf_Init();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswMExpressionFunctions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
*/

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_01(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_01(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunReached_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReached_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_RUN) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_01(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_01(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunReleased_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReleased_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((Request_ESH_RunRequest_0_requestedMode == RELEASED) && (Request_ESH_RunRequest_1_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoWakeup_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetComMChannelState(0, 0u) == COMM_NO_COMMUNICATION) && (EcuM_GetValidatedWakeupEvents() == 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_01(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((EcuM_GetValidatedWakeupEvents() != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_InitToWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_INIT) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_01(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunReleased_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((Request_ESH_PostRunRequest_0_requestedMode == RELEASED) && (Request_ESH_PostRunRequest_1_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_01(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_01(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_01(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequested_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((Request_ESH_RunRequest_0_requestedMode == REQUESTED) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRun_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRun_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Detections_89f78c9f_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode == SDC_SERVER_AVAILABE) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581IsRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetSdEventHandlerState(0, 0u) == SD_EVENT_HANDLER_REQUESTED) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode == SDC_CEG_REQUESTED) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode == SDC_CLIENT_REQUESTED) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85IsAvailable_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetSdConsumedEventState(0, 0u) == SD_CONSUMED_EVENTGROUP_AVAILABLE) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_SW_Info_c2745ec9_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode == SDC_SERVER_AVAILABE) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73caeIsRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetSdEventHandlerState(2, 0u) == SD_EVENT_HANDLER_REQUESTED) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_ApplRequest_S_provService_RDR_1_Status_d2069d01_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode == SDC_SERVER_AVAILABE) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382dIsRequested_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetSdEventHandlerState(1, 0u) == SD_EVENT_HANDLER_REQUESTED) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_SDC_LE_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055bIsAvailable_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetSdClientServiceState(0, 0u) == SD_CLIENT_SERVICE_AVAILABLE) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_TX_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_DM_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetCanSMChannelState(1, 0u) == CANSM_BSWM_FULL_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_VCAN_RADAR_489180b6_RX_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetCanSMChannelState(1, 0u) != CANSM_BSWM_NO_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_CN_PCAN_RADAR_458ff0f1_RX_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_CancelNotPending_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(0, 0u) != BSWM_TIMER_STARTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_LE_AckModeTransition_Execute_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset == RTE_MODE_DcmEcuReset_EXECUTE) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_LE_EcuSoftReset_RDR_01
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_LE_EcuSoftReset_RDR_01(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_Mode_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset == RTE_MODE_DcmEcuReset_SOFT) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_02(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_02(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_02(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_02(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_02(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_02(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_02(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_02(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_02(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_02(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_02(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_02(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_02
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_02(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_02(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_02(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_03(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_03(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_03(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_03(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_03(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_03(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_03(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_03(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_03(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_03(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_03(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_03(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_03
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_03(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_03(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_03(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_04(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_04(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_04(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_04(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_04(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_04(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_04(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_04(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_04(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_04(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_04(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_04(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_04
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_04(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_04(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_04(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_05(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_05(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_05(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_05(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_05(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_05(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_05(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_05(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_05(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_05(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_05(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_05(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_05
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_05(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_05(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_05(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_06(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_06(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_06(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_06(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_06(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_06(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_06(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_06(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_06(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_06(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_06(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_06(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_06
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_06(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_06(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_06(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_07(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_07(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_07(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_07(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_07(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_07(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_07(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_07(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_07(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_07(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_07(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_07(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_07
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_07(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_07(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_07(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_RDR_08(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_08(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_NoRunReasons_RDR_08(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReleased_RDR_08(partitionIdx) != 0u) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_08(partitionIdx) != 0u) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_RDR_08(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_08(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_RDR_08(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_CancelNotPending_RDR_08(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_08(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_PostRunReleased_RDR_08(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_08(partitionIdx) != 0u) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_08
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_RDR_08(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_ValidWakeup_RDR_08(partitionIdx) != 0u) || (BswM_ExpFct_ESH_LE_RunRequested_RDR_08(partitionIdx) != 0u)) ? 1u : 0u);
}


#define BSWM_STOP_SEC_CODE_ASIL_D
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

